#pragma once
#include "cFuncLookup.h"

class CNssItems : public CFuncLookup {
public:
	CNssItems(void);

private: //helper functions

public: //Script functions
	int SetItemWeight(CGameObject *oObject, char *Params);
	int SetItemValue(CGameObject *oObject, char *Params);
	int SetItemCharges(CGameObject *oObject, char *Params);
	int GetItemValue(CGameObject *oObject, char *Params);
};
