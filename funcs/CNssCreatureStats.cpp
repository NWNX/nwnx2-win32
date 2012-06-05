#include "stdafx.h"
#include "CNssCreatureStats.h"

CNssCreatureStats::CNssCreatureStats(uint8_t nSkill) {
	this->nSkill = nSkill;

	AddFunction("SETABILITYSCORE", L_CAST(&CNssCreatureStats::SetAbilityScore));
	AddFunction("SETBABOVERRIDE", L_CAST(&CNssCreatureStats::SetBABOverride));
	AddFunction("SETXP", L_CAST(&CNssCreatureStats::SetXP));
	AddFunction("SETRACE", L_CAST(&CNssCreatureStats::SetRace));
	AddFunction("GETBASEAC", L_CAST(&CNssCreatureStats::GetBaseAC));	
	AddFunction("GETBABOVERRIDE", L_CAST(&CNssCreatureStats::GetBABOverride));	
	AddFunction("SETAGE", L_CAST(&CNssCreatureStats::SetAge));	
	AddFunction("SETBASEAC", L_CAST(&CNssCreatureStats::SetBaseAC));	
	AddFunction("GETBONUSAC", L_CAST(&CNssCreatureStats::GetBonusAC));	
	AddFunction("SETBONUSAC", L_CAST(&CNssCreatureStats::SetBonusAC));	
	AddFunction("GETPENALTYAC", L_CAST(&CNssCreatureStats::GetPenaltyAC));	
	AddFunction("SETPENALTYAC", L_CAST(&CNssCreatureStats::SetPenaltyAC));	
	AddFunction("GETSAVEDSKILLPOINTS", L_CAST(&CNssCreatureStats::GetSavedSkillPoints));	
	AddFunction("SETSAVEDSKILLPOINTS", L_CAST(&CNssCreatureStats::SetSavedSkillPoints));	
	AddFunction("GETARMORCHECKPENALTY", L_CAST(&CNssCreatureStats::GetArmorCheckPenalty));	
	AddFunction("SETARMORCHECKPENALTY", L_CAST(&CNssCreatureStats::SetArmorCheckPenalty));	
	AddFunction("GETMOVEMENTRATE", L_CAST(&CNssCreatureStats::GetMovementRate));	
	AddFunction("SETMOVEMENTRATE", L_CAST(&CNssCreatureStats::SetMovementRate));	
	AddFunction("SETSKILL", L_CAST(&CNssCreatureStats::SetSkill));	
	AddFunction("SETSKILLBYLEVEL", L_CAST(&CNssCreatureStats::SetSkillByLevel));	
	AddFunction("SETCLASSBYPOSITION", L_CAST(&CNssCreatureStats::SetClassByPosition));	
	AddFunction("SETCLASSBYLEVEL", L_CAST(&CNssCreatureStats::SetClassByLevel));	
	AddFunction("SETCLASSLEVEL", L_CAST(&CNssCreatureStats::SetClassLevel));	
	AddFunction("REPLACECLASS", L_CAST(&CNssCreatureStats::ReplaceClass));	
	AddFunction("SETHITPOINTSBYLEVEL", L_CAST(&CNssCreatureStats::SetHitPointsByLevel));	
	AddFunction("SETCURRENTHITPOINTS", L_CAST(&CNssCreatureStats::SetCurrentHitPoints));	
	AddFunction("SETMAXHITPOINTS", L_CAST(&CNssCreatureStats::SetMaxHitPoints));	
	AddFunction("GETSAVINGTHROWBONUS", L_CAST(&CNssCreatureStats::GetSavingThrowBonus));	
	AddFunction("SETSAVINGTHROWBONUS", L_CAST(&CNssCreatureStats::SetSavingThrowBonus));	
	AddFunction("SETFAMILIARTYPE", L_CAST(&CNssCreatureStats::SetFamiliarType));	
	AddFunction("SETCOMPANIONTYPE", L_CAST(&CNssCreatureStats::SetCompanionType));	
	AddFunction("ZEROALLSKILLS", L_CAST(&CNssCreatureStats::ZeroAllSkills));	
	AddFunction("SETDOMAIN", L_CAST(&CNssCreatureStats::SetDomain));	
	AddFunction("GETDOMAIN", L_CAST(&CNssCreatureStats::GetDomain));	
	AddFunction("SETWIZARDSPECIALIZATION", L_CAST(&CNssCreatureStats::SetWizardSpecialization));	
	AddFunction("GETWIZARDSPECIALIZATION", L_CAST(&CNssCreatureStats::GetWizardSpecialization));	
	AddFunction("GETFEATSGAINEDATLEVEL", L_CAST(&CNssCreatureStats::GetFeatsGainedAtLevel));	
	AddFunction("GETSKILLRANKSGAINEDATLEVEL", L_CAST(&CNssCreatureStats::GetSkillRanksGainedAtLevel));	
	AddFunction("GETSPELLSGAINEDATLEVEL", L_CAST(&CNssCreatureStats::GetSpellsGainedAtLevel));	
	AddFunction("GETSTATSGAINEDATLEVEL", L_CAST(&CNssCreatureStats::GetStatsGainedAtLevel));	
	AddFunction("SETGENDER", L_CAST(&CNssCreatureStats::SetGender));	
}

