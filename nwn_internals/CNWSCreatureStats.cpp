#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void 			(__thiscall *CNWSCreatureStats__AddExperience)(CNWSCreatureStats *pTHIS, uint32_t XP) = (void (__thiscall*)(CNWSCreatureStats *pTHIS, uint32_t XP))0x0047D6F0;
char 			(__thiscall *CNWSCreatureStats__AddFeat)(CNWSCreatureStats *pTHIS, uint16_t Feat) = (char (__thiscall *)(CNWSCreatureStats *pTHIS, uint16_t Feat))0x0047EBC0;
char			(__thiscall *CNWSCreatureStats__GetACNaturalBase)(CNWSCreatureStats *pTHIS, int bTouchAttack) = (char (__thiscall*)(CNWSCreatureStats *pTHIS, int bTouchAttack))0x00489B00;
int 			(__thiscall *CNWSCreatureStats__GetAttackModifierVersus)(CNWSCreatureStats *, CNWSCreature *) = (int (__thiscall *)(CNWSCreatureStats *, CNWSCreature *))0x00470F00;
int 			(__thiscall *CNWSCreatureStats__GetBaseAttackBonus)(CNWSCreatureStats *Stats, int bPreEpicOnly) = (int (__thiscall*)(CNWSCreatureStats *Stats, int bPreEpicOnly))0x0046ED40;
char 			(__thiscall *CNWSCreatureStats__GetDEXMod)(CNWSCreatureStats *pTHIS, int bMaxArmorDex) = (char (__thiscall*)(CNWSCreatureStats *pTHIS, int bMaxArmorDex))0x0047CAF0;
signed int 		(__thiscall *CNWSCreatureStats__GetEpicWeaponFocus)(CNWSCreatureStats *pTHIS, CNWSItem *weapon) = (signed int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSItem *weapon))0x00481510;
int 			(__thiscall *CNWSCreatureStats__GetFavoredEnemyBonus)(CNWSCreatureStats *pTHIS, CNWSCreature *cre_enemy) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSCreature *cre_enemy))0x00489E50;
int 			(__thiscall *CNWSCreatureStats__GetIsWeaponOfChoice)(CNWSCreatureStats *pTHIS, uint32_t BaseItemType) = (int (__thiscall*)(CNWSCreatureStats *pTHIS, uint32_t BaseItemType))0x0048CB10;
uint8_t			(__thiscall *CNWSCreatureStats__GetLevel)(CNWSCreatureStats *pTHIS, int bCountNegativeLevels) = (uint8_t (__thiscall*)(CNWSCreatureStats *pTHIS, int bCountNegativeLevels))0x0046DB40;
int				(__thiscall *CNWSCreatureStats__GetMeleeAttackBonus)(CNWSCreatureStats *, int, int, int) = (int (__thiscall *)(CNWSCreatureStats *, int, int, int))0x0046FB40;
signed int 		(__thiscall *CNWSCreatureStats__GetWeaponFinesse)(CNWSCreatureStats *pTHIS, CNWSItem *weapon) = (signed int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSItem *weapon))0x00481210;
signed int 		(__thiscall *CNWSCreatureStats__GetWeaponFocus)(CNWSCreatureStats *pTHIS, CNWSItem *weapon) = (signed int (__thiscall*)(CNWSCreatureStats *pTHIS, CNWSItem *weapon))0x004812E0;
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

