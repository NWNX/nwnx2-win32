#include "stdafx.h"
#include "nwnx_areas.h"
#include "madchook.h"
#include <string>

extern CNWNXAreas NWNXAreas;

#define _log(a,b,...) if(a<=NWNXAreas.debugLevel)NWNXAreas.LOG(b,__VA_ARGS__)

void (*nwn_CExoResMan__ExistsNextHook)();
void (*nwn_OverridePlayerTURDAreaNextHook)();
void (*nwn_OverrideSetPlayerAreaFromTURDNextHook)();

char *git;
int iType;
std::string resPath;
FILE *GIT = NULL;
void __declspec(naked)CExoResMan__ExistsHookProc() {
	__asm {
		pushad	
		mov eax, [esp+0x24]
		mov git, eax
		mov eax, [esp+0x28]
		mov iType, eax;
	}

	if (iType != 2023) {
		__asm {
			popad
			jmp nwn_CExoResMan__ExistsNextHook
		}
	}
	else {
		//_log(3, "o GIT request\n");
		resPath = NWNXAreas.m_sourcePath;
		resPath += "are\\";
		resPath += git;
		resPath += ".git";
		GIT = fopen(resPath.c_str(), "rb");
		if (GIT == NULL) {
			_log(3, "o File not found\n");
			__asm {
				popad
				jmp nwn_CExoResMan__ExistsNextHook
			}
		}
		else {
			//_log(2, "o external git found: %s\n", resPath.c_str());
			fclose(GIT); // just needed to know it was there
			__asm {
				popad
				mov eax, 1
				retn 0x0C;
			}
		}
	}
}

uint32_t *pTHIS = NULL;
CNWSArea *OverrideArea = NULL;
void __declspec(naked)OverridePlayerTURDAreaHookProc() {
	__asm {
		mov ecx, esi //this
		pushad
		mov pTHIS, ecx
	}
	
	OverrideArea = NWNXAreas.GetOverrideArea((CNWSCreature*)pTHIS);

	if (!OverrideArea) {
		_asm {
			popad
			jmp nwn_OverridePlayerTURDAreaNextHook // no override area, let the function do it's thing
		}
	}
	else {
		__asm {
			popad
			mov eax, OverrideArea
			mov ebx, 0x0042F5EB
			jmp ebx 
		}
	}
}

CNWSPlayerTURD *TURD;
CNWSCreature *Cre;
uint32_t AreaID=OBJECT_INVALID;
float P_X, P_Y, P_Z, O_X, O_Y, O_Z;
void __declspec(naked)OverrideSetPlayerAreaFromTURDHookProc() {
	__asm {
		mov eax, edi //get turd

		pushad
		mov TURD, eax
	}

	_log(3, "TURD OVERRIDE");

	if (NWNXAreas.CheckArea(TURD)) {
		AreaID = TURD->TURD_AreaId;
		P_X = TURD->TURD_PositionX;
		P_Y = TURD->TURD_PositionY;
		P_Z = TURD->TURD_PositionZ;
		O_X = TURD->TURD_OrientatX;
		O_Y = TURD->TURD_OrientatY;
		O_Z = TURD->TURD_OrientatZ;

		__asm {
			popad
			mov eax, AreaID
			mov [edi+0x74], eax
			mov eax, P_X
			mov [edi+0x78], eax
			mov eax, P_Y
			mov [edi+0x7C], eax
			mov eax, P_Z 
			mov [edi+0x80], eax
			mov eax, O_X
			mov [edi+0x84], eax
			mov eax, O_Y
			mov [edi+0x88], eax
			mov eax, O_Z
			mov [edi+0x90], eax

			jmp nwn_OverrideSetPlayerAreaFromTURDNextHook

		}
	}
	else {
		__asm {
			popad
			jmp nwn_OverrideSetPlayerAreaFromTURDNextHook
		}
	}
}

