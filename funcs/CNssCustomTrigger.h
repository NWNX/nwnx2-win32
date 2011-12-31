#pragma once
#include "CFuncLookup.h"

class CNssCustomTrigger : public CFuncLookup {
public:
	CNssCustomTrigger(void);

	bool CreateCustomGeometry(CNWSTrigger *pTHIS, CScriptLocation *Loc, CNWSArea *Area);

private: //helper functions
	bool bUseCustomTriggerGeometry;
	bool bUseAbsoluteCoordinates;
	std::vector<float> Coordinates;

	void CreateGeometry(CNWSTrigger *Trigger, CScriptLocation *Loc, CNWSArea *Area);

public: //script functions
	int SetCustomGeometry(CGameObject *oObject, char *Params);
	int RotateCustomGeometry(CGameObject *oObject, char *Params);
	int GetTriggerGeometry(CGameObject *oObject, char *Params);
};
