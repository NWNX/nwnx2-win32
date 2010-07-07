#ifndef _NX_NWN_STRUCT_CNWSINVENTORY_
#define _NX_NWN_STRUCT_CNWSINVENTORY_

struct CNWSInventory_s {
    void               *unknown;

	CNWSItem *GetItemInSlot(unsigned long nSlot);
};

#endif