int CNssCreatureStats::SetAbilityScore(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetAbilityScore used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreatureStats *Stats = cre->cre_stats;
	uint8_t *Abilities = &Stats->cs_str;

	int AbilityScr = 0;
	int Ability = 0;
	int bAdd = 0;

	CParams::ExtractP3(Params, Ability, AbilityScr, bAdd);

	uint8_t AbilityScore = static_cast<uint8_t>(AbilityScr);

	unsigned short int iIndex = Ability*2;

	if (bAdd) AbilityScore += Abilities[iIndex];

	if (AbilityScore < 3) AbilityScore = 3;
	else if (AbilityScore > 255) AbilityScore = 255;

	switch (Ability) {
		case 0: Stats->SetSTRBase(AbilityScore); break;
		case 1: Stats->SetDEXBase(AbilityScore); break;
		case 2: Stats->SetCONBase(AbilityScore, 1); break;
		case 3: Stats->SetINTBase(AbilityScore); break;
		case 4: Stats->SetWISBase(AbilityScore); break;
		case 5: Stats->SetCHABase(AbilityScore); break;
	}

	return 1;
}

int CNssCreatureStats::SetBABOverride(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetBabOverride used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t BAB = 0;
	uint8_t bAdd = 0;

	CParams::ExtractP2(Params, BAB, bAdd);

	if (bAdd) BAB += cre->cre_stats->cs_override_bab;
	cre->cre_stats->cs_override_bab = BAB;

	return 1;
}

int CNssCreatureStats::SetXP(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetXP used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned int XP = 0;
	CParams::ExtractP1(Params, XP);

	cre->cre_stats->cs_xp = XP;

	return 1;
}

int CNssCreatureStats::SetRace(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetRace used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	
	unsigned short Race = 0;
	CParams::ExtractP1(Params, Race);

	cre->cre_stats->cs_race = Race;
	
	return 1;
}

int CNssCreatureStats::GetBaseAC(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetBaseAC used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int ACType = 0;
	CParams::ExtractP1(Params, ACType);

	uint8_t ac = 0;
	switch (ACType) {
		case AC_NATURAL: ac = cre->cre_stats->cs_ac_natural_base; break;
		case AC_ARMOUR:  ac = cre->cre_stats->cs_ac_armour_base; break;
		case AC_SHIELD:  ac = cre->cre_stats->cs_ac_shield_base; break;
	}
	sprintf(Params, "%d", ac);
	return 1;
}

int CNssCreatureStats::GetBABOverride(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetBABOverride used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", cre->cre_stats->cs_override_bab);

	return 1;
}

int CNssCreatureStats::SetAge(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetAge used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Age = 0;
	CParams::ExtractP1(Params, Age);

	cre->cre_stats->cs_age = Age;
	sprintf(Params, "1");

	return 1;
}

int CNssCreatureStats::SetBaseAC(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetBaseAC used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned char AC = 0;
	int Type = 0;
	CParams::ExtractP2<unsigned char, int>(Params, AC, Type);

	switch (Type) {
		case AC_NATURAL: cre->cre_stats->cs_ac_natural_base = AC; break;
		case AC_ARMOUR : cre->cre_stats->cs_ac_armour_base = AC; break;
		case AC_SHIELD : cre->cre_stats->cs_ac_shield_base = AC; break;
	}
	return 1;
}

