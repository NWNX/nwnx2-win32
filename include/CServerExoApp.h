#ifndef _NX_NWN_STRUCT_CSERVEREXOAPP_
#define _NX_NWN_STRUCT_CSERVEREXOAPP_

struct CServerExoApp_s {
    uint32_t                   *vftable;

    CServerExoAppInternal      *srv_internal;

	CWorldTimer*		GetActiveTimer(uint32_t a1);
	CNWSPlayer* 		GetClientObjectByObjectId(nwn_objid_t oID);
	CNWSClient * 		GetClientObjectByPlayerId(uint32_t player_id, uint8_t a3);
	CGenericObject*		GetGameObject(nwn_objid_t oID);
	int					GetIsControlledByPlayer(nwn_objid_t oID);
	int					GetModuleLanguage();
	CNWSMessage*		GetNWSMessage();
	CGameObjectArray*	GetObjectArray();
	void* 				GetPlayerList();
	CServerAIMaster*	GetServerAIMaster();

};

#endif