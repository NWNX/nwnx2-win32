#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

float 			(__thiscall *CNWSScriptVarTable__GetFloat)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (float (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A10C0;
int 			(__thiscall *CNWSScriptVarTable__GetInt)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (int (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A1090;
void 			(__thiscall *CNWSScriptVarTable__SetInt)(CNWSScriptVarTable *pTHIS, CExoString &VarName, int VarValue, int) = (void (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName, int VarValue, int))0x005A1250;
CScriptLocation (__thiscall *CNWSScriptVarTable__GetLocation)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (CScriptLocation (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A11B0;


float CNWSScriptVarTable_s::GetFloat(CExoString &VarName) {
	return CNWSScriptVarTable__GetFloat(this, VarName);
}

int CNWSScriptVarTable_s::GetInt(CExoString &VarName) {
	return CNWSScriptVarTable__GetInt(this, VarName);
}

void CNWSScriptVarTable_s::SetInt(CExoString &VarName, int VarValue, int a3) {
	CNWSScriptVarTable__SetInt(this, VarName, VarValue, a3);
}

CScriptLocation CNWSScriptVarTable_s::GetLocation(CExoString &VarName) {
	return CNWSScriptVarTable__GetLocation(this, VarName);
}
