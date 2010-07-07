#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void (__thiscall *CNWSEncounter__SetScriptName)(CNWSEncounter *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSEncounter *pTHIS, int iScript, CExoString ScriptName))0x005ADA00;

void CNWSEncounter::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSEncounter__SetScriptName(this, iScript, ScriptName);
}