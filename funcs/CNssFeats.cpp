#include "stdafx.h"
#include "CNssFeats.h"

CNssFeats::CNssFeats(void) {
	AddFunction("ADDFEAT", L_CAST(&CNssFeats::AddFeat));
	AddFunction("ADDFEATATLEVEL", L_CAST(&CNssFeats::AddFeatAtLevel));
	AddFunction("REMOVEFEAT", L_CAST(&CNssFeats::RemoveFeat));
	AddFunction("GETFEATKNOWN", L_CAST(&CNssFeats::GetFeatKnown));
	AddFunction("GETALLKNOWNFEATS", L_CAST(&CNssFeats::GetAllKnownFeats));
	AddFunction("CLEARFEATLIST", L_CAST(&CNssFeats::ClearFeatList));
	AddFunction("GETFEATCOUNT", L_CAST(&CNssFeats::GetFeatCount));
}

int CNssFeats::AddFeat(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		sprintf(Params, "-1");
		_log(2, "o Error: AddFeat used on non-creature object.\n");
		return 0;
	}

	uint16_t Feat = 0;
	CParams::ExtractP1(Params, Feat);

	cre->cre_stats->AddFeat(Feat);
	return 1;
}

int CNssFeats::AddFeatAtLevel(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		sprintf(Params, "-1");
		_log(2, "o Error: AddFeatAtLevel used on non-creature object.\n");
		return 0;
	}

	int Level = 0;
	uint16_t Feat = 0;

	CParams::ExtractP2(Params, Level, Feat);

	CNWSCreatureStats *Stats = cre->cre_stats;
	CNWSStats_Level *ls;
	if ((ls = GetLevelStats(Stats, Level)) == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	((CNWSCreatureStats*)cre->cre_stats)->AddFeat(Feat);
	ls->AddFeat(Feat);

	return 1;
}

int CNssFeats::RemoveFeat(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		sprintf(Params, "-1");
		_log(2, "o Error: RemoveFeat used on non-creature object.\n");
		return 0;
	}

	CNWSCreatureStats *Stats = cre->cre_stats;
	CNWSStats_Level *ls = NULL;

	uint16_t Feat = 0;
	int ByLevel = 0;

	CParams::ExtractP2(Params, Feat, ByLevel);

	int iLevelIndex = -1;

	//check the general feat list
	int iGeneralIndex = CExoArrayList_uint16_contains(&Stats->cs_feats, Feat);
	if (iGeneralIndex > 0) {
		_log(3, "Feat %i found in general feat index at position %i.\n", Feat, iGeneralIndex);
		CExoArrayList_uint16_delfeatindex(&Stats->cs_feats, iGeneralIndex);
	}

	int iLevel = 0;
	//check the feat list for the level provided; if provided
	if (ByLevel) {
		while ((ls = GetLevelStats(Stats, ++iLevel)) != NULL) {
			if((iLevelIndex = CExoArrayList_uint16_contains(&(ls->ls_featlist), Feat)) > -1) {
				_log(3, "Feat %i found in in feat list of level %i at position %i.\n", Feat, iLevel, iLevelIndex);
				CExoArrayList_uint16_delfeatindex(&Stats->cs_feats, iLevelIndex);
				break;
			}
		}
		if (ls == NULL) {
			// looped through all levels and couldn't find the feat
		}
	}
	return 1;
}

int CNssFeats::GetFeatKnown(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		sprintf(Params, "-1");
		_log(2, "o Error: GetFeatKnown used on non-creature object.\n");
		return 0;
	}

	uint16_t Feat = 0;

	CParams::ExtractP1(Params, Feat);

	int iGeneralIndex = (CExoArrayList_uint16_contains(&cre->cre_stats->cs_feats, Feat))+1;

	sprintf(Params, "%d", iGeneralIndex);
	return iGeneralIndex;
}

int CNssFeats::GetAllKnownFeats(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		sprintf(Params, "-1");
		_log(2, "o Error: GetAllKnownFeats used on non-creature object.\n");
		return 0;
	}

	char *sDelimiter = strchr(Params, ' ');
	char *sFeat;

	int iSize;
	try {
		iSize = sDelimiter-Params;
		sDelimiter = (char*)calloc(iSize, sizeof(char)+1);
		sscanf(Params, "%s ", sDelimiter);
		sFeat = (char*)calloc(6, sizeof(char)); //holds the feat as a string; max feat is 65535 so we need 5+1 chars to store it
	}
	catch (std::exception &e) {
		_log(2, "o Error (GetAllKnownFeats): %s\n", e.what());
		sprintf(Params, "-1");
		return 0;
	}

	CNWSCreatureStats *Stats = (CNWSCreatureStats*)((CNWSCreature*)oObject)->cre_stats;
	CExoArrayList_uint16 *Feats = &Stats->cs_feats;
	
	// FFFFFDFFFFFDFFFFF\n
	iSize = (Feats->len*5+(Feats->len-1)*strlen(sDelimiter))+1;

	if (iSize > strlen(Params)) {
		_log(2, "o Error (GetAllKnownFeats): Size of return string [%d] would be greater than spacer [%d].\n", iSize, strlen(Params));
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "");
	if (Feats->len > 0) {
		sprintf(Params, "%d", Feats->data[0]);

		int i=0;
		while (++i < Feats->len) {
			Params = strcat(Params, sDelimiter);
			sprintf(sFeat, "%d", Feats->data[i]);
			Params = strcat(Params, sFeat);
		}
	}
	else {
		sprintf(Params, "");
	}

	free(sFeat);
	free(sDelimiter);

	return 1;
}

int CNssFeats::ClearFeatList(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		sprintf(Params, "-1");
		_log(2, "o Error: ClearFeatList used on non-creature object.\n");
		return 0;
	}
	
	CNWSCreatureStats *Stats = cre->cre_stats;
	Stats->cs_feats.len = 0;

	int bClearLevelLists = 0;

	CParams::ExtractP1(Params, bClearLevelLists);

	if (bClearLevelLists) {
		CNWSStats_Level *ls;
		int iLevel = 0;

		while ((ls = GetLevelStats(Stats, ++iLevel)) != NULL) {
			ls->ls_featlist.len = 0;
		}
	}

	return 1;
}

int CNssFeats::GetFeatCount(CGameObject *oObject, char *Params) {
	sprintf(Params, "d", 0);
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		sprintf(Params, "-1");
		_log(2, "o Error: GetFeatCount used on non-creature object.\n");
		return 0;
	}

	sprintf(Params, "%d", cre->cre_stats->cs_feats.len);

	return 1;
}
