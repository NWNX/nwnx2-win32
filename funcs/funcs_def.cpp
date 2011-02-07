#include "stdafx.h"
#include "nwnx_funcs.h"
#include <string>
#include <list>
#include <math.h>

int CNWNXFuncs::PrintOffsets() {
	CGenericObject *obj = (CGenericObject*)oObject;
	CNWSCreature *cre = (CNWSCreature*)oObject;
	uint32_t iGO = (uint32_t)obj;
	CNWSCreatureStats *stats = ((CNWSCreature*)oObject)->cre_stats;

	_log(1, "\n--------------------CGenericObject--------------------\n");
	_log(1, "obj_type        : %08X\n", ((uint32_t)&obj->obj_type         - iGO));
	_log(1, "obj_id          : %08X\n", ((uint32_t)&obj->obj_id           - iGO));
	_log(1, "obj_type2       : %08X\n", ((uint32_t)&obj->obj_type2        - iGO));
	_log(1, "field_0009      : %08X\n", ((uint32_t)&obj->field_0009       - iGO));
	_log(1, "field_000A      : %08X\n", ((uint32_t)&obj->field_000A       - iGO));
	_log(1, "field_000B      : %08X\n", ((uint32_t)&obj->field_000B       - iGO));
	_log(1, "*obj_vtable     : %08X\n", ((uint32_t)&obj->obj_vtable       - iGO));
	_log(1, "*obj_lastname   : %08X\n", ((uint32_t)&obj->obj_lastname     - iGO));
	_log(1, "field_0014      : %08X\n", ((uint32_t)&obj->field_0014       - iGO));
	_log(1, "obj_tag         : %08X\n", ((uint32_t)&obj->obj_tag          - iGO));
	_log(1, "*obj_template   : %08X\n", ((uint32_t)&obj->obj_template     - iGO));
	_log(1, "\n--------------------CNWNSCreature--------------------\n");
	_log(1, "cre_events      : %08X\n", (uint32_t)&cre->cre_events - iGO);
	_log(1, "*cre_quickbat   : %08X\n", (uint32_t)&cre->cre_quickbar - iGO);
	_log(1, "cre_gold        : %08X\n", (uint32_t)&cre->cre_gold - iGO);
	_log(1, "cre_gold        : %08X\n", (uint32_t)&cre->cre_gold - iGO);
	_log(1, "cre_inventory   : %08X\n", (uint32_t)&cre->cre_inventory - iGO);
	_log(1, "cre_stats       : %08X\n\n", (uint32_t)&cre->cre_stats - iGO);

	iGO = (uint32_t)&stats->cs_feats;
	_log(1, "\n--------------------CNWSCreatureStats-----------------\n");
	_log(1, "cs_feats                        : %08X\n", (uint32_t)&stats->cs_feats - iGO);
	_log(1, "cs_featuses                     : %08X\n", (uint32_t)&stats->cs_featuses - iGO);
	_log(1, "*cs_original                    : %08X\n", (uint32_t)&stats->cs_original - iGO);
	_log(1, "cs_levelstat                    : %08X\n", (uint32_t)&stats->cs_levelstat - iGO);
	_log(1, "cs_firstname                    : %08X\n", (uint32_t)&stats->cs_firstname - iGO);
	_log(1, "cs_lastname                     : %08X\n", (uint32_t)&stats->cs_lastname - iGO);
	_log(1, "cs_conv[16]                     : %08X\n", (uint32_t)&stats->cs_conv[16] - iGO);
	_log(1, "cs_conv_interruptable           : %08X\n", (uint32_t)&stats->cs_conv_interruptable - iGO);
	_log(1, "cs_desc_base                    : %08X\n", (uint32_t)&stats->cs_desc_base - iGO);
	_log(1, "cs_desc_override                : %08X\n", (uint32_t)&stats->cs_desc_override - iGO);
	_log(1, "cs_age                          : %08X\n", (uint32_t)&stats->cs_age - iGO);
	_log(1, "cs_gender                       : %08X\n", (uint32_t)&stats->cs_gender - iGO);
	_log(1, "cs_xp                           : %08X\n", (uint32_t)&stats->cs_xp - iGO);
	_log(1, "cs_is_pc                        : %08X\n", (uint32_t)&stats->cs_is_pc - iGO);
	_log(1, "cs_is_dm                        : %08X\n", (uint32_t)&stats->cs_is_dm - iGO);
	_log(1, "field_7C                        : %08X\n", (uint32_t)&stats->field_7C - iGO);
	_log(1, "field_80                        : %08X\n", (uint32_t)&stats->field_80 - iGO);
	_log(1, "cs_ai_disabled                  : %08X\n", (uint32_t)&stats->cs_ai_disabled - iGO);
	_log(1, "field_88                        : %08X\n", (uint32_t)&stats->field_88 - iGO);
	_log(1, "cs_mclasslevupin                : %08X\n", (uint32_t)&stats->cs_mclasslevupin - iGO);
	_log(1, "cs_faction_id                   : %08X\n", (uint32_t)&stats->cs_faction_id - iGO);
	_log(1, "cs_faction_orig                 : %08X\n", (uint32_t)&stats->cs_faction_orig - iGO);
	_log(1, "cs_faction_predom               : %08X\n", (uint32_t)&stats->cs_faction_predom - iGO);
	_log(1, "cs_cr                           : %08X\n", (uint32_t)&stats->cs_cr - iGO);
	_log(1, "cs_starting_package             : %08X\n", (uint32_t)&stats->cs_starting_package - iGO);
	_log(1, "cs_classes_len                  : %08X\n", (uint32_t)&stats->cs_classes_len - iGO);
	_log(1, "field_9A                        : %08X\n", (uint32_t)&stats->field_9A - iGO);
	_log(1, "field_9B                        : %08X\n", (uint32_t)&stats->field_9B - iGO);
	_log(1, "cs_classes[3]                   : %08X\n", (uint32_t)&stats->cs_classes[3] - iGO);
	_log(1, "cs_race                         : %08X\n", (uint32_t)&stats->cs_race - iGO);
	_log(1, "field_3EE                       : %08X\n", (uint32_t)&stats->field_3EE - iGO);
	_log(1, "cs_subrace                      : %08X\n", (uint32_t)&stats->cs_subrace - iGO);
	_log(1, "cs_str                          : %08X\n", (uint32_t)&stats->cs_str - iGO);
	_log(1, "cs_str_mod                      : %08X\n", (uint32_t)&stats->cs_str_mod - iGO);
	_log(1, "cs_dex                          : %08X\n", (uint32_t)&stats->cs_dex - iGO);
	_log(1, "cs_dex_mod                      : %08X\n", (uint32_t)&stats->cs_dex_mod - iGO);
	_log(1, "cs_con                          : %08X\n", (uint32_t)&stats->cs_con - iGO);
	_log(1, "cs_con_mod                      : %08X\n", (uint32_t)&stats->cs_con_mod - iGO);
	_log(1, "cs_int                          : %08X\n", (uint32_t)&stats->cs_int - iGO);
	_log(1, "cs_int_mod                      : %08X\n", (uint32_t)&stats->cs_int_mod - iGO);
	_log(1, "cs_wis                          : %08X\n", (uint32_t)&stats->cs_wis - iGO);
	_log(1, "cs_wis_mod                      : %08X\n", (uint32_t)&stats->cs_wis_mod - iGO);
	_log(1, "cs_cha                          : %08X\n", (uint32_t)&stats->cs_cha - iGO);
	_log(1, "cs_cha_mod                      : %08X\n", (uint32_t)&stats->cs_cha_mod - iGO);
	_log(1, "cs_ac_natural_base              : %08X\n", (uint32_t)&stats->cs_ac_natural_base - iGO);
	_log(1, "cs_ac_armour_base               : %08X\n", (uint32_t)&stats->cs_ac_armour_base - iGO);
	_log(1, "cs_ac_shield_base               : %08X\n", (uint32_t)&stats->cs_ac_shield_base - iGO);
	_log(1, "cs_ac_armour_bonus              : %08X\n", (uint32_t)&stats->cs_ac_armour_bonus - iGO);
	_log(1, "cs_ac_armour_penalty            : %08X\n", (uint32_t)&stats->cs_ac_armour_penalty - iGO);
	_log(1, "cs_ac_deflection_bonus          : %08X\n", (uint32_t)&stats->cs_ac_deflection_bonus - iGO);
	_log(1, "cs_ac_deflection_penalty        : %08X\n", (uint32_t)&stats->cs_ac_deflection_penalty - iGO);
	_log(1, "cs_ac_shield_bonus              : %08X\n", (uint32_t)&stats->cs_ac_shield_bonus - iGO);
	_log(1, "cs_ac_shield_penalty            : %08X\n", (uint32_t)&stats->cs_ac_shield_penalty - iGO);
	_log(1, "cs_ac_natural_bonus             : %08X\n", (uint32_t)&stats->cs_ac_natural_bonus - iGO);
	_log(1, "cs_ac_natural_penalty           : %08X\n", (uint32_t)&stats->cs_ac_natural_penalty - iGO);
	_log(1, "cs_ac_dodge_bonus               : %08X\n", (uint32_t)&stats->cs_ac_dodge_bonus - iGO);
	_log(1, "cs_ac_dodge_penalty             : %08X\n", (uint32_t)&stats->cs_ac_dodge_penalty - iGO);
	_log(1, "cs_override_bab                 : %08X\n", (uint32_t)&stats->cs_override_bab - iGO);
	_log(1, "field_412                       : %08X\n", (uint32_t)&stats->field_412 - iGO);
	_log(1, "field_413                       : %08X\n", (uint32_t)&stats->field_413 - iGO);
	_log(1, "field_414                       : %08X\n", (uint32_t)&stats->field_414 - iGO);
	_log(1, "field_418                       : %08X\n", (uint32_t)&stats->field_418 - iGO);
	_log(1, "field_41C                       : %08X\n", (uint32_t)&stats->field_41C - iGO);
	_log(1, "field_420                       : %08X\n", (uint32_t)&stats->field_420 - iGO);
	_log(1, "field_424                       : %08X\n", (uint32_t)&stats->field_424 - iGO);
	_log(1, "*cs_combat_info                 : %08X\n", (uint32_t)&stats->cs_combat_info - iGO);
	_log(1, "*cs_combat_info                 : %08X\n", (uint32_t)&stats->cs_combat_info - iGO);
	_log(1, "field_42C                       : %08X\n", (uint32_t)&stats->field_42C - iGO);
	_log(1, "field_430                       : %08X\n", (uint32_t)&stats->field_430 - iGO);
	_log(1, "field_434                       : %08X\n", (uint32_t)&stats->field_434 - iGO);
	_log(1, "field_438                       : %08X\n", (uint32_t)&stats->field_438 - iGO);
	_log(1, "*cs_specabil                    : %08X\n", (uint32_t)&stats->cs_specabil - iGO);
	_log(1, "field_440                       : %08X\n", (uint32_t)&stats->field_440 - iGO);
	_log(1, "field_44C                       : %08X\n", (uint32_t)&stats->field_44C - iGO);
	_log(1, "field_450                       : %08X\n", (uint32_t)&stats->field_450 - iGO);
	_log(1, "field_454                       : %08X\n", (uint32_t)&stats->field_454 - iGO);
	_log(1, "field_458                       : %08X\n", (uint32_t)&stats->field_458 - iGO);
	_log(1, "field_45C                       : %08X\n", (uint32_t)&stats->field_45C - iGO);
	_log(1, "field_460                       : %08X\n", (uint32_t)&stats->field_460 - iGO);
	_log(1, "field_464                       : %08X\n", (uint32_t)&stats->field_464 - iGO);
	_log(1, "field_468                       : %08X\n", (uint32_t)&stats->field_468 - iGO);
	_log(1, "field_470                       : %08X\n", (uint32_t)&stats->field_470 - iGO);
	_log(1, "field_474                       : %08X\n", (uint32_t)&stats->field_474 - iGO);
	_log(1, "cs_skill_points                 : %08X\n", (uint32_t)&stats->cs_skill_points - iGO);
	_log(1, "*cs_skills                      : %08X\n", (uint32_t)&stats->cs_skills - iGO);
	_log(1, "cs_acp_armor                    : %08X\n", (uint32_t)&stats->cs_acp_armor - iGO);
	_log(1, "cs_acp_shield                   : %08X\n", (uint32_t)&stats->cs_acp_shield - iGO);
	_log(1, "cs_portrait[16]                 : %08X\n", (uint32_t)&stats->cs_portrait[16] - iGO);
	_log(1, "cs_al_goodevil                  : %08X\n", (uint32_t)&stats->cs_al_goodevil - iGO);
	_log(1, "field_48F                       : %08X\n", (uint32_t)&stats->field_48F - iGO);
	_log(1, "cs_al_lawchaos                  : %08X\n", (uint32_t)&stats->cs_al_lawchaos - iGO);
	_log(1, "field_491                       : %08X\n", (uint32_t)&stats->field_491 - iGO);
	_log(1, "cs_color_skin                   : %08X\n", (uint32_t)&stats->cs_color_skin - iGO);
	_log(1, "cs_color_hair                   : %08X\n", (uint32_t)&stats->cs_color_hair - iGO);
	_log(1, "cs_color_tattoo_1               : %08X\n", (uint32_t)&stats->cs_color_tattoo_1 - iGO);
	_log(1, "cs_color_tattoo_2               : %08X\n", (uint32_t)&stats->cs_color_tattoo_2 - iGO);
	_log(1, "cs_appearance                   : %08X\n", (uint32_t)&stats->cs_appearance - iGO);
	_log(1, "cs_phenotype                    : %08X\n", (uint32_t)&stats->cs_phenotype - iGO);
	_log(1, "cs_appearance_head              : %08X\n", (uint32_t)&stats->cs_appearance_head - iGO);
	_log(1, "cs_bodypart_rfoot               : %08X\n", (uint32_t)&stats->cs_bodypart_rfoot - iGO);
	_log(1, "cs_bodypart_lfoot               : %08X\n", (uint32_t)&stats->cs_bodypart_lfoot - iGO);
	_log(1, "cs_bodypart_rshin               : %08X\n", (uint32_t)&stats->cs_bodypart_rshin - iGO);
	_log(1, "cs_bodypart_lshin               : %08X\n", (uint32_t)&stats->cs_bodypart_lshin - iGO);
	_log(1, "cs_bodypart_lthigh              : %08X\n", (uint32_t)&stats->cs_bodypart_lthigh - iGO);
	_log(1, "cs_bodypart_rthigh              : %08X\n", (uint32_t)&stats->cs_bodypart_rthigh - iGO);
	_log(1, "cs_bodypart_pelvis              : %08X\n", (uint32_t)&stats->cs_bodypart_pelvis - iGO);
	_log(1, "cs_bodypart_torso               : %08X\n", (uint32_t)&stats->cs_bodypart_torso - iGO);
	_log(1, "cs_bodypart_belt                : %08X\n", (uint32_t)&stats->cs_bodypart_belt - iGO);
	_log(1, "cs_bodypart_neck                : %08X\n", (uint32_t)&stats->cs_bodypart_neck - iGO);
	_log(1, "cs_bodypart_rfarm               : %08X\n", (uint32_t)&stats->cs_bodypart_rfarm - iGO);
	_log(1, "cs_bodypart_lfarm               : %08X\n", (uint32_t)&stats->cs_bodypart_lfarm - iGO);
	_log(1, "cs_bodypart_rbicep              : %08X\n", (uint32_t)&stats->cs_bodypart_rbicep - iGO);
	_log(1, "cs_bodypart_lbicep              : %08X\n", (uint32_t)&stats->cs_bodypart_lbicep - iGO);
	_log(1, "cs_bodypart_rshoul              : %08X\n", (uint32_t)&stats->cs_bodypart_rshoul - iGO);
	_log(1, "cs_bodypart_lshoul              : %08X\n", (uint32_t)&stats->cs_bodypart_lshoul - iGO);
	_log(1, "cs_bodypart_rhand               : %08X\n", (uint32_t)&stats->cs_bodypart_rhand - iGO);
	_log(1, "cs_bodypart_lhand               : %08X\n", (uint32_t)&stats->cs_bodypart_lhand - iGO);
	_log(1, "field_4AC                       : %08X\n", (uint32_t)&stats->field_4AC - iGO);
	_log(1, "cs_tail_old                     : %08X\n", (uint32_t)&stats->cs_tail_old - iGO);
	_log(1, "cs_wings_old                    : %08X\n", (uint32_t)&stats->cs_wings_old - iGO);
	_log(1, "field_4AF                       : %08X\n", (uint32_t)&stats->field_4AF - iGO);
	_log(1, "cs_tail                         : %08X\n", (uint32_t)&stats->cs_tail - iGO);
	_log(1, "cs_wings                        : %08X\n", (uint32_t)&stats->cs_wings - iGO);
	_log(1, "cs_movement_rate                : %08X\n", (uint32_t)&stats->cs_movement_rate - iGO);
	_log(1, "cs_save_fort                    : %08X\n", (uint32_t)&stats->cs_save_fort - iGO);
	_log(1, "cs_save_will                    : %08X\n", (uint32_t)&stats->cs_save_will - iGO);
	_log(1, "cs_save_reflex                  : %08X\n", (uint32_t)&stats->cs_save_reflex - iGO);
	_log(1, "field_4C7                       : %08X\n", (uint32_t)&stats->field_4C7 - iGO);
	_log(1, "cs_acomp_type                   : %08X\n", (uint32_t)&stats->cs_acomp_type - iGO);
	_log(1, "cs_famil_type                   : %08X\n", (uint32_t)&stats->cs_famil_type - iGO);
	_log(1, "cs_acomp_name                   : %08X\n", (uint32_t)&stats->cs_acomp_name - iGO);
	_log(1, "cs_famil_name                   : %08X\n", (uint32_t)&stats->cs_famil_name - iGO);
	_log(1, "*cs_deity                       : %08X\n", (uint32_t)&stats->cs_deity - iGO);

	return 1;

}

