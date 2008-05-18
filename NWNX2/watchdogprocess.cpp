/***************************************************************************
    watchdogprocess.cpp - Functions for checking if server is alive
	                      (using process information)
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
#include "watchdogprocess.h"

// redefinition for thread function 
// (external to class)
struct sWatchdogThreadData
{
	HWND hwnd;
	int interval;
	bool threadRunning;
	bool doSleep;
	char* pCmdLine;
	LPVOID extradata;
};

// The watchdog thread function
DWORD WINAPI watchdogProcessThread(LPVOID lpParam)
{
	sWatchdogThreadData* pWatchdogThreadData = (sWatchdogThreadData*) lpParam;

	// Give server time to become ready
	Sleep(10000);

	while (1)
	{
		if (pWatchdogThreadData->doSleep)
		{
			Sleep(1000);
		}
		else
		{
			PostMessage(pWatchdogThreadData->hwnd, WM_PROCESS_STATE_CHECKING, 0, 0);
			if (!CheckProcessActive())
			{
				StartAndInject(pWatchdogThreadData->pCmdLine);
				// WM_SERVERRESTARTED is a user-defined message
				PostMessage(pWatchdogThreadData->hwnd, WM_SERVERRESTARTED_PROCESS, 0, 0);
			}
			else
			{
				Sleep(250);
				PostMessage(pWatchdogThreadData->hwnd, WM_PROCESS_STATE_NONE, 0, 0);
			}
		} // if DoSleep

		Sleep(pWatchdogThreadData->interval - 250);

		if (!pWatchdogThreadData->threadRunning)
		{
			PostMessage(pWatchdogThreadData->hwnd, WM_PROCESS_STATE_NONE, 0, 0);
			ExitThread(0);
		}

	}
	return 0;
}

void CWatchdogProcess::StartThread()
{
	if (!WatchdogThreadData.threadRunning)
	{
		WatchdogThreadData.threadRunning = true;
		hThread = CreateThread(NULL, 0, watchdogProcessThread, &WatchdogThreadData, 0, &dwThreadId);                
	}
}

void CWatchdogProcess::StopThread()
{
	if (WatchdogThreadData.threadRunning)
	{
		WatchdogThreadData.threadRunning = false;
		CloseHandle(hThread);
	}
}