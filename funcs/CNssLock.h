#pragma once
#include "CFuncLookup.h"

class CNssLock : public CFuncLookup {
public:
	CNssLock(void);

private: //helper functions

public: //script functions
	int GetAutoRemoveKey(CGameObject *oObject, char *Params);
	int SetAutoRemoveKey(CGameObject *oObject, char *Params);

};