int CNWNXFuncs::SetGold() {
	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->cre_gold = P1;

	return 1;
}

int CNWNXFuncs::SetXP() {
	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->cre_stats->cs_xp = P1;

	return 1;
}

int CNWNXFuncs::SetAbilityScore() {
	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;

	CNWSCreatureStats *Stats = cre->cre_stats;
	uint8_t *Abilities = &Stats->cs_str;

	unsigned short int iIndex = P1*2;

	if (P3)	P2 += Abilities[iIndex];

	if (P2 < 3) P2 = 3;
	else if (P2 > 255) P2 = 255;

	switch (P1) {
		case 0: Stats->SetSTRBase(P2); break;
		case 1: Stats->SetDEXBase(P2); break;
		case 2: Stats->SetCONBase(P2, P4); break;
		case 3: Stats->SetINTBase(P2); break;
		case 4: Stats->SetWISBase(P2); break;
		case 5: Stats->SetCHABase(P2); break;
	}
	//Abilities[iIndex] = P2;
	//Abilities[iIndex+1] = (P2-10)/2;
	
	return 1;
}

/*int CNWNXFuncs::SetLastEffectSpellID() {
	const CNWSObject *obj = (CNWSObject*)oObject;

	if (!ValidEffectObject()) {
		_log(2, "o Error: SetLAstEffectSpellID used on non-effect object.\n");
		return 0;
	}

	CGameEffect *eff = NULL;
	uint32_t iID = 0;

	//find highest effect id which I'm hoping will always be the last applied effect.
	//Scripteffects that apply more than one effect (e.g.: EffectAbilityIncrease applies AbilityIncrease and Icon effects)
	//should have the same effect id
	//Haste is a problem because it applies the actual haste effect and 4 additional which share the same effect id
	//which is different than the haste effect id
	//Wish there was a better way than 2 for loops (pointers?)
	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		eff = obj->obj_effects[i];
		if (eff == NULL) continue;
		if (eff->eff_id > iID) iID = eff->eff_id;
	}

	_log(1, "o SetLastEffectSpellID: Highest effectID: %i [new spell id: %i]\n", iID, P1);

	//now set all effects with iID as effect id to Parameters
	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		eff = obj->obj_effects[i];
		if (eff->eff_id == iID) {
			eff->eff_spellid = P1;
		}
	}
	
	return 1;
}
*/
/*int CNWNXFuncs::SetLastEffectCreator() {
	const CNWSObject *obj = (CNWSObject*)oObject;

	if (!ValidEffectObject()) {
		_log(2, "o Error: SetLAstEffectSpellID used on non-effect object.\n");
		return 0;
	}

	CGameEffect *eff = NULL;
	uint32_t iID = 0;

	//find highest effect id which I'm hoping will always be the last applied effect.
	//Scripteffects that apply more than one effect (e.g.: EffectAbilityIncrease applies AbilityIncrease and Icon effects)
	//should have the same effect id
	//Wish there was a better way than 2 for loops (pointers?)
	uint32_t len = obj->obj_effects_len;
	_log(3, "# of effcts: %i\n", len);

	int unsigned i=0;
	for (i=0; i < len; i++) {
		eff = obj->obj_effects[i];
		if ((eff->eff_id) > (iID)) {
			iID = eff->eff_id;
		}
		else {
		}
	}

	_log(1, "o SetLastEffectCreator: Highest effectID: %i [new creator: %s]\n", iID, Params);

	uint32_t newcreator=0;
	sscanf(Params, "%X", &newcreator);
	//now set all effects with iID as effect id to Parameters
	for (i=0; i< obj->obj_effects_len; i++) {
		eff = obj->obj_effects[i];
		if (eff->eff_id == iID) {
			eff->eff_creator = newcreator;
		}
	}
	return iID;

	return 1;
}
*/
uint32_t CNWNXFuncs::StringToObject(const char *soID) {

	if (strlen(soID) > 8) {
		//oID can't be greater than 8 chars (4 hex chars);
		sprintf(Params, "-1");
		_log(2, "o Error: StringtoObject: object ID passed is greater than 8 characters!\n");
		return 0; 
	}

	nwn_objid_t iObject = OBJECT_INVALID;

	sscanf(soID, "%08X", &iObject);

	return iObject;
}


int CNWNXFuncs::PrintEffects() {
	const CNWSObject *obj = NULL;
	CGameEffect *eff = NULL;
	obj = (CNWSObject*)oObject;

	if (!ValidEffectObject()) {
		sprintf(Params, "-1");
		_log(2, "o Error: SetLAstEffectSpellID used on non-effect object.\n");
		return 0;
	}

	UINT32 oID = obj->obj_generic.obj_id;
	_log(0, "o Printing Effects for: %08X\n", obj->obj_generic.obj_id);
	unsigned int i=0;
	_log(0, "@        |\t#   |\tID      |\tType    |\tSub   |\tDurT  |\tDur        |\tExD       |\tExT       |\tCreator |\tSpellID |\tE   |\tI   |\tL\n");
	for (i=0; i< obj->obj_effects_len; i++) {
		eff = obj->obj_effects[i];
		if (eff == NULL) continue;
		_log(0, "\
%#08X\
|\t%-04i\
|\t%08X\
|\t%8i\
|\t%-6i\
|\t%-6i\
|\t%-11.6f\
|\t%-10i\
|\t%-10i\
|\t%08X\
|\t%08X\
|\t%-4i\
|\t%-4i\
|\t%-4i\
\n",
			eff,
			i, 
			eff->eff_id,
			eff->eff_type,
			eff->eff_dursubtype & 24,
			eff->eff_dursubtype & 7,
			eff->eff_duration,
			eff->eff_expire_day,
			eff->eff_expire_time,
			eff->eff_creator,
			eff->eff_spellid,
			eff->eff_is_exposed,
			eff->eff_is_iconshown,
			eff->eff_skiponload		 
			);
	}
	return 1;
}

int CNWNXFuncs::GetLocalVariableByPosition(int nIndex) {
	sprintf(Params, "%d¬%s", 0, "0");
	if (nIndex == -1) {
		nIndex = P1;
	}
	const CNWSScriptVarTable *vartable;
	if ((vartable = GetVarTable()) == NULL) {
		_log(2, "o Error: GetLocalVariableByPosition: Could not find scriptvar table for object %09X!\n", ((CGenericObject*)oObject)->obj_id);
		sprintf(Params, "-1");
		return 0;
	}
	CScriptVariable *scriptVar = vartable->vt_list; 
	int n = vartable->vt_len;
	if (nIndex > n-1) { // the last variable is the NWNX!FUNCS one itself, no need to return it.
		_log(3, "o Error: GetLocalVariableByPosition: Requested local variable index (%i) exceeds number of local variables (%i) for object %09X!\n", nIndex, n, ((CGenericObject*)oObject)->obj_id);
		sprintf(Params, "");
		return 0;
	}
	sprintf(Params, "%d¬%s", scriptVar[nIndex].var_type, scriptVar[nIndex].var_name.text);
	return 1;
}

int CNWNXFuncs::GetFirstLocalVariable() {
	P1 = 0;
	// set the object id in any case, that way getnextlocalvariable won't throw an error if there are no locals
	getFirstNextVarObj = ((CGenericObject*)oObject)->obj_id;
	if (!GetLocalVariableByPosition(0)) {
		getFirstNextVarIndex = -1;
		return 0;
	}
	else {
		getFirstNextVarIndex = 0;
	}
	return 1;
}

int CNWNXFuncs::GetNextLocalVariable() {
	if (getFirstNextVarIndex < 0) return 0;
	if (((CGenericObject*)oObject)->obj_id != getFirstNextVarObj) {
		_log(2, "o ERROR: GetNextLocalVar used on an object before GetFirstLocalVar!\n");
		return 0;
	}
	else {
		getFirstNextVarIndex++;
		if(!GetLocalVariableByPosition(getFirstNextVarIndex)) {
			getFirstNextVarIndex = -1; // don't even read anymore 
			return 0;
		}
	}
	return 1;
}

uint32_t CNWNXFuncs::GetAreaByPosition(int iPos) {
	CNWSModule *cModule = nwn_GetModule();

	if (cModule) {

		uint32_t iPosition = (iPos == -1 ? P1 : iPos);
		if (iPosition >= cModule->mod_areas_len || iPosition < 0) {
			return OBJECT_INVALID;
		}

		uint32_t oArea = cModule->mod_areas[iPosition];
		return oArea;
	}
	return OBJECT_INVALID;
}

uint32_t CNWNXFuncs::GetFirstArea() {
	getFirstNextAreaIndex = 0;
	uint32_t ret = OBJECT_INVALID;

	ret = GetAreaByPosition(getFirstNextAreaIndex);
	if (ret == OBJECT_INVALID) getFirstNextAreaIndex=-1;

	return ret;
}

uint32_t CNWNXFuncs::GetNextArea() {
	uint32_t ret = OBJECT_INVALID;

	if (getFirstNextAreaIndex < 0) return OBJECT_INVALID; // skip out if there are no more areas

	getFirstNextAreaIndex++;
	ret = GetAreaByPosition(getFirstNextAreaIndex);
	if (ret == OBJECT_INVALID) getFirstNextAreaIndex = -1;

	return ret;
}

int CNWNXFuncs::GetBABOverride() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetBabOverride used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", ((CNWSCreature*)oObject)->cre_stats->cs_override_bab);

	return 1;
}

int CNWNXFuncs::SetBABOverride() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetBabOverride used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	if (P2) P1 += ((CNWSCreature*)oObject)->cre_stats->cs_override_bab;
	((CNWSCreature*)oObject)->cre_stats->cs_override_bab = P1;

	return 1;
}

