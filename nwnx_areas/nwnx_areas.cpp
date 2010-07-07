#include "StdAfx.h"
#include "nwnx_areas.h"
#include "../NWNXdll/IniFile.h"
#include "HookFunc.h"
#include "vector"

#define _log(a,b,...) if(a<=debugLevel)LOG(b,__VA_ARGS__)

CNWNXAreas::CNWNXAreas() {
	nLastAreaID = 0x7F000000;
}

CNWNXAreas::~CNWNXAreas() {
	OnRelease();
}

BOOL CNWNXAreas::OnCreate(const char* LogDir) {
	// call the base class function
	char _log[MAX_PATH];
	sprintf (_log, "%s\\nwnx_areas.txt", LogDir);
	if (!CNWNXBase::OnCreate(_log))
		return false;

	LoadConfiguration();
	WriteLogHeader(debugLevel);
	HookFunctions();

	return true;
}

void CNWNXAreas::LoadConfiguration() {
	CIniFile iniFile ("nwnx.ini");
	debugLevel = iniFile.ReadInteger("AREAS", "DebugLevel", 0);

	// steal the respath information from the resman section
	iniFile.ReadString("RESOURCEMANAGER", "SourcePath", m_sourcePath, 512, "");
	iniFile.ReadString("AREAS", "LocationFailSafe", LocationFailSafe, 512, "");
}

BOOL CNWNXAreas::OnRelease() {
	LOG("o Shutting down\n");

	// call base class function
	return CNWNXBase::OnRelease();
}

char* CNWNXAreas::OnRequest(char *gameObject, char* Request, char* Parameters) {
	_log(1, "- StrReq: \"%s\"\tParams: \"%s\"\n", Request, Parameters);

	if (gameObject == NULL) {
		_log(1, "o Error: Invalid Object passed to nwnx_areas.\n");
		sprintf(Parameters, "");
		return NULL;
	}

	else if (strncmp(Request, "CREATE_AREA", 11) == 0) {
		if (LoadArea(Parameters)) sprintf(Parameters, "1");
		else sprintf(Parameters, "0");
	}
	else if (strncmp(Request, "DESTROY_AREA", 12) == 0) {
		if (DestroyArea(strtol(Parameters, (char **)NULL, 16))) sprintf(Parameters, "1");
		else sprintf(Parameters, "0");

	} 
	else if (strncmp(Request, "SET_AREA_NAME", 13) == 0) {
		if (SetAreaName((CNWSArea*)gameObject, Parameters)) sprintf(Parameters, "1");
		else sprintf(Parameters, "0");
	}

	return 0;


	return NULL;
}

unsigned long CNWNXAreas::OnRequestObject (char *gameObject, char* Request){
	_log(1, "+ ObjReq: %08X             Request: %s\n", gameObject, Request);

	if (strcmp(Request, "GET_LAST_AREA_ID") == 0) {
		return nLastAreaID;
	}
	return OBJECT_INVALID; 
}

void CNWNXAreas::LOG(const char *pcMsg, ...) {
	va_list argList;
	char *pos;

	if (m_fFile)
	{  

		if (ftell(m_fFile) > m_maxLogSizeKB)
		{	
			fclose(m_fFile);
			m_fFile = fopen (m_LogFile, "w");
			WriteLogHeader(debugLevel);
			fprintf(m_fFile, "o Logfile hit maximum size limit, starting again.\n");
		}

		// build up the string
		va_start(argList, pcMsg);
		vsprintf(acBuffer, pcMsg, argList);
		va_end(argList);

		// replace any percent signs
		pos = strchr(acBuffer, '%');
		while (pos)
		{
			*pos = '~';
			pos = strchr(acBuffer, '%');
		}

		// _log string in file
		fprintf (m_fFile, acBuffer);
		fflush (m_fFile);
	}
}

void CNWNXAreas::WriteLogHeader(int debug)
{
	fprintf(m_fFile, "Windows NWNX Areas plugin v.0.0.1");
	if (!debug) fprintf(m_fFile, " [logging off]");
	else fprintf(m_fFile, " [_log level: %i]", debug);
	fprintf(m_fFile, "\n");
	fflush (m_fFile);
}

