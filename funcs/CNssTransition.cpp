#include "stdafx.h"
#include "CNssTransition.h"

CNssTransition::CNssTransition(void) {
	AddFunction("GETDESTINATIONTAG", L_CAST(&CNssTransition::GetDestinationTag));
	AddFunction("SETDESTINATIONTAG", L_CAST(&CNssTransition::SetDestinationTag));
}

int CNssTransition::GetDestinationTag(CGameObject *oObject, char *Params) {
	CExoString *DestTag = NULL;
	if (oObject->AsNWSDoor()) {
		DestTag = &oObject->AsNWSDoor()->LinkedToTag;
	}
	else if (oObject->AsNWSTrigger()) {
		DestTag = &oObject->AsNWSTrigger()->LinkedTo;
	}
	else {
		sprintf(Params, "");
		return 0;
	}
	if (DestTag && DestTag->text) {
		sprintf(Params, "%s", DestTag->text);
	}
	else sprintf(Params, "");
	return 1;
}

int CNssTransition::SetDestinationTag(CGameObject *oObject, char *Params) {
	CExoString *DestTag = NULL;
	if (oObject->AsNWSDoor()) {
		DestTag = &oObject->AsNWSDoor()->LinkedToTag;
	}
	else if (oObject->AsNWSTrigger()) {
		DestTag = &oObject->AsNWSTrigger()->LinkedTo;
	}
	else {
		sprintf(Params, "-1");
		return 0;
	}
	*DestTag = Params;
	return 1;
}
