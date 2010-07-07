#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"


void 			(__thiscall *CNetLayer__SetConnectionsDisallowed)(CNetLayer *pTHIS, int bDisAllowConnections) = (void (__thiscall*)(CNetLayer *pTHIS, int bDisAllowConnections))0x0041F890;
int 			(__thiscall *CNetLayer__SetGameMasterPassword)(CNetLayer *pTHIS, CExoString dm_pwd) = (int (__thiscall*)(CNetLayer *pTHIS, CExoString dm_pwd))0x0041F380;

void  CNetLayer_s::SetConnectionsDisallowed(int bDisAllowConnections) {
	CNetLayer__SetConnectionsDisallowed(this, bDisAllowConnections);
}

int  CNetLayer_s::SetGameMasterPassword(CExoString dm_pwd) {
	return CNetLayer__SetGameMasterPassword(this, dm_pwd);
}

