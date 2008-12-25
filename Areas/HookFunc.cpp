/***************************************************************************
    Chat plugin for NWNX  - hooks implementation
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

#include "HookFunc.h"
#include "NWNXAreas.h"
#include "AssemblyHelper.h"

extern CNWNXAreas areas;
AssemblyHelper asmhelp;

//Functions
void (*pCNWSArea__CNWSArea)(CResRef res, int a3, dword ObjID);
void (*pCNWSArea__LoadArea)(int flag);
void (*pCExoArrayList__Add)(dword nObjID);
void (*pCExoArrayList__Remove)(dword nObjID);
void (*pCNWSArea__Destructor)();
void *(*pGetAreaByGameObjectID)(dword nObjID);

dword pServThis = 0;
dword pScriptThis = 0;
dword pServInternal = 0;

//Wrappers
void CNWSArea__CNWSArea(void *pArea, CResRef res, int a3, dword ObjID){
	void *pESP;
	__asm{
		push ObjID
		push a3
		sub	esp, 0x10
/*		mov	edx, esp
		lea	eax, res
		mov	[edx], eax
		lea ecx, [res+4]
		mov	[edx+4], ecx
		lea	ecx, [res+8]
		mov	[edx+8], ecx
		lea	ecx, [res+12]
		mov	[edx+12], ecx*/
		mov pESP, esp
	}
	memcpy(pESP, &res, 0x10);
	__asm{
		mov ecx, pArea
		call pCNWSArea__CNWSArea
	}
}
void CNWSArea__LoadArea(void *pArea, int flag){
	__asm{
		push flag
		mov ecx, pArea
		call pCNWSArea__LoadArea
	}
}
void CExoArrayList__Add(void *pArray, dword nObjID){
	__asm{
		push nObjID
		mov ecx, pArray
		call pCExoArrayList__Add
	}
}
void CExoArrayList__Remove(void *pArray, dword nObjID){
	__asm{
		push nObjID
		mov ecx, pArray
		call pCExoArrayList__Remove
	}
}
void CNWSArea__Destructor(void *pArea){
	__asm{
		mov ecx, pArea
		call pCNWSArea__Destructor
	}
}
void *GetAreaByGameObjectID(void *pServerExoAppInternal, dword nObjID){
	void *retval;
	__asm{
		push nObjID
		mov ecx, pServerExoAppInternal
		call pGetAreaByGameObjectID
		mov retval, eax
	}
	return retval;
}


CResRef *CResRef____as(CResRef *res, char *str)
{
	memset(res->ResRef, 0, 0x10);
	strncpy(res->ResRef, str, 0x10);
	return res;
}

void NWNXCreateArea(void *pModule, char *sResRef)
{
	CResRef res;
	CResRef____as(&res, sResRef);
	void *pArea = malloc(0x20C);
	areas.Log(0, "Creating area '%s'\n", sResRef);
	CNWSArea__CNWSArea(pArea, res, 0, OBJECT_INVALID);
	areas.Log(0, "Loading area '%s'\n", sResRef);
	CNWSArea__LoadArea(pArea, 0);
	dword nAreaID = *((dword *)pArea+0x32);
	areas.Log(0, "AreaID=%08lX\n", nAreaID);
	void *pArray = ((dword *)pModule+0x6);
	CExoArrayList__Add(pArray, nAreaID);
	areas.nLastAreaID = nAreaID;
}

void NWNXDestroyArea(void *pModule, dword nAreaID)
{
	if(!nAreaID || nAreaID == OBJECT_INVALID)
		return;
	if(!pServInternal)
		InitConstants();
	areas.Log(0, "Unregistering area %08lX\n", nAreaID);
	void *pArray = ((dword *)pModule+0x6);
	CExoArrayList__Remove(pArray, nAreaID);
	areas.Log(0, "Destroying area %08lX\n", nAreaID);
	void *pArea = GetAreaByGameObjectID((void *)pServInternal, nAreaID);
	CNWSArea__Destructor(pArea);
}

DWORD FindSaveChar()
{
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x6A) &&
			(ptr[1] == (char) 0xFF) &&
			(ptr[7] == (char) 0x64) &&
			(ptr[8] == (char) 0xA1) &&
			(ptr[9] == (char) 0x00) &&
			(ptr[0x2F] == (char) 0x52) &&
			(ptr[0x30] == (char) 0x89) &&
			(ptr[0x31] == (char) 0x7C) &&
			(ptr[0x32] == (char) 0x24) &&
			(ptr[0x33] == (char) 0x2C) &&
			(ptr[0x34] == (char) 0x89) &&
			(ptr[0x35] == (char) 0x74) &&
			(ptr[0x36] == (char) 0x24) &&
			(ptr[0x37] == (char) 0x1C)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

int HookFunctions()
{
	DWORD org_SaveChar = FindSaveChar();
	
	if (org_SaveChar)
	{
		pServThis = *(dword*)(org_SaveChar + 0x19);
		pScriptThis = pServThis - 8;
	}
	
	*(dword*)&pCNWSArea__CNWSArea = 0x0050A2E0;
	*(dword*)&pCNWSArea__LoadArea = 0x0050C380;
	*(dword*)&pCExoArrayList__Add = 0x0048F480;
	*(dword*)&pCNWSArea__Destructor = 0x0050A780;
	*(dword*)&pGetAreaByGameObjectID = 0x0045C0C0;
	*(dword*)&pCExoArrayList__Remove = 0x004D0D50;

	return (org_SaveChar && pServThis && pScriptThis);
}

void InitConstants()
{
	pServInternal = *(*(*(dword***)pServThis + 1) + 1);
}