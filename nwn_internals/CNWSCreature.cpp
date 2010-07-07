#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

signed int 			(__thiscall *CNWSCreature__AcquireItem)(CNWSCreature *pTHIS, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack) = (signed int (__thiscall*)(CNWSCreature *pTHIS, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack))0x004C0580;
int 				(__thiscall *CNWSCreature__GetRelativeWeaponSize)(CNWSCreature *pTHIS, CNWSItem *weapon) = (int (__thiscall*)(CNWSCreature *pTHIS, CNWSItem *weapon))0x004A6D00;
int 				(__thiscall *CNWSCreature__GetTotalEffectBonus)(CNWSCreature *pTHIS, char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10) = (int (__thiscall*)(CNWSCreature *pTHIS, char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10))0x004AB140;
int 				(__thiscall *CNWSCreature__GetBlind)(CNWSCreature *Cre) = (int (__thiscall*)(CNWSCreature *Cre))0x004AEB40;
bool 				(__thiscall *CNWSCreature__GetFlanked)(CNWSCreature *pTHIS, CNWSCreature *Target) = (bool (__thiscall*)(CNWSCreature *pTHIS, CNWSCreature *Target))0x00551250;
int 				(__thiscall *CNWSCreature__GetFlatFooted)(CNWSCreature *pTHIS) = (int (__thiscall*)(CNWSCreature *pTHIS))0x00551170;
int 				(__thiscall *CNWSCreature__GetInvisible)(CNWSCreature *pTHIS, CNWSObject* obj, int i) = (int (__thiscall*)(CNWSCreature *pTHIS, CNWSObject* obj, int i))0x004AEB60;
int 				(__thiscall *CNWSCreature__GetRangeWeaponEquipped)(CNWSCreature *pTHIS) = (int (__thiscall*)(CNWSCreature *pTHIS))0x00496460;
CNWVisibilityNode * (__thiscall *CNWSCreature__GetVisibleListElement)(CNWSCreature *pTHIS, unsigned long ul) = (CNWVisibilityNode * (__thiscall*)(CNWSCreature *pTHIS, unsigned long ul))0x004C7FF0;
float 				(__thiscall *CNWSCreature__MaxAttackRange)(CNWSCreature *pTHIS, nwn_objid_t, int, int) = (float (__thiscall*)(CNWSCreature *pTHIS, nwn_objid_t, int, int))0x00498090;
void 				(__thiscall *CNWSCreature__PostProcess)(CNWSCreature *pTHIS) = (void (__thiscall*)(CNWSCreature *pTHIS))0x0049E450;
void				(__thiscall *CNWSCreature__RemoveFromArea)(CNWSCreature*, int AreaID) = (void (__thiscall *)(CNWSCreature*, int AreaID))0x004964C0;
signed int 			(__thiscall *CNWSCreature__RemoveItem)(CNWSCreature *pTHIS, CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6) = (signed int (__thiscall*)(CNWSCreature *pTHIS, CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6))0x004C0830;
void				(__thiscall *CNWSCreature__ResolveAttack)(CNWSCreature *pTHIS, int a2_target_oid, signed int a3, int a4) = (void (__thiscall*)(CNWSCreature *pTHIS, int a2_target_oid, signed int a3, int a4))0x00547580;
int					(__thiscall *CNWSCreature__ResolveRangedAttack)(CNWSCreature *Attacker_this, CNWSObject *Defender_a2, int nAttacks_a3, int a4) = (int (__thiscall*)(CNWSCreature *Attacker_this, CNWSObject *Defender_a2, int nAttacks_a3, int a4))0x00547880;
void 				(__thiscall *CNWSCreature__SendFeedbackMessage)(CNWSCreature *pTHIS, unsigned short, void*, CNWSPlayer *) = (void (__thiscall*)(CNWSCreature *pTHIS, unsigned short, void*, CNWSPlayer *))0x004AD4D0;
void				(__thiscall *CNWSCreature__SetQuickbarButton_Item)(CNWSCreature*, uint8_t, uint32_t, int, uint32_t) = (void (__thiscall *)(CNWSCreature*, uint8_t, uint32_t, int, uint32_t))0x004A8D20;
void				(__thiscall *CNWSCreature__SetQuickbarButton_Spell)(CNWSCreature*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t) = (void (__thiscall *)(CNWSCreature*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t))0x004A8D70;
void				(__thiscall *CNWSCreature__SetQuickbarButton_SpellLikeAbility)(CNWSCreature*, uint8_t, uint32_t, uint8_t) = (void (__thiscall *)(CNWSCreature*, uint8_t, uint32_t, uint8_t))0x004A8DD0;
void *				(__thiscall *CNWSCreature__SetScriptName)(CNWSCreature *pTHIS, signed int iScript, CExoString ScriptName) = (void* (__thiscall*)(CNWSCreature *pTHIS, signed int iScript, CExoString ScriptName))0x0049F8D0;
void				(__thiscall *CNWSCreature__StartGuiTimingBar)(CNWSCreature*, unsigned long, unsigned char) = (void (__thiscall *)(CNWSCreature*, unsigned long, unsigned char))0x004B1A90;
void				(__thiscall *CNWSCreature__StopGuiTimingBar)(CNWSCreature*) = (void (__thiscall *)(CNWSCreature*))0x004B1AF0;
void 				(__thiscall *CNWSCreature__UpdateAutoMap)(CNWSCreature* pTHIS, uint32_t areaid) = (void (__thiscall*)(CNWSCreature* pTHIS, uint32_t areaid))0x00494C50;


