#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void 	(__thiscall *CNWSStore__AddToArea)(CNWSStore *pTHIS, CNWSArea *Area, Vector Position, int a3) = (void(__thiscall*)(CNWSStore *pTHIS, CNWSArea *Area, Vector Position, int a3))0x00465640;
void	(__thiscall *CNWSStore__CNWSStore)(CNWSStore *pTHIS, nwn_objid_t oID) = (void(__thiscall*)(CNWSStore *pTHIS, nwn_objid_t oID))0x00464490;
int 	(__thiscall *CNWSStore__LoadStore)(CNWSStore *pTHIS, CResGFF *pResGFF, CResStruct *pResStruct, CExoString *Tag) = (int(__thiscall*)(CNWSStore *pTHIS, CResGFF *pResGFF, CResStruct *pResStruct, CExoString *Tag))0x00464940;
void	(__thiscall *CNWSStore__SetScriptName)(CNWSStore *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSStore *pTHIS, int iScript, CExoString ScriptName))0x00466460;
int		(__thiscall *CNWSStore__SaveStore)(CNWSStore *pTHIS, CResGFF *, void *ResStruct) = (int (__thiscall*)(CNWSStore *pTHIS, CResGFF *, void *ResStruct))0x004652B0;

CNWSStore_s::CNWSStore_s(nwn_objid_t oID) {
	CNWSStore__CNWSStore(this, oID);	
}

void CNWSStore::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSStore__SetScriptName(this, iScript, ScriptName);
}

int CNWSStore::SaveStore(CResGFF *ResGFF, void *ResStruct) {
	return CNWSStore__SaveStore(this, ResGFF, ResStruct);
}

int CNWSStore_s::LoadStore(CResGFF *pResGFF, CResStruct *pResStruct, CExoString *Tag) {
	return CNWSStore__LoadStore(this, pResGFF, pResStruct, Tag);
}

void CNWSStore_s::AddToArea(CNWSArea *Area, Vector Position, int a3) {
	CNWSStore__AddToArea(this, Area, Position, a3);
}