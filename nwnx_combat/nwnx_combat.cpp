#include "stdafx.h"
#include "nwnx_combat.h"
#include "../NWNXdll/IniFile.h"
#include <math.h>
#include <list>

#define _log(a,b,...) if(a<=debugLevel)LOG(b,__VA_ARGS__)

CNWNXCombat::CNWNXCombat() {
	loghasfeat = 0;
}

CNWNXCombat::~CNWNXCombat() {
	OnRelease();
}

BOOL CNWNXCombat::OnCreate(const char* LogDir) {
	// call the base class function
	char _log[MAX_PATH];
	sprintf (_log, "%s\\nwnx_combat.txt", LogDir);
	if (!CNWNXBase::OnCreate(_log))
		return false;

	LoadConfiguration();
	WriteLogHeader(debugLevel);
	//LoadCombatFeats();
	HookFunctions();

	return true;
}

void CNWNXCombat::LoadConfiguration() {
	CIniFile iniFile ("nwnx.ini");
	debugLevel = iniFile.ReadInteger("COMBAT", "DebugLevel", 0);
	
	CustomFeats.FEAT_KATANA_FINESSE = iniFile.ReadInteger("COMBAT", "FEAT_KATANA_FINESSE", 0xFFFF);
	CustomFeats.FEAT_GREATER_TWO_WEAPON_FIGHTING = iniFile.ReadInteger("COMBAT", "FEAT_GREATER_TWO_WEAPON_FIGHTING", 0xFFFF);
	CustomFeats.FEAT_SUPREME_TWO_WEAPON_FIGHTING = iniFile.ReadInteger("COMBAT", "FEAT_SUPREME_TWO_WEAPON_FIGHTING", 0xFFFF);
	CustomFeats.FEAT_PERFECT_TWO_WEAPON_FIGHTING = iniFile.ReadInteger("COMBAT", "FEAT_PERFECT_TWO_WEAPON_FIGHTING", 0xFFFF);
	CustomFeats.FEAT_ABSOLUTE_AMBIDEXTERITY = iniFile.ReadInteger("COMBAT", "FEAT_ABSOLUTE_AMBIDEXTERITY", 0xFFFF);
	
	CustomClasses.CLASS_TYPE_TEMPEST = iniFile.ReadInteger("COMBAT", "CLASS_TYPE_TEMPEST", 0xFFFF);
}

BOOL CNWNXCombat::OnRelease() {
	LOG("o Shutting down\n");

	// call base class function
	return CNWNXBase::OnRelease();
}

char* CNWNXCombat::OnRequest(char *gameObject, char* Request, char* Parameters) {
	_log(1, "- StrReq: \"%s\"           Params: \"%s\"\n", Request, Parameters);

	if (gameObject == NULL) {
		_log(1, "o Error: Invalid Object passed to nwnx_funcs.\n");
		sprintf(Parameters, "");
		return NULL;
	}

	if (strcmp(Request, "GETATTACKMODIFIER") == 0) {
		unsigned int oidDefender=0, bOffHand=0, nAttackNumber=0, bMonk=0;

		if (sscanf(Parameters, "%08X %d %d %d", &oidDefender, &bOffHand, &nAttackNumber, &bMonk) != 4) {
			_log(3, "Too little parameters\n");
		}
		else {
			_log(3, "%08X %d %d %d\n", oidDefender, bOffHand, nAttackNumber, bMonk);
			GetAttackModifierVersus((CNWSCreature*)gameObject, oidDefender, bOffHand, nAttackNumber, bMonk);
		}
	}
	else if (strcmp(Request, "RESOLVERANGEDATTACK") == 0) {
		unsigned int oidDefender=0, a3=0, a4;

		if (sscanf(Parameters, "%08X %d %d %d", &oidDefender, &a3, &a4) != 3) {
		}

		CNWSCreature *cre = (CNWSCreature*)gameObject;
		//CNWSObject *oDefender = (CNWSObject*)CServerExoApp__GetGameObject((*NWN_AppManager)->app_server, NULL, oidDefender);
		//CNWSCombatRound__ClearAllAttacks(cre->cre_combat_round, NULL);
		CNWSCombatRound__StartCombatRound(cre->cre_combat_round, NULL, oidDefender);
		CNWSCreature__ResolveAttack(cre, NULL, oidDefender, a3, a4);
	}
	else if (strcmp(Request, "TEST") == 0) {
		LoadCombatFeats();
	}

	return NULL;
}

unsigned long CNWNXCombat::OnRequestObject (char *gameObject, char* Request){
	_log(1, "- ObjReq: %08X             Request: %s\n", gameObject, Request);
	uint32_t ret = OBJECT_INVALID;

	return ret;
}


void CNWNXCombat::LOG(const char *pcMsg, ...) {
	va_list argList;
	char *pos;

	if (m_fFile)
	{  

		if (ftell(m_fFile) > m_maxLogSizeKB)
		{	
			fclose(m_fFile);
			m_fFile = fopen (m_LogFile, "w");
			WriteLogHeader(debugLevel);
			fprintf(m_fFile, "o Logfile hit maximum size limit, starting again.\n");
		}

		// build up the string
		va_start(argList, pcMsg);
		vsprintf(acBuffer, pcMsg, argList);
		va_end(argList);

		// replace any percent signs
		pos = strchr(acBuffer, '%');
		while (pos)
		{
			*pos = '~';
			pos = strchr(acBuffer, '%');
		}

		// _log string in file
		fprintf (m_fFile, acBuffer);
		fflush (m_fFile);
	}
}

void CNWNXCombat::WriteLogHeader(int debug)
{
	fprintf(m_fFile, "Windows NWNX Combat plugin v.0.0.1");
	if (!debug) fprintf(m_fFile, " [logging off]");
	else fprintf(m_fFile, " [_log level: %i]", debug);
	fprintf(m_fFile, "\n");
	fflush (m_fFile);
}

