#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"
#include "nwn_const.h"

CNWSItem *CGameObject_s::AsNWSItem() {
	if (obj_type2 == OBJECT_TYPE2_ITEM)
		return ((CNWSItem*)((char*)this-0x10));
	return NULL;
}

CNWSModule *CGameObject_s::AsModule() {
	if (obj_type2 == OBJECT_TYPE2_MODULE)
		return ((CNWSModule*)((char*)this-0x1C));
	return NULL;
}

CNWSAreaOfEffectObject *CGameObject_s::AsNWSAreaOfEffectObject() {
	if (obj_type2 == OBJECT_TYPE2_AREA_OF_EFFECT)
		return (CNWSAreaOfEffectObject*)this;
	return NULL;
}

CNWSArea *CGameObject_s::AsNWSArea() {
	if (obj_type2 == OBJECT_TYPE2_AREA)
		return ((CNWSArea*)((char*)this-0xC4));
	return NULL;
}

CNWSStore *CGameObject_s::AsNWSStore() {
	if (obj_type2 == OBJECT_TYPE2_STORE)
		return (CNWSStore*)this;
	return NULL;
}

CNWSObject *CGameObject_s::AsNWSObject() {
	return (CNWSObject*)this;
}

CNWSDoor *CGameObject_s::AsNWSDoor() {
	if (obj_type2 == OBJECT_TYPE2_DOOR)
		return (CNWSDoor*)this;
	return NULL;
}

CNWSCreature *CGameObject_s::AsNWSCreature() {
	if (obj_type2 == OBJECT_TYPE2_CREATURE)
		return (CNWSCreature*)this;
	return NULL;
}

CNWSTrigger *CGameObject_s::AsNWSTrigger() {
	if (obj_type2 == OBJECT_TYPE2_TRIGGER)
		return (CNWSTrigger*)this;
	return NULL;
}

CNWSPlaceable *CGameObject_s::AsNWSPlaceable() {
	if (obj_type2 == OBJECT_TYPE2_PLACEABLE)
		return (CNWSPlaceable*)this;
	return NULL;
}

CNWSWaypoint *CGameObject_s::AsNWSWaypoint() {
	if (obj_type2 == OBJECT_TYPE2_WAYPOINT)
		return (CNWSWaypoint*)this;
	return NULL;
}

CNWSEncounter *CGameObject_s::AsNWSEncounter() {
	if (obj_type2 == OBJECT_TYPE2_ENCOUNTER)
		return (CNWSEncounter*)this;
	return NULL;
}

