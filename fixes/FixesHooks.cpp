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

bool CompareVarLists (CNWObjectVarList *pVarList1, CNWObjectVarList *pVarList2) {
    if (pVarList1->VarCount == 0 && pVarList2->VarCount == 0)
        return true;

    for (int i = 0; i < pVarList1->VarCount; i++) {
		bool bFound = false;
		CNWObjectVarListElement *pVar1 = &pVarList1->VarList[i];

        for (int j = 0; j < pVarList2->VarCount; j++) {
			CNWObjectVarListElement *pVar2 = &pVarList2->VarList[j];

            if (pVar1->nVarType == pVar2->nVarType &&
                strcmp(pVar1->sVarName.Text, pVar2->sVarName.Text) == 0) {

				bFound = true;

				//Compare values
                switch (pVar1->nVarType) {
				case 1:  //int
                        if ((int)(pVar1->nVarValue) != (int)(pVar2->nVarValue)) {
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: int value '%s' %d != %d\n", pVar1->sVarName.Text,
                                      (int)(pVar1->nVarValue), (int)(pVar2->nVarValue));
#endif
                            return false;
                        }
					break;

				case 2:  //float
                        if ((float)(pVar1->nVarValue) != (float)(pVar2->nVarValue)) {
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: float value '%s' %.04f != %.04f\n", pVar1->sVarName.Text,
                                      (float)(pVar1->nVarValue), (float)(pVar2->nVarValue));
#endif
                            return false;
                        }
					break;

				case 3:  //string
                        // both pointers are equal or both are null
                        if ((char **)(pVar1->nVarValue) == (char **)(pVar2->nVarValue))
					break;
                        if ((char **)(pVar1->nVarValue) == NULL || (char **)(pVar2->nVarValue) == NULL) {  //the variable is not set on one of the objects
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: string value '%s' is not set on one of the objects\n", pVar1->sVarName.Text);
#endif
                            return false;
                        }

                        if (*(char **)(pVar1->nVarValue) == *(char **)(pVar2->nVarValue))  //equal pointers
                            break;
                        if (*(char **)(pVar1->nVarValue) == NULL || *(char **)(pVar2->nVarValue) == NULL) { //one of the variables is empty
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: string value '%s' is not set on one of the objects\n", pVar1->sVarName.Text);
#endif
                            return false;
                        }

                        if (strcmp(*(char **)(pVar1->nVarValue), *(char **)(pVar2->nVarValue)) != 0) {  //string values are not equal
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: string value '%s' '%s' != '%s'\n", pVar1->sVarName.Text,
                                      *(char **)(pVar1->nVarValue), *(char **)(pVar2->nVarValue));
#endif
                            return false;
                        }
					break;

				case 4:  //object
                        if ((dword)(pVar1->nVarValue) != (dword)(pVar2->nVarValue)) {
#ifdef NWNX_FIXES_DEBUG
                            fixes.Log(3, "blocking merge: object value '%s' %08X != %08X\n", pVar1->sVarName.Text,
                                      (dword)(pVar1->nVarValue), (dword)(pVar2->nVarValue));
#endif
                            return false;
                        }
					break;

				case 5:  //location
					break;
				}

                break;
			}
		}

        if (!bFound) {
#ifdef NWNX_FIXES_DEBUG
            fixes.Log(3, "blocking merge: local variable '%s' not found on one of the objects", pVar1->sVarName.Text);
#endif
            return false;
	}
	return 1;
}

    return true;
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
		if(!pVarList1 || !pVarList2) {
#ifdef NWNX_FIXES_DEBUG
                    fixes.Log(3, "blocking merge: one object has a variable list and the other does not\n");
#endif
                    return 0;
                }
		return (CompareVarLists(pVarList1, pVarList2) && CompareVarLists(pVarList2, pVarList1));
		//return lastRet;
	}
	else return lastRet;
}

