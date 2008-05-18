/***************************************************************************
    watchdogprocess.h - Functions for checking if server is alive
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

#if !defined(watchdog_process_h)
#define watchdog_process_h

#include "watchdog.h"

#define WM_SERVERRESTARTED_PROCESS WM_USER + 5
#define WM_PROCESS_STATE_CHECKING WM_USER + 10
#define WM_PROCESS_STATE_NONE WM_USER + 11

class CWatchdogProcess : public CWatchdog
{
public:
	void StartThread();
	void StopThread();
};

#endif