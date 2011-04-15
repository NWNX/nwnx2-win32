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

#define PLAYER_ID_ALL_PLAYERS						0xFFFFFFF7

#define FUNCTION_COUNT 137

class CNWNXFuncs : public CNWNXBase {
public: // main plugin functions
	CNWNXFuncs();
	virtual ~CNWNXFuncs();
	
	char *OnRequest(char *gameObject, char *Request, char *Parameters);
	BOOL OnCreate(const char *LogDir);
	BOOL OnRelease();

	void LOG(const char *pcMsg, ...);

	CNWSObject *CustomEffectObject;
private:

	unsigned long OnRequestObject (char *gameObject, char *Request);
	void WriteLogHeader(int debug);
	void SetParameters();

	int (__thiscall CNWNXFuncs::*pFunc[FUNCTION_COUNT])();
	stdext::hash_map<std::string, int> FunctionLookup;
	void CreateFunctionLookup();

	CHookFunctions *FunctionHooks;
	unsigned long gameID;
	char *Params;
	char *oObject;
	signed long int P1, P2, P3, P4;


private: //internal functions helper/utility declarations
	nwn_objid_t getFirstNextVarObj;
	int getFirstNextVarIndex;

	int getFirstNextAreaIndex;

	// effects stuff
	std::vector<uint64_t>EffectRemovalIDs;
	CGameEffect *getFirstNextEffect;
	nwn_objid_t getFirstNextEffectObj;
	int getFirstNextEffectScriptIndex;
	bool getFirstNextEffectScriptEffect;
	CNWSObject *getFirstNextEffectObject;

	CNWSScriptVarTable *GetVarTable(); //get the scriptvar table for a given object type
	CNWSStats_Level *nwn_GetLevelStats (const CNWSCreatureStats *stats, int level);
	BOOL GetIsCreature();
	BOOL GetIsItem();
	BOOL ValidEffectObject();
	char *GetScriptVarType(int i);

	void nwn_SetWorldTime(uint32_t wtDate, uint32_t wtTime, int P3=0);
	void nwn_UpdateQuickBar(CGenericObject* obj);
	CNWSModule *nwn_GetModule(bool addOffset=true);

	int GetEventScriptInfo(int &ScriptNumber, std::string &ScriptName, int Max);

public:
	//ini file values
	int debugLevel;
	bool bHookCreateGeometry;
	bool bOverrideMaximumDexMod;
	bool bHookRemovePCFromWorld;
	char OnPlayerLeavingScript[17];

	uint8_t nSkill;

public: //scripts functions
	nwn_objid_t StringToObject(const char * soID);

	//***************  Effects  *******************//
	int PrintEffects();

	// Unlike the regular GetFirst/NextEffect the following can be used to work on ALL effects
	// but need their own loop
	int GetFirstAllEffect();
	int GetNextAllEffect();
	int GetAllEffectRemainingDuration();
	int GetAllEffectInts();
	int SetAllEffectInts();
	int GetAllEffectID();
	int GetAllEffectType();
	int GetAllEffectSubType();
	int GetAllEffectSpellID();
	int GetAllEffectCreator();
	int GetAllEffectDurationType();
	int QueueRemoveEffect();
	int RemoveQueuedEffects();

	// The following can be used in a regular GetFirst/NextEffect loop
	// They use CNWSObject->obj_effect_index to get their effect
	// but invalidate a GetFirst/NextAllEffect loop
	int GetEffectInts();
	int SetEffectInt();
	int GetEffectRemainingDuration();
	int GetEffectID();
	int GetEffectRealType();

	int GetEffectDurationSubType();

	// the following don't work on one specific effect but scan the effect array on their own to do their work
	// so they should be save to use in either effect loop
	int GetHighestEffectID();
	int SetEffectCreatorByEffectID(int bRecurse = 1); //because of Haste/Slow this is called recursivley, we stop if bRecurse is 0 as a safty measure, although it should never happen
	int SetEffectSpellIDByEffectID(int bRecurse = 1);

	//*** Local Vars ***//
	int PrintLocalVars();
	int GetLocalVariableCount();
	int GetLocalVariableByPosition(int iIndex = -1);
	int GetFirstLocalVariable();
	int GetNextLocalVariable();
	int GetHasLocalVariable();

