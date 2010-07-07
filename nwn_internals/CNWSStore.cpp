#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void (__thiscall *CNWSStore__SetScriptName)(CNWSStore *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSStore *pTHIS, int iScript, CExoString ScriptName))0x00466460;

void CNWSStore::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSStore__SetScriptName(this, iScript, ScriptName);
}