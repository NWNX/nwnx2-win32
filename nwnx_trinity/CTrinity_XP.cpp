#include "StdAfx.h"
#include <math.h>
#include "CTrinityXP.h"
#include "nwnx_trinity.h"

extern CNWNXTrinity NWNXTrinity;

#define _log(a,b,...) if(a<=NWNXTrinity.debugLevel)_LOG(b,__VA_ARGS__)


CTrinityXP::CTrinityXP(CGenericObject *obj, nwn_objid_t VictimoID) {
		GiveXP(obj->obj_id, VictimoID);
}

CTrinityXP::CTrinityXP(CNWSCreature *cre, float fXP) {
		GiveXPToCreature(cre, fXP);
}

CTrinityXP::~CTrinityXP() {}

float CTrinityXP::GetLA(int Race) {
	switch (Race) {
		case 51		: return 4.00; break;
		case 53		: return 5.00; break;
		case 56		: return 6.00; break;
		case 62		: return 9.00; break;
		case 64		: return 4.00; break;
		case 66		: return 4.00; break;
		case 71		: return 4.00; break;
		case 77		: return 3.00; break;
		case 83		: return 4.00; break;
		case 102	: return 4.00; break;
		case 103	: return 3.00; break;
		case 104	: return 3.00; break;
		case 105	: return 3.00; break;
		case 106	: return 3.00; break;
		case 113	: return 3.00; break;
		case 124	: return 2.00; break;
		case 136	: return 4.00; break;
		case 144	: return 6.00; break;
		case 150	: return 3.00; break;
		case 151	: return 2.00; break;
		case 153	: return 2.00; break;
		case 162	: return 3.00; break;
		case 163	: return 2.00; break;
		case 164	: return 2.00; break;
		case 174	: return 3.00; break;
		case 187	: return 2.00; break;
		case 201	: return 3.00; break;
		case 203	: return 3.00; break;
		case 211	: return 7.00; break;
		case 212	: return 2.00; break;
		case 218	: return 2.00; break;
		case 220	: return 5.00; break;
		case 222	: return 2.00; break;
		case 223	: return 2.00; break;
		case 224	: return 7.00; break;
		case 225	: return 7.00; break;
		case 226	: return 4.00; break;
		case 227	: return 4.00; break;
		case 229	: return 2.00; break;
		case 231	: return 5.00; break;
		case 232	: return 3.00; break;
		case 233	: return 2.00; break;
		case 234	: return 2.00; break;
		case 249	: return 4.00; break;
		default		: return 0.00; break;
	}
}

void CTrinityXP::AverageParty() {
	_log(3, "\t\t<Average Party>\n");

	try {
		MemberCount = PlayerList.size();
		_log(3, "\t\t\tMemberCount: %d\n", MemberCount);
		if (MemberCount < 1) MemberCount = 1;
		AvgLevel = PartyLevel  / MemberCount;

		std::vector<struct PartyMember_s>::iterator it = PlayerList.begin();
		while (it != PlayerList.end()) {
			//party members not in the same area where excluded earlier
			if (it->Level < AvgLevel-5) {
				MemberCount--;
				PartyLevel -= it->Level;
			}
			CNWSCreatureStats *Stats = it->pCreature->cre_stats;
			if (Stats) {
				it->LA = GetLA(it->pCreature->cre_stats->cs_race);
			}
			it++;
		}
		if (MemberCount < 1) MemberCount = 1;
		AvgLevel = PartyLevel  / MemberCount;
		switch (MemberCount) {
			case 1:  PartyMod = 100; break;
			case 2:  PartyMod = 102; break;
			case 3:  PartyMod = 104; break;
			case 4:  PartyMod = 108; break;
			case 5:  PartyMod = 110; break;
			case 6:  PartyMod = 105; break;
			case 7:  PartyMod = 100; break;
			default: PartyMod = 90; break;
		}
		_log(3, "\t\t\tPartyMod: %d%%\n", PartyMod);
	}
	catch (std::exception &e) {
		_log(3, "::Exception: %s\n", e.what());
	}
	_log(3, "\t\t</Average Party>\n");
}