int CNWNXCombat::GetAttackModifierVersus(CNWSCreature *Attacker, nwn_objid_t oidDefender, int bOffHand, int nAttackNumber, int bMonk) {
	CNWSCreature *Defender = (CNWSCreature*)CServerExoApp__GetGameObject((*NWN_AppManager)->app_server, NULL, oidDefender);

	CNWSItem *Weapon;

	int iBab = 0;
	int iTwoWeaponFighting_Mod = 0;
	int iSize_Mod = 0;
	int iCombatMode_Mod = 0;
	int iSpecialAttack_Mod = 0;
	int iNatureSense_Mod = 0;
	int iEpicProwess_Mod = 0;
	int iWeaponMaster_Mod = 0;
	int iFavoredEnemy_Mod = 0;
	int iGoodAim_Mod = 0;
	int iHalflingSling_Mod = 0;
	int iEnchantArrow_Mod = 0;
	int iOffensiveTraining_Mod = 0;
	int iAbility_Mod = 0;
	int iWeaponFocus_Mod = 0;
	int iEpicWeaponFocus_Mod = 0;
	int iTotalEffect_Mod = 0;
	int iBlindDefender_Mod = 0;
	int iInvisAttacker_Mod = 0;
	int iCantSeeTarget_Mod = 0;
	int iTargetState_Mod = 0;
	int iTargetFlanked_Mod = 0;
	int iRanged_Mod = 0;
	int iEnemyAttack_Mod = 0;

	CNWSItem *WeaponMain = NULL;
	CNWSItem *WeaponOff = NULL;

	CNWBaseItem *BaseMain = NULL;
	CNWBaseItem *BaseOff = NULL;

	WeaponMain = CNWSInventory__GetItemInSlot(Attacker->cre_equipment, NULL, 0x10);
	WeaponOff  = CNWSInventory__GetItemInSlot(Attacker->cre_equipment, NULL, 0x20);

	_log (3, "Attacker ID: %08x\nDefender ID: %08x\nMain Weapon ID: %08x\nOff Weapon ID: %08x\n",
		Attacker == NULL ? 0x7F000000 : Attacker->obj.obj_generic.obj_id,
		Defender == NULL ? 0x7F000000 : Defender->obj.obj_generic.obj_id,
		WeaponMain == NULL ? 0x7F000000 : WeaponMain->obj.obj_generic.obj_id,
		WeaponOff == NULL ? 0x7F000000 : WeaponOff->obj.obj_generic.obj_id
	);

	// Base Attack Bonus
	iBab = CNWSCreatureStats__GetBaseAttackBonus(Attacker->cre_stats, NULL, 0);
	if (bMonk)
		iBab -= 3 * nAttackNumber;
	else
		iBab -= 5 * nAttackNumber;

	_log(3, "Bab: \t\t\t\t%d\n", iBab);


	/************************ iTwoWeaponFightingPenalty *********************/

	// get the baseitem data
	if (WeaponMain != NULL) { // is it possible to have an offhand weapon equipped without a main weapon?
		BaseMain = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, WeaponMain->it_baseitemtype);
		if (WeaponOff != NULL) {
			BaseOff = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, WeaponOff->it_baseitemtype);
		}

		if ((WeaponOff == NULL || BaseOff->WeaponType == 0) && (WeaponMain != NULL && BaseMain != NULL && BaseMain->WeaponType != 8)) {
			//not wielding an offhand weapon or a double sided weapo: no penalty
			iTwoWeaponFighting_Mod = 0;	
		}
		else { // wielding weapons that incurr penalties
			if (!bOffHand) { // main attack penalties
				iTwoWeaponFighting_Mod = -6;
				if ((CNWSCreature__GetRelativeWeaponSize(Attacker, NULL, WeaponOff) <= -1) || BaseMain->WeaponWield == 8)
					iTwoWeaponFighting_Mod = -4;
				if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 41)) //FEAT_TWO_WEAPON_FIGHTING
					iTwoWeaponFighting_Mod += 2;
			}
			else { // Off hand attack penalties
				iTwoWeaponFighting_Mod = -10;
				if ((CNWSCreature__GetRelativeWeaponSize(Attacker, NULL, WeaponOff) <= -1) || BaseMain->WeaponWield == 8)
					iTwoWeaponFighting_Mod = -8;
				if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 1)) //FEAT_AMBIDEXTERITY
					iTwoWeaponFighting_Mod += 4;
				if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 41)) //FEAT_TWO_WEAPON_FIGHTING
					iTwoWeaponFighting_Mod += 2;
			}
		}
	}

	_log(3, "iTwoWeaponFighting_Mod: \t%d\n", iTwoWeaponFighting_Mod);

	
	/************************ Size Modifiers *********************/

	iSize_Mod = 3 - Attacker->cre_size;

	_log(3, "iSize_Mod: \t\t\t%d\n", iSize_Mod);

	/************************ Combat Mode Modifiers *********************/
	
	switch(Attacker->cre_mode_combat) {
		case 2: iCombatMode_Mod = -5; break;
		case 3: iCombatMode_Mod = -10; break;
		case 5: iCombatMode_Mod = -2; break;
		case 6: iCombatMode_Mod = -2; break;
		case 7: iCombatMode_Mod = -5; break;
		case 8: iCombatMode_Mod = -10; break;
	}

	_log(3, "iCombatMode_Mod: \t\t%d\n", iCombatMode_Mod);

	/************************ Special Attack Modifiers *********************/

	iSpecialAttack_Mod = CNWSCreatureStats__ResolveSpecialAttackAttackBonus(Attacker->cre_stats, NULL, Defender);

	_log(3, "iSpecialAttack_Mod: \t\t%d\n", iSpecialAttack_Mod);

	/************************ Nature Sense Modifier *********************/

	unsigned char area = *(unsigned char *)(CNWSObject__GetArea((CNWSObject*)Attacker, NULL) + 4);
	if (area && (area & 4 || area & 1 || area & 2) && CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 198))
		iNatureSense_Mod = 2;

	_log(3, "iNatureSense_Mod: \t\t%d\n", iNatureSense_Mod);

	/************************ Epic Prowess Modifier *********************/

	if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 584))
		iEpicProwess_Mod = 1;

	_log(3, "iEpicProwess_Mod: \t\t%d\n", iEpicProwess_Mod);

	/************************ Weapon Master Modifier *********************/

	int bWeaponOfChoice = 0;
	if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 884)
	&& (bWeaponOfChoice = CNWSCreatureStats__GetIsWeaponOfChoice(Attacker->cre_stats, NULL, WeaponMain->it_baseitemtype))) {
		iWeaponMaster_Mod = 1;
		bWeaponOfChoice = 1;
	}
	if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 1071) && bWeaponOfChoice) {
		// get the weapon master levels
		for (int i = 0; i<3; i++) {
			if (Attacker->cre_stats->cs_classes[i].cl_class != 33)
				continue;

			int SuperiorWeaponFocus = (int)((Attacker->cre_stats->cs_classes[i].cl_level - 10) / 3);

			iWeaponMaster_Mod += SuperiorWeaponFocus > 0 ? SuperiorWeaponFocus : 0;
		}
	}

	_log(3, "iWeaponMaster_Mod: \t\t%d\n", iWeaponMaster_Mod);
	
	/************************ Favored Enemy Modifier *********************/

	if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 855)) {
		if (CNWSCreatureStats__GetFavoredEnemyBonus(Attacker->cre_stats, NULL, Defender)) {
			iFavoredEnemy_Mod = 2;
		}
	}

	_log(3, "iFavoredEnemy_Mod: \t\t%d\n", iFavoredEnemy_Mod);

	/************************ Good Aim Modifier *********************/

	iGoodAim_Mod = (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 250) && BaseMain && BaseMain->WeaponWield == 11);

	_log(3, "iGoodAim_Mod: \t\t\t%d\n", iGoodAim_Mod);

	/************************ Halfling Sling Modifier *********************/

	iHalflingSling_Mod =  (Attacker->cre_stats->cs_race == 3 && WeaponMain && WeaponMain->it_baseitemtype == 61);

	_log(3, "iHalflingSling_Mod: \t\t%d\n", iHalflingSling_Mod);

	/************************ Enchant Arrow Modifier *********************/

	if (WeaponMain && (WeaponMain->it_baseitemtype == 8 || WeaponMain->it_baseitemtype == 11)) {
		for (int i=1059; i<=1045; i--) {
			if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, i)) {
				iEnchantArrow_Mod = i-1039;
				break;
			}
		}
		if (!iEnchantArrow_Mod) {
			for (int i=449; i<=445; i--) {
				if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, i)) {
					iEnchantArrow_Mod = i-444;
					break;
				}
			}
		}
	}

	_log(3, "iEnchantArrow_Mod: \t\t%d\n", iEnchantArrow_Mod);

	/************************ Offensive Training Modifier *********************/

	if ((CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 232) && Defender->cre_stats->cs_race == 12)
		|| (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 231) && Defender->cre_stats->cs_race == 14)
		|| (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 242) && Defender->cre_stats->cs_race == 15)
	) {
		iOffensiveTraining_Mod = 1;
	}

	_log(3, "iOffensiveTraining_Mod: \t%d\n", iOffensiveTraining_Mod);
	
	/************************ Ability Modifier *********************/
	
	int iDex = CNWSCreatureStats__GetDEXMod(Attacker->cre_stats, NULL, 0);
	int iWis = Attacker->cre_stats->cs_wis_mod;
	int iStr = Attacker->cre_stats->cs_str_mod;
	int iAbility = iStr;

	if (BaseMain && BaseMain->RangedWeapon) { //ranged attack?
		iAbility = iDex;
		if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 412)) {
			if (iWis > iDex) iAbility = iWis;
		}
	}
	else {
		iAbility = iStr;
		if (!bOffHand) {
			if (WeaponMain && NWN_GetWeaponFinesse(Attacker->cre_stats, WeaponMain)) {
				if (iDex > iStr) iAbility = iDex;
			}
		}
		else {
			if (WeaponOff && NWN_GetWeaponFinesse(Attacker->cre_stats, WeaponOff)) {
				if (iDex > iStr) iAbility = iDex;
			}
		}
	}

	iAbility_Mod = iAbility;

	_log(3, "iAbility_Mod: \t\t\t%d\n", iAbility_Mod);

	/************************ Epic / Weapon Focus Modifier *********************/

	if (!bOffHand) Weapon = WeaponMain;
	else Weapon = WeaponOff;

	if (Weapon && CNWSCreatureStats__GetWeaponFocus(Attacker->cre_stats, NULL, Weapon)) iWeaponFocus_Mod = 1;
	if (Weapon && CNWSCreatureStats__GetEpicWeaponFocus(Attacker->cre_stats, NULL, Weapon)) iEpicWeaponFocus_Mod = 2;

	_log(3, "iWeaponFocus_Mod: \t\t%d\n", iWeaponFocus_Mod);
	_log(3, "iEpicWeaponFocus_Mod: \t\t%d\n", iEpicWeaponFocus_Mod);

	/************************ TotalEffectBonus Modifier *********************/
	//Have to admit, I have no clue what this actually does

	iTotalEffect_Mod = 
		CNWSCreature__GetTotalEffectBonus(
		Attacker,
		NULL,
		1,
		(CNWSObject *)(*(int (__thiscall **)(CNWSCreature *))(Defender->obj.obj_generic.obj_type + 16))(Defender),
		0,
		0,
		0,
		0,
		-1,
		-1,
		0);
	// can't believe this actually compiles O.O

	_log(3, "iTotalEffect_Mod: \t\t%d\n", iTotalEffect_Mod);

	/************************ Blind Defender Modifier *********************/

	if (CNWSCreature__GetBlind(Defender, NULL) && ((BaseMain && BaseMain->RangedWeapon) || !CNWSCreatureStats__HasFeat(Defender->cre_stats, NULL, 408))) {
		iBlindDefender_Mod = 2;
	}

	_log(3, "iBlindDefender_Mod: \t\t%d\n", iBlindDefender_Mod);

	/************************ Invisible Attacker Modifier *********************/

	CNWSObject *obj_bInvisible = (CNWSObject *)(*(int (__thiscall **)(CNWSCreature *))(Attacker->cre_stats->cs_original->obj.obj_generic.obj_type + 16))(Attacker->cre_stats->cs_original);
	if (CNWSCreature__GetInvisible(Attacker, NULL, obj_bInvisible, 0)
		&& ((BaseMain && BaseMain->RangedWeapon) || !CNWSCreatureStats__HasFeat(Defender->cre_stats, NULL, 408))
	) {
		iInvisAttacker_Mod = 2;
	}

	_log(3, "iInvisAttacker_Mod: \t\t%d\n", iInvisAttacker_Mod);

	/************************ Can't see target Modifier *********************/

	CNWVisibilityNode *obj_GetVisibleElement = CNWSCreature__GetVisibleListElement(Attacker, NULL, Defender->obj.obj_generic.obj_id);
	if ( !obj_GetVisibleElement || !((unsigned int)obj_GetVisibleElement[1].unknown & 1) ) {
		iCantSeeTarget_Mod = -4;
	}

	_log(3, "iCantSeeTarget_Mod: \t\t%d\n", iCantSeeTarget_Mod);

	/************************ Target States (Animation) Modifier *********************/

	int DefenderState = Defender->obj.obj_anim;

	int ProneMod = 0, MovingPenalty = 0, StunnedMod = 0;

	if (BaseMain && BaseMain->RangedWeapon) { //Ranged Attack
		if ( DefenderState == 4 || DefenderState == 87 || DefenderState == 86 )
			MovingPenalty = -2;
		if ( DefenderState == 36 || DefenderState == 33 || DefenderState == 32 || DefenderState == 7 || DefenderState == 5 ) {
			ProneMod = -4;
			//onHand_OffHand_2 = -4;                  // Target prone
		}
	}
	else {
		if ( DefenderState == 36 || DefenderState == 33 || DefenderState == 32 || DefenderState == 7 || DefenderState == 5 ) {
			ProneMod = 4;
			//onHand_OffHand_2 = 4;
		}
	}
	if ( Defender->cre_state == 6 ) //stunned?
		StunnedMod = 2;

	iTargetState_Mod = ProneMod + MovingPenalty + StunnedMod;

	_log(3, "iTargetState_Mod: \t\t%d [Anim: %d]\n", iTargetState_Mod, Defender->obj.obj_anim);

	/************************ Distance Calculation, gonna need that more than once *********************/

	Vector posAttacker = Attacker->obj.obj_position;
	Vector posDefender = Defender->obj.obj_position;

	posAttacker.x -= posDefender.x;
	posAttacker.y -= posDefender.y;
	posAttacker.z -= posDefender.z;

	posAttacker.x *= posAttacker.x;
	posAttacker.y *= posAttacker.y;
	posAttacker.z *= posAttacker.z;
	
	float fDistance = sqrt(posAttacker.x+posAttacker.y+posAttacker.z);


	/************************ Target Flanked Modifier *********************/

	if (CNWSCreature__GetFlanked(Attacker, NULL, Defender)) {
		if (BaseMain && BaseMain->RangedWeapon) {
			// on ranged sneak attack the distance between Attacker and Defender must be <= 9.144m
			if (fDistance <= 9.144) {
				iTargetFlanked_Mod = 2;
			}
		}
		else {
			iTargetFlanked_Mod = 2;
		}
	}

	_log(3, "iTargetFlanked_Mod: \t\t%d\n", iTargetFlanked_Mod);

	/************************ Point Blank Shot Modifier *********************/

	if (BaseMain && BaseMain->RangedWeapon) {
		if (fDistance <= 4.572) {
			if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 27)) { //+1 if within 15 ft with Point Blank Shot feat
				iRanged_Mod = 1;
			}
			else {
				iRanged_Mod = -4;
			}
