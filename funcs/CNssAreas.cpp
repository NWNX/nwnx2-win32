#include "stdafx.h"
#include "CNssAreas.h"

CNssAreas::CNssAreas(void) {
	getFirstNextAreaIndex = -1;

	AddFunction("GETAREACOUNT", L_CAST(&CNssAreas::GetAreaCount));
	AddFunction("GETFIRSTAREA", L_CAST(&CNssAreas::GetFirstArea));
	AddFunction("GETNEXTAREA", L_CAST(&CNssAreas::GetNextArea));
	AddFunction("GETAREABYPOSITION", L_CAST(&CNssAreas::GetAreaByPosition));
	AddFunction("GETSURFACEMATERIAL", L_CAST(&CNssAreas::GetSurfaceMaterial));
}

nwn_objid_t CNssAreas::GetAreaByPos(int iPos) {
	_log(3, "GetAreaByPos(%d)\n", iPos);
	CNWSModule *cModule = (*NWN_AppManager)->app_server->srv_internal->GetModule(); //nwn_GetModule();
	if (iPos >= cModule->mod_areas_len || iPos < 0) {
		return OBJECT_INVALID;
	}

	return cModule->mod_areas[iPos];
}

int CNssAreas::GetAreaCount(CGameObject *oObject, char *Params) {
	CNWSModule *cModule = (*NWN_AppManager)->app_server->srv_internal->GetModule();
	if (!cModule) {
		sprintf(Params, "-1");
		return 0;
	}
	
	sprintf(Params, "%d", cModule->mod_areas_len);

	return 1;
}

int CNssAreas::GetAreaByPosition(CGameObject *oObject, char *Params) {
	int iPos = 0;
	CParams::ExtractP1<int>(Params, iPos);

	nwn_objid_t oID = GetAreaByPos(iPos);
	sprintf(Params, "%08X", oID);
	return 1;
}

int CNssAreas::GetFirstArea(CGameObject *oObject, char *Params) {
	getFirstNextAreaIndex = 0;
	nwn_objid_t oID = OBJECT_INVALID;

	oID = GetAreaByPos(getFirstNextAreaIndex);
	if (oID == OBJECT_INVALID) getFirstNextAreaIndex=-1;

	sprintf(Params, "%08X", oID);

	return 1;
}

int CNssAreas::GetNextArea(CGameObject *oObject, char *Params) {
	nwn_objid_t oID = OBJECT_INVALID;

	if (getFirstNextAreaIndex < 0) {
		oID = OBJECT_INVALID; // skip out if there are no more areas
	}
	else {
		getFirstNextAreaIndex++;
		oID = GetAreaByPos(getFirstNextAreaIndex);
		if (oID == OBJECT_INVALID) getFirstNextAreaIndex = -1;
	}

	sprintf(Params, "%08X", oID);

	return 1;
}

int CNssAreas::GetSurfaceMaterial(CGameObject *oObject, char *Params) {
	int Result = -1;
	uint32_t oID=0;
	float x=0.0,y=0.0,z=0.0;
	nwn_objid_t oidArea = 0;

	sscanf(Params, "%08X %f %f %f", &oidArea, &x, &y, &z);

	CNWSArea *Area = (*NWN_AppManager)->app_server->srv_internal->GetAreaByGameObjectID(oidArea);
	if (Area) {
		CNWTile *Tile = Area->GetTile(x, y, (int)z);
		if (Tile) {
			int Tile_x=0, Tile_y=0;
			((CNWTile*)Tile)->GetLocation(&Tile_x, &Tile_y);
			x = x - (long double)Tile_x * 10.0;
			y = y - (long double)Tile_y * 10.0;
			
			Result = ((CNWSTile*)Tile)->GetSurfaceMaterial(x, y, z);
			sprintf(Params, "%d", Result);
			return 1;
		}
		else _log(3, "Tile invalid\n");
	}
	else _log(3, "Area invalid\n");

	
	sprintf(Params, "-1");
	return 0;
}