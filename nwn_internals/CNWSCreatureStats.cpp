#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void 			(__thiscall *CNWSCreatureStats__AddExperience)(CNWSCreatureStats *pTHIS, uint32_t XP) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint32_t XP))0x0047D6F0;
char 			(__thiscall *CNWSCreatureStats__AddFeat)(CNWSCreatureStats *pTHIS, uint16_t Feat) = (char (__thiscall *)(CNWSCreatureStats *pTHIS, uint16_t Feat))0x0047EBC0;
void			(__thiscall *CNWSCreatureStats__DecrementFeatRemainingUses)(CNWSCreatureStats *pTHIS, unsigned short FeatID) = (void(__thiscall*)(CNWSCreatureStats *pTHIS, unsigned short FeatID))0x00480200;
char			(__thiscall *CNWSCreatureStats__GetACNaturalBase)(CNWSCreatureStats *pTHIS, int bTouchAttack) = (char (__thiscall*)(CNWSCreatureStats *pTHIS, int bTouchAttack))0x00489B00;
int 			(__thiscall *CNWSCreatureStats__GetArmorClassVersus)(CNWSCreatureStats *pTHIS, CNWSCreature *Attacker, int bTouchAttack) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSCreature *Attacker, int bTouchAttack))0x0046DC00;
int 			(__thiscall *CNWSCreatureStats__GetAttackModifierVersus)(CNWSCreatureStats *, CNWSCreature *) = (int (__thiscall *)(CNWSCreatureStats *, CNWSCreature *))0x00470F00;
int 			(__thiscall *CNWSCreatureStats__GetBaseAttackBonus)(CNWSCreatureStats *Stats, int bPreEpicOnly) = (int (__thiscall*)(CNWSCreatureStats *Stats, int bPreEpicOnly))0x0046ED40;
int 			(__thiscall *CNWSCreatureStats__GetCanUseSkill)(CNWSCreatureStats *pTHIS, unsigned char Skill) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, unsigned char Skill))0x0047E160;
int				(__thiscall *CNWSCreatureStats__GetCriticalHitMultiplier)(CNWSCreatureStats *pthis, int bOffhandWeapon) = (int(__thiscall*)(CNWSCreatureStats *pthis, int bOffhandWeapon))0x00477A20;
char 			(__thiscall *CNWSCreatureStats__GetDEXMod)(CNWSCreatureStats *pTHIS, int bMaxArmorDex) = (char (__thiscall*)(CNWSCreatureStats *pTHIS, int bMaxArmorDex))0x0047CAF0;
signed int 		(__thiscall *CNWSCreatureStats__GetEpicWeaponFocus)(CNWSCreatureStats *pTHIS, CNWSItem *weapon) = (signed int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSItem *weapon))0x00481510;
int 			(__thiscall *CNWSCreatureStats__GetFavoredEnemyBonus)(CNWSCreatureStats *pTHIS, CNWSCreature *cre_enemy) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSCreature *cre_enemy))0x00489E50;
uint8_t			(__thiscall *CNWSCreatureStats__GetFeatRemainingUses)(CNWSCreatureStats *pTHIS, uint16_t FeatID) = (uint8_t(__thiscall*)(CNWSCreatureStats *pTHIS, uint16_t FeatID))0x0047EF10;
int 			(__thiscall *CNWSCreatureStats__GetEffectImmunity)(CNWSCreatureStats *pTHIS, unsigned __int8 Type, CNWSCreature *a3_Versus) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, unsigned __int8 Type, CNWSCreature *a3_Versus))0x0048B770;
unsigned char 	(__thiscall *CNWSCreatureStats__GetIsClass)(CNWSCreatureStats *pTHIS, unsigned char) = (unsigned char(__thiscall*)(CNWSCreatureStats *pTHIS, unsigned char))0x004732D0;
int 			(__thiscall *CNWSCreatureStats__GetIsWeaponOfChoice)(CNWSCreatureStats *pTHIS, uint32_t BaseItemType) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, uint32_t BaseItemType))0x0048CB10;
uint8_t			(__thiscall *CNWSCreatureStats__GetLevel)(CNWSCreatureStats *pTHIS, int bCountNegativeLevels) = (uint8_t (__thiscall*)(CNWSCreatureStats *pTHIS, int bCountNegativeLevels))0x0046DB40;
int				(__thiscall *CNWSCreatureStats__GetMeleeAttackBonus)(CNWSCreatureStats *, int, int, int) = (int (__thiscall *)(CNWSCreatureStats *, int, int, int))0x0046FB40;
int 			(__thiscall *CNWSCreatureStats__GetNumLevelsOfClass)(CNWSCreatureStats *pTHIS, unsigned char) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, unsigned char))0x0048F400;
int 			(__thiscall *CNWSCreatureStats__GetNumLevelsOfClass2)(CNWSCreatureStats *pTHIS, unsigned char, int) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, unsigned char, int))0x0048F240;
char 			(__thiscall *CNWSCreatureStats__GetSkillRank)(CNWSCreatureStats *pTHIS, unsigned __int8 nSkill, CNWSObject *vsObj, int bBaseRanksOnly) = (char (__thiscall*)(CNWSCreatureStats *pTHIS, unsigned __int8 nSkill, CNWSObject *vsObj, int bBaseRanksOnly))0x0047E2C0;
signed int 		(__thiscall *CNWSCreatureStats__GetWeaponFinesse)(CNWSCreatureStats *pTHIS, CNWSItem *weapon) = (signed int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSItem *weapon))0x00481210;
signed int 		(__thiscall *CNWSCreatureStats__GetWeaponFocus)(CNWSCreatureStats *pTHIS, CNWSItem *weapon) = (signed int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSItem *weapon))0x004812E0;
unsigned char	(__thiscall *CNWSCreatureStats__GetUnarmedDamageDice)(CNWSCreatureStats *pTHIS) = (unsigned char(__thiscall*)(CNWSCreatureStats *pTHIS))0x004707B0;
unsigned char	(__thiscall *CNWSCreatureStats__GetUnarmedDamageDie)(CNWSCreatureStats *pTHIS) = (unsigned char(__thiscall*)(CNWSCreatureStats *pTHIS))0x00470940;
int 			(__thiscall *CNWSCreatureStats__GetUseMonkAttackTables)(CNWSCreatureStats *pTHIS, int) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, int))0x00470730;
int 			(__thiscall *CNWSCreatureStats__HasFeat)(CNWSCreatureStats *Stats, uint16_t feat) = (int (__thiscall*)(CNWSCreatureStats *Stats, uint16_t feat))0x0047ECF0;
bool 			(__thiscall *CNWSCreatureStats__LevelUp)(CNWSCreatureStats *pTHIS, CNWSStats_Level *a2, int a3, char a4, char a5, int a6) = (bool (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSStats_Level *a2, int a3, char a4, char a5, int a6))0x004847F0;
int 			(__thiscall *CNWSCreatureStats__ResolveSpecialAttackAttackBonus)(CNWSCreatureStats *pAttackerStats, CNWSCreature *Defender) = (int (__thiscall*)(CNWSCreatureStats *pAttackerStats, CNWSCreature *Defender))0x004744F0;
//unsigned char 	(__thiscall *CNWSCreatureStats__GetAttacksPerRound)(CNWSCreatureStats *, = (unsigned char

