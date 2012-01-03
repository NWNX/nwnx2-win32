#pragma once
#include "CFuncLookup.h"
#include "types.h"

class CNssAreas : public CFuncLookup {
public:
	CNssAreas(void);

private: //helper functions
	nwn_objid_t GetAreaByPos(int iPos);
	
	int getFirstNextAreaIndex;

public: //Script functions
	int GetAreaCount(CGameObject *oObject, char *Params);
	int GetAreaByPosition(CGameObject *oObject, char *Params);
	int GetFirstArea(CGameObject *oObject, char *Params);
	int GetNextArea(CGameObject *oObject, char *Params);
	int GetSurfaceMaterial(CGameObject *oObject, char *Params);
	int SetNoRestFlag(CGameObject *oObject, char *Params);
	int GetNoRestFlag(CGameObject *oObject, char *Params);
};