/*			float maxAttackRange = CNWSCreature__MaxAttackRange(Attacker, NULL, Defender->obj.obj_generic.obj_id, 0, 0);
			if (fDistance <= maxAttackRange) {
			}*/
		}
	}

	_log(3, "iRanged_Mod: \t\t\t%d\n", iRanged_Mod);
	
	/************************ Enemy Attack Modifier *********************/
	// no clue what this is either
	iEnemyAttack_Mod = Defender->cre_stats->field_413;

	_log(3, "iEnemyAttack_Mod: \t\t%d\n", iEnemyAttack_Mod);


	int iAttackBonus = 
	iBab					+
	iTwoWeaponFighting_Mod	+
	iSize_Mod				+
	iCombatMode_Mod			+
	iSpecialAttack_Mod		+
	iNatureSense_Mod		+
	iEpicProwess_Mod		+
	iWeaponMaster_Mod		+
	iFavoredEnemy_Mod		+
	iGoodAim_Mod			+
	iHalflingSling_Mod		+
	iEnchantArrow_Mod		+
	iOffensiveTraining_Mod	+
	iAbility_Mod			+
	iWeaponFocus_Mod		+
	iEpicWeaponFocus_Mod	+
	iTotalEffect_Mod		+
	iBlindDefender_Mod		+
	iInvisAttacker_Mod		+
	iCantSeeTarget_Mod		+
	iTargetState_Mod		+
	iTargetFlanked_Mod		+
	iRanged_Mod				+
	iEnemyAttack_Mod;

	_log(3, "Final Attack Modifier: \t%d\n", iAttackBonus);
	return 0;
}

