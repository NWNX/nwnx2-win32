#ifndef _NX_NWN_STRUCT_CITEMREPOSITORY_
#define _NX_NWN_STRUCT_CITEMREPOSITORY_

struct CItemRepository_s {
    uint32_t            field_00;
    uint32_t            field_04;

    nwn_objid_t         ir_object;
    
    uint32_t			field_0C;

    CExoLinkedList      ir_list;

    void               *unknown;

	uint32_t FindItemWithTag(CExoString *sTag);
};

#endif