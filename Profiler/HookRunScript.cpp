/***************************************************************************
    NWN Extender - Hook run script function in the server
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com

	With performance optimization ideas from FastFrench.

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

#include "HookRunScript.h"
#include "madCHook.h"
#include "hash.h"
#include "NWNXProfiler.h"

#define MAX_CALLDEPTH 128

extern CNWNXProfiler profiler;

void (*RunScriptNextHook)();
void (*CrossAreaNextHook)();
void (*PathfindNextHook)();

hash_table scriptHash;

int iColumn;
int iCallDepth;
unsigned int iScriptCounter;
unsigned int iTotalRuntime;
unsigned int iTotalLast;
bool emptyScript;
char scriptName[MAX_CALLDEPTH][17];
LARGE_INTEGER liFrequency;
LARGE_INTEGER liLast[MAX_CALLDEPTH];
LARGE_INTEGER liLastStatistic;

struct sScriptData 
{
	unsigned long ulCalls;
	DWORD dwElapsedTime;
	char updated;
};

void printer(char *string, void *data)
{
	sScriptData* scriptData = (sScriptData*)data;
	
	int iLen = strlen(string);
	int iMsec = (int)scriptData->dwElapsedTime / 1000;
	fprintf(profiler.m_fFile, "%s", string);
	if (iLen > 7 && iLen < 16)
		fprintf(profiler.m_fFile, "\t");
	else if (iLen < 8)
		fprintf(profiler.m_fFile, "\t\t");

	if (scriptData->updated)
		fprintf(profiler.m_fFile, "%10d msec %6d calls *| ", iMsec, scriptData->ulCalls);
	else
	    fprintf(profiler.m_fFile, "%10d msec %6d calls  | ", iMsec, scriptData->ulCalls);
	if (iColumn == 1)
	{
		iColumn = 0;
		fprintf(profiler.m_fFile, "\n");
	}
	else
		iColumn++;

	iTotalRuntime += iMsec;
	scriptData->updated = FALSE;
}

void FlushStatistics(DWORD dwStatisticMsec)
{
	if (ftell(profiler.m_fFile) > profiler.m_maxLogSizeKB)
	{	
		fclose(profiler.m_fFile);
		profiler.m_fFile = fopen (profiler.m_LogFile, "w+");
		profiler.WriteLogHeader();
		fprintf(profiler.m_fFile, "* Logfile hit maximum size limit, starting again.\n");
	}
	
	fprintf(profiler.m_fFile, "\nCurrent statistics\n");
	fprintf(profiler.m_fFile, "-----------------------------------------------------------------------------------------------\n");
	enumerate(&scriptHash, printer);
	if (iColumn != 0)
	{
		fprintf(profiler.m_fFile, "\n");
		iColumn = 0;
	}
	fprintf(profiler.m_fFile, "-----------------------------------------------------------------------------------------------\n");
	fprintf(profiler.m_fFile, "Elapsed time                : %d msec\n", dwStatisticMsec);
	fprintf(profiler.m_fFile, "Runtime delta               : %d msec\n", iTotalRuntime - iTotalLast);
	fprintf(profiler.m_fFile, "Total cumulative runtime    : %d msec\n", iTotalRuntime);
	fprintf(profiler.m_fFile, "Total number of scriptcalls : %d\n\n", iScriptCounter);
	iTotalLast = iTotalRuntime;
	iTotalRuntime = 0;
	fflush(profiler.m_fFile);
}

void StopTimer()
{
	if (emptyScript)
		return;

	sScriptData* scriptData;
	DWORD dwPerfElapsed;
	DWORD dwStatisticMsec;

	LARGE_INTEGER liCurrent;
	QueryPerformanceCounter(&liCurrent);
	dwPerfElapsed = (DWORD) (((liCurrent.QuadPart - liLast[iCallDepth].QuadPart) * 1000000) / liFrequency.QuadPart);

	//fprintf(profiler.m_fFile, "(stop %s, %d microsec)\n", scriptName[iCallDepth], dwPerfElapsed);

	scriptData = (sScriptData*)lookup(scriptName[iCallDepth], &scriptHash);
	if (!scriptData)
	{
		scriptData = new sScriptData;
		scriptData->dwElapsedTime = dwPerfElapsed;
		scriptData->ulCalls = 1;
		scriptData->updated = TRUE;
	}
	else
	{
		scriptData->dwElapsedTime += dwPerfElapsed;
		scriptData->ulCalls++;
		scriptData->updated = TRUE;
	}
	insert(scriptName[iCallDepth], (void*)scriptData, &scriptHash);	

	dwStatisticMsec = (DWORD) (((liCurrent.QuadPart - liLastStatistic.QuadPart) * 1000) / liFrequency.QuadPart);
	if (dwStatisticMsec > 10000)
	{
		QueryPerformanceCounter(&liLastStatistic);
		FlushStatistics(dwStatisticMsec);
	}

	if (iCallDepth > -1)
		iCallDepth--;
}

void myRunScript(char *str)
{
	if (str != NULL)
	{
		if (iCallDepth < MAX_CALLDEPTH - 1)
			iCallDepth++;
		else
			fprintf(profiler.m_fFile, "Maximum call depth reached!\n");

		emptyScript = false;
		strncpy(scriptName[iCallDepth], str, 16);
		scriptName[iCallDepth][16] = 0x0;
		iScriptCounter++;

		if (profiler.m_LogLevel == profiler.logCallstack)
		{
		  fprintf(profiler.m_fFile, "%s (calldepth %d)\n", str, iCallDepth);
		  fflush(profiler.m_fFile);
		}
		QueryPerformanceCounter(&liLast[iCallDepth]);
	}
	else
		emptyScript = true;
}

void myRunScriptPart(char *str)
{
	if (str != NULL)
	{
		if (iCallDepth < MAX_CALLDEPTH - 1)
			iCallDepth++;
		else
			fprintf(profiler.m_fFile, "Maximum call depth reached!\n");

		emptyScript = false;
		scriptName[iCallDepth][0] = '>';
		scriptName[iCallDepth][1] = 0x0;
		strncat(scriptName[iCallDepth], str, 15);
		scriptName[iCallDepth][16] = 0x0;
		iScriptCounter++;

		if (profiler.m_LogLevel == profiler.logCallstack)
		{
		  fprintf(profiler.m_fFile, "%s (calldepth %d, scriptpart)\n", str, iCallDepth);
		  fflush(profiler.m_fFile);
		}
		QueryPerformanceCounter(&liLast[iCallDepth]);
	}
	else
		emptyScript = true;
}

void __declspec(naked) RunScriptHookProc()
{
	__asm {

		push ecx	  // save register contents
		push edx
		push ebx
		push esi
		push edi
		push ebp	  // prolog 1
        mov ebp, esp  // prolog 2

		// fetch script name
		mov esi, ecx
		mov eax, [esi+0xC]
		lea eax, [eax+eax*8]
		lea ecx, [esi+eax*4+0x28]
		//mov ecx, dword ptr ss:[esp+0x24]
		mov eax, dword ptr ss:[ecx]
		test eax, eax
		je scriptpart

        cmp byte ptr ds:[eax],0
		je invalidscript

		push eax
		call myRunScript
		add esp, 4
		jmp original

scriptpart:
		add ecx, 0x18
		mov eax, dword ptr ss:[ecx]
		test eax, eax
		je invalidscript
		push eax
		call myRunScriptPart
		add esp, 4

original:
		pop ebp		// restore register contents
		pop edi		
		pop esi
		pop ebx
		pop edx
		pop ecx

		mov eax, dword ptr ss:[esp+0x4] // arg 1
		push eax
		call RunScriptNextHook // call original function
		
		// save return value of StartConditional() script
		push eax 
		push 0
		call StopTimer
		jmp cleanup

invalidscript:
		pop ebp		// restore register contents
		pop edi		
		pop esi
		pop ebx
		pop edx
		pop ecx

		mov eax, dword ptr ss:[esp+0x4] // arg 1
		push eax
		call RunScriptNextHook // call original function
		
		// save return value of StartConditional() script
		push eax 
		push 0

cleanup:
		// cleanup stack
		add esp, 0x8
		pop eax
		add esp, 0x4
		push eax

		// put return value of StartConditional() script in EAX
		sub esp, 0x8
		pop eax
		add esp, 0x4

        retn
	}
}

void MyCrossArea(char *gameObject)
{
    char* tag = (char*)(*(int*)(gameObject+0x18));
	//fprintf(profiler.m_fFile, "MyCrossArea: %s\n", tag);

	if (tag != NULL)
	{
		if (iCallDepth < MAX_CALLDEPTH - 1)
			iCallDepth++;
		else
			fprintf(profiler.m_fFile, "Maximum call depth reached!\n");

		emptyScript = false;
		scriptName[iCallDepth][0] = '@';
		scriptName[iCallDepth][1] = 0x0;
		strncat(scriptName[iCallDepth], tag, 15);
		scriptName[iCallDepth][16] = 0x0;
		iScriptCounter++;

		if (profiler.m_LogLevel == profiler.logCallstack)
		{
			fprintf(profiler.m_fFile, "%s (calldepth %d, pathfinding)\n", tag, iCallDepth);
			fflush(profiler.m_fFile);
		}
		QueryPerformanceCounter(&liLast[iCallDepth]);
	}
	else
		emptyScript = true;
}


void __declspec(naked) CrossAreaHookProc()
{
	__asm {

		push ecx	  // save register contents
		push edx
		push ebx
		push esi
		push edi
		push ebp	  // prolog 1
        mov ebp, esp  // prolog 2

		mov eax, dword ptr ss:[esp+0x1c] // recursion depth
		cmp al, 0
		jne skip

		mov eax, dword ptr ss:[esp+0x5c] // param 1
		push eax
		call MyCrossArea
		add esp, 0x4

		pop ebp		// restore register contents
		pop edi		
		pop esi
		pop ebx
		pop edx
		pop ecx
		
		mov eax, dword ptr ss:[esp+0xc] // arg 3
		push eax
		mov eax, dword ptr ss:[esp+0xc] // arg 2
		push eax
		mov eax, dword ptr ss:[esp+0xc] // arg 1
		push eax

		call CrossAreaNextHook // call original function

		// save return value 
		push eax 
		push 0

		call StopTimer
		jmp cleanup

skip:
		pop ebp		// restore register contents
		pop edi		
		pop esi
		pop ebx
		pop edx
		pop ecx
		
		mov eax, dword ptr ss:[esp+0xc] // arg 3
		push eax
		mov eax, dword ptr ss:[esp+0xc] // arg 2
		push eax
		mov eax, dword ptr ss:[esp+0xc] // arg 1
		push eax

		call CrossAreaNextHook // call original function

		// save return value 
		push eax 
		push 0

cleanup:
		// cleanup stack
		add esp, 0x8
		pop eax
		add esp, 0xc
		push eax

		// put return value of StartConditional() script in EAX
		sub esp, 0x10
		pop eax
		add esp, 0xc

        retn

	}
}

void MyPathfind(char *gameArea)
{
    char* tag = (char*) gameArea+0xb4;
	//fprintf(profiler.m_fFile, "MyPathfind: %s\n", tag);

	if (tag != NULL)
	{
		if (iCallDepth < MAX_CALLDEPTH - 1)
			iCallDepth++;
		else
			fprintf(profiler.m_fFile, "Maximum call depth reached!\n");

		emptyScript = false;
		scriptName[iCallDepth][0] = '$';
		scriptName[iCallDepth][1] = 0x0;
		strncat(scriptName[iCallDepth], tag, 15);
		scriptName[iCallDepth][16] = 0x0;
		iScriptCounter++;

		if (profiler.m_LogLevel == profiler.logCallstack)
		{
		  fprintf(profiler.m_fFile, "%s (calldepth %d, pathfinding)\n", tag, iCallDepth);
		  fflush(profiler.m_fFile);
		}
		QueryPerformanceCounter(&liLast[iCallDepth]);
	}
	else
		emptyScript = true;

}


void __declspec(naked) PathfindHookProc()
{
	__asm {

		push ecx	  // save register contents
		push edx
		push ebx
		push esi
		push edi
		push ebp	  // prolog 1
        mov ebp, esp  // prolog 2

		mov eax, dword ptr ss:[esp+0x28] // recursion depth
		cmp al, 0
		jne skip

		mov eax, dword ptr ss:[esp+0x20] // param 1
		push eax
		call MyPathfind
		add esp, 0x4

		pop ebp		// restore register contents
		pop edi		
		pop esi
		pop ebx
		pop edx
		pop ecx
		
		mov eax, dword ptr ss:[esp+0x30] // arg 12
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 11
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 10
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 9
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 8
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 7
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 6
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 5
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 4
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 3
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 2
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 1
		push eax

		call PathfindNextHook // call original function

		// save return value 
		push eax 
		push 0

		call StopTimer
		jmp cleanup

skip:
		pop ebp		// restore register contents
		pop edi		
		pop esi
		pop ebx
		pop edx
		pop ecx
		
		mov eax, dword ptr ss:[esp+0x30] // arg 12
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 11
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 10
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 9
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 8
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 7
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 6
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 5
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 4
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 3
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 2
		push eax
		mov eax, dword ptr ss:[esp+0x30] // arg 1
		push eax

		call PathfindNextHook // call original function

		// save return value 
		push eax 
		push 0

cleanup:
		// cleanup stack
		add esp, 0x8
		pop eax
		add esp, 0x30 // number of parameters * 4
		push eax

		// put return value of StartConditional() script in EAX
		sub esp, 0x34 // number of parameters * 4 + 4
		pop eax
		add esp, 0x30 // number of parameters * 4

        retn
	}
}


DWORD FindHookRunScript()
{
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[24] == (char) 0x53) &&
			(ptr[25] == (char) 0x55) &&
			(ptr[26] == (char) 0x56) &&
			(ptr[27] == (char) 0x8B) &&
			(ptr[28] == (char) 0xF1) &&
			(ptr[29] == (char) 0x8B) &&
			(ptr[30] == (char) 0x86) &&
			(ptr[35] == (char) 0x8B) && 
  			(ptr[36] == (char) 0xAE) &&
  			(ptr[41] == (char) 0x57) &&
  			(ptr[42] == (char) 0xC7) &&
  			(ptr[43] == (char) 0x06) &&
			(ptr[44] == (char) 0x00)
			)

			return (DWORD) ptr;
		else
			ptr++;

	}
	return NULL;
}

DWORD FindHookCrossAreaPathFind()
{
	/*
	CNWSModule::InterAreaDFS(int depth,int,CPathfindInformation *)

	004CC290  /$ 83EC 10        SUB ESP,10
	004CC293  |. 53             PUSH EBX
	004CC294  |. 8B5C24 18      MOV EBX,DWORD PTR SS:[ESP+18]
	004CC298  |. 55             PUSH EBP
	004CC299  |. 56             PUSH ESI
	004CC29A  |. 8B7424 28      MOV ESI,DWORD PTR SS:[ESP+28]
	004CC29E  |. 8B86 9C000000  MOV EAX,DWORD PTR DS:[ESI+9C]
	004CC2A4  |. 8BE9           MOV EBP,ECX
	004CC2A6  |. 8B0C98         MOV ECX,DWORD PTR DS:[EAX+EBX*4]
	004CC2A9  |. 3B4E 60        CMP ECX,DWORD PTR DS:[ESI+60]
	004CC2AC  |. 57             PUSH EDI
	*/

	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x83) &&
			(ptr[1] == (char) 0xEC) &&
			(ptr[3] == (char) 0x53) &&
			(ptr[4] == (char) 0x8B) &&
			(ptr[5] == (char) 0x5C) &&
			(ptr[6] == (char) 0x24) &&
  			(ptr[8] == (char) 0x55) &&
  			(ptr[9] == (char) 0x56) &&
  			(ptr[10] == (char) 0x8B) &&
  			(ptr[11] == (char) 0x74) &&
  			(ptr[12] == (char) 0x24) &&
  			(ptr[14] == (char) 0x8B) &&
  			(ptr[15] == (char) 0x86) &&
  			(ptr[20] == (char) 0x8B) &&
  			(ptr[21] == (char) 0xE9) &&
  			(ptr[22] == (char) 0x8B) &&
  			(ptr[23] == (char) 0x0C) &&
  			(ptr[24] == (char) 0x98) &&
  			(ptr[25] == (char) 0x3B) &&
  			(ptr[26] == (char) 0x4E)
			)

			return (DWORD) ptr;
		else
			ptr++;

	}
	return NULL;
}

