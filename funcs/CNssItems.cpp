#include "stdafx.h"
#include "CNssItems.h"

CNssItems::CNssItems(void) {
	AddFunction("SETITEMVALUE", L_CAST(&CNssItems::SetItemValue));
	AddFunction("SETITEMWEIGHT", L_CAST(&CNssItems::SetItemWeight));
	AddFunction("SETITEMCHARGES", L_CAST(&CNssItems::SetItemCharges));
	AddFunction("GETITEMVALUE", L_CAST(&CNssItems::GetItemValue));
}

int CNssItems::SetItemWeight(CGameObject *oObject, char *Params) {
	CNWSItem *Item = oObject->AsNWSItem();

	if (!Item) {
		_log(2, "o Error SetItemWeight used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint32_t Weight = 0;
	CParams::ExtractP1<uint32_t>(Params, Weight);
	
	Item->it_weight = Weight;

	//_log(3, "PossessorID: %08X\n", Item->it_container_obj);
	CNWSObject *Possessor = (CNWSObject*)(*NWN_AppManager)->app_server->GetGameObject(Item->it_container_obj);
	if (Possessor) {
		//_log(3, "Possessor: %08X\n", Possessor->obj_type);
		if (Possessor->obj_type == OBJECT_TYPE_ITEM) {
			Possessor = (CNWSObject*)(*NWN_AppManager)->app_server->GetGameObject(((CNWSItem*)Possessor)->it_container_obj);
		}
		if (Possessor->obj_type == OBJECT_TYPE_CREATURE) {
			((CNWSCreature*)Possessor)->UpdateEncumbranceState(1);
		}
	}

	return 1;
}

int CNssItems::SetItemValue(CGameObject *oObject, char *Params) {
	CNWSItem *Item = oObject->AsNWSItem();
	if (!Item) {
		_log(2, "o Error SetItemValue used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint32_t Value, ValueType, ZeroAdditionalValue;
	CParams::ExtractP3<uint32_t>(Params, Value, ValueType, ZeroAdditionalValue);

	if (Value < 0) Value = 0;

	switch (ValueType) {
		case ITEM_VALUE_IDENTIFIED	: 
			Item->it_cost_ided = Value; 
			if (ZeroAdditionalValue) Item->it_cost_add = 0; 
		break;
		case ITEM_VALUE_UNIDENTIFIED: Item->it_cost_unided = Value; break;
		case ITEM_VALUE_ADDITIONAL	: Item->it_cost_add = Value; break;
	}

	return 1;
}

int CNssItems::SetItemCharges(CGameObject *oObject, char *Params) {
	CNWSItem *Item = oObject->AsNWSItem();
	if (!Item) {
		_log(2, "o Error SetItemCharges used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Charges = 0;
	CParams::ExtractP1<uint8_t>(Params, Charges);

	if (Charges < 0) Charges = 0;
	if (Charges > 255) Charges = 255;

	Item->it_charges = Charges;

	return 1;
}

int CNssItems::GetItemValue(CGameObject *oObject, char *Params) {
	sprintf(Params, "-1");

	CNWSItem *Item = oObject->AsNWSItem();
	if (!Item) {
		_log(2, "o Error GetItemValue used on non-item object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int Value = -1;
	int ValueType = 0;
	CParams::ExtractP1<int>(Params, ValueType);

	switch (ValueType) {
		case ITEM_VALUE_IDENTIFIED:   Value = Item->it_cost_ided; break;
		case ITEM_VALUE_UNIDENTIFIED: Value = Item->it_cost_unided; break;
		case ITEM_VALUE_ADDITIONAL	: Value = Item->it_cost_add; break;
	}

	sprintf(Params, "%d", Value);

	return 1;
}