#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void				(__thiscall *CNWSCreature__ActivityManager)(CNWSCreature *pTHIS, unsigned long Activity) = (void(__thiscall*)(CNWSCreature *pTHIS, unsigned long Activity))0x00490630;
signed int 			(__thiscall *CNWSCreature__AcquireItem)(CNWSCreature *pTHIS, CNWSItem **Item, nwn_objid_t From_oID, nwn_objid_t a4, char a5, char a6, int a7, int a8) = (signed int (__thiscall*)(CNWSCreature *pTHIS, CNWSItem **Item, nwn_objid_t From_oID, nwn_objid_t a4, char a5, char a6, int a7, int a8))0x004C0580;
int 				(__thiscall *CNWSCreature__ApplyDiseasePayload)(CNWSCreature *pTHIS, CGameEffect *eff, unsigned long a3, unsigned long a4) = (int(__thiscall*)(CNWSCreature *pTHIS, CGameEffect *eff, unsigned long a3, unsigned long a4))0x004B0170;
int 				(__thiscall *CNWSCreature__ApplyPoisonPayload)(CNWSCreature *pTHIS, CGameEffect *eff, unsigned long t1, unsigned long t2) = (int(__thiscall*)(CNWSCreature *pTHIS, CGameEffect *eff, unsigned long t1, unsigned long t2))0x004B0770;
void				(__thiscall *CNWSCreature__CancelRest)(CNWSCreature *pTHIS, unsigned short a1) = (void(__thiscall*)(CNWSCreature *pTHIS, unsigned short a1))0x004A6840;
__int16 			(__thiscall *CNWSCreature__GetArmorClass)(CNWSCreature *pTHIS) = (__int16 (__thiscall*)(CNWSCreature *pTHIS))0x004A6E00;
int 				(__thiscall *CNWSCreature__GetRelativeWeaponSize)(CNWSCreature *pTHIS, CNWSItem *weapon) = (int (__thiscall*)(CNWSCreature *pTHIS, CNWSItem *weapon))0x004A6D00;
int 				(__thiscall *CNWSCreature__GetTotalEffectBonus)(CNWSCreature *pTHIS, char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10) = (int (__thiscall*)(CNWSCreature *pTHIS, char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10))0x004AB140;
int 				(__thiscall *CNWSCreature__GetBlind)(CNWSCreature *Cre) = (int (__thiscall*)(CNWSCreature *Cre))0x004AEB40;
CNWSFaction * 		(__thiscall *CNWSCreature__GetFaction)(CNWSCreature *pTHIS) = (CNWSFaction*(__thiscall*)(CNWSCreature *pTHIS))0x004C7770;
bool 				(__thiscall *CNWSCreature__GetFlanked)(CNWSCreature *pTHIS, CNWSCreature *Target) = (bool (__thiscall*)(CNWSCreature *pTHIS, CNWSCreature *Target))0x00551250;
int 				(__thiscall *CNWSCreature__GetFlatFooted)(CNWSCreature *pTHIS) = (int (__thiscall*)(CNWSCreature *pTHIS))0x00551170;
int 				(__thiscall *CNWSCreature__GetInvisible)(CNWSCreature *pTHIS, CNWSObject* obj, int i) = (int (__thiscall*)(CNWSCreature *pTHIS, CNWSObject* obj, int i))0x004AEB60;
int16_t				(__thiscall *CNWSCreature__GetMaxHitPoints)(CNWSCreature *pTHIS, int a1) = (int16_t(__thiscall*)(CNWSCreature *pTHIS, int a1))0x004A6ED0;
nwn_objid_t			(__thiscall *CNWSCreature__GetNearestEnemy)(CNWSCreature *pTHIS, float fDistance, unsigned long a2, int a3, int a4) = (nwn_objid_t(__thiscall*)(CNWSCreature *pTHIS, float fDistance, unsigned long a2, int a3, int a4))0x004A5570;
int 				(__thiscall *CNWSCreature__GetRangeWeaponEquipped)(CNWSCreature *pTHIS) = (int (__thiscall*)(CNWSCreature *pTHIS))0x00496460;
int 				(__thiscall *CNWSCreature__GetUseMonkAbilities)(CNWSCreature *pTHIS) = (int (__thiscall*)(CNWSCreature *pTHIS))0x0049E370;
CNWVisibilityNode * (__thiscall *CNWSCreature__GetVisibleListElement)(CNWSCreature *pTHIS, unsigned long ul) = (CNWVisibilityNode * (__thiscall*)(CNWSCreature *pTHIS, unsigned long ul))0x004C7FF0;
float 				(__thiscall *CNWSCreature__MaxAttackRange)(CNWSCreature *pTHIS, nwn_objid_t, int, int) = (float (__thiscall*)(CNWSCreature *pTHIS, nwn_objid_t, int, int))0x00498090;
void 				(__thiscall *CNWSCreature__NotifyAssociateActionToggle)(CNWSCreature *pTHIS, int Action) = (void(__thiscall*)(CNWSCreature *pTHIS, int Action))0x004B2A70;
void 				(__thiscall *CNWSCreature__PossessCreature)(CNWSCreature *pTHIS, nwn_objid_t oidPossessee) = (void (__thiscall*)(CNWSCreature *pTHIS, nwn_objid_t oidPossessee))0x004CD1B0;
void 				(__thiscall *CNWSCreature__PostProcess)(CNWSCreature *pTHIS) = (void (__thiscall*)(CNWSCreature *pTHIS))0x0049E450;
void 				(__thiscall *CNWSCreature__ReceiveAssociateCommand)(CNWSCreature *pTHIS, int a1) = (void(__thiscall*)(CNWSCreature *pTHIS, int a1))0x004CBC60;
void				(__thiscall *CNWSCreature__RemoveBadEffects)(CNWSCreature *pTHIS) = (void(__thiscall*)(CNWSCreature *pTHIS))0x004A6C20;
void				(__thiscall *CNWSCreature__RemoveFromArea)(CNWSCreature*, int AreaID) = (void (__thiscall *)(CNWSCreature*, int AreaID))0x004964C0;
signed int 			(__thiscall *CNWSCreature__RemoveItem)(CNWSCreature *pTHIS, CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6) = (signed int (__thiscall*)(CNWSCreature *pTHIS, CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6))0x004C0830;
void				(__thiscall *CNWSCreature__ResolveAttack)(CNWSCreature *pTHIS, int a2_target_oid, signed int a3, int a4) = (void (__thiscall*)(CNWSCreature *pTHIS, int a2_target_oid, signed int a3, int a4))0x00547580;
int					(__thiscall *CNWSCreature__ResolveRangedAttack)(CNWSCreature *Attacker_this, CNWSObject *Defender_a2, int nAttacks_a3, int a4) = (int (__thiscall*)(CNWSCreature *Attacker_this, CNWSObject *Defender_a2, int nAttacks_a3, int a4))0x00547880;
void*				(__thiscall *CNWSCreature__Rest)(CNWSCreature *pTHIS, int a2, int bCreatureToEnemyLineOfSightCheck) = (void*(__thiscall*)(CNWSCreature *pTHIS, int a2, int bCreatureToEnemyLineOfSightCheck))0x004A65C0;
void				(__thiscall *CNWSCreature__RestoreItemProperties)(CNWSCreature *pTHIS) = (void(__thiscall*)(CNWSCreature *pTHIS))0x004A4F20;
void 				(__thiscall *CNWSCreature__SendFeedbackMessage)(CNWSCreature *pTHIS, unsigned short, void*, CNWSPlayer *) = (void (__thiscall*)(CNWSCreature *pTHIS, unsigned short, void*, CNWSPlayer *))0x004AD4D0;
void 				(__thiscall *CNWSCreature__SetActivity)(CNWSCreature *pTHIS, int Activity, int bOn) = (void(__thiscall*)(CNWSCreature *pTHIS, int Activity, int bOn))0x00490690;
void				(__thiscall *CNWSCreature__SetAnimation)(CNWSCreature *pTHIS, int nAnim) = (void(__thiscall*)(CNWSCreature *pTHIS, int nAnim))0x004960C0;
void 				(__thiscall *CNWSCreature__SetCombatMode)(CNWSCreature *pTHIS, unsigned char Mode, int bOn) = (void(__thiscall*)(CNWSCreature *pTHIS, unsigned char Mode, int bOn))0x004BB4D0;
void				(__thiscall *CNWSCreature__SetQuickbarButton_Item)(CNWSCreature*, uint8_t, uint32_t, int, uint32_t) = (void (__thiscall *)(CNWSCreature*, uint8_t, uint32_t, int, uint32_t))0x004A8D20;
void				(__thiscall *CNWSCreature__SetQuickbarButton_Spell)(CNWSCreature*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t) = (void (__thiscall *)(CNWSCreature*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t))0x004A8D70;
void				(__thiscall *CNWSCreature__SetQuickbarButton_SpellLikeAbility)(CNWSCreature*, uint8_t, uint32_t, uint8_t) = (void (__thiscall *)(CNWSCreature*, uint8_t, uint32_t, uint8_t))0x004A8DD0;
void *				(__thiscall *CNWSCreature__SetScriptName)(CNWSCreature *pTHIS, signed int iScript, CExoString ScriptName) = (void* (__thiscall*)(CNWSCreature *pTHIS, signed int iScript, CExoString ScriptName))0x0049F8D0;
void				(__thiscall *CNWSCreature__StartGuiTimingBar)(CNWSCreature*, unsigned long, unsigned char) = (void (__thiscall *)(CNWSCreature*, unsigned long, unsigned char))0x004B1A90;
void				(__thiscall *CNWSCreature__StopGuiTimingBar)(CNWSCreature*) = (void (__thiscall *)(CNWSCreature*))0x004B1AF0;
void 				(__thiscall *CNWSCreature__SummonAssociate)(CNWSCreature *pTHIS, CResRef ResRef, CExoString ExoString, uint16_t Type) = (void (__thiscall*)(CNWSCreature *pTHIS, CResRef ResRef, CExoString ExoString, uint16_t Type))0x004CC6D0;
int 				(__thiscall *CNWSCreature__ToggleMode)(CNWSCreature* pTHIS, unsigned char Mode) = (int (__thiscall*)(CNWSCreature* pTHIS, unsigned char Mode))0x004A5080;
void 				(__thiscall *CNWSCreature__UnpossessCreature)(CNWSCreature *pTHIS) = (void(__thiscall*)(CNWSCreature *pTHIS))0x004CD450;
void 				(__thiscall *CNWSCreature__UpdateAutoMap)(CNWSCreature* pTHIS, uint32_t areaid) = (void (__thiscall*)(CNWSCreature* pTHIS, uint32_t areaid))0x00494C50;
void 				(__thiscall *CNWSCreature__UpdateEncumbranceState)(CNWSCreature *pTHIS, int bFeedback) = (void (__thiscall*)(CNWSCreature *pTHIS, int bFeedback))0x004CFC70;