DWORD FindHookPathFind()
{
	/*
	CNWTileSurfaceMesh::IntraTileDFS(CNWTile *,CNWArea *,CPathfindInformation *,int,float,int,float,float,float,float,float,int)

	0054FAC0  /$ 83EC 10        SUB ESP,10
	0054FAC3  |. 53             PUSH EBX
	0054FAC4  |. 55             PUSH EBP
	0054FAC5  |. 56             PUSH ESI
	0054FAC6  |. 57             PUSH EDI
	0054FAC7  |. 8BF9           MOV EDI,ECX
	0054FAC9  |. 8B47 68        MOV EAX,DWORD PTR DS:[EDI+68]
	0054FACC  |. 85C0           TEST EAX,EAX
	0054FACE  |. 75 0F          JNZ SHORT nwserver.0054FADF
	0054FAD0  |. 8B87 B0000000  MOV EAX,DWORD PTR DS:[EDI+B0]
	0054FAD6  |. 85C0           TEST EAX,EAX
	0054FAD8  |. 75 05          JNZ SHORT nwserver.0054FADF
	0054FADA  |. E8 B1150000    CALL nwserver.00551090
	0054FADF  |> A1 64156200    MOV EAX,DWORD PTR DS:[621564]
	0054FAE4  |. D94424 3C      FLD DWORD PTR SS:[ESP+3C]
	0054FAE8  |. 8B97 F4000000  MOV EDX,DWORD PTR DS:[EDI+F4]
	0054FAEE  |. 8B7424 30      MOV ESI,DWORD PTR SS:[ESP+30]
	0054FAF2  |. 8B8F E8000000  MOV ECX,DWORD PTR DS:[EDI+E8]
	0054FAF8  |. 8B6C24 2C      MOV EBP,DWORD PTR SS:[ESP+2C]
	0054FAFC  |. 03D0           ADD EDX,EAX
	*/

	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x600000)
	{
		if ((ptr[0] == (char) 0x83) &&
			(ptr[1] == (char) 0xEC) &&
			(ptr[2] == (char) 0x10) &&
			(ptr[3] == (char) 0x53) &&
			(ptr[4] == (char) 0x55) &&
			(ptr[5] == (char) 0x56) &&
			(ptr[6] == (char) 0x57) &&
  			(ptr[7] == (char) 0x8B) &&
  			(ptr[8] == (char) 0xF9) &&
  			(ptr[9] == (char) 0x8B) &&
  			(ptr[10] == (char) 0x47) &&
  			(ptr[12] == (char) 0x85) &&
  			(ptr[13] == (char) 0xC0) &&
  			(ptr[14] == (char) 0x75) &&
  			(ptr[15] == (char) 0x0F) &&
  			(ptr[16] == (char) 0x8B) &&
  			(ptr[17] == (char) 0x87) &&
  			(ptr[22] == (char) 0x85) &&
  			(ptr[23] == (char) 0xC0) &&
  			(ptr[24] == (char) 0x75) &&
  			(ptr[25] == (char) 0x05) &&
  			(ptr[26] == (char) 0xE8) &&
  			(ptr[31] == (char) 0xA1) &&
  			(ptr[36] == (char) 0xD9) &&
  			(ptr[37] == (char) 0x44) &&
  			(ptr[38] == (char) 0x24) &&
  			(ptr[40] == (char) 0x8B) &&
  			(ptr[41] == (char) 0x97) &&
  			(ptr[46] == (char) 0x8B) &&
  			(ptr[47] == (char) 0x74) &&
  			(ptr[48] == (char) 0x24) &&
  			(ptr[50] == (char) 0x8B) &&
  			(ptr[51] == (char) 0x8F) &&
  			(ptr[56] == (char) 0x8B) &&
  			(ptr[57] == (char) 0x6C) &&
  			(ptr[58] == (char) 0x24)
			)

			return (DWORD) ptr;
		else
			ptr++;

	}
	return NULL;
}

