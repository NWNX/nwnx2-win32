#include "StdAfx.h"
#include "types.h"
#include "CAutoMap.h"

CMiniMapData **CCreatureMaps::ResizeMapList(int NewSize) {
	CMiniMapData **p = new CMiniMapData*[NewSize];
	for (unsigned int i=0; i<this->MiniMapCount; i++) {
		p[i] = this->MiniMap[i];
	}
	delete[] this->MiniMap;

	return p;
}

nwn_objid_t *CCreatureMaps::CopyAreas(int NewSize) {
	nwn_objid_t *p = new nwn_objid_t[NewSize];
	memcpy(p, this->Areas, this->AreaCount * 4);
	delete[] this->Areas;
	return p;
}

CMiniMapData **CCreatureMaps::Copy(CMiniMapData** CopyFrom, int nSize) {
	CMiniMapData **p = new CMiniMapData*[nSize];
	CMiniMapData *d = NULL;
	for (unsigned int i=0; i<nSize; i++) {
		d = new CMiniMapData;
		memcpy(d, CopyFrom[i], 0x80);
		p[i] = d;
	}
	return p;
}

void CCreatureMaps::DeleteMiniMaps() {
	if (MiniMap) {
		if (MiniMapCount > 0) {
			for (int i=0; i<MiniMapCount; i++) {
				delete[] MiniMap[i];
				MiniMap[i] = NULL;
			}
			delete[] MiniMap;
			MiniMap = NULL;
		}
	}
	MiniMapCount = 0;
}

void CCreatureMaps::DeleteAreas() {
	if (Areas) {
		delete[] Areas;
		Areas = NULL;
	}
	AreaAlloc = 0;
	AreaCount = 0;
}

void CCreatureMaps::AddArea(unsigned areaid) {
	MiniMap = ResizeMapList(MiniMapCount+1);

	MiniMap[MiniMapCount] = new CMiniMapData;
	++MiniMapCount;

	CExoArrayList_uint32_add((CExoArrayList_uint32*)&Areas, areaid);
}


void CCreatureMaps::RemoveArea(unsigned areaid) {
	int iIndex = CExoArrayList_uint32_contains((CExoArrayList_uint32*)&Areas, areaid);
	if (iIndex != -1) {

		CMiniMapData **Map = (CMiniMapData**)new unsigned[MiniMapCount-1];
		int j=0;
		for (int i=0; i<MiniMapCount; i++) {
			if (i != iIndex) {
				Map[j++] = MiniMap[i];
			}
			else {
				delete MiniMap[i];
			}
		}
		delete[] MiniMap;
		MiniMap = Map;
		--MiniMapCount;

		CExoArrayList_uint32___Remove(&Areas, NULL, areaid);
	}
}

CMiniMapData **CTURDMaps::Copy(CMiniMapData** CopyFrom, int nSize) {
	CMiniMapData **p = new CMiniMapData*[nSize];
	CMiniMapData *d = NULL;
	for (unsigned int i=0; i<nSize; i++) {
		d = new CMiniMapData;
		memcpy(d, CopyFrom[i], 0x80);
		p[i] = d;
	}
	return p;
}

CMiniMapData **CTURDMaps::ResizeMapList(int NewSize) {
	CMiniMapData **p = new CMiniMapData*[NewSize];
	for (unsigned int i=0; i<this->AreaCount; i++) {
		p[i] = this->MiniMap[i];
	}
	delete[] this->MiniMap;

	return p;
}

nwn_objid_t *CTURDMaps::CopyAreas(int NewSize) {
	nwn_objid_t *p = new nwn_objid_t[NewSize];
	memcpy(p, this->Areas, this->AreaCount * 4);
	delete[] this->Areas;
	return p;
}


void CTURDMaps::AddArea(unsigned areaid) {
	MiniMap = ResizeMapList(AreaCount+1);
	MiniMap[AreaCount] = new CMiniMapData;

	Areas = CopyAreas(AreaCount+1);
	Areas[AreaCount] = areaid;

	++AreaCount;
}

void CTURDMaps::RemoveArea(unsigned areaid) {
	int iIndex = CExoArrayList_uint32_contains((CExoArrayList_uint32*)&Areas, areaid);
	if (iIndex != -1) {

		CMiniMapData **Map = (CMiniMapData**)new unsigned[AreaCount-1];
		int j=0;
		for (int i=0; i<AreaCount; i++) {
			if (i != iIndex) {
				Map[j++] = MiniMap[i];
			}
			else {
				delete MiniMap[i];
			}
		}
		delete[] MiniMap;
		MiniMap = Map;

		nwn_objid_t *areas = new nwn_objid_t[AreaCount-1];
		j=0;
		for (int i=0; i<AreaCount; i++) {
			if (i != iIndex) {
				areas[j++] = Areas[i];
			}
		}
		delete[] Areas;
		Areas = areas;
	}
}