int CNssCreatureStats::GetBonusAC(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetBonusAC used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Type = 0;
	CParams::ExtractP1(Params, Type);

	uint8_t ac = 0;
	switch (Type) {
		case AC_NATURAL:	ac = cre->cre_stats->cs_ac_natural_bonus; break;
		case AC_ARMOUR:		ac = cre->cre_stats->cs_ac_armour_bonus; break;
		case AC_SHIELD:		ac = cre->cre_stats->cs_ac_shield_bonus; break;
		case AC_DEFLECTION:	ac = cre->cre_stats->cs_ac_deflection_bonus; break;
		case AC_DODGE:		ac = cre->cre_stats->cs_ac_dodge_bonus; break;
	}
	sprintf(Params, "%d", ac);
	return 1;
}

int CNssCreatureStats::SetBonusAC(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetBonusAC used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned char AC = 0;
	int Type = 0;
	CParams::ExtractP2<unsigned char, int>(Params, AC, Type);

	switch (Type) {
		case AC_NATURAL:	cre->cre_stats->cs_ac_natural_bonus = AC; break;
		case AC_ARMOUR:		cre->cre_stats->cs_ac_armour_bonus = AC; break;
		case AC_SHIELD:		cre->cre_stats->cs_ac_shield_bonus = AC; break;
		case AC_DEFLECTION:	cre->cre_stats->cs_ac_deflection_bonus = AC; break;
		case AC_DODGE:		cre->cre_stats->cs_ac_dodge_bonus = AC; break;
	}
	return 1;
}

int CNssCreatureStats::GetPenaltyAC(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetPenaltyAC used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Type = 0;
	CParams::ExtractP1(Params, Type);

	uint8_t ac = 0;
	switch (Type) {
		case AC_NATURAL:	ac = cre->cre_stats->cs_ac_natural_penalty; break;
		case AC_ARMOUR:		ac = cre->cre_stats->cs_ac_armour_penalty; break;
		case AC_SHIELD:		ac = cre->cre_stats->cs_ac_shield_penalty; break;
		case AC_DEFLECTION:	ac = cre->cre_stats->cs_ac_deflection_penalty; break;
		case AC_DODGE:		ac = cre->cre_stats->cs_ac_dodge_penalty; break;
	}
	sprintf(Params, "%d", ac);
	return 1;
}

int CNssCreatureStats::SetPenaltyAC(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetPenaltyAC used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned char AC = 0;
	int Type = 0;
	CParams::ExtractP2<unsigned char, int>(Params, AC, Type);

	switch (Type) {
		case AC_NATURAL:	cre->cre_stats->cs_ac_natural_penalty = AC; break;
		case AC_ARMOUR:		cre->cre_stats->cs_ac_armour_penalty = AC; break;
		case AC_SHIELD:		cre->cre_stats->cs_ac_shield_penalty = AC; break;
		case AC_DEFLECTION:	cre->cre_stats->cs_ac_deflection_penalty = AC; break;
		case AC_DODGE:		cre->cre_stats->cs_ac_dodge_penalty = AC; break;
	}
	return 1;
}

int CNssCreatureStats::GetSavedSkillPoints(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetSavedSkillPoints used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Level = 0;
	CParams::ExtractP1(Params, Level);

	if (Level == 0) {
		sprintf(Params, "%d", cre->cre_stats->cs_skill_points);
	}
	else {
		CNWSStats_Level *ls = GetLevelStats(cre->cre_stats, Level);
		if (ls) sprintf(Params, "%d", ls->ls_skillpoints);
	}

	return 1;
}

int CNssCreatureStats::SetSavedSkillPoints(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetSavedSkillPoints used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Level = 0;
	int bAdd = 0;
	uint8_t Points = 0;

	CParams::ExtractP3(Params, Points, bAdd, Level);

	if (bAdd) {
		if (Level > 0) {
			CNWSStats_Level *ls = GetLevelStats(cre->cre_stats, Level);
			if (ls) ls->ls_skillpoints += Points;
		}
		else {
			cre->cre_stats->cs_skill_points += Points;
		}
	}
	else {
		if (Level > 0) {
			CNWSStats_Level *ls = GetLevelStats(cre->cre_stats, Level);
			if (ls) ls->ls_skillpoints = Points;
		}
		else {
			cre->cre_stats->cs_skill_points = Points;
		}
	}
	return 1;
}

