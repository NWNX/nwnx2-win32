#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CNWBaseItem *	(__thiscall *CNWBaseItemArray__GetBaseItem)(CNWBaseItemArray *pTHIS, int baseItem) = (CNWBaseItem* (__thiscall*)(CNWBaseItemArray *pTHIS, int baseItem))0x00512AF0;


CNWBaseItem *CNWBaseItemArray_s::GetBaseItem(int BaseItem) {
	return CNWBaseItemArray__GetBaseItem(this, BaseItem);
}