/***************************************************************************
    Chat plugin for NWNX - interface for the CNWNXEvents class.
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

#if !defined(NWNXEVENTS_H_)
#define NWNXEVENTS_H_

#include "..\NWNXdll\NWNXBase.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "NwnDefines.h"
#include "HookFunc.h"

#define MAXPATH 512
#define MAXSIZE 512 * 1024

class CNWNXEvents : public CNWNXBase
{

public:
	CNWNXEvents();
	virtual ~CNWNXEvents();
	BOOL OnCreate(const char* LogDir);
	char* OnRequest(char* gameObject, char* Request, char* Parameters);
	unsigned long OnRequestObject (char *gameObject, char* Request);
	BOOL OnRelease();
	void LoadConfiguration();
	void WriteLogHeader();
	void FireEvent(const int pObj, int nEvID);
	char *pGameObject;
	dword nGameObjectID;
	int nEventID;
	dword oTarget;

	enum ELogLevel {logNothing, logScripter, logAll};
	int	m_LogLevel;

private:
  char eventScript[17];
};

#define OBJECT_INVALID 0x7F000000
#define EVENT_SAVE_CHAR 1
#define EVENT_PICKPOCKET 2
#define EVENT_ATTACK 3

#endif
