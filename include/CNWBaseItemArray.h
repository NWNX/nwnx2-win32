#ifndef _NX_NWN_STRUCT_CNWBASEITEMARRAY_
#define _NX_NWN_STRUCT_CNWBASEITEMARRAY_

struct CNWBaseItemArray_s {
	uint32_t			bitemarray_len;
    CNWBaseItem         *bitemarray_bitem;

	CNWBaseItem *GetBaseItem(int BaseItem);
};

#endif