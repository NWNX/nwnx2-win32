#ifndef ___NX_NWN_FUNC_INTERNALS__
#define ___NX_NWN_FUNC_INTERNALS__

extern CAppManager **NWN_AppManager;
extern CVirtualMachine **NWN_VirtualMachine;
extern CTlkTable **NWN_CTlkTable;
extern CNWTlkTable **NWN_CNWTlkTable;
extern CNWRules **NWN_Rules;
extern CExoResMan **NWN_ResMan;

//void SendFeedbackmessage(nwn_objid_t oID, char *Msg);

extern C2DA*				(__fastcall *C2DA__C2DA)(C2DA *pTHIS, void *pVOID, CResRef, int);
extern int 					(__fastcall *C2DA__Load2DArray)(C2DA *pTHIS, void *pVOID);
extern int 					(__fastcall *C2DA__GetCExoStringEntry)(C2DA *pTHIS, void *pVOID, int nRow, CExoString const &ColName, CExoString *Ret);
extern int 					(__fastcall *C2DA__GetINTEntry_strcol)(C2DA *pTHIS, void *pVOID, int nRow, CExoString const &ColName, int *Ret);
extern int 					(__fastcall *C2DA__GetINTEntry_intcol)(C2DA *pTHIS, void *pVOID, int nRow, int nCol, int *Ret);
extern void * 				(__fastcall *C2DA__vect_destructor)(C2DA *pTHIS, void *pVOID, unsigned int);
	
extern int 					(__fastcall *CExoArrayList_uint32___Add)(void *, void *, uint32_t a2);
extern void 				(__fastcall *CExoArrayList_uint32___Remove)(void *, void *, unsigned long);

extern int 					(__fastcall *CExoResMan__Exists)(CExoResMan *pThis, void *pVOID, CResRef *, unsigned short, unsigned long *);
extern int 					(__fastcall *CExoResMan__FreeChunk)(CExoResMan *pTHIS, void *pVOID);

extern int					(__fastcall *CExoString__AsTAG)(CExoString *pTHIS, void *pVOID, CExoString*);
extern int 					(__fastcall *CExoString__StripNonAlphaNumeric)(CExoString *pTHIS, void *pVOID, int, int, int);

extern CNWSFaction*			(__fastcall *CFactionManager__GetFaction)(CFactionManager *pTHIS, void *pVOID, uint32_t FactionID);

extern int					(__fastcall *CGameEffect__GetScriptEffectType)(CGameEffect*, void*);

extern uint32_t 			(__fastcall *CItemRepository__FindItemWithTag)(CItemRepository *pTHIS, void *pVOID, CExoString *sTag);

extern CNWBaseItem *		(__fastcall *CNWBaseItemArray__GetBaseItem)(CNWBaseItemArray *pTHIS, void *pVOID, int baseItem);

extern void					(__fastcall *CNWCCMessageData__ctor)(CNWCCMessageData *pTHIS, void *pVOID);
extern uint32_t 			(__fastcall *CNWCCMessageData__SetString)(CNWCCMessageData *pTHIS, void *pVOID, uint32_t, CExoString);

extern void					(__fastcall *CNWMessage__CreateWriteMessage)(CNWSMessage*, void*, uint32_t, nwn_objid_t, uint32_t);
extern int					(__fastcall *CNWMessage__GetWriteMessage)(CNWSMessage*, void*, uint8_t**, uint64_t*);
	
extern uint8_t 				(__fastcall *CNWRules__GetFeatExpansionLevel)(CNWRules *pTHIS, void *pVOID, uint16_t FeatID);

extern signed int 			(__fastcall *CNWSArea__AddObjectToArea)(CNWSArea *pTHIS, void *pVOID, unsigned int Object_ID, int bRunEnterScript);
extern int 					(__fastcall *CNWSArea__ClearLineOfSight)(CNWSArea *pTHIS, void *pVOID, Vector v1, Vector v2, Vector *v3, uint32_t *, nwn_objid_t, nwn_objid_t, uint8_t);
extern void					(__fastcall *CNWSArea__CNWSArea)(void*, void*, CResRef, int, unsigned long);
extern long double 			(__fastcall *CNWSArea__ComputeHeight)(CNWSArea *pTHIS, void*, float x, float y, float z);
extern void					(__fastcall *CNWSArea__Destructor)(CNWSArea *pTHIS, void *pVOID);
extern signed int 			(__fastcall *CNWSArea__ExploreArea)(CNWSArea *pTHIS, void* pVOID, CNWSCreature *a2, int a3, int a4, int a5);
extern signed int 			(__fastcall *CNWSArea__GetFirstObjectInArea)(CNWSArea *pTHIS, void *pVOID, nwn_objid_t *oID);
extern signed int 			(__fastcall *CNWSArea__GetNextObjectInArea)(CNWSArea *pTHIS, void *pVOID, nwn_objid_t *oID);
extern CNWTile*				(__fastcall *CNWSArea__GetTile)(CNWSArea* pTHIS, void *pVOID, float x, float y, int z);
extern int 					(__fastcall *CNWSArea__LoadArea)(void*, void*, int);
extern signed int 			(__fastcall *CNWSArea__RemoveObjectFromArea)(CNWSArea *pTHIS, void *pVOID, unsigned int oID);
extern void *				(__fastcall *CNWSArea__SetScriptName)(CNWSArea *pTHIS, void *pVOID, int iScript, CExoString ScriptName);
extern void					(__fastcall *CNWSArea__scalar_Destructor)(CNWSArea *pTHIS, void *pVOID, char);