CResRef *CResRef____as(CResRef *res, char *str)
{
	memset(res->resref, 0, 0x10);
	strncpy(res->resref, str, 0x10);
	return res;
}

int CNWNXAreas::UpdateAreasForDMs() {
	CNWSMessage *pMessage = ((*NWN_AppManager)->app_server)->GetNWSMessage();
	CExoLinkedList *pPlayerList = (CExoLinkedList*)((*NWN_AppManager)->app_server)->GetPlayerList();
	CExoLinkedListElement *pElement = pPlayerList->GetHeadPos();
	while (pElement) {
		CNWSPlayer *pPlayer = (CNWSPlayer*)pPlayerList->GetAtPos(pElement);
		if (pPlayer) pMessage->SendServerToPlayerDungeonMasterAreaList(pPlayer);
		pElement = pPlayerList->GetNext(pElement);
	}

	return 1;
}

int CNWNXAreas::LoadArea(char* ResRef) {
	char sResRef[20];
	sscanf(ResRef, "%s", sResRef);

	char *pMod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	CNWSModule *pModule = (CNWSModule*)(pMod+0x1C);

	_log(3, "o AreaCount: %d\n", pModule->mod_areas_len);

	CResRef res;
	CResRef____as(&res, sResRef);

	CNWSArea *pArea = (CNWSArea*)malloc(0x20C);
	pArea->CNWSArea(res, 0, OBJECT_INVALID);

	if (!pArea->LoadArea(0)) {
		_log(1, "o Error: Load failed: '%s'\n", sResRef);
		pArea->scalar_Destructor(1);
		nLastAreaID = OBJECT_INVALID;
		return 0;
	}
	uint32_t nAreaID = *((uint32_t *)pArea+0x32);

	void *pArray = ((uint32_t *)pModule+0x6);
	CExoArrayList_uint32___Add(pArray, NULL, nAreaID);

	_log(3, "o Area added\n", nAreaID);

	nLastAreaID = nAreaID;
	AddAreaToCreatures(pModule, nAreaID);
	UpdateAreasForDMs();

	return 1;
}

int CNWNXAreas::DestroyArea(nwn_objid_t nAreaID) {
	if (!nAreaID || nAreaID == OBJECT_INVALID) {
		return 0;
	}

	CNWSArea* pArea = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(nAreaID);
	if (!pArea) return 0;

	if (pArea->are_numplayers > 0) {
		_log(1, "o NumPlayers > 0; aborting\n");
		return 0;
	}

	char *pMod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	CNWSModule *pModule = (CNWSModule*)(pMod+0x1C);
	
	CGameObjectArray *objArray = ((*NWN_AppManager)->app_server)->GetObjectArray();

	_log(1, "o Destroying objects in area %08X\n", nAreaID);
	nwn_objid_t nTmpObj;

	std::vector<uint32_t> Objects;

	int bContinue=0;
	bContinue = pArea->GetFirstObjectInArea(&nTmpObj);
	do{
		Objects.push_back(nTmpObj);
	} while (pArea->GetNextObjectInArea(&nTmpObj));

	CGenericObject *pObject;

	while (!Objects.empty()) {
		nTmpObj = Objects.back();
		Objects.pop_back();
		pObject = (CGenericObject*)((*NWN_AppManager)->app_server->srv_internal)->GetGameObject(nTmpObj);
		if (!pObject) continue;

		CNWSArea *Area = NULL;
		_log(3, "o Object: %08X\tAddr: %08X\tObjtype: %d\n", pObject->obj_id, pObject, pObject->obj_type2);
		if (pObject->obj_type2 == 16) {
			// move the playerTURD to a different area instead of deleting it
			CNWSPlayerTURD *TURD = (CNWSPlayerTURD*)pObject;
			CNWSScriptVarTable *svTable = &TURD->TURD_ScriptvarTable;
			CScriptLocation Loc;
			Loc.loc_area = OBJECT_INVALID;
			Loc.loc_position .x = 0.0; Loc.loc_position.y = 0.0; Loc.loc_position.y = 0.0;
			Loc.loc_orientation.x = 0.0; Loc.loc_orientation.y = 0.0; Loc.loc_orientation.z = 0.0;

			CExoString VarName(LocationFailSafe);
			if (svTable) {
				Loc = svTable->GetLocation(VarName);
				Area = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(Loc.loc_area);
				_log(3, "o Creature LocationFailSafe AreaID: %08X\n", Loc.loc_area);
				if (!Area) {
					char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal->GetModule());
					CNWSModule *Mod= (CNWSModule*)(mod+0x1C);
					svTable = &Mod->mod_vartable;

					if (svTable) {
						Loc = svTable->GetLocation(VarName);
						_log(3, "o Module LocationFailSafe AreaID: %08X\n", Loc.loc_area);
						Area = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(Loc.loc_area);
					}
				}
			}
			if (Area) {
				_log(3, "\tLocationFailSafe Area valid.\n");
				pArea->RemoveObjectFromArea(TURD->TURD_id);
				Area->AddObjectToArea(TURD->TURD_id, 0);
				((CNWSObject*)TURD)->SetArea(Area);
			}
		}

		if (!Area) {
			void (__fastcall *pDestructor)(CGenericObject *pTHIS, void *pVOID, int flag) = (void (__fastcall*)(CGenericObject *pTHIS, void *pVOID, int flag))(*(DWORD*)((DWORD*)(pObject->obj_type)));
			pDestructor(pObject, NULL, 1);
			objArray->DEL(nTmpObj); //removes entry in the gameobject array*/
		}

	}

	_log(1, "o Unregistering area %08X\n", nAreaID);
	void *pArray = ((uint32_t *)pModule+0x6);
	CExoArrayList_uint32___Remove(pArray, NULL, nAreaID);

	_log(1, "o Destroying area %08X\n", nAreaID);
	pArea->scalar_Destructor(1);
	RemoveAreaForCreatures(pModule, nAreaID);
	UpdateAreasForDMs();

	return 1;
}

