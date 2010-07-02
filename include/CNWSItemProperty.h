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

#ifndef _NX_NWN_STRUCT_CNWITEMPROPERTY_
#define _NX_NWN_STRUCT_CNWITEMPROPERTY_

struct CNWSItemProperty_s {
    uint16_t			ip_type;				/* 0000 */
    uint16_t			ip_subtype;				/* 0002 */

    uint8_t				ip_cost_table;			/* 0004 */
    uint8_t				field_5;				/* 0005 */		//seems to always be 5C
    uint16_t			ip_cost_value;			/* 0006 */

    uint8_t				ip_param_table;			/* 0008 */
    uint8_t				ip_param_value;			/* 0009 */
    uint8_t				ip_chance;				/* 0x0A */
	uint8_t				field_0B;
	
	uint32_t			ip_useable;
	
	uint8_t				ip_usesleft;			/* 0x10 */
	uint8_t				ip_duration;			/* 0x11 */ //02 = permanent, 01 = temporary
	uint8_t				field_12;
	uint8_t				field_13;
};

#endif /* _NX_NWN_STRUCT_CNWITEMPROPERTY_ */

/* vim: set sw=4: */
