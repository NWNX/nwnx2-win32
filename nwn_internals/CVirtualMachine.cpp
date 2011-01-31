#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int (__thiscall *CVirtualMachine__RunScript)(CVirtualMachine *pTHIS, CExoString *a2, nwn_objid_t, int a4) = (int (__thiscall*)(CVirtualMachine *pTHIS, CExoString *a2, nwn_objid_t, int a4))0x005BF9D0;
int (__thiscall *CVirtualMachine__StackPushEngineStructure)(CVirtualMachine *pTHIS, int, void *) = (int (__thiscall*)(CVirtualMachine *pTHIS, int, void *))0x005C0970;
int (__thiscall *CVirtualMachine__StackPopInteger)(CVirtualMachine *pTHIS, int *) = (int (__thiscall*)(CVirtualMachine *pTHIS, int *))0x005C0590;
int (__thiscall *CVirtualMachine__StackPopEngineStructure)(CVirtualMachine *pTHIS, int a2, void **a3) = (int(__thiscall*)(CVirtualMachine *pTHIS, int a2, void **a3))0x005C08F0;
	
int CVirtualMachine_s::Runscript(CExoString *ScriptName, nwn_objid_t OBJECT_SELF, int a4) {
	return CVirtualMachine__RunScript(this, ScriptName, OBJECT_SELF, a4);
}

int CVirtualMachine_s::StackPushEngineStructure(int a2, void *a3) {
	return CVirtualMachine__StackPushEngineStructure(this, a2, a3);
}

int CVirtualMachine_s::StackPopEngineStructure(int a2, void **a3) {
	return CVirtualMachine__StackPopEngineStructure(this, a2, a3);
}

int CVirtualMachine_s::StackPopInteger(int *iINT) {
	return (CVirtualMachine__StackPopInteger(this, iINT));
}