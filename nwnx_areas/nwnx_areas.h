#pragma once
#include "..\NWNXDLL\NWNXBase.h"
#include "types.h"
#include <vector>
#include "HookFunc.h"


class CNWNXAreas : public CNWNXBase {
public:
	CNWNXAreas();
	virtual ~CNWNXAreas();

	char *OnRequest(char *gameObject, char *Request, char *Parameters);
	unsigned long OnRequestObject (char *gameObject, char *Request);
	BOOL OnCreate(const char *LogDir);
	BOOL OnRelease();

	int debugLevel;
	char m_sourcePath[512];
	char LocationFailSafe[512];

	CNWSArea *GetOverrideArea(CNWSCreature *cre);
	int CheckArea(CNWSPlayerTURD *TURD);

private:
	void WriteLogHeader(int debug);
	void LoadConfiguration();
	int LoadArea(char* ResRef);
	int DestroyArea(nwn_objid_t nAreaID);
	int AddAreaToCreatures(CNWSModule *pModule, nwn_objid_t nAreaID);
	int RemoveAreaForCreatures(CNWSModule *pModule, nwn_objid_t nAreaID);
	int UpdateAreasForDMs();
	int SetAreaName(CNWSArea *pArea, char *sNewName);

	void AddAreaToTURDS(CNWSModule *pModule, nwn_objid_t nAreaID);
	void CleanUpTURDS(CNWSModule *pModule, nwn_objid_t nAreaID);

	nwn_objid_t nLastAreaID;

	CHookFunctions *HookFunctions;
};
