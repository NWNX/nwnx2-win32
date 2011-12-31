#include "stdafx.h"
#include "nwnx_funcs.h"
#include "../NWNXdll/IniFile.h"
#include <time.h>

#include <stdlib.h>
#include <string.h>

CNWNXFuncs::CNWNXFuncs() {
//	getFirstNextEffect = NULL;
}

CNWNXFuncs::~CNWNXFuncs() {
	delete FunctionHooks;
	OnRelease();
}

char* CNWNXFuncs::OnRequest(char *gameObject, char* Request, char* Parameters) {
	_log(1, "- StrReq: \"%s\"           Params: \"%s\"\n", Request, Parameters);

	if (gameObject == NULL) {
		_log(1, "o Error: Invalid Object passed to nwnx_funcs.\n");
		sprintf(Parameters, "");
		return NULL;
	}

	if (strcmp(Request, "TEST") == 0) {
	}

	else if (MainLookup->Execute(Request, (CGameObject*)gameObject, Parameters)) {
	}

	else {sprintf(Parameters, "-1"); _log(1, "o Could not find requested function.\n");}

	return NULL;
}

unsigned long CNWNXFuncs::OnRequestObject (char *gameObject, char* Request){
	_log(1, "- ObjReq: %08X             Request: %s\n", gameObject, Request);
	uint32_t ret = OBJECT_INVALID;

	std::string sRequest = Request;
	std::string TrueRequest = Request, Param;
	char *NewParams = NULL;
	int i=0;

	if ((i = sRequest.find("¬")) != std::string::npos) {
		TrueRequest = sRequest.substr(0, i++);
		Param = sRequest.substr(i, sRequest.size()-i);
	}

	int l = Param.length();
	if (l < 20) l = 20;
	NewParams = new char[l+1];
	strcpy(NewParams, Param.c_str());

	if(MainLookup->Execute(TrueRequest, (CGameObject*)gameObject, NewParams)) {
		sscanf(NewParams, "%08X", &ret);
	}

	return ret;
}

BOOL CNWNXFuncs::OnCreate(const char* LogDir) {
	// call the base class function
	char __log[MAX_PATH];
	sprintf (__log, "%s\\nwnx_funcs.txt", LogDir);
	if (!CNWNXBase::OnCreate(__log))
		return false;

	CIniFile iniFile ("nwnx.ini");
	int debugLevel = iniFile.ReadInteger("FUNCS", "DebugLevel", 0);
	LogFile::SetDebugLevel(debugLevel);

	nSkill = iniFile.ReadInteger("FUNCS", "Number_of_Skills", 28);
	bHookCreateGeometry = iniFile.ReadInteger("FUNCS", "HOOK_CustomTrapGeometry", 0);
	bOverrideMaximumDexMod = iniFile.ReadInteger("FUNCS", "HOOK_OverrideMaximumDexMod", 0);

	if ((bHookRemovePCFromWorld = iniFile.ReadInteger("FUNCS", "HOOK_OnPlayerLeaving", 0))) {
		iniFile.ReadString("FUNCS", "OnPlayerLeavingScript", OnPlayerLeavingScript, 16, "onplayerleaving");
	}

	WriteLogHeader(debugLevel);

	FunctionHooks = new CHookFunctions();

	NssLocalVariables = new CNssLocalVariables;
	NssAreas = new CNssAreas;
	NssUtility = new CNssUtility;
	NssItems = new CNssItems;
	NssEffects = new CNssEffects;
	NssCreatureStats = new CNssCreatureStats(nSkill);
	Visibility = new CVisibility;
	NssCustomTrigger = new CNssCustomTrigger;
	NssCreature = new CNssCreature;
	NssFeats = new CNssFeats;
	NssSpells = new CNssSpells;
	NssObject = new CNssObject;
	NssLock = new CNssLock;
	NssPlayer = new CNssPlayer;
	NssServer = new CNssServer;
	NssTransition = new CNssTransition;
	NssItemProperty = new CNssItemProperty;
	
	MainLookup = NssLocalVariables;
	
	return true;
}

BOOL CNWNXFuncs::OnRelease() {
	_log(0, "o Shutting down\n");

	// call base class function
	return CNWNXBase::OnRelease();
}

void CNWNXFuncs::WriteLogHeader(int debugLevel) {
	_log(0, "Windows NWNX Funcs plugin v.0.0.9.1\n");
	_log(0, "log level: %i\n", debugLevel);
}