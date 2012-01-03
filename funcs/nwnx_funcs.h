#if !defined(NWNXFUNCS_H_)
#define NWNXFUNCS_H_

#include "..\NWNXDLL\NWNXBase.h"
#include "types.h"
#include "HookFunc.h"
#include <vector>
#include <list>
#include <string>
#include <hash_map>
#include "CVisibility.h"
#include "CNssLocalVariables.h"
#include "CNssAreas.h"
#include "CNssUtility.h"
#include "CNssItems.h"
#include "CNssEffects.h"
#include "CNssCreatureStats.h"
#include "CNssCustomTrigger.h"
#include "CNssCreature.h"
#include "CNssFeats.h"
#include "CNssSpells.h"
#include "CNssObject.h"
#include "CNssLock.h"
#include "CNssPlayer.h"
#include "CNssServer.h"
#include "CNssTransition.h"
#include "CNssItemProperty.h"
#include "CNssModule.h"


class CNWNXFuncs : public CNWNXBase {
public:
	CNWNXFuncs();
	virtual ~CNWNXFuncs();
	

private:
//nwnx base members
	BOOL OnCreate(const char *LogDir);
	BOOL OnRelease();
	char *OnRequest(char *gameObject, char *Request, char *Parameters);
	unsigned long OnRequestObject (char *gameObject, char *Request);
	void WriteLogHeader(int debugLevel);

	unsigned long gameID;


//function hooks
	CHookFunctions *FunctionHooks;
	friend class CHookFunctions;

//Script Function classes

	CFuncLookup *MainLookup; //main function lookup and execution. This is never actually instantiated but pointed at any of its derived classes
	CNssLocalVariables *NssLocalVariables;
	CNssAreas *NssAreas;
	CNssUtility *NssUtility;
	CNssItems *NssItems;
	CNssEffects *NssEffects;
	CNssCreatureStats *NssCreatureStats;
	CVisibility *Visibility;
	CNssCustomTrigger *NssCustomTrigger;
	CNssCreature *NssCreature;
	CNssFeats *NssFeats;
	CNssSpells *NssSpells;
	CNssObject *NssObject;
	CNssLock *NssLock;
	CNssPlayer *NssPlayer;
	CNssServer *NssServer;
	CNssTransition *NssTransition;
	CNssItemProperty *NssItemProperty;
	CNssModule *NssModule;

//ini file values
	bool bHookCreateGeometry;
	bool bOverrideMaximumDexMod;
	bool bHookRemovePCFromWorld;
	char OnPlayerLeavingScript[18];
	bool bHookTimeOfDayChange;
	char OnTimeOfDayChangeScript[18];
	uint8_t nSkill;

};

#endif;