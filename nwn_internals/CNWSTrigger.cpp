#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void (__thiscall *CNWSTrigger__SetScriptName)(CNWSTrigger *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSTrigger *pTHIS, int iScript, CExoString ScriptName))0x004CB790;

void CNWSTrigger::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSTrigger__SetScriptName(this, iScript, ScriptName);
}