#include "stdafx.h"
#include "CNssCreature.h"
#include "math.h"

CNssCreature::CNssCreature(void) {
	AddFunction("SETCREATURESIZE", L_CAST(&CNssCreature::SetCreatureSize));
	AddFunction("GETEQUIPPEDWEIGHT", L_CAST(&CNssCreature::GetEquippedWeight));
	AddFunction("SETGOLD", L_CAST(&CNssCreature::SetGold));
	AddFunction("SETSOUNDSETID", L_CAST(&CNssCreature::SetSoundSetID));
	AddFunction("GETSOUNDSETID", L_CAST(&CNssCreature::GetSoundSetID));
	AddFunction("JUMPTOLIMBO", L_CAST(&CNssCreature::JumpToLimbo));
	AddFunction("SUMMONASSOCIATE", L_CAST(&CNssCreature::SummonAssociate)); //not implemented in nwnx_funcs.nss yet
	AddFunction("GETATTACKMODIFIERVERSUS", L_CAST(&CNssCreature::GetAttackModifierVs));

}

int CNssCreature::SetCreatureSize(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetCreatureSize used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint32_t Size = 0;
	CParams::ExtractP1(Params, Size);
	
	cre->cre_size = Size;

	return 1;
}

int CNssCreature::GetEquippedWeight(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetEquippedWeight used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", cre->cre_equipped_weight);
	return 1;
}

int CNssCreature::SetGold(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetGold used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint32_t Gold = 0;
	CParams::ExtractP1(Params, Gold);

	cre->cre_gold = Gold;

	return 1;
}

int CNssCreature::GetSoundSetID(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetSoundSetID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", cre->cre_soundset);

	return 1;
}

int CNssCreature::SetSoundSetID(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetSoundSetID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint16_t SoundSet = 0;
	CParams::ExtractP1(Params, SoundSet);

	cre->cre_soundset = SoundSet;

	return 1;
}

int CNssCreature::JumpToLimbo(CGameObject *oObject, char *Params) {
	sprintf(Params, "");

	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error JumpToLimbo used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSModule *mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule(); 

	if (mod != NULL && cre != NULL) {
		cre->RemoveFromArea(0);
		mod->AddObjectToLimbo(cre->obj_id);
	}
	return 1;
}

int CNssCreature::SummonAssociate(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SummonAssociate used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

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
	cre->SummonAssociate(sResRef, sName, Type);

	return 1;
}

int CNssCreature::GetAttackModifierVs(CGameObject *oObject, char *Params) {
	CNWSCreature *Attacker = oObject->AsNWSCreature();
	if (Attacker) {
		nwn_objid_t Defender = OBJECT_INVALID;
		int bOffHand = 0;
		int bRangedAttack = 0;
		if (sscanf(Params, "%08X %d %d", &Defender, &bOffHand, &bRangedAttack) == 3) {
			CGameObject *o = (*NWN_AppManager)->app_server->srv_internal->GetGameObject(Defender);
			if (o) {
				int ab = GetAttackModifierVersus(Attacker, o->AsNWSObject(), bOffHand, bRangedAttack);
				sprintf(Params, "%d", ab);
				return 1;
			}
		}
	}
	sprintf(Params, "-1");
	return -1;
}