int CNWNXCombat::GetArmorClassVersus(CNWSCreature *Defender, nwn_objid_t oidAttacker, int bTouchAttack) {
//
//	int iAC_Base = 10;
//	int AC_Natural = 0;
//	int AC_Armor = 0;
//	int AC_Shield = 0;
//
//	int iSize_Mod = 0;
//	int iDex_Mod = 0;
//	int iDodge_AC = 0;
//	int iTumble_AC = 0;
//	int iDefensiveTraining_AC = 0;
//	int iExpertise_AC = 0;
//
//	int ac_natural_penalty
//
//	CNWSCreature *Attacker = (CNWSCreature*)CServerExoApp__GetGameObject((*NWN_AppManager)->app_server, NULL, oidAttacker);
//	int bRangedAttack = 0;
//	int bAoO = 0;
//
//
//	
//	/************************ Size Modifier *********************/
//
//	iSize_Mod = 3 - Defender->cre_size;
//
//	_log(3, "SizeMod: %d\n", iSize_Mod);
//
//
//	/************************ Armor, Shield and Natural AC Modifier *********************/
//
//	AC_Natural = CNWSCreatureStats__GetACNaturalBase(Defender->cre_stats, NULL, bTouchAttack);
//	
//	if (!bTouchAttack) {
//		AC_Armor = Defender->cre_stats->cs_ac_armour_base;
//		AC_Shield = Defender->cre_stats->cs_ac_shield_base;
//	}
//
//
//	/************************ Dex Modifier & Dodge Modifiers *********************/
//
//	iDex_Mod = CNWSCreatureStats__GetDEXMod(Defender->cre_stats, NULL, 1);
//
//	// do we get to keep our dex bonus
//	CNWSObject *obj_bInvisible = (CNWSObject *)(*(int (__thiscall **)(CNWSCreature *))(Defender->cre_stats->cs_original->obj.obj_generic.obj_type + 16))(Attacker->cre_stats->cs_original);
//	if (((CNWSCreature__GetInvisible(Attacker, NULL, obj_bInvisible, 0) && !CNWSCreatureStats__HasFeat(Defender->cre_stats, NULL, 0x198))
//	|| CNWSCreature__GetFlatFooted(Defender, NULL) == 1)
//	&& !(CNWSCreatureStats_HasFeat(Defender->cre_stats, NULL, 195) || CNWSCreatureStats_HasFeat(Defender->cre_stats, NULL, 949))){
//		iDex_Mod = 0;
//	}
//
//	if (iDex_Mod > 0) _log(3, "iDex_Mod: %d\n", iDex_Mod);
//	
//	if (iDex_Mod > 0) { //we don't get the following bonuses if we don't get the Dex Mod
//		CNWSVisibilityNode *visNode = CNWSCreature__GetVisibleListElement(Defender, NULL, Attacker->obj.obj_generic.obj_id);
//		if (visNode &&
//		((unsigned int)visNode[1].unknown &1
//		|| CNWSCreatureStats__HasFeat(Defender->cre_stats, 0x198)
//		&& !bRangedAttack)) {
//			iDodge_AC = Defender->cre_stats->cs_ac_dodge_bonus - Defender->cre_stats->cs_ac_dodge_penalty;
//			if (iDodge_AC > 20) iDodge_AC = 20;
//			if (bAoO) {
//				if (CNWSCreatureStats__HasFeat(Defender->cre_stats, NULL, 0x1A)) //Mobility
//					iDodge_AC += 4;
//			}
//			if (CNWSCreatureStats__HasFeat(Defender->cre_stats, NULL, 10)) {
//				if (Defender->cre_attack_target == oidAttacker) {
//					iDodge_AC += 2;
//				}
//			}
//
//			if (iDodge_AC > 0) _log(3, "iDodge_AC: %d\n", iDodge_AC);
//
//			int iTumbleRanks = CNWSCreatureStats_GetSkillRank(Defender->cre_stats, NULL, 21, 0, 1);
//			if (iTumbleRanks > 0) {
//				iTumble_AC = iTumbleRanks / 5;
//			}
//
//			if (iTumble_AC > 0) _log(3, "iTumble_AC: %d\n", iTumble_AC);
//
//			iDodge_AC += iTumble_AC;
//		}
//	}
//	else {
//		_log(3, "Dex (and dodge) bonus denied\n");
//	}
//
//	
//	/************************ Dex Modifier & Dodge Modifiers *********************/
//
//	if (CNWSCreatureStats__HasFeat(Defender->cre_stats, NULL, 233) && Attacker->cre_stats->cs_race == 18) { //Giant Training
//		iDefensiveTaining_AC = 4;
//	}
//
//	if (iDefensiveTaining_AC > 0) _log(3, "iDefensiveTaining_AC: %d\n", iDefensiveTaining_AC);
//
//
//	/************************ Experitse Modifiers *********************/
//
//	if (Defender->cre_mode_combat == 7) iExpertise_AC = 5;
//	else if (Defender->cre_mode_combat == 8) iExpertise_AC = 10;
//
//	if (iExpertise_AC > 0) _log(3, "iExpertise_AC: %d\n", iExpertise_AC);
//
//
//	/************************ Modifiers *********************/
//	
//	int ac_natural_penalty = Defender->cre_stats->cs_ac_natural_penalty;
//	int ac_natural_bonus = Defender->cre_stats->cs_ac_natural_bonus;
//	int ac_armor_penalty = Defender->cre_stats->cs_ac_armour_penalty;
//	int ac_armor_bonus = Defender->cre_stats->cs_ac_armour_bonus;
//	int ac_shield_penalty = Defender->cre_stats->cs_ac_shield_penalty;
//	int ac_shield_bonus = Defender->cre_stats->cs_ac_shield_bonus;
//	int ac_deflection_penalty = Defender->cre_stats->cs_ac_deflection_penalty;
//	int ac_dodge = NULL;                              // is still 0
//	int ac_deflection_bonus = Defender->cre_stats->cs_ac_deflection_bonus;
//
//	if (bTouchAttack) {
//		ac_natural_bonus = 0;
//		ac_natural_penalty = 0;
//		ac_armor_bonus = 0;
//		ac_armor_penalty = 0;
//		ac_shield_bonus = 0;
//		ac_shield_penalty = 0;
//	}
//
//	CNWSCreatureStats *Attacker_stats = Attacker->cre_stats;
//
//	int Attacker_LawChaos_absolute;
//	int Attacker_LawChaos = Attacker_stats->cs_al_lawchaos;
//	if (Attacker_LawChaos > 30) Attacker_LawChaos_absolute = (Attacker_LawChaos >= 70)+1;
//	else Attacker_LawChaos_absolute = 3;
//
//	int Attacker_GoodEvil_absolute;
//	int Attacker_GoodEvil = Attacker_stats->cs_al_lawchaos;
//	if (Attacker_GoodEvil > 30) Attacker_GoodEvil_absolute = (((Attacker_GoodEvil < 70) - 1) & 3)+1;
//	else Attacker_GoodEvil_absolute = 5;
//
//	int Attacker_Race = Attacker->cre_stats->cs_race;
//
//	short int DamageFlags = CNWSCreature_GetDamageFlags(Attacker, void);
//	
//	int Defender_EffectsLen = Defender->obj.obj_effects_len;
//	if (Defender_EffectsLen > 0) {
//		short int Defender_stats_field440 = Defender->cre_stats->field_440;
//		if (Defender_stats_field440 < Defender_effects_len) {
//			CGameEffect *Effect = NULL;
//			int ACInc_Type, ACInc_Value, ACInc_Value2, ACInc_vs_Race, ACInc_vs_LawChaos, ACInc_vs_GoodEvil, ACInc_vs_DamageType;
//			int b_vs_Race, b_vs_Alignment, b_vs_DamageType;
//			int EffectType_ACInc;
//
//
//			do {
//				Effect = Defender->obj.obj_effects[Defender_stats_field440];
//				if (Effect->eff_type == 48 || Effect->eff_type == 49) {
//					ACInc_Type = CGameEffect_GetInteger(Effect, NULL, 0);
//					ACInc_Value = CGameEffect_GetInteger(Effect, NULL, 1);
//					ACInc_vs_Race = CGameEffect_GetInteger(Effect, NULL, 2);
//					ACInc_vs_LawChaos = CGameEffect_GetInteger(Effect, NULL, 3);
//					ACInc_vs_GoodEvil = CGameEffect_GetInteger(Effect, NULL, 4);
//					ACInc_vs_DamageType = CGameEffect_GetInteger(Effect, NULL, 5);
//
//					if (ACInc_vs_Race != 28 || ACInc_vs_LawChaos || ACInc_vs_GoodEvil || ACInc_vs_DamageType != 4103) {
//						b_vs_Race = ACInc_vs_Race == 28 || ACInc_vs_race == Attacker_Race;
//			            
//						b_vs_Alignment = (!ACInc_vs_LawChaos || ACInc_vs_LawChaos == Attacker_LawChaos_absolute)
//                        && (!ACInc_vs_GoodEvil || ACInc_vs_GoodEvil == attacker_GoodEvil_absolute);
//						
//						b_vs_DamageType = ACInc_vs_DamageType == 4103 || ACInc_vs_DamageType & DamageFlags;
//
//						if (b_vs_Race && b_vs_Alignment && b_vs_DamageType) {
//							if (ACInc_Type == 0) {			//Dodge AC
//								EffectType_ACInc = 48;
//								ACInc_Value2 = ACInc_Value;
//								if (Effect->eff_type = 48)
//									ac_dodge += AC_IncValue;
//								else
//									ac_dodge -= AC_IncValue;
//							}
//							else {
//								ACInc_Value2 = ACInc_Value;
//								EffectType_ACInc = 48;
//							}
//							EffectType = Effect->eff_type;
//							if (EffectType == EffectType_ACInc) {
//								if (!bTouchAttack) {
//									if (ACInc_Type == 1) { //Natural AC
//										if (ACInc_Value2 > ac_natural_bonus)
//											ac_natural_bonus = ACInc_Value2;
//									}
//								}
//							}
//							else {
//
//
//
return 0;
}

CNWSCombatAttackData *CNWNXCombat::CNWSCombatRound__GetAttack(CNWSCombatRound *round, int nAttack) {
	if (nAttack < 50)
		return &round->AttackData[nAttack];

	return &round->AttackData[49];
}


