/***************************************************************************
    NWNXProfiler.cpp - Implementation of the CNWNXProfiler class.
    Copyright (C) 2003 Ingmar Stieger (Papillon, papillon@blackdagger.com)
    
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
#include "NWNXProfiler.h"
#include "HookRunScript.h"
#include "../NWNXdll/IniFile.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXProfiler::CNWNXProfiler()
{
	m_LogLevel = 1;
}

CNWNXProfiler::~CNWNXProfiler()
{
	// write last few samples to log file 
	Release();
}

BOOL CNWNXProfiler::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_profiler.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;

	LoadConfiguration();
	HookRunScript();
	return true;
}

char* CNWNXProfiler::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	return NULL;
}

void CNWNXProfiler::LoadConfiguration ()
{
	CIniFile iniFile ("nwnx.ini");

	// read log file setting
	m_maxLogSizeKB = 1024 * iniFile.ReadLong("PROFILER", "MaxLogSize", 1024);
	m_LogLevel = iniFile.ReadLong("PROFILER", "LogLevel", 1);
}

void CNWNXProfiler::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX Profiler V.1.62\n");
	fprintf(m_fFile, "(c) 2005 by Ingmar Stieger (papillon@nwnx.org)\n");
	fprintf(m_fFile, "(c) 2008 by virusman (virusman@virusman.ru)\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
	fprintf(m_fFile, "* Updated entries are marked with a * symbol\n");
	fprintf(m_fFile, "* Logfile maximum size limit is: %d bytes\n", m_maxLogSizeKB);
	fprintf(m_fFile, "* Log level: ");
	switch (m_LogLevel)
	{
		case logStats:
			fprintf(m_fFile, "Only overall statistics will be logged.\n");
			break;
		case logCallstack:
			fprintf(m_fFile, "Script callstack will be logged.\n");
			break;
	}
}