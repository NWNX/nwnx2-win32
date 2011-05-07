#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

uint32_t		(__thiscall *CNWSFaction__GetFactionMember)(CNWSFaction *pThis, int nNth, int bNPCs) = (uint32_t (__thiscall*)(CNWSFaction *pThis, int nNth, int bNPCs))0x004EA9E0;
void 			(__thiscall *CNWSFaction__SendChatMessage)(CNWSFaction *pTHIS, nwn_objid_t Sender_oID, CExoString Msg) = (void(__thiscall*)(CNWSFaction *pTHIS, nwn_objid_t Sender_oID, CExoString Msg))0x004E99A0;
	
uint32_t CNWSFaction_s::GetFactionMember(int nNth, int bNPCs) {
	return CNWSFaction__GetFactionMember(this, nNth, bNPCs);
}

void CNWSFaction_s::SendChatMessage(nwn_objid_t Sender_oID, CExoString Msg) {
	CNWSFaction__SendChatMessage(this, Sender_oID, Msg);
}