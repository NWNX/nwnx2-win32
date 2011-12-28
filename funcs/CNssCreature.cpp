#include "stdafx.h"
#include "CNssCreature.h"

CNssCreature::CNssCreature(void) {
	AddFunction("SETCREATURESIZE", L_CAST(&CNssCreature::SetCreatureSize));
	AddFunction("GETEQUIPPEDWEIGHT", L_CAST(&CNssCreature::GetEquippedWeight));
	AddFunction("SETGOLD", L_CAST(&CNssCreature::SetGold));
	AddFunction("SETSOUNDSETID", L_CAST(&CNssCreature::SetSoundSetID));
	AddFunction("GETSOUNDSETID", L_CAST(&CNssCreature::GetSoundSetID));
	AddFunction("JUMPTOLIMBO", L_CAST(&CNssCreature::JumpToLimbo));
	AddFunction("SUMMONASSOCIATE", L_CAST(&CNssCreature::SummonAssociate)); //not implemented in nwnx_funcs.nss yet
}

int CNssCreature::SetCreatureSize(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetCreatureSize used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint32_t Size = 0;
	CParams::ExtractP1(Params, Size);
	
	cre->cre_size = Size;

	return 1;
}

int CNssCreature::GetEquippedWeight(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetEquippedWeight used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", cre->cre_equipped_weight);
	return 1;
}

int CNssCreature::SetGold(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetGold used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint32_t Gold = 0;
	CParams::ExtractP1(Params, Gold);

	cre->cre_gold = Gold;

	return 1;
}

int CNssCreature::GetSoundSetID(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetSoundSetID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", cre->cre_soundset);

	return 1;
}

int CNssCreature::SetSoundSetID(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetSoundSetID used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint16_t SoundSet = 0;
	CParams::ExtractP1(Params, SoundSet);

	cre->cre_soundset = SoundSet;

	return 1;
}

int CNssCreature::JumpToLimbo(CGameObject *oObject, char *Params) {
	sprintf(Params, "");

	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error JumpToLimbo used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	CNWSModule *mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule(); 

	if (mod != NULL && cre != NULL) {
		cre->RemoveFromArea(0);
		mod->AddObjectToLimbo(cre->obj_id);
	}
	return 1;
}

int CNssCreature::SummonAssociate(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SummonAssociate used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint16_t Type=0;
	char Name[250];
	char ResRef[16];

	if (sscanf(Params, "%s %s %d", ResRef, Name, &Type) != 3) {
		sprintf(Params, "-1");
		return -1;
	}

	CResRef sResRef;
	strcpy(sResRef.resref, ResRef);
	CExoString sName(Name);
	_log(3, "ResRef: %s\tName: %s\tType %d\n", sResRef.resref, sName.text, Type);
	cre->SummonAssociate(sResRef, sName, Type);

	return 1;
}
