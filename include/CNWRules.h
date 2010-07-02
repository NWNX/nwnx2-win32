/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

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
};

#endif /* _NX_NWN_STRUCT_CNWRULES_ */

/* vim: set sw=4: */
