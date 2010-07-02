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

#ifndef _NX_NWN_STRUCT_CEXOSTRING_
#define _NX_NWN_STRUCT_CEXOSTRING_

#include "nwnx_funcs_const.h"

class CExoString_s {
public:
    char               *text;
    uint32_t            len;

	CExoString_s();
	CExoString_s(const char* c_string);
	CExoString_s(const char* c_string, int count);
	CExoString_s(int i);
	CExoString_s(const CExoString_s &ExoString);

	~CExoString_s();

	CExoString_s & operator=(const char *c_string);
	CExoString_s & operator=(const CExoString_s &ExoString);
};
#endif /* _NX_NWN_STRUCT_CEXOSTRING_ */

/* vim: set sw=4: */