int CNWNXAreas::AddAreaToCreatures(CNWSModule *pModule, nwn_objid_t nAreaID) {
	CGameObjectArray *pGameObjArray = ((*NWN_AppManager)->app_server)->GetObjectArray();

	_log(3, "o Module Area Count: %d\n", pModule->mod_areas_len);
	if (!pGameObjArray) return NULL;
	for (int i=0; i<=0xFFF; i++) {
		CGameObjectArrayElement **pObjects = pGameObjArray->Objects;
		CGameObjectArrayElement  *pElement = pObjects[i];
		if (!pElement) continue;
		CNWSCreature *pObject = (CNWSCreature*)pElement->Object;
		if (!pObject) continue;
		if (pObject->obj.obj_generic.obj_type2 == 5) {
			if (pObject->cre_areaminimaps) {
				_log(3, "o Adding minimap to creature '%08X'\n", pObject->obj.obj_generic.obj_id);
				pObject->cre_areaminimaps = (void**)realloc(pObject->cre_areaminimaps, pModule->mod_areas_len *4);
				void *pMinimap = new char[0x80];
				memset(pMinimap, 0, 0x80);
				pObject->cre_areaminimaps[pModule->mod_areas_len-1] = pMinimap;
				CExoArrayList_uint32_add((CExoArrayList_uint32*)&pObject->cre_arealist, nAreaID);
				_log(3, "o Creature area count: %d\n", pObject->cre_areacount);

			}
		}
	}
	return 1;
}

int CNWNXAreas::RemoveAreaForCreatures(CNWSModule *pModule, nwn_objid_t nAreaID) {
	CGameObjectArray *pGameObjArray = ((*NWN_AppManager)->app_server)->GetObjectArray();

	_log(3, "o Module Area Count: %d\n", pModule->mod_areas_len);
	if (!pGameObjArray) return 0;
	for (int i=0; i<=0xFFF; i++) {
		CGameObjectArrayElement **pObjects = pGameObjArray->Objects;
		CGameObjectArrayElement  *pElement = pObjects[i];
		if (!pElement) continue;
		CNWSCreature *pObject = (CNWSCreature*)pElement->Object;
		if (!pObject) continue;
		if (pObject->obj.obj_generic.obj_type2 == 5) {
			if (pObject->cre_areaminimaps) {
			
				//TODO: cleanup minimap data
				/*
				_log(3, "Removing minimaps for creature '%08X'\n", pObject->Object.ObjectID);
				*/
				
				pObject->cre_areaminimaps = (void**)realloc(pObject->cre_areaminimaps, pModule->mod_areas_len *4);
				CExoArrayList_uint32___Remove(&pObject->cre_arealist, NULL, nAreaID);
				_log(3, "Object area count: %d\n", pObject->cre_areacount);
			}
		}
	}
	return 1;
}

