#ifndef _NX_NWN_STRUCT_CNWSFACTION_
#define _NX_NWN_STRUCT_CNWSFACTION_

struct CNWSFaction_s {
    nwn_objid_t        *members_oID;
    uint32_t             members_len;
    uint32_t            members_alloc;

    uint32_t            fac_id;

    uint32_t            field_10;
    uint32_t            first_nextCounter;

    char               *fac_name;

	uint32_t GetFactionMember(int nNth, int bNPCs);
	void SendChatMessage(nwn_objid_t Sender_oID, CExoString Msg);
};

#endif
