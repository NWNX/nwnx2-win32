#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int16_t			(__thiscall *CNWSObject__ApplyEffect)(CNWSObject *pTHIS, CGameEffect *Effect_a2, int a3, int a4) = (int16_t (__thiscall*)(CNWSObject *pTHIS, CGameEffect *Effect_a2, int a3, int a4))0x004E27A0;
void 			(__thiscall *CNWSObject__ClearSpellEffectsOnOthers)(CNWSObject *pTHIS) = (void(__thiscall*)(CNWSObject *pTHIS))0x004E3E20;
int				(__thiscall *CNWSObject__DoDamageImmunity)(CNWSObject *pTHIS, CNWSCreature *Attacker, int DamageDelivered, int DamageFlags, int _bMaxDamage, int bFeedback) = (int(__thiscall*)(CNWSObject *pTHIS, CNWSCreature *Attacker, int DamageDelivered, int DamageFlags, int _bMaxDamage, int bFeedback))0x004E1A00;
int				(__thiscall *CNWSObject__DoDamageResistance)(CNWSObject *pTHIS, CNWSCreature *a2, int a3, signed int a4, int a5, int a6, int a7) = (int(__thiscall*)(CNWSObject *pTHIS, CNWSCreature *a2, int a3, signed int a4, int a5, int a6, int a7))0x004E07D0;
int16_t			(__thiscall *CNWSObject__GetCurrentHitPoints)(CNWSObject *pTHIS, int bExcludeTemp) = (int16_t(__thiscall*)(CNWSObject *pTHIS, int bExcludeTemp))0x004DFDA0;
char			(__thiscall *CNWSObject__GetDamageImmunityByFlags)(CNWSObject_s *pTHIS, uint16_t Flags) = (char (__thiscall *)(CNWSObject_s * pTHIS, uint16_t))0x004E1D50;
int 			(__thiscall *CNWSObject__GetIsPCDying)(CNWSObject *pTHIS) = (int(__thiscall*)(CNWSObject *pTHIS))0x004E5A60;
int				(__thiscall *CNWSObject__RemoveEffectById)(CNWSObject_s *pTHIS, uint64_t EffID) = (int (__thiscall *)(CNWSObject_s *pTHIS, uint64_t EffID))0x004E2DE0;
CNWSArea * 		(__thiscall *CNWSObject__GetArea)(CNWSObject_s *pTHIS) = (CNWSArea* (__thiscall *)(CNWSObject_s *pTHIS))0x004E3F50;
void 			(__thiscall *CNWSObject__SetTag)(CNWSObject_s *pTHIS, CExoString sTag) = (void (__thiscall*)(CNWSObject_s *pTHIS, CExoString sTag))0x00466360;
int 			(__thiscall *CNWSObject__GetDead)(CNWSObject_s *pTHIS) = (int (__thiscall*)(CNWSObject_s *pTHIS))0x004E59D0;
unsigned int 	(__thiscall *CNWSObject__SetArea)(CNWSObject_s *pTHIS, CNWSArea *Area) = (unsigned int (__thiscall*)(CNWSObject_s *pTHIS, CNWSArea *Area))0x004E3F90;
int 			(__thiscall *CNWSObject__GetMaximumDamageResistanceVsDamageFlag)(CNWSObject_s *pTHIS, uint16_t DamageType, int *EffectIndex) = (int (__thiscall*)(CNWSObject_s *pTHIS, uint16_t DamageType, int *EffectIndex))0x004E1920;
void 			(__thiscall *CNWSObject__SaveVarTable)(CNWSObject *pTHIS, CResGFF *pResGFF, CResStruct *pResStruct) = (void(__thiscall*)(CNWSObject *pTHIS, CResGFF *pResGFF, CResStruct *pResStruct))0x004DEF40;
void 			(__thiscall *CNWSObject__LoadVarTable)(CNWSObject *pTHIS, CResGFF *pResGFF, CResStruct *pResStruct) = (void(__thiscall*)(CNWSObject *pTHIS, CResGFF *pResGFF, CResStruct *pResStruct))0x004DEF20;
void 			(__thiscall *CNWSObject__SetPosition)(CNWSObject *pTHIS, Vector v, int a3) = (void(__thiscall*)(CNWSObject *pTHIS, Vector v, int a3))0x004E25D0;
void 			(__thiscall *CNWSObject__SetOrientation)(CNWSObject *pTHIS, Vector v) = (void(__thiscall*)(CNWSObject *pTHIS, Vector v))0x004E25B0;
void *			(__thiscall *CNWSObject__BroadcastDialog)(CNWSObject *pTHIS, CExoString Msg, float Max_Distance) = (void*(__thiscall*)(CNWSObject *pTHIS, CExoString Msg, float Max_Distance))0x004E54B0;

