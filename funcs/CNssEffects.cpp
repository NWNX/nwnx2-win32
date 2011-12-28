#include "stdafx.h"
#include "CNssEffects.h"

CNssEffects::CNssEffects(void) {
	AddFunction("GETALLEFFECTREMAININGDURATION", L_CAST(&CNssEffects::GetAllEffectRemainingDuration));
	AddFunction("GETHIGHESTEFFECTID", L_CAST(&CNssEffects::GetHighestEffectID));
	AddFunction("GETFIRSTALLEFFECT", L_CAST(&CNssEffects::GetFirstAllEffect));
	AddFunction("GETNEXTALLEFFECT", L_CAST(&CNssEffects::GetNextAllEffect));
	AddFunction("GETALLEFFECTINTEGERS", L_CAST(&CNssEffects::GetAllEffectInts));
	AddFunction("SETALLEFFECTINTEGERS", L_CAST(&CNssEffects::SetAllEffectInts));
	AddFunction("GETALLEFFECTID", L_CAST(&CNssEffects::GetAllEffectID));
	AddFunction("GETALLEFFECTTYPE", L_CAST(&CNssEffects::GetAllEffectType));
	AddFunction("GETALLEFFECTSUBTYPE", L_CAST(&CNssEffects::GetAllEffectSubType));
	AddFunction("GETALLEFFECTCREATOR", L_CAST(&CNssEffects::GetAllEffectCreator));
	AddFunction("GETALLEFFECTSPELLID", L_CAST(&CNssEffects::GetAllEffectSpellID));
	AddFunction("GETALLEFFECTDURATIONTYPE", L_CAST(&CNssEffects::GetAllEffectDurationType));
	AddFunction("QUEUEREMOVEEFFECT", L_CAST(&CNssEffects::QueueRemoveEffect));
	AddFunction("REMOVEQUEUEDEFFECTS", L_CAST(&CNssEffects::RemoveQueuedEffects));
	AddFunction("GETEFFECTINTEGERS", L_CAST(&CNssEffects::GetEffectInts));
	AddFunction("SETEFFECTINTEGERS", L_CAST(&CNssEffects::SetEffectInt));
	AddFunction("GETEFFECTID", L_CAST(&CNssEffects::GetEffectID));
	AddFunction("GETEFFECTREALTYPE", L_CAST(&CNssEffects::GetEffectRealType));
	AddFunction("GETEFFECTREMAININGDURATION", L_CAST(&CNssEffects::GetEffectRemainingDuration));
	AddFunction("GETEFFECTDURATIONSUBTYPE", L_CAST(&CNssEffects::GetEffectDurationSubType));
	AddFunction("PRINTEFFECTS", L_CAST(&CNssEffects::PrintEffects));
	AddFunction("SETEFFECTCREATORBYEFFECTID", L_CAST(&CNssEffects::SetEffectCreatorByEffectID));
	AddFunction("SETEFFECTSPELLIDBYEFFECTID", L_CAST(&CNssEffects::SetEffectSpellIDByEffectID));
	AddFunction("APPLYVFXFORPC", L_CAST(&CNssEffects::ApplyVFXForPC));
}

BOOL CNssEffects::ValidEffectObject(CGameObject *oObject) {
	switch (oObject->obj_type) {
		case OBJECT_TYPE_CREATURE:
		case OBJECT_TYPE_ITEM:
		case OBJECT_TYPE_PLACEABLE:
		case OBJECT_TYPE_DOOR:
		return 1;
	}
	return 0;
}

int CNssEffects::SetEffectCreatorByID(const CNWSObject *obj, const nwn_objid_t &Creator, const int &EffectID, int bRecurse) {
	int isHaste = 0;
	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		if (obj->obj_effects[i]->eff_id == EffectID) {
			obj->obj_effects[i]->eff_creator = Creator;
			if (!bRecurse) {
				if (obj->obj_effects[i]->eff_type == EFFECT_TRUETYPE_HASTE) {
					isHaste = 1;
				}
				else if (obj->obj_effects[i]->eff_type == EFFECT_TRUETYPE_HASTE_INTERNAL) {
					isHaste = -1;
				}
			}
		}
	}
	return isHaste;
}

