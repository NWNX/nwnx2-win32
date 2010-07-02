#if !defined(NWNXFUNCS_H_)
#define NWNXFUNCS_H_

#include "..\NWNXDLL\NWNXBase.h"
#include "types.h"
#include "HookFunc.h"
#include <list>
#include <map>
#include <vector>

class CNWNXCombat : public CNWNXBase {
public:
	CNWNXCombat();
	virtual ~CNWNXCombat();
	
	char *OnRequest(char *gameObject, char *Request, char *Parameters);
	BOOL OnCreate(const char *LogDir);
	BOOL OnRelease();

	void LOG(const char *pcMsg, ...);
	int NWN_GetAttackModifierVersus_Override(CNWSCreature *Attacker, CNWSObject *Defender);
	int NWN_GetMeleeAttackBonus(CNWSCreatureStats *Stats, int a2, int a3, int a4);
	int NWN_GetWeaponFinesse(CNWSCreatureStats *Stats, CNWSItem *Item);
	int NWN_CalculateOffHandAttacks(CNWSCombatRound *CombatRound);
	int NWN_HasFeat(CNWSCreatureStats *Stats, uint16_t FeatId);
	int NWN_GetWeaponFeat(CNWSCreatureStats *Stats, CNWSItem *Item, int iPos);

	void NWN_CreateGeometry(CNWSTrigger *Trigger, CScriptLocation *Loc, CNWSArea *Area);

	int debugLevel;
	int loghasfeat;

private:
	struct custom_feats_s {
		int16_t FEAT_KATANA_FINESSE,
				FEAT_GREATER_TWO_WEAPON_FIGHTING,
				FEAT_SUPREME_TWO_WEAPON_FIGHTING,
				FEAT_PERFECT_TWO_WEAPON_FIGHTING,
				FEAT_ABSOLUTE_AMBIDEXTERITY;
	}CustomFeats;

	struct custom_classes_s {
		uint8_t CLASS_TYPE_TEMPEST;
	}CustomClasses;

	std::map<int,int>M_WeaponFocus;
	std::map<int,int>M_EPWeaponFocus;
	std::map<int,int>M_WeaponSpec;
	std::map<int,int>M_EpWeaponSpec;
	std::map<int,int>M_ImprovedCrit;
	std::map<int,int>M_OverwhelmingCrit;
	std::map<int,int>M_DevCrit;
	std::map<int,int>M_WeaponOfChoice;

	std::vector<std::map<int,int>>WeaponFeats;

	void LoadCombatFeats();


	unsigned long OnRequestObject (char *gameObject, char *Request);
	void WriteLogHeader(int debug);
	void LoadConfiguration();


	int GetAttackModifierVersus(CNWSCreature *Attacker, nwn_objid_t oidDefender, int bOffHand, int nAttackNumber, int bMonk);
	int GetArmorClassVersus(CNWSCreature *Attacker, nwn_objid_t oidDefender, int bTouchAttack);
	CNWSCombatAttackData *CNWSCombatRound__GetAttack(CNWSCombatRound *round, int nAttack);
};

#endif;