CNWSCreature* (__fastcall *CNWSCreature__CNWSCreatureNEXT)(CNWSCreature *pTHIS, void *pVOID, int a2, unsigned int a3, unsigned int a4);
CNWSCreature* __fastcall CNWSCreature__CNWSCreatureHOOK(CNWSCreature *pTHIS, void *pVOID, int a2, unsigned int a3, unsigned int a4) {
	CNWSCreature *cre = CNWSCreature__CNWSCreatureNEXT(pTHIS, NULL, a2, a3, a4);
	// There's probably an internal list that keeps track of creatures, but we'll do it this way
	NWNXAreas.AddToCreatureList(cre->obj.obj_generic.obj_id);
	return cre;
}

void (__fastcall *CNWSCreature___CNWSCreatureNEXT)(CNWSCreature *pTHIS);
void __fastcall CNWSCreature___CNWSCreatureHOOK(CNWSCreature *pTHIS) {
	NWNXAreas.RemoveFromCreatureList(pTHIS->obj.obj_generic.obj_id);
	CNWSCreature___CNWSCreatureNEXT(pTHIS);
}

void (__fastcall *CNWSModule__AddToTURDListNEXT)(CNWSModule *pTHIS, void *pVOID, CNWSPlayerTURD *TURD);
void __fastcall CNWSModule__AddToTURDListHOOK(CNWSModule *pTHIS, void *pVOID, CNWSPlayerTURD *TURD) {
	_log(3, "%08X\n%08X\n", pTHIS, TURD);
	CNWSModule__AddToTURDListNEXT(pTHIS, NULL, TURD);
}

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

void HookFunctions() {
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

/*
	DWORD CNWSCreature__CNWSCreatureORG = 0x0048F5B0;
	if (HookCode((PVOID) CNWSCreature__CNWSCreatureORG, CNWSCreature__CNWSCreatureHOOK, (PVOID*)&CNWSCreature__CNWSCreatureNEXT))
		_log(0, "* CNWSCreature__CNWSCreature hooked\n");
	else 
		_log(0, "x CNWSCreature__CNWSCreature hook failed\n");

	DWORD CNWSCreature___CNWSCreatureORG = 0x00490000;
	if (HookCode((PVOID) CNWSCreature___CNWSCreatureORG, CNWSCreature___CNWSCreatureHOOK, (PVOID*)&CNWSCreature___CNWSCreatureNEXT))
		_log(0, "* CNWSCreature___CNWSCreature hooked\n");
	else 
		_log(0, "x CNWSCreature___CNWSCreature hook failed\n");
*/
	//DWORD org_OverridePlayerTURDArea=0x0042F5D9;

	//DWORD org_OverrideSetPlayerAreaFromTURD=0x0042F830;

	DWORD org_CExoResMan__Exists=0x00416BE0;
	if (strlen(NWNXAreas.m_sourcePath) > 0) {
		if (HookCode((PVOID) org_CExoResMan__Exists, CExoResMan__ExistsHookProc, (PVOID*)&nwn_CExoResMan__ExistsNextHook)) _log(0, "* CExoResMan__Exists hooked; SourcePath: '%s'\n", NWNXAreas.m_sourcePath);
	}

	// catch and change the area on logout
	//if (HookCode((PVOID) org_OverridePlayerTURDArea, OverridePlayerTURDAreaHookProc, (PVOID*)&nwn_OverridePlayerTURDAreaNextHook)) _log(0, "* nwn_OverridePlayerTURDArea hooked\n");
	
	// catch and change the area on login
	// this crashes the server when the player logs back in: CNWSModule::LoadTURDLIST: virtual GetFirstName
//	if (HookCode((PVOID) org_OverrideSetPlayerAreaFromTURD, OverrideSetPlayerAreaFromTURDHookProc, (PVOID*)&nwn_OverrideSetPlayerAreaFromTURDNextHook)) _log(0, "* OverrideSetPlayerAreaFromTURD hooked\n");
}