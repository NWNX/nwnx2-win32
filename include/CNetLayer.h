#ifndef _NX_NWN_STRUCT_CNETLAYER_
#define _NX_NWN_STRUCT_CNETLAYER_

struct CNetLayer_s {
    void               *unknown;

	void	SetConnectionsDisallowed(int bDisAllowConnections);
	int		SetGameMasterPassword(CExoString dm_pwd);
	int		DisconnectPlayer(unsigned long PlayerID, unsigned long tlkEntry, int a3);


};

#endif