int CNWNXFuncs::AddFeatAtLevel() {
	CNWSCreature *cre = (CNWSCreature*)oObject;

	if (!GetIsCreature()) {
		_log(2, "o Error: AddFeatAtLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)cre->cre_stats;
	CNWSStats_Level *ls;
	if ((ls = nwn_GetLevelStats(Stats, P1)) == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreatureStats*)cre->cre_stats)->AddFeat(P2);
	ls->AddFeat(P2);

	return 1;
}

int CNWNXFuncs::AddFeat() {
	CNWSCreature *cre = (CNWSCreature*)oObject;

	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		_log(2, "o Error: AddFeat used on non-creature object.\n");
		return 0;
	}

	((CNWSCreatureStats*)cre->cre_stats)->AddFeat(P1);
	return 1;
}

int CNWNXFuncs::SetRace(){
	if (!GetIsCreature()) {
		_log(2, "o Error: SetRace used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	
	((CNWSCreature*)(oObject))->cre_stats->cs_race = P1;
	
	return 1;
}

int CNWNXFuncs::GetBaseAC(){
	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		_log(2, "o Error: GetBaseAC used on non-creature object.\n");
		return 0;
	}
	uint8_t ac = 0;
	switch (P1) {
		case AC_NATURAL: ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_natural_base; break;
		case AC_ARMOUR:  ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_armour_base; break;
		case AC_SHIELD:  ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_shield_base; break;
	}
	sprintf(Params, "%d", ac);
	return 1;
}

int CNWNXFuncs::SetBaseAC() {
	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		_log(2, "o Error: SetBaseAC used on non-creature object.\n");
		return 0;
	}
	switch (P2) {
		case AC_NATURAL: ((CNWSCreature*)(oObject))->cre_stats->cs_ac_natural_base = P1; break;
		case AC_ARMOUR : ((CNWSCreature*)(oObject))->cre_stats->cs_ac_armour_base = P1; break;
		case AC_SHIELD : ((CNWSCreature*)(oObject))->cre_stats->cs_ac_shield_base = P1; break;
	}
	return 1;
}

int CNWNXFuncs::GetBonusAC() {
	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		_log(2, "o Error: GetBonusAC used on non-creature object.\n");
		return 0;
	}
	uint8_t ac = 0;
	switch (P1) {
		case AC_NATURAL:	ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_natural_bonus; break;
		case AC_ARMOUR:		ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_armour_bonus; break;
		case AC_SHIELD:		ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_shield_bonus; break;
		case AC_DEFLECTION:	ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_deflection_bonus; break;
		case AC_DODGE:		ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_dodge_bonus; break;
	}
	sprintf(Params, "%d", ac);
	return 1;
}

int CNWNXFuncs::SetBonusAC() {

	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		_log(2, "o Error: SetBonusAC used on non-creature object.\n");
		return 0;
	}
	switch (P2) {
		case AC_NATURAL:	((CNWSCreature*)(oObject))->cre_stats->cs_ac_natural_bonus = P1; break;
		case AC_ARMOUR:		((CNWSCreature*)(oObject))->cre_stats->cs_ac_armour_bonus = P1; break;
		case AC_SHIELD:		((CNWSCreature*)(oObject))->cre_stats->cs_ac_shield_bonus = P1; break;
		case AC_DEFLECTION:	((CNWSCreature*)(oObject))->cre_stats->cs_ac_deflection_bonus = P1; break;
		case AC_DODGE:		((CNWSCreature*)(oObject))->cre_stats->cs_ac_dodge_bonus = P1; break;
	}
	return 1;
}

int CNWNXFuncs::GetPenaltyAC() {

	if (!GetIsCreature()) {
		sprintf(Params, "-1");
		_log(2, "o Error: GetPenaltyAC used on non-creature object.\n");
		return 0;
	}
	uint8_t ac = 0;
	switch (P1) {
		case AC_NATURAL:	ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_natural_penalty; break;
		case AC_ARMOUR:		ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_armour_penalty; break;
		case AC_SHIELD:		ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_shield_penalty; break;
		case AC_DEFLECTION:	ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_deflection_penalty; break;
		case AC_DODGE:		ac = ((CNWSCreature*)(oObject))->cre_stats->cs_ac_dodge_penalty; break;
	}
	sprintf(Params, "%d", ac);
	return 1;
}

int CNWNXFuncs::SetPenaltyAC() {

	if (!GetIsCreature()) {
		_log(2, "o Error: SetPenaltyAC used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	switch (P2) {
		case AC_NATURAL:	((CNWSCreature*)(oObject))->cre_stats->cs_ac_natural_penalty = P1; break;
		case AC_ARMOUR:		((CNWSCreature*)(oObject))->cre_stats->cs_ac_armour_penalty = P1; break;
		case AC_SHIELD:		((CNWSCreature*)(oObject))->cre_stats->cs_ac_shield_penalty = P1; break;
		case AC_DEFLECTION:	((CNWSCreature*)(oObject))->cre_stats->cs_ac_deflection_penalty = P1; break;
		case AC_DODGE:		((CNWSCreature*)(oObject))->cre_stats->cs_ac_dodge_penalty = P1; break;
	}
	return 1;
}

int CNWNXFuncs::GetSavedSkillPoints() {

	if (!GetIsCreature()) {
		_log(2, "o Error: GetSavedSkillPoints used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	if (P1 == 0) {
		sprintf(Params, "%d", ((CNWSCreature*)(oObject))->cre_stats->cs_skill_points);
	}
	else {
		CNWSStats_Level *ls = nwn_GetLevelStats(((CNWSCreature*)(oObject))->cre_stats, P1);
		if (ls) sprintf(Params, "%d", ls->ls_skillpoints);
	}

	return 1;
}

int CNWNXFuncs::SetSavedSkillPoints() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetSavedSkillPoints used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)(oObject);

	if (P2) {
		if (P3 > 0) {
			CNWSStats_Level *ls = nwn_GetLevelStats(cre->cre_stats, P3);
			if (ls) ls->ls_skillpoints += P1;
		}
		else {
			cre->cre_stats->cs_skill_points += P1;
		}
	}
	else {
		if (P3 > 0) {
			CNWSStats_Level *ls = nwn_GetLevelStats(cre->cre_stats, P3);
			if (ls) ls->ls_skillpoints = P1;
		}
		else {
			cre->cre_stats->cs_skill_points = P1;
		}
	}
	return 1;
}

int CNWNXFuncs::GetArmorCheckPenalty() {

	if (!GetIsCreature()) {
		_log(2, "o Error: GetArmorCheckPenalty used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int8_t acp = 0;
	switch (P1) {
		case AC_ARMOUR: acp = ((CNWSCreature*)(oObject))->cre_stats->cs_acp_armor; break;
		case AC_SHIELD: acp = ((CNWSCreature*)(oObject))->cre_stats->cs_acp_shield; break;
	}
	sprintf(Params, "%d", acp);
	return 1;
}

int CNWNXFuncs::SetArmorCheckPenalty() {

	if (!GetIsCreature()) {
		_log(2, "o Error: SetArmorCheckPenalty used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	_log(1, "o Setting ArmorCheckPenalty [%08X | %s]: %i, %i\n", oObject, Params, P2, P1);
	switch (P2) {
		case AC_ARMOUR: ((CNWSCreature*)(oObject))->cre_stats->cs_acp_armor = P1; break;
		case AC_SHIELD: ((CNWSCreature*)(oObject))->cre_stats->cs_acp_shield = P1; break;
	}
	return 1;
}

int CNWNXFuncs::GetMovementRate() {
	if (!GetIsCreature()) {
		_log(2, "o Error: GetMovementRate used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", ((CNWSCreature*)(oObject))->cre_stats->cs_movement_rate);
	return 1;
}

int CNWNXFuncs::SetMovementRate() {
	if (!GetIsCreature()) {
		_log(2, "o Error: GetMovementRate used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)(oObject))->cre_stats->cs_movement_rate = P1;

	return 1;
}

int CNWNXFuncs::SetFamiliarType() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetFamiliarType used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)(oObject))->cre_stats->cs_famil_type = P1;
	return 1;
}

int CNWNXFuncs::SetCompanionType() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetCompanionType used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)(oObject))->cre_stats->cs_acomp_type = P1;
	return 1;
}

int CNWNXFuncs::SetHitPointsByLevel() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetHitPointsByLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *obj = (CNWSCreature*)oObject;
	CNWSStats_Level *ls = nwn_GetLevelStats(obj->cre_stats, P2);

	if (!ls) {
		sprintf(Params, "-1");
		return 0;
	}
	
	if (!P3) ls->ls_hp = P1;
	else ls->ls_hp += P1;
	return 1;
}