int CNssEffects::SetEffectSpellIDByID(const CNWSObject *obj, const int &spellid, const int &EffectID, int bRecurse) {
	int isHaste = 0;
	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		if (obj->obj_effects[i]->eff_id == EffectID) {
			obj->obj_effects[i]->eff_spellid = spellid;
			if (!bRecurse) {
				if (obj->obj_effects[i]->eff_type == EFFECT_TRUETYPE_HASTE) {
					isHaste = 1;
				}
				else if (obj->obj_effects[i]->eff_type == EFFECT_TRUETYPE_HASTE_INTERNAL) {
					isHaste = -1;
				}
			}
		}
	}
	return isHaste;
}


int CNssEffects::PrintEffects(CGameObject *oObject, char *Params) {
	const CNWSObject *obj = oObject->AsNWSObject();
	CGameEffect *eff = NULL;

	_log(0, "o Printing Effects for: %08X\n", obj->obj_id);
	unsigned int i=0;
	_log(0, "@        |\t#   |\tID      |\tType    |\tSub   |\tDurT  |\tDur        |\tExD       |\tExT       |\tCreator |\tSpellID |\tE   |\tI   |\tL\n");
	for (i=0; i< obj->obj_effects_len; i++) {
		eff = obj->obj_effects[i];
		if (eff == NULL) continue;
		_log(0, "\
%#08X\
|\t%-04i\
|\t%08X\
|\t%8i\
|\t%-6i\
|\t%-6i\
|\t%-11.6f\
|\t%-10i\
|\t%-10i\
|\t%08X\
|\t%08X\
|\t%-4i\
|\t%-4i\
|\t%-4i\
\n",
			eff,
			i, 
			eff->eff_id,
			eff->eff_type,
			eff->eff_dursubtype & 24,
			eff->eff_dursubtype & 7,
			eff->eff_duration,
			eff->eff_expire_day,
			eff->eff_expire_time,
			eff->eff_creator,
			eff->eff_spellid,
			eff->eff_is_exposed,
			eff->eff_is_iconshown,
			eff->eff_skiponload		 
			);
	}
	return 1;
}

int CNssEffects::GetFirstAllEffect(CGameObject *oObject, char *Params) {
	if (!ValidEffectObject(oObject)) {
		_log(2, "o Error: GetEffectRemainingDuration used on non-effect object.\n");
		sprintf(Params, "-1");
		getFirstNextEffectObj = OBJECT_INVALID;
		getFirstNextEffectObject = NULL;
		return 0;
	}

	CNWSObject *obj = oObject->AsNWSObject();

	CParams::ExtractP1<bool>(Params, getFirstNextEffectScriptEffect);
	getFirstNextEffectObj = obj->obj_id;
	getFirstNextEffect = NULL;
	getFirstNextEffectObject = obj;
	EffectRemovalIDs.clear();

	uint16_t durType, subType;
	BOOL bIsExposed;
	unsigned int i=0;
	for (i=0; i< obj->obj_effects_len; i++) {
		getFirstNextEffect = obj->obj_effects[i];
		if (getFirstNextEffect != NULL) {
			durType = getFirstNextEffect->eff_dursubtype & 7;
			subType = getFirstNextEffect->eff_dursubtype & 24;
			bIsExposed = getFirstNextEffect->eff_is_exposed && (durType == 1 || durType == 2);
			if ((!getFirstNextEffectScriptEffect || bIsExposed)) {
				getFirstNextEffectScriptIndex = i;
				sprintf(Params, "1");
				return 1;
			}
		}
	}
	sprintf(Params, "0");
	getFirstNextEffect = NULL;
	getFirstNextEffectScriptIndex = -1;
	getFirstNextEffectObject = NULL;

	return 1;
}

