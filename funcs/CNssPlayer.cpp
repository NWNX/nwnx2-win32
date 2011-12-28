#include "stdafx.h"
#include "CNssPlayer.h"

CNssPlayer::CNssPlayer(void) {
	AddFunction("SETQUICKSLOT", L_CAST(&CNssPlayer::SetQuickSlot));
	AddFunction("GETQUICKSLOT", L_CAST(&CNssPlayer::GetQuickSlot));
	AddFunction("UPDATEQUICKBAR", L_CAST(&CNssPlayer::UpdateQuickbar));
	AddFunction("TIMEBARSTART", L_CAST(&CNssPlayer::TimebarStart));
	AddFunction("TIMEBARSTOP", L_CAST(&CNssPlayer::TimebarStop));
	AddFunction("UPDATECHARSHEET", L_CAST(&CNssPlayer::UpdateCharSheet));
	AddFunction("POSSESSCREATURE", L_CAST(&CNssPlayer::PossessCreature));
	AddFunction("BOOTPCWITHMESSAGE", L_CAST(&CNssPlayer::BootPCWithMessage));
}

void CNssPlayer::UpdateQuickBar(CGameObject* obj) {
	CNWSPlayer *pl = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(obj->obj_id);

	if (pl != NULL) {
		((*NWN_AppManager)->app_server->srv_internal->srv_client_messages)->SendServerToPlayerGuiQuickbar_SetButton(pl, 0, 1);
	}
}

int CNssPlayer::SetQuickSlot(CGameObject *oObject, char *Params) {
    int slot, qb_type, qb_class, qb_id, qb_meta, bUpdate;
    CNWSCreature *cre;
	std::string s = Params;
	int iP;

    if (oObject == NULL                               ||
        !(cre = oObject->AsNWSCreature())			  ||
        !cre->cre_is_pc                               ||
        cre->cre_quickbar == NULL)
        //sscanf(Params, "%d %d %d %d %d %d¬%s¬%s", &slot, &qb_type, &qb_class, &qb_id, &qb_meta, &bUpdate) != 6 ||
    {

        sprintf_s(Params, strlen(Params), "-1");
        return 0;
    }

	iP = s.find("¬");

	if (iP == -1) {
		if ((sscanf((s.c_str()), "%d %d %d %d %d %d", &slot, &qb_type, &qb_class, &qb_id, &qb_meta, &bUpdate) != 6)
			|| slot < 0 || slot >= 36) {
			sprintf(Params, "-2");
			return 0;
		}
	}
	else {
		if ((sscanf((s.substr(0, iP).c_str()), "%d %d %d %d %d %d", &slot, &qb_type, &qb_class, &qb_id, &qb_meta, &bUpdate) != 6)
			|| slot < 0 || slot >= 36) {
			sprintf(Params, "-2");
			return 0;
		}
	}

	if (qb_type == 1) { // can't do items
		sprintf(Params, "-1");
		return 0;
	}

	std::string s2;
	if (iP > 0) {
		s2 = s.substr(iP+1);
		s = s2.substr(s2.find("¬")+1);
		s2 = s2.substr(0, s2.find("¬"));
	}
	else {
		s = "";
		s2 = "";
	}

	CNWSQuickbarButton *button = &cre->cre_quickbar[slot];

	//if quickslot contains strings, free their memory first
	switch (button->qb_type) {
		case 18: {
			free(button->qb_label.text); button->qb_label.text = NULL;
			button->qb_label.len = 0;
			free(button->qb_command.text); button->qb_command.text = NULL;
			button->qb_command.len = 0;
		} break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: {//dm creator stuff
			free(button->qb_label2.text); button->qb_label2.text = NULL;
			button->qb_label2.len = 0;
		} break;
	}

	// put the new data in
	switch (qb_type) {
		case 18: {
			if (s.length() > 0 && s2.length() > 0) {
				button->qb_label.len = s2.length()+1;
				button->qb_label.text = (char*)malloc(button->qb_label.len);
				sprintf_s(button->qb_label.text, button->qb_label.len, "%s", s2.c_str());
				
				button->qb_command.len = s.length()+1;
				button->qb_command.text = (char*)malloc(button->qb_command.len);
				sprintf_s(button->qb_command.text, button->qb_command.len, "%s", s.c_str());
			}
			else {
				qb_type = 0;
				qb_class = 0;
				qb_id = 0;
				qb_meta = 0;
			}
		} break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: {//dm creator stuff
			if (s.length() > 0 && s2.length() > 0) {
				button->qb_label2.len = s2.length()+1;
				button->qb_label2.text = (char*)malloc(button->qb_label2.len);
				sprintf_s(button->qb_label2.text, button->qb_label2.len, "%s", s2.c_str());

				int i=0;
				s = s.substr(0,16);
				sprintf_s(button->qb_resref, "%s", s.c_str());
			}
			else {
				qb_type = 0;
				qb_class = 0;
				qb_id = 0;
				qb_meta = 0;
			}
		} break;
	}

	qb_class--;
	qb_class = qb_class < 0 ? 0 : qb_class > 2 ? 2 : qb_class;
	button->qb_type      = qb_type;
	button->qb_class     = qb_class;
	button->qb_id        = qb_id;
	button->qb_metamagic = qb_meta;

	if (bUpdate) UpdateQuickBar(oObject);

	return 1;
}

