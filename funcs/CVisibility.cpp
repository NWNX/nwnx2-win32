#include "stdafx.h"
#include "CVisibility.h"
#include "nwn_const.h"

CVisibility::CVisibility() {
	AddFunction("SET_VISIBILITY", L_CAST(&CVisibility::NssSetVisibility));
	AddFunction("GET_VISIBILITY", L_CAST(&CVisibility::NssGetVisibility));
	AddFunction("SET_VISIBILITY_OVERRIDE", L_CAST(&CVisibility::NssSetVisibilityOverride));
	AddFunction("GET_VISIBILITY_OVERRIDE", L_CAST(&CVisibility::NssGetVisibilityOverride));
}

CVisibility::~CVisibility() {}

int CVisibility::TestVisibility(nwn_objid_t oObject1, nwn_objid_t oObject2, int &nResult)
{
	CNWSObject *Obj1 = (CNWSObject*)(*NWN_AppManager)->app_server->GetGameObject(oObject1);
	CNWSObject *Obj2 = (CNWSObject*)(*NWN_AppManager)->app_server->GetGameObject(oObject2);
	if (Obj1 && Obj2) {
		if (Obj2->obj_type2 == OBJECT_TYPE2_CREATURE && ((CNWSCreature*)Obj2)->cre_stats->cs_is_dm) {
			nResult = 1;
			return 1;
		}

		int LocalVarOverride = Obj1->obj_vartable.GetInt(CExoString("NWNXFUNCS_VIS"));
		if (LocalVarOverride) {
			if (LocalVarOverride == Obj2->obj_vartable.GetInt(CExoString("NWNXFUNCS_VIS"))) {
				nResult = 1;
				return 1;
			}
		}

		if(objects.find(oObject1) != objects.end()){
			//__log(2, "Found object entry!");
			if(objects[oObject1].vismap.find(oObject2) != objects[oObject1].vismap.end()){
				//__log(2, "Found object-object entry!");
				nResult = objects[oObject1].vismap[oObject2];
				return 1;
			}
			else {
				switch(objects[oObject1].eOverrideType){
					case AlwaysVisible:
						nResult = 1;
						return 1;
						break;
						
					case AlwaysInvisible:
						nResult = 0;
						return 1;
						break;

					case Default:
					default:
						return 0;
				}
			}
		}
	}
	return 0;
}

void CVisibility::SetVisibilityOverride(nwn_objid_t oObject1, OverrideType eOverrideType)
{
	objects[oObject1];
	objects[oObject1].eOverrideType = eOverrideType;
}

void CVisibility::SetVisibility(nwn_objid_t oObject1, nwn_objid_t oObject2, unsigned int nValue)
{
	if(objects.find(oObject1) == objects.end()){
		objects[oObject1];
		objects[oObject1].eOverrideType = Default;
	}
	objects[oObject1].vismap[oObject2] = nValue;
}

int CVisibility::GetVisibilityOverride(nwn_objid_t oObject) {
	if ((it = objects.find(oObject)) != objects.end())
		return it->second.eOverrideType;
	return 0;
}

int CVisibility::GetVisibility(nwn_objid_t oObject1, nwn_objid_t oObject2) {
	if ((it = objects.find(oObject1)) != objects.end()) {
		if ((it_Vis = objects[oObject1].vismap.find(oObject2)) != objects[oObject1].vismap.end())
			return it_Vis->second;
	}
	return 0;
}


int CVisibility::NssSetVisibilityOverride(CGameObject *oObject, char *Params) {
	SetVisibilityOverride(oObject->obj_id, (OverrideType) atoi(Params));
	return 1;
}

int CVisibility::NssSetVisibility(CGameObject *oObject, char *Params) {
	nwn_objid_t oObject2 = OBJECT_INVALID;
	int nValue = -1;

	CParams::ExtractP2(Params, oObject2, nValue);

	SetVisibility(oObject->obj_id, oObject2, nValue);
	return 1;
}

int CVisibility::NssGetVisibilityOverride(CGameObject *oObject, char *Params) {
	sprintf(Params, "%d", GetVisibilityOverride(oObject->obj_id));
	return 1;
}

int CVisibility::NssGetVisibility(CGameObject *oObject, char *Params) {
	nwn_objid_t oObject2 = OBJECT_INVALID;
	CParams::ExtractP1(Params, oObject2);

	sprintf(Params, "%d", GetVisibility(oObject->obj_id, oObject2));
	return 1;
}