int CNWNXAreas::SetAreaName(CNWSArea *pArea, char *sNewName) {
	_log(3, "o SetAreaName: %08X, '%s'\n", pArea->are_id, sNewName);
	CExoLocString *lsName = (CExoLocString *)&pArea->area_name;
	if (!lsName) return 0;
	char *newstr = new char[strlen(sNewName)+1];
	memcpy(newstr, sNewName, strlen(sNewName));
	newstr[strlen(sNewName)] = 0;
	lsName->AddString(0, newstr);
	UpdateAreasForDMs();
	return 1;
}

CNWSArea *CNWNXAreas::GetOverrideArea(CNWSCreature *Cre) {
	CNWSArea *Area = NULL;
	_log(3, "Cre: %08X\n", Cre);
	if (Cre) {
		CNWSScriptVarTable *svTable = &Cre->obj.obj_vartable;
		CScriptLocation Loc;
		Loc.loc_area = OBJECT_INVALID;
		Loc.loc_orientation.x = 0.0; Loc.loc_orientation.y = 0.0; Loc.loc_orientation.y = 0.0;
		Loc.loc_orientation.x = 0.0; Loc.loc_orientation.y = 0.0; Loc.loc_orientation.z = 0.0;

		CExoString VarName(LocationFailSafe);
		if (svTable) {
			Loc = svTable->GetLocation(VarName);
			Area = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(Loc.loc_area);
			_log(3, "o Creature LocationFailSafe AreaID: %08X\n", Loc.loc_area);
			if (!Area) {
				char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
				CNWSModule *Mod= (CNWSModule*)(mod+0x1C);
				svTable = &Mod->mod_vartable;

				if (svTable) {
					Loc = svTable->GetLocation(VarName);
					_log(3, "o Module LocationFailSafe AreaID: %08X\n", Loc.loc_area);
					Area = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(Loc.loc_area);
				}
			}
		}
	}
	return Area;
}

int CNWNXAreas::CheckArea(CNWSPlayerTURD *TURD) {
	CNWSArea *Area = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(TURD->TURD_AreaId);
	if (Area == NULL) {
		_log(1, "o Area not valid for returning Player: Get Override Location\n");
		// the creatures varlist is copied when the TURD is created so we can just use it to find a failsafe location
		CNWSScriptVarTable *svTable = &TURD->TURD_ScriptvarTable;
		CExoString VarName("OVERRIDETURDAREA");
		CScriptLocation Loc;
		Loc.loc_area = OBJECT_INVALID;
		Loc.loc_orientation.x = 0.0; Loc.loc_orientation.y = 0.0; Loc.loc_orientation.y = 0.0;
		Loc.loc_orientation.x = 0.0; Loc.loc_orientation.y = 0.0; Loc.loc_orientation.z = 0.0;
		if (svTable) {

			if (Loc.loc_area = OBJECT_INVALID || !((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(Loc.loc_area)) {
				char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
				CNWSModule *Mod= (CNWSModule*)(mod+0x1C);
				svTable = &Mod->mod_vartable;

				if (svTable) {
					Loc = svTable->GetLocation(VarName);
					_log(3, "o Module LocalLocation AreaID: %08X\n", Loc.loc_area);
				}
			}
		}
		// let's see what happens with area = OBJECT_INVALID if we still don't have a good location
		TURD->TURD_AreaId = Loc.loc_area;
		TURD->TURD_PositionX = Loc.loc_position.x;
		TURD->TURD_PositionY = Loc.loc_position.y;
		TURD->TURD_PositionZ = Loc.loc_position.z;
		TURD->TURD_OrientatX = Loc.loc_orientation.x;
		TURD->TURD_OrientatY = Loc.loc_orientation.y;
		TURD->TURD_OrientatZ = Loc.loc_orientation.z;

		return 1;
	}

	return 0;
}