#pragma once
#include "..\NWNXDLL\NWNXBase.h"
#include "types.h"
#include "CTrinityXP.h"
#include <string>
#include <hash_map>
#include <list>


#define FUNCTION_COUNT 4

class CNWNXTrinity : public CNWNXBase {
public:
	CNWNXTrinity();
	virtual ~CNWNXTrinity();

	char *OnRequest(char *gameObject, char *Request, char *Parameters);
	unsigned long OnRequestObject (char *gameObject, char *Request);
	BOOL OnCreate(const char *LogDir);
	BOOL OnRelease();

	int debugLevel;
	char NegXPVar[64];

	int CanLevelUpXP(CNWSCreatureStats *Stats);

private:
	void WriteLogHeader();
	void LoadConfiguration();

	CServerExoAppInternal *ServInternal;
	
	//GetObjectInShapeStuff
	void SetConeCoords(CNWSObject *obj);
	int PointInpoly(int nvert, float *vertx, float *verty, float &testx, float &testy);
	nwn_objid_t GetCreatureInShapeByIndex(CNWSObject *obj);
	
	nwn_objid_t GetAllCreaturesInShape(CNWSObject *obj);
	nwn_objid_t GetCreatureInShape(CNWSObject *obj);

	float fx[5], fy[5];
	int ObjectIndex;
	std::list<uint32_t> oIDsInShape;
	std::list<uint32_t>::iterator oIDsInShape_it;
	CNWSArea *Area;
	//

	void GiveXPToCreature(char *gameObject, char *Parameters);
	void GiveKillXPToParty(char *gameObject, char *Parameters);
	void PLCTakeItem(char *gameObject, char *Parameters);
	void CreatureTakeItem(char *gameObject, char *Parameters);

	stdext::hash_map<std::string, int> FunctionLookup;
	void (__thiscall CNWNXTrinity::*pFunc[FUNCTION_COUNT])(char*, char*);
	void CreateFunctionLookup();

};
