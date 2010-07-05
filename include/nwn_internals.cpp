#include "stdafx.h"
#include ".\types.h"

// Internal function calls definitions

CAppManager **NWN_AppManager = (CAppManager**)0x0066c050;
CVirtualMachine **NWN_VirtualMachine = (CVirtualMachine**)0x0066C048;
CTlkTable **NWN_CTlkTable = (CTlkTable**)0x0066C054;
CNWTlkTable **NWN_CNWTlkTable = (CNWTlkTable**)0x0066C058;
CNWRules **NWN_Rules = (CNWRules**)0x0066c060;
CExoResMan **NWN_ResMan = (CExoResMan**)0x0066C044;

CNWSPlayer* 	(__fastcall *CServerExoApp__GetClientObjectByObjectId)(CServerExoApp*, void*, uint32_t) = (CNWSPlayer *(__fastcall *)(CServerExoApp*, void*, uint32_t))0x0042cd20;
CGenericObject* (__fastcall *CServerExoApp__GetGameObject)(CServerExoApp*, void*, uint32_t/*oID*/) = (CGenericObject* (__fastcall *)(CServerExoApp*, void*, uint32_t))0x0042C810;

CNWSModule*		(__fastcall *CServerExoAppInternal__GetModule)(CServerExoAppInternal *, void*) = (CNWSModule* (__fastcall *)(CServerExoAppInternal*, void*))0x004530A0;

int 			(__fastcall *CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton)(CNWSMessage*, void *, CNWSPlayer*, uint8_t, int32_t) = (int (__fastcall *)(CNWSMessage*, void *, CNWSPlayer *, uint8_t, int32_t))0x044E950; 

int				(__fastcall *CNWSMessage__SendServerToPlayerGameObjUpdate)(CNWSMessage*, void*, CNWSPlayer *) = (int (__fastcall *)(CNWSMessage*, void*, CNWSPlayer *))0x00440110;

void			(__fastcall *CWorldTimer__GetWorldTime)(CWorldTimer*, void*, uint32_t *, uint32_t *) = (void (__fastcall *)(CWorldTimer*, void*, uint32_t *, uint32_t *))0x005BA630;
void			(__fastcall *CWorldTimer__SetWorldTime)(CWorldTimer*, void*, uint32_t, uint32_t, int) = (void (__fastcall *)(CWorldTimer*, void*, uint32_t, uint32_t, int))0x005BA590;
unsigned long 	(__fastcall *CWorldTimer__SubtractWorldTimes)(CWorldTimer *pTHIS, void *pVOID, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *) = (unsigned long (__fastcall *)(CWorldTimer *pTHIS, void *pVOID, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *))0x005BA7B0;

void			(__fastcall *CNWSModule__AddObjectToLimbo)(CNWSModule*, void*, uint32_t) = (void (__fastcall *)(CNWSModule*, void*, uint32_t))0x004DB3D0;

char			(__fastcall *CNWSObject__GetDamageImmunityByFlags)(CNWSObject*, void*, uint16_t) = (char (__fastcall *)(CNWSObject*, void*, uint16_t))0x004E1D50;
int				(__fastcall *CNWSObject__RemoveEffectById)(CNWSObject*, void*, unsigned __int64) = (int (__fastcall *)(CNWSObject*, void*, unsigned __int64))0x004E2DE0;

void			(__fastcall *CNWSCreature__RemoveFromArea)(CNWSCreature*, void*, int) = (void (__fastcall *)(CNWSCreature*, void*, int))0x004964C0;

void			(__fastcall *CNWSCreature__StartGuiTimingBar)(CNWSCreature*, void*, unsigned long, unsigned char) = (void (__fastcall *)(CNWSCreature*, void*, unsigned long, unsigned char))0x004B1A90;
void			(__fastcall *CNWSCreature__StopGuiTimingBar)(CNWSCreature*, void*) = (void (__fastcall *)(CNWSCreature*, void*))0x004B1AF0;
////////

void			(__fastcall *CNWMessage__CreateWriteMessage)(CNWSMessage*, void*, uint32_t, nwn_objid_t, uint32_t) = (void (__fastcall *)(CNWSMessage*, void*, uint32_t, nwn_objid_t, uint32_t))0x00507E30;
void			(__fastcall *CNWSMessage__WriteGameObjUpdate_UpdateObject)(CNWSMessage*, void*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t) = (void (__fastcall *)(CNWSMessage*, void*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t))0x00445160;
void			(__fastcall *CNWSMessage__WriteGameObjUpdate_UpdateAppearance)(CNWSMessage*, void* , CNWSObject*, CLastUpdateObject*, uint32_t) = (void (__fastcall *)(CNWSMessage*, void* , CNWSObject*, CLastUpdateObject*, uint32_t))0x0043E9C0;

													  //(*pMessage,    NULL,  **ppData,        *pLength)				 
int				(__fastcall *CNWMessage__GetWriteMessage)(CNWSMessage*, void*, uint8_t**, uint64_t*) = (int (__fastcall *)(CNWSMessage*, void*, uint8_t**, uint64_t*))0x00508B80;

																 //(*pMessage,    NULL,  nPlayerID,   type,          subtype,       *dataPtr,        length);
