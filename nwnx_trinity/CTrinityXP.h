#pragma once
#include "..\NWNXDLL\NWNXBase.h"
#include "types.h"
#include <vector>

#define iXPBase 209
#define iModLevel 109
#define iCRCap 60
#define iCRModCap 150

#define fLevelDiv 1.75
#define fLevelDivUpper 2.6

class CTrinityXP {
public:
	CTrinityXP(CGenericObject *obj, nwn_objid_t VictimoID);
	CTrinityXP(CNWSCreature *cre, float fXP);
	~CTrinityXP();

private:
	struct PartyMember_s {
		CNWSCreature *pCreature;
		int Level;
		float LA;
		bool bGiveXP;
	}PartyMember;

	int PartyLevel;
	int AvgLevel;
	int MemberCount;
	int PartyMod;
	CNWSArea *Area;

	std::vector<struct PartyMember_s> PlayerList;

	int GiveXPToCreature(CNWSCreature *cre, float fXP, float fLevel = -1.0, float fLA = -1.0, bool bEquipmentPenalty = false);
	void CreateParty(nwn_objid_t oID);
	float GetLA(int Race);
	int GetLevels(CNWSCreature *cre);
	void AverageParty();
	int GiveXP(nwn_objid_t oID, nwn_objid_t VictimoID);
};