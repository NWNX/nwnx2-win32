#include "stdafx.h"
#include "CNssObject.h"

CNssObject::CNssObject(void) {
	AddFunction("GETDAMAGEIMMUNITY", L_CAST(&CNssObject::GetDamageImmunity));
	AddFunction("GETREGENERATION", L_CAST(&CNssObject::GetRegeneration));
	AddFunction("SETTAG", L_CAST(&CNssObject::SetTag));
	AddFunction("SETEVENT", L_CAST(&CNssObject::SetEvent));
	AddFunction("GETEVENT", L_CAST(&CNssObject::GetEvent));
	AddFunction("SETCONVERSATION", L_CAST(&CNssObject::SetConversation));
	AddFunction("GETCONVERSATION", L_CAST(&CNssObject::GetConversation));
	AddFunction("SETBODYBAG", L_CAST(&CNssObject::SetBodyBag));
	AddFunction("GETBODYBAG", L_CAST(&CNssObject::GetBodyBag));
	AddFunction("SETFACTIONID", L_CAST(&CNssObject::SetFactionID));
	AddFunction("GETFACTIONID", L_CAST(&CNssObject::GetFactionID));
}

int CNssObject::GetEventScriptInfo(int &ScriptNumber, std::string &ScriptName, int Max, char *Params) {
	if (strlen(Params) > 0) {
		std::string Param = Params;
		int Space;
		if ((Space = Param.find(" ")) != std::string::npos) {
			if (Param.length() > Space+1) {
				std::string Script = Param.substr(Space+1, std::string::npos);
				Param = Param.substr(0, Space);
				int iScript = atoi(Param.c_str());

				if (iScript >= 0 && iScript <= Max) {
					CExoString sScriptName(Script.c_str());
					sScriptName.StripNonAlphaNumeric(1, 0, 0);
					Param = sScriptName.text;
					Param = Param.substr(0, 16);

					ScriptNumber = iScript;
					ScriptName = Param;
					return 1;
				}
			}
		}
	}
	ScriptNumber = atoi(Params);
	return 1;
}

