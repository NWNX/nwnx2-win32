#ifndef _NX_NWN_STRUCT_CNWSAREA_
#define _NX_NWN_STRUCT_CNWSAREA_

struct CNWSArea_s {
    void                    *are_vftable;
    unsigned __int32					are_id;			/* 0x004 */
    unsigned __int32                    are_width;
    unsigned __int32                    are_height;
    unsigned __int32                    field_10;
    uint32_t                    field_14;
    uint32_t                    field_18;
    uint32_t                    field_1C;
    uint32_t                    field_20;
    uint32_t                    field_24;
    uint32_t                    field_28;
    uint32_t                    field_2C;
    uint32_t                    field_30;

    CExoLocString               area_name;				/* 0x0034 */
    CExoString                  area_tag;				/* 0x003C */
    char                        area_tileset_ref[16];	/* 0x0044 */	//no terminator

    uint32_t                    field_54;
    uint32_t                    field_58;
    uint32_t                    field_5C;
    CExoString					are_script_hb;
    CExoString					are_script_userdefined;
    CExoString					are_script_onenter;
    CExoString					are_script_onexit;
    uint32_t                    field_80;
    uint32_t                    field_84;
    uint32_t                    field_88;
    uint32_t                    field_8C;
    uint32_t                    field_90;
    uint32_t                    field_94;
    uint32_t                    field_98;
    uint32_t                    field_9C;
    uint32_t                    field_A0;
    uint32_t                    field_A4;
    uint32_t                    field_A8;
    uint32_t                    field_AC;
    uint32_t                    field_B0;
    CResRef                     *area_git;
    uint32_t                    field_B8;
    uint32_t                    field_BC;
    uint32_t                    field_C0;
    uint32_t                    field_C4;
    uint32_t                    field_C8;
    uint32_t                    field_CC;
    uint32_t                    are_numplayers;
    uint32_t                    field_D4;
    uint32_t                    field_D8;
    uint32_t                    field_DC;
    uint32_t                    field_E0;
    uint32_t                    field_E4;
    uint32_t                    field_E8;
    uint32_t                    field_EC;
    uint32_t                    field_F0;
    uint32_t                    field_F4;
    uint32_t                    field_F8;
    uint32_t                    field_FC;
    uint32_t                    field_100;
    uint32_t                    field_104;
    uint32_t                    field_108;
    uint32_t                    field_10C;
    CNWSScriptVarTable          area_vartable;	/* 0x0110 */
    uint32_t                    field_114;
    uint32_t                    field_118;
    uint32_t                    field_11C;
    uint32_t                    field_120;
    uint32_t                    field_124;
    uint32_t                    field_128;
    uint32_t                    field_12C;
    uint32_t                    field_130;
    uint32_t                    field_134;
    uint32_t                    field_138;
    uint32_t                    field_13C;
    uint32_t                    field_140;
    uint32_t                    field_144;
    uint32_t                    field_148;
    uint32_t                    *obj_list;
    uint32_t                    obj_list_len;
    uint32_t                    obj_list_alloc;
    uint32_t                    first_next_obj_index;
    uint32_t                    *transition_list;
    uint32_t                    transition_list_len;
    uint32_t                    transition_list_alloc;
    
};

#endif /* _NX_NWN_STRUCT_CNWSAREA_ */

/* vim: set sw=4: */