int CNssCreature::GetAttackModifierVersus(CNWSCreature *Attacker, CNWSObject* Defender, int bOffHand, int bRangedAttack) {
	if (Attacker == NULL) return 0;

	//_log(3, "Atk oid: %08X\tDef oid: %08X\n", Attacker->obj_id, Defender->obj_id);

	//int iMod = 0;
	//int iAttackBonus = 0;

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

//	CNWSCombatRound *combatRound = Attacker->cre_combat_round;
//	uint8_t CurrentAttack = Attacker->cre_combat_round->CurrentAttack;
	
//	CNWSCombatAttackData *AttackData = combatRound->GetAttack(CurrentAttack);

//	uint32_t bRangedAttack = AttackData->RangedAttack;
	Weapon = GetWeapon(Attacker, bOffHand, false);

	int iBaB = AttackerStats->GetBaseAttackBonus(0);

	int TwoWeaponPenalty = 0;
	int SizeMod = 0;
	int CombatMod = 0;
	int SpecialAttackMod = 0;
	int NatureSenseMod = 0;
	int EpicProwessMod = 0;
	int SuperiorWeaponFocus = 0;
	int FavoredEnemyMod = 0;
	int GoodAimMod = 0;
	int SlingMod = 0;
	int EnchantArrowMod = 0;
	int OffensiveTrainingMod = 0;
	int AbilityMod = 0;
	int WeaponFocusMod = 0;
	int EffectMod = 0;
	int BlindDefenderMod = 0;
	int AttackerInvisibleMod = 0;
	int CantSeeTargetMod = 0;
	int TargetStateMod = 0;
	int TargetFlankedMod = 0;
	int PBSMod = 0;
	int EnemyAttackMod = 0;
	int FinesseACP = 0;

	std::string sAbility = "STR";

	if (Weapon != NULL) BaseWeapon = (*NWN_Rules)->ru_baseitems->GetBaseItem(Weapon->it_baseitemtype);

//		_log(3, "Bab: %d\n", iMod);

	/************************ iTwoWeaponFightingPenalty *********************/

	//apply penalties if: 
	//	offHand weapon equipped
	//	mainHand weapon is double sided

	Weapon2nd = Attacker->cre_equipment->GetItemInSlot(0x20);
	if (!Weapon2nd) {
		Weapon2nd = Attacker->cre_equipment->GetItemInSlot(0x10);
		if (Weapon2nd) {
			Base2nd = (*NWN_Rules)->ru_baseitems->GetBaseItem(Weapon2nd->it_baseitemtype);
			if (Base2nd) {
				if (Base2nd->WeaponWield != 8)
					Weapon2nd = NULL;
			}
		}
	}

	if (Weapon2nd) {
		if (!bOffHand) {
			Base2nd = (*NWN_Rules)->ru_baseitems->GetBaseItem(Weapon2nd->it_baseitemtype);
			if (Base2nd->WeaponType) {
				TwoWeaponPenalty = -6;
				if ((Attacker->GetRelativeWeaponSize(Weapon2nd) <= -1) || Base2nd->WeaponWield == 8)
					TwoWeaponPenalty = -4;
				if (AttackerStats->HasFeat(FEAT_TWO_WEAPON_FIGHTING)) //FEAT_TWO_WEAPON_FIGHTING
					TwoWeaponPenalty += 2;
			}
		}
		else {
			Base2nd = (*NWN_Rules)->ru_baseitems->GetBaseItem(Weapon2nd->it_baseitemtype);
			if (Base2nd) {
				TwoWeaponPenalty = -10;
				if ((Attacker->GetRelativeWeaponSize(Weapon2nd) <= -1) || BaseWeapon->WeaponWield == 8)
					TwoWeaponPenalty = -8;
				if (AttackerStats->HasFeat(FEAT_AMBIDEXTERITY)) //FEAT_AMBIDEXTERITY
					TwoWeaponPenalty += 4;
				if (AttackerStats->HasFeat(FEAT_TWO_WEAPON_FIGHTING)) //FEAT_TWO_WEAPON_FIGHTING
					TwoWeaponPenalty += 2;
			}
		}
//		_log(3, "iTwoWeaponFighting_Mod: %d\n", iMod);
	}

		
	/************************ Size Modifiers *********************/

	SizeMod = 3 - Attacker->cre_size;

//		_log(3, "iSize_Mod: %d\n", iMod);


	/************************ Combat Mode Modifiers *********************/

	switch(Attacker->cre_mode_combat) {
		case 2: CombatMod = -5; break;
		case 3: CombatMod = -10; break;
		case 5: CombatMod = -2; break;
		case 6: CombatMod = -2; break;
		case 7: CombatMod = -5; break;
		case 8: CombatMod = -10; break;
	}

		//_log(3, "iCombatMode_Mod: %d\n", iMod);

	/************************ Special Attack Modifiers *********************/

	SpecialAttackMod = (Attacker->cre_stats)->ResolveSpecialAttackAttackBonus(DefenderAsCreature);

//		_log(3, "iSpecialAttack_Mod: %d\n", iMod);

	/************************ Nature Sense Modifier *********************/

	CNWSArea *CNWArea = ((CNWSObject*)Attacker)->GetArea();
	if (CNWArea) {
		int area = CNWArea->are_id;
		if (area && (area & 4 || area & 1 || area & 2) && (Attacker->cre_stats)->HasFeat(FEAT_NATURE_SENSE))
			NatureSenseMod = 2;

//		_log(3, "iNatureSense_Mod: %d\n", iMod);
	}


	/************************ Epic Prowess Modifier *********************/

	if ((Attacker->cre_stats)->HasFeat(FEAT_EPIC_PROWESS)) {
		EpicProwessMod = 1;

//		_log(3, "iEpicProwess_Mod: %d\n", iMod);
	}


	/************************ Weapon Master Modifier *********************/

	if (Weapon != NULL) {
		int bWeaponOfChoice = 0;
		if (AttackerStats->HasFeat(FEAT_SUPERIOR_WEAPON_FOCUS)
		&& (bWeaponOfChoice = (Attacker->cre_stats)->GetIsWeaponOfChoice(Weapon->it_baseitemtype))) {
			SuperiorWeaponFocus = 1;
			bWeaponOfChoice = 1;
		}
		if (AttackerStats->HasFeat(FEAT_EPIC_SUPERIOR_WEAPON_FOCUS) && bWeaponOfChoice) {
			// get the weapon master levels
			for (int i = 0; i<3; i++) {
				if (AttackerStats->cs_classes[i].cl_class != 33)
					continue;

				int EpicSuperiorWeaponFocus = (int)((AttackerStats->cs_classes[i].cl_level - 10) / 3);

				SuperiorWeaponFocus += EpicSuperiorWeaponFocus > 0 ? EpicSuperiorWeaponFocus : 0;
			}
		}

//		_log(3, "iWeaponMaster_Mod: %d\n", iMod);
	}


	/************************ Favored Enemy Modifier *********************/

	if (DefenderAsCreature != NULL) {
		if ((Attacker->cre_stats)->HasFeat(855)) { //FEAT_EPIC_BANE_OF_ENEMIES
			if ((Attacker->cre_stats)->GetFavoredEnemyBonus(DefenderAsCreature)) {
				FavoredEnemyMod = 2;
			}
//			_log(3, "iFavoredEnemy_Mod: %d\n", iMod);
		}
	}

	/************************ Good Aim Modifier *********************/

	GoodAimMod = (AttackerStats->HasFeat(250) && BaseWeapon && BaseWeapon->WeaponWield == 11);

//	_log(3, "iGoodAim_Mod: %d\n", iMod);


	/************************ Halfling Sling Modifier *********************/

	SlingMod =  (AttackerStats->cs_race == 3 && Weapon && Weapon->it_baseitemtype == 61);

//	_log(3, "iHalflingSling_Mod: %d\n", iMod);

	/************************ Enchant Arrow Modifier *********************/

	if (Weapon && (Weapon->it_baseitemtype == 8 || Weapon->it_baseitemtype == 11)) {
		for (int i=1059; i<=1045; i--) {
			if (AttackerStats->HasFeat(i)) {
				EnchantArrowMod = i-1039;
				break;
			}
		}
		if (!EnchantArrowMod) {
			for (int i=449; i<=445; i--) {
				if (AttackerStats->HasFeat(i)) {
					EnchantArrowMod = i-444;
					break;
				}
			}
		}
//		_log(3, "iEnchantArrow_Mod: %d\n", iMod);
	}


	/************************ Offensive Training Modifier *********************/

	if (DefenderAsCreature != NULL) {
		if ((AttackerStats->HasFeat(232) && DefenderAsCreatureStats->cs_race == 12)
			|| (AttackerStats->HasFeat(231) && DefenderAsCreatureStats->cs_race == 14)
			|| (AttackerStats->HasFeat(242) && DefenderAsCreatureStats->cs_race == 15)
		) {
			OffensiveTrainingMod = 1;

//			_log(3, "iOffensiveTraining_Mod: %d\n", iMod);
		}
	}


	/************************ Ability Modifier *********************/

	if (bRangedAttack) {
		if (AttackerStats->HasFeat(FEAT_ZEN_ARCHERY)) {
			int iDexMod = AttackerStats->GetDEXMod(0);
			if (iDexMod > AttackerStats->cs_wis_mod) {
				AbilityMod = iDexMod;
				sAbility = "DEX";
			}
			else {
				AbilityMod = AttackerStats->cs_wis_mod;
				sAbility = "WIS";
			}
		}
		else {
			AbilityMod = AttackerStats->GetDEXMod(0);
			sAbility = "DEX";
		}
	}
	else {
		AbilityMod = AttackerStats->cs_str_mod;
		if (AttackerStats->GetWeaponFinesse(Weapon)) {
			int iDexMod = AttackerStats->GetDEXMod(0);
			if (iDexMod > AttackerStats->cs_str_mod) {
				AbilityMod = iDexMod;
				sAbility = "DEX";
/*				if (WeaponFinesse_ShieldPenalty) {
					CNWSItem *Shield = Attacker->cre_equipment->GetItemInSlot(EQUIPMENT_SLOT_LEFTHAND);
					if (Shield && (Shield->it_baseitemtype == BASE_ITEM_SMALLSHIELD || Shield->it_baseitemtype == BASE_ITEM_LARGESHIELD || Shield->it_baseitemtype == BASE_ITEM_TOWERSHIELD)) {
						CNWBaseItem *Base = (*NWN_Rules)->ru_baseitems->GetBaseItem(Shield->it_baseitemtype);
						if ((iDexMod + Base->ArmorCheckPen) > AttackerStats->cs_str_mod) {
							AbilityMod = iDexMod;
							sAbility = "DEX";
							FinesseACP = Base->ArmorCheckPen;
						}
						else {
							sAbility = "STR";
							AbilityMod = AttackerStats->cs_str_mod;
						}
					}
				}*/
			}
		}
	}

//	_log(3, "iAbility_Mod: %d\n", iMod);

	/************************ Epic / Weapon Focus Modifier *********************/

	WeaponFocusMod = AttackerStats->GetWeaponFocus(Weapon);
	WeaponFocusMod += (AttackerStats->GetEpicWeaponFocus(Weapon) * 2);
//	_log(3, "Weapon Foci: %d\n", iMod);


	/************************ TotalEffectBonus Modifier *********************/

	if (DefenderAsCreature != NULL) {
		EffectMod = 
			Attacker->GetTotalEffectBonus(
			1,
			(CNWSObject *)(*(int (__thiscall **)(CNWSCreature *))(DefenderAsCreature->obj_type + 16))(DefenderAsCreature),
			0, 0, 0, 0, -1, -1, 0);
	}
	else {
		EffectMod = 
			Attacker->GetTotalEffectBonus(
			1, 0, 0, 0, 0, 0, -1, -1, 0);
	}

//	_log(3, "iTotalEffect_Mod: %d\n", iMod);


	/************************ Blind Defender Modifier *********************/

	if (DefenderAsCreature != NULL) {
		if (DefenderAsCreature->GetBlind() 
			&& (bRangedAttack || !DefenderAsCreatureStats->HasFeat(FEAT_BLIND_FIGHT))) {
			BlindDefenderMod = 2;

//			_log(3, "iBlindDefender_Mod: %d\n", iMod);
		}
	}


	/************************ Invisible Attacker Modifier *********************/

	if (DefenderAsCreature != NULL) {
		CNWSObject *obj_bInvisible = (CNWSObject *)(*(int (__thiscall **)(CNWSCreature *))(AttackerStats->cs_original->obj_type + 16))(AttackerStats->cs_original);
		if (Attacker->GetInvisible(obj_bInvisible, 0)
			&& (bRangedAttack || !DefenderAsCreatureStats->HasFeat(FEAT_BLIND_FIGHT))
		) {
			AttackerInvisibleMod = 2;
		}

//		_log(3, "iInvisAttacker_Mod: %d\n", iMod);
	}


	/************************ Can't see target Modifier *********************/

	if (Defender != NULL) {
		CNWVisibilityNode *obj_GetVisibleElement = Attacker->GetVisibleListElement(Defender->obj_id);
		if ( !obj_GetVisibleElement || !((unsigned int)obj_GetVisibleElement[1].unknown & 1) ) {
			CantSeeTargetMod = -4;

//			_log(3, "iCantSeeTarget_Mod: %d\n", iMod);
		}
	}

	/************************ Target States (Animation) Modifier *********************/

	if (DefenderAsCreature != NULL) {
		int DefenderState = DefenderAsCreature->obj_anim;

		int ProneMod = 0, MovingPenalty = 0, StunnedMod = 0;

		if (bRangedAttack) { //Ranged Attack
			if ( DefenderState == 4 || DefenderState == 87 || DefenderState == 86 ) //Target Moving
				TargetStateMod = -2;
			else if ( DefenderState == 36 || DefenderState == 33 || DefenderState == 32 || DefenderState == 7 || DefenderState == 5 ) { //Target Prone
				TargetStateMod = -4;
			}
		}
		else {
			if ( DefenderState == 36 || DefenderState == 33 || DefenderState == 32 || DefenderState == 7 || DefenderState == 5 ) { //Taget Prone
				TargetStateMod = 4;
			}
		}
		if ( DefenderAsCreature->cre_state == 6 ) //stunned?
			TargetStateMod += 2;


//		_log(3, "iTargetState_Mod: %d\n", iMod);
	}


	/************************ Distance Calculation, gonna need that more than once *********************/

	float fDistance=0.0;
	if (Defender != NULL) {
		Vector posAttacker = Attacker->obj_position;
		Vector posDefender = Defender->obj_position;

		posAttacker.x -= posDefender.x;
		posAttacker.y -= posDefender.y;
		posAttacker.z -= posDefender.z;

		posAttacker.x *= posAttacker.x;
		posAttacker.y *= posAttacker.y;
		posAttacker.z *= posAttacker.z;
		
		fDistance = sqrt(posAttacker.x+posAttacker.y+posAttacker.z);

		//_log (3, "Distance: %f\n", fDistance);
	}


	/************************ Target Flanked Modifier *********************/

	if (DefenderAsCreature) {
		if (Attacker->GetFlanked(DefenderAsCreature) == 1) {
			if (bRangedAttack || fDistance < 9.144) {
				// on ranged sneak attack the distance between Attacker and Defender must be <= 9.144m
				TargetFlankedMod = 2;
			}

//			_log(3, "iTargetFlanked_Mod: %d\n", iMod);
		}
	}


	/************************ Point Blank Shot Modifier *********************/

	if (DefenderAsCreature) {
		if (bRangedAttack) {
			if (fDistance <= 4.572) {
				if ((Attacker->cre_stats)->HasFeat(FEAT_POINT_BLANK_SHOT)) { //+1 if within 15 ft with Point Blank Shot feat
					PBSMod = 1;
				}
				else {
					float maxAttackRange = Attacker->MaxAttackRange(Defender->obj_id, 0, 0);
					if (maxAttackRange * maxAttackRange >= fDistance) {
						if (!DefenderAsCreature->GetRangeWeaponEquipped()) {
							PBSMod = -4;
						}
					}
				}
			}
//			_log(3, "iRanged_Mod: %d\n", iMod);
		}
	}

	/************************ Enemy Attack Modifier *********************/
	// no clue what this is either

	if(DefenderAsCreature) {
		EnemyAttackMod = DefenderAsCreatureStats->field_413;

//			_log(3, "iEnemyAttack_Mod: %d\n", iMod);
	}

	int iAttackBonus =
		iBaB +
		TwoWeaponPenalty +
		SizeMod +
		CombatMod +
		SpecialAttackMod +
		NatureSenseMod +
		EpicProwessMod +
		SuperiorWeaponFocus +
		FavoredEnemyMod +
		GoodAimMod +
		SlingMod +
		EnchantArrowMod +
		OffensiveTrainingMod +
		AbilityMod +
		WeaponFocusMod +
		EffectMod +
		BlindDefenderMod +
		AttackerInvisibleMod +
		CantSeeTargetMod +
		TargetStateMod +
		TargetFlankedMod +
		PBSMod +
		EnemyAttackMod +
		FinesseACP;

	return iAttackBonus;
}

CNWSItem *CNssCreature::GetWeapon(CNWSCreature *cre, int bOffHand, bool bGetBracers) {
	CNWSItem *Weapon = NULL;

	if (!bOffHand) {
		return cre->cre_equipment->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND);
	}
	else {
		Weapon = cre->cre_equipment->GetItemInSlot(EQUIPMENT_SLOT_LEFTHAND);
		if (!Weapon) {
			Weapon = cre->cre_equipment->GetItemInSlot(EQUIPMENT_SLOT_RIGHTHAND);
			if (Weapon) {
				CNWBaseItem *Base = (*NWN_Rules)->ru_baseitems->GetBaseItem(Weapon->it_baseitemtype);
				if (Base) {
					if (Base->WeaponWield != 8) Weapon = NULL;
				}
			}
		}
	}
	return Weapon;
}
