#include "stdafx.h"
#include "CNssServer.h"

CNssServer::CNssServer(void) {
	AddFunction("CLEARTURDLIST", L_CAST(&CNssServer::ClearTURDList));
	AddFunction("GETWORLDTIME", L_CAST(&CNssServer::GetWorldTime));
	AddFunction("SETWORLDTIME", L_CAST(&CNssServer::SetWorldTime));
}

int CNssServer::ClearTURDList(CGameObject *oObject, char *Params) {
	CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	
	CNWSPlayerTURD *TURD = NULL;
	
	CExoLinkedListElement *Element = Mod->mod_PlayerTURDList.GetHeadPos();
	while (Element) {
		TURD = (CNWSPlayerTURD*)Element->Data;
		Mod->mod_PlayerTURDList.Remove(Element);

		TURD->ScalarDestructor(1);

		Element = Mod->mod_PlayerTURDList.GetHeadPos();
	}

	return 1;
}

int CNssServer::GetWorldTime(CGameObject *oObject, char *Params) {
	uint32_t wtDate, wtTime;

	(*NWN_AppManager)->app_server->srv_internal->srv_time_world->GetWorldTime(&wtDate, &wtTime);

	int TimeOnly = 0;
	CParams::ExtractP1(Params, TimeOnly);

	//return time only
	if (TimeOnly == 0) sprintf_s(Params, strlen(Params), "%ld", wtTime);
	else sprintf_s(Params, strlen(Params), "%ld", wtDate);

	return 1;
}

int CNssServer::SetWorldTime(CGameObject *oObject, char *Params) {
	uint32_t wtTime = 0;
	uint32_t wtDate = 0;
	int P3 = 0;
	CParams::ExtractP3(Params, wtDate, wtTime, P3);
	
	(*NWN_AppManager)->app_server->srv_internal->srv_time_world->SetWorldTime(wtDate, wtTime, P3);

	return 1;
}