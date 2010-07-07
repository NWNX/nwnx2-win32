#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

uint32_t (__thiscall *CItemRepository__FindItemWithTag)(CItemRepository *pTHIS, CExoString *sTag) = (uint32_t (__thiscall*)(CItemRepository *pTHIS, CExoString *sTag))0x004FFA40;

uint32_t CItemRepository_s::FindItemWithTag(CExoString *sTag) {
	return CItemRepository__FindItemWithTag(this, sTag);
}