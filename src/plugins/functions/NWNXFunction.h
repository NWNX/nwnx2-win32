/***************************************************************************
    NWNXFunction.h - Interface for the CNWNXFunction class.
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

#if !defined(AFX_NWNXFUNCTION_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
#define AFX_NWNXFUNCTION_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_

#include "NWNXBase.h"
#include <winsock.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* TODO: UGLY! */
typedef unsigned long int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
struct CGameObject_s;                     typedef struct CGameObject_s                     CGameObject;
struct CNWSCreature_s;                    typedef struct CNWSCreature_s                    CNWSCreature;
struct CNWSPlayer_s;                      typedef struct CNWSPlayer_s                      CNWSPlayer;
struct CServerExoApp_s;                   typedef struct CServerExoApp_s                   CServerExoApp;
struct CServerExoAppInternal_s;           typedef struct CServerExoAppInternal_s           CServerExoAppInternal;
struct CNetLayer_s;                       typedef struct CNetLayer_s                       CNetLayer;
struct CAppManager_s;                     typedef struct CAppManager_s                     CAppManager;

class CNWNXFunction : public CNWNXBase
{
public:
	CNWNXFunction();
	virtual ~CNWNXFunction();

	BOOL OnCreate(const char* LogDir);
	char* OnRequest (char* gameObject, char* Request, char* Parameters);
	BOOL OnRelease ();

protected:
	void SetLockDC(char* value);
	void SetGoldPieceValue(char* value);
	void SetTag(char* value);
	void SetArmorAC(char* value);
	void GetArmorAC(char* value);
	void GetDescription(char* value);
	void SetIsPickPocketable(char* value);
	void GetIsPickPocketable(char* value);
	int GetPlayerPort (void *pSomeStruct, uint32_t nPlayerID);
	void Func_GetPCPort (CGameObject *ob, char *value);

private:
	char* pGameObject;
};

struct CGameObject_s {
    uint32_t            field_00;

    uint32_t            id;
};

struct CNWSCreature_s {
    uint8_t fields1[0xad8];
    uint32_t                 cre_is_pc;
};

struct CNWSPlayer_s {
	uint32_t			vftable;
    uint32_t            pl_id;
};

struct CServerExoApp_s {
    uint32_t                   unknown;

    CServerExoAppInternal      *srv_internal;
};

struct CServerExoAppInternal_s {
    uint8_t                   unknown[0x10060];
    CNetLayer                  *srv_network;            /* 10060 */
};

struct CNetLayer_s {
    void               *unknown;
};

struct CAppManager_s {
    uint32_t                   field_00;

    CServerExoApp              *app_server;             /* 0004 */
};

#endif // !defined(AFX_NWNXFUNCTION_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