int CNWNXCombat::NWN_GetAttackModifierVersus_Override(CNWSCreature *Attacker, CNWSObject* Defender) {
	if (Attacker == NULL) return 0;

	//_log(3, "Atk oid: %08X\tDef oid: %08X\n", Attacker->obj.obj_generic.obj_id, Defender->obj_generic.obj_id);

	int iMod = 0;
	int iAttackBonus = 0;

	CNWSItem *Weapon = NULL;
	CNWBaseItem *BaseWeapon = NULL;

	CNWSItem *Weapon2nd = NULL;
	CNWBaseItem *Base2nd = NULL;

	CNWSCreatureStats *AttackerStats = Attacker->cre_stats;
	CNWSCreatureStats *DefenderAsCreatureStats = NULL;

	CNWSCreature *DefenderAsCreature = NULL;
	if (Defender != NULL) {
		DefenderAsCreature = (CNWSCreature*)Defender;
		DefenderAsCreatureStats = DefenderAsCreature->cre_stats;
	}

	CNWSCombatRound *combatRound = Attacker->cre_combat_round;
	uint8_t CurrentAttack = Attacker->cre_combat_round->CurrentAttack;
	
	CNWSCombatAttackData *AttackData = CNWSCombatRound__GetAttack(Attacker->cre_combat_round, CurrentAttack);

	uint32_t bRangedAttack = AttackData->RangedAttack;
	uint8_t WeaponAttackType = AttackData->WeaponAttackType;
	Weapon = CNWSCombatRound__GetCurrentAttackWeapon(combatRound, NULL, WeaponAttackType);

	iMod = CNWSCreatureStats__GetBaseAttackBonus(AttackerStats, NULL, 0);

	if (Weapon != NULL) BaseWeapon = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Weapon->it_baseitemtype);

	if (WeaponAttackType == 2) {
		 iMod -= 5 * combatRound->OffHandTaken++;
	}
	else {
		if (WeaponAttackType == 6 || WeaponAttackType == 8) {
			if (AttackData->AttackType != 867 //whirlwind
				&& AttackData->AttackType != 868 //improved whirlwind
				&& AttackData->AttackType != 391) { //great cleave
				iMod += 5* combatRound->ExtraTaken;
			}
			++combatRound->ExtraTaken;
		}
		else if (AttackData->AttackType != 0xFDEA //Attack of Opportunity
		&& AttackData->AttackType != 6 //cleave
		&& AttackData->AttackType != 391 //great cleave
		) {
			if (CNWSCreatureStats__GetUseMonkAttackTables(AttackerStats, NULL, 0))
				iMod -= 3 * CurrentAttack;
			else
				iMod -= 5 * CurrentAttack;
		}
	}

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "Bab: %d\n", iMod);
	}



	/************************ iTwoWeaponFightingPenalty *********************/

	iMod=0;

	//apply penalties if: 
	//	offHand weapon equipped
	//	mainHand weapon is double sided

	Weapon2nd = CNWSInventory__GetItemInSlot(Attacker->cre_equipment, NULL, 0x20);
	if (!Weapon2nd) {
		Weapon2nd = CNWSInventory__GetItemInSlot(Attacker->cre_equipment, NULL, 0x10);
		if (Weapon2nd) {
			Base2nd = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Weapon2nd->it_baseitemtype);
			if (Base2nd) {
				if (Base2nd->WeaponWield != 8)
					Weapon2nd = NULL;
			}
		}
	}

	if (Weapon2nd) {
		if (WeaponAttackType == 1) {
			Base2nd = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Weapon2nd->it_baseitemtype);
			if (Base2nd->WeaponType) {
				iMod = -6;
				if ((CNWSCreature__GetRelativeWeaponSize(Attacker, NULL, Weapon2nd) <= -1) || Base2nd->WeaponWield == 8)
					iMod = -4;
				if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 41)) //FEAT_TWO_WEAPON_FIGHTING
					iMod += 2;
				if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, CustomFeats.FEAT_ABSOLUTE_AMBIDEXTERITY ))
					iMod += 2;
			}
		}
		else if (WeaponAttackType == 2) {
			Base2nd = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Weapon2nd->it_baseitemtype);
			if (Base2nd) {
				iMod = -10;
				if ((CNWSCreature__GetRelativeWeaponSize(Attacker, NULL, Weapon2nd) <= -1) || BaseWeapon->WeaponWield == 8)
					iMod = -8;
				if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 1)) //FEAT_AMBIDEXTERITY
					iMod += 4;
				if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 41)) //FEAT_TWO_WEAPON_FIGHTING
					iMod += 2;
				if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, CustomFeats.FEAT_ABSOLUTE_AMBIDEXTERITY ))
					iMod += 2;
			}
		}
		iAttackBonus += iMod;
		_log(3, "iTwoWeaponFighting_Mod: %d\n", iMod);
	}

		
	/************************ Size Modifiers *********************/

	iMod = 3 - Attacker->cre_size;

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iSize_Mod: %d\n", iMod);
	}


	/************************ Combat Mode Modifiers *********************/

	iMod = 0;
	switch(Attacker->cre_mode_combat) {
		case 2: iMod = -5; break;
		case 3: iMod = -10; break;
		case 5: iMod = -2; break;
		case 6: iMod = -2; break;
		case 7: iMod = -5; break;
		case 8: iMod = -10; break;
	}

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iCombatMode_Mod: %d\n", iMod);
	}


	/************************ Special Attack Modifiers *********************/

	iMod = CNWSCreatureStats__ResolveSpecialAttackAttackBonus(Attacker->cre_stats, NULL, DefenderAsCreature);

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iSpecialAttack_Mod: %d\n", iMod);
	}


	/************************ Nature Sense Modifier *********************/

	iMod = 0;
	unsigned char area = *(unsigned char *)(CNWSObject__GetArea((CNWSObject*)Attacker, NULL) + 4);
	if (area && (area & 4 || area & 1 || area & 2) && CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 198))
		iMod = 2;

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iNatureSense_Mod: %d\n", iMod);
	}


	/************************ Epic Prowess Modifier *********************/

	iMod = 0;
	if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 584))
		iMod = 1;

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iEpicProwess_Mod: %d\n", iMod);
	}


	/************************ Weapon Master Modifier *********************/

	iMod = 0;
	if (Weapon != NULL) {
		int bWeaponOfChoice = 0;
		if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 884)
		&& (bWeaponOfChoice = CNWSCreatureStats__GetIsWeaponOfChoice(Attacker->cre_stats, NULL, Weapon->it_baseitemtype))) {
			iMod = 1;
			bWeaponOfChoice = 1;
		}
		if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 1071) && bWeaponOfChoice) {
			// get the weapon master levels
			for (int i = 0; i<3; i++) {
				if (AttackerStats->cs_classes[i].cl_class != 33)
					continue;

				int SuperiorWeaponFocus = (int)((AttackerStats->cs_classes[i].cl_level - 10) / 3);

				iMod += SuperiorWeaponFocus > 0 ? SuperiorWeaponFocus : 0;
			}
		}

		if (iMod) {
			iAttackBonus += iMod;
			_log(3, "iWeaponMaster_Mod: %d\n", iMod);
		}
	}


	/************************ Favored Enemy Modifier *********************/

	if (DefenderAsCreature != NULL) {
		iMod=0;
		if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 855)) { //FEAT_EPIC_BANE_OF_ENEMIES
			if (CNWSCreatureStats__GetFavoredEnemyBonus(Attacker->cre_stats, NULL, DefenderAsCreature)) {
				iMod = 2;
			}
			if (iMod) {
				iAttackBonus += iMod;
				_log(3, "iFavoredEnemy_Mod: %d\n", iMod);
			}
		}
	}

	/************************ Good Aim Modifier *********************/

	iMod = (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 250) && BaseWeapon && BaseWeapon->WeaponWield == 11);

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iGoodAim_Mod: %d\n", iMod);
	}


	/************************ Halfling Sling Modifier *********************/

	iMod =  (AttackerStats->cs_race == 3 && Weapon && Weapon->it_baseitemtype == 61);

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iHalflingSling_Mod: %d\n", iMod);
	}


	/************************ Enchant Arrow Modifier *********************/

	iMod = 0;
	if (Weapon && (Weapon->it_baseitemtype == 8 || Weapon->it_baseitemtype == 11)) {
		for (int i=1059; i<=1045; i--) {
			if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, i)) {
				iMod = i-1039;
				break;
			}
		}
		if (!iMod) {
			for (int i=449; i<=445; i--) {
				if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, i)) {
					iMod = i-444;
					break;
				}
			}
		}
		if (iMod) {
			iAttackBonus += iMod;
			_log(3, "iEnchantArrow_Mod: %d\n", iMod);
		}
	}


	/************************ Offensive Training Modifier *********************/

	if (DefenderAsCreature != NULL) {
		iMod=0;
		if ((CNWSCreatureStats__HasFeat(AttackerStats, NULL, 232) && DefenderAsCreatureStats->cs_race == 12)
			|| (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 231) && DefenderAsCreatureStats->cs_race == 14)
			|| (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 242) && DefenderAsCreatureStats->cs_race == 15)
		) {
			iMod = 1;

			if (iMod) {
				iAttackBonus += iMod;
				_log(3, "iOffensiveTraining_Mod: %d\n", iMod);
			}
		}
	}


	/************************ Ability Modifier *********************/

	iMod = 0;
	if (bRangedAttack) {
		if (CNWSCreatureStats__HasFeat(AttackerStats, NULL, 412)) {
			int iDexMod = CNWSCreatureStats__GetDEXMod(AttackerStats, NULL, 0);
			iMod = iDexMod > AttackerStats->cs_wis_mod ? iDexMod : AttackerStats->cs_wis_mod;
		}
		else {
			iMod = CNWSCreatureStats__GetDEXMod(AttackerStats, NULL, 0);
		}
	}
	else {
		if (NWN_GetWeaponFinesse(AttackerStats, Weapon)) {
			int iDexMod = CNWSCreatureStats__GetDEXMod(AttackerStats, NULL, 0);
			iMod = iDexMod > AttackerStats->cs_str_mod ? iDexMod : AttackerStats->cs_str_mod;
		}
		else {
			iMod = AttackerStats->cs_str_mod;
		}
	}

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iAbility_Mod: %d\n", iMod);
	}


	/************************ Epic / Weapon Focus Modifier *********************/

	if (iMod = CNWSCreatureStats__GetWeaponFocus(AttackerStats, NULL, Weapon)) {
		iAttackBonus += 1;
		_log(3, "iWeaponFocus_Mod: %d\n", iMod);
	}

	if (iMod = 2*CNWSCreatureStats__GetEpicWeaponFocus(AttackerStats, NULL, Weapon)) {
		iAttackBonus += 2;
		_log(3, "iEpicWeaponFocus_Mod: %d\n", iMod);
	}


	/************************ TotalEffectBonus Modifier *********************/

	iMod = 0;
	if (DefenderAsCreature != NULL) {
		iMod = 
			CNWSCreature__GetTotalEffectBonus(
			Attacker,
			NULL,
			1,
			(CNWSObject *)(*(int (__thiscall **)(CNWSCreature *))(DefenderAsCreature->obj.obj_generic.obj_type + 16))(DefenderAsCreature),
			0, 0, 0, 0, -1, -1, 0);
	}
	else {
		iMod = 
			CNWSCreature__GetTotalEffectBonus(
			Attacker,
			NULL,
			1, 0, 0, 0, 0, 0, -1, -1, 0);
	}

	if (iMod) {
		iAttackBonus += iMod;
		_log(3, "iTotalEffect_Mod: %d\n", iMod);
	}


	/************************ Blind Defender Modifier *********************/

	if (DefenderAsCreature != NULL) {
		iMod=0;
		if (CNWSCreature__GetBlind(DefenderAsCreature, NULL) 
			&& (bRangedAttack || !CNWSCreatureStats__HasFeat(DefenderAsCreatureStats, NULL, 408))) {
			iMod = 2;

			if (iMod) {
				iAttackBonus += iMod;
				_log(3, "iBlindDefender_Mod: %d\n", iMod);
			}
		}
	}


	/************************ Invisible Attacker Modifier *********************/

	if (DefenderAsCreature != NULL) {
		iMod=0;
		CNWSObject *obj_bInvisible = (CNWSObject *)(*(int (__thiscall **)(CNWSCreature *))(AttackerStats->cs_original->obj.obj_generic.obj_type + 16))(AttackerStats->cs_original);
		if (CNWSCreature__GetInvisible(Attacker, NULL, obj_bInvisible, 0)
			&& (bRangedAttack || !CNWSCreatureStats__HasFeat(DefenderAsCreatureStats, NULL, 408))
		) {
			iMod = 2;
		}

		if (iMod) {
			iAttackBonus += iMod;
			_log(3, "iInvisAttacker_Mod: %d\n", iMod);
		}
	}


	/************************ Can't see target Modifier *********************/

	if (Defender != NULL) {
		iMod=0;
		CNWVisibilityNode *obj_GetVisibleElement = CNWSCreature__GetVisibleListElement(Attacker, NULL, Defender->obj_generic.obj_id);
		if ( !obj_GetVisibleElement || !((unsigned int)obj_GetVisibleElement[1].unknown & 1) ) {
			iMod = -4;

			if (iMod) {
				iAttackBonus += iMod;
				_log(3, "iCantSeeTarget_Mod: %d\n", iMod);
			}
		}
	}

	/************************ Target States (Animation) Modifier *********************/

	if (DefenderAsCreature != NULL) {
		iMod=0;
		int DefenderState = DefenderAsCreature->obj.obj_anim;

		int ProneMod = 0, MovingPenalty = 0, StunnedMod = 0;

		if (bRangedAttack) { //Ranged Attack
			if ( DefenderState == 4 || DefenderState == 87 || DefenderState == 86 ) //Target Moving
				iMod = -2;
			else if ( DefenderState == 36 || DefenderState == 33 || DefenderState == 32 || DefenderState == 7 || DefenderState == 5 ) { //Target Prone
				iMod = -4;
			}
		}
		else {
			if ( DefenderState == 36 || DefenderState == 33 || DefenderState == 32 || DefenderState == 7 || DefenderState == 5 ) { //Taget Prone
				iMod = 4;
			}
		}
		if ( DefenderAsCreature->cre_state == 6 ) //stunned?
			iMod += 2;


		if (iMod) {
			iAttackBonus += iMod;
			_log(3, "iTargetState_Mod: %d\n", iMod);
		}
	}


	/************************ Distance Calculation, gonna need that more than once *********************/

	float fDistance=0.0;
	if (Defender != NULL) {
		Vector posAttacker = Attacker->obj.obj_position;
		Vector posDefender = Defender->obj_position;

		posAttacker.x -= posDefender.x;
		posAttacker.y -= posDefender.y;
		posAttacker.z -= posDefender.z;

		posAttacker.x *= posAttacker.x;
		posAttacker.y *= posAttacker.y;
		posAttacker.z *= posAttacker.z;
		
		fDistance = sqrt(posAttacker.x+posAttacker.y+posAttacker.z);

		_log (3, "Distance: %f\n", fDistance);
	}


	/************************ Target Flanked Modifier *********************/

	if (DefenderAsCreature) {
		iMod=0;
		if (CNWSCreature__GetFlanked(Attacker, NULL, DefenderAsCreature) == 1) {
			if (bRangedAttack || fDistance < 9.144) {
				// on ranged sneak attack the distance between Attacker and Defender must be <= 9.144m
				iMod = 2;
			}

			if (iMod) {
				iAttackBonus += iMod;
				_log(3, "iTargetFlanked_Mod: %d\n", iMod);
			}
		}
	}


	/************************ Point Blank Shot Modifier *********************/

	if (DefenderAsCreature) {
		iMod=0;
		if (bRangedAttack) {
			if (fDistance <= 4.572) {
				if (CNWSCreatureStats__HasFeat(Attacker->cre_stats, NULL, 27)) { //+1 if within 15 ft with Point Blank Shot feat
					iMod = 1;
				}
				else {
					float maxAttackRange = CNWSCreature__MaxAttackRange(Attacker, NULL, Defender->obj_generic.obj_id, 0, 0);
					if (maxAttackRange * maxAttackRange >= fDistance) {
						if (!CNWSCreature__GetRangeWeaponEquipped(DefenderAsCreature, NULL)) {
							iMod = -4;
						}
					}
				}
			}
			if (iMod) {
				iAttackBonus += iMod;
				_log(3, "iRanged_Mod: %d\n", iMod);
			}
		}
	}

	/************************ Enemy Attack Modifier *********************/
	// no clue what this is either

	if(DefenderAsCreature) {
		iMod = DefenderAsCreatureStats->field_413;

			if (iMod) {
				iAttackBonus += iMod;
				_log(3, "iEnemyAttack_Mod: %d\n", iMod);
			}
	}


	_log(3, "Final Attack Modifier: \t%d\n", iAttackBonus);
	return iAttackBonus;
}

