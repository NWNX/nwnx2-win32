#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

char			(__thiscall *CNWSObject__GetDamageImmunityByFlags)(CNWSObject_s *pTHIS, uint16_t Flags) = (char (__thiscall *)(CNWSObject_s * pTHIS, uint16_t))0x004E1D50;
int				(__thiscall *CNWSObject__RemoveEffectById)(CNWSObject_s *pTHIS, uint64_t EffID) = (int (__thiscall *)(CNWSObject_s *pTHIS, uint64_t EffID))0x004E2DE0;
CNWSArea * 		(__thiscall *CNWSObject__GetArea)(CNWSObject_s *pTHIS) = (CNWSArea* (__thiscall *)(CNWSObject_s *pTHIS))0x004E3F50;
void 			(__thiscall *CNWSObject__SetTag)(CNWSObject_s *pTHIS, CExoString sTag) = (void (__thiscall*)(CNWSObject_s *pTHIS, CExoString sTag))0x00466360;
int 			(__thiscall *CNWSObject__GetDead)(CNWSObject_s *pTHIS) = (int (__thiscall*)(CNWSObject_s *pTHIS))0x004E59D0;
unsigned int 	(__thiscall *CNWSObject__SetArea)(CNWSObject_s *pTHIS, CNWSArea *Area) = (unsigned int (__thiscall*)(CNWSObject_s *pTHIS, CNWSArea *Area))0x004E3F90;
int 			(__thiscall *CNWSObject__GetMaximumDamageResistanceVsDamageFlag)(CNWSObject_s *pTHIS, uint16_t DamageType, int *EffectIndex) = (int (__thiscall*)(CNWSObject_s *pTHIS, uint16_t DamageType, int *EffectIndex))0x004E1920;
int16_t			(__thiscall *CNWSObject__ApplyEffect)(CNWSObject *pTHIS, CGameEffect *Effect_a2, int a3, int a4) = (int16_t (__thiscall*)(CNWSObject *pTHIS, CGameEffect *Effect_a2, int a3, int a4))0x004E27A0;

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