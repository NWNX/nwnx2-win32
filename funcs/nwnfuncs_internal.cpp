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

void CNWNXFuncs::nwn_SetWorldTime(uint32_t wtDate, uint32_t wtTime, int P3) {
	(*NWN_AppManager)->app_server->srv_internal->srv_time_world->SetWorldTime(wtDate, wtTime, P3);
}

CNWSModule *CNWNXFuncs::nwn_GetModule(bool addOffset) {
	//I'm not sure why there is a difference of 0x1C bettwen the ServerExoAppInternal call and the object GetModule (nss) the script returns
	if (!addOffset) return (*NWN_AppManager)->app_server->srv_internal->GetModule();

	char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	return (CNWSModule*)(mod+=0x1C);
}

void CNWNXFuncs::nwn_UpdateQuickBar(CGenericObject* obj) {
	CNWSPlayer *pl = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(obj->obj_id);

	if (pl != NULL) {
		((*NWN_AppManager)->app_server->srv_internal->srv_client_messages)->SendServerToPlayerGuiQuickbar_SetButton(pl, 0, 1);
	}
}