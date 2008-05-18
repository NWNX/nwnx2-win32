/***************************************************************************
    NWNX Base class - Library for custom expansions
    Copyright (C) 2005 Ingmar Stieger (Papillon, papillon@blackdagger.com) and 
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

#include "stdafx.h"
#include "NWNXBase.h"
#include <stdarg.h>
#include <typeinfo.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXBase::CNWNXBase()
{
	m_fFile = NULL;
	m_maxLogSizeKB = 1024 * 1024;
}

CNWNXBase::~CNWNXBase()
{
	// The OnRelease function is always called before
	// an instance is deleted
	OnRelease ();
}

BOOL CNWNXBase::OnCreate(const char* LogFile)
{
	// try to open the log file
	m_LogFile = strdup(LogFile);
	m_fFile = fopen (LogFile, "w");
	return (m_fFile != NULL);
}

BOOL CNWNXBase::OnRelease()
{
	// close the log file
	int ret;
	if (m_fFile)
		ret = fclose (m_fFile);
	return (ret == 0);
}

void CNWNXBase::Log(const char *pcMsg, ...)
{
	va_list argList;
	char *pos;

	if (m_fFile)
	{  
		if (ftell(m_fFile) > m_maxLogSizeKB)
		{	
			fclose(m_fFile);
			m_fFile = fopen (m_LogFile, "w");
			WriteLogHeader();
			fprintf(m_fFile, "o Logfile hit maximum size limit, starting again.\n");
		}

		// build up the string
		va_start(argList, pcMsg);
		vsprintf(acBuffer, pcMsg, argList);
		va_end(argList);

		// replace any percent signs
		pos = strchr(acBuffer, '%');
		while (pos)
		{
			*pos = '~';
			pos = strchr(acBuffer, '%');
		}

		// log string in file
		fprintf (m_fFile, acBuffer);
		fflush (m_fFile);
	}
}

void CNWNXBase::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX base plugin\n");
	fprintf(m_fFile, "(c) 2004 by Ingmar Stieger (Papillon) and Jeroen Broekhuizen\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
}