void (__thiscall *CNWSCreatureStats__SetCHABase)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase))0x0047D0D0;
void (__thiscall *CNWSCreatureStats__SetCONBase)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase, int a3) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase, int a3))0x0047CDE0;
void (__thiscall *CNWSCreatureStats__SetDEXBase)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase))0x0047CCC0;
void (__thiscall *CNWSCreatureStats__SetINTBase)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase))0x0047CEF0;
void (__thiscall *CNWSCreatureStats__SetSTRBase)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase))0x0047CBD0;
void (__thiscall *CNWSCreatureStats__SetWISBase)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint8_t AbilityBase))0x0047CFE0;

int16_t (__thiscall *CNWSCreatureStats__GetDamageRoll)(CNWSCreatureStats *pTHIS, CNWSObject *Defender, int bOffHand, int AttackResult, int SneakAttack, int DeathAttack, int a7) = (int16_t (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSObject *Defender, int bOffHand, int AttackResult, int SneakAttack, int DeathAttack, int a7))0x004764D0;

void CNWSCreatureStats_s::SetCHABase(uint8_t CHABase) {
	CNWSCreatureStats__SetCHABase(this, CHABase);
}

void CNWSCreatureStats_s::SetCONBase(uint8_t CONBase, int a3) {
	CNWSCreatureStats__SetCONBase(this, CONBase, a3);
}

