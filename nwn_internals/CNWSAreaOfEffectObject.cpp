#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void 			(__thiscall *CNWSAreaOfEffectObject__SetScriptName)(CNWSAreaOfEffectObject *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSAreaOfEffectObject *pTHIS, int iScript, CExoString ScriptName))0x004F2F20;

void CNWSAreaOfEffectObject_s::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSAreaOfEffectObject__SetScriptName(this, iScript, ScriptName);
}
