#pragma once
#include "CFuncLookup.h"

class CNssUtility : public CFuncLookup {
public:
	CNssUtility();

private: //helper functions

public: //Script functions
	int StringToObject(CGameObject *oObject, char *Params);
	int SetDebugLevel(CGameObject *oObject, char *Params);
	int PrintOffsets(CGameObject *oObject, char *Params);

};