extern void 				(__fastcall *CNWSAreaOfEffectObject__SetScriptName)(CNWSAreaOfEffectObject *pTHIS, void *pVOID, int iScript, CExoString ScriptName);

extern void					(__fastcall *CNWSCombatRound__ClearAllAttacks)(CNWSCombatRound *pTHIS, void *pVOID);
extern CNWSItem *			(__fastcall *CNWSCombatRound__GetCurrentAttackWeapon)(CNWSCombatRound *pTHIS, void *pVOID, uint32_t);
extern void					(__fastcall *CNWSCombatRound__StartCombatRound)(CNWSCombatRound *pTHIS, void *pVOID, nwn_objid_t oidDefender);

extern signed int 			(__fastcall *CNWSCreature__AcquireItem)(CNWSCreature *pTHIS, void *pVOID, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack);
extern int 					(__fastcall *CNWSCreature__GetBlind)(CNWSCreature *pTHIS, void *pVOID);
extern bool 				(__fastcall *CNWSCreature__GetFlanked)(CNWSCreature *pTHIS, void *pVOID, CNWSCreature *Target);
extern int 					(__fastcall *CNWSCreature__GetFlatFooted)(CNWSCreature *pTHIS, void *pVOID);
extern int 					(__fastcall *CNWSCreature__GetInvisible)(CNWSCreature *pTHIS, void *pVOID, CNWSObject* obj, int i);
extern int 					(__fastcall *CNWSCreature__GetRangeWeaponEquipped)(CNWSCreature *pTHIS, void *pVOID);
extern int 					(__fastcall *CNWSCreature__GetRelativeWeaponSize)(CNWSCreature *pTHIS, void *pVOID, CNWSItem *weapon);
extern int 					(__fastcall *CNWSCreature__GetTotalEffectBonus)(CNWSCreature *pTHIS, void *pVOID, char a2, CNWSObject *obj_a, int a4, int a5, unsigned __int8 a6, unsigned __int8 a7, unsigned __int8 a8, unsigned __int8 a9, int a10);
extern CNWVisibilityNode *	(__fastcall *CNWSCreature__GetVisibleListElement)(CNWSCreature *pTHIS, void *pVOID, unsigned long ul);
extern float 				(__fastcall *CNWSCreature__MaxAttackRange)(CNWSCreature *pTHIS, void *pVOID, nwn_objid_t, int, int);
extern void 				(__fastcall *CNWSCreature__PostProcess)(CNWSCreature *pTHIS, void* pVOID);
extern void					(__fastcall *CNWSCreature__RemoveFromArea)(CNWSCreature*, void*, int);
extern signed int 			(__fastcall *CNWSCreature__RemoveItem)(CNWSCreature *pTHIS, void *pVOID, CNWSItem *a2, int a3, int bSendFeedBack, int a5, int a6);
extern void					(__fastcall *CNWSCreature__ResolveAttack)(CNWSCreature *pTHIS, void *pVOID, int a2_target_oid, signed int a3, int a4);
extern int					(__fastcall *CNWSCreature__ResolveRangedAttack)(CNWSCreature *Attacker_this, void* pVOID, CNWSObject *Defender_a2, int nAttacks_a3, int a4);
extern void 				(__fastcall *CNWSCreature__SendFeedbackMessage)(CNWSCreature *pTHIS, void* pVOID, unsigned short, void*, CNWSPlayer *);
extern void					(__fastcall *CNWSCreature__StartGuiTimingBar)(CNWSCreature*, void*, unsigned long, unsigned char);
extern void					(__fastcall *CNWSCreature__StopGuiTimingBar)(CNWSCreature*, void*);
extern void 				(__fastcall *CNWSCreature__UpdateAutoMap)(CNWSCreature* pTHIS, void *pVOID, uint32_t areaid);

