/***************************************************************************
    nwntypes.h - NWN engine types for use in NWNX plugins
    Copyright (C) 2010 Andrew Brockert (Zebranky)
    email: andrew@mercuric.net

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
struct CNWSPlayer_s;		typedef struct CNWSPlayer_s			CNWSPlayer;
struct CGameObject_s;		typedef struct CGameObject_s		CGameObject;
struct CAppManager_s;		typedef struct CAppManager_s		CAppManager;
struct CVirtualMachine_s;	typedef struct CVirtualMachine_s	CVirtualMachine;
struct CExoString_s;		typedef struct CExoString_s			CExoString;
struct Vector_s;			typedef struct Vector_s				Vector;

struct Vector_s {
	float x;
	float y;
	float z;
};
struct CGameObject_s {
    uint32_t            field_00;
    uint32_t            id;
};

struct CAppManager_s {
    uint32_t                   field_00;
};

struct CVirtualMachine_s {
    uint32_t                   field_00;
};

struct CNWSPlayer_s {
	uint8_t			unknown[0x30];
    uint32_t            nwsoid;
};

struct CExoString_s {
    char               *text;
    uint32_t            len;
};