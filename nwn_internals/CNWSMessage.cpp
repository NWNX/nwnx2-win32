#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int 		(__thiscall *CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton)(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t) = (int (__thiscall *)(CNWSMessage*, CNWSPlayer *, uint8_t, int32_t))0x044E950; 
int			(__thiscall *CNWSMessage__SendServerToPlayerGameObjUpdate)(CNWSMessage*, CNWSPlayer *) = (int (__thiscall *)(CNWSMessage*, CNWSPlayer *))0x00440110;
void		(__thiscall *CNWSMessage__WriteGameObjUpdate_UpdateObject)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t) = (void (__thiscall *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t))0x00445160;
void		(__thiscall *CNWSMessage__WriteGameObjUpdate_UpdateAppearance)(CNWSMessage*, CNWSObject*, CLastUpdateObject*, uint32_t) = (void (__thiscall *)(CNWSMessage*, CNWSObject*, CLastUpdateObject*, uint32_t))0x0043E9C0;
nwn_objid_t	(__thiscall *CNWSMessage__ReadOBJECTIDServer)(CNWSMessage *pTHIS) = (nwn_objid_t (__thiscall*)(CNWSMessage *pTHIS))0x00508C80;
int			(__thiscall *CNWSMessage__SendServerToPlayerMessage)(CNWSMessage*, nwn_objid_t, uint8_t, uint8_t, uint8_t *, uint32_t) = (int (__thiscall *)(CNWSMessage*, nwn_objid_t, uint8_t, uint8_t, uint8_t *, uint32_t))0x00449F40;
int 		(__thiscall *CNWSMessage__SendServerToPlayerArea_VisualEffect)(CNWSMessage *pTHIS, CNWSPlayer* plyer, int VFX_number, float Px, float Py, float Pz) = (int (__thiscall*)(CNWSMessage *pTHIS, CNWSPlayer* plyer, int VFX_number, float Px, float Py, float Pz))0x0043A2B0;
int 		(__thiscall *CNWSMessage__SendServerToPlayerDungeonMasterAreaList)(CNWSMessage *pTHIS, CNWSPlayer *Player) = (int (__thiscall*)(CNWSMessage *pTHIS, CNWSPlayer *Player))0x00448700;
int 		(__thiscall *CNWSMessage__SendServerToPlayerChat_ServerTell)(CNWSMessage *pTHIS, uint32_t Receiver_id, CExoString Msg) = (int (__thiscall*)(CNWSMessage *pTHIS, uint32_t Receiver_id, CExoString Msg))0x0043DEA0;
int 		(__thiscall *CNWSMessage__SendServerToPlayerChat_Shout)(CNWSMessage *pTHIS, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg) = (int (__thiscall*)(CNWSMessage *pTHIS, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg))0x0043DF80;
int 		(__thiscall *CNWSMessage__SendServerToPlayerChat_Tell)(CNWSMessage *pTHIS, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg) = (int (__thiscall*)(CNWSMessage *pTHIS, uint32_t Receiver, nwn_objid_t Sender, CExoString Msg))0x0043DC90;
int 		(__thiscall *CNWSMessage__SendServerToPlayerChat_Party)(CNWSMessage *pTHIS, unsigned long, unsigned long, char*, int) = (int (__thiscall*)(CNWSMessage *pTHIS, unsigned long, unsigned long, char*, int))0x0043D790;
int 		(__thiscall *CNWSMessage__SendServerToPlayerChatMessage)(CNWSMessage *pTHIS, uint8_t Channel, nwn_objid_t Sender, char* Msg, uint32_t msg_len, uint32_t player_id) = (int (__thiscall*)(CNWSMessage *pTHIS, uint8_t Channel, nwn_objid_t Sender, char* Msg, uint32_t msg_len, uint32_t player_id))0x0043CA00;
void		(__thiscall *CNWSMessage__WriteGameObjUpdate_CharacterSheet)(CNWSMessage *pTHIS, CNWSPlayer *player, uint32_t a3) = (void (__thiscall*)(CNWSMessage *pTHIS, CNWSPlayer *player, uint32_t a3))0x00447B10;
int			(__thiscall *CNWSMessage__SendServerToPlayerPVP_Attitude_Change)(CNWSMessage *pTHIS, int oidPlayer1, int oidPlayer2, int a4) = (int(__thiscall*)(CNWSMessage *pTHIS, int oidPlayer1, int oidPlayer2, int a4))0x00450630;
int 		(__thiscall *CNWSMessage__SendServerToPlayerCCMessage)(CNWSMessage *pTHIS, unsigned long a1, unsigned char a2, CNWCCMessageData *mData, CNWSCombatAttackData *CombatAttackData) = (int(__thiscall*)(CNWSMessage *pTHIS, unsigned long a1, unsigned char a2, CNWCCMessageData *mData, CNWSCombatAttackData *CombatAttackData))0x0044B630;