extern void 				(__fastcall *CNWSCreatureStats__AddExperience)(CNWSCreatureStats *pTHIS, void *pVOID, uint32_t XP);
extern char 				(__fastcall *CNWSCreatureStats__AddFeat)(CNWSCreatureStats *pTHIS, void *pVOID, uint16_t Feat);
extern char					(__fastcall *CNWSCreatureStats__GetACNaturalBase)(CNWSCreatureStats *pTHIS, void *pVOID, int bTouchAttack);
extern int 					(__fastcall *CNWSCreatureStats__GetAttackModifierVersus)(CNWSCreatureStats *, void*, CNWSCreature *);
extern unsigned char 		(__fastcall *CNWSCreatureStats__GetAttacksPerRound)(CNWSCreatureStats *, void *);
extern int 					(__fastcall *CNWSCreatureStats__GetBaseAttackBonus)(CNWSCreatureStats *Stats, void* pVOID, int bPreEpicOnly);
extern char 				(__fastcall *CNWSCreatureStats__GetDEXMod)(CNWSCreatureStats *pTHIS, void *pVOID, int bMaxArmorDex);
extern signed int 			(__fastcall *CNWSCreatureStats__GetEpicWeaponFocus)(CNWSCreatureStats *pTHIS, void* pVOID, CNWSItem *weapon);
extern int 					(__fastcall *CNWSCreatureStats__GetFavoredEnemyBonus)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSCreature *cre_enemy);
extern int 					(__fastcall *CNWSCreatureStats__GetIsWeaponOfChoice)(CNWSCreatureStats *pTHIS, void *pVOID, uint32_t BaseItemType);
extern uint8_t				(__fastcall *CNWSCreatureStats__GetLevel)(CNWSCreatureStats *pTHIS, void *pVOID, int bCountNegativeLevels);
extern int					(__fastcall *CNWSCreatureStats__GetMeleeAttackBonus)(CNWSCreatureStats *, void *, int, int, int);
extern int 					(__fastcall *CNWSCreatureStats__GetUseMonkAttackTables)(CNWSCreatureStats *pTHIS, void *pVOID, int);
extern signed int 			(__fastcall *CNWSCreatureStats__GetWeaponFinesse)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSItem *weapon);
extern signed int 			(__fastcall *CNWSCreatureStats__GetWeaponFocus)(CNWSCreatureStats *pTHIS, void* pVOID, CNWSItem *weapon);
extern int 					(__fastcall *CNWSCreatureStats__HasFeat)(CNWSCreatureStats *Stats, void *pVOID, uint16_t feat);
extern bool 				(__fastcall *CNWSCreatureStats__LevelUp)(CNWSCreatureStats *pTHIS, void *pVOID, CNWSStats_Level *a2, int a3, char a4, char a5, int a6);
extern int 					(__fastcall *CNWSCreatureStats__ResolveSpecialAttackAttackBonus)(CNWSCreatureStats *pAttackerStats, void* pVOID, CNWSCreature *Defender);

extern uint32_t				(__fastcall *CNWSFaction__GetFactionMember)(CNWSFaction *pThis, void *pVoid, int nNth, int bNPCs);
	
extern CNWSItem *			(__fastcall *CNWSInventory__GetItemInSlot)(CNWSInventory* inventory, void* pVOID, unsigned long nSlot);

extern void					(__fastcall *CNWSITEM__DESTRUCTOR)(CNWSItem *pTHIS, void *pVOID);
extern int 					(__fastcall *CNWSItem__ComputeArmorClass)(CNWSItem *pTHIS, void *pVOID);
extern int 					(__fastcall *CNWSItem__SetPossessor)(CNWSItem *pTHIS, unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i);

extern void 				(__fastcall *CNWLevelStats__AddFeat)(CNWSStats_Level *pTHIS, void *pVOID, uint16_t Feat);
extern CNWSStats_Level*		(__fastcall *CNWLevelStats__CNWLevelStats)(CNWSStats_Level *pTHIS, void *pVOID);

