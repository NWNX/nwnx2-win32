#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void			(__thiscall *CNWSModule__AddObjectToLimbo)(CNWSModule*, uint32_t) = (void (__thiscall *)(CNWSModule*, uint32_t))0x004DB3D0;
int 			(__thiscall *CNWSModule__AddObjectToLookupTable)(CNWSModule *pTHIS, CExoString Tag, int oID) = (int (__thiscall*)(CNWSModule *pTHIS, CExoString Tag, int oID))0x004DA3C0;
nwn_objid_t		(__thiscall *CNWSModule__FindObjectByTagOrdinal)(CNWSModule *pTHIS, CExoString *sTag, int nNth) = (nwn_objid_t (__thiscall*)(CNWSModule *pTHIS, CExoString *sTag, int nNth))0x004DA780;
CNWSArea * 		(__thiscall *CNWSModule__GetArea)(CNWSModule *pTHIS, nwn_objid_t) = (CNWSArea* (__thiscall*)(CNWSModule *pTHIS, nwn_objid_t))0x004D2390;
CNWSPlayerTURD* (__thiscall *CNWSModule__GetPlayerTURDFromList)(CNWSModule *pTHIS, CNWSPlayer *) = (CNWSPlayerTURD* (__thiscall*)(CNWSModule *pTHIS, CNWSPlayer *))0x004D7330;
int 			(__thiscall *CNWSModule__RemoveObjectFromLookupTable)(CNWSModule *pTHIS, CExoString Tag, int oID) = (int (__thiscall*)(CNWSModule *pTHIS, CExoString Tag, int oID))0x004DA5E0;
void 			(__thiscall *CNWSModule__SetScriptName)(CNWSModule *pTHIS, int iScript, CExoString ScriptName) = (void (__thiscall*)(CNWSModule *pTHIS, int iScript, CExoString ScriptName))0x004D97F0;


void CNWSModule_s::AddObjectToLimbo(nwn_objid_t oID) {
	CNWSModule__AddObjectToLimbo(this, oID);
}

int CNWSModule_s::AddObjectToLookupTable(CExoString Tag, nwn_objid_t oID) {
	return CNWSModule__AddObjectToLookupTable(this, Tag, oID);
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

nwn_objid_t CNWSModule_s::FindObjectByTagOrdinal(CExoString *sTag, int nNth) {
	return CNWSModule__FindObjectByTagOrdinal(this, sTag, nNth);
}

int CNWSModule_s::RemoveObjectFromLookupTable(CExoString Tag, nwn_objid_t oID) {
	return CNWSModule__RemoveObjectFromLookupTable(this, Tag, oID);
}
