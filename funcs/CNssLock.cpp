#include "stdafx.h"
#include "CNssLock.h"

CNssLock::CNssLock(void) {
	AddFunction("GETAUTOREMOVEKEY", L_CAST(&CNssLock::GetAutoRemoveKey));
	AddFunction("SETAUTOREMOVEKEY", L_CAST(&CNssLock::SetAutoRemoveKey));
}

int CNssLock::GetAutoRemoveKey(CGameObject *oObject, char *Params) {
	if (oObject->obj_type2 == OBJECT_TYPE2_DOOR) {
		sprintf (Params, "%d", oObject->AsNWSDoor()->AutoRemoveKey);
		return 1;
	}
	else if (oObject->obj_type2 = OBJECT_TYPE2_PLACEABLE) {
		sprintf (Params, "%d", oObject->AsNWSPlaceable()->plc_auto_remove_key);
		return 1;
	}
	else sprintf(Params, "0");
	return 1;
}

int CNssLock::SetAutoRemoveKey(CGameObject *oObject, char *Params) {
	uint8_t bRemoveKey = 0;
	CParams::ExtractP1(Params, bRemoveKey);

	if (oObject->obj_type2 == OBJECT_TYPE2_DOOR) {
		oObject->AsNWSDoor()->AutoRemoveKey = bRemoveKey;
		return 1;
	}
	else if (oObject->obj_type2 = OBJECT_TYPE2_PLACEABLE) {
		oObject->AsNWSPlaceable()->plc_auto_remove_key = bRemoveKey;
		return 1;
	}
	else sprintf(Params, "-1");
	return 1;
}