/***************************************************************************
    Chat plugin for NWNX - Implementation of the CNWNXEvents class.
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
	if (!scriptRun) return NULL; //The following functions are accessible only from event script
	if (strncmp(Request, "GETEVENTID", 10) == 0)
	{
		if (strlen(Parameters) > 1)
		sprintf(Parameters, "%d", nEventID);
		return NULL;
	}

	return NULL;
}

unsigned long CNWNXEvents::OnRequestObject (char *gameObject, char* Request)
{
	fprintf(m_fFile,"ObjRequest: \"%s\"\n",Request);
	this->pGameObject = gameObject;
	this->nGameObjectID = *(dword *)(gameObject+0x4);
	if (!scriptRun) return OBJECT_INVALID; //The following functions are accessible only from event script
	if (strncmp(Request, "TARGET", 6) == 0)
	{
		return oTarget;
	}
	return OBJECT_INVALID;
}

BOOL CNWNXEvents::OnRelease ()
{
	Log ("o Shutdown.\n");
	// call base class function
	return CNWNXBase::OnRelease();
}

void CNWNXEvents::LoadConfiguration ()
{
	CIniFile iniFile ("nwnx.ini");

	iniFile.ReadString("EVENTS", "event_script", eventScript, 16, "vir_events");
}

void CNWNXEvents::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX Events 1.0-beta for Windows\n");
	fprintf(m_fFile, "(c) 2006-2007 by virusman (virusman@virusman.ru)\n");
}

void CNWNXEvents::FireEvent(const int pObj, int nEvID)
{
	nEventID = nEvID;
	fprintf(m_fFile, "o EVENTS: Fired event %d (%08lX). Calling '%s'\n", nEventID, pObj, eventScript);
	RunScript(eventScript, pObj);
	//deinitialize
	oTarget = OBJECT_INVALID;
	nEventID = 0;
}
