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

#include "stdafx.h"
#include "shellapi.h"
#include <conio.h>
#include <windows.h>
#include "madCHook.h"
#include "nwnserver.h"

STARTUPINFO si;
PROCESS_INFORMATION pi;
char logDir[8] = {0};

// returns log directory the server will use (logs.0, logs.1, ...)
char* GetLogDir()
{
	if (strlen(logDir) == 0)
	{
		int iDirectory = 0;
		char tmpNo[3] = {0};		
		char tmpFileName[26] = {0};
		HANDLE outFile;
		
		while (iDirectory < 100)
		{
			strcpy(tmpFileName, "logs.");
			itoa(iDirectory, tmpNo, 10);
			strcat(tmpFileName, tmpNo);
			strcat(tmpFileName, "\\nwserverlog1.txt");

			outFile = CreateFile(
			tmpFileName,						// pointer to name of the file
			GENERIC_READ | GENERIC_WRITE,       // access (read-write) mode
			0,									// exclusive mode
			NULL,                               // pointer to security attributes
			OPEN_ALWAYS,                        // how to create
			0,                                  // file attributes
			NULL);                              // handle to file with attributes to copy

			if (outFile != INVALID_HANDLE_VALUE)
			{
				// file not in use
				strcpy(logDir, "logs.");
				strcat(logDir, tmpNo);
				CloseHandle(outFile);
				break;
			}
			CloseHandle(outFile);
			iDirectory++;
		}

	}
	return logDir;
}

void RotateLogs()
{
	char tmpNo[3] = {0};
	char baseDirName[256] = {0};
	char oldDirName[256] = {0};
	char newDirName[256] = {0};
	char tmpFileName[256] = {0};

	if (strlen(GetLogDir()) == 0)
		return;

	GetCurrentDirectory(256, baseDirName);
	strcat(baseDirName, "\\");
	strcat(baseDirName, GetLogDir());
	strcat(baseDirName, "\\");

    time_t curtime;
    tm now;
    time(&curtime);
    now = *localtime(&curtime);
    sprintf(newDirName, "%s%d-%d-%d--%d-%d-%d", baseDirName, now.tm_year+1900, now.tm_mon+1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);

    // Create directory from filename
    CreateDirectory(newDirName, NULL);

    // Move previous log files to new directory
    sprintf(tmpFileName, "%s*.txt", baseDirName);
    WIN32_FIND_DATA wfd;
    HANDLE h_find = FindFirstFile(tmpFileName, &wfd);
    while (h_find != INVALID_HANDLE_VALUE)
	{
      sprintf(oldDirName, "%s%s", baseDirName, wfd.cFileName);
      sprintf(newDirName, "%s%d-%d-%d--%d-%d-%d\\%s", baseDirName, now.tm_year+1900, now.tm_mon+1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec, wfd.cFileName);
      MoveFile(oldDirName, newDirName);
      if (!FindNextFile(h_find, &wfd))
	  {
        FindClose(h_find);
        h_find = INVALID_HANDLE_VALUE;
      }
   }
}

void StartServerProcess(LPTSTR cl, STARTUPINFO* si, PROCESS_INFORMATION* pi)
{
	CreateProcessEx("nwserver.exe", cl, NULL, NULL,FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, si, pi, "nwnx-module.dll");
}

void StartAndInject(char* cl)
{
	ZeroMemory(&si,sizeof(si));
	si.cb = sizeof(si);

	RotateLogs();
	StartServerProcess(cl, &si, &pi);
}

BOOL CheckProcessActive()
{
	DWORD lpExitCode;
	if (GetExitCodeProcess(pi.hProcess, &lpExitCode))
	{
		if (lpExitCode == STILL_ACTIVE)
			return TRUE;
	}	
	return FALSE;
}

void KillServerProcess()
{
	TerminateProcess(pi.hProcess, -1);
}


DWORD WINAPI StartServerDummyThread(LPVOID lpParam) 
{
	// Start NWN server
	StartAndInject((char*)lpParam);
	return 0;
} 

