#ifndef _NX_NWN_NWNX_FUNCS_CONST_H_
#define _NX_NWN_NWNX_FUNCS_CONST_H_

typedef unsigned __int64 uint64_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int8  uint8_t;
typedef signed   __int64 int64_t;
typedef signed   __int32 int32_t;
typedef signed   __int16 int16_t;
typedef signed   __int8  int8_t;

typedef uint32_t nwn_objid_t;
typedef uint32_t implelemnt32;

#define VAR_TYPE_INT 1
#define VAR_TYPE_FLT 2
#define VAR_TYPE_STR 3
#define VAR_TYPE_OBJ 4
#define VAR_TYPE_LOC 5

// These are actually the addresses of the vftables
// but they work quite well because we don't have to dereference the actual object type first
#define		OBJECT_TYPE_MODULE			0x00633BF8
#define		OBJECT_TYPE_ITEM			0x006341E0
#define		OBJECT_TYPE_AREA			0x00634388
#define		OBJECT_TYPE_CREATURE		0x00633A24
#define		OBJECT_TYPE_WAYPOINT		0x006358D8
#define		OBJECT_TYPE_PLACEABLE		0x00634460
#define		OBJECT_TYPE_TRIGGER			0x00635610
#define		OBJECT_TYPE_AREA_OF_EFFECT	0x00635524
#define		OBJECT_TYPE_ENCOUNTER		0x00635728
#define		OBJECT_TYPE_STORE			0x006337B4
#define		OBJECT_TYPE_DOOR			0x006345A8
#define		OBJECT_TYPE_PLAYERTURD		0x00633C74


#define AC_DODGE		0
#define AC_NATURAL		1
#define AC_ARMOUR		2
#define AC_SHIELD		3
#define AC_DEFLECTION	4

#define EVENT_CREATURE_HEARTBEAT		1
#define EVENT_CREATURE_PERCEPTION		2
#define EVENT_CREATURE_SPELLCASTAT		3
#define EVENT_CREATURE_ATTACKED			4
#define EVENT_CREATURE_DAMAGED			5
#define EVENT_CREATURE_DISTURBED		6
#define EVENT_CREATURE_ENDCOMBAT		7
#define EVENT_CREATURE_DIALOG			8
#define EVENT_CREATURE_RESTED			9
#define EVENT_CREATURE_SPAWN			10
#define EVENT_CREATURE_DEATH			11
#define EVENT_CREATURE_USERDEFINDED		12
#define EVENT_CREATURE_BLOCKED			13

#define EVENT_AREA_HEARTBEAT			0
#define EVENT_AREA_USERDEFINED			1
#define EVENT_AREA_ONENTER				2
#define EVENT_AREA_ONEXIT				3

#define EVENT_PLACEABLE_CLOSED			0
#define EVENT_PLACEABLE_DAMAGED			1
#define EVENT_PLACEABLE_DEATH			2
#define EVENT_PLACEABLE_DISARM			3
#define EVENT_PLACEABLE_HEARTBEAT		4
#define EVENT_PLACEABLE_DISTURBED		5
#define EVENT_PLACEABLE_ONLOCK			6
#define EVENT_PLACEABLE_ATTACKED		7
#define EVENT_PLACEABLE_OPEN			8
#define EVENT_PLACEABLE_ONDIALOG		9
#define EVENT_PLACEABLE_SPELLCASTAT		10
#define EVENT_PLACEABLE_ONUNLOCK		11
#define EVENT_PLACEABLE_USED			12
#define EVENT_PLACEABLE_USERDEFINED		13
#define EVENT_PLACEABLE_TRAPTRIGGERED	14
#define EVENT_PLACEABLE_ONCLICK			15

#define EVENT_AOE_HEARTBEAT				0
#define EVENT_AOE_USERDEFINED			1
#define EVENT_AOE_ONENTER				2
#define EVENT_AOE_ONEXIT				3

#define ITEM_VALUE_IDENTIFIED 1
#define ITEM_VALUE_UNIDENTIFIED 2
#define ITEM_VALUE_ADDITIONAL 3

#define ABILITY_STR = 0;
#define ABILITY_DEX = 1;
#define ABILITY_CON = 2;
#define ABILITY_INT = 3;
#define ABILITY_WIS = 4;
#define ABILITY_CHA = 5;

#endif