int				(__fastcall *CNWSMessage__SendServerToPlayerMessage)(CNWSMessage*, void*, nwn_objid_t, uint8_t, uint8_t, uint8_t *, uint32_t) = (int (__fastcall *)(CNWSMessage*, void*, nwn_objid_t, uint8_t, uint8_t, uint8_t *, uint32_t))0x00449F40;

void *			(__fastcall *CServerExoApp__GetNWSMessage)(CServerExoApp*, void *) = (void * (__fastcall *)(CServerExoApp*, void *))0x0042C940;

int				(__fastcall *CGameEffect__GetScriptEffectType)(CGameEffect*, void*) = (int (__fastcall *)(CGameEffect*, void*))0x004E8CD0;
/*
void			(__fastcall *CNWSCreature__SetQuickbarButton_AssociateCommand)(CNWSCreature*, void*, uint8_t, int, uint16_t, uint32_t) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, int, uint16_t, uint32_t))0x004A8E10;
void			(__fastcall *CNWSCreature__SetQuickbarButton_CommandLine)(CNWSCreature*, void*, uint8_t, class CExoString const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CExoString const &, class CExoString const &))0x004A9100;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DM_General_ResRefParam)(CNWSCreature*, void*, uint8_t, uint8_t, CResRef const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint8_t, class CResRef const &))0x004A9160;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateCreature)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8E60;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateEncounter)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8F20;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateItem)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8EC0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePlaceable)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A90A0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePortal)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A9040;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateTrigger)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8FE0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateWaypoint)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8F80;
void			(__fastcall *CNWSCreature__SetQuickbarButton_GeneralINTParam)(CNWSCreature*, void*, uint8_t, uint8_t, int) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint8_t, int))0x004A91E0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_GeneralNoParam)(CNWSCreature*, void*, uint8_t, uint8_t) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint8_t))0x004A91B0;
*/
void			(__fastcall *CNWSCreature__SetQuickbarButton_Item)(CNWSCreature*, void*, uint8_t, uint32_t, int, uint32_t) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint32_t, int, uint32_t))0x004A8D20;
void			(__fastcall *CNWSCreature__SetQuickbarButton_Spell)(CNWSCreature*, void*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint8_t, uint32_t, uint8_t, uint8_t))0x004A8D70;
void			(__fastcall *CNWSCreature__SetQuickbarButton_SpellLikeAbility)(CNWSCreature*, void*, uint8_t, uint32_t, uint8_t) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint32_t, uint8_t))0x004A8DD0;

void			(__fastcall *CNWSCombatRound__ClearAllAttacks)(CNWSCombatRound* pTHIS, void *pVOID) = (void (__fastcall*)(CNWSCombatRound* pTHIS, void *pVOID))0x00530980;
int				(__fastcall *CNWSCreature__ResolveRangedAttack)(CNWSCreature *Attacker_this, void* pVOID, CNWSObject *Defender_a2, int nAttacks_a3, int a4) = (int (__fastcall*)(CNWSCreature *Attacker_this, void* pVOID, CNWSObject *Defender_a2, int nAttacks_a3, int a4))0x00547880;
int 			(__fastcall *CNWSCreatureStats__GetAttackModifierVersus)(CNWSCreatureStats *, void*, CNWSCreature *) = (int (__fastcall *)(CNWSCreatureStats *, void*, CNWSCreature *))0x00470F00;
CNWSCreature*	(__fastcall *CServerExoAppInternal__GetCreatureByGameObjectID)(CServerExoAppInternal*, void*, unsigned long) = (CNWSCreature * (__fastcall *)(CServerExoAppInternal*, void*, unsigned long))0x0045C020;

int				(__fastcall *CNWSCreatureStats__GetMeleeAttackBonus)(CNWSCreatureStats *, void *, int, int, int) = (int (__fastcall *)(CNWSCreatureStats *, void *, int, int, int))0x0046FB40;

//unsigned char 	(__thiscall *CNWSCreatureStats__GetAttacksPerRound)(CNWSCreatureStats *, void *) = (unsigned char
////////
//crash
void			(__fastcall *CServerExoAppInternal__UpdateClientGameObjectsForPlayer)(CServerExoAppInternal*, void*, CNWSPlayer*, int, uint64_t) = (void (__fastcall*)(CServerExoAppInternal*, void*, CNWSPlayer*, int, uint64_t))0x0045B7A0;

