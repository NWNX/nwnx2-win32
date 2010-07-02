#include "stdafx.h"
#include "nwnx_combat.h"
#include "madchook.h"

extern CNWNXCombat NWNXCombat;

#define _log(a,b,...) if(a<=NWNXCombat.debugLevel)NWNXCombat.LOG(b,__VA_ARGS__)

void (*nwn_GetAttackModifierVersusNextHook)();
void (*nwn_GetMeleeAttackBonusNextHook)();
void (*nwn_GetWeaponFinesseNextHook)();
void (*nwn_CalculateOffhandAttacksNextHook)();
void (*nwn_HasFeatNextHook)();

void (*nwn_GetWeaponFocusNextHook)();
void (*nwn_GetEpicWeaponFocusNextHook)();
void (*nwn_GetWeaponSpecNextHook)();
void (*nwn_GetEpicWeaponSpecNextHook)();
void (*nwn_GetImprovedCritNextHook)();
void (*nwn_GetOverwhelmingCritNextHook)();
void (*nwn_GetDevastatingCritNextHook)();
void (*nwn_GetWeaponOfChoiceNextHook)();

void *pThis=NULL;
int i=0, a2=0, a3=0, a4=0;
CNWSObject *Defender=NULL;
CNWSItem *Item=NULL;

unsigned int stack;

void __declspec(naked)GetAttackModifierVersusHookProc() {
	_asm {
		pushad
		mov pThis, ecx
		mov Defender, eax
	}
	i = NWNXCombat.NWN_GetAttackModifierVersus_Override(((CNWSCreatureStats*)pThis)->cs_original, Defender);
	
	__asm {
		popad
		mov eax, i
		ret 4
	}//OMG IT WORKS! Really wish I knew why...

}

void __declspec(naked)GetMeleeAttackBonusHookProc() {
	__asm {
		pushad
		mov pThis, ecx;
		mov eax, [esp+0x24] 
		mov a2, eax
		mov eax, [esp+0x28] 
		mov a3, eax
		mov eax, [esp+0x2C] 
		mov a4, eax
	}

	i = NWNXCombat.NWN_GetMeleeAttackBonus((CNWSCreatureStats*)pThis, a2, a3, a4);
	_log(3, "meleeattackbonus: %d\n", i);

	__asm {
		popad
		mov eax, i
		ret 0Ch
	}
}

void __declspec(naked)GetWeaponFinesseHookProc() {
	__asm {
		pushad
		mov pThis, ecx
		mov eax, [esp+0x24] 
		mov Item, eax
	}

	i=0;
	if (pThis)
		i = NWNXCombat.NWN_GetWeaponFinesse((CNWSCreatureStats*)pThis, Item);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)CalculateOffhandAttacksHookProc() {
	__asm {
		pushad
		mov pThis, ecx
	}

	_log(3, "custom offhand func\n");
	i = NWNXCombat.NWN_CalculateOffHandAttacks((CNWSCombatRound*)pThis);
	_log(3, "custom offhand done: %d\n", i);

	__asm {
		popad
		mov eax, i
		retn
	}
}

void __declspec(naked)HasFeatHookProc() {
	__asm {
		pushad	
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov a2, eax
	}

	i = NWNXCombat.NWN_HasFeat((CNWSCreatureStats*)pThis, a2);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}


void __declspec(naked)GetWeaponFocusHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 0);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)GetEpicWeaponFocusHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 1);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)GetWeaponSpecHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 2);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)GetEpicWeaponSpecHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 3);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)GetImprovedCritHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 4);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)GetOverwhelmingCritHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 5);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)GetDevastatingCritHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 6);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void __declspec(naked)GetWeaponOfChoiceHook() {
	__asm	{
		pushad;
		mov pThis, ecx
		mov eax, [esp+0x24]
		mov Item, eax
	}

	i = NWNXCombat.NWN_GetWeaponFeat((CNWSCreatureStats*)pThis, Item, 7);

	__asm {
		popad
		mov eax, i
		retn 4
	}
}