int CNssPlayer::GetQuickSlot(CGameObject *oObject, char *Params) {
    int slot = 0;
	CParams::ExtractP1(Params, slot);

    const CNWSCreature *cre = NULL;

    if (oObject == NULL                               ||
        !(cre = oObject->AsNWSCreature())			  ||
        !cre->cre_is_pc                               ||
        cre->cre_quickbar == NULL                     ||
        (slot < 0 || slot >= 36)) {

        sprintf(Params, "-1");
        return 0;
    }

	if (cre->cre_quickbar[slot].qb_type == 1) { // can't do items
		sprintf(Params, "-1");
		return 0;
	}

	switch(cre->cre_quickbar[slot].qb_type) {
		case 18: {
			sprintf_s(Params, strlen(Params), "%d¬%d¬0¬0¬0¬%s¬%s", 
				slot,
				cre->cre_quickbar[slot].qb_type,
				cre->cre_quickbar[slot].qb_label.text,
				cre->cre_quickbar[slot].qb_command.text
			);
		} break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: {//dm creator stuff
			sprintf_s(Params, strlen(Params), "%d¬%d¬0¬0¬0¬%s¬%s", 
				slot,
				cre->cre_quickbar[slot].qb_type,
				cre->cre_quickbar[slot].qb_label2.text,
				cre->cre_quickbar[slot].qb_resref
			);
		} break;
		default: {
			sprintf_s(Params, strlen(Params), "%d¬%d¬%d¬%d¬%d", 
				slot,
				cre->cre_quickbar[slot].qb_type,
				cre->cre_quickbar[slot].qb_class,
				cre->cre_quickbar[slot].qb_id,
				cre->cre_quickbar[slot].qb_metamagic
			);
		}break;
	}

	return 1;
}

int CNssPlayer::UpdateQuickbar(CGameObject *oObject, char *Params) {
	if (!oObject->AsNWSCreature()) {
		_log(2, "o Error: UpdateQuickbar used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	UpdateQuickBar(oObject);
	return 1;
}

int CNssPlayer::TimebarStart(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: TimebarStart used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	unsigned long Duration = 0;
	unsigned char Label = 0;
	CParams::ExtractP2(Params, Duration, Label);


	cre->StartGuiTimingBar(Duration, Label);

	return 1;
}

int CNssPlayer::TimebarStop(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error: TimebarStop used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	cre->StopGuiTimingBar();
	return 1;
}

int CNssPlayer::UpdateCharSheet(CGameObject *oObject, char *Params) {
	uint32_t player_id = 0;
	CParams::ExtractP1(Params, player_id);

	CNWSPlayer *Player = (*NWN_AppManager)->app_server->GetClientObjectByObjectId(player_id);

	if (Player != NULL) {
		CNWSPlayerCharSheetGUI *CharSheet = (CNWSPlayerCharSheetGUI*)(((char*)Player)+0x60);
		uint32_t msg = CharSheet->ComputeCharacterSheetUpdateRequired(Player);
		if (msg) {
			((*NWN_AppManager)->app_server->srv_internal->srv_client_messages)->WriteGameObjUpdate_CharacterSheet(Player, msg);
		}
	}
	return 1;
}

int CNssPlayer::PossessCreature(CGameObject *oObject, char *Params) {
	CNWSCreature *Possessor = oObject->AsNWSCreature();
	if (!Possessor) {
		_log(2, "o Error: PossessCreature used with invalid Possessor.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int oID_Possessee = 0;
	CParams::ExtractP1(Params, oID_Possessee);

	_log(3, "Possessor: %08X\tPossessee: %08X\n", Possessor->obj_id, oID_Possessee);
	Possessor->PossessCreature(oID_Possessee);
	return 1;
}

int CNssPlayer::BootPCWithMessage(CGameObject *oObject, char *Params) {
	int iMsg = 0;
	CParams::ExtractP1(Params, iMsg);
	CNWSObject *obj = oObject->AsNWSObject();

	nwn_objid_t plID = obj->obj_id;
	CNWSPlayer* pPlayer = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(plID);
	if(pPlayer != NULL) {
		uint32_t pID = pPlayer->pl_id;
		CNetLayer* netlayer = (*NWN_AppManager)->app_server->srv_internal->srv_network;

		netlayer->DisconnectPlayer(pID, iMsg, 1);
		return 1;
	}
	return 0; 
}
