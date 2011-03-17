#include "stdafx.h"
#include "nwnx_areas.h"
#include "madchook.h"
#include <string>
#include <malloc.h>
#include "HookFunc.h"

int CHookFunctions::debugLevel = 0;
char *CHookFunctions::m_sourcePath = NULL;

#define _log(a,b,...) if(a<=debugLevel)_LOG(b,__VA_ARGS__)


int __fastcall CHookFunctions::CExoResMan__ExistsHOOK(CExoResMan *pTHIS, void *pVOID, CResRef const &ResRef, unsigned short Type, unsigned long *a3) {
	if (Type != 2023) return CExoResMan__ExistsNEXT(pTHIS, NULL, ResRef, Type, a3);
	
	char ref[17];
	memcpy(ref, &ResRef, 16); ref[16] = 0;
	std::string resPath = m_sourcePath;
	resPath += "are\\";
	resPath += ref;
	resPath += ".git";
	FILE *GIT = fopen(resPath.c_str(), "rb");
	if (GIT == NULL) {
		_log(3, "o External area (%s) file not found\n", ref);
		return CExoResMan__ExistsNEXT(pTHIS, NULL, ResRef, Type, a3);
	}
	else {
		//_log(2, "o external git found: %s\n", resPath.c_str());
		fclose(GIT); // just needed to know it was there
		return 1;
	}
}

#ifdef _DEBUG
void *(__fastcall *CNWSCreature__SetAutoMapDataNEXT)(CNWSCreature *pTHIS, void *pVOID, int AreaCount, nwn_objid_t *AreaList, CMiniMapData **MiniMapData);
void *__fastcall CNWSCreature__SetAutoMapDataHOOK(CNWSCreature *pTHIS, void *pVOID, int AreaCount, nwn_objid_t *AreaList, CMiniMapData **MiniMapData) {
	_log(3, "CNWSCreature__SetAutoMapData\n");
	//_log(3, "%08X\n", AreaList);
	//return CNWSCreature__SetAutoMapDataNEXT(pTHIS, NULL, AreaCount, AreaList, MiniMapData);
	
	CCreatureMaps *AreaData = &pTHIS->AreaData;
	//delete minimaps and minimap array
	
	AreaData->DeleteMiniMaps();
	AreaData->DeleteAreas();	

	if (AreaCount > 0) {
		AreaData->MiniMap = AreaData->Copy(MiniMapData, AreaCount);

		AreaData->Areas = new nwn_objid_t[AreaCount];
		memcpy(AreaData->Areas, AreaList, 4*AreaCount);

		AreaData->MiniMapCount = AreaCount;
		AreaData->AreaAlloc = AreaCount;
		AreaData->AreaCount = AreaCount;
	}
	return (void*)AreaCount;
}

