#ifndef _NX_NWN_STRUCT_CNWITEM_
#define _NX_NWN_STRUCT_CNWITEM_

struct CNWItem_s {
	uint32_t					CNWItem_vftable;				/* 0x0000 */
	
    uint8_t                     it_color[6];			/* 0x0004 */       
    uint8_t                     field_06;				/* 0x000A */
    uint8_t                     field_07;				/* 0x000B */

    uint32_t                    it_baseitemtype;		/* 0x000C */
}; 

#endif