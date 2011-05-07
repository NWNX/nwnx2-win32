#ifndef _NX_NWN_STRUCT_CNWSMESSAGE_
#define _NX_NWN_STRUCT_CNWSMESSAGE_

struct CNWSMessage_s {
    void               *unknown;

	nwn_objid_t ReadOBJECTIDServer();
	int 		SendServerToPlayerArea_VisualEffect(CNWSPlayer* player, int VFX_number, float Px, float Py, float Pz);
	int 		SendServerToPlayerCCMessage(unsigned long a1, unsigned char a2, CNWCCMessageData *mData, CNWSCombatAttackData *CombatAttackData);
	int 		SendServerToPlayerChat_DM_Talk(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_DM_Whisper(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_Party(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_ServerTell(uint32_t Receiver_id, CExoString Msg);
	int 		SendServerToPlayerChat_Shout(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_Silent_Shout(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_Talk(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_Tell(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChat_Whisper(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg);
	int 		SendServerToPlayerChatMessage(uint8_t Channel, nwn_objid_t Sender, CExoString Msg, uint32_t player_id); 
	int 		SendServerToPlayerDungeonMasterAreaList(CNWSPlayer *Player);
	int			SendServerToPlayerGameObjUpdate(CNWSPlayer *);
	int 		SendServerToPlayerGuiQuickbar_SetButton(CNWSPlayer*, uint8_t, int32_t);
	int			SendServerToPlayerMessage(nwn_objid_t Receiver, uint8_t a2, uint8_t Channel, void *pMessagedata, nwn_objid_t Sender);
	int			SendServerToPlayerPVP_Attitude_Change(int oidPlayer1, int oidPlayer2, int a4);
	void 		WriteGameObjUpdate_CharacterSheet(CNWSPlayer* player, uint32_t a3);
	void		WriteGameObjUpdate_UpdateAppearance(CNWSObject*, CLastUpdateObject*, uint32_t);
	void		WriteGameObjUpdate_UpdateObject(CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t);
	
	int SendServerToPlayerArea_ClientArea(CNWSPlayer_s *Player, CNWSArea *Area, Vector Pos, Vector *Rot, int a8);
	int CNWSMessage_s::SendServerToPlayerModule_Info(uint32_t PlayerID);
};

#endif