CNWSItem*		(__fastcall *CNWSInventory__GetItemInSlot)(CNWSInventory* inventory, void* pVOID, unsigned long nSlot) = (CNWSItem* (__fastcall*)(CNWSInventory* inventory, void* pVOID, unsigned long nSlot))0x00502240;
int 			(__fastcall *CNWSCreatureStats__GetBaseAttackBonus)(CNWSCreatureStats *Stats, void* pVOID, int bPreEpicOnly) = (int (__fastcall*)(CNWSCreatureStats *Stats, void* pVOID, int bPreEpicOnly))0x0046ED40;
CNWBaseItem *	(__fastcall *CNWBaseItemArray__GetBaseItem)(CNWBaseItemArray *pTHIS, void *pVOID, int baseItem) = (CNWBaseItem* (__fastcall*)(CNWBaseItemArray *pTHIS, void *pVOID, int baseItem))0x00512AF0;
int 			(__fastcall *CNWSCreature__GetRelativeWeaponSize)(CNWSCreature *pTHIS, void *pVOID, CNWSItem *weapon) = (int (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, CNWSItem *weapon))0x004A6D00;
int 			(__fastcall *CNWSCreatureStats__HasFeat)(CNWSCreatureStats *Stats, void *pVOID, uint16_t feat) = (int (__fastcall*)(CNWSCreatureStats *Stats, void *pVOID, uint16_t feat))0x0047ECF0;
int 			(__fastcall *CNWSCreatureStats__ResolveSpecialAttackAttackBonus)(CNWSCreatureStats *pAttackerStats, void* pVOID, CNWSCreature *Defender) = (int (__fastcall*)(CNWSCreatureStats *pAttackerStats, void* pVOID, CNWSCreature *Defender))0x004744F0;
CNWSArea * 		(__fastcall *CNWSObject__GetArea)(CNWSObject *pTHIS, void*) = (CNWSArea* (__fastcall *)(CNWSObject *pTHIS, void*))0x004E3F50;
int 			(__fastcall *CNWSCreatureStats__GetIsWeaponOfChoice)(CNWSCreatureStats *pTHIS, void *pVOID, uint32_t BaseItemType) = (int (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, uint32_t BaseItemType))0x0048CB10;
int 			(__fastcall *CNWSCreatureStats__GetFavoredEnemyBonus)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSCreature *cre_enemy) = (int (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSCreature *cre_enemy))0x00489E50;
char 			(__fastcall *CNWSCreatureStats__GetDEXMod)(CNWSCreatureStats *pTHIS, void *pVOID, int bMaxArmorDex) = (char (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, int bMaxArmorDex))0x0047CAF0;
signed int 		(__fastcall *CNWSCreatureStats__GetWeaponFinesse)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSItem *weapon) = (signed int (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSItem *weapon))0x00481210;
signed int 		(__fastcall *CNWSCreatureStats__GetWeaponFocus)(CNWSCreatureStats *pTHIS, void* pVOID, CNWSItem *weapon) = (signed int (__fastcall*)(CNWSCreatureStats *pTHIS, void* pVOID, CNWSItem *weapon))0x004812E0;
signed int 		(__fastcall *CNWSCreatureStats__GetEpicWeaponFocus)(CNWSCreatureStats *pTHIS, void* pVOID, CNWSItem *weapon) = (signed int (__fastcall*)(CNWSCreatureStats *pTHIS, void* pVOID, CNWSItem *weapon))0x00481510;
int 			(__fastcall *CNWSCreature__GetTotalEffectBonus)(CNWSCreature *pTHIS, void *pVOID, char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10) = (int (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10))0x004AB140;
int 			(__fastcall *CNWSCreature__GetBlind)(CNWSCreature* pTHIS, void *pVOID) = (int (__fastcall*)(CNWSCreature* pTHIS, void *pVOID))0x004AEB40;
int 			(__fastcall *CNWSCreature__GetInvisible)(CNWSCreature *pTHIS, void *pVOID, CNWSObject* obj, int i) = (int (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, CNWSObject* obj, int i))0x004AEB60;
CNWVisibilityNode * (__fastcall *CNWSCreature__GetVisibleListElement)(CNWSCreature *pTHIS, void *pVOID, unsigned long ul) = (CNWVisibilityNode * (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, unsigned long ul))0x004C7FF0;
bool 			(__fastcall *CNWSCreature__GetFlanked)(CNWSCreature *pTHIS, void *pVOID, CNWSCreature *Target) = (bool (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, CNWSCreature *Target))0x00551250;
float 			(__fastcall *CNWSCreature__MaxAttackRange)(CNWSCreature *pTHIS, void *pVOID, nwn_objid_t, int, int) = (float (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, nwn_objid_t, int, int))0x00498090;
CNWSItem *		(__fastcall *CNWSCombatRound__GetCurrentAttackWeapon)(CNWSCombatRound *pTHIS, void *pVOID, uint32_t) = (CNWSItem* (__fastcall*)(CNWSCombatRound *pTHIS, void *pVOID, uint32_t))0x00532C90;
int 			(__fastcall *CNWSCreatureStats__GetUseMonkAttackTables)(CNWSCreatureStats *pTHIS, void *pVOID, int) = (int (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, int))0x00470730;
int 			(__fastcall *CNWSCreature__GetRangeWeaponEquipped)(CNWSCreature *pTHIS, void *pVOID) = (int (__fastcall*)(CNWSCreature *pTHIS, void *pVOID))0x00496460;
uint8_t 		(__fastcall *CNWRules__GetFeatExpansionLevel)(CNWRules *pTHIS, void *pVOID, uint16_t FeatID) = (uint8_t (__fastcall*)(CNWRules *pTHIS, void *pVOID, uint16_t FeatID))0x004B80F0;
int 			(__fastcall *CNWSPlayer__HasExpansionPack)(CNWSPlayer *pTHIS, void* pVOID, unsigned char, int) = (int (__fastcall*)(CNWSPlayer *pTHIS, void* pVOID, unsigned char, int))0x00436720;
int 			(__fastcall *CNWSItem__ComputeArmorClass)(CNWSItem *pTHIS, void *pVOID) = (int (__fastcall*)(CNWSItem *pTHIS, void *pVOID))0x004FE870;