void Release()
{
	LARGE_INTEGER liCurrent;
	QueryPerformanceCounter(&liCurrent);
	DWORD dwStatisticMsec = (DWORD) (((liCurrent.QuadPart - liLastStatistic.QuadPart) * 1000) / liFrequency.QuadPart);
	FlushStatistics(dwStatisticMsec);	
}

void HookRunScript()
{
	int success = false;
	int success_crossarea = false;
	int success_pathfind = false;

	DWORD old_RunScript = FindHookRunScript();
	DWORD old_CrossAreaPathFind = FindHookCrossAreaPathFind();

	DWORD old_PathFind = FindHookPathFind();

	if (old_RunScript)
		success = HookCode((PVOID) old_RunScript, RunScriptHookProc, (PVOID*) &RunScriptNextHook);

	if (old_CrossAreaPathFind)
		success_crossarea = HookCode((PVOID) old_CrossAreaPathFind, CrossAreaHookProc, (PVOID*) &CrossAreaNextHook);

	if (old_PathFind)
		success_pathfind = HookCode((PVOID) old_PathFind, PathfindHookProc, (PVOID*) &PathfindNextHook);

	// Performance analysis variables
	iColumn = 0;
	iTotalRuntime = 0;
	iTotalLast = 0;
	iScriptCounter = 0;
	iCallDepth = -1;
	construct_table(&scriptHash, 2048);
	QueryPerformanceFrequency(&liFrequency);
	QueryPerformanceCounter(&liLastStatistic);

	// Log file
	profiler.WriteLogHeader();

	if (success)
		fprintf(profiler.m_fFile, "* RunScript hooked (symbol: >).\n");
	else
		fprintf(profiler.m_fFile, "* Could not find RunScript function or hook failed: %x\n", old_RunScript);

	if (success_crossarea)
		fprintf(profiler.m_fFile, "* Cross area pathfinding hooked (symbol: @)\n");
	else
		fprintf(profiler.m_fFile, "* Could not find Cross area pathfinding function or hook failed: %x\n", old_CrossAreaPathFind);

	if (success_pathfind)
		fprintf(profiler.m_fFile, "* Tile pathfinding hooked (symbol: $)\n");
	else
		fprintf(profiler.m_fFile, "* Could not find pathfinding function or hook failed: %x\n", old_PathFind);
	fflush(profiler.m_fFile);

	return;
}


