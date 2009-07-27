/***************************************************************************
    NWNXFunction.cpp - Implementation of the CNWNXFunction class.
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

#include "stdafx.h"
#include "NWNXFunction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXFunction::CNWNXFunction()
{
}

CNWNXFunction::~CNWNXFunction()
{
}

BOOL CNWNXFunction::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_functions.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;
	fprintf(m_fFile, "NWNX Functions V.1.1.0 for Windows\n");
	fprintf(m_fFile, "(c) virusman 2007-2009, Zebranky 2009\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
	
	fflush(m_fFile);

	return true;
	// we do not need a log file, so just exit
	// WRONG -- Zeb
	//return true;
}

void CNWNXFunction::SetLockDC(char* value)
{
	if (*(pGameObject+0x8) == 0x9) // object type placeable
	{
		int iLockDC = atoi(value);
		*(pGameObject+0x210) = iLockDC;
	}
}


void CNWNXFunction::SetGoldPieceValue(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int iGoldValue = atoi(value);
		*(int*)(pGameObject+0x1F4) = iGoldValue;
	}
}

void CNWNXFunction::SetTag(char* value)
{
    char* tag = (char*)(*(int*)(pGameObject+0x18));

	int iLength;
	int iOrgLength = strlen(tag);
	int iNewLength = strlen(value);

	if (iOrgLength > iNewLength)
		iLength = iNewLength;
	else
		iLength = iOrgLength;

	strncpy(tag, value, iLength);

	*(tag+iLength) = 0x0;
}

void CNWNXFunction::SetArmorAC(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int iAC = atoi(value);
		*(int*)(pGameObject+0x1CC) = iAC;
	}
	// 0x1d4: auch armor class ??
}

void CNWNXFunction::GetArmorAC(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int iAC = *(int*)(pGameObject+0x1CC);
		if (strlen(value) > 1)
			sprintf(value, "%d", iAC);
	}
}

void CNWNXFunction::GetDescription(char* value)
{
	int length = strlen(value);
	char* desc;
	
	if (*(pGameObject+0x8) != 0x6) // object type item	
		return;
	
	desc = (char*)(*(int*)(pGameObject+0x228));
	if (*(desc+4) == 0)
		return;
	desc = (char*)(*(int*)(desc));
	desc = (char*)(*(int*)(desc));
	desc = (char*)(*(int*)(desc+0x8));
	desc = (char*)(*(int*)(desc+0x4));

	int iDescLength = strlen(desc);
	if (iDescLength < length)
	{
		strncpy(value, desc, iDescLength);
		*(value+iDescLength) = 0x0;
	}
	else
	{
		strncpy(value, desc, length);
		*(value+length) = 0x0;
	}
}

void CNWNXFunction::GetIsPickPocketable(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int i = *(int*)(pGameObject+0x248);
		if (strlen(value) > 1)
			sprintf(value, "%d", i);
	}
}

void CNWNXFunction::SetIsPickPocketable(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int i = atoi(value);
		*(int*)(pGameObject+0x248) = i;
	}
}

/* TODO: ugly */
CNWSPlayer* (__stdcall *CServerExoApp__GetClientObjectByObjectId)(uint32_t) = (CNWSPlayer *(__stdcall *)(uint32_t))0x0042cd20;
int (__stdcall *CNetLayer__DisconnectPlayer)(uint32_t,uint32_t,int)  = (int (__stdcall *)(uint32_t,uint32_t,int))0x0041f490;
CAppManager **NWN_AppManager = (CAppManager**)0x0066c050;