void 			(__fastcall *CNetLayer__SetConnectionsDisallowed)(CNetLayer *pTHIS, void* pVOID, int bDisAllowConnections) = (void (__fastcall*)(CNetLayer *pTHIS, void* pVOID, int bDisAllowConnections))0x0041F890;
int 			(__fastcall *CNetLayer__SetGameMasterPassword)(CNetLayer *pTHIS, void *pVOID, CExoString dm_pwd) = (int (__fastcall*)(CNetLayer *pTHIS, void *pVOID, CExoString dm_pwd))0x0041F380;

int 			(__fastcall *CNWSMessage__SendServerToPlayerArea_VisualEffect)(CNWSMessage *pTHIS, void *pVOID, CNWSPlayer* plyer, int VFX_number, float Px, float Py, float Pz) = (int (__fastcall*)(CNWSMessage *pTHIS, void *pVOID, CNWSPlayer* plyer, int VFX_number, float Px, float Py, float Pz))0x0043A2B0;

void			(__fastcall *CNWSCreature__ResolveAttack)(CNWSCreature *pTHIS, void *pVOID, int a2_target_oid, signed int a3, int a4) = (void (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, int a2_target_oid, signed int a3, int a4))0x00547580;
void			(__fastcall *CNWSCombatRound__StartCombatRound)(CNWSCombatRound *pTHIS, void *pVOID, nwn_objid_t oidDefender) = (void (__fastcall *)(CNWSCombatRound *pTHIS, void *pVOID, nwn_objid_t oidDefender))0x0052FA00;

char			(__fastcall *CNWSCreatureStats__GetACNaturalBase)(CNWSCreatureStats *pTHIS, void *pVOID, int bTouchAttack) = (char (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, int bTouchAttack))0x00489B00;
int 			(__fastcall *CNWSCreature__GetFlatFooted)(CNWSCreature *pTHIS, void *pVOID) = (int (__fastcall*)(CNWSCreature *pTHIS, void *pVOID))0x00551170;

void 			(__fastcall *CNWLevelStats__AddFeat)(CNWSStats_Level *pTHIS, void *pVOID, uint16_t Feat) = (void (__fastcall *)(CNWSStats_Level *pTHIS, void *pVOID, uint16_t Feat))0x00506570;
char 			(__fastcall *CNWSCreatureStats__AddFeat)(CNWSCreatureStats *pTHIS, void *pVOID, uint16_t Feat) = (char (__fastcall *)(CNWSCreatureStats *pTHIS, void *pVOID, uint16_t Feat))0x0047EBC0;

void			(__fastcall *CNWSArea__CNWSArea)(void*, void*, CResRef, int, unsigned long) = (void (__fastcall*)(void*, void*, CResRef, int, unsigned long))0x0050A2E0;
void			(__fastcall *CNWSArea__Destructor)(CNWSArea *pTHIS, void *pVOID) = (void (__fastcall*)(CNWSArea *pTHIS, void *pVOID))0x0050A780;
int 			(__fastcall *CNWSArea__LoadArea)(void*, void*, int) = (int (__fastcall*)(void*, void*, int))0x0050C380;
void			(__fastcall *CNWSArea__scalar_Destructor)(CNWSArea *pTHIS, void *pVOID, char) = (void (__fastcall*)(CNWSArea *pTHIS, void *pVOID, char))0x0050A760;

int 			(__fastcall *CExoArrayList_uint32___Add)(void *, void *, uint32_t a2) = (int (__fastcall *)(void *, void *, uint32_t a2))0x0048F480;
void 			(__fastcall *CExoArrayList_uint32___Remove)(void *, void *, unsigned long) = (void (__fastcall *)(void *, void *, unsigned long))0x004D0D50;

CGameObjectArray * (__fastcall *CServerExoApp__GetObjectArray)(CServerExoApp*, void*) = (CGameObjectArray* (__fastcall*)(CServerExoApp*, void*))0x0042C800;

int 			(__fastcall *CNWSPlayer__AddArea)(CNWSPlayer* pTHIS, void* pVOID, uint32_t areaid) = (int (__fastcall*)(CNWSPlayer* pTHIS, void* pVOID, uint32_t areaid))0x00436560;
void 			(__fastcall *CNWSCreature__PostProcess)(CNWSCreature *pTHIS, void* pVOID) = (void (__fastcall*)(CNWSCreature *pTHIS, void* pVOID))0x0049E450;
signed int 		(__fastcall *CNWSArea__ExploreArea)(CNWSArea *pTHIS, void* pVOID, CNWSCreature *a2, int a3, int a4, int a5) = (signed int (__fastcall*)(CNWSArea *pTHIS, void* pVOID, CNWSCreature *a2, int a3, int a4, int a5))0x00529C50;
void 			(__fastcall *CNWSCreature__UpdateAutoMap)(CNWSCreature* pTHIS, void *pVOID, uint32_t areaid) = (void (__fastcall*)(CNWSCreature* pTHIS, void *pVOID, uint32_t areaid))0x00494C50;

CExoString const & (__fastcall *CTlkTable__GetCustomTokenValue)(CTlkTable *pThis, void *pVOID, unsigned long) = (CExoString const & (__fastcall*)(CTlkTable *pThis, void *pVOID, unsigned long))0x0043C370;