void CTrinityXP::CreateParty(nwn_objid_t oID) {
	_log(3, "\t<CreateParty>\n");
	PartyLevel = 0;

	CNWSCreature *cre = ((*NWN_AppManager)->app_server->srv_internal)->GetCreatureByGameObjectID(oID);
	if (cre) {
		Area = ((CNWSObject*)cre)->GetArea();
		if (Area) {
			Area = (CNWSArea*)((char*)Area+0xC4);
			_log(3, "\t\tParty Area: %08X\n", Area->are_id);
			uint32_t FactionID = cre->cre_stats->cs_faction_id;

			CNWSFaction *Faction = (*NWN_AppManager)->app_server->srv_internal->srv_factions->GetFaction(FactionID);
			if (Faction) {
				int Length = Faction->members_len;
				PlayerList.reserve(Length);
				int i=0;
				nwn_objid_t MemberoID = OBJECT_INVALID;
				CNWSArea *MemberArea = NULL;
				while (i < Length) {
					MemberoID = Faction->members_oID[i];
					cre = ((*NWN_AppManager)->app_server->srv_internal)->GetCreatureByGameObjectID(MemberoID);
					if (cre && cre->cre_is_pc) {
						_log(3, "\t\tMemberoID: %08X", MemberoID);
						MemberArea = ((CNWSObject*)cre)->GetArea();
						if (MemberArea) {
							MemberArea = (CNWSArea*)((char*)MemberArea+0xC4);
							_log(3, " | MemberArea %08X", MemberArea->are_id);
							if (MemberArea->are_id == Area->are_id) {
								int Levels = GetLevels(cre);
								_log(3, " | Member Level: %d", Levels);
								this->PartyLevel += Levels;

								struct PartyMember_s PartyMember;
								PartyMember.bGiveXP = true;
								PartyMember.Level = Levels;
								PartyMember.pCreature = cre;

								PlayerList.push_back(PartyMember);
							}
						}
						_log(3, "\n");
					}
					i++;
				}
			}
			AverageParty();
		}
	}
	_log(3, "\t</CreateParty>\n");
}

int CTrinityXP::GiveXPToCreature(CNWSCreature * cre, float fXP, float fLevel, float fLA, bool bEquipmentPenalty) {
	_log(3, "\t<GiveXPToCreature [%08X]> ", ((CNWSObject*)cre)->obj_generic.obj_id);
	if (!cre || !cre->cre_is_pc) return 0;
	
	if (fLevel < 0.0) fLevel = (float)GetLevels(cre);

	//ECL adjustment
	if (fLA < 0.0) fLA = GetLA(cre->cre_stats->cs_race);

	_log(3, "\tLA: %.0f", fLA);

	if (fLA > 0.0) {
		fXP = fXP / (float)(fLA / fLevel + 1.0);
	}

	if (bEquipmentPenalty) {
		CExoString VarName;
		// penalty for uber equipment
		if (fLevel < 20.0) {
			VarName = "MC_NEQUIPMENT_AVERAGE";
			float fAverageItemLevel = ((CNWSObject*)cre)->obj_vartable.GetFloat(VarName);
			_log(3, "\tAvg Item Level: %f", fAverageItemLevel);
			if (fAverageItemLevel > fLevel+5.0) {
				float fDiv = 1.0;
				fDiv = (float)pow(4.0,((fAverageItemLevel - (fLevel+5.0)) / 10.0));
				if (fDiv < 1.0) fDiv = 1.0;
				fXP /= fDiv;
			}
		}
	}

	int iFinalXP = (int)floor(fXP);
	_log(3, "\tiFinalXP: %d", iFinalXP);

	// fill up negative xp on the handbook first

	int iOldXP = cre->cre_stats->cs_xp;
	(cre->cre_stats)->AddExperience(iFinalXP);
	int iNewXP = cre->cre_stats->cs_xp;

	iFinalXP = iNewXP - iOldXP; //this is the amount of xp cre gets, figuring in multi class penalties (too lazy to calc them myself)
	
	// reset the xp to the old value (there's no message like this)
	cre->cre_stats->cs_xp = iOldXP;

	//and see if we need to fill up the negative xp first

	CExoString sTag = "TRINITYHANDBOOK";
	nwn_objid_t oidBook = cre->cre_inventory->FindItemWithTag(&sTag);
	if (oidBook != OBJECT_INVALID) {
	CNWSItem *oBook = ((*NWN_AppManager)->app_server->srv_internal)->GetItemByGameObjectID(oidBook);
		if (oBook) {
			CExoString VarName;
			CNWSObject *objBook = ((CNWSObject*)((char*)(oBook)+0x10));
			VarName = NWNXTrinity.NegXPVar;
			int iNegativeXP = objBook->obj_vartable.GetInt(VarName);
			if (iNegativeXP < 0) {
				iNegativeXP += iFinalXP;
				if (iNegativeXP >= 0) {
					iFinalXP = iNegativeXP;
					iNegativeXP = 0;
				}
				else iFinalXP = 0;
				_log(3, "\tNegative XP: %d", iNegativeXP);
			}
			objBook->obj_vartable.SetInt(VarName, iNegativeXP, 0);
		}
	}

	//set the actual xp again
	if (iFinalXP > 0) {
		cre->cre_stats->cs_xp += iFinalXP;
	}

	_log(3, " </GiveXPToCreature (%d)>\n", iFinalXP);

	return 1;
}