CNWSItem *CNWSObject_s::AsNWSItem() {
	return ((CNWSItem*)((char*)this-0x10));
}

CNWSModule *CNWSObject_s::AsModule() {
	return ((CNWSModule*)((char*)this-0x1C));
}

CNWSAreaOfEffectObject *CNWSObject_s::AsNWSAreaOfEffectObject() {
	return (CNWSAreaOfEffectObject*)this;
	
}

CNWSArea *CNWSObject_s::AsNWSArea() {
	return ((CNWSArea*)((char*)this-0xC4));
}

CNWSStore *CNWSObject_s::AsNWSStore() {
	return (CNWSStore*)this;
}


CNWSArea *CNWSObject_s::GetArea() {
	return CNWSObject__GetArea(this);
}

char CNWSObject_s::GetDamageImmunityByFlags(uint16_t Flags) {
	return CNWSObject__GetDamageImmunityByFlags(this, Flags);
}

int CNWSObject_s::GetDead() {
	return CNWSObject__GetDead(this);
}

int CNWSObject_s::RemoveEffectById(uint64_t EffID) {
	return CNWSObject__RemoveEffectById(this, EffID);
}

unsigned int  CNWSObject_s::SetArea(CNWSArea *Area) {
	return CNWSObject__SetArea(this, Area);
}

void  CNWSObject_s::SetTag(CExoString sTag) {
	CNWSObject__SetTag(this, sTag);
}

int CNWSObject_s::GetMaximumDamageResistanceVsDamageFlag(uint16_t DamageType, int *EffectIndex) {
	return CNWSObject__GetMaximumDamageResistanceVsDamageFlag(this, DamageType, EffectIndex);
}

int16_t CNWSObject_s::ApplyEffect(CGameEffect *Effect, int a3, int a4) {
	return CNWSObject__ApplyEffect(this, Effect, a3, a4);
}

int CNWSObject_s::DoDamageImmunity(CNWSCreature *Attacker, int DamageDelivered, int DamageFlags, int _bMaxDamage, int bFeedback) {
	return CNWSObject__DoDamageImmunity(this, Attacker, DamageDelivered, DamageFlags, _bMaxDamage, bFeedback);
}

int	CNWSObject_s::DoDamageResistance(CNWSCreature *a2, int a3, signed int a4, int a5, int a6, int a7) {
	return CNWSObject__DoDamageResistance(this, a2, a3, a4, a5, a6, a7);
}

int CNWSObject_s::GetIsPCDying() {
	return CNWSObject__GetIsPCDying(this);
}

void CNWSObject::ClearSpellEffectsOnOthers() {
	return CNWSObject__ClearSpellEffectsOnOthers(this);
}

int16_t CNWSObject_s::GetCurrentHitPoints(int bExcludeTemp) {
	return CNWSObject__GetCurrentHitPoints(this, bExcludeTemp);
}

void CNWSObject_s::SaveVarTable(CResGFF *pResGFF, CResStruct *pResStruct) {
	CNWSObject__SaveVarTable(this, pResGFF, pResStruct);
}

void CNWSObject_s::LoadVarTable(CResGFF *pResGFF, CResStruct *pResStruct) {
	CNWSObject__LoadVarTable(this, pResGFF, pResStruct);
}

void CNWSObject_s::SetPosition(Vector v, int a3) {
	CNWSObject__SetPosition(this, v, a3);
}

void CNWSObject_s::SetOrientation(Vector v) {
	CNWSObject__SetOrientation(this, v);
}

void *CNWSObject_s::BroadcastDialog(CExoString Msg, float Max_Distance) {
	return CNWSObject__BroadcastDialog(this, Msg, Max_Distance);
}