int CNssCreatureStats::GetArmorCheckPenalty(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetArmorCheckPenalty used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int8_t acp = 0;
	int Type = 0;
	CParams::ExtractP1(Params, Type);

	switch (Type) {
		case AC_ARMOUR: acp = cre->cre_stats->cs_acp_armor; break;
		case AC_SHIELD: acp = cre->cre_stats->cs_acp_shield; break;
	}

	sprintf(Params, "%d", acp);
	return 1;
}

int CNssCreatureStats::SetArmorCheckPenalty(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetArmorCheckPenalty used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Type = 0;
	char Penalty = 0;
	CParams::ExtractP2(Params, Penalty, Type);

	switch (Type) {
		case AC_ARMOUR: cre->cre_stats->cs_acp_armor = Penalty; break;
		case AC_SHIELD: cre->cre_stats->cs_acp_shield = Penalty; break;
	}
	return 1;
}

int CNssCreatureStats::GetMovementRate(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetMovementRate used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", cre->cre_stats->cs_movement_rate);
	return 1;
}

int CNssCreatureStats::SetMovementRate(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetMovementRate used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned int Rate = 0;
	CParams::ExtractP1(Params, Rate);

	cre->cre_stats->cs_movement_rate = Rate;

	return 1;
}

int CNssCreatureStats::SetSkill(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetSkill used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Skill = 0; //P1;
	uint8_t Value = 0; //P2;
	int bAdd = 0; //P3;

	CParams::ExtractP3(Params, Skill, Value, bAdd);

	if (Skill > nSkill) {
		_log(2, "o Error (SetSkill): Specified Skill [%i] is outside the range specified in nwnx.ini [%i].\n", Skill, nSkill);
		sprintf(Params, "-1");
		return 0;
	}

	if (bAdd) Value += cre->cre_stats->cs_skills[Skill];

	if (Value > 127) Value = 127;
	if (Value < 0) Value = 0;

	cre->cre_stats->cs_skills[Skill] = Value;

	return 1;
}

int CNssCreatureStats::SetSkillByLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetSkillByLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSStats_Level *ls;

	uint8_t Skill = 0; //P1;
	uint8_t Value = 0; //P2;
	int Level = 0; //P3
	int bAdd = 0; //P4;

	CParams::ExtractP4(Params, Skill, Value, Level, bAdd);

	if (Skill > nSkill) {
		_log(2, "o Error (SetSkillByLevel): Specified Skill [%i] is outside the range specified in nwnx.ini [%i].\n", Skill, nSkill);
		sprintf(Params, "-1");
		return 0;
	}

	if ((ls = GetLevelStats(cre->cre_stats, Level)) == NULL) {
		_log(2, "o Error (SetSkillByLevel): Invalid level\n", Skill, nSkill);
		sprintf(Params, "-1");
		return 0;
	}

	int iVal = Value;

	if (bAdd) {
		iVal = Value + cre->cre_stats->cs_skills[Skill];
		Value += ls->ls_skilllist[Skill];
	}

	if (Value > 127) Value = 127;
	if (Value < 0) Value = 0;
	ls->ls_skilllist[Skill] = Value;

	if (iVal > 127) iVal = 127;
	if (iVal < 0) iVal = 0;
	cre->cre_stats->cs_skills[Skill] = iVal;

	return 1;
}

int CNssCreatureStats::SetClassByPosition(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetClassByPosition used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	if (cre->cre_stats->cs_classes == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	int Pos = 0;
	uint8_t Class = 0;

	CParams::ExtractP2(Params, Pos, Class);

	if (Pos < 1 || Pos > 3) {
		_log(2, "o Error: SetClassByPosition: Class Position invalid [%d].\n", Pos);
		sprintf(Params, "-1");
		return 0;
	}

	cre->cre_stats->cs_classes[Pos-1].cl_class = Class;

	return 1;
}

int CNssCreatureStats::SetClassByLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetClassByLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int Level = 0;

	CParams::ExtractP2(Params, Class, Level);

	CNWSStats_Level *ls = GetLevelStats(cre->cre_stats, Class);

	if (!ls) {
		sprintf(Params, "-1");
		return 0;
	}

	ls->ls_class = Level;
	
	return 1;
}