int CNWNXFuncs::SetCurrentHitPoints() {
	if (!ValidEffectObject()) {
		_log(2, "o Error: SetCurrentHitPoints used on non-hp object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSObject*)(oObject))->obj_hp_cur = P1;
	return 1;
}

int CNWNXFuncs::SetMaxHitPoints() {
	if (!ValidEffectObject()) {
		_log(2, "o Error: SetMaxHitPoints used on non-hp object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSObject*)(oObject))->obj_hp_max = P1;
	return 1;
}

int CNWNXFuncs::SetSavingThrowBonus() {
	_log(3, "o SavingThrowBonus: P1=%i, P2=%i, P3=%1\n", P1, P2,P3);
	if (!GetIsCreature()) {
		_log(2, "o Error: SetSavingThrowBonus used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *obj = (CNWSCreature*)oObject;

	switch (P1) {
		case 1: obj->cre_stats->cs_save_fort = P3 ? obj->cre_stats->cs_save_fort + P2 : P2; break;
		case 2: obj->cre_stats->cs_save_reflex = P3 ? obj->cre_stats->cs_save_reflex + P2 : P2; break;
		case 3: obj->cre_stats->cs_save_will = P3 ? obj->cre_stats->cs_save_will + P2 : P2; break;
		default:
			sprintf(Params, "-1");
			_log(2, "o Error: SetSavingThrowBonus: Invalid Saving Throw Type\n");
		break;

	}
	return 1;
}

int CNWNXFuncs::SetSkill() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetSkill used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}


	if (P1 > nSkill) {
		_log(2, "o Error (SetSkill): Specified Skill [%i] is outside the range specified in nwnx.ini [%i].\n", P1, nSkill);
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;
	if (P3) P2 += cre->cre_stats->cs_skills[P1];

	if (P2 > 127) P2 = 127;
	if (P2 < 0) P2 = 0;

	cre->cre_stats->cs_skills[P1] = P2;

	return 1;
}

int CNWNXFuncs::SetSkillByLevel() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetSkillByLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *obj = (CNWSCreature*)oObject;
	CNWSStats_Level *ls;

	if (P1 > nSkill) {
		_log(2, "o Error (SetSkill): Specified Skill [%i] is outside the range specified in nwnx.ini [%i].\n", P1, nSkill);
		sprintf(Params, "-1");
		return 0;
	}

	if ((ls = nwn_GetLevelStats(obj->cre_stats, P3)) == NULL) {
		_log(2, "o Error (SetSkill): Invalid level\n", P1, nSkill);
		sprintf(Params, "-1");
		return 0;
	}

	int iVal = P2;

	if (P4) {
		iVal = P2 + obj->cre_stats->cs_skills[P1];
		P2 += ls->ls_skilllist[P1];
	}

	if (P2 > 127) P2 = 127;
	if (P2 < 0) P2 = 0;
	ls->ls_skilllist[P1] = P2;

	if (iVal > 127) iVal = 127;
	if (iVal < 0) iVal = 0;
	obj->cre_stats->cs_skills[P1] = iVal;

	return 1;
}

int CNWNXFuncs::GetAreaCount() {
	CNWSModule *cModule = (CNWSModule*)oObject;
	if (!cModule) {
		sprintf(Params, "-1");
		return 0;
	}
	
	sprintf(Params, "%d", cModule->mod_areas_len);

	return 1;
}

int CNWNXFuncs::GetLocalVariableCount() {
	CNWSScriptVarTable *vartable;
	if ((vartable = GetVarTable()) == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", vartable->vt_len);

	return 1;
}

int CNWNXFuncs::GetHasLocalVariable() {
	const CNWSScriptVarTable *vartable;
	if ((vartable = GetVarTable()) == NULL) {
		sprintf(Params, "-1");
		return 0;
	}
	CScriptVariable *scriptVar = vartable->vt_list;

	std::string sVarName = Params;
	int iP;

	uint32_t varType;
	int n = vartable->vt_len;
	iP = sVarName.find(" ");
	varType = atoi((sVarName.substr(iP+1)).c_str());
	sVarName = sVarName.substr(0, iP);

	for (int i=0; i<n; i++) {
		if ((strcmp(sVarName.c_str(), (&scriptVar->var_name)->text) == 0) && ( varType == 0 || varType == scriptVar->var_type)) {
			sprintf(Params, "%d", scriptVar->var_type);
			return 1;
		}
		scriptVar++;
	}
	sprintf(Params, "0");


	return 1;
}

int CNWNXFuncs::PrintLocalVars() {
	const CNWSScriptVarTable *vartable;
	if ((vartable = GetVarTable()) == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	CScriptVariable *scriptVar = vartable->vt_list; 

	uint32_t varType;
	uint32_t varValue;
	int n = vartable->vt_len;

	_log(0, "o Printing local vars for %08X\n", ((CGenericObject*)oObject)->obj_id);
	for (int i=0; i<n; i++) {
		varType = scriptVar->var_type;
		varValue = scriptVar->var_value;
		switch (varType) {
			case 1: _log(0, "  [%s] %s = %i\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, varValue); break;
			case 2: _log(0, "  [%s] %s = %f\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, *(float*)&scriptVar->var_value); break;
			case 3: _log(0, "  [%s] %s = %s\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, ((CExoString*)*&varValue)->text); break;
			case 4: _log(0, "  [%s] %s = %08X\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, varValue); break;
			case 5: {
				Vector *v = (Vector*)*&varValue;
				_log(0, "  [%s] %s = (%f, %f, %f)\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, v->x, v->y, v->z); break;
			}
		}
		scriptVar++;
	}
	return 1;
}

int CNWNXFuncs::GetEvent() {
	sprintf(Params, "-1");
	switch (((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE: {
			CNWSCreature *cre = (CNWSCreature*)oObject;
			if (P1 >= 0 && P1 < 16) {
				void *p = ((char*)&cre->cre_events.onHeartbeat)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type creature\n");
			}
		} break;
		case OBJECT_TYPE_AREA: {
			CNWSArea *Area = (CNWSArea*)oObject;
			if (P1 >= 0 && P1 < 4) {
				void *p = ((char*)&Area->are_script_hb)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for area\n");
			}
		}break;
		case OBJECT_TYPE_PLACEABLE: {
			CNWSPlaceable *Plc = (CNWSPlaceable*)oObject;
			if (P1 >= 0 && P1 < 17) {
				void *p = ((char*)&Plc->OnClosed)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type placeable\n");
			}
		}break;
		case OBJECT_TYPE_AREA_OF_EFFECT: {
			CNWSAreaOfEffectObject *AoE = (CNWSAreaOfEffectObject*)oObject;
			if (P1 >= 0 && P1 < 4) {
				void *p = ((char*)&AoE->OnHeartbeat)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type AoE\n");
			}
		}break;
		case OBJECT_TYPE_DOOR: {
			CNWSDoor *Door = (CNWSDoor*)oObject;
			if (P1 >= 0 && P1 < 15) {
				void *p = ((char*)&Door->OnOpen)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Door\n");
			}
		}break;
		case OBJECT_TYPE_ENCOUNTER: {
			CNWSEncounter *Enc = (CNWSEncounter*)oObject;
			if (P1 >= 0 && P1 < 5) {
				void *p = ((char*)&Enc->OnEntered)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Encounter\n");
			}
		}break;
		case OBJECT_TYPE_MODULE: {
			CNWSModule *Mod = (CNWSModule*)oObject;
			if (P1 >= 0 && P1 < 18) {
				void *p = ((char*)&Mod->Mod_OnHeartbeat)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Module\n");
			}
		}break;
		case OBJECT_TYPE_STORE: {
			CNWSStore *Store = (CNWSStore*)oObject;
			if (P1 >= 0 && P1 < 2) {
				void *p = ((char*)&Store->OnOpenStore)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Store\n");
			}
		}break;
		case OBJECT_TYPE_TRIGGER: {
			CNWSTrigger *Trigger = (CNWSTrigger*)oObject;
			if (P1 >= 0 && P1 < 7) {
				void *p = ((char*)&Trigger->OnHeartbeat)+ P1 * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Trigger\n");
			}
		}break;
		default: sprintf(Params, "-1"); return 0; break;
	}

	if (strcmp(Params, "(null)") == 0) sprintf(Params, "");
	return 1;
}

int CNWNXFuncs::SetEvent() {
	int iScript=0;
	std::string ScriptName = "";

	switch (((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE: {
			CNWSCreature *cre;
			if ((cre = ((*NWN_AppManager)->app_server->srv_internal)->GetCreatureByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 13)) {
					cre->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetCreatureEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetCreatureEventScript): Invalid Creature\n");
		}break;
		case OBJECT_TYPE_AREA: {
			CNWSArea *Area;
			if ((Area = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 3)) {
					Area->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetAreaEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetAreaEventScript): Invalid Area\n");
		}break;
		case OBJECT_TYPE_PLACEABLE: {
			CNWSPlaceable *Plc;
			if ((Plc = ((*NWN_AppManager)->app_server->srv_internal)->GetPlaceableByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 15)) {
					Plc->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetPlaceableEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetPlaceableEventScript): Invalid Placeable\n");
		}break;
		case OBJECT_TYPE_AREA_OF_EFFECT: {
			CNWSAreaOfEffectObject *AoE;
			if ((AoE = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaOfEffectByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 3)) {
					AoE->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetAoEEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetAoEEventScript): Invalid AoE\n");
		}break;
		case OBJECT_TYPE_DOOR: {
			CNWSDoor *Door;
			if ((Door = ((*NWN_AppManager)->app_server->srv_internal)->GetDoorByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 14)) {
					Door->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetDoorEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetDoorEventScript): Invalid Door\n");
		}break;
		case OBJECT_TYPE_ENCOUNTER: {
			CNWSEncounter *Enc;
			if ((Enc = ((*NWN_AppManager)->app_server->srv_internal)->GetEncounterByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 4)) {
					Enc->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetEncounterEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetEncounterEventScript): Invalid Encounter\n");
		}break;
		case OBJECT_TYPE_MODULE: {
			CNWSModule *Mod;
			if ((Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule())) {
				if (GetEventScriptInfo(iScript, ScriptName, 17)) {
					Mod->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetModuleEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetModuleEventScript): Invalid Module\n");
		}break;
		case OBJECT_TYPE_STORE: {
			CNWSStore *Store;
			if ((Store = ((*NWN_AppManager)->app_server->srv_internal)->GetStoreByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 1)) {
					Store->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetStoreEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetStoreEventScript): Invalid Store\n");
		}break;
		case OBJECT_TYPE_TRIGGER: {
			CNWSTrigger *Trigger;
			if ((Trigger = ((*NWN_AppManager)->app_server->srv_internal)->GetTriggerByGameObjectID(((CGenericObject*)oObject)->obj_id))) {
				if (GetEventScriptInfo(iScript, ScriptName, 6)) {
					Trigger->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetTriggerEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetTriggerEventScript): Invalid Trigger\n");
		}break;
	}

	return 1;
}

int CNWNXFuncs::SetTag() {
	_log(3, "SetTag: %s\n", Params);
	uint32_t oID = ((CNWSObject*)oObject)->obj_generic.obj_id;
	CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	CLookupTableObject *LookupObject = Mod->lookuptable;
	int i=0;
	while (i<Mod->lookuptable_len) {
		if (LookupObject->obj_oid == oID) {
			CGenericObject *obj = LookupObject->pObject;
			CExoString sNewTag(Params);
			((CNWSObject*)oObject)->SetTag(sNewTag);

			strcpy(LookupObject->Tag, Params);
			break;
			//CExoString Newtag(Params);
		}
		LookupObject++;
		i++;
	}
	
	return 1;
}

int CNWNXFuncs::SetCreatureSize() {
	if (!GetIsCreature()) {
		_log(2, "o Error SetCreatureSize used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	
	CNWSCreature *cre = (CNWSCreature*)oObject;
	cre->cre_size = P1;

	return 1;
}

int CNWNXFuncs::GetEquippedWeight() {
	if (!GetIsCreature()) {
		_log(2, "o Error GetEquippedWeight used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	sprintf(Params, "%d", ((CNWSCreature*)oObject)->cre_equipped_weight);
	return 1;
}

int CNWNXFuncs::RemoveFeat() {
	//P1 = feat
	//P2 = bByLevel

	if (!GetIsCreature()) {
		_log(2, "o Error RemoveFeat used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;
	CNWSCreatureStats *Stats = (CNWSCreatureStats*)cre->cre_stats;
	CNWSStats_Level *ls;

	int iLevelIndex = -1;

	//check the general feat list
	int iGeneralIndex = CExoArrayList_uint16_contains(&Stats->cs_feats, P1);
	if (iGeneralIndex > 0) {
		_log(3, "Feat %i found in general feat index at position %i.\n", P1, iGeneralIndex);
		CExoArrayList_uint16_delfeatindex(&Stats->cs_feats, iGeneralIndex);
	}

	int iLevel = 0;
	//check the feat list for the level provided; if provided
	if (P2) {
		while ((ls = nwn_GetLevelStats(Stats, ++iLevel)) != NULL) {
			if((iLevelIndex = CExoArrayList_uint16_contains(&(ls->ls_featlist), P1)) > -1) {
				_log(3, "Feat %i found in in feat list of level %i at position %i.\n", P1, iLevel, iLevelIndex);
				CExoArrayList_uint16_delfeatindex(&Stats->cs_feats, iLevelIndex);
				break;
			}
		}
		if (ls == NULL) {
			// looped through all levels and couldn't find the feat
		}
	}
	return 1;
}

int CNWNXFuncs::GetFeatKnown() {
	if (!GetIsCreature()) {
		_log(2, "o Error GetFeatKnown used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;

	int iGeneralIndex = (CExoArrayList_uint16_contains(&Stats->cs_feats, P1))+1;

	sprintf(Params, "%d", iGeneralIndex);
	return iGeneralIndex;
}

int CNWNXFuncs::GetAllKnownFeats() {
	if (!GetIsCreature()) {
		_log(2, "o Error GetAllKnownFeats used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	char *sDelimiter = strchr(Params, ' ');
	char *sFeat;

	int iSize;
	try {
		iSize = sDelimiter-Params;
		sDelimiter = (char*)calloc(iSize, sizeof(char)+1);
		sscanf(Params, "%s ", sDelimiter);
		sFeat = (char*)calloc(6, sizeof(char)); //holds the feat as a string; max feat is 65535 so we need 5+1 chars to store it
	}
	catch (std::exception &e) {
		_log(2, "o Error (GetAllKnownFeats): %s\n", e.what());
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CExoArrayList_uint16 *Feats = &Stats->cs_feats;
	
	// FFFFFDFFFFFDFFFFF\n
	iSize = (Feats->len*5+(Feats->len-1)*strlen(sDelimiter))+1;

	if (iSize > strlen(Params)) {
		_log(2, "o Error (GetAllKnownFeats): Size of return string [%d] would be greater than spacer [%d].\n", iSize, strlen(Params));
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "");
	if (Feats->len > 0) {
		sprintf(Params, "%d", Feats->data[0]);

		int i=0;
		while (++i < Feats->len) {
			Params = strcat(Params, sDelimiter);
			sprintf(sFeat, "%d", Feats->data[i]);
			Params = strcat(Params, sFeat);
		}
	}
	else {
		sprintf(Params, "");
	}

	free(sFeat);
	free(sDelimiter);

	return 1;
}


int CNWNXFuncs::ClearFeatList() {
	if (!GetIsCreature()) {
		_log(2, "o Error ClearFeatList used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	
	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	Stats->cs_feats.len = 0;

	if (P1) {
		CNWSStats_Level *ls;
		int iLevel = 0;

		while ((ls = nwn_GetLevelStats(Stats, ++iLevel)) != NULL) {
			ls->ls_featlist.len = 0;
		}
	}

	return 1;
}

int CNWNXFuncs::ZeroAllSkills() {
	if (!GetIsCreature()) {
		_log(2, "o Error ZeroAllSkills used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *obj = (CNWSCreature*)oObject;
	CNWSStats_Level *ls;

	int iLevel = 0;
	int iSkill = 0;
	
	while ((ls = nwn_GetLevelStats(obj->cre_stats, ++iLevel)) != NULL) {
		for(iSkill = nSkill; iSkill > 0; iSkill--) {
			obj->cre_stats->cs_skills[iSkill] = 0;
			if (iLevel == 1) ls->ls_skilllist[iSkill] = 0;
		}
	}
	return 1;
}

int CNWNXFuncs::AddKnownSpell() {
	if (!GetIsCreature()) {
		_log(2, "o Error AddSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, sp_class = P1, sp_level = P2, sp_id = P3;
	CNWSCreature *cre = (CNWSCreature*)oObject;
	CNWSStats_Level *ls;

	if (cre->cre_stats == NULL ||
		sp_level < 0 || sp_level > 9) {
			return 0;
	}

	/* find the requested class and level, then add the new spell */
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].alloc < 1) {
			cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len  = 0;
			cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data = NULL;
		}

		if (CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id) == -1) {
			CExoArrayList_uint32_add(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id);
			if (P4 > 0) {
				if((ls = nwn_GetLevelStats(cre->cre_stats, P4)) != NULL) {
					CExoArrayList_uint32_add(&(ls->ls_spells_known[sp_level]), sp_id);
				}
			}
		}
	}
	return 1;
}

int CNWNXFuncs::RemoveKnownSpell() {
	if (!GetIsCreature()) {
		_log(2, "o Error RemoveKnownSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, sp_class = P1, sp_id=P2;
	int sp_level=0;
	int iIndex=0;
	CNWSCreature *cre = (CNWSCreature*)oObject;
	CNWSStats_Level *ls;

	if (cre->cre_stats == NULL ||
		sp_level < 0 || sp_level > 9) {
			return 0;
	}

	/* find the requested class and level, then remove the new spell */
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
						if ((iIndex = CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id)) > -1) {
							_log(3, "Spell %i found in class[i] spell list[%i] of class type sp_class.\n", sp_id, sp_class, sp_level, i);
							CExoArrayList_uint32_delfeatindex(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), iIndex);
						}
					}
				}
			}
		}
	}

	if (P3 > 0) {
		// need to loop through all levels, through all spell levels
		int iCharacterLevel=0;
		sp_level=0;
		while ((ls = nwn_GetLevelStats(cre->cre_stats, ++iCharacterLevel)) != NULL) {
			if (ls->ls_class == sp_class) {
				for (sp_level = 0; sp_level <=9; sp_level++) {
					if (ls->ls_spells_known[sp_level].len > 0) {
						if ((iIndex = CExoArrayList_uint32_contains(&(ls->ls_spells_known[sp_level]), sp_id)) > -1) {
							_log(3, "Spell %i found in spell list[%i] at at character level %i.\n", sp_id, sp_level, iCharacterLevel);
							CExoArrayList_uint32_delfeatindex(&(ls->ls_spells_known[sp_level]), iIndex);
						}
					}
				}
			}
		}
	}
	return 1;
}

int CNWNXFuncs::RemoveAllSpells() {
	int i=0, sp_level=0;

	if (!GetIsCreature()) {
		_log(2, "o Error RemoveAllSpells used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;
	CNWSStats_Level *ls;

	if (cre->cre_stats == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	/* find the requested class and level, then remove the new spell */
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != P1)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len = 0;
				}
			}
		}
	}

	int iCharacterLevel=0;
	sp_level=0;
	while ((ls = nwn_GetLevelStats(cre->cre_stats, ++iCharacterLevel)) != NULL) {
		for (sp_level = 0; sp_level <=9; sp_level++) {
			if (ls->ls_spells_known != NULL) {
				ls->ls_spells_known[sp_level].len = 0;
			}
		}
	}

	return 1;
}

int CNWNXFuncs::GetKnowsSpell() {
	sprintf(Params, "0");
	if (!GetIsCreature()) {
		_log(2, "o Error GetKnowsSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, sp_class = P1, sp_level = P3, sp_id = P2;
	int iIndex=0;
	CNWSCreature *cre = (CNWSCreature*)oObject;

	if (cre->cre_stats == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (sp_level > -1) {
			if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
					if (CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id) > -1) {
						sprintf(Params, "1");
						return 1;
					}
				}
			}
		}
		else { //loop all spell levels
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
						if (CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id) > -1) {
							sprintf(Params, "%d", sp_level+1);
							return 1;
						}
					}
				}
			}
		}
	}
	sprintf(Params, "-1");
	return 1;
}

int CNWNXFuncs::SetItemWeight() {
	if (!GetIsItem()) {
		_log(2, "o Error SetItemWeight used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	oObject = oObject-0x10;
	CNWSItem *Item = (CNWSItem*)oObject;
	
	Item->it_weight = P1;

	_log(3, "PossessorID: %08X\n", Item->it_container_obj);
	CNWSObject *Possessor = (CNWSObject*)(*NWN_AppManager)->app_server->GetGameObject(Item->it_container_obj);
	if (Possessor) {
		_log(3, "Possessor: %08X\n", Possessor->obj_generic.obj_type);
		if (Possessor->obj_generic.obj_type == OBJECT_TYPE_ITEM) {
			Possessor = (CNWSObject*)(*NWN_AppManager)->app_server->GetGameObject(((CNWSItem*)Possessor)->it_container_obj);
		}
		if (Possessor->obj_generic.obj_type == OBJECT_TYPE_CREATURE) {
			((CNWSCreature*)Possessor)->UpdateEncumbranceState(1);
		}
	}

	return 1;
}

int CNWNXFuncs::SetItemValue() {
	if (!GetIsItem()) {
		_log(2, "o Error SetItemValue used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	oObject = oObject-0x10;

	if (P1 < 0) P1 = 0;

	switch (P2) {
		case ITEM_VALUE_IDENTIFIED	: 
			((CNWSItem*)oObject)->it_cost_ided = P1; 
			if (P3) ((CNWSItem*)oObject)->it_cost_add = 0; 
		break;
		case ITEM_VALUE_UNIDENTIFIED: ((CNWSItem*)oObject)->it_cost_unided = P1; break;
		case ITEM_VALUE_ADDITIONAL	: ((CNWSItem*)oObject)->it_cost_add = P1; break;
	}

	return 1;
}

int CNWNXFuncs::SetItemCharges() {
	if (!GetIsItem()) {
		_log(2, "o Error SetItemCharges used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	oObject = oObject-0x10;

	if (P1 < 0) P1 = 0;
	if (P1 > 255) P1 = 255;

	((CNWSItem*)oObject)->it_charges = P1;

	return 1;
}

int CNWNXFuncs::GetItemValue() {
	sprintf(Params, "-1");
	if (!GetIsItem()) {
		_log(2, "o Error GetItemValue used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	oObject = oObject-0x10;

	switch (P1) {
		case ITEM_VALUE_IDENTIFIED: sprintf(Params, "%d", ((CNWSItem*)oObject)->it_cost_ided); break;
		case ITEM_VALUE_UNIDENTIFIED: sprintf(Params, "%d", ((CNWSItem*)oObject)->it_cost_unided); break;
		case ITEM_VALUE_ADDITIONAL	: sprintf(Params, "%d", ((CNWSItem*)oObject)->it_cost_add); break;
	}

	return 1;
}

int CNWNXFuncs::SetDomain() {
	if (!GetIsCreature()) {
		_log(2, "o Error SetDomain used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;
	if (P1 < 1 || P1 > 2) return 0;

	int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 2) {
            if (P1 == 1)
                cre->cre_stats->cs_classes[i].cl_domain_1 = P2;
            else
                cre->cre_stats->cs_classes[i].cl_domain_2 = P2;
            return 1;
        }
    } 

	return 1;
}

int CNWNXFuncs::GetDomain() {
	sprintf(Params, "-1");
	if (!GetIsCreature()) {
		_log(2, "o Error GetDomain used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;
	if (P1 < 1 || P1 > 2) {
		sprintf(Params, "-1");
		return 0;
	}

	int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 2) {
            if (P1 == 1)
                sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_domain_1);
            else
                sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_domain_2);
            return 1;
        }
    } 

	return 1;
}

int CNWNXFuncs::SetWizardSpecialization () {
	if (!GetIsCreature()) {
		_log(2, "o Error GetWizardSpecialization used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	if (P1 < 0 || P1 > 8) {
		sprintf(Params, "-1");
		return 0;
	}

    const CNWSCreature *cre = (CNWSCreature*)oObject;

    int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 10) {
            cre->cre_stats->cs_classes[i].cl_specialist = P1;
            break;
        }
    }

	return 1;
}

int CNWNXFuncs::GetWizardSpecialization () {
	sprintf(Params, "-1");

	if (!GetIsCreature()) {
		_log(2, "o Error GetWizardSpecialization used on non-creature object.\n");
		return 0;
	}

    const CNWSCreature *cre = (CNWSCreature*)oObject;

    int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 10) {
            sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_specialist);
            break;
        }
    }

	return 1;
} 

int CNWNXFuncs::ReplaceKnownSpell() {
	if (!GetIsCreature()) {
		_log(2, "o Error ReplaceKnownSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, sp_class = P1, sp_id=P2;
	int sp_level=0;
	int iIndex=0;
	CNWSCreature *cre = (CNWSCreature*)oObject;
	CNWSStats_Level *ls;

	if (cre->cre_stats == NULL || sp_level < 0 || sp_level > 9) {
		sprintf(Params, "-1");
		return 0;
	}

	//Classlist
	//loop through all classes to find the right one; then loop through the knownlist to find the spell
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
						if ((iIndex = CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id)) > -1) {
							_log(3, "ClassList: Spell %i found in class[%i] spell list[%i] at position %i.\n", sp_id, i, sp_level, iIndex);
							cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data[iIndex] = P3;
							_log(3, "ClassList: Spell Replaced\n");
						}
					}
				}
			}
		}
	}

	// LevelStatList
	// need to loop through all levels, through all spell levels
	int iCharacterLevel=0;
	sp_level=0;
	while ((ls = nwn_GetLevelStats(cre->cre_stats, ++iCharacterLevel)) != NULL) {
		if (ls->ls_class == sp_class) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (ls->ls_spells_known[sp_level].len > 0) {
					if ((iIndex = CExoArrayList_uint32_contains(&(ls->ls_spells_known[sp_level]), sp_id)) > -1) {
						_log(3, "LevelStatList: Spell %i found at Character Level %i; known list[%i].\n", sp_id, iCharacterLevel, sp_level);
						ls->ls_spells_known[sp_level].data[iIndex] = P3;
						_log(3, "LevelStatList: Spell Replaced\n");
					}
				}
			}
		}
	}
	return 1;
}

int CNWNXFuncs::GetRemainingSpellSlots() {
	sprintf(Params, "%d", 0);
	if (!GetIsCreature()) {
		_log(2, "o Error GetRemainingSpellSLots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, slots = 0;
    CNWSCreature *cre = (CNWSCreature*)oObject;

	if (P2 < 0 || P2 > 9) {
		sprintf(Params, "-1");
		return 0;
	}

    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_left[P2];
		sprintf(Params, "%d", slots);
        break;
    }
	return 1;
}

int CNWNXFuncs::SetRemainingSpellSlots() {
	if (!GetIsCreature()) {
		_log(2, "o Error SetRemainingSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i;//, sp_class = P1, sp_level=P2, sp_slots=P3;
    CNWSCreature *cre  = (CNWSCreature*)oObject;

	if (P2 < 0 || P2 > 9 || P3 < 0 || P3 > 99) {
		sprintf(Params, "-1");
		return 0;
	}

    /* iterate their class list, matching the requested class, then set the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

		if (P3 > cre->cre_stats->cs_classes[i].cl_spells_max[P2])
            P3 = cre->cre_stats->cs_classes[i].cl_spells_max[P2];

        cre->cre_stats->cs_classes[i].cl_spells_left[P2] = P3;
        break;
    }
	return 1;
}

int CNWNXFuncs::GetMaxSpellSlots () {
	sprintf(Params, "%d", 0);
 	if (!GetIsCreature()) {
		_log(2, "o Error GetMaxSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, slots;// sp_class=P1, sp_level=P2, slots = 0;
    CNWSCreature *cre   = (CNWSCreature*)oObject;

	if (P2 < 0 || P2 > 9) {
		sprintf(Params, "-1");
		return 0;
	}


    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_max[P2];

        if (slots == 0)
            slots = cre->cre_stats->cs_classes[i].cl_spells_mem[P2].len;

        break;
    }
    sprintf(Params, "%d", slots);

	return 1;
}


int CNWNXFuncs::GetBonusSpellSlots () {
	sprintf(Params, "%d", 0);
 	if (!GetIsCreature()) {
		_log(2, "o Error GetBonusSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

    int i, slots = 0;// sp_class=P1, sp_level=P2,
    CNWSCreature *cre   = (CNWSCreature*)oObject;

	if (P2 < 0 || P2 > 9) {
		sprintf(Params, "-1");
		return 0;
	}


    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_bonus[P2];
        break;
    }

    sprintf(Params, "%d", slots);

	return 1;
}

int CNWNXFuncs::GetMemorizedSpellSlot() {
	sprintf(Params, "%d", -1);

 	if (!GetIsCreature()) {
		_log(2, "o Error GetMemorizedSpellSlot used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

    CNWSCreature *cre = (CNWSCreature*)oObject;
    CNWSStats_Spell *sp;

	int i, ret = -1;//sp_class=P1, sp_levelP2, sp_idxP3, 

	if (P2 < 0 || P2 > 9) {
		sprintf(Params, "-1");
		return 0;
	}




    /* iterate their class list, matching the requested class, then iterate the spells
     * known list for that class */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

        if ((sp = (CNWSStats_Spell*)(CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[i].cl_spells_mem[P2]), P3))) == NULL)
            break;

        ret = (sp->sp_id & 0xFFFF) | ((sp->sp_meta & 0xFF) << 16) | (sp->sp_ready << 24);
    }

    sprintf(Params, "%d", ret);

	return 1;
}

int CNWNXFuncs::SetMemorizedSpell() {
 	if (!GetIsCreature()) {
		_log(2, "o Error SetMemorizedSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, sp_spell, sp_meta, sp_flags; //, P1=P1, P2=P2, P3=P3
    CNWSCreature *cre = (CNWSCreature*)oObject;
    CNWSStats_Spell *sp;

	sp_spell = P4 & 0xFFFF;
	sp_meta  = (P4 >> 16) & 0x7F;
	sp_flags = (P4 >> 24) & 1;

	if( P2 < 0 || P2 > 9 || P3 < 0) {
		sprintf(Params, "-1");
		return 0;
	}



    /* find the requested class, then alter the requested memorized spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

        if (P3 >= cre->cre_stats->cs_classes[i].cl_spells_mem[P2].len)
            break;

        if (sp_spell < 0) {
            if (cre->cre_stats->cs_classes[i].cl_spells_mem[P2].data[P3] != NULL)
                free(cre->cre_stats->cs_classes[i].cl_spells_mem[P2].data[P3]); 

            cre->cre_stats->cs_classes[i].cl_spells_mem[P2].data[P3] = NULL;
        } else {
            if ((sp = ((CNWSStats_Spell *)cre->cre_stats->cs_classes[i].cl_spells_mem[P2].data[P3])) == NULL) {
                if ((sp = ((CNWSStats_Spell *)calloc(1, sizeof(*sp)))) == NULL)
                    break;

                cre->cre_stats->cs_classes[i].cl_spells_mem[P2].data[P3] = sp;
            }

            sp->sp_id     = sp_spell;
            sp->sp_meta   = sp_meta;
            sp->sp_ready  = !!(sp_flags & 1);
            sp->sp_domain = !!(sp_flags & 2);
		}
        return 1;
    }

	return 1;
}

int CNWNXFuncs::RestoreMemorizedSpells () {
	sprintf(Params, "%d", 0);
 	if (!GetIsCreature()) {
		_log(2, "o Error RestoreMemorizedSpells used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	// P1 = class, P2 = starting spell level, P3 = ending level

	CNWSCreature *cre = (CNWSCreature*)oObject;
    CNWSStats_Spell *sp;
	int i,j,k;

	if (P2 < 0) P2 = 0; if (P2 > 9) P2 = 9;
	if (P3 < 0) P3 = 0; if (P3 > 9) P3 = 9;
	if (P3 < P2) P3 = P2;
	
	/* find the requested class, then alter the requested memorized spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

		for (j=P2; j<=P3; j++) {
			k=0;
			while (k < cre->cre_stats->cs_classes[i].cl_spells_mem[j].len) {
				sp = (CNWSStats_Spell*)(CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[i].cl_spells_mem[j]), k++));
				if (sp != NULL) sp->sp_ready = 1;
			}

		}
	}
	return 1;
} 

int CNWNXFuncs::GetFeatCount() {
	sprintf(Params, "d", 0);
 	if (!GetIsCreature()) {
		_log(2, "o Error GetFeatCount used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

    CNWSCreature *cre = (CNWSCreature*)oObject;

	sprintf(Params, "%d", cre->cre_stats->cs_feats.len);

	return 1;
}

int CNWNXFuncs::GetKnownSpellCount() {
	if (!GetIsCreature()) {
		_log(2, "o Error: GetKnownSpellCount used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;

	if (cre->cre_stats == NULL ||
	P2< 0 || P2 > 9) {
		sprintf(Params, "-1");
		return 0;
	}

	//number of spells for given spell level
	int nSpells=0, i;
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;
		
		if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
			sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_spells_known[P2].len);
		}
		break;
    }
	return 1;
}

int CNWNXFuncs::GetKnownSpells() {
	if (!GetIsCreature()) {
		_log(2, "o Error GetKnownSpells used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;

	int sp_class, sp_level;
	char sDelimiter[10];
	char sSpell[6]; //string representation of a single spell id (5 + '\n')

	//split Params up into class, spell level and delimiter
	// "1|10|,|            "
	sscanf(Params, "%d %d %s", &sp_class, &sp_level, sDelimiter);

	if (cre->cre_stats == NULL ||
	sp_level < 0 || sp_level > 9) {
		sprintf(Params, "-1");
		return 0;
	}

	//number of spells for given spell level
	int nSpells=0, i;
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;
		
		nSpells = cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len;
		break;
    } 


	// SSSSSDSSSSSDSSSSS\n
	unsigned int iSize = (nSpells*5+(nSpells-1)*strlen(sDelimiter))+1;

	if (iSize > strlen(Params)) {
		_log(2, "o Error (GetKnownSpells): Size of return string [%d] would be greater than spacer [%d].\n", iSize, strlen(Params));
		sprintf(Params, "-1");
		return 0;
	}
	sprintf(Params, "-1");

	int j;
    for (j = 0; j < cre->cre_stats->cs_classes_len; j++) {
        if (cre->cre_stats->cs_classes[j].cl_class != sp_class)
            continue;

		if ((cre->cre_stats->cs_classes[j].cl_spells_known != NULL) 
		&& (cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].len > 0)) {
			sprintf(Params, "%d", cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].data[0]);
			for (i=1; i < cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].len; i++) {
				Params = strcat(Params, sDelimiter);
				sprintf(sSpell, "%d", cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].data[i]);
				Params = strcat(Params, sSpell);
			}
		}
	}

	return 1;
}

int CNWNXFuncs::SetMaxSpellSlots () {
 	if (!GetIsCreature()) {
		_log(2, "o Error SetMaxSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i, slots;// sp_class=P1, sp_level=P2, slots = 0;
    CNWSCreature *cre   = (CNWSCreature*)oObject;

	if (P2 < 0 || P2 > 9) {
		sprintf(Params, "-1");
		return 0;
	}


    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != P1)
            continue;

        cre->cre_stats->cs_classes[i].cl_spells_max[P2] = P3;

        break;
    }

	return 1;
}

int CNWNXFuncs::SetConversation() {
	size_t len = strlen(Params);
	if (len > 16) len = 16;

	switch(((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE: memcpy_s(((CNWSCreature*)oObject)->cre_stats->cs_conv, len, Params, len); break;
		case OBJECT_TYPE_PLACEABLE: memcpy_s(((CNWSPlaceable*)oObject)->plc_conv, len, Params, len); break;
		default :
			sprintf(Params, "-1");
			return 0;
		break;
	}
	
	return 1;
}

int CNWNXFuncs::GetConversation() {
    size_t len = strlen(Params);
	if (len > 16) len = 16;

	switch(((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE: 
			memcpy(Params, ((CNWSCreature*)oObject)->cre_stats->cs_conv, len); 
		break;
		case OBJECT_TYPE_PLACEABLE: memcpy(Params, ((CNWSPlaceable*)oObject)->plc_conv, len); break;
		default : 
			sprintf(Params, "-1");
			return 0;
		break;
	}

	Params[len] = 0;

	return 1;
}

int CNWNXFuncs::GetAllEffectRemainingDuration() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}
    uint32_t tD, tT, eD, eT;
	int64_t current, expire;

	(*NWN_AppManager)->app_server->srv_internal->srv_time_world->GetWorldTime(&tD, &tT);
	current = (tD * 2880000LL) + tT;

	eD = getFirstNextEffect->eff_expire_day;
	eT = getFirstNextEffect->eff_expire_time;
	expire = (eD * 2880000LL) + eT;

	_log(3, "[tD: %ld | tT: %ld] current: %ld\n", tD, tT, current);
	_log(3, "[eD: %ld | eT: %ld] expire: %ld\n", eD, eT, expire);
 
	sprintf(Params, "%.2lf", (float)(expire - current)/1000.0);
	return 1;
}

int CNWNXFuncs::SetBodyBag() {
	if (P1 < 0) P1 = 0;
	if (P1 > 255) P1 = 255;
	switch(((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE: ((CNWSCreature*)oObject)->cre_bodybag = P1; break;
		case OBJECT_TYPE_PLACEABLE: ((CNWSPlaceable*)oObject)->plc_bodybag = P1; break;
		default:
			sprintf(Params, "-1");
			_log(2, "o Error (SetBodyBag): Could not set bodybag type for given object type.\n");
		break;
	}
	return 1;
}

int CNWNXFuncs::GetBodyBag() {
	sprintf(Params, "-1");
	switch(((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE: sprintf(Params, "%d", ((CNWSCreature*)oObject)->cre_bodybag);
		case OBJECT_TYPE_PLACEABLE: sprintf(Params, "%d", ((CNWSPlaceable*)oObject)->plc_bodybag);
		default: 
			sprintf(Params, "-1");
			_log(2, "o Error (GetBodyBag): Could not get bodybag type for given object type.\n");
		break;
	}
	return 1;
}

int CNWNXFuncs::GetFeatsGainedAtLevel() {
	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CNWSStats_Level *ls;
		
	if ((ls = nwn_GetLevelStats(Stats, P1)) == NULL) {
		_log(2, "o Error (GetFeatsGainedAtLevel): Could not get stats for given level(%d).\n", P1);
		sprintf(Params, "-1");
		return 0;
	}
	CExoArrayList_uint16 *Feats = &ls->ls_featlist;
	int32_t len = Feats->len;
	if (len > 0) {
		std::string sFeats;
		sFeats.reserve(len*6);
		char feat[6];
		
		sprintf(feat, "%d", Feats->data[0]);
		sFeats += feat;
		int i=0;
		while (++i < len) {
			sFeats += "|";
			sprintf(feat, "%d", Feats->data[i]);
			sFeats += feat;
		}

		sprintf(Params, "%s", sFeats.c_str());
	}
	else {
		sprintf(Params, "");
	}
	return 1;
}

int CNWNXFuncs::GetSkillRanksGainedAtLevel() {
	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CNWSStats_Level *ls;
		
	if ((ls = nwn_GetLevelStats(Stats, P1)) == NULL) {
		_log(2, "o Error (GetSkillRanksGainedAtLevel): Could not get stats for given level(%d).\n", P1);
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t *skills = ls->ls_skilllist;
	int i=0;
	char skill[4];
	std::string sSkills; sSkills.reserve(nSkill*4);

	sprintf(skill, "%d", skills[0]);
	sSkills += skill;
	for (i=1; i<nSkill; i++) {
		sSkills += "|";
		sprintf(skill, "%d", skills[i]);
		sSkills += skill;
	}

	sprintf(Params, "%s", sSkills.c_str());

	return 1;
}

int CNWNXFuncs::GetSpellsGainedAtLevel() {
	sprintf(Params, "");

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CNWSStats_Level *ls;
		
	if ((ls = nwn_GetLevelStats(Stats, P1)) == NULL) {
		_log(2, "o Error (GetSpellsGainedAtLevel): Could not get stats for given level(%d).\n", P1);
		sprintf(Params, "-1");
		return 0;
	}

	CExoArrayList_uint32 *ls_spells_known = &ls->ls_spells_known[P2];
	int32_t len = ls_spells_known->len;

	if (len > 0) {
		int i=0;
		char spell[6];
		std::string sSpells; sSpells.reserve(nSkill*4);

		sprintf(spell, "%d", ls_spells_known->data[0]);
		sSpells += spell;
		for (i=1; i<len; i++) {
			sSpells += "|";
			sprintf(spell, "%d", ls_spells_known->data[i]);
			sSpells += spell;
		}
		sprintf(Params, "%s", sSpells.c_str());
	}
	
	return 1;
}

int CNWNXFuncs::GetStatsGainedAtLevel() {
	sprintf(Params, "");

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CNWSStats_Level *ls;
		
	if ((ls = nwn_GetLevelStats(Stats, P1)) == NULL) {
		_log(2, "o Error (GetSpellsGainedAtLevel): Could not get stats for given level(%d).\n", P1);
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d|%d|%d|%d", ls->ls_ability, ls->ls_class, ls->ls_hp, ls->ls_skillpoints); 

	return 1;
}

int CNWNXFuncs::GetQuickSlot() {
    int slot = P1;
    const CNWSCreature *cre = (CNWSCreature*)oObject;

    if (oObject == NULL                               ||
        !GetIsCreature()							  ||
        !cre->cre_is_pc                               ||
        cre->cre_quickbar == NULL                     ||
        (slot < 0 || slot >= 36)) {

        sprintf(Params, "-1");
        return 0;
    }

	if (cre->cre_quickbar[slot].qb_type == 1) { // can't do items
		sprintf(Params, "-1");
		return 0;
	}

	switch(cre->cre_quickbar[slot].qb_type) {
		case 18: {
			sprintf_s(Params, strlen(Params), "%d¬%d¬0¬0¬0¬%s¬%s", 
				slot,
				cre->cre_quickbar[slot].qb_type,
				cre->cre_quickbar[slot].qb_label.text,
				cre->cre_quickbar[slot].qb_command.text
			);
		} break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: {//dm creator stuff
			sprintf_s(Params, strlen(Params), "%d¬%d¬0¬0¬0¬%s¬%s", 
				slot,
				cre->cre_quickbar[slot].qb_type,
				cre->cre_quickbar[slot].qb_label2.text,
				cre->cre_quickbar[slot].qb_resref
			);
		} break;
		default: {
			sprintf_s(Params, strlen(Params), "%d¬%d¬%d¬%d¬%d", 
				slot,
				cre->cre_quickbar[slot].qb_type,
				cre->cre_quickbar[slot].qb_class,
				cre->cre_quickbar[slot].qb_id,
				cre->cre_quickbar[slot].qb_metamagic
			);
		}break;
	}

	return 1;
}

int CNWNXFuncs::SetQuickSlot () {
    int slot, qb_type, qb_class, qb_id, qb_meta, bUpdate;
    CNWSCreature *cre = (CNWSCreature*)oObject;
	std::string s = Params;
	int iP;

    if (oObject == NULL                               ||
        !GetIsCreature()							  ||
        !cre->cre_is_pc                               ||
        cre->cre_quickbar == NULL)
        //sscanf(Params, "%d %d %d %d %d %d¬%s¬%s", &slot, &qb_type, &qb_class, &qb_id, &qb_meta, &bUpdate) != 6 ||
    {

        sprintf_s(Params, strlen(Params), "-1");
        return 0;
    }

	iP = s.find("¬");

	if (iP == -1) {
		if ((sscanf((s.c_str()), "%d %d %d %d %d %d", &slot, &qb_type, &qb_class, &qb_id, &qb_meta, &bUpdate) != 6)
			|| slot < 0 || slot >= 36) {
			sprintf(Params, "-2");
			return 0;
		}
	}
	else {
		if ((sscanf((s.substr(0, iP).c_str()), "%d %d %d %d %d %d", &slot, &qb_type, &qb_class, &qb_id, &qb_meta, &bUpdate) != 6)
			|| slot < 0 || slot >= 36) {
			sprintf(Params, "-2");
			return 0;
		}
	}

	if (qb_type == 1) { // can't do items
		sprintf(Params, "-1");
		return 0;
	}

	std::string s2;
	if (iP > 0) {
		s2 = s.substr(iP+1);
		s = s2.substr(s2.find("¬")+1);
		s2 = s2.substr(0, s2.find("¬"));
	}
	else {
		s = "";
		s2 = "";
	}

	CNWSQuickbarButton *button = &cre->cre_quickbar[slot];

	//if quickslot contains strings, free their memory first
	switch (button->qb_type) {
		case 18: {
			free(button->qb_label.text); button->qb_label.text = NULL;
			button->qb_label.len = 0;
			free(button->qb_command.text); button->qb_command.text = NULL;
			button->qb_command.len = 0;
		} break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: {//dm creator stuff
			free(button->qb_label2.text); button->qb_label2.text = NULL;
			button->qb_label2.len = 0;
		} break;
	}

	// put the new data in
	switch (qb_type) {
		case 18: {
			if (s.length() > 0 && s2.length() > 0) {
				button->qb_label.len = s2.length()+1;
				button->qb_label.text = (char*)malloc(button->qb_label.len);
				sprintf_s(button->qb_label.text, button->qb_label.len, "%s", s2.c_str());
				
				button->qb_command.len = s.length()+1;
				button->qb_command.text = (char*)malloc(button->qb_command.len);
				sprintf_s(button->qb_command.text, button->qb_command.len, "%s", s.c_str());
			}
			else {
				qb_type = 0;
				qb_class = 0;
				qb_id = 0;
				qb_meta = 0;
			}
		} break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: {//dm creator stuff
			if (s.length() > 0 && s2.length() > 0) {
				button->qb_label2.len = s2.length()+1;
				button->qb_label2.text = (char*)malloc(button->qb_label2.len);
				sprintf_s(button->qb_label2.text, button->qb_label2.len, "%s", s2.c_str());

				int i=0;
				s = s.substr(0,16);
				sprintf_s(button->qb_resref, "%s", s.c_str());
			}
			else {
				qb_type = 0;
				qb_class = 0;
				qb_id = 0;
				qb_meta = 0;
			}
		} break;
	}

	qb_class--;
	qb_class = qb_class < 0 ? 0 : qb_class > 2 ? 2 : qb_class;
	button->qb_type      = qb_type;
	button->qb_class     = qb_class;
	button->qb_id        = qb_id;
	button->qb_metamagic = qb_meta;

	if (bUpdate) nwn_UpdateQuickBar((CGenericObject*)oObject);

	return 1;
}

	int CNWNXFuncs::UpdateQuickbar() {
	if (!GetIsCreature()) {
		_log(2, "o Error: UpdateQuickbar used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	nwn_UpdateQuickBar((CGenericObject*)oObject);
	return 1;
}

int CNWNXFuncs::SetClassByPosition() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetClassByPosition used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;

	if (cre == NULL ||
		cre->cre_stats->cs_classes == NULL
		) {
			sprintf_s(Params, sizeof(Params), "-1");
			return 0;
	}

	cre->cre_stats->cs_classes[P1-1].cl_class = P2;

	return 1;
}

int CNWNXFuncs::SetGender() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetGender used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	CNWSCreature* cre = (CNWSCreature*)oObject;
	cre->cre_stats->cs_gender = P1;
	return 1;
}

int CNWNXFuncs::GetWorldTime() {
	uint32_t wtDate, wtTime;

	(*NWN_AppManager)->app_server->srv_internal->srv_time_world->GetWorldTime(&wtDate, &wtTime);

	//return time only
	if (P1 == 0) sprintf_s(Params, strlen(Params), "%ld", wtTime);
	else sprintf_s(Params, strlen(Params), "%ld", wtDate);

	return 1;
}

int CNWNXFuncs::GetFactionID() {
	sprintf(Params, "-1");
	if (!GetIsCreature()) {
		_log(2, "o Error: GetFactionID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int iFactionID = ((CNWSCreature*)oObject)->cre_stats->cs_faction_id;
	sprintf(Params, "%d", iFactionID);

	return 1;
}

int CNWNXFuncs::SetFactionID() {
	if (!GetIsCreature()) {
		sprintf(Params, "");
		_log(2, "o Error: SetFactionID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->cre_stats->cs_faction_id = P1;

	return 1;
}

int CNWNXFuncs::GetSoundSetID() {
		sprintf(Params, "-1");
	if (!GetIsCreature()) {
		_log(2, "o Error: GetSoundSetID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int iSoundSetID = ((CNWSCreature*)oObject)->cre_soundset;
	sprintf(Params, "%d", iSoundSetID);

	return 1;
}

int CNWNXFuncs::SetSoundSetID() {
	if (!GetIsCreature()) {
		sprintf(Params, "");
		_log(2, "o Error: SetSoundSetID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->cre_soundset = P1;

	return 1;
}

int CNWNXFuncs::GetSavingThrowBonus() {
	sprintf(Params, "-1");
	if (!GetIsCreature()) {
		_log(2, "o Error: GetSavingThrowBonus used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	switch(P1) {
		case 1: sprintf(Params, "%d", ((CNWSCreature*)oObject)->cre_stats->cs_save_fort);
		case 2: sprintf(Params, "%d", ((CNWSCreature*)oObject)->cre_stats->cs_save_reflex);
		case 3: sprintf(Params, "%d", ((CNWSCreature*)oObject)->cre_stats->cs_save_will);
		default:
			sprintf(Params, "-1");
			_log(2, "o Error: GetSavingThrowBonus: Invalid Saving Throw type.\n");
		break;

	}

	return 1 ;
}

int CNWNXFuncs::JumpToLimbo() {
	sprintf(Params, "");
	if (!GetIsCreature()) {
		_log(2, "o Error: JumpToLimbo used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	nwn_JumpCreatureToLimbo((CNWSCreature*)oObject);
	return 1;
}

int CNWNXFuncs::SetClassLevel() {
 	if (!GetIsCreature()) {
		_log(2, "o Error SetClassLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	
	int i;// class=P1, level=P2
    CNWSCreature *cre   = (CNWSCreature*)oObject;
	if (cre->cre_is_pc) {
		sprintf(Params, "-1");
		return 0;
	}

	if (P1 < 1 || P1 > 3 || P2 < 1 || P2 > 60) {
		sprintf(Params, "-1");
		return 0;
	}

	P1--;

	if (P1 < cre->cre_stats->cs_classes_len)
		cre->cre_stats->cs_classes[P1].cl_level = P2;

	return 1;
}

int CNWNXFuncs::GetDamageImmunity() {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (!obj ||
		(obj->obj_generic.obj_type2 != 5 && obj->obj_generic.obj_type2 != 8 && obj->obj_generic.obj_type2 != 10)
	) {
		_log(2, "o Error GetDamageImmunity used on invalid object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", ((CNWSObject*)oObject)->GetDamageImmunityByFlags(P1));
	return 1;
}

int CNWNXFuncs::GetAllEffectInts() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	if (getFirstNextEffect->eff_num_integers < 0) {
		sprintf(Params, "");
		return 0;
	}
	else {
		if (P1 == -1) {
			char buf[11];
			size_t size = (11*getFirstNextEffect->eff_num_integers)+1;
			char *ints = new char[size];
			memset(ints, 0, size);

			for(int i=0; i<getFirstNextEffect->eff_num_integers; i++) {
				sprintf(buf, "%d¬", getFirstNextEffect->eff_integers[i]);
				strcat(ints, buf);
			}

			if (strlen(ints) > 0) {
				sprintf(Params, "%s", ints);
				delete[] ints;
			}
			else {
				sprintf(Params, "");
				delete[] ints;
			}
		}
		else {
			if (P1 < getFirstNextEffect->eff_num_integers) {
				sprintf(Params, "%d", getFirstNextEffect->eff_integers[P1]);
			}
			else {
				sprintf(Params, "");
			}
		}
	}
	return 1;
}

int CNWNXFuncs::SetAllEffectInts() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	if (getFirstNextEffect->eff_num_integers < 0 || P1 > getFirstNextEffect->eff_num_integers) {
		sprintf(Params, "-1");
	}
	else {
		getFirstNextEffect->eff_integers[P1] = P2;
		sprintf(Params, "1");
	}

	return 1;
}

int CNWNXFuncs::GetFirstAllEffect() {
	CNWSObject *obj = (CNWSObject*)oObject;

	if (!ValidEffectObject()) {
		_log(2, "o Error: GetEffectRemainingDuration used on non-effect object.\n");
		sprintf(Params, "-1");
		getFirstNextEffectObj = OBJECT_INVALID;
		getFirstNextEffectObject = NULL;
		return 0;
	}

	getFirstNextEffectScriptEffect = (bool)P1;
	getFirstNextEffectObj = obj->obj_generic.obj_id;
	getFirstNextEffect = NULL;
	getFirstNextEffectObject = obj;
	EffectRemovalIDs.clear();

	uint16_t durType, subType;
	BOOL bIsExposed;
	unsigned int i=0;
	for (i=0; i< obj->obj_effects_len; i++) {
		getFirstNextEffect = obj->obj_effects[i];
		if (getFirstNextEffect != NULL) {
			durType = getFirstNextEffect->eff_dursubtype & 7;
			subType = getFirstNextEffect->eff_dursubtype & 24;
			bIsExposed = getFirstNextEffect->eff_is_exposed && (durType == 1 || durType == 2);
			if ((!getFirstNextEffectScriptEffect || bIsExposed)) {
				getFirstNextEffectScriptIndex = i;
				sprintf(Params, "1");
				return 1;
			}
		}
	}
	sprintf(Params, "0");
	getFirstNextEffect = NULL;
	getFirstNextEffectScriptIndex = -1;
	getFirstNextEffectObject = NULL;

	return 1;
}

int CNWNXFuncs::GetNextAllEffect() {
	if (getFirstNextEffectObject != NULL) {
		unsigned int i = getFirstNextEffectScriptIndex;
		while(++i < getFirstNextEffectObject->obj_effects_len) {
			getFirstNextEffect = getFirstNextEffectObject->obj_effects[i];
			if (getFirstNextEffect != NULL) {
				if ((!getFirstNextEffectScriptEffect || getFirstNextEffect->eff_is_exposed && ((getFirstNextEffect->eff_dursubtype & 7) == 1 || (getFirstNextEffect->eff_dursubtype & 24) == 2))) {
					getFirstNextEffectScriptIndex = i;
					sprintf(Params, "1");
					return 1;
				}
			}
		}
	}

	sprintf(Params, "0");
	getFirstNextEffect = NULL;
	getFirstNextEffectObject = NULL;
	return 1;
}

int CNWNXFuncs::GetHighestEffectID() {
	const CNWSObject *obj = NULL;
	obj = (CNWSObject*)oObject;

	if (!ValidEffectObject()) {
		_log(2, "o Error: GetEffectRemainingDuration used on non-effect object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	// since the effect array is sorted by effect type we have to go through it and find the highest id

	long iID = 1;
	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		if ((signed long)obj->obj_effects[i]->eff_id > iID) {
			iID = obj->obj_effects[i]->eff_id;
		}
	}

	sprintf(Params, "%d", iID);
	return 1;
}

int CNWNXFuncs::GetAllEffectID() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	int iID = getFirstNextEffect->eff_id;
	sprintf(Params, "%d", iID);

	return 1;
}

int CNWNXFuncs::SetEffectCreatorByEffectID(int bRecurse) {
	int bHasteSlow = 0;
	const CNWSObject *obj = NULL;
	obj = (CNWSObject*)oObject;

	// need to rescan Params since the creator id is in hex format
	if (!ValidEffectObject()) {
		_log(2, "o Error: SetEffectCreatorByEffectID used on non-effect object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	if (bRecurse) { //already scanned them last iteration
		if (sscanf(Params, "%d %08X", &P1, &P2) != 2) return 0;
	}

	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		if (obj->obj_effects[i]->eff_id == P1) {
			obj->obj_effects[i]->eff_creator = P2;
			if (obj->obj_effects[i]->eff_type == 41) { //internal Haste: need to change the ID-1 too
				bHasteSlow = -1;
			}
			if (obj->obj_effects[i]->eff_type == 41) { //Haste: need to change the ID+1 too
				bHasteSlow = 1;
			}
		}
	}

	if (bHasteSlow && bRecurse) {
		P1 += bHasteSlow;
		SetEffectSpellIDByEffectID(bRecurse-1);
	}

	return 1;
}

int CNWNXFuncs::SetEffectSpellIDByEffectID(int bRecurse) {
	int bHasteSlow = 0;
	const CNWSObject *obj = NULL;
	obj = (CNWSObject*)oObject;

	if (!ValidEffectObject()) {
		_log(2, "o Error: SetSpellIDByEffectCreator used on non-effect object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		if (obj->obj_effects[i]->eff_id == P1) {
			obj->obj_effects[i]->eff_spellid = P2;
			if (obj->obj_effects[i]->eff_type == 41) { //internal Haste: need to change the ID-1 too
				bHasteSlow = -1;
			}
			if (obj->obj_effects[i]->eff_type == 1) { //Haste: need to change the ID+1 too
				bHasteSlow = 1;
			}
		}
	}

	if (bHasteSlow && bRecurse) {
		P1 += bHasteSlow;
		SetEffectSpellIDByEffectID(bRecurse-1);
	}

	return 1;
}

int CNWNXFuncs::GetAllEffectType() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}


	int iType;
	if (!P1) {
		iType = getFirstNextEffect->GetScriptEffectType();
	}
	else {
		iType = getFirstNextEffect->eff_type;
	}
	sprintf(Params, "%d", iType);
	return 1;
}

int CNWNXFuncs::GetAllEffectSubType() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", (getFirstNextEffect->eff_dursubtype & 24));
	return 1;
}

int CNWNXFuncs::GetAllEffectSpellID() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", getFirstNextEffect->eff_spellid);
	return 1;
}

int CNWNXFuncs::GetAllEffectCreator() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%08X", getFirstNextEffect->eff_creator);
	return 1;
}

int CNWNXFuncs::GetAllEffectDurationType() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", (getFirstNextEffect->eff_dursubtype & 7));
	return 1;
}

int CNWNXFuncs::QueueRemoveEffect() {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	EffectRemovalIDs.push_back(getFirstNextEffect->eff_id);
	// Haste and Slow are a problem as they create internal versions which have all the other effects (Movement Speed,
	// AC, etc) linked to them. The ID for those seems to be 1 higher
	// I hope this holds true in all cases

	if (getFirstNextEffect->eff_type == 1 || getFirstNextEffect->eff_type == 3) {
		EffectRemovalIDs.push_back(getFirstNextEffect->eff_id+1);
	}

	return 1;
}

int CNWNXFuncs::RemoveQueuedEffects() {
	uint64_t iID;

	while (!EffectRemovalIDs.empty()) {
		iID = EffectRemovalIDs.back();
		((CNWSObject*)oObject)->RemoveEffectById(iID);
		EffectRemovalIDs.pop_back();
	}
	return 1;
}

int CNWNXFuncs::ApplyVFXForPC() {
	CNWSObject *obj = (CNWSObject*)oObject;
	
	if (obj == NULL || !GetIsCreature() || !((CNWSCreature*)obj)->cre_is_pc) {
		_log(2, "o Error: ApplyVFXForPC used on invalid object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	nwn_objid_t plID = obj->obj_generic.obj_id;

	int nVFX=0;
	float Px=0.0, Py=0.0, Pz=0.0;
	//rescan Params for vfx and position floats
	if (sscanf(Params, "%d %f %f %f", &nVFX, &Px, &Py, &Pz) != 4) {
		_log(2, "o Error ApplyVFXForPC: Not enough Parameters [%s]\n", Params);
		sprintf(Params, "-1");
		return 0;
	}

	CNWSPlayer *pPlayer = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(plID);
	
	if(((CNWSObject*)(pPlayer->GetGameObject()))->GetArea() != NULL) {
		CNWSMessage *pServerMessage = ((*NWN_AppManager)->app_server)->GetNWSMessage();
		return pServerMessage->SendServerToPlayerArea_VisualEffect(pPlayer, nVFX, Px, Py, Pz);
	}
	return 0;
}

int CNWNXFuncs::GetEffectInts() {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		GetAllEffectInts();
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNWNXFuncs::SetEffectInt() {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		SetAllEffectInts();
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNWNXFuncs::GetEffectRemainingDuration() {
	CNWSObject *obj = (CNWSObject*)oObject;
	_log(3, "index: %08X\n", obj->obj_effect_index);
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		_log(3, "getFirstNextEffect: %08X\n", getFirstNextEffect);
		GetAllEffectRemainingDuration();
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNWNXFuncs::GetEffectID() {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		GetAllEffectID();
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNWNXFuncs::GetEffectRealType() {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		P1 = 1;
		GetAllEffectType();
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNWNXFuncs::SetCustomGeometry() {
	std::string floats = Params, sTemp;

	int iStart = 0;
	int iP = floats.find("¬", iStart);
	float f;

	if (iP != std::string::npos) {
		sTemp = floats.substr(iStart, iP-iStart);
		sscanf(sTemp.c_str(), "%d", &AbsoluteCoordinates);
		
		iStart = iP+1; iP = floats.find("¬", iStart);

		Floats.clear();
		while (iP != std::string::npos) {
			sTemp = floats.substr(iStart, iP-iStart); iStart = iP+1; iP = floats.find("¬", iStart);
			sscanf(sTemp.c_str(), "%f", &f);
			Floats.push_back(f);
		}

		if (Floats.size() < 4 || (Floats.size() % 2) != 0) {
			_log(2, "o Error: invalid number of coordinates\n");
			Floats.clear();
			CustomTriggerGeometry = 0;
			sprintf(Params, "-1");
			return 0;
		}
		else {
			CustomTriggerGeometry = 1;
			_log(3, "coordinates valid\n");
		}
	}
	else {
		_log(2, "o Error: Invalid number of coordinates\n");
		Floats.clear();
		CustomTriggerGeometry = 0;
		return 0;
	}

	return 1;
}

int CNWNXFuncs::RotateCustomGeometry() {
	float fAngle = 0.0;

	if ((sscanf(Params, "%f", &fAngle) != 1)
		||Floats.empty()) {
			sprintf(Params, "-1");
			return 0;
	}

	std::list<float> rotate;
	std::list<float>::iterator it;

	float fx, fy, fx_n, fy_n, sini, cosi;
	for (it=Floats.begin(); it != Floats.end(); it++) {
		fx = *it;
		it++;
		fy = *it;

		sini = sin(fAngle*0.0174532925199);
		cosi = cos(fAngle*0.0174532925199);
		fx_n = fx * cosi + fy * sini;
		fy_n = -(fx * sini) + fy * cosi;
		rotate.push_back(fx_n);
		rotate.push_back(fy_n);
	}

	Floats.clear();
	Floats = rotate;

	return 1;
}

int CNWNXFuncs::GetTriggerGeometry() {
	CNWSTrigger *Trigger = (CNWSTrigger*)oObject;
	sprintf(Params, "");

	if (!Trigger || Trigger->obj.obj_generic.obj_type2 != 7) {
		_log(3, "o Error: GetTriggerGeometry used on non Trigger object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	char c[40];
	int Verts = Trigger->VerticesCount;
	_log(3, "Verts: %d\n", Verts);

	std::string sReturn;

	Vector *v;
	if (Verts > 0) {
		for (int i=0; i<Verts; i++) {
			v = &Trigger->geometry_vectors[i];
			sprintf(c, "%.3f", v->x); sReturn += c; sReturn += "¬";
			sprintf(c, "%.3f", v->y); sReturn += c; sReturn += "¬";
		}
		sprintf(Params, "%s", sReturn.c_str());
	}
return 1;
}

int CNWNXFuncs::GetSurfaceMaterial() {
	int Result = -1;
	uint32_t oID=0;
	float x=0.0,y=0.0,z=0.0;

	sscanf(Params, "%f %f %f", &x, &y, &z);
	sprintf(Params, "-1");

	CNWSArea *Area = (CNWSArea*)(oObject-0xC4);
	if (Area) {
		CNWTile *Tile = Area->GetTile(x, y, (int)z);
		if (Tile) {
			int Tile_x=0, Tile_y=0;
			((CNWTile*)Tile)->GetLocation(&Tile_x, &Tile_y);
			x = x - (long double)Tile_x * 10.0;
			y = y - (long double)Tile_y * 10.0;
			
			Result = ((CNWSTile*)Tile)->GetSurfaceMaterial(x, y, z);
		}
		else _log(3, "Tile invalid\n");
	}
	else _log(3, "Area invalid\n");

	sprintf(Params, "%d", Result);

	return 1;
}

int CNWNXFuncs::TimebarStart() {
	if (!GetIsCreature()) {
		_log(2, "o Error: TimebarStart used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->StartGuiTimingBar(P1, P2);

	return 1;
}

int CNWNXFuncs::TimebarStop() {
	if (!GetIsCreature()) {
		_log(2, "o Error: TimebarStop used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->StopGuiTimingBar();
	return 1;
}

int CNWNXFuncs::SetAge() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetAge used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->cre_stats->cs_age = P1;
	sprintf(Params, "1");

	return 1;
}

int CNWNXFuncs::ModifyItem() {
	CNWSItem *Item = ((*NWN_AppManager)->app_server->srv_internal)->GetItemByGameObjectID(((CGenericObject*)oObject)->obj_id);
	if (Item) {
		Item->ModelPart1 = 1;
	}
	return 1;
}

int CNWNXFuncs::ClearTURDList() {
	CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	
	CNWSPlayerTURD *TURD = NULL;
	
	CExoLinkedListElement *Element = Mod->mod_PlayerTURDList.GetHeadPos();
	while (Element) {
		TURD = (CNWSPlayerTURD*)Element->Data;
		Mod->mod_PlayerTURDList.Remove(Element);

		TURD->ScalarDestructor(1);

		Element = Mod->mod_PlayerTURDList.GetHeadPos();
	}


	return 1;
}

int CNWNXFuncs::PossessCreature() {
	CNWSCreature *Possessor = (CNWSCreature*)oObject;
	int oID_Possessee = 0;
	sscanf(Params, "%x", &oID_Possessee);

	_log(3, "Possessor: %08X\tPossessee: %08X\n", Possessor->obj.obj_generic.obj_id, oID_Possessee);
	Possessor->PossessCreature(oID_Possessee);
	return 1;
}

int CNWNXFuncs::SetClassByLevel() {
	if (!GetIsCreature()) {
		_log(2, "o Error: SetClassByLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;
	CNWSStats_Level *ls = nwn_GetLevelStats(cre->cre_stats, P1);

	if (!ls) {
		sprintf(Params, "-1");
		return 0;
	}

	ls->ls_class = P2;
	
	return 1;
}

int CNWNXFuncs::ReplaceClass() {
	if (!GetIsCreature()) {
		_log(2, "o Error: ReplaceClass used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreature *cre = (CNWSCreature*)oObject;
	CNWSStats_Level *ls;
	int i=0;

	while (i < cre->cre_stats->cs_levelstat.len) {
		ls = (CNWSStats_Level*)cre->cre_stats->cs_levelstat.data[i];
		if (ls->ls_class == P1) ls->ls_class = P2;
		i++;
	}

	for (i=0; i<cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class == P1) {
			cre->cre_stats->cs_classes[i].cl_class = P2;
			break;
		}
	}

	return 1;
}

int CNWNXFuncs::UpdateCharSheet() {
	uint32_t player_id = 0;
	sscanf(Params, "%x", &player_id);
	CNWSPlayer *Player = (*NWN_AppManager)->app_server->GetClientObjectByObjectId(player_id);

	if (Player != NULL) {
		CNWSPlayerCharSheetGUI *CharSheet = (CNWSPlayerCharSheetGUI*)(((char*)Player)+0x60);
		uint32_t msg = CharSheet->ComputeCharacterSheetUpdateRequired(Player);
		if (msg) {
			((*NWN_AppManager)->app_server->srv_internal->srv_client_messages)->WriteGameObjUpdate_CharacterSheet(Player, msg);
		}
	}
	return 1;
}

int CNWNXFuncs::SummonAssociate() {
	uint16_t Type=0;
	char Name[250];
	char ResRef[16];

	if (sscanf(Params, "%s %s %d", ResRef, Name, &Type) != 3) {
		sprintf(Params, "-1");
		return -1;
	}

	CResRef sResRef;
	strcpy(sResRef.resref, ResRef);
	CExoString sName(Name);
	_log(3, "ResRef: %s\tName: %s\tType %d\n", sResRef.resref, sName.text, Type);
	((CNWSCreature*)oObject)->SummonAssociate(sResRef, sName, Type);

	return 1;
}

int CNWNXFuncs::GetEffectDurationSubType() {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}

	getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];

	int iSubType = getFirstNextEffect->eff_dursubtype;

	getFirstNextEffect = NULL;
	sprintf(Params, "%d", iSubType);
	return 1;
}

int CNWNXFuncs::BootPCWithMessage() {
	int iMsg = 0;
	sscanf(Params, "%d", &iMsg);
	CNWSObject *obj = (CNWSObject*)oObject;
	nwn_objid_t plID = obj->obj_generic.obj_id;
	CNWSPlayer* pPlayer = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(plID);
	if(pPlayer != NULL)
	{
		uint32_t pID = pPlayer->pl_id;
		CNetLayer* netlayer = (*NWN_AppManager)->app_server->srv_internal->srv_network;

		netlayer->DisconnectPlayer(pID, iMsg, 1);
		return 1;
	}
	return 0; 
}

int CNWNXFuncs::GetItemPropertyInformation() {
	CExoString varname = CExoString("NWNX_FUNCS_IPRP");
	char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	CNWSModule *Mod = ((CNWSModule*)(mod+=0x1C));
	CExoString *Params = NULL;
	int iprp=0, P2=0, P3=0;

	Params = Mod->mod_vartable.GetString(varname);
	if (Params) {
		if (sscanf(Params->text, "%d %d %d", &iprp, &P2, &P3) == 3) {
			int Ret = 0;
			CGameEffect *eff = NULL;
			CNWSItemProperty *ip = NULL;
			void *temp;
			if ((*NWN_VirtualMachine)->StackPopEngineStructure(4, &temp)) {
				int iPush = -1;
				if (temp != NULL) {
					eff = (CGameEffect*)temp;
					uint32_t tD, tT, eD, eT;
					int64_t current, expire;
					float fRemaining = 0.0;
					switch (iprp) {
						case 1: Mod->mod_vartable.SetFloat(varname, eff->eff_duration); iPush = 1; break;
						case 2: iPush = eff->eff_spellid; break;
						case 3:	if (eff->eff_integers[P2] != NULL) {iPush = eff->GetInteger(P2); } break;
						case 4:
							if (eff->eff_integers[P2] != NULL) {
								eff->eff_integers[P2] = P3; iPush = 1; 
							}
						break;
						case 5: eff->eff_spellid = P2; iPush = 1; break;
						case 6: 
							if (eff->eff_duration != 0.0) {
								(*NWN_AppManager)->app_server->srv_internal->srv_time_world->GetWorldTime(&tD, &tT);
								current = (tD * 2880000LL) + tT;

								eD = eff->eff_expire_day;
								eT = eff->eff_expire_time;
								expire = (eD * 2880000LL) + eT;
			 
								Mod->mod_vartable.SetFloat(varname, (float)(expire - current)/1000.0);
								iPush = 1;
							}
						break;
					}
				}
				if (!(*NWN_VirtualMachine)->StackPushInteger(iPush)) Ret = -638;
			}
			else {
				Ret = -639;
			}
			return Ret;
		}
	}
	return -1;
}

int CNWNXFuncs::ItemPropertyCustom(void *CVirtComm, int a1) {
	int result = -1;
	if (a1 == 657) {
		CExoString varname = CExoString("NWNX_FUNCS_IPRP");
		char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
		CNWSModule *Mod = ((CNWSModule*)(mod+=0x1C));
		CExoString *Params = NULL;
		Params = Mod->mod_vartable.GetString(varname);
		if (Params && Params->len > 0) {
			int Type=0, SubType=0, CostValue=0, ParamValue=0;
			if (sscanf(Params->text, "%d %d %d %d", &Type, &SubType, &CostValue, &ParamValue) == 4) {
				CGameEffect *e = (CGameEffect*)malloc(0x90);
				e->ctor(1);
				e->SetNumIntegersInitializeToNegativeOne(9);
				e->SetCreator(((CVirtualMachineCommands*)CVirtComm)->OBJ_SELF);
				e->eff_type = 91;
				e->eff_dursubtype &= 0xFFA | 2;

				e->eff_integers[0] = Type;
				e->eff_integers[1] = SubType;
				e->eff_integers[2] = a1;
				e->eff_integers[3] = CostValue;
				e->eff_integers[5] = ParamValue;

				e->eff_integers[7] = 100;
				e->eff_integers[8] = 1;

				if ((*NWN_VirtualMachine)->StackPushEngineStructure(4, e)) {
					if (e) {
						e->dtor();
						free(e);
					}
					result = 0;
				}
				else result = -638;
			}
		}
	}
	return result;
}