void				(__thiscall *CNWSCreature__SetAutoMapData)(CNWSCreature *pTHIS, int a2, int a3, int a4) = (void(__thiscall*)(CNWSCreature *pTHIS, int a2, int a3, int a4))0x004B1DD0;
void 				(__thiscall *CNWSCreature__SetPVPPlayerLikesMe)(CNWSCreature *pTHIS, unsigned long oid_Player2, int a3, int a4) = (void(__thiscall*)(CNWSCreature *pTHIS, unsigned long oid_Player2, int a3, int a4))0x004D0450;

CNWSCreature*		(__thiscall *CNWSCreature__CNWSCreature)(CNWSCreature *pTHIS, int a2, unsigned int a3, unsigned int a4) = (CNWSCreature*(__thiscall*)(CNWSCreature *pTHIS, int a2, unsigned int a3, unsigned int a4))0x0048F5B0;
void				(__thiscall *CNWSCreature___CNWSCreature)(CNWSCreature *pTHIS) = (void(__thiscall*)(CNWSCreature *pTHIS))0x00490000;
char				(__thiscall *CNWSCreature__CalculateDamagePower)(CNWSCreature *pTHIS, CNWSObject *Defender, int bOffHand) = (char(__thiscall*)(CNWSCreature *pTHIS, CNWSObject *Defender, int bOffHand))0x004A7620;

