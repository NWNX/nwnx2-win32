#ifndef _NX_NWN_STRUCT_CNWSINVENTORY_
#define _NX_NWN_STRUCT_CNWSINVENTORY_
#include "types.h"

struct CNWSInventory_s {
    uint32_t		*vftable;
	uint32_t		Slot[18];

	CNWSInventory_s();
	CNWSItem *GetItemInSlot(unsigned long nSlot);
};

#endif