int CNssObject::GetDamageImmunity(CGameObject *oObject, char *Params) {
	CNWSObject *obj = oObject->AsNWSObject();
	if (!obj ||
	   (obj->obj_type2 != OBJECT_TYPE2_CREATURE && 
		obj->obj_type2 != OBJECT_TYPE2_PLACEABLE && 
		obj->obj_type2 != OBJECT_TYPE2_DOOR)
	) {
		_log(2, "o Error GetDamageImmunity used on invalid object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	char DamageType = 0;
	CParams::ExtractP1(Params, DamageType);

	sprintf(Params, "%d", obj->GetDamageImmunityByFlags(DamageType));
	return 1;
}

int CNssObject::GetRegeneration(CGameObject *oObject, char *Params) {
	CNWSObject *obj = oObject->AsNWSObject();

	int Type = 0;
	CParams::ExtractP1(Params, Type);

	int regen=0;
	int eff_len = obj->obj_effects_len;
	if (eff_len > 0) {
		int i=0;
		int DurType=0;
		CGameEffect *eff;
		while (i<eff_len) {
			eff = obj->obj_effects[i];
			if (eff->eff_type > EFFECT_TRUETYPE_REGENERATE) break;

			DurType = eff->eff_dursubtype & 7;
			if (eff->eff_type == EFFECT_TRUETYPE_REGENERATE && (
			Type == 1 ||
			(Type == 2 && DurType >= 3) ||
			(Type == 3 && DurType < 3))) {
				regen += eff->eff_integers[0];
			}
			i++;
		}
	}
	sprintf(Params, "%d", regen);
	return 1;
}

int CNssObject::SetTag(CGameObject *oObject, char *Params) {
	CExoString sNewTag(Params);

	CGameObject *obj = oObject->AsNWSObject();
	if (obj->obj_type2 >= OBJECT_TYPE2_AREA) {
		uint32_t oID = obj->obj_id;

		CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
		Mod->RemoveObjectFromLookupTable(obj->obj_tag, oID);
		Mod->AddObjectToLookupTable(sNewTag, oID);

		if (obj->obj_type2 == OBJECT_TYPE2_AREA) {
			CNWSArea *Area = obj->AsNWSArea();
			Area->are_tag = sNewTag;
		}
		else {
			obj->obj_tag = sNewTag;
		}
	}
	return 1;
}

int CNssObject::SetEvent(CGameObject *oObject, char *Params) {
	int iScript=0;
	std::string ScriptName = "";

	switch (oObject->obj_type) {
		case OBJECT_TYPE_CREATURE: {
			CNWSCreature *cre = ((*NWN_AppManager)->app_server->srv_internal)->GetCreatureByGameObjectID(oObject->obj_id);
			if (cre) {
				if (GetEventScriptInfo(iScript, ScriptName, 13, Params)) {
					cre->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetCreatureEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetCreatureEventScript): Invalid Creature\n");
		}break;
		case OBJECT_TYPE_AREA: {
			CNWSArea *Area = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaByGameObjectID(oObject->obj_id);
			if (Area) {
				if (GetEventScriptInfo(iScript, ScriptName, 3, Params)) {
					Area->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetAreaEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetAreaEventScript): Invalid Area\n");
		}break;
		case OBJECT_TYPE_PLACEABLE: {
			CNWSPlaceable *Plc = ((*NWN_AppManager)->app_server->srv_internal)->GetPlaceableByGameObjectID(oObject->obj_id);
			if (Plc) {
				if (GetEventScriptInfo(iScript, ScriptName, 15, Params)) {
					Plc->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetPlaceableEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetPlaceableEventScript): Invalid Placeable\n");
		}break;
		case OBJECT_TYPE_AREA_OF_EFFECT: {
			CNWSAreaOfEffectObject *AoE = ((*NWN_AppManager)->app_server->srv_internal)->GetAreaOfEffectByGameObjectID(oObject->obj_id);
			if (AoE) {
				if (GetEventScriptInfo(iScript, ScriptName, 3, Params)) {
					AoE->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetAoEEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetAoEEventScript): Invalid AoE\n");
		}break;
		case OBJECT_TYPE_DOOR: {
			CNWSDoor *Door = ((*NWN_AppManager)->app_server->srv_internal)->GetDoorByGameObjectID(oObject->obj_id);
			if (Door) {
				if (GetEventScriptInfo(iScript, ScriptName, 14, Params)) {
					Door->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetDoorEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetDoorEventScript): Invalid Door\n");
		}break;
		case OBJECT_TYPE_ENCOUNTER: {
			CNWSEncounter *Enc = ((*NWN_AppManager)->app_server->srv_internal)->GetEncounterByGameObjectID(oObject->obj_id);
			if (Enc) {
				if (GetEventScriptInfo(iScript, ScriptName, 4, Params)) {
					Enc->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetEncounterEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetEncounterEventScript): Invalid Encounter\n");
		}break;
		case OBJECT_TYPE_MODULE: {
			CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
			if (Mod) {
				if (GetEventScriptInfo(iScript, ScriptName, 17, Params)) {
					Mod->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetModuleEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetModuleEventScript): Invalid Module\n");
		}break;
		case OBJECT_TYPE_STORE: {
			CNWSStore *Store = ((*NWN_AppManager)->app_server->srv_internal)->GetStoreByGameObjectID(oObject->obj_id);
			if (Store) {
				if (GetEventScriptInfo(iScript, ScriptName, 1, Params)) {
					Store->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetStoreEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetStoreEventScript): Invalid Store\n");
		}break;
		case OBJECT_TYPE_TRIGGER: {
			CNWSTrigger *Trigger = ((*NWN_AppManager)->app_server->srv_internal)->GetTriggerByGameObjectID(oObject->obj_id);
			if (Trigger) {
				if (GetEventScriptInfo(iScript, ScriptName, 6, Params)) {
					Trigger->SetScriptName(iScript, CExoString(ScriptName.c_str()));
				}
				else _log(1, "o Error (SetTriggerEventScript): Invalid script name or constant\n");
			}
			else _log(1, "o Error (SetTriggerEventScript): Invalid Trigger\n");
		}break;
	}

	return 1;
}

int CNssObject::GetEvent(CGameObject *oObject, char *Params) {
	sprintf(Params, "-1");

	int Script = 0;
	CParams::ExtractP1(Params, Script);
	
	switch (oObject->obj_type) {
		case OBJECT_TYPE_CREATURE: {
			CNWSCreature *cre = oObject->AsNWSCreature();
			if (cre && Script >= 0 && Script < 16) {
				void *p = ((char*)&cre->cre_events.onHeartbeat)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type creature\n");
			}
		} break;
		case OBJECT_TYPE_AREA: {
			CNWSArea *Area = oObject->AsNWSArea();
			if (Area && Script >= 0 && Script < 4) {
				void *p = ((char*)&Area->are_script_hb)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for area\n");
			}
		}break;
		case OBJECT_TYPE_PLACEABLE: {
			CNWSPlaceable *Plc = oObject->AsNWSPlaceable();
			if (Plc && Script >= 0 && Script < 17) {
				void *p = ((char*)&Plc->OnClosed)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type placeable\n");
			}
		}break;
		case OBJECT_TYPE_AREA_OF_EFFECT: {
			CNWSAreaOfEffectObject *AoE = oObject->AsNWSAreaOfEffectObject();
			if (AoE && Script >= 0 && Script < 4) {
				void *p = ((char*)&AoE->OnHeartbeat)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type AoE\n");
			}
		}break;
		case OBJECT_TYPE_DOOR: {
			CNWSDoor *Door = oObject->AsNWSDoor();
			if (Door && Script >= 0 && Script < 15) {
				void *p = ((char*)&Door->OnOpen)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Door\n");
			}
		}break;
		case OBJECT_TYPE_ENCOUNTER: {
			CNWSEncounter *Enc = oObject->AsNWSEncounter();
			if (Enc && Script >= 0 && Script < 5) {
				void *p = ((char*)&Enc->OnEntered)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Encounter\n");
			}
		}break;
		case OBJECT_TYPE_MODULE: {
			CNWSModule *Mod = oObject->AsModule();
			if (Mod && Script >= 0 && Script < 18) {
				void *p = ((char*)&Mod->Mod_OnHeartbeat)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Module\n");
			}
		}break;
		case OBJECT_TYPE_STORE: {
			CNWSStore *Store = oObject->AsNWSStore();
			if (Store && Script >= 0 && Script < 2) {
				void *p = ((char*)&Store->OnOpenStore)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Store\n");
			}
		}break;
		case OBJECT_TYPE_TRIGGER: {
			CNWSTrigger *Trigger = oObject->AsNWSTrigger();
			if (Trigger && Script >= 0 && Script < 7) {
				void *p = ((char*)&Trigger->OnHeartbeat)+ Script * 8;
				sprintf(Params, "%s", ((CExoString*)p)->text);
			}
			else {
				_log(2, "o Error (GetEvent): Could not get event for object type Trigger\n");
			}
		}break;
		default:
			_log(2, "o Error (GetEvent): Invalid Object Type\n");
			sprintf(Params, "-1");
			return 0;
		break;
	}

	if (strcmp(Params, "(null)") == 0) sprintf(Params, "");
	return 1;
}

int CNssObject::SetConversation(CGameObject *oObject, char *Params) {
	size_t len = strlen(Params);
	if (len > 16) len = 16;

	switch(oObject->obj_type) {
		case OBJECT_TYPE_CREATURE: 
			memset(((CNWSCreature*)oObject)->cre_stats->cs_conv, 0, 16);
			memcpy_s(((CNWSCreature*)oObject)->cre_stats->cs_conv, len, Params, len);
		break;
		case OBJECT_TYPE_PLACEABLE: 
			memset(((CNWSPlaceable*)oObject)->plc_conv, 0, 16);
			memcpy_s(((CNWSPlaceable*)oObject)->plc_conv, len, Params, len);
		break;
		default :
			sprintf(Params, "-1");
			return 0;
		break;
	}
	
	return 1;
}

int CNssObject::GetConversation(CGameObject *oObject, char *Params) {
    size_t len = strlen(Params);
	if (len > 16) len = 16;

	switch(((CGameObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE: 
			memcpy(Params, ((CNWSCreature*)oObject)->cre_stats->cs_conv, len); 
		break;
		case OBJECT_TYPE_PLACEABLE:
			memcpy(Params, ((CNWSPlaceable*)oObject)->plc_conv, len);
		break;
		default : 
			sprintf(Params, "-1");
			return 0;
		break;
	}

	Params[len] = 0;

	return 1;
}

int CNssObject::SetBodyBag(CGameObject *oObject, char *Params) {
	uint8_t BodyBag = 0;
	CParams::ExtractP1(Params, BodyBag);

	if (BodyBag < 0) BodyBag = 0;
	if (BodyBag > 255) BodyBag = 255;
	switch(oObject->obj_type) {
		case OBJECT_TYPE_CREATURE: ((CNWSCreature*)oObject)->cre_bodybag = BodyBag; break;
		case OBJECT_TYPE_PLACEABLE: ((CNWSPlaceable*)oObject)->plc_bodybag = BodyBag; break;
		default:
			sprintf(Params, "-1");
			_log(2, "o Error (SetBodyBag): Could not set bodybag type for given object type.\n");
		break;
	}
	return 1;
}

int CNssObject::GetBodyBag(CGameObject *oObject, char *Params) {
	sprintf(Params, "-1");
	switch(oObject->obj_type) {
		case OBJECT_TYPE_CREATURE: sprintf(Params, "%d", ((CNWSCreature*)oObject)->cre_bodybag);
		case OBJECT_TYPE_PLACEABLE: sprintf(Params, "%d", ((CNWSPlaceable*)oObject)->plc_bodybag);
		default: 
			sprintf(Params, "-1");
			_log(2, "o Error (GetBodyBag): Could not get bodybag type for given object type.\n");
		break;
	}
	return 1;
}

int CNssObject::GetFactionID(CGameObject *oObject, char *Params) {
	sprintf(Params, "-1");
	uint32_t Faction = -1;

	(*NWN_AppManager)->app_server->srv_internal->GetFactionOfObject(oObject->obj_id, &Faction);

	sprintf(Params, "%d", Faction);

	return 1;
}

int CNssObject::SetFactionID(CGameObject *oObject, char *Params) {
	sprintf(Params, "-1");
	return 0;

	//deprecated until I can figure out how to actually change factions
	//factions are a little more involved than this

	if (!oObject->AsNWSCreature()) {
		sprintf(Params, "");
		_log(2, "o Error: SetFactionID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreature*)oObject)->cre_stats->cs_faction_id = 0/*P1*/;

	return 1;
}