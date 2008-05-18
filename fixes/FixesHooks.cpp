/***************************************************************************
    Fixes plugin for NWNX  - hooks implementation
    (c) 2007 virusman (virusman@virusman.ru)

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

#include "FixesHooks.h"
#include "madCHook.h"
#include "NWNXFixes.h"
#include "NWNStructures.h"
#include "AssemblyHelper.h"

extern CNWNXFixes fixes;
AssemblyHelper asmhelp;

//Functions:
int (*pGetIsMergeable)(void *pItem1, void *pItem2);

void (*GetIsMergeableNextHook)();
unsigned long lastRet;

//#################### FUNCTIONS ####################

bool CompareVarLists(CNWObjectVarList *pVarList1, CNWObjectVarList *pVarList2)
{
	if(pVarList1->VarCount == 0) return 1;
	for(unsigned int i=0; i<pVarList1->VarCount; i++)
	{
		bool bFound = false;
		CNWObjectVarListElement *pVar1 = &pVarList1->VarList[i];
		for(unsigned int j=0; j<pVarList2->VarCount; j++)
		{
			CNWObjectVarListElement *pVar2 = &pVarList2->VarList[j];
			if((strcmp(pVar1->sVarName.Text, pVar2->sVarName.Text) == 0) && (pVar1->nVarType == pVar2->nVarType))
			{
				bFound = true;
				//Compare values
				switch(pVar1->nVarType)
				{
				case 1:  //int
					if((int)pVar1->nVarValue != (int)pVar2->nVarValue) return 0;
					break;
				case 2:  //float
					if((float)pVar1->nVarValue != (float)pVar2->nVarValue) return 0;
					break;
				case 3:  //string
					if(!(char **)pVar1->nVarValue && !(char **)pVar2->nVarValue) break;
					if(!(char **)pVar1->nVarValue || !(char **)pVar2->nVarValue) return 0;
					if(!*(char **)pVar1->nVarValue && !*(char **)pVar2->nVarValue) break;
					if(!*(char **)pVar1->nVarValue || !*(char **)pVar2->nVarValue) return 0;
					if(strcmp(*(char **)pVar1->nVarValue, *(char **)pVar2->nVarValue) != 0) return 0;
					break;
				case 4:  //object
					if((dword)pVar1->nVarValue != (dword)pVar2->nVarValue) return 0;
					break;
				case 5:  //location
					break;
				}
			}
		}
		if(!bFound) return 0;
	}
	return 1;
}


//#################### HOOKED FUNCTIONS ####################

int __stdcall GetIsMergeableHookProc(void *pItem2)
{
	void *pItem1;
	//void *pItem2;
	__asm {
		mov pItem1, ecx
		push pItem2
		call GetIsMergeableNextHook
		mov lastRet, eax
	}
	if(fixes.bHooked && lastRet)
	{
		//Check local vars
		CNWObjectVarList *pVarList1 = (CNWObjectVarList*)((char*)pItem1+0x10+0xD8);
		CNWObjectVarList *pVarList2 = (CNWObjectVarList*)((char*)pItem2+0x10+0xD8);
		if(!pVarList1 && !pVarList2) return 1;
		if(!pVarList1 || !pVarList2) return 0;
		return (CompareVarLists(pVarList1, pVarList2) && CompareVarLists(pVarList2, pVarList1));
	}
	return lastRet;
}


//#################### HOOK ####################

void
d_enable_write (unsigned long location)
{
	char *page;
	dword oldAlloc;
	page = (char *) location;
	/*page = (char *) (((int) page + PAGESIZE - 1) & ~(PAGESIZE - 1));
	page -= PAGESIZE;*/

	/*if (mprotect (page, PAGESIZE, PROT_WRITE | PROT_READ | PROT_EXEC))
		perror ("mprotect");*/
	VirtualProtect(page, 0xFF, PAGE_EXECUTE_READWRITE, &oldAlloc);
}

int FindHookFunctions()
{
	*(dword*)&pGetIsMergeable = asmhelp.FindFunctionBySignature("53 55 8B D9 8B 83 E0 01 00 00 85 C0 56 57 0F 84 ** ** ** ** 8B 74 24 14 8B 86 E0 01 00 00 85 C0");
	fixes.Log(2, "GetIsMergeable: %08lX\n", pGetIsMergeable);
	char *pSplitItem_Copy = (char *) asmhelp.FindFunctionBySignature("64 A1 00 00 00 00 6A FF 68 ** ** ** ** 50 64 89 25 00 00 00 00 53 8B 5C 24 14 85 DB 56 57 8B F9 0F 8E ** ** ** ** 3B 9F 80 02 00 00");
	fixes.Log(2, "SplitItem_Copy: %08lX\n", pSplitItem_Copy);
	char *pBuyItem = (char *) asmhelp.FindFunctionBySignature("6A FF 68 ** ** ** ** 64 A1 00 00 00 00 50 64 89 25 00 00 00 00 83 EC 08 8B 44 24 18 8B 40 0C 56 8B F1 8B 0D ** ** ** ** 8B 49 18");
	fixes.Log(2, "BuyItem: %08lX\n", pBuyItem);
	char *pMergeItems_RemoveItem = (char *) asmhelp.FindFunctionBySignature("8B F0 85 F6 74 76 8B 84 24 84 00 00 00 6A 01 50 8B CE E8");
	fixes.Log(2, "MergeItems_RemoveItem: %08lX\n", pMergeItems_RemoveItem);

	if(pSplitItem_Copy)
	{
		d_enable_write((dword) pSplitItem_Copy);
		if(pSplitItem_Copy[0x5D]==0x6A) pSplitItem_Copy[0x5E] = 0x1;
		else fixes.Log(2, "Couldn't patch the SplitItem_Copy function\n");
	}

	if(pBuyItem)
	{
		d_enable_write((dword) pBuyItem);
		if(pBuyItem[0xA4]==0x6A) pBuyItem[0xA5] = 0x1;
		else fixes.Log(2, "Couldn't patch the BuyItem function\n");
	}

	if(pMergeItems_RemoveItem)
	{
		d_enable_write((dword) pMergeItems_RemoveItem);
		if(pMergeItems_RemoveItem[0xD]==0x6A) pMergeItems_RemoveItem[0xE] = 0x0;
		else fixes.Log(2, "Couldn't patch the MergeItems_RemoveItem function\n");
	}

	if(pGetIsMergeable)
	{
		int hook_success = HookCode((PVOID) pGetIsMergeable, GetIsMergeableHookProc, (PVOID*) &GetIsMergeableNextHook);
		if(!hook_success)
			fixes.Log(2, "Couldn't hook the GetIsMergeable function\n");
	}
	if(!(pGetIsMergeable && pSplitItem_Copy && pBuyItem && pMergeItems_RemoveItem))
	{
		fixes.Log(2, "Some of the functions could not be found\n");
		return false;
	}
	fixes.Log(2, "All functions set\n");
	return true;
}

