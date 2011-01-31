#ifndef _NX_NWN_STRUCT_CNWSMESSAGE_
#define _NX_NWN_STRUCT_CNWSMESSAGE_

struct CNWSMessage_s {
    void               *unknown;

	nwn_objid_t ReadOBJECTIDServer();
	int 		SendServerToPlayerArea_VisualEffect(CNWSPlayer* player, int VFX_number, float Px, float Py, float Pz);
	int 		SendServerToPlayerChat_Party(unsigned long, unsigned long, char*, int);
	int 		SendServerToPlayerChat_ServerTell(uint32_t Receiver_id, CExoString Msg);
	int 		SendServerToPlayerChat_Shout(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_Tell(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChatMessage(uint8_t Channel, nwn_objid_t Sender, char* Msg, uint32_t msg_len, uint32_t player_id); 
	int 		SendServerToPlayerDungeonMasterAreaList(CNWSPlayer *Player);
	int			SendServerToPlayerGameObjUpdate(CNWSPlayer *);
	int 		SendServerToPlayerGuiQuickbar_SetButton(CNWSPlayer*, uint8_t, int32_t);
	int			SendServerToPlayerMessage(nwn_objid_t, uint8_t, uint8_t, uint8_t *, uint32_t);
	int			SendServerToPlayerPVP_Attitude_Change(int oidPlayer1, int oidPlayer2, int a4);
	void 		WriteGameObjUpdate_CharacterSheet(CNWSPlayer* player, uint32_t a3);
	void		WriteGameObjUpdate_UpdateAppearance(CNWSObject*, CLastUpdateObject*, uint32_t);
	void		WriteGameObjUpdate_UpdateObject(CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t);

};

#endif