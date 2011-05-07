#include "stdafx.h"
#include "CNWSInventory.h"
#include "types.h"
#include "nwn_internals.h"

CNWSItem* (__thiscall *CNWSInventory__GetItemInSlot)(CNWSInventory* pTHIS, unsigned long nSlot) = (CNWSItem* (__thiscall*)(CNWSInventory* inventory, unsigned long nSlot))0x00502240;

CNWSInventory_s::CNWSInventory_s() {
	*(uint32_t*)&vftable = 0x006342E0;
	memset(Slot, 0x7F000000, sizeof(Slot));
}

CNWSItem *CNWSInventory::GetItemInSlot(unsigned long nSlot) {
	return CNWSInventory__GetItemInSlot(this, nSlot);
}