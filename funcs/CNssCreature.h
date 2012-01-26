#pragma once
#include "cfunclookup.h"

class CNssCreature : public CFuncLookup {
public:
	CNssCreature(void);

private: //helper functions
	int GetAttackModifierVersus(CNWSCreature *Attacker, CNWSObject* Defender, int bOffHand, int bRangedAttack);
	CNWSItem *GetWeapon(CNWSCreature *cre, int bOffHand, bool bGetBracers);

public: //script functions
	int SetCreatureSize(CGameObject *oObject, char *Params);
	int GetEquippedWeight(CGameObject *oObject, char *Params);
	int SetGold(CGameObject *oObject, char *Params);
	int GetSoundSetID(CGameObject *oObject, char *Params);
	int SetSoundSetID(CGameObject *oObject, char *Params);
	int JumpToLimbo(CGameObject *oObject, char *Params);
	int SummonAssociate(CGameObject *oObject, char *Params);
	int GetAttackModifierVs(CGameObject *oObject, char *Params);

};