int (__fastcall *CNWSCreature__LoadAutoMapDataNEXT)(CNWSCreature *pTHIS, void *pVOID, CResGFF *pGFF, CResStruct *Res);
int __fastcall CNWSCreature__LoadAutoMapDataHOOK(CNWSCreature *pTHIS, void *pVOID, CResGFF *pGFF, CResStruct *Res) {
	_log(3, "CNWSCreature__LoadAutoMapData\n");
	if (pTHIS->AreaData.MiniMap) {
		if (pTHIS->AreaData.MiniMapCount > 0) {
			for (int i=0; i<pTHIS->AreaData.MiniMapCount; i++) {
				delete pTHIS->AreaData.MiniMap[i];
				pTHIS->AreaData.MiniMap[i] = NULL;
			}
			delete[] pTHIS->AreaData.MiniMap;
			pTHIS->AreaData.MiniMap = NULL;
		}
	}
	pTHIS->AreaData.MiniMapCount = 0;

	if (pTHIS->AreaData.Areas) {
		delete[] pTHIS->AreaData.Areas;
		pTHIS->AreaData.Areas = NULL;
		pTHIS->AreaData.AreaAlloc = 0;
	}
	pTHIS->AreaData.AreaCount = 0;

	int v12 = 0;
	void *v16 = NULL;
	int ListCount = 0;

	int iNumAreas = pGFF->ReadFieldINT(Res, "Mod_MapNumAreas", v12, 0);
	if (pGFF->GetList(v16, Res, "Mod_MapDataList") == 1) {
		ListCount = pGFF->GetListCount(v16);
		if (!ListCount) return 0;

		pTHIS->AreaData.MiniMap = (CMiniMapData**)new unsigned[ListCount];
		int nElement = 0;
		while (nElement < ListCount) {
			pGFF->GetListElement(Res, v16, nElement);
			CMiniMapData *p = new CMiniMapData;
			pGFF->ReadFieldVOID(Res, p, 0x80, "Mod_MapData", v12, NULL);
			pTHIS->AreaData.MiniMap[nElement] = p;
			++nElement;
		}
		pTHIS->AreaData.MiniMapCount = ListCount;
	}

	if (ListCount > 0) {
		pTHIS->AreaData.Areas = new nwn_objid_t[ListCount];
		pGFF->ReadFieldVOID(Res, pTHIS->AreaData.Areas, 4*ListCount, "Mod_MapAreasData", v12, 0);
		pTHIS->AreaData.AreaCount = ListCount;
		pTHIS->AreaData.AreaAlloc = ListCount;
	}

	if (pTHIS->AreaData.Areas) {
		delete[] pTHIS->AreaData.Areas;
		pTHIS->AreaData.Areas = NULL;
		pTHIS->AreaData.AreaAlloc = 0;
	}

	return ListCount;
}

unsigned long (__fastcall *CNWSPlayer__LoadCreatureDataNEXT)(CNWSPlayer *pTHIS, void *pVOID, CResRef ResRef, CNWSCreature *Cre);
unsigned long __fastcall CNWSPlayer__LoadCreatureDataHOOK(CNWSPlayer *pTHIS, void *pVOID, CResRef ResRef, CNWSCreature *Cre) {
	_log(3, "CNWSPlayer__LoadCreatureDataNEXT\n");

	char *pMod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	CNWSModule *pModule = (CNWSModule*)(pMod+0x1C);

	int nAreaCount = pModule->mod_areas_len;

	Cre->AreaData.MiniMap = (CMiniMapData**)new unsigned[nAreaCount];
	Cre->AreaData.Areas = new nwn_objid_t[nAreaCount];
	CMiniMapData *p = NULL;
	for (int i=0; i<nAreaCount; i++) {
		p = new CMiniMapData;
		Cre->AreaData.MiniMap[i] = p;
		Cre->AreaData.Areas[i] = pModule->mod_areas[i];
	}

	Cre->AreaData.AreaAlloc = nAreaCount;
	Cre->AreaData.AreaCount = nAreaCount;
	Cre->AreaData.MiniMapCount = nAreaCount;

	return CNWSPlayer__LoadCreatureDataNEXT(pTHIS, NULL, ResRef, Cre);
}

void **(__fastcall *CNWSPlayerTURD__CopyAutomapDataNEXT)(CNWSPlayerTURD *pTHIS, void *pVOID, int AreaCount, nwn_objid_t **Areas, CMiniMapData **MiniMap);
void ** __fastcall CNWSPlayerTURD__CopyAutomapDataHOOK(CNWSPlayerTURD *pTHIS, void *pVOID, int AreaCount, nwn_objid_t **Areas, CMiniMapData **MiniMap) {
	_log(3, "CNWSPlayerTURD__CopyAutomapData\n");

	if (pTHIS->AreaData.MiniMap) {
		for (int i=0; i< pTHIS->AreaData.AreaCount; i++) {
			delete[] pTHIS->AreaData.MiniMap[i];
			pTHIS->AreaData.MiniMap[i] = NULL;
		}
		delete[] pTHIS->AreaData.MiniMap;
		pTHIS->AreaData.MiniMap = NULL;
	}
	if (pTHIS->AreaData.Areas) {
		delete[] pTHIS->AreaData.Areas;
		pTHIS->AreaData.Areas = NULL;
	}
	pTHIS->AreaData.AreaCount = 0;

	pTHIS->AreaData.MiniMap = pTHIS->AreaData.Copy(MiniMap, AreaCount);

	pTHIS->AreaData.Areas = new nwn_objid_t[AreaCount];
	memcpy(pTHIS->AreaData.Areas, *Areas, AreaCount*4);

	pTHIS->AreaData.AreaCount = AreaCount;

	return (void**)AreaCount;
}

