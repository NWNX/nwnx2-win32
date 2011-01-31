#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int32_t	(__thiscall *CNWSPlaceable__AcquireItem)(CNWSPlaceable *pTHIS, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack) = (signed int (__thiscall*)(CNWSPlaceable *pTHIS, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack))0x00521AD0;
void 	(__thiscall *CNWSPlaceable__SetScriptName)(CNWSPlaceable *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSPlaceable *pTHIS, int iScript, CExoString ScriptName))0x004CD150;
int		(__thiscall *CNWSPlaceable__SavePlaceable)(CNWSPlaceable *pTHIS, CResGFF *, void *CResStruct) = (int (__thiscall*)(CNWSPlaceable *pTHIS, CResGFF *, void *CResStruct))0x0051FBD0;
	
int32_t CNWSPlaceable_s::AcquireItem(CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack) {
	return CNWSPlaceable__AcquireItem(this, a2, a3, a4, a5, bSendFeedBack);
}

void  CNWSPlaceable_s::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSPlaceable__SetScriptName(this, iScript, ScriptName);
}

int CNWSPlaceable::SavePlaceable(CResGFF *ResGFF, void *ResStruct) {
	return CNWSPlaceable__SavePlaceable(this, ResGFF, ResStruct);
}
