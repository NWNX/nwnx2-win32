/***************************************************************************
    NWN Extender - NWN Server related functions
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

#if !defined(nwserver_h)
#define nwserver_h

char* GetLogDir();
void RotateLogs();
void StartServerProcess(LPTSTR, STARTUPINFO*, PROCESS_INFORMATION*);
void StartAndInject(char*);
BOOL CheckProcessActive();
void KillServerProcess();
DWORD WINAPI StartServerDummyThread(LPVOID);

#endif