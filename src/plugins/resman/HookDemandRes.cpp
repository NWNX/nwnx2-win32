/***************************************************************************
    NWN Resource Manager  - Hook DemandRes function in the server
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

#include "HookDemandRes.h"
#include "madCHook.h"
#include "NWNXResMan.h"
#include "NwnDefines.h"

extern CNWNXResMan resman;

void (*RetrieveResEntryNextHook)();
void (*DemandResNextHook)();

NwnResType lastResType;
char lastResRef[17];

void __declspec(naked) RetrieveResEntryHookProc()
{
	__asm {

		push ecx
		push edx
		push ebx
		push ebp
 		push esi
        push edi

		mov eax, dword ptr ss:[esp+0x18+0x10]
		push eax
		mov eax, dword ptr ss:[esp+0x1C+0x0C]
		push eax
		mov eax, dword ptr ss:[esp+0x20+0x08]
		push eax
		mov eax, dword ptr ss:[esp+0x24+0x4]
		push eax
		call RetrieveResEntry
		add esp, 0x10
		test eax, eax

		pop edi
		pop esi
		pop ebp
		pop ebx
		pop edx
		pop ecx

		jnz end

		mov eax, dword ptr ss:[esp+0x00+0x10]
		push eax
		mov eax, dword ptr ss:[esp+0x04+0x0C]
		push eax
		mov eax, dword ptr ss:[esp+0x08+0x08]
		push eax
		mov eax, dword ptr ss:[esp+0x0C+0x04]
		push eax

		call RetrieveResEntryNextHook

end:
	    retn 0x10
	}
}

void __declspec(naked) DemandResHookProc()
{
	__asm {

		push ecx
		push edx
		push ebx
		push ebp
 		push esi
        push edi

		mov eax, dword ptr ss:[esp+0x18+0x1C]
		push eax
		mov eax, dword ptr ss:[esp+0x1C+0x04]
		push eax
		call DemandRes
		add esp, 0x8
		test eax, eax
		
		pop edi
		pop esi
		pop ebp
		pop ebx
		pop edx
		pop ecx

		jnz end

		mov eax, dword ptr ss:[esp+0x00+0x04]
		push eax
		call DemandResNextHook
end:
	    retn 4
	}
}

int RetrieveResEntry(char* resRef, NwnResType resType, void ** v1, void** v2)
{
	lastResType = resType;
	memcpy(lastResRef, resRef, 16);
	lastResRef[16] = 0x0;
	return 0;
}

char* DemandRes(CResStruct* cRes, char* resName)
{
	return resman.DemandRes(cRes, lastResRef, lastResType);
}

DWORD FindHookRetrieveResEntry()
{
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x51) &&
			(ptr[1] == (char) 0x53) &&
			(ptr[2] == (char) 0x8B) &&
			(ptr[3] == (char) 0x5C) &&
			(ptr[4] == (char) 0x24) &&
			(ptr[5] == (char) 0x0C) &&
			(ptr[6] == (char) 0x55) &&
			(ptr[7] == (char) 0x8B) && 
  			(ptr[8] == (char) 0x6C) &&
  			(ptr[9] == (char) 0x24) &&
  			(ptr[10] == (char) 0x14)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

DWORD FindHookDemandRes()
{
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x56) &&
			(ptr[1] == (char) 0x57) &&
			(ptr[2] == (char) 0x8B) &&
			(ptr[3] == (char) 0x7C) &&
			(ptr[4] == (char) 0x24) &&
			(ptr[5] == (char) 0x0C) &&
			(ptr[6] == (char) 0x85) &&
			(ptr[7] == (char) 0xFF) && 
  			(ptr[8] == (char) 0x8B) &&
  			(ptr[9] == (char) 0xF1) &&
  			(ptr[10] == (char) 0x0F) &&
  			(ptr[11] == (char) 0x84) &&
  			(ptr[16] == (char) 0x83) &&
			(ptr[17] == (char) 0x7F)
			)

			return (DWORD) ptr;
		else
			ptr++;

	}
	return NULL;
}

void HookFunctions()
{
	int success1 = false;
	int success2 = false;
	DWORD old_RetrieveResEntry = FindHookRetrieveResEntry();
	DWORD old_DemandRes = FindHookDemandRes();
	if (old_RetrieveResEntry)
		success1 = HookCode((PVOID) old_RetrieveResEntry, RetrieveResEntryHookProc, (PVOID*) &RetrieveResEntryNextHook);
	if (old_DemandRes)
		success2= HookCode((PVOID) old_DemandRes, DemandResHookProc, (PVOID*) &DemandResNextHook);

	// Log file
	resman.WriteLogHeader();

	if (success1)
		fprintf(resman.m_fFile, "* RetrieveResEntry hooked at %x.\n", old_RetrieveResEntry);
	else
		fprintf(resman.m_fFile, "* Could not find RetrieveResEntry function or hook failed: %x\n", old_RetrieveResEntry);
	if (success2)
		fprintf(resman.m_fFile, "* DemandRes hooked at %x.\n", old_DemandRes);
	else
		fprintf(resman.m_fFile, "* Could not find DemandRes function or hook failed: %x\n", old_DemandRes);

	fprintf(resman.m_fFile, "\n");

	lastResRef[0] = 0x0;
	return;
}