int CNWNXCombat::NWN_GetMeleeAttackBonus(CNWSCreatureStats *CreatureStats, int a2, int a3, int a4) {
	_log (3, "a2: %d\ta3: %d\ta4: %d\n", a2, a3, a4);
	if (CreatureStats == NULL) return 0;
	CNWSItem *Item_1, *Item_2;
	CNWSCreature *cre = CreatureStats->cs_original;
	CNWBaseItem *BaseItem = NULL;

	int iAttackBonus = 0;


	if(!a2
		|| (Item_1 = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x20), !Item_1)
		&& (Item_2 = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x10), 
			(BaseItem = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Item_2->it_baseitemtype)) != 0)
		&& BaseItem->WeaponWield == 8)
		Item_1 = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x10);
	
	if (NWN_GetWeaponFinesse(CreatureStats, Item_1)
		|| CNWSCreatureStats__GetDEXMod(CreatureStats, NULL, 0) <= CreatureStats->cs_str_mod
		|| a4)
		iAttackBonus = CreatureStats->cs_str_mod;
	else
		iAttackBonus = CNWSCreatureStats__GetDEXMod(CreatureStats, NULL, 0);


/////////////

	if (a3 == 1) {
		if (a4) {
			iAttackBonus += CNWSCreature__GetTotalEffectBonus(
			cre,
			NULL,
			6, NULL, 0, 0, 0, 0, -1, -1, a2);
		}
		else {
			iAttackBonus += CNWSCreature__GetTotalEffectBonus(
			cre,
			NULL,
			1, NULL, 0, 0, 0, 0, -1, -1, a2);
		}
	}

