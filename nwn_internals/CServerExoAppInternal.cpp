#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CNWSModule*				(__thiscall *CServerExoAppInternal__GetModule)(CServerExoAppInternal*) = (CNWSModule* (__thiscall *)(CServerExoAppInternal*))0x004530A0;
CNWSCreature*			(__thiscall *CServerExoAppInternal__GetCreatureByGameObjectID)(CServerExoAppInternal*, unsigned long) = (CNWSCreature * (__thiscall *)(CServerExoAppInternal*, unsigned long))0x0045C020;
CNWSArea* 				(__thiscall *CServerExoAppInternal__GetAreaByGameObjectID)(CServerExoAppInternal *, nwn_objid_t Area) = (CNWSArea* (__thiscall*)(CServerExoAppInternal *, nwn_objid_t Area))0x0045C0C0;
uint32_t				(__thiscall *CServerExoAppInternal__GetPlayerIDByGameObjectID)(CServerExoAppInternal* pThis, nwn_objid_t oID) = (uint32_t (__thiscall*)(CServerExoAppInternal* pThis, nwn_objid_t oID))0x00462C80;
CNWSItem*  				(__thiscall *CServerExoAppInternal__GetItemByGameObjectID)(CServerExoAppInternal* pThis, nwn_objid_t oID) = (CNWSItem* (__thiscall*)(CServerExoAppInternal* pThis, nwn_objid_t oID))0x0045BFD0;
CGameObject*			(__thiscall *CServerExoAppInternal__GetGameObject)(CServerExoAppInternal* pTHIS, nwn_objid_t oID) = (CGameObject* (__thiscall*)(CServerExoAppInternal* pTHIS, nwn_objid_t oID))0x0045BF40;
CNWSPlaceable*  		(__thiscall *CServerExoAppInternal__GetPlaceableByGameObjectID)(CServerExoAppInternal *, nwn_objid_t Placeable) = (CNWSPlaceable* (__thiscall*)(CServerExoAppInternal *, nwn_objid_t Placeable))0x0045C160;
CNWSAreaOfEffectObject*	(__thiscall *CServerExoAppInternal__GetAreaOfEffectByGameObjectID)(CServerExoAppInternal* pThis, nwn_objid_t oID) = (CNWSAreaOfEffectObject* (__thiscall*)(CServerExoAppInternal* pThis, nwn_objid_t oID))0x0045C200;
CNWSDoor* 				(__thiscall *CServerExoAppInternal__GetDoorByGameObjectID)(CServerExoAppInternal *pTHIS, nwn_objid_t oID) = (CNWSDoor* (__thiscall*)(CServerExoAppInternal *pTHIS, nwn_objid_t oID))0x0045C1B0;
CNWSEncounter* 			(__thiscall *CServerExoAppInternal__GetEncounterByGameObjectID)(CServerExoAppInternal *pTHIS, nwn_objid_t oID) = (CNWSEncounter* (__thiscall*)(CServerExoAppInternal *pTHIS, nwn_objid_t oID))0x0045C2A0;
CNWSStore* 				(__thiscall *CServerExoAppInternal__GetStoreByGameObjectID)(CServerExoAppInternal* pThis, nwn_objid_t oID) = (CNWSStore* (__thiscall*)(CServerExoAppInternal* pThis, nwn_objid_t oID))0x0045BF80;
CNWSTrigger* 			(__thiscall *CServerExoAppInternal__GetTriggerByGameObjectID)(CServerExoAppInternal* pThis, nwn_objid_t oID) = (CNWSTrigger* (__thiscall*)(CServerExoAppInternal* pThis, nwn_objid_t oID))0x0045C110;
int 					(__thiscall *CServerExoAppInternal__GetFactionOfObject)(CServerExoAppInternal* pTHIS, nwn_objid_t, uint32_t *ret_factionID) = (int (__thiscall*)(CServerExoAppInternal* pTHIS, nwn_objid_t, uint32_t *ret_factionID))0x004615A0;

CNWSArea *CServerExoAppInternal_s::GetAreaByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetAreaByGameObjectID(this, oID);
}

CNWSAreaOfEffectObject *CServerExoAppInternal_s::GetAreaOfEffectByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetAreaOfEffectByGameObjectID(this, oID);
}

CNWSCreature *CServerExoAppInternal_s::GetCreatureByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetCreatureByGameObjectID(this, oID);
}

CNWSDoor *CServerExoAppInternal_s::GetDoorByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetDoorByGameObjectID(this, oID);
}

CNWSEncounter *CServerExoAppInternal_s::GetEncounterByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetEncounterByGameObjectID(this, oID);
}

int CServerExoAppInternal_s::GetFactionOfObject(nwn_objid_t oID, uint32_t *ret_factionID) {
	return CServerExoAppInternal__GetFactionOfObject(this, oID, ret_factionID);
}

CGameObject *CServerExoAppInternal_s::GetGameObject(nwn_objid_t oID) {
	return CServerExoAppInternal__GetGameObject(this, oID);
}

CNWSItem * CServerExoAppInternal_s::GetItemByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetItemByGameObjectID(this, oID);
}

CNWSModule *CServerExoAppInternal_s::GetModule() {
	return CServerExoAppInternal__GetModule(this);
}

CNWSPlaceable *CServerExoAppInternal_s::GetPlaceableByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetPlaceableByGameObjectID(this, oID);
}

uint32_t CServerExoAppInternal_s::GetPlayerIDByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetPlayerIDByGameObjectID(this, oID);
}

CNWSStore *CServerExoAppInternal_s::GetStoreByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetStoreByGameObjectID(this, oID);
}

CNWSTrigger *CServerExoAppInternal_s::GetTriggerByGameObjectID(nwn_objid_t oID) {
	return CServerExoAppInternal__GetTriggerByGameObjectID(this, oID);
}

