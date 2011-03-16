#pragma once

#include <string.h>

class CMiniMapData {
	char MAP[0x80];
public:
	CMiniMapData() {memset(MAP, 0, 0x80);}
};

class CCreatureMaps {
public:
	CMiniMapData **MiniMap;
	nwn_objid_t *Areas;
	uint32_t AreaCount;
	uint32_t AreaAlloc;
	uint32_t MiniMapCount;

	void AddArea(unsigned areid);
	void RemoveArea(unsigned areaid);
	CMiniMapData **ResizeMapList(int NewSize);
	CMiniMapData **Copy(CMiniMapData** CopyFrom, int nSize);
	void DeleteMiniMaps();
	void DeleteAreas();
	nwn_objid_t *CopyAreas(int NewSize);
};

class CTURDMaps {
public:
	uint32_t AreaCount;
	nwn_objid_t *Areas;
	CMiniMapData **MiniMap;

	void AddArea(unsigned areid);
	void RemoveArea(unsigned areaid);
	CMiniMapData **ResizeMapList(int NewSize);
	CMiniMapData **Copy(CMiniMapData** CopyFrom, int nSize);
	nwn_objid_t *CopyAreas(int NewSize);
};