/***************************************************************************
    watchdoggamespy.cpp - Functions for checking if server is alive
	                     (using gamespy server query)
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/


#include "stdafx.h"
#include "nwnserver.h"
#include "watchdoggamespy.h"

// redefinitions for thread function 
// (external to class)
struct sWatchdogThreadData
{
	HWND hwnd;
	int interval;
	bool threadRunning;
	bool doSleep;
	char* pCmdLine;
	LPVOID extraData;
};

struct sWatchdogThreadDataExtra
{
	int port;
	int retries;
	bool oldGamespyProtocol;
	CUDP *udp;
};


DWORD WINAPI watchdogGamespyThread(LPVOID lpParam)
{
	char buffer[2048];
	int ret;
	int retries;
	int watchdogState = WATCHDOG_STATE_NONE;
	sWatchdogThreadData* pWatchdogThreadData = (sWatchdogThreadData*) lpParam;
	sWatchdogThreadDataExtra* pWatchdogThreadDataExtra = (sWatchdogThreadDataExtra*) pWatchdogThreadData->extraData;

	// Give server time to become ready
	Sleep(10000);

	if (!pWatchdogThreadDataExtra->udp)
		pWatchdogThreadDataExtra->udp = new CUDP("localhost", pWatchdogThreadDataExtra->port);

	while (1)
	{

		if (pWatchdogThreadData->doSleep)
		{
			Sleep(1000);
		}
		else
		{
			if (watchdogState == WATCHDOG_STATE_NONE)
			{
				PostMessage(pWatchdogThreadData->hwnd, WM_GAMESPY_STATE_CHECKING, 0, 0);
				watchdogState = WATCHDOG_STATE_WAITING;
				retries = 0;
			}

			// Send status request
			if (pWatchdogThreadDataExtra->oldGamespyProtocol == false)
				pWatchdogThreadDataExtra->udp->sendMessage("BNLM");
			else
				pWatchdogThreadDataExtra->udp->sendMessage("\\status\\");
			Sleep(UDP_WAIT);

			// Read server response
			ret = pWatchdogThreadDataExtra->udp->getMessage(buffer, 2048);
			if (ret == 0)
			{
				// No reply from server
				retries++;
				Sleep(pWatchdogThreadData->interval);
			}
			else
			{
				// Server answered
				watchdogState = WATCHDOG_STATE_NONE;
				PostMessage(pWatchdogThreadData->hwnd, WM_GAMESPY_STATE_NONE, 0, 0);
				Sleep(pWatchdogThreadData->interval - UDP_WAIT);
				retries = 0;
			}

			// Check if it is time to restart the server
			if ((retries > pWatchdogThreadDataExtra->retries) &&
				(watchdogState != WATCHDOG_STATE_RESTARTING))
			{
				// Restart server
				watchdogState = WATCHDOG_STATE_RESTARTING;
				if (CheckProcessActive())
				{
					KillServerProcess();
					PostMessage(pWatchdogThreadData->hwnd, WM_SERVERRESTARTED_GAMESPY_LOCKUP, 0, 0);
				}
				else
				{
					PostMessage(pWatchdogThreadData->hwnd, WM_SERVERRESTARTED_GAMESPY, 0, 0);
				}

				StartAndInject(pWatchdogThreadData->pCmdLine);
			}
		} // if do Sleep

		if (!pWatchdogThreadData->threadRunning)
		{
			PostMessage(pWatchdogThreadData->hwnd, WM_GAMESPY_STATE_NONE, 0, 0);
			ExitThread(0);
		}
	}
	return 0;
}


CWatchdogGamespy::CWatchdogGamespy()
{
	// "Link" in extra data for this class
	WatchdogThreadData.extraData = &WatchdogThreadDataExtra;
	// Set extra data for gamespy queries
	WatchdogThreadDataExtra.udp = NULL;
	setPort(5121);
	setRetries(5);
	UseOldGamespyProtocol(false);
}

void CWatchdogGamespy::setPort(int port)
{
	WatchdogThreadDataExtra.port = port;
}

void CWatchdogGamespy::setRetries(int retries)
{
	WatchdogThreadDataExtra.retries = retries;
}

void CWatchdogGamespy::UseOldGamespyProtocol(bool truefalse)
{
	WatchdogThreadDataExtra.oldGamespyProtocol = truefalse;
}

void CWatchdogGamespy::StartThread()
{
	if (!WatchdogThreadData.threadRunning)
	{
		WatchdogThreadData.threadRunning = true;
		hThread = CreateThread(NULL, 0, watchdogGamespyThread, &WatchdogThreadData, 0, &dwThreadId);                
	}
}

void CWatchdogGamespy::StopThread()
{
	if (WatchdogThreadData.threadRunning)
	{
		WatchdogThreadData.threadRunning = false;
		CloseHandle(hThread);
	}
}


