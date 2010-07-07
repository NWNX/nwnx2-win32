#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void 			(__thiscall *CNWLevelStats__AddFeat)(CNWSStats_Level *pTHIS, uint16_t Feat) = (void (__thiscall *)(CNWSStats_Level *pTHIS, uint16_t Feat))0x00506570;
CNWSStats_Level*(__thiscall *CNWLevelStats__CNWLevelStats)(CNWSStats_Level *pTHIS) = (CNWSStats_Level* (__thiscall*)(CNWSStats_Level *pTHIS))0x00506330;


void  CNWSStats_Level_s::AddFeat(uint16_t Feat) {
	CNWLevelStats__AddFeat(this, Feat);
}

CNWSStats_Level* CNWSStats_Level_s::CNWLevelStats() {
	return CNWLevelStats__CNWLevelStats(this);
}

