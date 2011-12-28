#pragma once
#include "CFuncLookup.h"

class CNssServer : public CFuncLookup {
public:
	CNssServer(void);

private: //helper functions

public: //script functions
	int ClearTURDList(CGameObject *oObject, char *Params);
	int GetWorldTime(CGameObject *oObject, char *Params);
	int SetWorldTime(CGameObject *oObject, char *Params);

};
