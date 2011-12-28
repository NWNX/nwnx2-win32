#pragma once
#include "CFuncLookup.h"
#include "CFuncUtility.h"

class CNssCreatureStats : public CFuncLookup, public CFuncUtility {
public:
	CNssCreatureStats(uint8_t nSkills);

private: //helper functions
	uint8_t nSkill;

public: //script functions
	int SetAbilityScore(CGameObject *oObject, char *Params);
	int SetBABOverride(CGameObject *oObject, char *Params);
	int SetXP(CGameObject *oObject, char *Params);
	int SetRace(CGameObject *oObject, char *Params);
	int GetBaseAC(CGameObject *oObject, char *Params);
	int GetBABOverride(CGameObject *oObject, char *Params);
	int SetAge(CGameObject *oObject, char *Params);
	int SetBaseAC(CGameObject *oObject, char *Params);
	int GetBonusAC(CGameObject *oObject, char *Params);
	int SetBonusAC(CGameObject *oObject, char *Params);
	int GetPenaltyAC(CGameObject *oObject, char *Params);
	int SetPenaltyAC(CGameObject *oObject, char *Params);
	int GetSavedSkillPoints(CGameObject *oObject, char *Params);
	int SetSavedSkillPoints(CGameObject *oObject, char *Params);
	int GetArmorCheckPenalty(CGameObject *oObject, char *Params);
	int SetArmorCheckPenalty(CGameObject *oObject, char *Params);
	int GetMovementRate(CGameObject *oObject, char *Params);
	int SetMovementRate(CGameObject *oObject, char *Params);
	int SetSkill(CGameObject *oObject, char *Params);
	int SetSkillByLevel(CGameObject *oObject, char *Params);
	int SetClassByPosition(CGameObject *oObject, char *Params);
	int SetClassByLevel(CGameObject *oObject, char *Params);
	int SetClassLevel(CGameObject *oObject, char *Params);
	int ReplaceClass(CGameObject *oObject, char *Params);
	int SetHitPointsByLevel(CGameObject *oObject, char *Params);
	int SetCurrentHitPoints(CGameObject *oObject, char *Params) ;
	int SetMaxHitPoints(CGameObject *oObject, char *Params);
	int GetSavingThrowBonus(CGameObject *oObject, char *Params);
	int SetSavingThrowBonus(CGameObject *oObject, char *Params);
	int SetFamiliarType(CGameObject *oObject, char *Params);
	int SetCompanionType(CGameObject *oObject, char *Params);
	int ZeroAllSkills(CGameObject *oObject, char *Params);
	int SetDomain(CGameObject *oObject, char *Params);
	int GetDomain(CGameObject *oObject, char *Params);
	int SetWizardSpecialization (CGameObject *oObject, char *Params);
	int GetWizardSpecialization (CGameObject *oObject, char *Params);
	int GetFeatsGainedAtLevel(CGameObject *oObject, char *Params);
	int GetSkillRanksGainedAtLevel(CGameObject *oObject, char *Params);
	int GetSpellsGainedAtLevel(CGameObject *oObject, char *Params);
	int GetStatsGainedAtLevel(CGameObject *oObject, char *Params);
	int SetGender(CGameObject *oObject, char *Params);

};