//void Destructor(char c) {
	//CNWSCreature__dtor_CNWSCreature(this, c);
//}

CNWSCreature_s::CNWSCreature_s(int a2, unsigned int a3, unsigned int a4) {
	CNWSCreature__CNWSCreature(this, a2, a3, a4);
}

CNWSCreature_s::~CNWSCreature_s() {
	CNWSCreature___CNWSCreature(this);
}

signed int CNWSCreature_s::AcquireItem(CNWSItem **Item, nwn_objid_t From_oID, nwn_objid_t a4, char a5, char a6, int a7, int bUpdateEncumbrance) {
	return CNWSCreature__AcquireItem(this, Item, From_oID, a4, a5, a6, a7, bUpdateEncumbrance);
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

void CNWSCreature_s::PossessCreature(nwn_objid_t oid_Possessee) {
	CNWSCreature__PossessCreature(this, oid_Possessee);
}

void CNWSCreature_s::SummonAssociate(CResRef ResRef, CExoString Name, uint16_t Type) {
	CNWSCreature__SummonAssociate(this, ResRef, Name, Type);
}

int CNWSCreature_s::GetUseMonkAbilities() {
	return CNWSCreature__GetUseMonkAbilities(this);
}

void CNWSCreature_s::UpdateEncumbranceState(int bFeedback) {
	return CNWSCreature__UpdateEncumbranceState(this, bFeedback);
}

void CNWSCreature_s::SetAutoMapData(int a2, int a3, int a4) {
	CNWSCreature__SetAutoMapData(this, a2, a3, a4);
}

void CNWSCreature_s::SetPVPPlayerLikesMe(unsigned long oid_Player2, int a3, int a4) {
	CNWSCreature__SetPVPPlayerLikesMe(this, oid_Player2, a3, a4);
}

int CNWSCreature_s::GetDamageFlags() {
	CNWSCombatRound *CRound = cre_combat_round;
	CNWSCombatAttackData *AttackData = CRound->GetAttack(CRound->CurrentAttack);
	CNWSItem *Weapon = CRound->GetCurrentAttackWeapon(AttackData->WeaponAttackType);

	if (Weapon) {
		return Weapon->GetDamageFlags();
	}

	return 1;
}

void CNWSCreature_s::SetActivity(int Activity, int bOn) {
	CNWSCreature__SetActivity(this, Activity, bOn);
}

void CNWSCreature_s::SetCombatMode(int Mode, int bOn) {
	CNWSCreature__SetCombatMode(this, Mode, bOn);
}

int CNWSCreature_s::ToggleMode(unsigned char Mode) {
	return CNWSCreature__ToggleMode(this, Mode);
}

void CNWSCreature_s::NotifyAssociateActionToggle(int Action) {
	CNWSCreature__NotifyAssociateActionToggle(this, Action);
}

int CNWSCreature_s::GetArmorClass() {
	return CNWSCreature__GetArmorClass(this);
}

int CNWSCreature_s::ApplyPoisonPayload(CGameEffect *eff, unsigned long t1, unsigned long t2) {
	return CNWSCreature__ApplyPoisonPayload(this, eff, t1, t2);
}

void *CNWSCreature_s::Rest(int a2, int bCreatureToEnemyLineOfSightCheck) {
	return CNWSCreature__Rest(this, a2, bCreatureToEnemyLineOfSightCheck);
}

void CNWSCreature_s::ReceiveAssociateCommand(int a1) {
	CNWSCreature__ReceiveAssociateCommand(this, a1);
}

void CNWSCreature_s::ActivityManager(unsigned long Activity) {
	CNWSCreature__ActivityManager(this, Activity);
}

void CNWSCreature_s::CancelRest(unsigned short a1) {
	CNWSCreature__CancelRest(this, a1);
}

void CNWSCreature_s::SetAnimation(int nAnim) {
	CNWSCreature__SetAnimation(this, nAnim);
}

nwn_objid_t CNWSCreature_s::GetNearestEnemy(float fDistance, unsigned long a2, int a3, int a4) {
	return CNWSCreature__GetNearestEnemy(this, fDistance, a2, a3, a4);
}

void CNWSCreature_s::RemoveBadEffects() {
	CNWSCreature__RemoveBadEffects(this);
}

int CNWSCreature_s::ApplyDiseasePayload(CGameEffect *eff, unsigned long a3, unsigned long a4) {
	return CNWSCreature__ApplyDiseasePayload(this, eff, a3, a4);
}

void CNWSCreature_s::RestoreItemProperties() {
	CNWSCreature__RestoreItemProperties(this);
}

int16_t CNWSCreature_s::GetMaxHitPoints(int a2) {
	return CNWSCreature__GetMaxHitPoints(this, a2);
}

void CNWSCreature_s::UnpossessCreature() {
	CNWSCreature__UnpossessCreature(this);
}

CNWSFaction * CNWSCreature_s::GetFaction() {
	return CNWSCreature__GetFaction(this);
}

char CNWSCreature_s::CalculateDamagePower(CNWSObject* Defender, int bOffhand) {
	return CNWSCreature__CalculateDamagePower(this, Defender, bOffhand);
}