CNWSArea * 		(__fastcall *CServerExoAppInternal__GetAreaByGameObjectID)(CServerExoAppInternal *, void*, nwn_objid_t Area) = (CNWSArea* (__fastcall*)(CServerExoAppInternal *, void*, nwn_objid_t Area))0x0045C0C0;
long double 	(__fastcall *CNWSArea__ComputeHeight)(CNWSArea *pTHIS, void*, float x, float y, float z) = (long double (__fastcall*)(CNWSArea *pTHIS, void*, float x, float y, float z))0x005276D0;

void * 			(__fastcall *CServerExoApp__GetPlayerList)(CServerExoApp *pTHIS, void *pVOID) = (void* (__fastcall*)(CServerExoApp *pTHIS, void *pVOID))0x0042C920;
int 			(__fastcall *CNWSMessage__SendServerToPlayerDungeonMasterAreaList)(CNWSMessage *pTHIS, void *pVOID, CNWSPlayer *Player) = (int (__fastcall*)(CNWSMessage *pTHIS, void *pVOID, CNWSPlayer *Player))0x00448700;

void 			(__fastcall *CNWSObject__SetTag)(CNWSObject *pTHIS, void *pVOID, CExoString sTag) = (void (__fastcall*)(CNWSObject *pTHIS, void *pVOID, CExoString sTag))0x00466360;
int 			(__fastcall *CNWSModule__AddObjectToLookupTable)(CNWSModule *pTHIS, void *pVOID, CExoString Tag, int a3, int oID) = (int (__fastcall*)(CNWSModule *pTHIS, void *pVOID, CExoString Tag, int a3, int oID))0x004DA3C0;

int 			(__fastcall *CExoResMan__Exists)(CExoResMan *pThis, void *pVOID, CResRef *, unsigned short, unsigned long *) = (int (__fastcall*)(CExoResMan *pThis, void *pVOID, CResRef *, unsigned short, unsigned long *))0x00416BE0;

int 			(__fastcall *CNWSMessage__SendServerToPlayerChat_ServerTell)(CNWSMessage *pTHIS, void *pVOID, uint32_t Receiver_id, CExoString Msg) = (int (__fastcall*)(CNWSMessage *pTHIS, void *pVOID, uint32_t Receiver_id, CExoString Msg))0x0043DEA0;
int 			(__fastcall *CNWSMessage__SendServerToPlayerChat_Shout)(CNWSMessage *pTHIS, void *pVOID, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg) = (int (__fastcall*)(CNWSMessage *pTHIS, void *pVOID, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg))0x0043DF80;
int 			(__fastcall *CNWSMessage__SendServerToPlayerChat_Tell)(CNWSMessage *pTHIS, void* pVOID, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg) = (int (__fastcall*)(CNWSMessage *pTHIS, void* pVOID, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg))0x0043DC90;
int 			(__fastcall *CNWSMessage__SendServerToPlayerChat_Party)(CNWSMessage *pTHIS, void *pVOID, unsigned long, unsigned long, char*, int) = (int (__fastcall*)(CNWSMessage *pTHIS, void *pVOID, unsigned long, unsigned long, char*, int))0x0043D790;
CNWSClient * 	(__fastcall *CServerExoApp__GetClientObjectByPlayerId)(CServerExoApp *pTHIS, void *pVOID, unsigned long player_id, unsigned char) = (CNWSClient* (__fastcall*)(CServerExoApp *pTHIS, void *pVOID, unsigned long player_id, unsigned char))0x0042CD30;
int 			(__fastcall *CNWSMessage__SendServerToPlayerChatMessage)(CNWSMessage *pTHIS, void *pVOID, uint8_t Channel, nwn_objid_t Sender, char* Msg, uint32_t msg_len, uint32_t player_id) = (int (__fastcall*)(CNWSMessage *pTHIS, void *pVOID, uint8_t Channel, nwn_objid_t Sender, char* Msg, uint32_t msg_len, uint32_t player_id))0x0043CA00;

void 			(__fastcall *CNWSCreature__SendFeedbackMessage)(CNWSCreature *pTHIS, void* pVOID, unsigned short, void*, CNWSPlayer *) = (void (__fastcall*)(CNWSCreature *pTHIS, void* pVOID, unsigned short, void*, CNWSPlayer *))0x004AD4D0;
void			(__fastcall *CNWCCMessageData__ctor)(CNWCCMessageData *pTHIS, void *pVOID) = (void (__fastcall*)(CNWCCMessageData *pTHIS, void *pVOID))0x00506630;
uint32_t 		(__fastcall *CNWCCMessageData__SetString)(CNWCCMessageData *pTHIS, void *pVOID, uint32_t, CExoString) = (uint32_t (__fastcall*)(CNWCCMessageData *pTHIS, void *pVOID, uint32_t, CExoString))0x00506880;

