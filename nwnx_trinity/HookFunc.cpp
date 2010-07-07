#include "stdafx.h"
#include "nwnx_trinity.h"
#include "madchook.h"
#include <string>

#include <stdarg.h>


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

DWORD pServThis = 0;
DWORD pScriptThis = 0;
DWORD pServInternal = 0;
DWORD **g_pVirtualMachine;

int (__fastcall *CNWVirtualMachineCommands_ExecuteCommand)(void *pCommands, int edx, DWORD nCommandID, int arg_8);
int (__fastcall *CVirtualMachine_StackPopInteger)(void *pVM, int edx, int *buf);
int (__fastcall *CVirtualMachine_StackPopFloat)(void *pVM, int edx, float *buf);
int (__fastcall *CVirtualMachine_StackPopString)(void *pVM, int edx, CExoString *buf);
int (__fastcall *CVirtualMachine_StackPopVector)(void *pVM, int edx, Vector *buf);
int (__fastcall *CVirtualMachine_StackPopObject)(void *pVM, int edx, DWORD *buf);
int (__fastcall *CVirtualMachine_StackPopEngineStructure)(void *pVM, int edx, DWORD nStructType, void **buf);

int (__fastcall *CVirtualMachine_StackPushInteger)(void *pVM, int edx, int value);
int (__fastcall *CVirtualMachine_StackPushFloat)(void *pVM, int edx, float value);
int (__fastcall *CVirtualMachine_StackPushString)(void *pVM, int edx, CExoString *value);
int (__fastcall *CVirtualMachine_StackPushVector)(void *pVM, int edx, Vector value);
int (__fastcall *CVirtualMachine_StackPushObject)(void *pVM, int edx, DWORD value);
int (__fastcall *CVirtualMachine_StackPushEngineStructure)(void *pVM, int edx, DWORD nStructType, void *value);

int StackPopInteger(int *buf)
{
	return CVirtualMachine_StackPopInteger(*g_pVirtualMachine, 0, buf);
}

int StackPopFloat(float *buf)
{
	return CVirtualMachine_StackPopFloat(*g_pVirtualMachine, 0, buf);
}

int StackPopString(char **buf)
{
	CExoString *str = (CExoString *) malloc(sizeof(CExoString));
	str->text = NULL;
	str->len = 0;
	int retval = CVirtualMachine_StackPopString(*g_pVirtualMachine, 0, str);
	if (!str->text)
		*buf = "";
	else
		*buf = str->text;
	free(str);
	return retval;
}

int StackPopVector(Vector *buf)
{
	return CVirtualMachine_StackPopVector(*g_pVirtualMachine, 0, buf);
}

int StackPopObject(DWORD *buf)
{
	return CVirtualMachine_StackPopObject(*g_pVirtualMachine, 0, buf);
}

int StackPopEngineStructure(DWORD nStructType, void **buf)
{
	return CVirtualMachine_StackPopEngineStructure(*g_pVirtualMachine, 0, nStructType, buf);
}

int StackPushInteger(int value)
{
	return CVirtualMachine_StackPushInteger(*g_pVirtualMachine, 0, value);
}

int StackPushFloat(float value)
{
	return CVirtualMachine_StackPushFloat(*g_pVirtualMachine, 0, value);
}

int StackPushString(char *value)
{
	return CVirtualMachine_StackPushString(*g_pVirtualMachine, 0, (CExoString *) &value);
}

int StackPushVector(Vector value)
{
	return CVirtualMachine_StackPushVector(*g_pVirtualMachine, 0, value);
}

int StackPushObject(DWORD value)
{
	return CVirtualMachine_StackPushObject(*g_pVirtualMachine, 0, value);
}

int StackPushEngineStructure(DWORD nStructType, void *value)
{
	return CVirtualMachine_StackPushEngineStructure(*g_pVirtualMachine, 0, nStructType, value);
}

DWORD GetObjectSelf()
{
	CVirtualMachine *pVM = (CVirtualMachine *) *g_pVirtualMachine;
	return pVM->ObjectID[pVM->RecursionLevel];
}

void *GetCommandsPtr()
{
	return *(void **)(*(DWORD *)(g_pVirtualMachine) + 0x3A0);
}

void VM_ExecuteCommand(DWORD nCommandID, int nArgsCount)
{
	CNWVirtualMachineCommands_ExecuteCommand(GetCommandsPtr(), 0, nCommandID, nArgsCount);
}

void InitConstants()
{
	*(DWORD*)&g_pVirtualMachine = 0x0066C048;
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

	*(DWORD*)&CNWVirtualMachineCommands_ExecuteCommand = 0x00566020;
	*(DWORD*)&CVirtualMachine_StackPopInteger = 0x005C0590;
	*(DWORD*)&CVirtualMachine_StackPopFloat = 0x005C0610;
	*(DWORD*)&CVirtualMachine_StackPopString = 0x005C0800;
	*(DWORD*)&CVirtualMachine_StackPopVector = 0x005C0690;
	*(DWORD*)&CVirtualMachine_StackPopObject = 0x005C09C0;
	*(DWORD*)&CVirtualMachine_StackPopEngineStructure = 0x005C08F0;

	*(DWORD*)&CVirtualMachine_StackPushInteger = 0x005C05E0;
	*(DWORD*)&CVirtualMachine_StackPushFloat = 0x005C0660;
	*(DWORD*)&CVirtualMachine_StackPushString = 0x005C0860;
	*(DWORD*)&CVirtualMachine_StackPushVector = 0x005C0780;
	*(DWORD*)&CVirtualMachine_StackPushObject = 0x005C0A10;
	*(DWORD*)&CVirtualMachine_StackPushEngineStructure = 0x005C0970;

}

