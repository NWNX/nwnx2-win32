#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void			(__thiscall *CNWSModule__AddObjectToLimbo)(CNWSModule*, uint32_t) = (void (__thiscall *)(CNWSModule*, uint32_t))0x004DB3D0;
int 			(__thiscall *CNWSModule__AddObjectToLookupTable)(CNWSModule *pTHIS, CExoString Tag, int a3, int oID) = (int (__thiscall*)(CNWSModule *pTHIS, CExoString Tag, int a3, int oID))0x004DA3C0;
CNWSArea * 		(__thiscall *CNWSModule__GetArea)(CNWSModule *pTHIS, nwn_objid_t) = (CNWSArea* (__thiscall*)(CNWSModule *pTHIS, nwn_objid_t))0x004D2390;
CNWSPlayerTURD* (__thiscall *CNWSModule__GetPlayerTURDFromList)(CNWSModule *pTHIS, CNWSPlayer *) = (CNWSPlayerTURD* (__thiscall*)(CNWSModule *pTHIS, CNWSPlayer *))0x004D7330;
void 			(__thiscall *CNWSModule__SetScriptName)(CNWSModule *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSModule *pTHIS, int iScript, CExoString ScriptName))0x004D97F0;


void CNWSModule_s::AddObjectToLimbo(nwn_objid_t oID) {
	CNWSModule__AddObjectToLimbo(this, oID);
}

int CNWSModule_s::AddObjectToLookupTable(CExoString Tag, int a3, nwn_objid_t oID) {
	return CNWSModule__AddObjectToLookupTable(this, Tag, a3, oID);
}

CNWSArea *CNWSModule_s::GetArea(nwn_objid_t oID) {
	return CNWSModule__GetArea(this, oID);
}

CNWSPlayerTURD* CNWSModule_s::GetPlayerTURDFromList(CNWSPlayer *Player) {
	return CNWSModule__GetPlayerTURDFromList(this, Player);
}

void CNWSModule_s::SetScriptName(int iScript, CExoString ScriptName) {
	CNWSModule__SetScriptName(this, iScript, ScriptName);
}

