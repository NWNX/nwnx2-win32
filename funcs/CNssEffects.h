#pragma once
#include "CFuncLookup.h"

class CNssEffects :	public CFuncLookup {
public:
	CNssEffects(void);

	int CreateCustomEffect(int a3);

private: //helper functions
	BOOL ValidEffectObject(CGameObject *oObject);
	int SetEffectCreatorByID(const CNWSObject *obj, const nwn_objid_t &Creator, const int &EffectID, int bRecurse);
	int SetEffectSpellIDByID(const CNWSObject *obj, const int &spellid, const int &EffectID, int bRecurse);


	std::vector<uint64_t>EffectRemovalIDs;
	CGameEffect *getFirstNextEffect;
	nwn_objid_t getFirstNextEffectObj;
	int getFirstNextEffectScriptIndex;
	bool getFirstNextEffectScriptEffect;
	CNWSObject *getFirstNextEffectObject;

	CNWSObject *CustomEffectObject;

public: //Script functions
	int PrintEffects(CGameObject *oObject, char *Params);

	// Unlike the regular GetFirst/NextEffect the following can be used to work on ALL effects
	// but need their own loop
	int GetFirstAllEffect(CGameObject *oObject, char *Params);
	int GetNextAllEffect(CGameObject *oObject, char *Params);
	int GetAllEffectRemainingDuration(CGameObject *oObject, char *Params);
	int GetAllEffectInts(CGameObject *oObject, char *Params);
	int SetAllEffectInts(CGameObject *oObject, char *Params);
	int GetAllEffectID(CGameObject *oObject, char *Params);
	int GetAllEffectType(CGameObject *oObject, char *Params);
	int GetAllEffectSubType(CGameObject *oObject, char *Params);
	int GetAllEffectSpellID(CGameObject *oObject, char *Params);
	int GetAllEffectCreator(CGameObject *oObject, char *Params);
	int GetAllEffectDurationType(CGameObject *oObject, char *Params);
	int QueueRemoveEffect(CGameObject *oObject, char *Params);
	int RemoveQueuedEffects(CGameObject *oObject, char *Params);

	// The following can be used in a regular GetFirst/NextEffect loop
	// They use CNWSObject->obj_effect_index to get their effect
	// but invalidate a GetFirst/NextAllEffect loop
	int GetEffectInts(CGameObject *oObject, char *Params);
	int SetEffectInt(CGameObject *oObject, char *Params);
	int GetEffectRemainingDuration(CGameObject *oObject, char *Params);
	int GetEffectID(CGameObject *oObject, char *Params);
	int GetEffectRealType(CGameObject *oObject, char *Params);

	int GetEffectDurationSubType(CGameObject *oObject, char *Params);

	// the following don't work on one specific effect but scan the effect array on their own to do their work
	// so they should be save to use in either effect loop
	int GetHighestEffectID(CGameObject *oObject, char *Params);

	int SetEffectCreatorByEffectID(CGameObject *oObject, char *Params);
	int SetEffectSpellIDByEffectID(CGameObject *oObject, char *Params);

	int ApplyVFXForPC(CGameObject *oObject, char *Params);
};
