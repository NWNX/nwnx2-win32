#include "stdafx.h"
#include "nwnx_funcs.h"
#include "madchook.h"

extern CNWNXFuncs NWNFuncs;

#define __log(a,b,...) if(a<=NWNFuncs.debugLevel)NWNFuncs.LOG(b,__VA_ARGS__)

void (*nwn_CreateNewGeometryNextHook)();

void *pThis=NULL;
CNWSArea *Area=NULL;
CScriptLocation *Loc=NULL;
uint32_t u32_1=NULL;

void __declspec(naked)CreateNewGeometryHookProc() {
	if (NWNFuncs.CustomTriggerGeometry) {

		__asm {
			pushad	
			mov pThis, ecx
			mov eax, [esp+0x28]
			mov Loc, eax
			mov eax, [esp+0x2C]
			mov Area, eax
		}

		NWNFuncs.NWN_CreateGeometry((CNWSTrigger*)pThis, Loc, Area);
		NWNFuncs.CustomTriggerGeometry = 0;
		NWNFuncs.Floats.clear();

		__asm {
			popad
			retn 0x0C
		}
		
	}
	else {
		__asm jmp nwn_CreateNewGeometryNextHook
	}
}


void HookFunctions() {
	DWORD org_CreateNewGeometry = 0x005A9250;

	if(NWNFuncs.bHookCreateGeometry)
		if (HookCode((PVOID) org_CreateNewGeometry, CreateNewGeometryHookProc, (PVOID*)&nwn_CreateNewGeometryNextHook)) __log(1, "* CreateNewGeometry hooked\n");

}
