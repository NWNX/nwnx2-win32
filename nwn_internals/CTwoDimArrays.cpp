#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

//unsigned char (__thiscall *CTwoDimArrays__GetEpicFortSaveBonus)(CTwoDimArrays *pTHIS, unsigned char EpicLevel) = (unsigned char(__thiscall*)(CTwoDimArrays *pTHIS, unsigned char EpicLevel))0x00518630;
//unsigned char (__thiscall *CTwoDimArrays__GetEpicRefSaveBonus)(CTwoDimArrays *pTHIS, unsigned char EpicLevel) = (unsigned char(__thiscall*)(CTwoDimArrays *pTHIS, unsigned char EpicLevel))0x00518650;
//unsigned char (__thiscall *CTwoDimArrays__GetEpicWillSaveBonus)(CTwoDimArrays *pTHIS, unsigned char EpicLevel) = (unsigned char(__thiscall*)(CTwoDimArrays *pTHIS, unsigned char EpicLevel))0x00518670;

uint8_t CTwoDimArrays_s::GetEpicFortSaveBonus(int EpicLevels) {
	if (EpicLevels < 1 || EpicLevels > 60) return 0;
	return tda_epic_save_fort[EpicLevels];
}

uint8_t CTwoDimArrays_s::GetEpicWillSaveBonus(int EpicLevels) {
	if (EpicLevels < 1 || EpicLevels > 60) return 0;
	return tda_epic_save_will[EpicLevels];
}

uint8_t CTwoDimArrays_s::GetEpicRefSaveBonus(int EpicLevels) {
	if (EpicLevels < 1 || EpicLevels > 60) return 0;
	return tda_epic_save_ref[EpicLevels];
}

uint8_t CTwoDimArrays_s::GetEpicAttackBonus(int EpicLevels) {
	if (EpicLevels < 1 || EpicLevels > 60) return 0;
	return tda_epic_ab[EpicLevels];
}