//void Destructor(char c) {
	//CNWSCreature__dtor_CNWSCreature(this, c);
//}

signed int CNWSCreature_s::AcquireItem(CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack) {
	return CNWSCreature__AcquireItem(this, a2, a3, a4, a5, bSendFeedBack);
}

int CNWSCreature_s::GetBlind() {
	return CNWSCreature__GetBlind(this);
}

bool CNWSCreature_s::GetFlanked(CNWSCreature *Target) {
	return CNWSCreature__GetFlanked(this, Target);
}

int CNWSCreature_s::GetFlatFooted() {
	return CNWSCreature__GetFlatFooted(this);
}

int CNWSCreature_s::GetInvisible(CNWSObject* obj, int i) {
	return CNWSCreature__GetInvisible(this, obj, i);
}

int CNWSCreature_s::GetRangeWeaponEquipped() {
	return CNWSCreature__GetRangeWeaponEquipped(this);
}

int CNWSCreature_s::GetRelativeWeaponSize(CNWSItem *weapon) {
	return CNWSCreature__GetRelativeWeaponSize(this, weapon);
}

int CNWSCreature_s::GetTotalEffectBonus(char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10) {
	return CNWSCreature__GetTotalEffectBonus(this, a2, obj_a, a4, a5,  a6, a7, a8, a9, a10);
}

CNWVisibilityNode *CNWSCreature_s::GetVisibleListElement(unsigned long ul) {
	return CNWSCreature__GetVisibleListElement(this, ul);
}

float CNWSCreature_s::MaxAttackRange(nwn_objid_t ID, int a, int b) {
	return CNWSCreature__MaxAttackRange(this, ID, a, b);
}

void CNWSCreature_s::PostProcess() {
	CNWSCreature__PostProcess(this);
}

void CNWSCreature_s::RemoveFromArea(int AreaID) {
	CNWSCreature__RemoveFromArea(this, AreaID);
}

signed int CNWSCreature_s::RemoveItem(CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6) {
	return CNWSCreature__RemoveItem(this, a2, a3, bSendFeedBack, a5, a6);
}

void CNWSCreature_s::ResolveAttack(int a2_target_oid, signed int a3, int a4) {
	CNWSCreature__ResolveAttack(this, a2_target_oid, a3, a4);
}

int CNWSCreature_s::ResolveRangedAttack(CNWSObject *Defender_a2, int nAttacks_a3, int a4) {
	return CNWSCreature__ResolveRangedAttack(this, Defender_a2, nAttacks_a3, a4);
}

void CNWSCreature_s::SendFeedbackMessage(unsigned short a1, void* a2, CNWSPlayer *a3) {
	CNWSCreature__SendFeedbackMessage(this, a1, a2, a3);
}

void *CNWSCreature_s::SetScriptName(signed int iScript, CExoString ScriptName) {
	return CNWSCreature__SetScriptName(this, iScript, ScriptName);
}

void CNWSCreature_s::StartGuiTimingBar(unsigned long a, unsigned char b) {
	CNWSCreature__StartGuiTimingBar(this, a, b);
}

void CNWSCreature_s::StopGuiTimingBar() {
	CNWSCreature__StopGuiTimingBar(this);
}

void CNWSCreature_s::UpdateAutoMap(uint32_t areaid) {
	CNWSCreature__UpdateAutoMap(this, areaid);
}