int CNWNXFunction::GetPlayerPort (void *pNetLayer, uint32_t nPlayerID)
{
    int i;
    uint32_t nNum;
    void *pClientStruct, *pNetLayerInternal, *pExoNet, *pExoNetInternal;

    pNetLayerInternal = *(void **)pNetLayer;
    pExoNet = *(void **)((char*)pNetLayerInternal+0x4);
        if(!pExoNet) return -1;
    pExoNetInternal = *(void **)pExoNet;
        if(!pExoNetInternal) return -2;

    /* Yes, this is ugly. But I don't want to describe 4 or 5 nested structures. :) */
    for (i = 0; i < 0x60; i++) {
        pClientStruct = (void *)((char *)pNetLayerInternal + 0xC + i*0x91C);

        if(*(uint32_t *)((char*)pClientStruct+0x8) == 1) {
            if(*(uint32_t *)((char*)pClientStruct+0xC) == nPlayerID) {
                nNum = *(uint32_t *)((char*)pClientStruct+0x14);

                uint8_t *pFlagList = *(uint8_t **)((char*)pExoNetInternal+0x3c);
                if(!pFlagList || !pFlagList[nNum]) return -3;

				char* pNetInfoBase = *(char**)((char*)pExoNetInternal+0x44);
				struct sockaddr_in *pIP = (struct sockaddr_in *)(pNetInfoBase+nNum*16);
                if(!pIP) return -4;

                return pIP->sin_port;
            }
        }
    }
    return -5;
}

void CNWNXFunction::Func_GetPCPort (CGameObject *ob, char *value)
{
    CNWSPlayer *pl;
    CNWSCreature *cre = (CNWSCreature*)ob;

    if (!ob || !cre->cre_is_pc) {
        _snprintf(value, strlen(value), "0");
        return;
    }

	CServerExoApp* app_server = (*NWN_AppManager)->app_server;
	uint32_t objid = ob->id;
	__asm { mov ecx, app_server }
    pl = CServerExoApp__GetClientObjectByObjectId(objid);
    if (pl == NULL) {
        _snprintf(value, strlen(value), "0");
        return;
    }

	int port = GetPlayerPort((*NWN_AppManager)->app_server->srv_internal->srv_network, pl->pl_id);

    _snprintf(value, strlen(value), "%d", port);

    /* TODO: describe all nested structures */
}

void Func_BootPCWithMessage (CGameObject *ob, char *value) {
    CNWSPlayer *pl;

	CServerExoApp* app_server = (*NWN_AppManager)->app_server;
	uint32_t objid = ob->id;
	__asm { mov ecx, app_server }
    pl = CServerExoApp__GetClientObjectByObjectId(objid);
    if (pl != NULL)
	{
		CNetLayer* netlayer = (*NWN_AppManager)->app_server->srv_internal->srv_network;
		uint32_t pl_id = pl->pl_id;
		int iVal = atoi(value);
		__asm { mov ecx, netlayer }
        CNetLayer__DisconnectPlayer(pl_id, iVal, 1);
	}
}

char* CNWNXFunction::OnRequest (char *gameObject, char* Request, char* Parameters)
{
	this->pGameObject = gameObject;

	if (strncmp(Request, "SETLOCKDC", 9) == 0) 	
	{
		SetLockDC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETGOLDPIECEVALUE", 17) == 0) 	
	{
		SetGoldPieceValue(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETTAG", 6) == 0) 	
	{
		SetTag(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETARMORAC", 10) == 0) 	
	{
		SetArmorAC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETARMORAC", 10) == 0) 	
	{
		GetArmorAC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETDESCRIPTION", 14) == 0) 	
	{
		GetDescription(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETISPICKPOCKETABLE", 19) == 0) 	
	{
		GetIsPickPocketable(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETISPICKPOCKETABLE", 19) == 0) 	
	{
		SetIsPickPocketable(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETPCPORT", 9) == 0) 	
	{
		/* TODO: figure out why this is necessary -- nwserver was triggering
		 * GETPCPORT again on disconnect. Haven't seen that before. */
		if(Parameters[0] == ' ')
			Func_GetPCPort((CGameObject*)gameObject, Parameters);
		return NULL;
	}
	else if (strncmp(Request, "BOOTPCWITHMESSAGE", 17) == 0) 	
	{
		Func_BootPCWithMessage((CGameObject*)gameObject, Parameters);
		return NULL;
	}
	return NULL;
}

BOOL CNWNXFunction::OnRelease ()
{
	// call base class
	return CNWNXBase::OnRelease ();
}
