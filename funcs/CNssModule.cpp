#include "stdafx.h"
#include "CNssModule.h"

CNssModule::CNssModule(void) {
	AddFunction("GETTIMEOFDAY", L_CAST(&CNssModule::GetTimeOfDay));
}

int CNssModule::GetTimeOfDay(CGameObject *oObject, char *Params) {
	CNWSModule *Mod = (*NWN_AppManager)->app_server->srv_internal->GetModule();
	if (Mod) {
		sprintf(Params, "%d", Mod->mod_timeofday);
		return 1;
	}
	sprintf(Params, "-1");
	return 0;
}