#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CNWSPlayer* 		(__thiscall *CServerExoApp__GetClientObjectByObjectId)(CServerExoApp *pTHIS, nwn_objid_t oID) = (CNWSPlayer *(__thiscall *)(CServerExoApp *pTHIS, nwn_objid_t oID))0x0042cd20;
CGenericObject* 	(__thiscall *CServerExoApp__GetGameObject)(CServerExoApp *pTHIS, nwn_objid_t oID) = (CGenericObject* (__thiscall *)(CServerExoApp *pTHIS, nwn_objid_t oID))0x0042C810;
CNWSMessage*		(__thiscall *CServerExoApp__GetNWSMessage)(CServerExoApp *pTHIS) = (CNWSMessage* (__thiscall *)(CServerExoApp *pTHIS))0x0042C940;
CGameObjectArray*	(__thiscall *CServerExoApp__GetObjectArray)(CServerExoApp *pTHIS) = (CGameObjectArray* (__thiscall*)(CServerExoApp *pTHIS))0x0042C800;
void* 				(__thiscall *CServerExoApp__GetPlayerList)(CServerExoApp *pTHIS) = (void* (__thiscall*)(CServerExoApp *pTHIS))0x0042C920;
CNWSClient* 		(__thiscall *CServerExoApp__GetClientObjectByPlayerId)(CServerExoApp *pTHIS, uint32_t player_id, uint8_t a3) = (CNWSClient* (__thiscall*)(CServerExoApp *pTHIS, uint32_t player_id, uint8_t a3))0x0042CD30;
int 				(__thiscall *CServerExoApp__GetModuleLanguage)(CServerExoApp *pTHIS) = (int (__thiscall*)(CServerExoApp *pTHIS))0x0042C900;

CNWSPlayer *CServerExoApp_s::GetClientObjectByObjectId(nwn_objid_t oID) {
	return CServerExoApp__GetClientObjectByObjectId(this, oID);
}

CNWSClient *CServerExoApp_s::GetClientObjectByPlayerId(uint32_t player_id, uint8_t a3) {
	return CServerExoApp__GetClientObjectByPlayerId(this, player_id, a3);
}

CGenericObject *CServerExoApp_s::GetGameObject(nwn_objid_t oID) {
	return CServerExoApp__GetGameObject(this, oID);
}

CNWSMessage *CServerExoApp_s::GetNWSMessage() {
	return CServerExoApp__GetNWSMessage(this);
}

CGameObjectArray *CServerExoApp_s::GetObjectArray() {
	return CServerExoApp__GetObjectArray(this);
}

void *CServerExoApp_s::GetPlayerList() {
	return CServerExoApp__GetPlayerList(this);
}

int CServerExoApp_s::GetModuleLanguage() {
	return CServerExoApp__GetModuleLanguage(this);
}