	//*** Area ***//
	int GetAreaCount();
	uint32_t GetAreaByPosition(int iPos=-1);
	uint32_t GetFirstArea();
	uint32_t GetNextArea();

	//*** Creature Stats ***/
	int SetGold();
	int SetAbilityScore();
	int GetBABOverride();
	int SetBABOverride();
	int SetXP();
	int SetAge();
	int SetRace();
	int GetBaseAC();
	int SetBaseAC();
	int GetBonusAC();
	int SetBonusAC();
	int GetPenaltyAC();
	int SetPenaltyAC();
	int GetSavedSkillPoints();
	int SetSavedSkillPoints();
	int GetArmorCheckPenalty();
	int SetArmorCheckPenalty();
	int GetMovementRate();
	int SetMovementRate();
	int SetSkill();
	int SetSkillByLevel();
	int SetClassByPosition();
	int SetClassByLevel();
	int SetClassLevel();
	int ReplaceClass();

	int SetHitPointsByLevel();
	int SetCurrentHitPoints();
	int SetMaxHitPoints();
	int GetSavingThrowBonus();
	int SetSavingThrowBonus();

	int SetFamiliarType();
	int SetCompanionType();

	int GetDamageImmunity();

	int ZeroAllSkills();
	int SetDomain();
	int GetDomain();
	int GetWizardSpecialization();
	int SetWizardSpecialization();

	int GetFeatsGainedAtLevel();
	int GetSkillRanksGainedAtLevel();
	int GetSpellsGainedAtLevel();
	int GetStatsGainedAtLevel();

	int SetCreatureSize();
	int GetEquippedWeight();

	int SetGender();

	int GetRegeneration();

	//*** Feats ***//
	int AddFeat();
	int AddFeatAtLevel();
	int RemoveFeat();
	int GetFeatKnown();
	int GetAllKnownFeats();
	int ClearFeatList();
	int GetFeatCount();

	//*** Spells ***//
	int AddKnownSpell();
	int RemoveKnownSpell();
	int RemoveAllSpells();
	int GetKnowsSpell();
	int ReplaceKnownSpell();
	int GetRemainingSpellSlots(); //for spontaneous casters
	int SetRemainingSpellSlots();
	int GetMaxSpellSlots();
	int GetBonusSpellSlots();
	int GetMemorizedSpellSlot();
	int SetMemorizedSpell();
	int RestoreMemorizedSpells();
	int GetKnownSpells();
	int GetKnownSpellCount();
	int SetMaxSpellSlots();
	int GetKnownsSpell();

	//*** Items ***//
	int SetItemWeight();
	int SetItemValue();
	int SetItemCharges();
	int GetItemValue();

	//*** Misc stuff ***/
	int SetTag();
	int SetEvent();
	int GetEvent();
	int SetConversation();
	int GetConversation();
	int SetBodyBag();
	int GetBodyBag();
	int GetFactionID();
	int SetFactionID();
	int GetSoundSetID();
	int SetSoundSetID();

	int GetQuickSlot();
	int SetQuickSlot();
	int UpdateQuickbar();

	int GetWorldTime();

	int JumpToLimbo();

	int ApplyVFXForPC();

	int GetSurfaceMaterial();

	int SetCustomGeometry();
	int RotateCustomGeometry();
	int GetTriggerGeometry();

	int CustomTriggerGeometry;
	int AbsoluteCoordinates;
	std::list<float> Floats;
	void NWN_CreateGeometry(CNWSTrigger *Trigger, CScriptLocation *Loc, CNWSArea *Area);

	int SetDebugLevel();

	int TimebarStart();
	int TimebarStop();

	int UpdateCharSheet();

	int ClearTURDList();

	int PossessCreature();

	int SummonAssociate();

	int PrintOffsets();
	void PrintIPs();

	int BootPCWithMessage();

	int GetItemPropertyInformation();
	int ItemPropertyCustom(void *CVirtComm, int a1);

	CVisibility Visibility;
	int SetVisibilityOverride();
	int SetVisibility();
	int GetVisibilityOverride();
	int GetVisibility();

	int GetAutoRemoveKey();
	int SetAutoRemoveKey();

	int GetDestinationTag();
	int SetDestinationTag();
};

#endif;