int CNssCreatureStats::SetClassLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetClassLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}
	
	if (cre->cre_is_pc) {
		_log(2, "o Error: SetClassLevel cannot be used on player characters.\n");
		sprintf(Params, "-1");
		return 0;
	}

	char Pos = 0;
	uint8_t Level = 0;
	CParams::ExtractP2(Params, Pos, Level);

	if (Pos < 1 || Pos > 3 || Level < 1 || Level > 60) {
		_log(2, "o Error: SetClassLevel: Class Position has to be between 1 and 3 and Level has to be within 1 and 60.\n");
		sprintf(Params, "-1");
		return 0;
	}

	Pos--;

	if (Pos < cre->cre_stats->cs_classes_len)
		cre->cre_stats->cs_classes[Pos].cl_level = Level;

	return 1;
}

int CNssCreatureStats::ReplaceClass(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: ReplaceClass used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSStats_Level *ls;
	int i=0;

	uint8_t OldClass = 0, NewClass = 0;
	CParams::ExtractP2(Params, OldClass, NewClass);

	while (i < cre->cre_stats->cs_levelstat.len) {
		ls = (CNWSStats_Level*)cre->cre_stats->cs_levelstat.data[i];
		if (ls->ls_class == OldClass) ls->ls_class = NewClass;
		i++;
	}

	for (i=0; i<cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class == OldClass) {
			cre->cre_stats->cs_classes[i].cl_class = NewClass;
			break;
		}
	}

	return 1;
}

int CNssCreatureStats::SetHitPointsByLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetHitPointsByLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t HP = 0;
	int Level = 0;
	int bAdd = 0;
	CParams::ExtractP3(Params, HP, Level, bAdd);

	CNWSStats_Level *ls = GetLevelStats(cre->cre_stats, Level);

	if (!ls) {
		sprintf(Params, "-1");
		return 0;
	}
	
	if (!bAdd) ls->ls_hp = HP;
	else ls->ls_hp += HP;
	return 1;
}

int CNssCreatureStats::SetCurrentHitPoints(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetCurrentHitPoints used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int16_t HP = 0;
	CParams::ExtractP1(Params, HP);

	cre->obj_hp_cur = HP;
	return 1;
}

int CNssCreatureStats::SetMaxHitPoints(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetMaxHitPoints used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int16_t HP = 0;
	CParams::ExtractP1(Params, HP);

	cre->obj_hp_max = HP;
	return 1;
}

int CNssCreatureStats::GetSavingThrowBonus(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetSavingThrowBonus used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Save = 0;
	CParams::ExtractP1(Params, Save);

	switch(Save) {
		case 1: sprintf(Params, "%d", cre->cre_stats->cs_save_fort);
		case 2: sprintf(Params, "%d", cre->cre_stats->cs_save_reflex);
		case 3: sprintf(Params, "%d", cre->cre_stats->cs_save_will);
		default:
			sprintf(Params, "-1");
			_log(2, "o Error: GetSavingThrowBonus: Invalid Saving Throw type.\n");
		break;

	}

	return 1 ;
}

int CNssCreatureStats::SetSavingThrowBonus(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetSavingThrowBonus used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Save = 0;
	char Value = 0;
	int bAdd = 0;
	CParams::ExtractP3(Params, Save, Value, bAdd);


	_log(3, "o SavingThrowBonus: Save=%i, Value=%i, bAdd=%1\n", Save, Value, bAdd);

	switch (Save) {
		case 1: cre->cre_stats->cs_save_fort = bAdd ? cre->cre_stats->cs_save_fort + Value : Value; break;
		case 2: cre->cre_stats->cs_save_reflex = bAdd ? cre->cre_stats->cs_save_reflex + Value : Value; break;
		case 3: cre->cre_stats->cs_save_will = bAdd ? cre->cre_stats->cs_save_will + Value : Value; break;
		default:
			sprintf(Params, "-1");
			_log(2, "o Error: SetSavingThrowBonus: Invalid Saving Throw Type\n");
		break;

	}
	return 1;
}

int CNssCreatureStats::SetFamiliarType(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetFamiliarType used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned int Type = 0;
	CParams::ExtractP1(Params, Type);

	cre->cre_stats->cs_famil_type = Type;
	return 1;
}

int CNssCreatureStats::SetCompanionType(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetCompanionType used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned int Type = 0;
	CParams::ExtractP1(Params, Type);

	cre->cre_stats->cs_acomp_type = Type;
	return 1;
}

