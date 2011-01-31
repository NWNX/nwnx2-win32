#include "nwnx_funcs_effst"

/*
These functions will return structs for use with NWNXFuncs_EffectCustomEffect() to set effect creator and spell id
Most of the regular effect functions are duplicated here.
The missing ones are for effects that can only be applied instantly which can't be checked for creator and spell id anyways

usage example:

	struct gameeffect_s stACIncrease = NWNXFuncs_EffectACIncrease("AABBAABB", 50000, 5);
	effect eAC = NWNXFuncs_EffectCustomEffect(stACIncrease);
	ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eAC, oPC, 60.0);

This will add 5 Dodge AC to oPC armor class for 60. seconds. The only difference is that the effect is defined using a struct 
instead of the regular EffectACIncrease function.
Also, the creator and spell id do not have to be valid objects or spells for the effect to function, but they can still be compared 
using GetEffectSpellId() and GetEffectCreator() - Actually you would want to use ObjectToString(GetEffectCreator()). Spell ids can even be negative values.

As far as I can tell no object will ever have an id greater than 0x80000000 so using values greater than this shouldn't cause any problems.

So what's the point?
Getting around creating creatures to change creator ids and having them cast spells to change the spell id.

The PRC - at least with version 3.1 - uses an effect's spell id to keep track of attack bonuses for custom classes. This means having a valid spell from spells.2da
and spawning in an object which casts the spell to give the class its bonuses. My prime example is the Tempest which eventually has no penalties fighting with
two weapons:
- Equip Weapon
- Has required feat?
- Spawn in object to cast spell which applies the attack bonus
The reason being is that since it is actually a feat, this bonus is not supposed to be removed with Dispel Magic and the likes; correct stacking is another. This is
done by checking against the spell id.
The problem I found is that spawning in the object to cast the spell can utterly fail at times, so the character never gets the bonus.
Using NWNXFuncs_EffectCustomEffect gets around this problem and the overhead shouldn't be much worse:

	
	const int COMPOSITE_ATTACK_BONUS = -100;

	struct gameeffect_s stAttack = NWNXFuncs_EffectAttackIncrease("AABBAABB", COMPOSITE_ATTACK_BONUS, 2);
	effect eAttack = NWNXFuncs_EffectCustomEffect(stAttack);
	ApplyEffectToObject(DURATION_TYPE_TEMPORARY, eAttack, oPC, 9999.0);
	
	//Dispel Magic but not our attack bonus
	effect e = GetFirstEffect(oPC);
	while (GetIsEffectValid(e)) {
		if (GetEffectSpellID(e) != COMPOSITE_ATTACK_BONUS)
			RemoveEffect(oPC, e);
		}
		e = GetNextEffect(oPC);
	}
*/






