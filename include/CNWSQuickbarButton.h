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

#ifndef _NX_NWN_STRUCT_CNWSQUICKBARBUTTON_
#define _NX_NWN_STRUCT_CNWSQUICKBARBUTTON_

class CNWSQuickbarButton_s {
public:
    CNWSQuickbarButton_s();
	~CNWSQuickbarButton_s();
	CNWSQuickbarButton_s &operator=(CNWSQuickbarButton_s &qb);

	uint32_t            qb_objid1;		/* 0x00 */
    uint32_t            qb_objid2;		/* 0x04 */

    uint8_t             qb_type;		/* 0x08 */
    uint8_t             qb_class;		/* 0x09 */

	char				qb_resref[17];	/* 0x0A */	// for stuff dragged from the creator
    
    CExoString			qb_label;		/* 0x1C */
    CExoString			qb_command;		/* 0x24 */

    CExoString          qb_label2;		/* 0x2C */	// for stuff dragged from the creator

    uint32_t            qb_id;			/* 0x34 */
    uint32_t            qb_metamagic;	/* 0x38 */

    uint32_t            field_3C;		/* 0x3C */
};
	

#endif /* _NX_NWN_STRUCT_CNWSQUICKBARBUTTON_ */

/* vim: set sw=4: */