int CNssCreatureStats::ZeroAllSkills(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: ZeroAllSkills used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSStats_Level *ls;

	int iLevel = 0;
	int iSkill = 0;
	
	while ((ls = GetLevelStats(cre->cre_stats, ++iLevel)) != NULL) {
		for(iSkill = nSkill; iSkill > 0; iSkill--) {
			cre->cre_stats->cs_skills[iSkill] = 0;
			if (iLevel == 1) ls->ls_skilllist[iSkill] = 0;
		}
	}
	return 1;
}

int CNssCreatureStats::SetDomain(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetDomain used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Domain_1_2 = 0;
	uint8_t Domain = 0;

	CParams::ExtractP2(Params, Domain_1_2, Domain);

	if (Domain_1_2 < 1 || Domain_1_2 > 2) return 0;

	int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 2) {
            if (Domain_1_2 == 1)
                cre->cre_stats->cs_classes[i].cl_domain_1 = Domain;
            else
                cre->cre_stats->cs_classes[i].cl_domain_2 = Domain;
            return 1;
        }
    } 

	return 1;
}

int CNssCreatureStats::GetDomain(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetDomain used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Domain_1_2 = 0;

	CParams::ExtractP1(Params, Domain_1_2);

	if (Domain_1_2 < 1 || Domain_1_2 > 2) return 0;

	int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 2) {
			if (Domain_1_2 == 1)
                sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_domain_1);
			else
                sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_domain_2);
            return 1;
        }
    } 

	return 1;
}

int CNssCreatureStats::SetWizardSpecialization (CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetWizardSpecialization used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Spec = 0;
	CParams::ExtractP1(Params, Spec);

	if (Spec < 0 || Spec > 8) {
		sprintf(Params, "-1");
		return 0;
	}

    int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 10) {
            cre->cre_stats->cs_classes[i].cl_specialist = Spec;
            break;
        }
    }

	return 1;
}

int CNssCreatureStats::GetWizardSpecialization (CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetWizardSpecialization used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "-1");

	int i;
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == 10) {
            sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_specialist);
            break;
        }
    }

	return 1;
}

int CNssCreatureStats::GetFeatsGainedAtLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetFeatsGainedAtLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreatureStats *Stats = cre->cre_stats;
	CNWSStats_Level *ls;

	int Level = -1;
	CParams::ExtractP1(Params, Level);
		
	if ((ls = GetLevelStats(Stats, Level)) == NULL) {
		_log(2, "o Error (GetFeatsGainedAtLevel): Could not get stats for given level(%d).\n", Level);
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

int CNssCreatureStats::GetSkillRanksGainedAtLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetSkillRanksGainedAtLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreatureStats *Stats = cre->cre_stats;
	CNWSStats_Level *ls;

	int Level = -1;
	CParams::ExtractP1(Params, Level);
	
	if ((ls = GetLevelStats(Stats, Level)) == NULL) {
		_log(2, "o Error (GetSkillRanksGainedAtLevel): Could not get stats for given level(%d).\n", Level);
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

int CNssCreatureStats::GetSpellsGainedAtLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetSpellsGainedAtLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Level = -1;
	int SpellLevel = 0;

	CParams::ExtractP2(Params, Level, SpellLevel);
	sprintf(Params, "");

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CNWSStats_Level *ls;
		
	if ((ls = GetLevelStats(Stats, Level)) == NULL) {
		_log(2, "o Error (GetSpellsGainedAtLevel): Could not get stats for given level(%d).\n", Level);
		sprintf(Params, "-1");
		return 0;
	}

	CExoArrayList_uint32 *ls_spells_known = &ls->ls_spells_known[SpellLevel];
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

int CNssCreatureStats::GetStatsGainedAtLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: GetStatsGainedAtLevel used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Level = -1;
	CParams::ExtractP1(Params, Level);
	sprintf(Params, "");

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CNWSStats_Level *ls;
		
	if ((ls = GetLevelStats(Stats, Level)) == NULL) {
		_log(2, "o Error (GetSpellsGainedAtLevel): Could not get stats for given level(%d).\n", Level);
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d|%d|%d|%d", ls->ls_ability, ls->ls_class, ls->ls_hp, ls->ls_skillpoints); 

	return 1;
}

int CNssCreatureStats::SetGender(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: SetGender used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned int Gender = 0;
	CParams::ExtractP1(Params, Gender);

	cre->cre_stats->cs_gender = Gender;
	return 1;
}
