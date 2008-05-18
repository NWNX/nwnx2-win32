/***************************************************************************
    NWNXFixes.cpp - Implementation of the CNWNXFixes class.
    (c) 2007 virusman (virusman@virusman.ru)

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
#include "NWNXFixes.h"
#include "FixesHooks.h"
#include "../NWNXdll/IniFile.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXFixes::CNWNXFixes()
{
	bHooked = 0;
}

CNWNXFixes::~CNWNXFixes()
{
}

BOOL CNWNXFixes::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_fixes.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;
	fprintf(m_fFile, "NWNX Fixes V.1.0.3 for Windows\n");
	fprintf(m_fFile, "(c) by virusman, 2007\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
	
	CIniFile iniFile ("nwnx.ini");

	debuglevel = iniFile.ReadInteger("FIXES", "debuglevel", 0);

	if (FindHookFunctions())
	{
		bHooked=1;
		fprintf(m_fFile, "* Module loaded successfully.\n");
	}
	else
	{
		bHooked=0;
		fprintf(m_fFile, "* Module loaded successfully.\n");
		fprintf(m_fFile, "* Signature recognition failed. Some functions will be disabled.\n");
		//return false;
	}
	fflush(m_fFile);

	return true;
}

char* CNWNXFixes::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	return NULL;
}

unsigned long CNWNXFixes::OnRequestObject (char *gameObject, char* Request)
{
	return OBJECT_INVALID;
}

BOOL CNWNXFixes::OnRelease ()
{
	Log ("o Shutdown.\n");
	// call base class function
	return CNWNXBase::OnRelease();
}
