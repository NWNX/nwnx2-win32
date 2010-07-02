#include "stdafx.h"
#include "nwnx_trinity.h"
#include "madchook.h"
#include <string>

extern CNWNXTrinity NWNXTrinity;

#define _log(a,b,...) if(a<=NWNXTrinity.debugLevel)_LOG(b,__VA_ARGS__)

void (*nwn_OverrideGlobalMaxLevelNextHook)();
void (*nwn_OverrideCanLevelUpMaxLevelNextHook)();
void (*nwn_OverrideCanLevelUpCheckXPNextHook)();

void (*nwn_EventRecoverTrapTriggerNextHook)();

void __declspec(naked)OverrideGlobalMaxLevelHookProc() {
	__asm {
		mov bl, 0x78
		jmp nwn_OverrideGlobalMaxLevelNextHook
	}
}

void __declspec(naked)OverrideCanLevelUpMaxLevelHookProc() {
	__asm {
		mov [esp+0x13], 0x78
		jmp nwn_OverrideCanLevelUpMaxLevelNextHook
	}
}

CNWSCreatureStats *Stats;
void __declspec(naked)OverrideCanLevelUpCheckXPHookProc() {
	__asm {
		pushad
		mov Stats, ebx
	}
	
	if (NWNXTrinity.CanLevelUpXP(Stats)) {
		__asm {
			popad
			mov eax, 0x00483CFC
			jmp eax
		}
	}
	else {
		__asm {
			popad
			mov eax, 0x00483D09
			jmp eax
		}
	}
}

uint32_t TriggeroID=OBJECT_INVALID, CreatureoID=OBJECT_INVALID;
CNWSTrigger *Trigger=NULL;
void __declspec(naked)EventRecoverTrapTriggerHookProc() {
	__asm {
		//mov edx, [edi+0x4]
		//mov CreatureoID, edx
		mov edx, [esp+0x38]
		mov Trigger, edx
		pushad
		pushfd
	}
	_log(3, "TriggeroID %08X\tCreatureoID %08X\n", Trigger, CreatureoID);

	__asm {
		popfd
		popad
		jmp nwn_EventRecoverTrapTriggerNextHook
	}
}

void HookFunctions() {
	DWORD org_OverrideGlobalMaxLevel=0x0043261C;
	DWORD org_OverrideCanLevelUpMaxLevel=0x00483B7C;
	DWORD org_OverrideCanLevelUpCheckXP=0x00483CF6;

	DWORD org_EventRecoverTrapTrigger=0x004B8CD8;

	// catch and change the area on logout
/*	_log(0, "* Override Global Max Level (120) hook: %s\n", 
		HookCode((PVOID) org_OverrideGlobalMaxLevel, OverrideGlobalMaxLevelHookProc, (PVOID*)&nwn_OverrideGlobalMaxLevelNextHook) ? "success" : "failure");

	_log(0, "* Override CanLevelUp Max Level (120) hook: %s\n", 
		HookCode((PVOID) org_OverrideCanLevelUpMaxLevel, OverrideCanLevelUpMaxLevelHookProc, (PVOID*)&nwn_OverrideCanLevelUpMaxLevelNextHook) ? "success" : "failure");

	_log(0, "* Override CanLevelUp CheckXP (120) hook: %s\n", 
		HookCode((PVOID) org_OverrideCanLevelUpCheckXP, OverrideCanLevelUpCheckXPHookProc, (PVOID*)&nwn_OverrideCanLevelUpCheckXPNextHook) ? "success" : "failure");

	_log(0, "* Event Recover TrapTrigger hook: %s\n", 
		HookCode((PVOID) org_EventRecoverTrapTrigger, EventRecoverTrapTriggerHookProc, (PVOID*)&nwn_EventRecoverTrapTriggerNextHook) ? "success" : "failure");
*/
}