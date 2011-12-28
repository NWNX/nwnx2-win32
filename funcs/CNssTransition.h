#pragma once
#include "CFuncLookup.h"

class CNssTransition : public CFuncLookup {
public:
	CNssTransition(void);

private: //helper functions

public: //script functions
	int GetDestinationTag(CGameObject *oObject, char *Params);
	int SetDestinationTag(CGameObject *oObject, char *Params);

};
