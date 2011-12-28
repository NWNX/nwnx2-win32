#pragma once
#include "CFuncLookup.h"
#include "CFuncUtility.h"

class CNssSpells :	public CFuncLookup, public CFuncUtility {
public:
	CNssSpells(void);

private: //helper functions

public: //script functions
	int AddKnownSpell(CGameObject *oObject, char *Params);
	int RemoveKnownSpell(CGameObject *oObject, char *Params);
	int RemoveAllSpells(CGameObject *oObject, char *Params);
	int GetKnowsSpell(CGameObject *oObject, char *Params);
	int ReplaceKnownSpell(CGameObject *oObject, char *Params);
	int GetRemainingSpellSlots(CGameObject *oObject, char *Params);
	int SetRemainingSpellSlots(CGameObject *oObject, char *Params);
	int GetMaxSpellSlots (CGameObject *oObject, char *Params);
	int GetBonusSpellSlots(CGameObject *oObject, char *Params);
	int GetMemorizedSpellSlot(CGameObject *oObject, char *Params);
	int SetMemorizedSpell(CGameObject *oObject, char *Params);
	int RestoreMemorizedSpells(CGameObject *oObject, char *Params);
	int GetKnownSpells(CGameObject *oObject, char *Params);
	int GetKnownSpellCount(CGameObject *oObject, char *Params);
	int SetMaxSpellSlots(CGameObject *oObject, char *Params);

};