void CNWSCreatureStats_s::SetDEXBase(uint8_t DEXBase) {
	CNWSCreatureStats__SetDEXBase(this, DEXBase);
}

void CNWSCreatureStats_s::SetINTBase(uint8_t INTBase) {
	CNWSCreatureStats__SetINTBase(this, INTBase);
}

void CNWSCreatureStats_s::SetSTRBase(uint8_t STRBase) {
	CNWSCreatureStats__SetSTRBase(this, STRBase);
}

void CNWSCreatureStats_s::SetWISBase(uint8_t WISBase) {
	CNWSCreatureStats__SetWISBase(this, WISBase);
}

void CNWSCreatureStats_s::AddExperience(uint32_t XP) {
	return CNWSCreatureStats__AddExperience(this, XP);
}

char CNWSCreatureStats_s::AddFeat(uint16_t Feat) {
	return CNWSCreatureStats__AddFeat(this, Feat);
}

char CNWSCreatureStats_s::GetACNaturalBase(int bTouchAttack) {
	return CNWSCreatureStats__GetACNaturalBase(this, bTouchAttack);
}

int CNWSCreatureStats_s::GetAttackModifierVersus(CNWSCreature *Vs) {
	return CNWSCreatureStats__GetAttackModifierVersus(this, Vs);
}

//unsigned char CNWSCreatureStats_s::GetAttacksPerRound() {
//	return CNWSCreatureStats__GetAttacksPerRound(this);
//}

int CNWSCreatureStats_s::GetBaseAttackBonus(int bPreEpicOnly) {
	return CNWSCreatureStats__GetBaseAttackBonus(this, bPreEpicOnly);
}

char CNWSCreatureStats_s::GetDEXMod(int bMaxArmorDex) {
	return CNWSCreatureStats__GetDEXMod(this, bMaxArmorDex);
}

signed int CNWSCreatureStats_s::GetEpicWeaponFocus(CNWSItem *weapon) {
	return CNWSCreatureStats__GetEpicWeaponFocus(this, weapon);
}

int CNWSCreatureStats_s::GetFavoredEnemyBonus(CNWSCreature *cre_enemy) {
	return CNWSCreatureStats__GetFavoredEnemyBonus(this, cre_enemy);
}

int CNWSCreatureStats_s::GetIsWeaponOfChoice(uint32_t BaseItemType) {
	return CNWSCreatureStats__GetIsWeaponOfChoice(this, BaseItemType);
}

uint8_t CNWSCreatureStats_s::GetLevel(int bCountNegativeLevels) {
	return CNWSCreatureStats__GetLevel(this, bCountNegativeLevels);
}

int CNWSCreatureStats_s::GetMeleeAttackBonus(int a1, int a2, int a3) {
	return CNWSCreatureStats__GetMeleeAttackBonus(this, a1, a2, a3);
}

int CNWSCreatureStats_s::GetUseMonkAttackTables(int a1) {
	return CNWSCreatureStats__GetUseMonkAttackTables(this, a1);
}

signed int CNWSCreatureStats_s::GetWeaponFinesse(CNWSItem *weapon) {
	return CNWSCreatureStats__GetWeaponFinesse(this, weapon);
}