void* (*operator_newNEXT)(unsigned int a1);
void *__cdecl operator_newHOOK(unsigned int a1) {
	return malloc(a1);
}

void (*operator_deleteNEXT)(unsigned int a1);
void __cdecl operator_deleteHOOK(void *a1) {
	free(a1);
}
#endif

void CHookFunctions::HookFunctions() {

	if (strlen(m_sourcePath) > 0 && HookCode((PVOID) CExoResMan__ExistsORG, CExoResMan__ExistsHOOK, (PVOID*)&CExoResMan__ExistsNEXT)) {
		_log(0, "* CExoResMan__Exists hooked; SourcePath: '%s'\n", m_sourcePath);
	}
	else _log(0, "x CExoResMan_Exists hook failed\n");

#ifdef _DEBUG
// we only need this for debug compiling/linking since in that mode memory allocation/deallocation adds all kinds of
// additional data which can overwrite actual data from the server process
	if (1) {
		DWORD operator_newORG = 0x00601C2C;
		if (HookCode((PVOID) operator_newORG, operator_newHOOK, (PVOID*)&operator_newNEXT))	_log(0, "* nwn_operator_new hooked\n");
		else _log(0, "x nwn_operator_new hook failed\n");

		DWORD operator_deleteORG = 0x00601C21;
		if (HookCode((PVOID) operator_deleteORG, operator_deleteHOOK, (PVOID*)&operator_deleteNEXT))	_log(0, "* nwn_operator_new hooked\n");
		else _log(0, "x nwn_operator_new hook failed\n");
	}

	if (1) { //OnClientLeave: Copys the area data from the player object to the player TURD
		DWORD CNWSPlayerTURD__CopyAutomapDataORG = 0x004DD210;
		if (HookCode((PVOID) CNWSPlayerTURD__CopyAutomapDataORG, CNWSPlayerTURD__CopyAutomapDataHOOK, (PVOID*)&CNWSPlayerTURD__CopyAutomapDataNEXT))
			_log(0, "* CNWSPlayerTURD__CopyAutomapData hooked\n");
		else 
			_log(0, "x CNWSPlayerTURD__CopyAutomapData hook failed\n");
	}

	if (1) { //OnClientLeave: Copys the area data from the player object to the player TURD
		DWORD CNWSPlayerTURD__CopyAutomapDataORG = 0x004DD210;
		if (HookCode((PVOID) CNWSPlayerTURD__CopyAutomapDataORG, CNWSPlayerTURD__CopyAutomapDataHOOK, (PVOID*)&CNWSPlayerTURD__CopyAutomapDataNEXT))
			_log(0, "* CNWSPlayerTURD__CopyAutomapData hooked\n");
		else 
			_log(0, "x CNWSPlayerTURD__CopyAutomapData hook failed\n");
	}

	if (1) { //Creates the initial AreaData for a player creature
		DWORD CNWSPlayer__LoadCreatureDataORG = 0x00431040;
		if (HookCode((PVOID) CNWSPlayer__LoadCreatureDataORG, CNWSPlayer__LoadCreatureDataHOOK, (PVOID*)&CNWSPlayer__LoadCreatureDataNEXT))
			_log(0, "* CNWSPlayer__LoadCreatureData hooked\n");
		else 
			_log(0, "x CNWSPlayer__LoadCreatureData hook failed\n");
	}

	if (1) {// OnClientEnter: Copys AreaData from an existing TURD back to the player creature
		DWORD CNWSCreature__SetAutoMapDataORG = 0x004B1DD0;
		if (HookCode((PVOID) CNWSCreature__SetAutoMapDataORG, CNWSCreature__SetAutoMapDataHOOK, (PVOID*)&CNWSCreature__SetAutoMapDataNEXT))
			_log(0, "* CNWSCreature__SetAutoMapData hooked\n");
		else
			_log(0, "x CNWSCreature__SetAutoMapData hook failed\n");
	}
#endif
}