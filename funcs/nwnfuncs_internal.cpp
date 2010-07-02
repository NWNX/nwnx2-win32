#include "stdafx.h"
#include "nwnx_funcs.h"

void CNWNXFuncs::nwn_TimebarStart(CNWSCreature *cre, unsigned long ul, unsigned char uc) {
	CNWSCreature__StartGuiTimingBar(cre, NULL, ul, uc);
}

void CNWNXFuncs::nwn_TimebarStop(CNWSCreature *cre) {
	CNWSCreature__StopGuiTimingBar(cre, NULL);
}
/*
void nwn_SetQuickSlot_Item(CNWSCreature* cre, uint8_t nQuickSlot, nwn_objid_t oItem1, int iCastProperty, nwn_objid_t oItem2) {
	CNWSCreature__SetQuickbarButton_Item(cre, NULL, nQuickSlot, oItem1, iCastProperty, oItem2);
}

void nwn_SetQuickSlot_Spell(CNWSCreature* cre, uint8_t nQuickSlot, uint8_t nClassPos, uint32_t nSpellID, uint8_t nMetaMagic, uint8_t bIsDomainSpell) {
	CNWSCreature__SetQuickbarButton_Spell(cre, NULL, nQuickSlot, nClassPos, nSpellID, nMetaMagic, bIsDomainSpell);
}

void nwn_setQuickSlot_SpellLikeAbility(CNWSCreature *cre, uint8_t nQuickSlot, uint32_t nSpellID, uint8_t nMetaMagic) {
	CNWSCreature__SetQuickbarButton_SpellLikeAbility(cre, NULL, nQuickSlot, nSpellID, nMetaMagic);
}
*/
void CNWNXFuncs::nwn_JumpCreatureToLimbo(CNWSCreature *cre) {
	CNWSModule *mod = CServerExoAppInternal__GetModule((*NWN_AppManager)->app_server->srv_internal, NULL); 

	if (mod != NULL && cre != NULL) {
		CNWSCreature__RemoveFromArea(cre, NULL, 0);
		CNWSModule__AddObjectToLimbo(mod, NULL, cre->obj.obj_generic.obj_id);
	}
}


void CNWNXFuncs::nwn_UpdateObject(nwn_objid_t plID, nwn_objid_t objID, CNWSObject* obj) {
	CNWSMessage *pServerMessage = (CNWSMessage*)CServerExoApp__GetNWSMessage((*NWN_AppManager)->app_server, NULL);
	CNWSPlayer *pPlayer = CServerExoApp__GetClientObjectByObjectId((*NWN_AppManager)->app_server, NULL, plID);
	CNWSObject *pObject = (CNWSObject*)CServerExoApp__GetGameObject((*NWN_AppManager)->app_server, NULL, objID);
	CLastUpdateObject luo;
	uint8_t *pData;
	uint64_t length;
	if (!pServerMessage || !pPlayer || !pObject || pObject->obj_generic.obj_type2 != 5) return;

	CNWMessage__CreateWriteMessage(pServerMessage, NULL, 0x400, pPlayer->pl_id, 1);
	//CNWSMessage__WriteGameObjUpdate_UpdateObject(pServerMessage, NULL, pPlayer, pObject, &luo, 0, 0x400);
	CNWSMessage__WriteGameObjUpdate_UpdateAppearance(pServerMessage, NULL, obj, &luo, 0x400);
	CNWMessage__GetWriteMessage(pServerMessage, NULL, &pData, &length);
	if (length) {
		CNWSMessage__SendServerToPlayerMessage(pServerMessage, NULL, pPlayer->pl_id, 5, 1, pData, length);
	}
}

void CNWNXFuncs::nwn_SetWorldTime(uint32_t wtDate, uint32_t wtTime, int P3) {
	CWorldTimer__SetWorldTime((*NWN_AppManager)->app_server->srv_internal->srv_time_world, NULL, wtDate, wtTime, P3);
}

void CNWNXFuncs::RunTestFunc(CGenericObject* obj) {
	CNWSPlayer *pl = CServerExoApp__GetClientObjectByObjectId((*NWN_AppManager)->app_server, NULL, obj->obj_id);

	CNWSMessage__SendServerToPlayerGameObjUpdate((*NWN_AppManager)->app_server->srv_internal->srv_client_messages, NULL, pl);
}

CNWSModule *CNWNXFuncs::nwn_GetModule(bool addOffset) {
	//I'm not sure why there is a difference of 0x1C bettwen the ServerExoAppInternal call and the object GetModule (nss) the script returns
	char *mod = (char*)CServerExoAppInternal__GetModule((*NWN_AppManager)->app_server->srv_internal, NULL);
	if (addOffset)
		return (CNWSModule*)(mod+=0x1C);
	return (CNWSModule*)mod;
}

void CNWNXFuncs::nwn_UpdateQuickBar(CGenericObject* obj) {
	CNWSPlayer *pl = CServerExoApp__GetClientObjectByObjectId((*NWN_AppManager)->app_server, NULL, obj->obj_id);

	if (pl != NULL) {
		CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton((*NWN_AppManager)->app_server->srv_internal->srv_client_messages, NULL, pl, 0, 1);
	}
}