// This doesn't seem ideal, but VS6's inline asm syntax is less than intuitive.
// Also I should really be using the nice struct definitions, but... it works!
char* PlayerListNoDMHookjmp1 = (char*)0x004510c4;
char* PlayerListNoDMHookjmp2 = (char*)0x00450f61;
__declspec(naked) void PlayerListNoDMHook()
{
  __asm {
  mov esi, eax
  cmp esi, ebp
  jz suppressresponse
  // cs_is_dm
  mov eax, [eax+0xC64]
  mov eax, [eax+0x78]
  test eax, eax
  jnz suppressresponse
  // cs_is_pc
  mov eax, [esi+0xC64]
  mov eax, [eax+0x74]
  test eax, eax
  jnz sendresponse
  // cre_master_id
  mov eax, [esi+0xB38]
  cmp eax, 7
  jnz sendresponse

  suppressresponse:
  jmp dword ptr [PlayerListNoDMHookjmp1]

  sendresponse:
  jmp dword ptr [PlayerListNoDMHookjmp2]
  }
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
	char *pSplitItem_Copy = (char *) asmhelp.FindFunctionBySignature("64 A1 00 00 00 00 6A FF 68 ** ** ** ** 50 64 89 25 00 00 00 00 53 8B 5C 24 14 85 DB 56 57 8B F9 0F 8E ** ** ** ** 3B 9F ** 02 00 00");
	fixes.Log(2, "SplitItem_Copy: %08lX\n", pSplitItem_Copy);
	char *pBuyItem = (char *) asmhelp.FindFunctionBySignature("6A FF 68 ** ** ** ** 64 A1 00 00 00 00 50 64 89 25 00 00 00 00 83 EC 08 8B 44 24 18 8B 40 0C 56 8B F1 8B 0D ** ** ** ** 8B 49 18");
	fixes.Log(2, "BuyItem: %08lX\n", pBuyItem);
	char *pMergeItems_RemoveItem = (char *) asmhelp.FindFunctionBySignature("8B F0 85 F6 74 76 8B 84 24 84 00 00 00 6A 01 50 8B CE E8");
	fixes.Log(2, "MergeItems_RemoveItem: %08lX\n", pMergeItems_RemoveItem);

	char *pAIActionDialogObject = (char *) asmhelp.FindFunctionBySignature("64 A1 00 00 00 00 6A FF 68 ** ** ** ** 50 64 89 25 00 00 00 00 83 EC 3C 53 55 56 8B F1 8B 06 57 FF 50 30");
	fixes.Log(2, "AIActionDialogObject: %08lX\n", pAIActionDialogObject);
	char *pGetDead = (char *) asmhelp.FindFunctionBySignature("56 8B F1 8B 06 FF 50 30 85 C0 74 3C 8B 16 8B CE FF 52 30 8B 88 D8 0A 00 00 85 C9 75 0B 8B C8 E8");
	fixes.Log(2, "GetDead: %08lX\n", pGetDead);

	char *pPlayModCharList = (char*)0x00546570;
	char *pPlayModCharListCode = "\xC2\x04\x00";
	char *pNoClassesHook = (char*)0x0045102d;
	char *pNoClassesHookCode = "\xB1\x00\x90\x90\x90\x90";
	char *pNoPortraitHook1 = (char*)0x00450fd4;
	char *pNoPortraitHook1Code = "\xB8\xFF\xFF\x00\x00\x90";
	char *pNoPortraitHook2 = (char*)0x00450ff4;
	char *pNoPortraitHook2Code = "\x6A\x10\x6A\x00\x68\x30\x32\x5F\x00\x68\x6F\x62\x6F\x64\x68\x70\x6F\x5F\x6E\x8B\xCF\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
	char *pNoDMHook = (char*)0x00450f57;

	if(fixes.GetConfInteger("hide_charlist_all"))
	{
		d_enable_write((dword) pPlayModCharList);
		memcpy(pPlayModCharList, pPlayModCharListCode, 3);
		fixes.Log(2, "* Suppressing character list response.\n");
	}
	if(fixes.GetConfInteger("hide_charlist_levels"))
	{
		d_enable_write((dword) pNoClassesHook);
		memcpy(pNoClassesHook, pNoClassesHookCode, 6);
		fixes.Log(2, "* Suppressing classes in character list.\n");
	}
	if(fixes.GetConfInteger("hide_charlist_portraits"))
	{
		d_enable_write((dword) pNoPortraitHook1);
		memcpy(pNoPortraitHook1, pNoPortraitHook1Code, 6);
		memcpy(pNoPortraitHook2, pNoPortraitHook2Code, 46);
		fixes.Log(2, "* Disguising portraits in character list.\n");
	}
	if(fixes.GetConfInteger("hide_charlist_dms"))
	{
		d_enable_write((dword) pNoDMHook);
		pNoDMHook[0] = (char)0xE9;
		*((int*)(&pNoDMHook[1])) = (int)&PlayerListNoDMHook - (int)pNoDMHook - 5;
	}

	if(pSplitItem_Copy && fixes.GetConfInteger("copy_vars"))
	{
		fixes.Log(2, "copy_vars = 1\n");
		d_enable_write((dword) pSplitItem_Copy);
		if(pSplitItem_Copy[0x5D]==0x6A) pSplitItem_Copy[0x5E] = 0x1;
		else fixes.Log(2, "Couldn't patch the SplitItem_Copy function\n");
	}

	if(pBuyItem && fixes.GetConfInteger("copy_vars"))
	{
		d_enable_write((dword) pBuyItem);
		if(pBuyItem[0xA4]==0x6A) pBuyItem[0xA5] = 0x1;
		else fixes.Log(2, "Couldn't patch the BuyItem function\n");
	}

	if(pMergeItems_RemoveItem && fixes.GetConfInteger("copy_vars"))
	{
		d_enable_write((dword) pMergeItems_RemoveItem);
		if(pMergeItems_RemoveItem[0xD]==0x6A) pMergeItems_RemoveItem[0xE] = 0x0;
		else fixes.Log(2, "Couldn't patch the MergeItems_RemoveItem function\n");
	}

	if(pAIActionDialogObject && fixes.GetConfInteger("keep_hidden_in_conversation"))
	{
		fixes.Log(2, "keep_hidden_in_conversation = 1\n");
		d_enable_write((dword) pAIActionDialogObject);
		if(pAIActionDialogObject[0x15C] == 0x6A && pAIActionDialogObject[0x15D] == 0x00)
		{
			memset(&pAIActionDialogObject[0x15C], 0x90, 11);
		}
		else fixes.Log(2, "Couldn't patch the AIActionDialogObject function\n");
	}

	if(pGetIsMergeable && fixes.GetConfInteger("compare_vars"))
	{
		fixes.Log(2, "compare_vars = 1\n");
		int hook_success = HookCode((PVOID) pGetIsMergeable, GetIsMergeableHookProc, (PVOID*) &GetIsMergeableNextHook);
		if(!hook_success)
			fixes.Log(2, "Couldn't hook the GetIsMergeable function\n");
	}

	if(pGetDead && fixes.GetConfInteger("hp_limit"))
	{
		d_enable_write((dword) pGetDead);
		char hpLimit = (char)fixes.GetConfInteger("hp_limit");
		if (hpLimit > 0) hpLimit = -10;
		fixes.Log(2, "HP limit = %d\n", hpLimit);
		pGetDead[0x3F] = hpLimit;
	}
	
	if(!(pGetIsMergeable && pSplitItem_Copy && pBuyItem && pMergeItems_RemoveItem))
	{
		fixes.Log(2, "Some of the functions could not be found\n");
		return false;
	}
	fixes.Log(2, "All functions set\n");
	return true;
}