signed int CNWSCreatureStats_s::GetWeaponFocus(CNWSItem *weapon) {
	return CNWSCreatureStats__GetWeaponFocus(this, weapon);
}

int CNWSCreatureStats_s::HasFeat(uint16_t feat) {
	return CNWSCreatureStats__HasFeat(this, feat);
}

bool CNWSCreatureStats_s::LevelUp(CNWSStats_Level *a2, int a3, char a4, char a5, int a6) {
	return CNWSCreatureStats__LevelUp(this, a2, a3, a4, a5, a6);
}

int CNWSCreatureStats_s::ResolveSpecialAttackAttackBonus(CNWSCreature *Defender) {
	return CNWSCreatureStats__ResolveSpecialAttackAttackBonus(this, Defender);
}

int16_t CNWSCreatureStats_s::GetDamageRoll(CNWSObject *Defender, int bOffHand, int AttackResult, int SneakAttack, int DeathAttack, int a7) {
	return CNWSCreatureStats__GetDamageRoll(this, Defender, bOffHand, AttackResult, SneakAttack, DeathAttack, a7);
}

int CNWSCreatureStats_s::GetNumLevelsOfClass(unsigned char nClassType) {
	return CNWSCreatureStats__GetNumLevelsOfClass(this, nClassType);
}

int CNWSCreatureStats_s::GetNumLevelsOfClass(unsigned char nClassType, int bPreEpicOnly) {
	return CNWSCreatureStats__GetNumLevelsOfClass2(this, nClassType, bPreEpicOnly);
}

unsigned char CNWSCreatureStats_s::GetSimpleAlignmentGoodEvil() {
	int ge = this->cs_al_goodevil;
	if (ge > 30)
		if (ge > 70) 
			return  4;
		return 1;
	return 5;
}

unsigned char CNWSCreatureStats_s::GetSimpleAlignmentLawChaos() {
	int lc = this->cs_al_lawchaos;
	if (lc > 30)
		if (lc > 70) 
			return  2;
		return 1;
	return 3;	
}

int CNWSCreatureStats_s::GetCanUseSkill(unsigned char Skill) {
	return CNWSCreatureStats__GetCanUseSkill(this, Skill);
}

char CNWSCreatureStats_s::GetSkillRank(unsigned char Skill, CNWSObject *vsObj, int bBaseRanksOnly) {
	return CNWSCreatureStats__GetSkillRank(this, Skill, vsObj, bBaseRanksOnly);
}

int CNWSCreatureStats_s::GetEffectImmunity(unsigned __int8 Type, CNWSCreature *a3_Versus) {
	return CNWSCreatureStats__GetEffectImmunity(this, Type, a3_Versus);
}

uint8_t CNWSCreatureStats_s::GetFeatRemainingUses(uint16_t FeatID) {
	return CNWSCreatureStats__GetFeatRemainingUses(this, FeatID);
}

void CNWSCreatureStats_s::DecrementFeatRemainingUses(uint16_t FeatID) {
	return CNWSCreatureStats__DecrementFeatRemainingUses(this, FeatID);
}

unsigned char CNWSCreatureStats_s::GetIsClass(unsigned char ClassType) {
	return CNWSCreatureStats__GetIsClass(this, ClassType);
}

int CNWSCreatureStats_s::GetArmorClassVersus(CNWSCreature *Attacker, int bTouchAttack) {
	return CNWSCreatureStats__GetArmorClassVersus(this, Attacker, bTouchAttack);	
}

unsigned char CNWSCreatureStats_s::GetUnarmedDamageDice() {
	return CNWSCreatureStats__GetUnarmedDamageDice(this);
}

unsigned char CNWSCreatureStats::GetUnarmedDamageDie() {
	return CNWSCreatureStats__GetUnarmedDamageDie(this);
}

int CNWSCreatureStats::GetCriticalHitMultiplier(int bOffhand) {
	return CNWSCreatureStats__GetCriticalHitMultiplier(this, bOffhand);
}