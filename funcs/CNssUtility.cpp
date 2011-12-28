#include "stdafx.h"
#include "CNssUtility.h"

CNssUtility::CNssUtility(void) {
	AddFunction("STRINGTOOBJECT", L_CAST(&CNssUtility::StringToObject));
	AddFunction("PRINTOFFSETS", L_CAST(&CNssUtility::PrintOffsets));
}

int CNssUtility::StringToObject(CGameObject *oObject, char *Params) {
	if (strlen(Params) < 1 && strlen(Params) > 8) {
		//oID can't be greater than 8 chars (4 hex chars);
		sprintf(Params, "%08X", OBJECT_INVALID);
		_log(2, "o Error: StringtoObject: object ID passed is greater than 8 characters or empty!\n");
		return 0;
	}

	return 1;
}

int CNssUtility::SetDebugLevel(CGameObject *oObject, char *Params) {
	int DebugLevel = 0;
	CParams::ExtractP1(Params, DebugLevel);
	LogFile::SetDebugLevel(DebugLevel);
	return 1;
}

int CNssUtility::PrintOffsets(CGameObject *oObject, char *Params) {
	CGameObject *obj = oObject;
	uint32_t iGO = (uint32_t)obj;

	_log(1, "\n--------------------CGameObject--------------------\n");
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

	CNWSCreature *cre = oObject->AsNWSCreature();
	CNWSCreatureStats *stats = cre->cre_stats;
	if (!cre) return 1;

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