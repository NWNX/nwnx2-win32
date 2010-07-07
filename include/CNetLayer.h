#ifndef _NX_NWN_STRUCT_CNETLAYER_
#define _NX_NWN_STRUCT_CNETLAYER_

struct CNetLayer_s {
    void               *unknown;

	void	SetConnectionsDisallowed(int bDisAllowConnections);
	int		SetGameMasterPassword(CExoString dm_pwd);

};

#endif