/***************************************************************************
    scorcohook.cpp - Hooking of StoreCampaingObject and RetrieveCampaignObject
    Copyright (C) 2005 Ingmar Stieger (Papillon, papillon@blackdagger.com)

	Thanks go to Earandel for conducting the fundamental research and 
	for creating the hooks to SCO and RCO.

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
#include "scorcohook.h"
#include "madCHook.h"
#include "NWNXOdbc.h"

void (*OriginalSCO)();
void (*OriginalRCO)();
extern CNWNXODBC odbc;

void __declspec(naked) SCOHookProc()
{
	__asm {
		mov		eax, ecx
		mov		ecx, [ecx]
		test	ecx, ecx
		mov		ecx, eax
		jz		short bail_out
		
		mov		eax, dword ptr ss:[esp+18h]
		mov		edx, dword ptr ss:[esp+14h]
		push	eax
		mov		eax, dword ptr ss:[esp+4+10h]
		push	edx
		mov		edx, dword ptr ss:[esp+8+0ch]
		push	eax
		mov		eax, dword ptr ss:[esp+0ch+8]
		push	edx
		mov		edx, dword ptr ss:[esp+10h+4]
		push	eax
		push	edx

		// DB == NWNX ?
		mov		edx, [edx]
		mov		edx, [edx]
		cmp		edx, 0x584E574E
		pop		edx
		push	edx
		jz		sql

		call	OriginalSCO
		retn	18h

sql:
		call	SQLSCO
		add		esp, 18h
		retn	18h

bail_out:
		xor		eax,eax
		retn	18h
	}
}
void __declspec(naked) RCOHookProc()
{
	__asm {
		mov		eax, ecx
		mov		ecx, [ecx]
		test	ecx, ecx
		mov		ecx, eax
		jz		short bail_out

		mov		eax, [esp+14h]
		mov		edx, [esp+10h]
		push	eax
		mov		eax, [esp+4+0ch]
		push	edx
		mov		edx, [esp+8+8]
		push	eax
		mov		eax, [esp+0ch+4]
		push	edx
		push	eax

		// DB == NWNX ?
		mov		eax, [eax]
		mov		eax, [eax]
		cmp		eax, 0x584E574E
		pop		eax
		push	eax
		jz		sql

		call	OriginalRCO
		retn	14h

sql:
		call	SQLRCO
		add		esp, 14h
		retn	14h

bail_out:
		xor		eax,eax
		retn	14h
	}
}

void HookSCO(FILE* logFile, char* logFileName)
{
	DWORD dwError = 0;
	char szError[256];
	int success;

	DWORD Location = FindHookSCO();
	if (!Location)
	{
		fprintf (logFile, "not found.\n");
		return;
	}

	success = HookCode((PVOID) Location, SCOHookProc, (PVOID*) &OriginalSCO);
	if (success)
		fprintf (logFile, "hooked at %x\n", Location);
	else
		fprintf (logFile, "not hooked (%d - %s)!\n", dwError, szError);
}

void HookRCO(FILE* logFile, char* logFileName)
{
	DWORD dwError = 0;
	char szError[256];
	int success;

	DWORD Location = FindHookRCO();
	if (!Location)
	{
		fprintf (logFile, "not found.\n");
		return;
	}

	success = HookCode((PVOID) Location, RCOHookProc, (PVOID*) &OriginalRCO);
	if (success)
		fprintf (logFile, "hooked at %x\n", Location);
	else
		fprintf (logFile, "not hooked (%d - %s)!\n", dwError, szError);
}

DWORD FindHookSCO()
{
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x8b) &&
			(ptr[1] == (char) 0x09) &&
			(ptr[2] == (char) 0x85) &&
			(ptr[3] == (char) 0xc9) &&
			(ptr[4] == (char) 0x74) &&
			(ptr[5] == (char) 0x26)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

DWORD FindHookRCO()
{
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x8b) &&
			(ptr[1] == (char) 0x09) &&
			(ptr[2] == (char) 0x85) &&
			(ptr[3] == (char) 0xc9) &&
			(ptr[4] == (char) 0x74) &&
			(ptr[5] == (char) 0x21)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

int SQLSCO(char** database, char** key, char** player, int flags, BYTE* pData, int size)
{
	odbc.WriteScorcoData(*key, pData, size);
	return 1;
}

void* SQLRCO(char** database, char** key, char** player, int* arg4, int* size)
{
	*arg4 = 0x4f;
	return odbc.ReadScorcoData(*key, size);
}
