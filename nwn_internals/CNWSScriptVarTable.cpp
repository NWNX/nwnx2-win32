#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void 			(__thiscall *CNWSScriptVarTable__DestroyFloat)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (void(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A16D0;
void			(__thiscall *CNWSScriptVarTable__DestroyInt)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (void(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A15A0;
void			(__thiscall *CNWSScriptVarTable__DestroyObject)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (void(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A17F0;
void			(__thiscall *CNWSScriptVarTable__DestroyString)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (void(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A1760;
float 			(__thiscall *CNWSScriptVarTable__GetFloat)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (float (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A10C0;
int 			(__thiscall *CNWSScriptVarTable__GetInt)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (int (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A1090;
CScriptLocation (__thiscall *CNWSScriptVarTable__GetLocation)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (CScriptLocation (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A11B0;
nwn_objid_t		(__thiscall *CNWSScriptVarTable__GetObject)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (nwn_objid_t(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A1180;
CExoString*		(__thiscall *CNWSScriptVarTable__GetString)(CNWSScriptVarTable *pTHIS, CExoString &VarName) = (CExoString* (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName))0x005A10F0;
CScriptVariable*(__thiscall *CNWSScriptVarTable__MatchIndex)(CNWSScriptVarTable *pTHIS, CExoString &VarName, uint32_t, int) = (CScriptVariable*(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName, uint32_t, int))0x005A0F20;
void 			(__thiscall *CNWSScriptVarTable__SetFloat)(CNWSScriptVarTable *pTHIS,  CExoString &VarName, float VarValue) = (void(__thiscall*)(CNWSScriptVarTable *pTHIS,  CExoString &VarName, float VarValue))0x005A1420;
void 			(__thiscall *CNWSScriptVarTable__SetInt)(CNWSScriptVarTable *pTHIS, CExoString &VarName, int VarValue, int) = (void (__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName, int VarValue, int))0x005A1250;
void 			(__thiscall *CNWSScriptVarTable__SetObject)(CNWSScriptVarTable *pTHIS, CExoString &VarName, nwn_objid_t Object_oID) = (void(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName, nwn_objid_t Object_oID))0x005A1460;
void 			(__thiscall *CNWSScriptVarTable__SetString)(CNWSScriptVarTable *pTHIS, CExoString &VarName, CExoString &VarValue) = (void(__thiscall*)(CNWSScriptVarTable *pTHIS, CExoString &VarName, CExoString &VarValue))0x005A1440;
		
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

CExoString *CNWSScriptVarTable_s::GetString(CExoString &VarName) {
	CScriptVariable *var = CNWSScriptVarTable__MatchIndex(this, VarName, 3, 0);
	if (var) return (CExoString*)var->var_value;
	return NULL;
}

void CNWSScriptVarTable_s::SetFloat(CExoString &VarName, float VarValue) {
	CNWSScriptVarTable__SetFloat(this, VarName, VarValue);
}

void CNWSScriptVarTable_s::SetString(CExoString &VarName, CExoString &VarValue) {
	CNWSScriptVarTable__SetString(this, VarName, VarValue);
}

void CNWSScriptVarTable_s::DestroyFloat(CExoString &VarName) {
	CNWSScriptVarTable__DestroyFloat(this, VarName);
}

void CNWSScriptVarTable_s::DestroyInt(CExoString &VarName) {
	CNWSScriptVarTable__DestroyInt(this, VarName);
}

nwn_objid_t CNWSScriptVarTable_s::GetObject(CExoString &VarName) {
	return CNWSScriptVarTable__GetObject(this, VarName);
}

void CNWSScriptVarTable_s::DestroyObject(CExoString &VarName) {
	CNWSScriptVarTable__DestroyObject(this, VarName);
}

void CNWSScriptVarTable_s::DestroyString(CExoString &VarName) {
	CNWSScriptVarTable__DestroyString(this, VarName);
}

void CNWSScriptVarTable_s::SetObject(CExoString &VarName, nwn_objid_t Object_oID) {
	CNWSScriptVarTable__SetObject(this, VarName, Object_oID);
}