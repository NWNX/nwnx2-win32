#ifndef _NX_NWN_STRUCT_CNWSSTATS_LEVEL_
#define _NX_NWN_STRUCT_CNWSSTATS_LEVEL_

struct CNWSStats_Level_s {
    CExoArrayList_uint32        ls_spells_known[10];

    uint32_t                    unknown_1[30];

    CExoArrayList_uint16        ls_featlist;

    uint8_t                    *ls_skilllist;
    uint8_t                     ls_skillpoints;

    uint8_t                     unknown_2;

    uint8_t                     ls_ability;
    uint8_t                     ls_hp;
    
    uint8_t                     ls_class;

	void 				AddFeat(uint16_t Feat);
	CNWSStats_Level*	CNWLevelStats();

};

#endif