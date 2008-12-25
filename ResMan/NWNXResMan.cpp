/***************************************************************************
    NWNXResMan.cpp - Implementation of the CNWNXResMan class.
    Copyright (C) 2005 Ingmar Stieger (papillon@nwnx.org)
    
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
#include "NWNXResMan.h"
#include "NwnDefines.h"
#include "HookDemandRes.h"
#include "../NWNXdll/IniFile.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXResMan::CNWNXResMan()
{
	m_LogLevel = 1;
	bufferSize = 0;
}

CNWNXResMan::~CNWNXResMan()
{
}

BOOL CNWNXResMan::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_resman.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;

	LoadConfiguration();
	HookFunctions();
	return true;
}

char* CNWNXResMan::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	return NULL;
}

BOOL CNWNXResMan::OnRelease ()
{
	Log ("o Shutdown.\n");
	// call base class function
	return CNWNXBase::OnRelease();
}

char* CNWNXResMan::DemandRes(CResStruct* cRes, char* resRef, NwnResType resType)
{
	unsigned long size;

	if (!resRef)
		return NULL;

	if (cRes->pResName)
	{
		if (m_LogLevel == logAll)
			Log("o Request for internal resource = %s (type %X)\n", resRef, resType);
		// nothing for us to do
		return NULL;
	}

	// try to load external resource
	char resPath[MAXPATH + 16];
	strcpy(resPath, m_sourcePath);
	strcat(resPath, resRef);

	strcat(resPath, NwnGetResTypeExtension(resType));
	size = LoadResource(resPath);
	if (size == 0)
		return NULL;

	// resource loaded	
	// set resStruct
	cRes->pResData = pScriptBuffer;
	cRes->pResName = saveName;
	cRes->resSize = size;
	cRes->unk2 = 1;
	cRes->unk4 = 4;
	cRes->loaded = 1;
	cRes->loaded2 = 1;
	cRes->resSize2 = size;
	cRes->pResData2 = pScriptBuffer;

	cRes->id1 = 0;
	cRes->id2 = 0;
	cRes->id3 = 0;
	cRes->id4 = 0;

	// Call server function which sets various data pointers
	if (cRes->pClass)
	{
		char* pFunc = cRes->pClass;
		pFunc = (char*)(*(int*)(pFunc+0x10));
		__asm {
			mov ecx, cRes
			call pFunc
		}
	}

	//alternatively:
	//void (__fastcall *pServFunc)(CResStruct* cRes) = (void (__fastcall *)(CResStruct* cRes)) pFunc;
	//pServFunc(cRes);
	
	return cRes->pResData;

}

unsigned long CNWNXResMan::LoadResource(char* resPath)
{
	FILE* pTemp = fopen (resPath, "rb");
	if (pTemp == NULL)
	{
		if (m_LogLevel > logNothing)
			Log("o Skip - File not found: %s\n", resPath);
		return 0;
	}

	fseek (pTemp, 0, SEEK_END);
	unsigned long size = ftell(pTemp);

	if (m_LogLevel > logNothing)
		Log("o Loading external resource %s (%ld bytes)\n", resPath, size);

	if (size > MAXSIZE)
	{
		if (m_LogLevel > logNothing)
			Log("o Critical error - resource too large (>%ld bytes).\n", MAXSIZE);
		fclose (pTemp);
		return 0;
	}
	
	fseek (pTemp, 0, SEEK_SET);
	fread (pScriptBuffer, 1, size, pTemp);
	fclose (pTemp);

	return size;
}

void CNWNXResMan::LoadConfiguration ()
{
	CIniFile iniFile ("nwnx.ini");

	// read log file setting
	m_maxLogSizeKB = 1024 * iniFile.ReadLong("RESOURCEMANAGER", "MaxLogSize", 1024);
	m_LogLevel = iniFile.ReadLong("RESOURCEMANAGER", "LogLevel", 1);
	iniFile.ReadString("RESOURCEMANAGER", "SourcePath", m_sourcePath, MAXPATH, "");
}

void CNWNXResMan::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX Resource Manager V.0.0.2.0\n");
	fprintf(m_fFile, "(c) 2005 by Ingmar Stieger (papillon@nwnx.org)\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
	fprintf(m_fFile, "* Resource source path is: %s\n", m_sourcePath);
	fprintf(m_fFile, "* Logfile maximum size limit is: %d bytes\n", m_maxLogSizeKB);
	fprintf(m_fFile, "* Log level: ");
	switch (m_LogLevel)
	{
		case logNothing:
			fprintf(m_fFile, "Logging disabled.\n");
			break;
		case logScripter:
			fprintf(m_fFile, "Resource Manager specific info will be logged.\n");
			break;
		case logAll:
			fprintf(m_fFile, "List of all loaded resources will be logged.\n");
			break;
	}
}