//////////

	iAttackBonus += CNWSCreatureStats__GetBaseAttackBonus(CreatureStats, NULL, 0);

/////////////

	if (Item_1 && CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Item_1->it_baseitemtype)->RangedWeapon) {
		return a4 != 0 ? iAttackBonus : 0;
	}

//////////////

	if (a4 != 1) {
		if (CNWSCreatureStats__GetWeaponFocus(CreatureStats, NULL, Item_1)) {
			iAttackBonus += 1;
		}
	}
	else if (!Item_1 && CNWSCreatureStats__GetWeaponFocus(CreatureStats, NULL, NULL)) {
		iAttackBonus += 1;
	}

	if (a4 != 1) {
		if (CNWSCreatureStats__GetEpicWeaponFocus(CreatureStats, NULL, Item_1)) {
			iAttackBonus += 1;
		}
	}
	else if (!Item_1 && CNWSCreatureStats__GetEpicWeaponFocus(CreatureStats, NULL, NULL)) {
		iAttackBonus += 1;
	}

////////////////

	if (CNWSObject__GetArea((CNWSObject*)cre, NULL)) {
		if ( *(uint8_t *)(CNWSObject__GetArea((CNWSObject*)cre, NULL) + 4) & 4 ) {
			if ( !(*(uint8_t *)(CNWSObject__GetArea((CNWSObject*)cre, NULL) + 4) & 1) ) {
				if ( !(*(uint8_t *)(CNWSObject__GetArea((CNWSObject*)cre, NULL) + 4) & 2) ) {
					if ( CNWSCreatureStats__HasFeat(CreatureStats, NULL, 198) )
						iAttackBonus += 2;
				}
			}
		}
	}

///////////////

	if (CNWSCreatureStats__HasFeat(CreatureStats, NULL, 584))
		++iAttackBonus;

///////////////

	if (a4)
		return iAttackBonus;
	
//////////////

	int bWeaponOfChoice = 0;
	if (Item_1) {
		if (CNWSCreatureStats__HasFeat(CreatureStats, NULL, 884)) {
			if ((bWeaponOfChoice = CNWSCreatureStats__GetIsWeaponOfChoice(CreatureStats, NULL, Item_1->it_baseitemtype)))
				++iAttackBonus;
		}
	}
	if (CNWSCreatureStats__HasFeat(CreatureStats, NULL, 1071) && bWeaponOfChoice) {
		// get the weapon master levels
		for (int i = 0; i<3; i++) {
			if (CreatureStats->cs_classes[i].cl_class != 33)
				continue;

			int SuperiorWeaponFocus = (int)((CreatureStats->cs_classes[i].cl_level - 10) / 3);

			iAttackBonus += SuperiorWeaponFocus > 0 ? SuperiorWeaponFocus : 0;
		}
	}

///////////////

	Item_1 = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x20);
	if (!Item_1) {
		Item_1 = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x10);
		if (Item_1) {
			BaseItem = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Item_1->it_baseitemtype);
			if (BaseItem) {
				if (BaseItem->WeaponWield != 8)
					Item_1 = NULL;
			}
		}
	}

	int iMod=0;

	if (!Item_1) {
		_log(3, "no two weapon fighting\n");
		return iAttackBonus;
	}
	else {
		if (a2) {
			BaseItem = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Item_1->it_baseitemtype);
			if (!BaseItem) return iAttackBonus;

			iMod = -10;
			if ((CNWSCreature__GetRelativeWeaponSize(cre, NULL, Item_1) <= -1) || BaseItem->WeaponWield == 8)
				iMod = -8;
			if (CNWSCreatureStats__HasFeat(CreatureStats, NULL, 1)) //FEAT_AMBIDEXTERITY
				iMod += 4;
			if (CNWSCreatureStats__HasFeat(CreatureStats, NULL, 41)) //FEAT_TWO_WEAPON_FIGHTING
				iMod += 2;
		}
		else {
			BaseItem = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Item_1->it_baseitemtype);
			if (!BaseItem || !BaseItem->WeaponType) return iAttackBonus;

			iMod = -6;
			if ((CNWSCreature__GetRelativeWeaponSize(cre, NULL, Item_1) <= -1) || BaseItem->WeaponWield == 8)
				iMod = -4;
			if (CNWSCreatureStats__HasFeat(CreatureStats, NULL, 41)) //FEAT_TWO_WEAPON_FIGHTING
				iMod += 2;
		}
	}

	iAttackBonus += iMod;
	return iAttackBonus;
}

int CNWNXCombat::NWN_GetWeaponFinesse(CNWSCreatureStats *Stats, CNWSItem *Item) {
	_log(3, "NWN_WeaponFinesse [Stats: %08X | item: %08X]\n", Stats, Item);

	if (Item) {
		//Katana Finesse
		_log(3, "base: %d\n", Item->it_baseitemtype);
		if (Item->it_baseitemtype == 41) {
			loghasfeat = 1;
			_log(3, "KatanaFinesseFeat?: %d\n", CNWSCreatureStats__HasFeat(Stats, NULL, CustomFeats.FEAT_KATANA_FINESSE));
			loghasfeat = 0;
			if (NWN_HasFeat(Stats, CustomFeats.FEAT_KATANA_FINESSE) && CNWSCreature__GetRelativeWeaponSize(Stats->cs_original, NULL, Item) <= 0) return 1;
			else return 0;
		}
	}

	if (!CNWSCreatureStats__HasFeat(Stats, NULL, 42))//Weapon Finesse
		return 0;
	if (Item) {
		int BaseItemType = Item->it_baseitemtype;
		if (BaseItemType != 78) { //bracers
			if (BaseItemType != 36 && BaseItemType != 69 && BaseItemType != 70 && BaseItemType != 71 && BaseItemType != 72) { //gloves and creature weapons
				CNWSCreature *cre = Stats->cs_original;
				if (cre->cre_size > 2) {
					if (BaseItemType != 51 && BaseItemType != 111 && CNWSCreature__GetRelativeWeaponSize(cre, NULL, Item) >= 0
						|| BaseItemType == 51 && CNWSCreature__GetRelativeWeaponSize(cre, NULL, Item) > 0)
						return 0;
				}
				else {
					if (CNWSCreature__GetRelativeWeaponSize(cre, NULL, Item) > 0)
						return 0;
				}
				if (BaseItemType != 22 && BaseItemType != 9 && BaseItemType != 60 && BaseItemType != 37
					&& BaseItemType != 38 && BaseItemType && BaseItemType != 51 && BaseItemType != 42
					&& BaseItemType != 40 && BaseItemType != 111)
					return 0;
			}
		}
	}
	return 1;
}