nwn_objid_t CNWSMessage_s::ReadOBJECTIDServer() {
	return CNWSMessage__ReadOBJECTIDServer(this);
}

void CNWSMessage_s::WriteGameObjUpdate_CharacterSheet(CNWSPlayer* player, uint32_t a3) {
	CNWSMessage__WriteGameObjUpdate_CharacterSheet(this, player, a3);
}

int CNWSMessage_s::SendServerToPlayerArea_VisualEffect(CNWSPlayer* player, int VFX_number, float Px, float Py, float Pz) {
	return CNWSMessage__SendServerToPlayerArea_VisualEffect(this, player, VFX_number, Px, Py, Pz);
}

int CNWSMessage_s::SendServerToPlayerChat_Party(unsigned long a1, unsigned long a2, char* a3, int a4) {
	return CNWSMessage__SendServerToPlayerChat_Party(this, a1, a2, a3, a4);
}

int CNWSMessage_s::SendServerToPlayerChat_ServerTell(uint32_t Receiver_id, CExoString Msg) {
	return CNWSMessage__SendServerToPlayerChat_ServerTell(this, Receiver_id, Msg);
}

int CNWSMessage_s::SendServerToPlayerChat_Shout(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg) {
	return CNWSMessage__SendServerToPlayerChat_Shout(this, Receiver, Sender, Msg);
}

int CNWSMessage_s::SendServerToPlayerChat_Tell(uint32_t Receiver, nwn_objid_t Sender, CExoString Msg) {
	return CNWSMessage__SendServerToPlayerChat_Tell(this, Receiver, Sender, Msg);
}

int CNWSMessage_s::SendServerToPlayerChatMessage(uint8_t Channel, nwn_objid_t Sender, char* Msg, uint32_t msg_len, uint32_t player_id) {
	return CNWSMessage__SendServerToPlayerChatMessage(this, Channel, Sender, Msg, msg_len, player_id);
}
 
int CNWSMessage_s::SendServerToPlayerDungeonMasterAreaList(CNWSPlayer *Player) {
	return CNWSMessage__SendServerToPlayerDungeonMasterAreaList(this, Player);
}

int CNWSMessage_s::SendServerToPlayerGameObjUpdate(CNWSPlayer *Player) {
	return CNWSMessage__SendServerToPlayerGameObjUpdate(this, Player);
}

int CNWSMessage_s::SendServerToPlayerGuiQuickbar_SetButton(CNWSPlayer* Player, uint8_t a2, int32_t a3) {
	return CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton(this, Player, a2, a3);
}

int CNWSMessage_s::SendServerToPlayerMessage(nwn_objid_t a1, uint8_t a2, uint8_t a3, uint8_t *a4, uint32_t a5) {
	return CNWSMessage__SendServerToPlayerMessage(this, a1, a2, a3, a4, a5);
}

void CNWSMessage_s::WriteGameObjUpdate_UpdateAppearance(CNWSObject* a1, CLastUpdateObject* a2, uint32_t a3) {
	CNWSMessage__WriteGameObjUpdate_UpdateAppearance(this, a1, a2, a3);
}

void CNWSMessage_s::WriteGameObjUpdate_UpdateObject(CNWSPlayer* a1, CNWSObject* a2, CLastUpdateObject* a3, uint32_t a4, uint32_t a5) {
	CNWSMessage__WriteGameObjUpdate_UpdateObject(this, a1, a2, a3, a4, a5);
}

int CNWSMessage_s::SendServerToPlayerPVP_Attitude_Change(int oidPlayer1, int oidPlayer2, int a4) {
	return CNWSMessage__SendServerToPlayerPVP_Attitude_Change(this, oidPlayer1, oidPlayer2, a4);
}

int CNWSMessage_s::SendServerToPlayerCCMessage(unsigned long a1, unsigned char a2, CNWCCMessageData *mData, CNWSCombatAttackData *CombatAttackData) {
	return CNWSMessage__SendServerToPlayerCCMessage(this, a1, a2, mData, CombatAttackData);
}