extern int 					(__fastcall *CNWSMessage__SendServerToPlayerArea_VisualEffect)(CNWSMessage *pTHIS, void *pVOID, CNWSPlayer* plyer, int VFX_number, float Px, float Py, float Pz);
extern int 					(__fastcall *CNWSMessage__SendServerToPlayerChat_Party)(CNWSMessage *pTHIS, void *pVOID, unsigned long, unsigned long, char*, int);
extern int 					(__fastcall *CNWSMessage__SendServerToPlayerChat_ServerTell)(CNWSMessage *pTHIS, void *pVOID, uint32_t Receiver_id, CExoString Msg);
extern int 					(__fastcall *CNWSMessage__SendServerToPlayerChat_Shout)(CNWSMessage *pTHIS, void *pVOID, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
extern int 					(__fastcall *CNWSMessage__SendServerToPlayerChat_Tell)(CNWSMessage *pTHIS, void* pVOID, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
extern int 					(__fastcall *CNWSMessage__SendServerToPlayerChatMessage)(CNWSMessage *pTHIS, void *pVOID, uint8_t Channel, nwn_objid_t Sender, char* Msg, uint32_t msg_len, uint32_t player_id); 
extern int 					(__fastcall *CNWSMessage__SendServerToPlayerDungeonMasterAreaList)(CNWSMessage *pTHIS, void *pVOID, CNWSPlayer *Player);
extern int					(__fastcall *CNWSMessage__SendServerToPlayerGameObjUpdate)(CNWSMessage*, void*, CNWSPlayer *);
extern int 					(__fastcall *CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton)(CNWSMessage*, void *, CNWSPlayer*, uint8_t, int32_t);
extern int					(__fastcall *CNWSMessage__SendServerToPlayerMessage)(CNWSMessage*, void*, nwn_objid_t, uint8_t, uint8_t, uint8_t *, uint32_t);
extern void					(__fastcall *CNWSMessage__WriteGameObjUpdate_UpdateAppearance)(CNWSMessage*, void* , CNWSObject*, CLastUpdateObject*, uint32_t);
extern void					(__fastcall *CNWSMessage__WriteGameObjUpdate_UpdateObject)(CNWSMessage*, void*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t);

extern void					(__fastcall *CNWSModule__AddObjectToLimbo)(CNWSModule*, void*, uint32_t);
extern int 					(__fastcall *CNWSModule__AddObjectToLookupTable)(CNWSModule *pTHIS, void *pVOID, CExoString Tag, int a3, int oID);
extern CNWSArea * 			(__fastcall *CNWSModule__GetArea)(CNWSModule *pTHIS, void *pVOID, nwn_objid_t);
extern CNWSPlayerTURD* 		(__fastcall *CNWSModule__GetPlayerTURDFromList)(CNWSModule *pTHIS, void *pVOID, CNWSPlayer *);

extern CNWSArea * 			(__fastcall *CNWSObject__GetArea)(CNWSObject *pTHIS, void*);
extern char					(__fastcall *CNWSObject__GetDamageImmunityByFlags)(CNWSObject*, void*, uint16_t);
extern int 					(__fastcall *CNWSObject__GetDead)(CNWSObject *pTHIS, void *pVOID);
extern int					(__fastcall *CNWSObject__RemoveEffectById)(CNWSObject*, void*, unsigned __int64);
extern unsigned int 		(__fastcall *CNWSObject__SetArea)(CNWSObject *pTHIS, void *pVOID, CNWSArea *Area);
extern void 				(__fastcall *CNWSObject__SetTag)(CNWSObject *pTHIS, void *pVOID, CExoString sTag);

extern signed int 			(__fastcall *CNWSPlaceable__AcquireItem)(CNWSPlaceable *pTHIS, void *pVOID, CNWSItem **a2, unsigned int a3, int a4, int a5, int bSendFeedBack);
extern void 				(__fastcall *CNWSPlaceable__SetScriptName)(CNWSPlaceable *pTHIS, void *pVOID, int iScript, CExoString ScriptName);

extern int 					(__fastcall *CNWSPlayer__AddArea)(CNWSPlayer* pTHIS, void* pVOID, uint32_t areaid);
extern CGenericObject* 		(__fastcall *CNWSPlayer__GetGameObject)(CNWSPlayer *pTHIS, void *pVOID);
extern int 					(__fastcall *CNWSPlayer__HasExpansionPack)(CNWSPlayer *pTHIS, void* pVOID, unsigned char, int);
extern void					(__fastcall *CNWSPlayer__vec_dtor)(CNWSPlayer *pTHIS, void* pVOID, char);

extern float 				(__fastcall *CNWSScriptVarTable__GetFloat)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName);
extern int 					(__fastcall *CNWSScriptVarTable__GetInt)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName);
extern void 				(__fastcall *CNWSScriptVarTable__SetInt)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName, int VarValue, int);
extern CScriptLocation 		(__fastcall *CNWSScriptVarTable__GetLocation)(CNWSScriptVarTable *pTHIS, void *pVOID, CExoString &VarName);
	
