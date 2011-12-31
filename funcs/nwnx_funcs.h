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

#define PLAYER_ID_ALL_PLAYERS						0xFFFFFFF7

#define FUNCTION_COUNT 137

class CNWNXFuncs : public CNWNXBase {
public: // main plugin functions
	CNWNXFuncs();
	virtual ~CNWNXFuncs();
	
	char *OnRequest(char *gameObject, char *Request, char *Parameters);
	BOOL OnCreate(const char *LogDir);
	BOOL OnRelease();

private:

	unsigned long OnRequestObject (char *gameObject, char *Request);
	void WriteLogHeader(int debugLevel);

	CHookFunctions *FunctionHooks;
	unsigned long gameID;

private: //Script Function classes
	friend class CHookFunctions;

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

public:
	//ini file values
	bool bHookCreateGeometry;
	bool bOverrideMaximumDexMod;
	bool bHookRemovePCFromWorld;
	char OnPlayerLeavingScript[17];

	uint8_t nSkill;

};

#endif;