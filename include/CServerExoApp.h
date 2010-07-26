#ifndef _NX_NWN_STRUCT_CSERVEREXOAPP_
#define _NX_NWN_STRUCT_CSERVEREXOAPP_

struct CServerExoApp_s {
    uint32_t                   *vftable;

    CServerExoAppInternal      *srv_internal;

	CNWSPlayer* 		GetClientObjectByObjectId(nwn_objid_t oID);
	CNWSClient * 		GetClientObjectByPlayerId(uint32_t player_id, uint8_t a3);
	CGenericObject*		GetGameObject(nwn_objid_t oID);
	CNWSMessage*		GetNWSMessage();
	CGameObjectArray*	GetObjectArray();
	void* 				GetPlayerList();
	int					GetModuleLanguage();

};

#endif