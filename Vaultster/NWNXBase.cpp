/***************************************************************************
    NWNX Base class - Library for custom expansions
    Copyright (C) 2003 Ingmar Stieger (Papillon, papillon@blackdagger.com) and 
	 Jeroen Broekhuizen (nwnx@jengine.nl)

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
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include "NWNXBase.h"

CIniFile::CIniFile() {
   m_szFileName[0] = 0;
}

CIniFile::CIniFile(LPCSTR lpszFileName) {
	open (lpszFileName);
}

CIniFile::~CIniFile() {
}

bool CIniFile::open (LPCSTR lpszFileName)
{
   // profile functions require complete path
	_fullpath (m_szFileName, lpszFileName, MAX_PATH);
   return true;
}

int CIniFile::ReadInteger (LPCSTR lpszSection, LPCSTR lpszKey, int iDefault)
{
	// read integer value from ini-file
	return GetPrivateProfileInt (lpszSection, lpszKey, iDefault, m_szFileName);
}

void CIniFile::ReadString (LPCSTR lpszSection, LPCSTR lpszKey, LPSTR lpszBuffer, int Size, LPCSTR lpszDefault)
{
	// read string value
	GetPrivateProfileString (lpszSection, lpszKey, lpszDefault, lpszBuffer, Size, m_szFileName);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXBase::CNWNXBase()
{
	m_fFile = NULL;
	logFile = NULL;
}

CNWNXBase::~CNWNXBase()
{
	// The OnRelease function is always called before
	// an instance is deleted
	OnRelease ();
}

BOOL CNWNXBase::OnCreate(const char* logFileName)
{
   char name[_MAX_FNAME+5];
   char fullname[_MAX_FNAME+4+1]; // nwnx_ and .ini and 0

   // try to open the log file
	logFile = _strdup (logFileName);
	m_fFile = fopen (logFile, "w");
   if (m_fFile == NULL)
      return FALSE;

   // try to open the ini file
   _splitpath (logFileName, NULL, NULL, name, NULL);
   sprintf (fullname, "%s.ini", name);
   iniFile.open (fullname);
   return TRUE;
}

BOOL CNWNXBase::OnRelease()
{
	// close the log file
	int ret = 0;
	if (m_fFile)
	{
		ret = fclose (m_fFile);
		m_fFile = NULL;
	}
	if (logFile)
	{
		free (logFile);
		logFile = NULL;
	}
	return (ret == 0);
}

char* CNWNXBase::OnRequest (char *gameObject, char* Request, char* Parameters)
{
	if (strncmp (Request, "LOG", 3) == 0)
	{
		char log = Parameters[0];		// 0 = no log; 1 = log
		if (log == '0' && m_fFile)
		{
			// close current file and remove it
			fclose (m_fFile);
			m_fFile = NULL;
			remove (logFile);
			logFile = NULL;
		}
		else if (log == '1' && !m_fFile)
		{
			// create & open the logfile
			m_fFile = fopen (logFile, "w");
		}
	}
	return NULL;
}

void CNWNXBase::Log(const char *pcMsg, ...)
{
	va_list argList;
	char acBuffer[1024], acTime[128], acDate[128];

	if (m_fFile)
	{  
		_strtime (acTime);
		_strdate (acDate);

		// build up the string
		va_start(argList, pcMsg);
		vsprintf(acBuffer, pcMsg, argList);
		va_end(argList);

		// log string in file
		fprintf (m_fFile, "[%s %s] ", acDate, acTime);
		fprintf (m_fFile, acBuffer);
		fflush (m_fFile);
	}
}
