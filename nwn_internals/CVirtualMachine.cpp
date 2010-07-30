#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int (__thiscall *CVirtualMachine__RunScript)(CVirtualMachine *pTHIS, CExoString *a2, nwn_objid_t, int a4) = (int (__thiscall*)(CVirtualMachine *pTHIS, CExoString *a2, nwn_objid_t, int a4))0x005BF9D0;

int CVirtualMachine_s::Runscript(CExoString *ScriptName, nwn_objid_t OBJECT_SELF, int a4) {
	return CVirtualMachine__RunScript(this, ScriptName, OBJECT_SELF, a4);
}