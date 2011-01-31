#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void	(__thiscall *CNWSStore__SetScriptName)(CNWSStore *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSStore *pTHIS, int iScript, CExoString ScriptName))0x00466460;
int		(__thiscall *CNWSStore__SaveStore)(CNWSStore *pTHIS, CResGFF *, void *ResStruct) = (int (__thiscall*)(CNWSStore *pTHIS, CResGFF *, void *ResStruct))0x004652B0;

void CNWSStore::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSStore__SetScriptName(this, iScript, ScriptName);
}

int CNWSStore::SaveStore(CResGFF *ResGFF, void *ResStruct) {
	return CNWSStore__SaveStore(this, ResGFF, ResStruct);
}