int CNssEffects::GetNextAllEffect(CGameObject *oObject, char *Params) {
	if (getFirstNextEffectObject != NULL) {
		unsigned int i = getFirstNextEffectScriptIndex;
		while(++i < getFirstNextEffectObject->obj_effects_len) {
			getFirstNextEffect = getFirstNextEffectObject->obj_effects[i];
			if (getFirstNextEffect != NULL) {
				if ((!getFirstNextEffectScriptEffect || getFirstNextEffect->eff_is_exposed && ((getFirstNextEffect->eff_dursubtype & 7) == 1 || (getFirstNextEffect->eff_dursubtype & 24) == 2))) {
					getFirstNextEffectScriptIndex = i;
					sprintf(Params, "1");
					return 1;
				}
			}
		}
	}

	sprintf(Params, "0");
	getFirstNextEffect = NULL;
	getFirstNextEffectObject = NULL;
	return 1;
}

int CNssEffects::GetAllEffectRemainingDuration(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}
    uint32_t tD, tT, eD, eT;
	int64_t current, expire;

	(*NWN_AppManager)->app_server->srv_internal->srv_time_world->GetWorldTime(&tD, &tT);
	current = (tD * 2880000LL) + tT;

	eD = getFirstNextEffect->eff_expire_day;
	eT = getFirstNextEffect->eff_expire_time;
	expire = (eD * 2880000LL) + eT;

	_log(3, "[tD: %ld | tT: %ld] current: %ld\n", tD, tT, current);
	_log(3, "[eD: %ld | eT: %ld] expire: %ld\n", eD, eT, expire);
 
	sprintf(Params, "%.2lf", (float)(expire - current)/1000.0);
	return 1;
}

int CNssEffects::GetAllEffectInts(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	int nNth = 0;
	CParams::ExtractP1<int>(Params, nNth);

	if (getFirstNextEffect->eff_num_integers < 0) {
		sprintf(Params, "");
		return 0;
	}
	else {
		if (nNth == -1) {
			char buf[11];
			size_t size = (11*getFirstNextEffect->eff_num_integers)+1;
			char *ints = new char[size];
			memset(ints, 0, size);

			for(int i=0; i<getFirstNextEffect->eff_num_integers; i++) {
				sprintf(buf, "%d¬", getFirstNextEffect->eff_integers[i]);
				strcat(ints, buf);
			}

			if (strlen(ints) > 0) {
				sprintf(Params, "%s", ints);
				delete[] ints;
			}
			else {
				sprintf(Params, "");
				delete[] ints;
			}
		}
		else {
			if (nNth < getFirstNextEffect->eff_num_integers) {
				sprintf(Params, "%d", getFirstNextEffect->eff_integers[nNth]);
			}
			else {
				sprintf(Params, "");
			}
		}
	}
	return 1;
}

int CNssEffects::SetAllEffectInts(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	int nNth = 0;
	int Value = 0;
	CParams::ExtractP2<int>(Params, nNth, Value);

	if (getFirstNextEffect->eff_num_integers < 0 || nNth > getFirstNextEffect->eff_num_integers) {
		sprintf(Params, "-1");
	}
	else {
		getFirstNextEffect->eff_integers[nNth] = Value;
		sprintf(Params, "1");
	}

	return 1;
}

int CNssEffects::GetAllEffectID(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	int iID = getFirstNextEffect->eff_id;
	sprintf(Params, "%d", iID);

	return 1;
}

int CNssEffects::GetAllEffectType(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	bool bRealType = false;
	CParams::ExtractP1<bool>(Params, bRealType);

	int iType;
	if (!bRealType) {
		iType = getFirstNextEffect->GetScriptEffectType();
	}
	else {
		iType = getFirstNextEffect->eff_type;
	}
	sprintf(Params, "%d", iType);
	return 1;
}

int CNssEffects::GetAllEffectSubType(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", (getFirstNextEffect->eff_dursubtype & 24));
	return 1;
}

int CNssEffects::GetAllEffectSpellID(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", getFirstNextEffect->eff_spellid);
	return 1;
}

int CNssEffects::GetAllEffectCreator(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%08X", getFirstNextEffect->eff_creator);
	return 1;
}

int CNssEffects::GetAllEffectDurationType(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", (getFirstNextEffect->eff_dursubtype & 7));
	return 1;
}

