#pragma once
#include "cfunclookup.h"

class CNssItemProperty : public CFuncLookup {
public:
	CNssItemProperty(void);

	int GetItemPropertyInformation();
	int ItemPropertyCustom(void *CVirtComm, int a1);

};