CNWTile*		(__fastcall *CNWSArea__GetTile)(CNWSArea* pTHIS, void*pVOID, float x, float y, int z) = (CNWTile* (__fastcall*)(CNWSArea* pTHIS, void*pVOID, float x, float y, int z))0x0050C0E0;
void 			(__fastcall *CNWTile__GetLocation)(CNWTile* pTHIS, void *pVOID, int *, int *) = (void (__fastcall*)(CNWTile* pTHIS, void *pVOID, int *, int *))0x00523150;
int 			(__fastcall *CNWSTile__GetSurfaceMaterial)(CNWSTile *pTHIS, void *pVOID, float, float, float) = (int (__fastcall*)(CNWSTile *pTHIS, void *pVOID, float, float, float))0x005B4CB0;
CNWSArea * 		(__fastcall *CNWSModule__GetArea)(CNWSModule *pTHIS, void *pVOID, nwn_objid_t) = (CNWSArea* (__fastcall*)(CNWSModule *pTHIS, void *pVOID, nwn_objid_t))0x004D2390;
uint32_t		(__fastcall *CServerExoAppInternal__GetPlayerIDByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID) = (uint32_t (__fastcall*)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID))0x00462C80;
int 			(__fastcall *CServerExoApp__GetFactionOfObject)(CServerExoApp* pTHIS, void *pVOID, nwn_objid_t, uint32_t *ret_factionID) = (int (__fastcall*)(CServerExoApp* pTHIS, void *pVOID, nwn_objid_t, uint32_t *ret_factionID))0x0042CD90;
CNWSFaction*	(__fastcall *CFactionManager__GetFaction)(CFactionManager *pTHIS, void *pVOID, uint32_t FactionID) = (CNWSFaction * (__fastcall*)(CFactionManager *pTHIS, void *pVOID, uint32_t FactionID))0x00533EE0;

uint32_t		(__fastcall *CNWSFaction__GetFactionMember)(CNWSFaction *pThis, void *pVoid, int nNth, int bNPCs) = (uint32_t (__fastcall*)(CNWSFaction *pThis, void *pVoid, int nNth, int bNPCs))0x004EA9E0;

uint32_t 		(__fastcall *CItemRepository__FindItemWithTag)(CItemRepository *pTHIS, void *pVOID, CExoString *sTag) = (uint32_t (__fastcall*)(CItemRepository *pTHIS, void *pVOID, CExoString *sTag))0x004FFA40;
uint8_t			(__fastcall *CNWSCreatureStats__GetLevel)(CNWSCreatureStats *pTHIS, void *pVOID, int bCountNegativeLevels) = (uint8_t (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, int bCountNegativeLevels))0x0046DB40;
float 			(__fastcall *CNWSScriptVarTable__GetFloat)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName) = (float (__fastcall*)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName))0x005A10C0;
int 			(__fastcall *CNWSScriptVarTable__GetInt)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName) = (int (__fastcall*)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName))0x005A1090;
int 			(__fastcall *CNWSObject__GetDead)(CNWSObject *pTHIS, void *pVOID) = (int (__fastcall*)(CNWSObject *pTHIS, void *pVOID))0x004E59D0;
void 			(__fastcall *CNWSCreatureStats__AddExperience)(CNWSCreatureStats *pTHIS, void *pVOID, uint32_t XP) = (void (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, uint32_t XP))0x0047D6F0;

