/***************************************************************************
    watchdoggamespy.h - Functions for checking if server is alive
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

#if !defined(watchdog_gamespy_h)
#define watchdog_gamespy_h

#include "watchdog.h"
#include "udp.h"

#define WM_SERVERRESTARTED_GAMESPY WM_USER + 6
#define WM_SERVERRESTARTED_GAMESPY_LOCKUP WM_USER + 7
#define WM_GAMESPY_STATE_CHECKING WM_USER + 12
#define WM_GAMESPY_STATE_NONE WM_USER + 13

#define WATCHDOG_STATE_NONE 0
#define WATCHDOG_STATE_WAITING 1
#define WATCHDOG_STATE_RESTARTING 2

#define UDP_WAIT 1000

class CWatchdogGamespy : public CWatchdog
{
public:

	struct sWatchdogThreadDataExtra
	{
		int port;
		int retries;
		bool oldGamespyProtocol;
		CUDP *udp;
	};

	CWatchdogGamespy();

	void setPort(int port);
	void setRetries(int retries);
	void UseOldGamespyProtocol(bool truefalse);
	void StartThread();
	void StopThread();

protected:
	sWatchdogThreadDataExtra WatchdogThreadDataExtra;
};

#endif