struct gameeffect_s NWNXFuncs_EffectACIncrease(string sCreator, int iSpellID, int nValue, int nModifyType=AC_DODGE_BONUS, int nDamageType=AC_VS_DAMAGE_TYPE_ALL, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 48;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 6;
	e.Ints = IntToString(nModifyType)+" "+IntToString(nValue)+" "+IntToString(nVsRace)+" 0 0 "+IntToString(nDamageType);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectACDecrease(string sCreator, int iSpellID, int nValue, int nModifyType=AC_DODGE_BONUS, int nDamageType=AC_VS_DAMAGE_TYPE_ALL, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 49;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 6;
	e.Ints = IntToString(nModifyType)+" "+IntToString(nValue)+" "+IntToString(nVsRace)+" 0 0 "+IntToString(nDamageType);
	return e;
}	

struct gameeffect_s NWNXFuncs_EffectAbilityDecrease(string sCreator, int iSpellID, int nAbility, int nModifyBy) {
	struct gameeffect_s e;
	e.Type = 37;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nAbility)+" "+IntToString(nModifyBy);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectAbilityIncrease(string sCreator, int iSpellID, int nAbilityToIncrease, int nModifyBy) {
	struct gameeffect_s e;
	e.Type = 36;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nAbilityToIncrease)+" "+IntToString(nModifyBy);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectAttackDecrease(string sCreator, int iSpellID, int nPenalty, int nModifierType=ATTACK_BONUS_MISC, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 11;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nPenalty)+" "+IntToString(nModifierType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectAttackIncrease(string sCreator, int iSpellID, int nBonus, int nModifierType=ATTACK_BONUS_MISC, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 10;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nBonus)+" "+IntToString(nModifierType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectBlindness(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x49;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectEntangle(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x12;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectKnockdown(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x14;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDeaf(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x15;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectHaste(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x01;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSilence(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x2E;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSlow(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x03;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectTimeStop(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x40;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectCutsceneImmobilize(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x5E;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectCurse(string sCreator, int iSpellID, int nStrMod=1, int nDexMod=1, int nConMod=1, int nIntMod=1, int nWisMod=1, int nChaMod=1) {
	struct gameeffect_s e;
	e.Type = 0x2D;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 6;
	e.Ints = IntToString(nStrMod)+" "+IntToString(nDexMod)+" "+IntToString(nConMod)+" "+IntToString(nIntMod)+" "+IntToString(nWisMod)+" "+IntToString(nChaMod);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDispelMagicBest(string sCreator, int iSpellID, int nCasterLevel=USE_CREATURE_LEVEL) {
	struct gameeffect_s e;
	e.Type = 0x34;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nCasterLevel);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectPolymorph(string sCreator, int iSpellID, int nPolymorphSelection, int nLocked=FALSE) {
	struct gameeffect_s e;
	e.Type = 0x3E;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nPolymorphSelection)+" 0 "+IntToString(nLocked);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectRegenerate(string sCreator, int iSpellID, int nAmount, float fIntervalSeconds) {
	struct gameeffect_s e;
	e.Type = 0x07;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nAmount)+" "+IntToString(FloatToInt(fIntervalSeconds*1000.0));
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDispelMagicAll(string sCreator, int iSpellID, int nCasterLevel=USE_CREATURE_LEVEL) {
	struct gameeffect_s e;
	e.Type = 0x33;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nCasterLevel);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectConcealment(string sCreator, int iSpellID, int nPercentage, int nMissType=MISS_CHANCE_TYPE_NORMAL, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x4C;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 5;
	if (nMissType == 1) nMissType = 2;
	else if (nMissType == 2) nMissType = 3;
	e.Ints = IntToString(nPercentage)+" "+IntToString(nVsRace)+" 0 0 "+IntToString(nMissType);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectCutsceneGhost(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x5D;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDamageDecrease(string sCreator, int iSpellID, int nPenalty, int nDamageType=DAMAGE_TYPE_MAGICAL, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x0E;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nPenalty)+" "+IntToString(nDamageType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDamageImmunityDecrease(string sCreator, int iSpellID, int nDamageType, int nPercentImmunity) {
	struct gameeffect_s e;
	e.Type = 0x11;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nDamageType)+" "+IntToString(nPercentImmunity);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDamageImmunityIncrease(string sCreator, int iSpellID, int nDamageType, int nPercentImmunity) {
	struct gameeffect_s e;
	e.Type = 0x10;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nDamageType)+" "+IntToString(nPercentImmunity);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDamageIncrease(string sCreator, int iSpellID, int nBonus, int nDamageType=DAMAGE_TYPE_MAGICAL, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x0D;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nBonus)+" "+IntToString(nDamageType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDamageReduction(string sCreator, int iSpellID, int nAmount, int nDamagePower, int nLimit=0) {
	struct gameeffect_s e;
	e.Type = 0x0C;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nAmount)+" "+IntToString(nDamagePower)+" "+IntToString(nLimit);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDamageResistance(string sCreator, int iSpellID, int nDamageType, int nAmount, int nLimit=0) {
	struct gameeffect_s e;
	e.Type = 0x02;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nDamageType)+" "+IntToString(nAmount)+" "+IntToString(nLimit);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDamageShield(string sCreator, int iSpellID, int nDamageAmount, int nRandomAmount, int nDamageType) {
	struct gameeffect_s e;
	e.Type = 0x3D;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nDamageAmount)+" "+IntToString(nRandomAmount)+" "+IntToString(nDamageType);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDarkness(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x4A;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDisease(string sCreator, int iSpellID, int nDiseaseType) {
	struct gameeffect_s e;
	e.Type = 0x05;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nDiseaseType);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectEthereal(string sCreator, int iSpellID, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x3F;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 6;
	e.Ints = "8 "+IntToString(nVsRace)+" 0 0 0 0";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectImmunity(string sCreator, int iSpellID, int nImmunityType, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x16;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nImmunityType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectInvisibility(string sCreator, int iSpellID, int nInvisibilityType, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x2F;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nInvisibilityType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectMissChance(string sCreator, int iSpellID, int nPercentage, int nMissChanceType=MISS_CHANCE_TYPE_NORMAL) {
	struct gameeffect_s e;
	e.Type = 0x4B;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	if (nMissChanceType == 1) nMissChanceType = 2;
	else if (nMissChanceType == 2) nMissChanceType = 3;
	e.Ints = IntToString(nPercentage)+" "+IntToString(nMissChanceType);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectModifyAttacks(string sCreator, int iSpellID, int nAttacks) {
	struct gameeffect_s e;
	e.Type = 0x2C;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nAttacks);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectMovementSpeedDecrease(string sCreator, int iSpellID, int nPercentChange) {
	struct gameeffect_s e;
	e.Type = 0x1D;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nPercentChange);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectMovementSpeedIncrease(string sCreator, int iSpellID, int nPercentChange) {
	struct gameeffect_s e;
	e.Type = 0x1C;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nPercentChange);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectNegativeLevel(string sCreator, int iSpellID, int nNumLevels, int bHPBonus=FALSE) {
	struct gameeffect_s e;
	e.Type = 0x52;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nNumLevels)+" "+IntToString(bHPBonus);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectPetrify(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "15";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectPoison(string sCreator, int iSpellID, int nPoisonType) {
	struct gameeffect_s e;
	e.Type = 0x23;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nPoisonType);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSanctuary(string sCreator, int iSpellID, int nDifficultyClass, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x3F;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 6;
	e.Ints = "8 "+IntToString(nVsRace)+" 0 0 "+IntToString(nDifficultyClass)+" 1";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSavingThrowDecrease(string sCreator, int iSpellID, int nSave, int nValue, int nSaveType=SAVING_THROW_TYPE_ALL, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x1B;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 4;
	e.Ints = IntToString(nValue)+" "+IntToString(nSave)+" "+IntToString(nSaveType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSavingThrowIncrease(string sCreator, int iSpellID, int nSave, int nValue, int nSaveType=SAVING_THROW_TYPE_ALL, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x1A;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 4;
	e.Ints = IntToString(nValue)+" "+IntToString(nSave)+" "+IntToString(nSaveType)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSeeInvisible(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x46;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSkillDecrease(string sCreator, int iSpellID, int nSkill, int nValue, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x38;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nSkill)+" "+IntToString(nValue)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSkillIncrease(string sCreator, int iSpellID, int nSkill, int nValue, int nVsRace=RACIAL_TYPE_ALL) {
	struct gameeffect_s e;
	e.Type = 0x37;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nSkill)+" "+IntToString(nValue)+" "+IntToString(nVsRace);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSpellFailure(string sCreator, int iSpellID, int nPercent=100, int nSpellSchool=SPELL_SCHOOL_GENERAL) {
	struct gameeffect_s e;
	e.Type = 0x5C;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 2;
	e.Ints = IntToString(nPercent)+" "+IntToString(nSpellSchool);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSpellImmunity(string sCreator, int iSpellID, int nImmunityToSpell=SPELL_ALL_SPELLS) {
	struct gameeffect_s e;
	e.Type = 0x32;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nImmunityToSpell);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSpellLevelAbsorption(string sCreator, int iSpellID, int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed=0, int nSpellSchool=SPELL_SCHOOL_GENERAL ) {
	struct gameeffect_s e;
	e.Type = 0x41;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nMaxSpellLevelAbsorbed)+" "+IntToString(nTotalSpellLevelsAbsorbed)+" "+IntToString(nSpellSchool);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSpellResistanceDecrease(string sCreator, int iSpellID, int nValue) {
	struct gameeffect_s e;
	e.Type = 0x22;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nValue);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSpellResistanceIncrease(string sCreator, int iSpellID, int nValue) {
	struct gameeffect_s e;
	e.Type = 0x21;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nValue);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectEffectTemporaryHitpoints(string sCreator, int iSpellID, int nHitPoints) {
	struct gameeffect_s e;
	e.Type = 0x0F;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nHitPoints);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectTrueSeeing(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x48;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectTurnResistanceDecrease(string sCreator, int iSpellID, int nHitDice) {
	struct gameeffect_s e;
	e.Type = 0x58;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nHitDice);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectTurnResistanceIncrease(string sCreator, int iSpellID, int nHitDice) {
	struct gameeffect_s e;
	e.Type = 0x4D;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = IntToString(nHitDice);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectUltravision(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x47;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 0;
	e.Ints = "";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectVisualEffect(string sCreator, int iSpellID, int nVisualEffectId, int nMissEffect=FALSE) {
	struct gameeffect_s e;
	e.Type = 0x1E;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 3;
	e.Ints = IntToString(nVisualEffectId)+" 0 "+IntToString(FALSE);
	return e;
}

struct gameeffect_s NWNXFuncs_EffectParalyze(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "8";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectSleep(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "9";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectCharmed(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "1";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectConfused(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "2";
return e;
}

struct gameeffect_s NWNXFuncs_EffectFrightened(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "3";
return e;
}

struct gameeffect_s NWNXFuncs_EffectDominated(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "7";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectDazed(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "5";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectStunned(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "6";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectEffectCutsceneParalyze(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "20";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectEffectCutsceneDominated(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "21";
	return e;
}

struct gameeffect_s NWNXFuncs_EffectEffectTurned(string sCreator, int iSpellID) {
	struct gameeffect_s e;
	e.Type = 0x08;
	e.Creator = sCreator;
	e.SpellID = iSpellID;
	e.NumInts = 1;
	e.Ints = "4";
	return e;
}


/* the following are not implemented as custom effects yet
effect EffectHeal(int nDamageToHeal);
effect EffectResurrection();
effect EffectSummonCreature(string sCreatureResref, int nVisualEffectId=VFX_NONE, float fDelaySeconds=0.0f, int nUseAppearAnimation=0);
effect EffectDeath(int nSpectacularDeath=FALSE, int nDisplayFeedback=TRUE);
effect EffectAreaOfEffect(int nAreaEffectId, string sOnEnterScript="", string sHeartbeatScript="", string sOnExitScript="");
effect EffectBeam(int nBeamVisualEffect, object oEffector, int nBodyPart, int bMissEffect=FALSE);
effect EffectHitPointChangeWhenDying(float fHitPointChangePerRound);
effect EffectDisappearAppear(location lLocation, int nAnimation=1);
effect EffectDisappear(int nAnimation=1);
effect EffectAppear(int nAnimation=1);
effect EffectSwarm(int nLooping, string sCreatureTemplate1, string sCreatureTemplate2="", string sCreatureTemplate3="", string sCreatureTemplate4="");
effect EffectDamage(int nDamageAmount, int nDamageType=DAMAGE_TYPE_MAGICAL, int nDamagePower=DAMAGE_POWER_NORMAL);

*/