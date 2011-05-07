#ifndef _NX_NWN_STRUCT_CNWSMODULE_
#define _NX_NWN_STRUCT_CNWSMODULE_

struct CNWSModule_s {
    uint32_t                    obj_type;
    nwn_objid_t					obj_id			/* 0x004 */;
    uint32_t                    field_08;
    uint32_t                    field_0C;
    uint32_t                    field_10;
    uint32_t                    field_14;
    nwn_objid_t                 *mod_areas;
    uint32_t                    mod_areas_len;
    uint32_t                    field_20;
    uint32_t                    field_24;
    uint32_t                    field_28;
    uint32_t                    field_2C;
    uint32_t                    field_30;
    uint32_t                    field_34;
    uint32_t                    field_38;
    uint32_t                    field_3C;
    uint32_t                    field_40;
    uint32_t                    field_44;
    CExoLinkedList              mod_PlayerTURDList;
    uint32_t                    field_4C;
    uint32_t                    field_50;
    uint32_t                    field_54;
    uint32_t                    field_58;
    uint32_t                    field_5C;
    uint32_t                    field_60;
    uint32_t                    field_64;
    uint32_t                    field_68;
    uint32_t                    field_6C;
    uint32_t                    field_70;
    uint32_t                    field_74;
    uint32_t                    field_78;
    uint32_t                    field_7C;
    uint32_t                    field_80;
    uint32_t                    field_84;
    CNWSScriptVarTable          mod_vartable;	/* 0x0088 */
    
    uint32_t                    field_90;
    uint32_t                    field_94;

	CExoString					Mod_OnHeartbeat;
	CExoString					Mod_OnUsrDefined;
	CExoString					Mod_OnModLoad;
	CExoString					Mod_OnModStart;
	CExoString					Mod_OnClientEntr;
	CExoString					Mod_OnClientLeav;
	CExoString					Mod_OnActvtItem;
	CExoString					Mod_OnAcquirItem;
	CExoString					Mod_OnUnAqreItem;
	CExoString					Mod_OnPlrDeath;
	CExoString					Mod_OnPlrDying;
	CExoString					Mod_OnSpawnBtnDn;
	CExoString					Mod_OnPlrRest;
	CExoString					Mod_OnPlrLvlUp;
	CExoString					Mod_OnCutsnAbort;
	CExoString					Mod_OnPlrEqItm;
	CExoString					Mod_OnPlrUnEqItm;
	CExoString					Mod_OnPlrChat;    

    uint32_t					spacer1[2];					/* 0x0090 */
    
    void						*mod_objlist;					/* 0x0130 */
    uint32_t					mod_objlist_len;				/* 0x0134 */
    uint32_t					mod_objlist_alloc;				/* 0x0138 */
    
    uint32_t					spacer2_01;						/* 0x013C */
    uint32_t					spacer2_02;						/* 0x0140 */
    uint32_t					spacer2_03;						/* 0x0144 */
    uint32_t					spacer2_04;						/* 0x0148 */
    CLookupTableObject			*lookuptable;					/* 0x014C */
    uint32_t					lookuptable_len;				/* 0x0150 */
    uint32_t					lookuptable_alloc;				/* 0x0154 */
    uint32_t					spacer2[26];					/* 0x0158 */
    
    uint32_t					mod_date_year;					/* 0x01C0 */
    uint32_t					mod_date_month;					/* 0x01C4 */
    uint32_t					mod_date_day;					/* 0x01C8 */
    uint32_t					mod_time_hour;					/* 0x01CC */
    
    uint32_t					field_1D0;
    uint8_t						mod_min_per_hour;
    uint8_t						mod_dawnhour;
    uint8_t						mod_duskhour;
    uint8_t						field_1D7l;

    uint32_t					mod_LL_date;					/* 0x01D8 */
    uint32_t					mod_LL_time;					/* 0x01DC */
    
    uint32_t	getModuleTime() {
    	return (mod_LL_date * 2880000LL) + mod_LL_time;
    }

	void				AddObjectToLimbo(nwn_objid_t oID);
	int 				AddObjectToLookupTable(CExoString Tag, nwn_objid_t oID);
	CNWSArea * 			GetArea(nwn_objid_t oID);
	CNWSPlayerTURD* 	GetPlayerTURDFromList(CNWSPlayer *Player);
	void 				SetScriptName(int iScript, CExoString ScriptName);
	int 				RemoveObjectFromLookupTable(CExoString Tag, nwn_objid_t oID);
	nwn_objid_t			FindObjectByTagOrdinal(CExoString *sTag, int nNth);
};

#endif