int CTrinityXP::GiveXP(nwn_objid_t oID, nwn_objid_t VictimoID) {
	_log(3, "<GiveXP>\n");

	if (VictimoID == OBJECT_INVALID) return 0;

	CNWSCreature *cre_Killed = ((*NWN_AppManager)->app_server->srv_internal)->GetCreatureByGameObjectID(VictimoID);
	if (!cre_Killed) return 0;

	CreateParty(oID);
	
	if (MemberCount > 0) {
		CExoString VarName("iOVERRIDE_CR");

		int iCR = ((CNWSObject*)cre_Killed)->obj_vartable.GetInt(VarName);
		if (iCR == 0) iCR = (int)floor(cre_Killed->cre_stats->cs_cr);
		if (iCR > iCRCap) iCR = iCRCap;
		else if (iCR < 1) iCR = 1;

		_log(3, "\tChallenge Rating: %d\n", iCR);

		int iBaseXP = iCR * 2 + iXPBase;

		float fCRMod = (float)iCR / (float)AvgLevel * (float)100.0;
		if (fCRMod > iCRModCap) fCRMod = iCRModCap;
		int iLevelMod = iModLevel - (AvgLevel);
		float fXPMod = (float)PartyMod * fCRMod * (float)iLevelMod;
		float fXP = (float)iBaseXP * fXPMod / (float)1000000.0;

		std::vector<struct PartyMember_s>::iterator it = PlayerList.begin();
		while (it != PlayerList.end()) {
			if (it->bGiveXP && !((CNWSObject*)it->pCreature)->GetDead()) {

				// Check if they have enough xp to take 2 levels
				int iLevelFromXP = (int)floor(0.5 + sqrt(0.25 + ( (float)(it->pCreature->cre_stats->cs_xp) / 500.0 )));
				if (iLevelFromXP > 40) iLevelFromXP = 40;

				if (iLevelFromXP - it->Level > 1) {
					_log(3, "\tNO XP! Player could already level up\n");
				}
				else {
					float fLevel = (float)it->Level;

					float fMod = fLevel / ((float)AvgLevel / (float)fLevelDiv);
					if (fMod < 1.0) fXP *= fMod;
					else if (fMod > fLevelDivUpper) fXP /= fMod;


					GiveXPToCreature(it->pCreature, fXP, fLevel, it->LA, true);
				}
			}
			it++;
		}

	}
	_log(3, "</GiveXP>\n");
	return 1;
}

int CTrinityXP::GetLevels(CNWSCreature *cre) {
	if (cre) {
		int Level = (cre->cre_stats)->GetLevel(0);
		CExoString VarName("MC_LL_LEVEL1");
		int LL = ((CNWSObject*)cre)->obj_vartable.GetInt(VarName);
		VarName = "MC_LL_LEVEL2"; LL += ((CNWSObject*)cre)->obj_vartable.GetInt(VarName);
		VarName = "MC_LL_LEVEL3"; LL += ((CNWSObject*)cre)->obj_vartable.GetInt(VarName);
		return Level + LL;
	}
	return 0;
}