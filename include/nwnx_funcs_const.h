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

#define EVENT_CREATURE_HEARTBEAT		0
#define EVENT_CREATURE_PERCEPTION		1
#define EVENT_CREATURE_SPELLCASTAT		2
#define EVENT_CREATURE_ATTACKED			3
#define EVENT_CREATURE_DAMAGED			4
#define EVENT_CREATURE_DISTURBED		5
#define EVENT_CREATURE_ENDCOMBAT		6
#define EVENT_CREATURE_DIALOG			7
#define EVENT_CREATURE_RESTED			8
#define EVENT_CREATURE_SPAWN			9
#define EVENT_CREATURE_DEATH			10
#define EVENT_CREATURE_USERDEFINDED		11
#define EVENT_CREATURE_BLOCKED			12
                                         
#define EVENT_AREA_HEARTBEAT			0
#define EVENT_AREA_USERDEFINED			1
#define EVENT_AREA_ENTER				2
#define EVENT_AREA_EXIT					3
                                         
#define EVENT_PLACEABLE_CLOSED			0
#define EVENT_PLACEABLE_DAMAGED			1
#define EVENT_PLACEABLE_DEATH			2
#define EVENT_PLACEABLE_DISARM			3
#define EVENT_PLACEABLE_HEARTBEAT		4
#define EVENT_PLACEABLE_DISTURBED		5
#define EVENT_PLACEABLE_LOCK			6
#define EVENT_PLACEABLE_ATTACKED		7
#define EVENT_PLACEABLE_OPEN			8
#define EVENT_PLACEABLE_SPELLCASTAT		9
#define EVENT_PLACEABLE_TRAPTRIGGERED	10
#define EVENT_PLACEABLE_UNLOCK			11
#define EVENT_PLACEABLE_USED			12
#define EVENT_PLACEABLE_USERDEFINED		13
#define EVENT_PLACEABLE_DIALOG			14
#define EVENT_PLACEABLE_CLICK			15
                                         
#define EVENT_AOE_HEARTBEAT				0
#define EVENT_AOE_USERDEFINED			1
#define EVENT_AOE_ENTER					2
#define EVENT_AOE_EXIT					3
                                         
#define EVENT_DOOR_OPEN					0
#define EVENT_DOOR_CLOSED				1
#define EVENT_DOOR_DAMAGED				2
#define EVENT_DOOR_DEATH				3
#define EVENT_DOOR_DISARM				4
#define EVENT_DOOR_HEARTBEAT			5
#define EVENT_DOOR_LOCK					6
#define EVENT_DOOR_ATTACKED				7
#define EVENT_DOOR_SPELLCASTAT			8
#define EVENT_DOOR_TRAPTRIGGERED		9
#define EVENT_DOOR_UNLOCK				10
#define EVENT_DOOR_USERDEFINED			11
#define EVENT_DOOR_CLICK				12
#define EVENT_DOOR_DIALOG				13
#define EVENT_DOOR_FAILTOOPEN			14
                                         
#define EVENT_ENCOUNTER_ENTERED         0
#define EVENT_ENCOUNTER_EXIT            1
#define EVENT_ENCOUNTER_HEARTBEAT       2
#define EVENT_ENCOUNTER_EXHAUSTED       3
#define EVENT_ENCOUNTER_USERDEFINED     4
                                         
#define EVENT_MODULE_Heartbeat			0
#define EVENT_MODULE_UsrDefined			1
#define EVENT_MODULE_ModLoad			2
#define EVENT_MODULE_ModStart			3
#define EVENT_MODULE_ClientEntr			4
#define EVENT_MODULE_ClientLeav			5
#define EVENT_MODULE_ActvtItem			6
#define EVENT_MODULE_AcquirItem			7
#define EVENT_MODULE_UnAqreItem			8
#define EVENT_MODULE_PlrDeath			9
#define EVENT_MODULE_PlrDying			10
#define EVENT_MODULE_SpawnBtnDn			11
#define EVENT_MODULE_PlrRest			12
#define EVENT_MODULE_PlrLvlUp			13
#define EVENT_MODULE_CutsnAbort			14
#define EVENT_MODULE_PlrEqItm			15
#define EVENT_MODULE_PlrUnEqItm			16
#define EVENT_MODULE_PlrChat			17
                                         
#define EVENT_STORE_OPENSTORE			0
#define EVENT_STORE_CLOSESTORE			1
                                         
#define EVENT_TRIGGER_HEARTBEAT			0
#define EVENT_TRIGGER_ENTER		    	1
#define EVENT_TRIGGER_EXIT		    	2
#define EVENT_TRIGGER_USERDEFINED		3
#define EVENT_TRIGGER_TRAPTRIGGERED		4
#define EVENT_TRIGGER_DISARM			5
#define EVENT_TRIGGER_CLICK				6

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