int CNWNXCombat::NWN_CalculateOffHandAttacks(CNWSCombatRound *CombatRound) {
	CNWSCreature *cre = CombatRound->org_nwcreature;
	CNWSItem *Item = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x10);
	CNWBaseItem *BaseItem = NULL;

	if (Item)
		CNWBaseItem *BaseItem = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Item->it_baseitemtype);
	CombatRound->OffHandAttacks = 0;

	_log(3, "Creature: %08X\tItem: %08X\n", cre, Item);

	if ( Item && !BaseItem->RangedWeapon) {
		_log(3, "not ranged [%d]\n", Item->it_baseitemtype);
		_log(3, "WeaponSize-CreSize [%d - %d = %d]\n", BaseItem->WeaponSize, cre->cre_size, BaseItem->WeaponSize - cre->cre_size);
		if (((int8_t)(BaseItem->WeaponSize - cre->cre_size)) > 0) { // means they can't have anything equipped in the off hand
			_log(3, "OnHandItem: WeaponType: %d\tWeaponWield: %d\n", BaseItem->WeaponType, BaseItem->WeaponWield);
			if (BaseItem->WeaponWield == 8) {
				CombatRound->OffHandAttacks = 1;
			}
		}
		else {
			Item = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x20);
			if (Item) BaseItem = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, Item->it_baseitemtype);
			_log(3, "OffhandItem: WeaponType: %d\tWeaponWield: %d\n", BaseItem->WeaponType, BaseItem->WeaponWield);
			if (Item && BaseItem->WeaponType && BaseItem->WeaponWield != 7) { //WeaponType := does damage && no shields
				CombatRound->OffHandAttacks = 1;
			}
		}

		_log(3, "CombatRound->OffHandAttacks before feats: %d\n", CombatRound->OffHandAttacks);

		if (CombatRound->OffHandAttacks > 0) {
			if (CNWSCreatureStats__HasFeat(cre->cre_stats, NULL, CustomFeats.FEAT_SUPREME_TWO_WEAPON_FIGHTING))
				CombatRound->OffHandAttacks = 4;
			else if (CNWSCreatureStats__HasFeat(cre->cre_stats, NULL, CustomFeats.FEAT_GREATER_TWO_WEAPON_FIGHTING))
				CombatRound->OffHandAttacks = 3;
			else if (CNWSCreatureStats__HasFeat(cre->cre_stats, NULL, 20))  //Improved two weapon fighting
				CombatRound->OffHandAttacks = 2;
			
			if (CNWSCreatureStats__HasFeat(cre->cre_stats, NULL, CustomFeats.FEAT_PERFECT_TWO_WEAPON_FIGHTING))
				CombatRound->OffHandAttacks = CombatRound->OnHandAttacks > CombatRound->OffHandAttacks ? CombatRound->OnHandAttacks : CombatRound->OffHandAttacks;
		}
	}

	return CombatRound->OffHandAttacks;
}

int CNWNXCombat::NWN_HasFeat(CNWSCreatureStats *Stats, uint16_t FeatId) {
	if (loghasfeat) _log(3, "Feat check: %d\n", FeatId);
	CNWSPlayer *pl = CServerExoApp__GetClientObjectByObjectId((*NWN_AppManager)->app_server, NULL, Stats->cs_original->obj.obj_generic.obj_id);
	if (!pl || (CNWSPlayer__HasExpansionPack(pl, NULL, CNWRules__GetFeatExpansionLevel(*NWN_Rules, NULL, FeatId), 1)) != 0) {

		uint32_t Feats_len = Stats->cs_feats.len;
		uint32_t i=0;
		while (i < Feats_len) {
			if (Stats->cs_feats.data[i] == FeatId) return 1;
			i++;
		}

		Feats_len = Stats->cs_skin_feats.len;
		i=0;
		while (i < Feats_len) {
			if (Stats->cs_skin_feats.data[i] == FeatId) return 1;
			i++;
		}

		if (FeatId == 1 || FeatId == 42) { // make sure we have a ranger and they have no medium or heavy armor on
			CNWSItem *Item = CNWSInventory__GetItemInSlot(Stats->cs_original->cre_equipment, NULL, 2);
			if (Stats->cs_classes_len > 0) {
				int ClassType=0;
				i=0;
				while (i < Stats->cs_classes_len) {
					if (Stats->cs_classes[i].cl_class == 7) break;
					++i;
				}
				if (i < Stats->cs_classes_len) {
					if (!Item || CNWSItem__ComputeArmorClass(Item, NULL) < 4) return 1;
				}
			}
		}

		// Tempest
		else if (FeatId == 20 //Improved two weapon fighting
			||	 FeatId == CustomFeats.FEAT_GREATER_TWO_WEAPON_FIGHTING
			||	 FeatId == CustomFeats.FEAT_SUPREME_TWO_WEAPON_FIGHTING
			||   FeatId == CustomFeats.FEAT_ABSOLUTE_AMBIDEXTERITY
		) {
			CNWSItem *Item = CNWSInventory__GetItemInSlot(Stats->cs_original->cre_equipment, NULL, 2);
			if (!Item || CNWSItem__ComputeArmorClass(Item, NULL) < 4) {
				if (Stats->cs_classes_len > 0) {
					int ClassType=0;
					int iTempestLevel = 0;
					int iRangerLevel = 0;
					i=0;
					while (i < Stats->cs_classes_len) {
						if (Stats->cs_classes[i].cl_class == CustomClasses.CLASS_TYPE_TEMPEST) iTempestLevel = Stats->cs_classes[i].cl_level;
						else if (Stats->cs_classes[i].cl_class == 7) iRangerLevel = Stats->cs_classes[i].cl_level;
						++i;
					}
					if (FeatId == 20 && (iTempestLevel > 0)) return 1;
					else if (FeatId == CustomFeats.FEAT_GREATER_TWO_WEAPON_FIGHTING && iTempestLevel >= 5) return 1;
					else if (FeatId == CustomFeats.FEAT_SUPREME_TWO_WEAPON_FIGHTING && iTempestLevel >= 10) return 1;
					else if (FeatId == CustomFeats.FEAT_ABSOLUTE_AMBIDEXTERITY && iTempestLevel >= 8) return 1;
				}
			}
		}
	}
	return 0;
}

void CNWNXCombat::LoadCombatFeats() {
	_log(1, "o LoadCombatFeats\n");
	CExoString exostr("weaponfeats");
	CResRef *ResRef = (CResRef*)malloc(16); memset(ResRef, 0, 16);
	ResRef = CResRef__CResRef(ResRef, NULL, exostr);
	
	C2DA *TwoDA = (C2DA*)malloc(60); memset(TwoDA, 0, 60);
	TwoDA = C2DA__C2DA(TwoDA, NULL, *ResRef, 0);

	C2DA__Load2DArray(TwoDA, NULL);

	exostr = "BaseItem";
	CExoString col;
	CExoString Test;
	int ret=0;
	int i=0;
	int iRows = TwoDA->tda_rows_len;
	int BaseItem=0;

	while (i < iRows) {
		if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, exostr, &BaseItem)) {
			col = "WeaponFocus";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_WeaponFocus[BaseItem] = ret+1; else M_WeaponFocus[BaseItem] = -1;
			col = "EpicWeaponFocus";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_EPWeaponFocus[BaseItem] = ret+1; else M_EPWeaponFocus[BaseItem] = -1;
			col = "WeaponSpec";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_WeaponSpec[BaseItem] = ret+1; else M_WeaponSpec[BaseItem] = -1;
			col = "EpicWeaponSpec";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_EpWeaponSpec[BaseItem] = ret+1; else M_EpWeaponSpec[BaseItem] = -1;
			col = "ImprovedCrit";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_ImprovedCrit[BaseItem] = ret+1; else M_ImprovedCrit[BaseItem] = -1;
			col = "OverwhelmingCrit";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_OverwhelmingCrit[BaseItem] = ret+1; else M_OverwhelmingCrit[BaseItem] = -1;
			col = "DevCrit";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_DevCrit[BaseItem] = ret+1; else M_DevCrit[BaseItem] = -1;
			col = "WeaponOfChoice";
			if (C2DA__GetINTEntry_strcol(TwoDA, NULL, i, col, &ret)) M_WeaponOfChoice[BaseItem] = ret+1; else M_WeaponOfChoice[BaseItem] = -1;
		}
		++i;
	}

	WeaponFeats.push_back(M_WeaponFocus);
	WeaponFeats.push_back(M_EPWeaponFocus);
	WeaponFeats.push_back(M_WeaponSpec);
	WeaponFeats.push_back(M_EpWeaponSpec);
	WeaponFeats.push_back(M_ImprovedCrit);
	WeaponFeats.push_back(M_OverwhelmingCrit);
	WeaponFeats.push_back(M_DevCrit);
	WeaponFeats.push_back(M_WeaponOfChoice);

	C2DA__vect_destructor(TwoDA, NULL, 1);
	free(ResRef);

}

int CNWNXCombat::NWN_GetWeaponFeat(CNWSCreatureStats *Stats, CNWSItem *Item, int iPos) {
	int iRet = 0;
	if (Item) {
		int iFeat = WeaponFeats[iPos][Item->it_baseitemtype]-1;
		if (iFeat > 0) {
			iRet = NWN_HasFeat(Stats, iFeat);
		}
	}
	else {
		switch (iPos) {
			case 0: iRet = NWN_HasFeat(Stats, 100); break;
			case 1: iRet = NWN_HasFeat(Stats, 630); break;
			case 2: iRet = NWN_HasFeat(Stats, 138); break;
			case 3: iRet = NWN_HasFeat(Stats, 668); break;
			case 4: iRet = NWN_HasFeat(Stats, 62); break;
			case 5: iRet = NWN_HasFeat(Stats, 720); break;
			case 6: iRet = NWN_HasFeat(Stats, 506); break;
			case 7: iRet = 0; break;
		}
	}
	return iRet;
}