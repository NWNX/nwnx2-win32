#include "StdAfx.h"
#include "nwnx_trinity.h"
#include "../NWNXdll/IniFile.h"
#include <math.h>
#include <string>
#include <hash_map>
#include "HookFunc.h"

#define _log(a,b,...) if(a<=debugLevel)_LOG(b,__VA_ARGS__)

CNWNXTrinity::CNWNXTrinity() {

}

CNWNXTrinity::~CNWNXTrinity() {
	OnRelease();
}

BOOL CNWNXTrinity::OnCreate(const char* LogDir) {
	// call the base class function
	char log[MAX_PATH];
	sprintf_s (log, "%s\\nwnx_events.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;
	fclose(m_fFile); // we're using a custom logger

	LoadConfiguration();
	WriteLogHeader();
	//HookFunctions();

	CreateFunctionLookup();
	ServInternal = (*NWN_AppManager)->app_server->srv_internal;
	ObjectIndex = 0;
	Area = NULL;

	return true;
}

BOOL CNWNXTrinity::OnRelease() {
	_log(0, "o Shutting down\n");

	// call base class function
	return CNWNXBase::OnRelease();
}

void CNWNXTrinity::LoadConfiguration() {
	CIniFile iniFile ("nwnx.ini");
	debugLevel = iniFile.ReadInteger("TRINITY", "debugLevel", 0);
	iniFile.ReadString("TRINITY", "NegXPVar", NegXPVar, 64, "MC_NEG_XP");

}

void CNWNXTrinity::WriteLogHeader() {
	_log(0, "Windows NWNX Trinity plugin v.0.0.1 [debugLevel %d]\n", debugLevel);
}

void CNWNXTrinity::CreateFunctionLookup() {
	int i = 0;

	i = 0;		FunctionLookup["GETKILLXP"]			= i; pFunc[i] = &CNWNXTrinity::GiveKillXPToParty;
	i = 1;		FunctionLookup["GIVEXPTOCREATURE"]	= i; pFunc[i] = &CNWNXTrinity::GiveXPToCreature;
	i = 2;		FunctionLookup["PLCTAKEITEM"]		= i; pFunc[i] = &CNWNXTrinity::PLCTakeItem;
	i = 3;		FunctionLookup["CRETAKEITEM"]		= i; pFunc[i] = &CNWNXTrinity::CreatureTakeItem;
}

char* CNWNXTrinity::OnRequest(char *gameObject, char* Request, char* Parameters) {
	_log(1, "+ StrRqst: %s\tParams: %s\n", Request, Parameters);
	if (strlen(Request) < 1) return NULL;

	stdext::hash_map<std::string, int>::iterator it;
	it = FunctionLookup.find(Request);
	if (it != FunctionLookup.end()) {
		(*this.*pFunc[it->second])(gameObject, Parameters);
	}


	return NULL;
}

void CNWNXTrinity::PLCTakeItem(char *gameObject, char* Parameters) {
	uint32_t oId_Item = 0, oID_From = 0, oID_Placeable = 0;
	int bFeedback = 0;
	sscanf(Parameters, "%08X %08X %08X, %d", &oID_Placeable, &oId_Item, &oID_From, &bFeedback);
	
	CNWSItem *Item = (CNWSItem*)((char*)(CServerExoAppInternal__GetItemByGameObjectID((*NWN_AppManager)->app_server->srv_internal , NULL, oId_Item))+0x0);
	CNWSPlaceable *plc = CServerExoAppInternal__GetPlaceableByGameObjectID((*NWN_AppManager)->app_server->srv_internal , NULL, oID_Placeable);

	if (Item && plc)
		CNWSPlaceable__AcquireItem(plc, NULL, &Item, oID_From, 1, 1, bFeedback);
}

void CNWNXTrinity::CreatureTakeItem(char *gameObject, char* Parameters) {
	uint32_t oId_Item = 0, oID_Cre = 0, oID_From = 0;
	int bFeedback = 0;
	sscanf(Parameters, "%08X %08X %08X, %d", &oID_Cre, &oId_Item, &oID_From, &bFeedback);
	
	CNWSItem *Item = (CNWSItem*)((char*)(CServerExoAppInternal__GetItemByGameObjectID((*NWN_AppManager)->app_server->srv_internal , NULL, oId_Item))+0x0);
	CNWSCreature *cre = CServerExoAppInternal__GetCreatureByGameObjectID((*NWN_AppManager)->app_server->srv_internal , NULL, oID_Cre);

	if (Item && cre)
		CNWSCreature__AcquireItem(cre, NULL, &Item, oID_From, -1, -1, bFeedback);
}

int CNWNXTrinity::PointInpoly(int nvert, float *vertx, float *verty, float &testx, float &testy)
{
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((verty[i]>testy) != (verty[j]>testy)) &&
	 (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
       c = !c;
  }
  return c;
}

void CNWNXTrinity::SetConeCoords(CNWSObject *obj) {
	float cosi = obj->obj_orientation.x;
	float sini = obj->obj_orientation.y;
	
	fx[0] = 0.0; fx[1] =  12.932; fx[2] = 17.665; fx[3] = 17.665; fx[4] = 12.932;
	fy[0] = 0.0; fy[1] = -12.932; fy[2] = -4.733; fy[3] =  4.733; fy[4] = 12.932;

	float fy_n=0.0, fx_n=0.0;
	float px = obj->obj_position.x, py = obj->obj_position.y;

	for (int i=0; i<5; i++) {
		fx_n = (fx[i] * cosi - fy[i] * sini) + px;
		fy_n = (fx[i] * sini + fy[i] * cosi) + py;
		fx[i] = fx_n;
		fy[i] = fy_n;
	}
}

nwn_objid_t CNWNXTrinity::GetCreatureInShapeByIndex(CNWSObject *obj) {
	CNWSCreature *cre;
	CNWSObject *cre_obj;
	while  (ObjectIndex < Area->obj_list_len) {
		cre = CServerExoAppInternal__GetCreatureByGameObjectID(ServInternal, NULL, Area->obj_list[ObjectIndex]);
		if (cre) {
			if(obj->obj_generic.obj_id != (cre_obj = (CNWSObject*)cre)->obj_generic.obj_id) {
				_log(3, "cre[%08X]: (%.2f|%.2f)\n", cre_obj, cre_obj->obj_position.x, cre_obj->obj_position.y);
				if (PointInpoly(5, &fx[0], &fy[0], cre_obj->obj_position.x, cre_obj->obj_position.y)) {
					return cre_obj->obj_generic.obj_id;
				}
			}
		}
		++ObjectIndex;
	}
	return OBJECT_INVALID;
}

unsigned long CNWNXTrinity::OnRequestObject (char *gameObject, char* Request) {
	_log(1, "- ObjReq: %08X             Request: %s\n", gameObject, Request);

	uint32_t ret = OBJECT_INVALID;

	std::string sRequest = Request;
	int iP = sRequest.find("¬");
	if (iP != std::string::npos) {
		std::string sAreaID = sRequest.substr(iP+1, sRequest.length()-iP);
		sRequest = sRequest.substr(0, iP);

		if (strcmp(sRequest.c_str(), "GETFIRSTIN") == 0) {
			CNWSObject *obj = (CNWSObject*)gameObject;
			if (obj) {
				nwn_objid_t AreaID = 0;
				sscanf(sAreaID.c_str(), "%08X", &AreaID);
				ObjectIndex = 0;
				SetConeCoords(obj);

				Area = CServerExoAppInternal__GetAreaByGameObjectID(ServInternal, NULL, AreaID);
				if (Area) {
					return GetAllCreaturesInShape(obj);
				}
			}
		}
		else if (strcmp(sRequest.c_str(), "GETALLCREATUERSINSHAPE") == 0) {
			CNWSObject *obj = (CNWSObject*)gameObject;
			if (obj) {
				nwn_objid_t AreaID = 0;
				sscanf(sAreaID.c_str(), "%08X", &AreaID);
				SetConeCoords(obj);

				Area = CServerExoAppInternal__GetAreaByGameObjectID(ServInternal, NULL, AreaID);
				return GetAllCreaturesInShape(obj);
			}
		}

	}
	else if (strcmp(Request, "GETNEXTIN") == 0) {
		CNWSObject *obj = (CNWSObject*)gameObject;
		++ObjectIndex;
		return GetCreatureInShapeByIndex(obj);
	}
	else if (strcmp(Request, "GETFIRSTINSHAPE") == 0) {
		CNWSObject *obj = (CNWSObject*)gameObject;
		oIDsInShape_it = oIDsInShape.begin();
		return GetCreatureInShape(obj);
	}
	else if (strcmp(Request, "GETNEXTINSHAPE") == 0) {
		CNWSObject *obj = (CNWSObject*)gameObject;
		return GetCreatureInShape(obj);
	}
	return OBJECT_INVALID; 
}

nwn_objid_t CNWNXTrinity::GetAllCreaturesInShape(CNWSObject *obj) {
	_log(3, "GETALL\n");
	CNWSCreature *cre;
	CNWSObject *cre_obj;
	oIDsInShape.clear();
	int i = 0;
	uint32_t FirstoID = OBJECT_INVALID;
	_log(3, "GETALL: Arealistlen: %d\n", Area->obj_list_len);
	Vector v1, v2, v3;
	v3.x = 0.0, v3.y = 0.0; v3.z = 0.0;
	uint32_t temp;
	while  (i < Area->obj_list_len) {
		cre = CServerExoAppInternal__GetCreatureByGameObjectID(ServInternal, NULL, Area->obj_list[i]);
		if (cre) {
			_log(3, "Cre Valid\n");
			if(obj->obj_generic.obj_id != (cre_obj = (CNWSObject*)cre)->obj_generic.obj_id) {
				v1 = obj->obj_position; v1.z += 1.0;
				v2 = cre_obj->obj_position; v2.z += 1.0;
				if (PointInpoly(5, &fx[0], &fy[0], cre_obj->obj_position.x, cre_obj->obj_position.y)
					&& CNWSArea__ClearLineOfSight(Area, NULL, v1, v2, &v3, &temp, OBJECT_INVALID, OBJECT_INVALID, 1)
				) {
					_log(3, "cre[%08X]: (%.2f|%.2f)\n", cre_obj, cre_obj->obj_position.x, cre_obj->obj_position.y);
					oIDsInShape.push_back(cre_obj->obj_generic.obj_id);
				}
			}
		}
		++i;
	}
	_log(3, "/GETALL: %d\n", oIDsInShape.size());

	if (oIDsInShape.size() > 0) {
		oIDsInShape_it = oIDsInShape.begin();
		++oIDsInShape_it;
		return oIDsInShape.front();
	}
	else {
		oIDsInShape_it = oIDsInShape.end();
		return OBJECT_INVALID;
	}
}

nwn_objid_t CNWNXTrinity::GetCreatureInShape(CNWSObject *obj) {
	_log(3, "GetCreatureInShape\n");
	CNWSObject *cre_obj;
	CNWSCreature *cre;
	Vector v1, v2, v3;
	v3.x = 0.0, v3.y = 0.0; v3.z = 0.0;
	uint32_t temp;
	while (oIDsInShape_it != oIDsInShape.end()) {
		cre = CServerExoAppInternal__GetCreatureByGameObjectID(ServInternal, NULL, *oIDsInShape_it);
		if (cre) {
			cre_obj = (CNWSObject*)cre;
			_log(3, "cre[%08X]: (%.2f|%.2f)\n", cre_obj, cre_obj->obj_position.x, cre_obj->obj_position.y);
			v1 = obj->obj_position; v1.z += 1.0;
			v2 = cre_obj->obj_position; v2.z += 1.0;
			if (PointInpoly(5, &fx[0], &fy[0], cre_obj->obj_position.x, cre_obj->obj_position.y)
				&& CNWSArea__ClearLineOfSight(Area, NULL, v1, v2, &v3, &temp, OBJECT_INVALID, OBJECT_INVALID, 1)
			) {
				++oIDsInShape_it;
				return cre_obj->obj_generic.obj_id;
			}
			else {
				std::list<uint32_t>::iterator it_temp = oIDsInShape_it;
				++oIDsInShape_it;
				oIDsInShape.erase(it_temp);
				continue;
			}					
		}
		++oIDsInShape_it;
	}
	return OBJECT_INVALID;
}

void CNWNXTrinity::GiveKillXPToParty(char *gameObject, char *Parameters) {
	nwn_objid_t VictimoID = OBJECT_INVALID;
	if (sscanf_s(Parameters, "%08x", &VictimoID) == 1) {
		if (VictimoID != OBJECT_INVALID) {
			CNWSObject *obj = (CNWSObject*)gameObject;
			if (obj->obj_generic.obj_type2 == 5 && ((CNWSCreature*)gameObject)->cre_is_pc) {
				CTrinityXP((CGenericObject*)obj, VictimoID);
			}
		}
	}
}

void CNWNXTrinity::GiveXPToCreature(char *gameObject, char *Parameters) {
	float fXP=0.0;
	if (sscanf_s(Parameters, "%f", &fXP) == 1 && fXP > 0.0) {
		CNWSObject *obj = (CNWSObject*)gameObject;
		if (obj->obj_generic.obj_type2 == 5 && ((CNWSCreature*)gameObject)->cre_is_pc) {
			CTrinityXP((CNWSCreature*)gameObject, fXP);
		}
	}
}

int CNWNXTrinity::CanLevelUpXP(CNWSCreatureStats *Stats) {
	int nClasses = Stats->cs_classes_len;
	int iLevel = 0;
	for (int i=0; i<nClasses; i++) {
		iLevel += Stats->cs_classes[i].cl_level;
	}

	int bCanLevelUp = 0;

	if (iLevel < 60) {
		int XPNeeded;
		switch (iLevel) {
			case  1 : XPNeeded =    1000; break;
			case  2 : XPNeeded =    3000; break;
			case  3 : XPNeeded =    6000; break;
			case  4 : XPNeeded =   10000; break;
			case  5 : XPNeeded =   15000; break;
			case  6 : XPNeeded =   21000; break;
			case  7 : XPNeeded =   28000; break;
			case  8 : XPNeeded =   36000; break;
			case  9 : XPNeeded =   45000; break;
			case 10 : XPNeeded =   55000; break;
			case 11 : XPNeeded =   66000; break;
			case 12 : XPNeeded =   78000; break;
			case 13 : XPNeeded =   91000; break;
			case 14 : XPNeeded =  105000; break;
			case 15 : XPNeeded =  120000; break;
			case 16 : XPNeeded =  136000; break;
			case 17 : XPNeeded =  153000; break;
			case 18 : XPNeeded =  171000; break;
			case 19 : XPNeeded =  190000; break;
			case 20 : XPNeeded =  210000; break;
			case 21 : XPNeeded =  231000; break;
			case 22 : XPNeeded =  253000; break;
			case 23 : XPNeeded =  276000; break;
			case 24 : XPNeeded =  300000; break;
			case 25 : XPNeeded =  325000; break;
			case 26 : XPNeeded =  351000; break;
			case 27 : XPNeeded =  378000; break;
			case 28 : XPNeeded =  406000; break;
			case 29 : XPNeeded =  435000; break;
			case 30 : XPNeeded =  465000; break;
			case 31 : XPNeeded =  496000; break;
			case 32 : XPNeeded =  528000; break;
			case 33 : XPNeeded =  561000; break;
			case 34 : XPNeeded =  595000; break;
			case 35 : XPNeeded =  630000; break;
			case 36 : XPNeeded =  666000; break;
			case 37 : XPNeeded =  703000; break;
			case 38 : XPNeeded =  741000; break;
			case 39 : XPNeeded =  780000; break;
			case 40 : XPNeeded =  821000; break;
			case 41 : XPNeeded =  882000; break;
			case 42 : XPNeeded =  950000; break;
			case 43 : XPNeeded = 1025000; break;
			case 44 : XPNeeded = 1108000; break;
			case 45 : XPNeeded = 1200000; break;
			case 46 : XPNeeded = 1301000; break;
			case 47 : XPNeeded = 1413000; break;
			case 48 : XPNeeded = 1536000; break;
			case 49 : XPNeeded = 1672000; break;
			case 50 : XPNeeded = 1822000; break;
			case 51 : XPNeeded = 1986000; break;
			case 52 : XPNeeded = 2167000; break;
			case 53 : XPNeeded = 2365000; break;
			case 54 : XPNeeded = 2582000; break;
			case 55 : XPNeeded = 2819000; break;
			case 56 : XPNeeded = 3077000; break;
			case 57 : XPNeeded = 3360000; break;
			case 58 : XPNeeded = 3665000; break;
			case 59 : XPNeeded = 4000000; break;
		}
		if (Stats->cs_xp >= XPNeeded) bCanLevelUp = 1;
		_log(3, "XP: %d\tLevel: %d\tNeeded: %d", Stats->cs_xp, iLevel, XPNeeded);
	}
	_log(3, "CanLevelUp: %d\n", bCanLevelUp);
	return bCanLevelUp;
}