void HookFunctions() {
	DWORD org_GetAttackModifierVersus = 0x00470F00;
	DWORD org_GetMeleeAttackBonus = 0x0046FB40;
	DWORD org_GetWeaponFinesse = 0x00481210;
	DWORD org_CalculateOffhandAttacks = 0x00530820;
	DWORD org_HasFeat = 0x0047ECF0;

	DWORD org_GetWeaponFocus= 0x004812E0;
	DWORD org_GetEpicWeaponFocus= 0x00481510;
	DWORD org_GetWeaponSpec= 0x004817E0;
	DWORD org_GetEpicWeaponSpec= 0x00481AA0;
	DWORD org_GetImprovedCrit= 0x00481D70;
	DWORD org_GetOverwhelmingCrit= 0x00481FB0;
	DWORD org_GetDevastatingCrit= 0x00482280;
	DWORD org_GetWeaponOfChoice= 0x0048CB10;


	//if (HookCode((PVOID) org_GetAttackModifierVersus, GetAttackModifierVersusHookProc, (PVOID*)&nwn_GetAttackModifierVersusNextHook)) _log(3, "* GetAttackModifierVersus hooked\n");
	//HookCode((PVOID) org_GetMeleeAttackBonus, GetMeleeAttackBonusHookProc, (PVOID*)&nwn_GetMeleeAttackBonusNextHook);
	//if (HookCode((PVOID) org_GetWeaponFinesse, GetWeaponFinesseHookProc, (PVOID*)&nwn_GetWeaponFinesseNextHook)) _log(3, "* GetWeaponFinnesse hooked\n");
	//if (HookCode((PVOID) org_CalculateOffhandAttacks, CalculateOffhandAttacksHookProc, (PVOID*)&nwn_CalculateOffhandAttacksNextHook)) _log(3, "* CalculateOffhandAttacks hooked\n");
	//if (HookCode((PVOID) org_HasFeat, HasFeatHookProc, (PVOID*)&nwn_HasFeatNextHook)) _log(3, "* HasFeat hooked\n");
	
	_log(3, "* GetWeaponFocusHook: %s\n", 
		HookCode((PVOID) org_GetWeaponFocus, GetWeaponFocusHook, (PVOID*)&nwn_GetWeaponFocusNextHook) ? "success" : "fail");
	_log(3, "* GetEpicWeaponFocusHook: %s\n", 
		HookCode((PVOID) org_GetEpicWeaponFocus, GetEpicWeaponFocusHook, (PVOID*)&nwn_GetEpicWeaponFocusNextHook) ? "success" : "fail");
	_log(3, "* GetWeaponSpecHook: %s\n", 
		HookCode((PVOID) org_GetWeaponSpec, GetWeaponSpecHook, (PVOID*)&nwn_GetWeaponSpecNextHook) ? "success" : "fail");
	_log(3, "* GetEpicWeaponSpecHook: %s\n", 
		HookCode((PVOID) org_GetEpicWeaponSpec, GetEpicWeaponSpecHook, (PVOID*)&nwn_GetEpicWeaponSpecNextHook) ? "success" : "fail");
	_log(3, "* GetImprovedCritHook: %s\n", 
		HookCode((PVOID) org_GetImprovedCrit, GetImprovedCritHook, (PVOID*)&nwn_GetImprovedCritNextHook) ? "success" : "fail");
	_log(3, "* GetOverwhelmingCritHook: %s\n", 
		HookCode((PVOID) org_GetOverwhelmingCrit, GetOverwhelmingCritHook, (PVOID*)&nwn_GetOverwhelmingCritNextHook) ? "success" : "fail");
	_log(3, "* GetDevastatingCritHook: %s\n", 
		HookCode((PVOID) org_GetDevastatingCrit, GetDevastatingCritHook, (PVOID*)&nwn_GetDevastatingCritNextHook) ? "success" : "fail");
	_log(3, "* GetWeaponOfChoiceHook: %s\n", 
		HookCode((PVOID) org_GetWeaponOfChoice, GetWeaponOfChoiceHook, (PVOID*)&nwn_GetWeaponOfChoiceNextHook) ? "success" : "fail");
}