#include "stdafx.h"
#include "nwnx_funcs.h"

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
	CNWSModule *mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule(); 

	if (mod != NULL && cre != NULL) {
		cre->RemoveFromArea(0);
		mod->AddObjectToLimbo(cre->obj.obj_generic.obj_id);
	}
}


void CNWNXFuncs::nwn_UpdateObject(nwn_objid_t plID, nwn_objid_t objID, CNWSObject* obj) {
	CNWSMessage *pServerMessage = ((*NWN_AppManager)->app_server)->GetNWSMessage();
	CNWSPlayer *pPlayer = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(plID);
	CNWSObject *pObject = (CNWSObject*)((*NWN_AppManager)->app_server)->GetGameObject(objID);
	CLastUpdateObject luo;
	uint8_t *pData;
	uint64_t length;
	if (!pServerMessage || !pPlayer || !pObject || pObject->obj_generic.obj_type2 != 5) return;

	CNWMessage__CreateWriteMessage(pServerMessage, NULL, 0x400, pPlayer->pl_id, 1);
	//pServerMessage->WriteGameObjUpdate_UpdateObject(pPlayer, pObject, &luo, 0, 0x400);
	pServerMessage->WriteGameObjUpdate_UpdateAppearance(obj, &luo, 0x400);
	CNWMessage__GetWriteMessage(pServerMessage, NULL, &pData, &length);
	if (length) {
		pServerMessage->SendServerToPlayerMessage(pPlayer->pl_id, 5, 1, pData, length);
	}
}

void CNWNXFuncs::nwn_SetWorldTime(uint32_t wtDate, uint32_t wtTime, int P3) {
	(*NWN_AppManager)->app_server->srv_internal->srv_time_world->SetWorldTime(wtDate, wtTime, P3);
}

void CNWNXFuncs::RunTestFunc(CGenericObject* obj) {
	CNWSPlayer *pl = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(obj->obj_id);

	((*NWN_AppManager)->app_server->srv_internal->srv_client_messages)->SendServerToPlayerGameObjUpdate(pl);
}

CNWSModule *CNWNXFuncs::nwn_GetModule(bool addOffset) {
	//I'm not sure why there is a difference of 0x1C bettwen the ServerExoAppInternal call and the object GetModule (nss) the script returns
	char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	if (addOffset)
		return (CNWSModule*)(mod+=0x1C);
	return (CNWSModule*)mod;
}

void CNWNXFuncs::nwn_UpdateQuickBar(CGenericObject* obj) {
	CNWSPlayer *pl = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(obj->obj_id);

	if (pl != NULL) {
		((*NWN_AppManager)->app_server->srv_internal->srv_client_messages)->SendServerToPlayerGuiQuickbar_SetButton(pl, 0, 1);
	}
}