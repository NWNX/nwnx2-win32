#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CNWSItem* (__thiscall *CNWSInventory__GetItemInSlot)(CNWSInventory* pTHIS, unsigned long nSlot) = (CNWSItem* (__thiscall*)(CNWSInventory* inventory, unsigned long nSlot))0x00502240;

CNWSItem *CNWSInventory::GetItemInSlot(unsigned long nSlot) {
	return CNWSInventory__GetItemInSlot(this, nSlot);
}