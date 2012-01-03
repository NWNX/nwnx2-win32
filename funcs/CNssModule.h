#pragma once
#include "CFuncLookup.h"

class CNssModule :public CFuncLookup {
public:
	CNssModule(void);

private: //helper functions

public: //script functions
	int GetTimeOfDay(CGameObject *oObject, char *Params);
};