int CNssEffects::QueueRemoveEffect(CGameObject *oObject, char *Params) {
	if (getFirstNextEffect == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	EffectRemovalIDs.push_back(getFirstNextEffect->eff_id);
	// Haste and Slow are a problem as they create internal versions which have all the other effects (Movement Speed,
	// AC, etc) linked to them. The ID for those seems to be 1 higher
	// I hope this holds true in all cases

	if (getFirstNextEffect->eff_type == 1 || getFirstNextEffect->eff_type == 3) {
		EffectRemovalIDs.push_back(getFirstNextEffect->eff_id+1);
	}

	return 1;
}

int CNssEffects::RemoveQueuedEffects(CGameObject *oObject, char *Params) {
	uint64_t iID;

	while (!EffectRemovalIDs.empty()) {
		iID = EffectRemovalIDs.back();
		((CNWSObject*)oObject)->RemoveEffectById(iID);
		EffectRemovalIDs.pop_back();
	}
	return 1;
}

int CNssEffects::GetEffectInts(CGameObject *oObject, char *Params) {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		GetAllEffectInts(oObject, Params);
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNssEffects::SetEffectInt(CGameObject *oObject, char *Params) {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		SetAllEffectInts(oObject, Params);
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNssEffects::GetEffectRemainingDuration(CGameObject *oObject, char *Params) {
	CNWSObject *obj = (CNWSObject*)oObject;
	_log(3, "index: %08X\n", obj->obj_effect_index);
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		_log(3, "getFirstNextEffect: %08X\n", getFirstNextEffect);
		GetAllEffectRemainingDuration(oObject, Params);
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNssEffects::GetEffectID(CGameObject *oObject, char *Params) {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		GetAllEffectID(oObject, Params);
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNssEffects::GetEffectRealType(CGameObject *oObject, char *Params) {
	CNWSObject *obj = (CNWSObject*)oObject;
	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}
	else {
		getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];
		sprintf(Params, "1");
		GetAllEffectType(oObject, Params);
		getFirstNextEffect = NULL;
	}
	return 1;
}

int CNssEffects::GetHighestEffectID(CGameObject *oObject, char *Params) {
	if (!ValidEffectObject(oObject)) {
		_log(2, "o Error: GetEffectRemainingDuration used on non-effect object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSObject *obj = oObject->AsNWSObject();

	// since the effect array is sorted by effect type we have to go through it and find the highest id
	long iID = 1;
	for (unsigned int i=0; i< obj->obj_effects_len; i++) {
		if ((signed long)obj->obj_effects[i]->eff_id > iID) {
			iID = obj->obj_effects[i]->eff_id;
		}
	}

	sprintf(Params, "%d", iID);
	return 1;
}

int CNssEffects::GetEffectDurationSubType(CGameObject *oObject, char *Params) {
	CNWSObject *obj = oObject->AsNWSObject();

	if (obj->obj_effect_index < 1) {
		sprintf(Params, "-1");
		return 0;
	}

	getFirstNextEffect = obj->obj_effects[obj->obj_effect_index - 1];

	int iSubType = getFirstNextEffect->eff_dursubtype;

	getFirstNextEffect = NULL;
	sprintf(Params, "%d", iSubType);
	return 1;
}

int CNssEffects::SetEffectCreatorByEffectID(CGameObject *oObject, char *Params) {
	if (!ValidEffectObject(oObject)) {
		_log(2, "o Error: SetEffectCreatorByEffectID used on non-effect object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	const CNWSObject *obj = oObject->AsNWSObject();

	nwn_objid_t Creator = OBJECT_INVALID;
	int EffectID = 0;

	CParams::ExtractP2<int, nwn_objid_t>(Params, EffectID, Creator);

	int isHaste = SetEffectCreatorByID(obj, Creator, EffectID, true);
	if (isHaste) {
		EffectID += isHaste;
		SetEffectCreatorByID(obj, Creator, EffectID, false);
	}

	return 1;
}

int CNssEffects::SetEffectSpellIDByEffectID(CGameObject *oObject, char *Params) {
	if (!ValidEffectObject(oObject)) {
		_log(2, "o Error: SetEffectCreatorByEffectID used on non-effect object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	const CNWSObject *obj = oObject->AsNWSObject();

	int SpellID = 0;
	int EffectID = 0;

	CParams::ExtractP2<int, int>(Params, EffectID, SpellID);

	int isHaste = SetEffectSpellIDByID(obj, SpellID, EffectID, true);
	if (isHaste) {
		EffectID += isHaste;
		SetEffectSpellIDByID(obj, SpellID, EffectID, false);
	}

	return 1;
}

int CNssEffects::ApplyVFXForPC(CGameObject *oObject, char *Params) {
	CNWSObject *obj = oObject->AsNWSObject();
	
	if (obj == NULL || !oObject->AsNWSCreature()->cre_is_pc || !oObject->AsNWSCreature()->cre_is_pc) {
		_log(2, "o Error: ApplyVFXForPC used on invalid object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	nwn_objid_t plID = obj->obj_id;

	int nVFX=0;
	float Px=0.0, Py=0.0, Pz=0.0;
	//rescan Params for vfx and position floats
	if (sscanf(Params, "%d %f %f %f", &nVFX, &Px, &Py, &Pz) != 4) {
		_log(2, "o Error ApplyVFXForPC: Not enough Parameters [%s]\n", Params);
		sprintf(Params, "-1");
		return 0;
	}

	CNWSPlayer *pPlayer = ((*NWN_AppManager)->app_server)->GetClientObjectByObjectId(plID);
	
	if(((CNWSObject*)(pPlayer->GetGameObject()))->GetArea() != NULL) {
		CNWSMessage *pServerMessage = ((*NWN_AppManager)->app_server)->GetNWSMessage();
		return pServerMessage->SendServerToPlayerArea_VisualEffect(pPlayer, nVFX, Px, Py, Pz);
	}
	return 0;
}

int CNssEffects::CreateCustomEffect(int a3) {
	CNWSScriptVarTable *vartable = NULL;
	if (CustomEffectObject == NULL) {
		CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
		vartable = &Mod->mod_vartable;
	}
	else {
		vartable = &CustomEffectObject->obj_vartable;
	}


	CExoString VarName("NWNXFUNCS_CE");
	if (vartable->GetInt(VarName)) {
		CExoString *effectstruct = NULL;
		VarName = "NWNXFUNCS_CE_EFFECT";
		effectstruct = vartable->GetString(VarName);
		int NumInts=0;
		std::string Ints;
		VarName = "NWNXFUNCS_CE_NUMINTS";
		NumInts = vartable->GetInt(VarName);
		if (NumInts > 0) {
			VarName = "NWNXFUNCS_CE_INTS";
			Ints = (vartable->GetString(VarName))->text;
		}
		if (effectstruct) {
			_log(3, "%s\n", effectstruct->text);
			if (strlen(effectstruct->text) > 0) {
				int i=0;
				if (a3 <= 0 || (*NWN_VirtualMachine)->StackPopInteger(&i)) {
					int type=0, creator=0, spellid=0;
					if (sscanf(effectstruct->text, "%d %x %d", &type, &creator, &spellid) == 3) {
						_log(3, "scanned: %d %x %d\n", type, creator, spellid);

						CGameEffect *e = (CGameEffect*)malloc(0x90);
						e->ctor(1);
					
						e->eff_type = type;
						e->eff_creator = creator;
						e->eff_spellid = spellid;
						e->eff_dursubtype = e->eff_dursubtype & 0xFFEF | 8;

						_log(3, "NumInts: %d\n", NumInts);
						if (e->eff_num_integers < NumInts) {
							e->SetNumIntegers(NumInts);
						}

						int iP=0, iStart=0;
						int value;
						for (int j=0; j<NumInts; j++) {
							iP = Ints.find(" ", iStart);
							value = atoi(Ints.substr(iStart, iP-iStart).c_str());
							_log(3, "Int[%d]: %d\n", j, value);
							e->eff_integers[j] = value;
							iStart = iP+1;
						}

						if ((*NWN_VirtualMachine)->StackPushEngineStructure(0, e)) {
							if (e) {
								e->dtor();
								free(e);
							}
							return 0;
						}
						else {
							return -638;
						}
					}
				}
				else {
					return -639;
				}
			}
		}
	}
	return -1;
}