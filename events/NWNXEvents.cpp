/***************************************************************************
    Event plugin for NWNX - Implementation of the CNWNXEvents class.
    (c) 2005 dumbo (dumbo@nm.ru)

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
#include "NWNXEvents.h"
#include "HookFunc.h"
#include "../NWNXdll/IniFile.h"
#include <stdio.h>
#include "string"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXEvents::CNWNXEvents()
{
	m_LogLevel = 0;
}

CNWNXEvents::~CNWNXEvents()
{
}

BOOL CNWNXEvents::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_events.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;
    WriteLogHeader();
	LoadConfiguration();
	return HookFunctions();
}

char* CNWNXEvents::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	if (strncmp(Request, "GETISALIVE", 10) == 0)
	{
		if (strlen(Parameters) > 1)
		{
			sprintf(Parameters, "%x", OBJECT_INVALID);	
			//fprintf( m_fFile, "! GETEVENTID: %d\n", nEventID );
		}
		return NULL;

	}

	//if (!scriptRun) return NULL; //The following functions are accessible only from event script

	else if (strncmp(Request, "GETEVENTID", 10) == 0)
	{
		if (strlen(Parameters) > 1)
		{
			sprintf(Parameters, "%d", nEventID);	
			//fprintf( m_fFile, "! GETEVENTID: %d\n", nEventID );
		}
		return NULL;
	}
	else if (strncmp(Request, "GETTARGETID", 10) == 0)
	{
		if (strlen(Parameters) > 1)
		{
			sprintf(Parameters, "%x", oTarget);
			//fprintf( m_fFile, "! GETTARGETID: %08lx\n", oTarget );
		}
		return NULL;
	}
	return NULL;
}

BOOL CNWNXEvents::OnRelease ()
{
	Log( "o Shutting down\n" );
	// call base class function
	return CNWNXBase::OnRelease();
}

void CNWNXEvents::LoadConfiguration ()
{
	CIniFile iniFile ("nwnx.ini");

	iniFile.ReadString("EVENTS", "event_script", eventScript, 16, "nwnx_events");

	fprintf( m_fFile, "Loaded event script: %s\n\n", eventScript );
}

void CNWNXEvents::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX Events 1.1 for Windows\n");
	fprintf(m_fFile, "(c) 2006-2007 by virusman (virusman@virusman.ru)\n");
	fprintf(m_fFile, "Version 1.1 by Terra_777\n\n");
}

void CNWNXEvents::FireEvent(const int pObj, int nEvID)
{
	nEventID = nEvID;

	if( nEventID == EVENT_SAVE_CHAR ) 
		Log( "o EVENT_SAVE_CHAR (%d):....OBJECT_SELF: %08lx.\n", nEventID, pObj);
	else if( nEventID == EVENT_PICKPOCKET ) 
		Log( "o EVENT_PICKPOCKET (%d):...OBJECT_SELF: %08lx TARGET: %08lx.\n", nEventID, pObj, oTarget);
	else if( nEventID == EVENT_ATTACK ) 
		Log( "o EVENT_ATTACK (%d):.......OBJECT_SELF: %08lx TARGET: %08lx.\n", nEventID, pObj, oTarget);
	
	RunScript(eventScript, pObj);

	oTarget = OBJECT_INVALID;
	nEventID = 0;

	//fflush(m_fFile);
}