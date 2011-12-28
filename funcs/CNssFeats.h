#pragma once
#include "CFuncLookup.h"
#include "CFuncUtility.h"

class CNssFeats : public CFuncLookup, public CFuncUtility {
public:
	CNssFeats(void);

private: //helper funcions

public: //script functions
	int AddFeat(CGameObject *oObject, char *Params);
	int AddFeatAtLevel(CGameObject *oObject, char *Params);
	int RemoveFeat(CGameObject *oObject, char *Params);
	int GetFeatKnown(CGameObject *oObject, char *Params);
	int GetAllKnownFeats(CGameObject *oObject, char *Params);
	int ClearFeatList(CGameObject *oObject, char *Params);
	int GetFeatCount(CGameObject *oObject, char *Params);

};
