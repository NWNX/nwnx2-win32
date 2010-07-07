#if !defined(NWNXFUNCS_H_)
#define NWNXFUNCS_H_

#include "..\NWNXDLL\NWNXBase.h"
#include "types.h"
#include "HookFunc.h"
#include <vector>
#include <list>
#include <string>
#include <hash_map>

#define _log(a,b,...) if(a<=debugLevel)LOG(b,__VA_ARGS__)

#define PLAYER_ID_ALL_PLAYERS						0xFFFFFFF7

#define FUNCTION_COUNT 121

class CNWNXFuncs : public CNWNXBase {
public:
	CNWNXFuncs();
	virtual ~CNWNXFuncs();
	
	char *OnRequest(char *gameObject, char *Request, char *Parameters);
	BOOL OnCreate(const char *LogDir);
	BOOL OnRelease();

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

	// the following don't work on one specific effect but scan the effect array on their own to do their work
	// so they should be save to use in either effect loop
	int GetHighestEffectID();
	int SetEffectCreatorByEffectID(int bRecurse = 1); //because of Haste/Slow this is called recursivley, we stop if bRecurse is 0 as a safty measure, although it should never happen
	int SetEffectSpellIDByEffectID(int bRecurse = 1);



	//***********  Local Vars  **************//
	int PrintLocalVars();
	int GetLocalVariableCount();
	int GetLocalVariableByPosition(int iIndex = -1);
	int GetFirstLocalVariable();
	int GetNextLocalVariable();
	int GetHasLocalVariable();

	// Area
	int GetAreaCount();
	uint32_t GetAreaByPosition(int iPos=-1);
	uint32_t GetFirstArea();
	uint32_t GetNextArea();

	// creature stats
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
	int SetClassLevel();

	int SetHitPointsByLevel();
	int SetCurrentHitPoints();
	int SetMaxHitPoints();
	int GetSavingThrowBonus();
	int SetSavingThrowBonus();

	int SetFamiliarType();
	int SetCompanionType();

	int GetDamageImmunity();

	//Feats
	int AddFeat();
	int AddFeatAtLevel();
	int RemoveFeat();
	int GetFeatKnown();
	int GetAllKnownFeats();
	int ClearFeatList();
	int GetFeatCount();

	int ZeroAllSkills();
	int SetDomain();
	int GetDomain();
	int GetWizardSpecialization();
	int SetWizardSpecialization();

	int GetFeatsGainedAtLevel();
	int GetSkillRanksGainedAtLevel();
	int GetSpellsGainedAtLevel();
	int GetStatsGainedAtLevel();

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

	int SetCreatureSize();
	int GetEquippedWeight();

	//spells
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

	int SetItemWeight();
	int SetItemValue();
	int SetItemCharges();
	int GetItemValue();

	int GetQuickSlot();
	int SetQuickSlot();
	int UpdateQuickbar();

	int SetGender();

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
	bool bHookCreateGeometry;

	int SetDebugLevel();
	int debugLevel;

	int TimebarStart();
	int TimebarStop();

	void LOG(const char *pcMsg, ...);

private:
	struct effect_id_type_s {
		uint64_t id;
		uint8_t type;
	}EffIdType;

	unsigned long OnRequestObject (char *gameObject, char *Request);
	void WriteLogHeader(int debug);
	void SetParameters();

	int PrintOffsets();
	void PrintIPs();

	CNWSScriptVarTable *GetVarTable(); //get the scriptvar table for a given object type
	CNWSStats_Level *nwn_GetLevelStats (const CNWSCreatureStats *stats, int level);
	BOOL GetIsCreature();
	BOOL GetIsItem();
	BOOL ValidEffectObject();
	char *GetScriptVarType(int i);

	unsigned long gameID;
	char *Params;
	char *oObject;

	uint8_t nSkill;

	signed long int P1, P2, P3, P4;

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

	CGameEffect *GetNthEffect(const CNWSObject *obj, long P1, long P2);

// internal functions helper declarations

	void nwn_SetWorldTime(uint32_t wtDate, uint32_t wtTime, int P3=0);
	void nwn_UpdateQuickBar(CGenericObject* obj);
	CNWSModule *nwn_GetModule(bool addOffset=true);
	void nwn_JumpCreatureToLimbo(CNWSCreature *cre);

	void nwn_UpdateObject(nwn_objid_t plID, nwn_objid_t objID, CNWSObject* obj);

	void nwn_SendServerToPlayerGameObjUpdate(CGenericObject *obj);

	void RunTestFunc(CGenericObject* obj);

	void CreateFunctionLookup();
	int (__thiscall CNWNXFuncs::*pFunc[FUNCTION_COUNT])();
	stdext::hash_map<std::string, int> FunctionLookup;

	int GetEventScriptInfo(int &ScriptNumber, std::string &ScriptName, int Max);

	int ModifyItem();

public:
	int SendServerToPlayerChatMessage(uint8_t Channel, nwn_objid_t Sender, char *Msg, int Msg_len, uint32_t Receiver);

};

#endif;