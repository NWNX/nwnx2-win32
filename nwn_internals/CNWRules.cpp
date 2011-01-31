#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

uint8_t 		(__thiscall *CNWRules__GetFeatExpansionLevel)(CNWRules *pTHIS, uint16_t FeatID) = (uint8_t (__thiscall*)(CNWRules *pTHIS, uint16_t FeatID))0x004B80F0;

uint8_t CNWRules::GetFeatExpansionLevel(uint16_t FeatID) {
	return CNWRules__GetFeatExpansionLevel(this, FeatID);
}

unsigned short CNWRules::RollDice(unsigned char NumDice, unsigned char DieType) {
	int v4, v3=0;
	if (DieType && (v4 = NumDice, (signed int)NumDice > 0)) {
		do {
			--v4;
			v3 += rand() % DieType + 1;
		} while (v4);
		return v3;
	}
	return 0;		
}