#ifndef _NX_NWN_STRUCT_CNWRULES_
#define _NX_NWN_STRUCT_CNWRULES_

struct CNWRules_s {
	void				*v_table;						/* 0x0000 */
	float				ru_spell_range_personal;		/* 0x0004 */
	float				ru_spell_range_touch;			/* 0x0008 */
	float				ru_spell_range_short;			/* 0x000C */
	float				ru_spell_range_medium;			/* 0x0010 */
	float				ru_spell_range_long;			/* 0x0014 */

	CNWBaseItemArray 	*ru_baseitems;					/* 0x0018 */

	uint32_t			ru_xp_level[41];				/* 0x001C */

	void				*ru_spells;						/* 0x00C0 */

	uint32_t			field_C4;
	uint32_t			field_C8;
	uint32_t			field_CC;
	uint32_t			field_D0;

	uint16_t			*ru_sorted_feats;				/* 0x00D4 */

	uint16_t			ru_feats_len;					/* 0x00D6 */
	uint16_t			ru_sorted_feats_len;			/* 0x00D8 */

	uint8_t				ru_unknown_len;					/* 0x00DA */
	uint8_t				ru_classes_len;					/* 0x00DB */
	uint8_t				ru_races_len;					/* 0x00DC */
	uint8_t				ru_skills_len;					/* 0x00DD */
	uint8_t				ru_domains_len;					/* 0x00DE */
	
	uint8_t GetFeatExpansionLevel(uint16_t FeatID);
};

#endif