extern int 					(__fastcall *CNWSTile__GetSurfaceMaterial)(CNWSTile *pTHIS, void *pVOID, float, float, float);
extern void 				(__fastcall *CNWTile__GetLocation)(CNWTile* pTHIS, void *pVOID, int *, int *);

extern void 				(__fastcall *CNetLayer__SetConnectionsDisallowed)(CNetLayer *pTHIS, void* pVOID, int bDisAllowConnections);
extern int 					(__fastcall *CNetLayer__SetGameMasterPassword)(CNetLayer *pTHIS, void *pVOID, CExoString dm_pwd);

extern CResRef*				(__fastcall *CResRef__CResRef)(CResRef *pTHIS, void *pVOID, CExoString const &);

extern CNWSPlayer* 			(__fastcall *CServerExoApp__GetClientObjectByObjectId)(CServerExoApp*, void*, uint32_t);
extern CNWSClient * 		(__fastcall *CServerExoApp__GetClientObjectByPlayerId)(CServerExoApp *pTHIS, void *pVOID, unsigned long player_id, unsigned char);
extern CGenericObject*		(__fastcall *CServerExoApp__GetGameObject)(CServerExoApp*, void*, uint32_t/*oID*/);
extern int 					(__fastcall *CServerExoApp__GetFactionOfObject)(CServerExoApp* pTHIS, void *pVOID, nwn_objid_t, uint32_t *ret_factionID);
extern void*				(__fastcall *CServerExoApp__GetNWSMessage)(CServerExoApp*, void *);
extern CGameObjectArray*	(__fastcall *CServerExoApp__GetObjectArray)(CServerExoApp*, void*);
extern void* 				(__fastcall *CServerExoApp__GetPlayerList)(CServerExoApp *pTHIS, void *pVOID);


extern CNWSArea * 				(__fastcall *CServerExoAppInternal__GetAreaByGameObjectID)(CServerExoAppInternal *, void*, nwn_objid_t Area);
extern CNWSCreature*			(__fastcall *CServerExoAppInternal__GetCreatureByGameObjectID)(CServerExoAppInternal*, void*, unsigned long);
extern int 						(__fastcall *CServerExoAppInternal__GetFactionOfObject)(CServerExoAppInternal* pTHIS, void *pVOID, nwn_objid_t, uint32_t *ret_factionID);
extern CGenericObject * 		(__fastcall *CServerExoAppInternal__GetGameObject)(CServerExoAppInternal* pTHIS, void *pVOID, nwn_objid_t oID);
extern CNWSItem * 				(__fastcall *CServerExoAppInternal__GetItemByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID);
extern CNWSModule*				(__fastcall *CServerExoAppInternal__GetModule)(CServerExoAppInternal *, void*);
extern CNWSPlaceable * 			(__fastcall *CServerExoAppInternal__GetPlaceableByGameObjectID)(CServerExoAppInternal *, void*, nwn_objid_t Placeable);
extern uint32_t					(__fastcall *CServerExoAppInternal__GetPlayerIDByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID);
extern CNWSAreaOfEffectObject*	(__fastcall *CServerExoAppInternal__GetAreaOfEffectByGameObjectID)(CServerExoAppInternal* pThis, void *pVoid, nwn_objid_t oID);
		
extern void					(__fastcall *CWorldTimer__GetWorldTime)(CWorldTimer*, void*, uint32_t *, uint32_t *);
extern void					(__fastcall *CWorldTimer__SetWorldTime)(CWorldTimer*, void*, uint32_t, uint32_t, int);
extern unsigned long 		(__fastcall *CWorldTimer__SubtractWorldTimes)(CWorldTimer *pTHIS, void *pVOID, unsigned long, unsigned long, unsigned long, unsigned long, unsigned long *, unsigned long *);

extern CExoString const &	(__fastcall *CTlkTable__GetCustomTokenValue)(CTlkTable *pThis, void *pVOID, unsigned long);

extern uint8_t		 		(__fastcall *CGameObjectArray__delete)(CGameObjectArray *pTHIS, void *pVOID, nwn_objid_t oID);

// scalar and vector(if existing) deleting destructors
extern void (__fastcall *CNWSCreature__dtor_CNWSCreature)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSItem__dtor_CNWSItem)								(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSTrigger__dtor_CNWSTrigger)							(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSPlaceable__dtor_CNWSPlaceable)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSDoor__dtor_CNWSDoor)								(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSAreaOfEffectObject__dtor_CNWSAreaOfEffectObject)	(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSWaypoint__dtor_CNWSWaypoint)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSEncounter__dtor_CNWSEncounter)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSStore__dtor_CNWSStore)								(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSSoundObject_dtor_CNWSSoundObject)					(void *pTHIS, void *pVOID, char);


#endif