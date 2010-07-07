#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int 			(__thiscall *CNWSItem__ComputeArmorClass)(CNWSItem *pTHIS) = (int (__thiscall*)(CNWSItem *pTHIS))0x004FE870;
int 			(__thiscall *CNWSItem__SetPossessor)(CNWSItem *pTHIS, unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i) = (int (__thiscall*)(CNWSItem *pTHIS, unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i))0x004FAF10;

int CNWSItem_s::ComputeArmorClass() {
	return CNWSItem__ComputeArmorClass(this);
}

int CNWSItem_s::SetPossessor(unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i) {
	return CNWSItem__SetPossessor(this, a2_Possessor_id, a3_Signalevent, a4_bFeedback, i);
}
