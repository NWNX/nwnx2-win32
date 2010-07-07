#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

uint8_t 		(__thiscall *CNWRules__GetFeatExpansionLevel)(CNWRules *pTHIS, uint16_t FeatID) = (uint8_t (__thiscall*)(CNWRules *pTHIS, uint16_t FeatID))0x004B80F0;

uint8_t CNWRules::GetFeatExpansionLevel(uint16_t FeatID) {
	return CNWRules__GetFeatExpansionLevel(this, FeatID);
}