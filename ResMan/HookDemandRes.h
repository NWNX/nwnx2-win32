/***************************************************************************
    NWN Extender - Hook Demandres function in the server
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

#if !defined(HookDemandRes_h_)
#define HookDemandRes_h_

#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "NwnDefines.h"

struct CResStruct
{
	char* pClass;			// 0x0
	long unk2;				// 0x4
	char id1;				// 0x8
	char id2;				// 0x9
	char id3;				// 0xA
	char id4;				// 0xB
	long unk4;				// 0xC
	char* pResData;			// 0x10
	char* pResName;			// 0x14
	unsigned long resSize;	// 0x18
	long loaded;			// 0x1C
	char* unk5;				// 0x20
	char* unk6;				// 0x24
	char* unk7;				// 0x28
	long loaded2;			// 0x2C
	unsigned long resSize2;	// 0x30
	char* pResData2;		// 0x34

};

struct CResEntry
{
	char* resName1;
	char* resName2;
	char* resName3;
	char* resName4;
	CResStruct* resStruct;
	long unk6; // _04401040;
	long unk7;
};


void RetrieveResEntryHookProc();
void HookFunctions();
DWORD FindHookRetrieveResEntry();

int RetrieveResEntry(char* resRef, NwnResType resType, void ** v1, void** v2);

void DemandResHookProc();
DWORD FindHookDemandRes();
char* DemandRes(CResStruct* cRes, char* resName);

#endif

