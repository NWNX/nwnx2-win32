/***************************************************************************
    NWNXResMan.h - Interface for the CNWNXResMan class.
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

#if !defined(AFX_SCRIPTER_H_)
#define AFX_SCRIPTER_H_

#include "..\NWNXdll\NWNXBase.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NwnDefines.h"
#include "HookDemandRes.h"

#define MAXPATH 512
#define MAXSIZE 512 * 1024

class CNWNXResMan : public CNWNXBase
{
	
public:
	CNWNXResMan();
	virtual ~CNWNXResMan();
	BOOL OnCreate(const char* LogDir);
	char* OnRequest(char* gameObject, char* Request, char* Parameters);
	BOOL OnRelease();
	void LoadConfiguration();
	void WriteLogHeader();

	enum ELogLevel {logNothing, logScripter, logAll};
	int	m_LogLevel;

	char* DemandRes(CResStruct* cRes, char* resRef, NwnResType resType);
	unsigned long LoadResource(char* resPath);

private:
	char pScriptBuffer[MAXSIZE];
	char saveName[17];
	int bufferSize;
	char m_sourcePath[MAXPATH];
};

#endif 
