#include "stdafx.h"
#include "CVisibility.h"
#include "nwnx_funcs.h"

extern CNWNXFuncs NWNFuncs;

#define __log(a,b,...) if(a<=NWNFuncs.debugLevel)NWNFuncs.LOG(b,__VA_ARGS__)

CVisibility::CVisibility() {}

CVisibility::~CVisibility() {}

int CVisibility::TestVisibility(nwn_objid_t oObject1, nwn_objid_t oObject2, int &nResult)
{
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