CNWSItem * 		(__fastcall *CServerExoAppInternal__GetItemByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID) = (CNWSItem* (__fastcall*)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID))0x0045BFD0;
void 			(__fastcall *CNWSScriptVarTable__SetInt)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName, int VarValue, int) = (void (__fastcall*)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName, int VarValue, int))0x005A1250;
int 			(__fastcall *CExoResMan__FreeChunk)(CExoResMan *pTHIS, void *pVOID) = (int (__fastcall*)(CExoResMan *pTHIS, void *pVOID))0x00416D10;
void *			(__fastcall *CNWSArea__SetScriptName)(CNWSArea *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void* (__fastcall*)(CNWSArea *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x00510C00;
int 			(__fastcall *CExoString__StripNonAlphaNumeric)(CExoString *pTHIS, void *pVOID, int, int, int) = (int (__fastcall*)(CExoString *pTHIS, void *pVOID, int, int, int))0x0040CE30;
int		 		(__fastcall *CExoString__AsTAG)(CExoString *pTHIS, void *pVOID, CExoString*) = (int (__fastcall*)(CExoString *pTHIS, void *pVOID, CExoString*))0x0040CFB0;

void			(__fastcall *CNWSITEM__DESTRUCTOR)(CNWSItem *pTHIS, void *pVOID) = (void (__fastcall*)(CNWSItem *pTHIS, void *pVOID))0x004FACA0;

int 			(__fastcall *CNWSArea__ClearLineOfSight)(CNWSArea *pTHIS, void *pVOID, Vector v1, Vector v2, Vector *v3, uint32_t *, nwn_objid_t, nwn_objid_t, uint8_t) = (int (__fastcall*)(CNWSArea *pTHIS, void *pVOID, Vector v1, Vector v2, Vector *v3, uint32_t *, nwn_objid_t, nwn_objid_t, uint8_t))0x005114E0;
CGenericObject *(__fastcall *CServerExoAppInternal__GetGameObject)(CServerExoAppInternal* pTHIS, void *pVOID, nwn_objid_t oID) = (CGenericObject* (__fastcall*)(CServerExoAppInternal* pTHIS, void *pVOID, nwn_objid_t oID))0x0045BF40;
signed int 		(__fastcall *CNWSArea__GetFirstObjectInArea)(CNWSArea *pTHIS, void *pVOID, nwn_objid_t *oID) = (signed int (__fastcall*)(CNWSArea *pTHIS, void *pVOID, nwn_objid_t *oID))0x0050C070;
signed int 		(__fastcall *CNWSArea__GetNextObjectInArea)(CNWSArea *pTHIS, void *pVOID, nwn_objid_t *oID) = (signed int (__fastcall*)(CNWSArea *pTHIS, void *pVOID, nwn_objid_t *oID))0x0050C0A0;

uint8_t 		(__fastcall *CGameObjectArray__delete)(CGameObjectArray *pTHIS, void *pVOID, nwn_objid_t oID) = (uint8_t (__fastcall*)(CGameObjectArray *pTHIS, void *pVOID, nwn_objid_t oID))0x004668C0;

CNWSPlayerTURD* (__fastcall *CNWSModule__GetPlayerTURDFromList)(CNWSModule *pTHIS, void *pVOID, CNWSPlayer *) = (CNWSPlayerTURD* (__fastcall*)(CNWSModule *pTHIS, void *pVOID, CNWSPlayer *))0x004D7330;
CNWSStats_Level*(__fastcall *CNWLevelStats__CNWLevelStats)(CNWSStats_Level *pTHIS, void *pVOID) = (CNWSStats_Level* (__fastcall*)(CNWSStats_Level *pTHIS, void *pVOID))0x00506330;
bool 			(__fastcall *CNWSCreatureStats__LevelUp)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSStats_Level *a2, int a3, char a4, char a5, int a6) = (bool (__fastcall*)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSStats_Level *a2, int a3, char a4, char a5, int a6))0x004847F0;
CGenericObject* (__fastcall *CNWSPlayer__GetGameObject)(CNWSPlayer *pTHIS, void *pVOID) = (CGenericObject* (__fastcall*)(CNWSPlayer *pTHIS, void *pVOID))0x004364E0;
CScriptLocation (__fastcall *CNWSScriptVarTable__GetLocation)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName) = (CScriptLocation (__fastcall*)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName))0x005A11B0;
C2DA*			(__fastcall *C2DA__C2DA)(C2DA *pTHIS, void *pVOID, CResRef, int) = (C2DA* (__fastcall*)(C2DA *pTHIS, void *pVOID, CResRef, int))0x0041DF10;
CResRef*		(__fastcall *CResRef__CResRef)(CResRef *pTHIS, void *pVOID, CExoString const &) = (CResRef* (__fastcall*)(CResRef *pTHIS, void *pVOID, CExoString const &))0x00415AD0;
int 			(__fastcall *C2DA__Load2DArray)(C2DA *pTHIS, void *pVOID) = (int (__fastcall*)(C2DA *pTHIS, void *pVOID))0x0041E720;
int 			(__fastcall *C2DA__GetINTEntry_strcol)(C2DA *pTHIS, void *pVOID, int nRow, CExoString const &ColName, int *Ret) = (int (__fastcall*)(C2DA *pTHIS, void *pVOID, int nRow, CExoString const &ColName, int *Ret))0x0041E540;
int 			(__fastcall *C2DA__GetINTEntry_intcol)(C2DA *pTHIS, void *pVOID, int nRow, int nCol, int *Ret) = (int (__fastcall*)(C2DA *pTHIS, void *pVOID, int nRow, int nCol, int *Ret))0x0041E430;
int 			(__fastcall *C2DA__GetCExoStringEntry)(C2DA *pTHIS, void *pVOID, int nRow, CExoString const &ColName, CExoString *Ret) = (int (__fastcall*)(C2DA *pTHIS, void *pVOID, int nRow, CExoString const &ColName, CExoString *Ret))0x0041E250;
void * 			(__fastcall *C2DA__vect_destructor)(C2DA *pTHIS, void *pVOID, unsigned int) = (void* (__fastcall*)(C2DA *pTHIS, void *pVOID, unsigned int))0x0041E0B0;
signed int		(__fastcall *CNWSArea__AddObjectToArea)(CNWSArea *pTHIS, void *pVOID, unsigned int Object_ID, int bRunEnterScript) = (signed int (__fastcall*)(CNWSArea *pTHIS, void *pVOID, unsigned int Object_ID, int bRunEnterScript))0x0050BAA0;
signed int 		(__fastcall *CNWSArea__RemoveObjectFromArea)(CNWSArea *pTHIS, void *pVOID, unsigned int oID) = (signed int (__fastcall*)(CNWSArea *pTHIS, void *pVOID, unsigned int oID))0x0050BEE0;
unsigned int 	(__fastcall *CNWSObject__SetArea)(CNWSObject *pTHIS, void *pVOID, CNWSArea *Area) = (unsigned int (__fastcall*)(CNWSObject *pTHIS, void *pVOID, CNWSArea *Area))0x004E3F90;
signed int 		(__fastcall *CNWSCreature__RemoveItem)(CNWSCreature *pTHIS, void *pVOID, CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6) = (signed int (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6))0x004C0830;
signed int 		(__fastcall *CNWSPlaceable__AcquireItem)(CNWSPlaceable *pTHIS, void *pVOID, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack) = (signed int (__fastcall*)(CNWSPlaceable *pTHIS, void *pVOID, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack))0x00521AD0;
signed int 		(__fastcall *CNWSCreature__AcquireItem)(CNWSCreature *pTHIS, void *pVOID, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack) = (signed int (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack))0x004C0580;
CNWSPlaceable*  (__fastcall *CServerExoAppInternal__GetPlaceableByGameObjectID)(CServerExoAppInternal *, void*, nwn_objid_t Placeable) = (CNWSPlaceable* (__fastcall*)(CServerExoAppInternal *, void*, nwn_objid_t Placeable))0x0045C160;
void 			(__fastcall *CNWSPlaceable__SetScriptName)(CNWSPlaceable *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void (__fastcall*)(CNWSPlaceable *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x004CD150;
void 			(__fastcall *CNWSAreaOfEffectObject__SetScriptName)(CNWSAreaOfEffectObject *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void (__fastcall*)(CNWSAreaOfEffectObject *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x004F2F20;
CNWSAreaOfEffectObject*	(__fastcall *CServerExoAppInternal__GetAreaOfEffectByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID) = (CNWSAreaOfEffectObject* (__fastcall*)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID))0x0045C200;
int 			(__fastcall *CNWSItem__SetPossessor)(CNWSItem *pTHIS, unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i) = (int (__fastcall*)(CNWSItem *pTHIS, unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i))0x004FAF10;
void *			(__fastcall *CNWSCreature__SetScriptName)(CNWSCreature *pTHIS, void *pVOID, signed int iScript, CExoString ScriptName) = (void* (__fastcall*)(CNWSCreature *pTHIS, void *pVOID, signed int iScript, CExoString ScriptName))0x0049F8D0;
CNWSDoor * 		(__fastcall *CServerExoAppInternal__GetDoorByGameObjectID)(CServerExoAppInternal *pTHIS, void *pVOID, nwn_objid_t oID) = (CNWSDoor* (__fastcall*)(CServerExoAppInternal *pTHIS, void *pVOID, nwn_objid_t oID))0x0045C1B0;
void 			(__fastcall *CNWSDoor__SetScriptName)(CNWSDoor *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void (__fastcall*)(CNWSDoor *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x004CC670;
CNWSEncounter * (__fastcall *CServerExoAppInternal__GetEncounterByGameObjectID)(CServerExoAppInternal *pTHIS, void *pVOID, nwn_objid_t oID) = (CNWSEncounter* (__fastcall*)(CServerExoAppInternal *pTHIS, void *pVOID, nwn_objid_t oID))0x0045C2A0;
void 			(__fastcall *CNWSEncounter__SetScriptName)(CNWSEncounter *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void (__fastcall*)(CNWSEncounter *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x005ADA00;
void 			(__fastcall *CNWSModule__SetScriptName)(CNWSModule *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void (__fastcall*)(CNWSModule *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x004D97F0;
void 			(__fastcall *CNWSStore__SetScriptName)(CNWSStore *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void (__fastcall*)(CNWSStore *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x00466460;
CNWSStore * 	(__fastcall *CServerExoAppInternal__GetStoreByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID) = (CNWSStore* (__fastcall*)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID))0x0045BF80;
void 			(__fastcall *CNWSTrigger__SetScriptName)(CNWSTrigger *pTHIS, void *pVOID, int iScript, CExoString ScriptName) = (void (__fastcall*)(CNWSTrigger *pTHIS, void *pVOID, int iScript, CExoString ScriptName))0x004CB790;
CNWSTrigger* 	(__fastcall *CServerExoAppInternal__GetTriggerByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID) = (CNWSTrigger* (__fastcall*)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID))0x0045C110;

void (__fastcall *CNWSAreaOfEffectObject__dtor_CNWSAreaOfEffectObject)	(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005A3880;
void (__fastcall *CNWSCreature__dtor_CNWSCreature)						(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x0048FFE0;
void (__fastcall *CNWSDoor__dtor_CNWSDoor)								(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005237F0;
void (__fastcall *CNWSEncounter__dtor_CNWSEncounter)					(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005A9D80;
void (__fastcall *CNWSItem__dtor_CNWSItem)								(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x00502150;
void (__fastcall *CNWSPlaceable__dtor_CNWSPlaceable)					(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x0051E1C0;
void (__fastcall *CNWSSoundObject_dtor_CNWSSoundObject)					(void *pTHIS, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005B5BA0;
void (__fastcall *CNWSStore__dtor_CNWSStore)							(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x004645E0;
void (__fastcall *CNWSTrigger__dtor_CNWSTrigger)						(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005A63D0;
void (__fastcall *CNWSWaypoint__dtor_CNWSWaypoint)						(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005B51B0;

void (__fastcall *CNWSPlayer__vec_dtor)									(CNWSPlayer *pTHIS, void* pVOID, char) = (void (__fastcall*)(CNWSPlayer *pTHIS, void* pVOID, char))0x0042EEA0;

/*
void SendFeedbackmessage(nwn_objid_t oID, char *Msg) {
	CNWSCreature *cre = CServerExoAppInternal__GetCreatureByGameObjectID((*NWN_AppManager)->app_server->srv_internal, NULL, oID);
	CNWCCMessageData *Data = (CNWCCMessageData*)malloc(52);
	CNWCCMessageData__ctor(Data, NULL);
	CExoString cstr(Msg);
	CNWCCMessageData__SetString(Data, NULL, 0, cstr);
	CNWSCreature__SendFeedbackMessage(cre, NULL, 0xCC, Data, 0);
}*/