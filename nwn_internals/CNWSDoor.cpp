#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void (__thiscall *CNWSDoor__SetScriptName)(CNWSDoor *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSDoor *pTHIS, int iScript, CExoString ScriptName))0x004CC670;


void CNWSDoor::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSDoor__SetScriptName(this, iScript, ScriptName);
}