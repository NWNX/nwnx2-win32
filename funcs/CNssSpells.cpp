#include "stdafx.h"
#include "CNssSpells.h"

CNssSpells::CNssSpells(void) {
	AddFunction("ADDKNOWNSPELL", L_CAST(&CNssSpells::AddKnownSpell));
	AddFunction("REMOVEKNOWNSPELL", L_CAST(&CNssSpells::RemoveKnownSpell));
	AddFunction("REMOVEALLSPELLS", L_CAST(&CNssSpells::RemoveAllSpells));
	AddFunction("GETKNOWSSPELL", L_CAST(&CNssSpells::GetKnowsSpell));
	AddFunction("REPLACEKNOWNSPELL", L_CAST(&CNssSpells::ReplaceKnownSpell));
	AddFunction("GETREMAININGSPELLSLOTS", L_CAST(&CNssSpells::GetRemainingSpellSlots));
	AddFunction("SETREMAININGSPELLSLOTS", L_CAST(&CNssSpells::SetRemainingSpellSlots));
	AddFunction("GETMAXSPELLSLOTS", L_CAST(&CNssSpells::GetMaxSpellSlots));
	AddFunction("GETBONUSSPELLSLOTS", L_CAST(&CNssSpells::GetBonusSpellSlots));
	AddFunction("GETMEMORIZEDSPELLSLOT", L_CAST(&CNssSpells::GetMemorizedSpellSlot));
	AddFunction("SETMEMORIZEDSPELLSLOT", L_CAST(&CNssSpells::SetMemorizedSpell));
	AddFunction("RESTOREMEMORIZEDSPELLS", L_CAST(&CNssSpells::RestoreMemorizedSpells));
	AddFunction("GETKNOWNSPELLS", L_CAST(&CNssSpells::GetKnownSpells));
	AddFunction("GETKNOWNSPELLCOUNT", L_CAST(&CNssSpells::GetKnownSpellCount));
	AddFunction("SETMAXSSPELLSPELLSLOTS", L_CAST(&CNssSpells::SetMaxSpellSlots)); //not implemented in nwnx_funcs.nss yet
}

int CNssSpells::AddKnownSpell(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error AddSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int i;
	uint8_t sp_class = 0;
	int sp_level = 0;
	uint32_t sp_id = 0;
	int AtLevel = 0;

	CParams::ExtractP4(Params, sp_class, sp_level, sp_id, AtLevel);
	CNWSStats_Level *ls = NULL;

	if (cre->cre_stats == NULL ||
		sp_level < 0 || sp_level > 9) {
			return 0;
	}

	/* find the requested class and level, then add the new spell */
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].alloc < 1) {
			cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len  = 0;
			cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data = NULL;
		}

		if (CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id) == -1) {
			CExoArrayList_uint32_add(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id);
			if (AtLevel > 0) {
				if((ls = GetLevelStats(cre->cre_stats, AtLevel)) != NULL) {
					CExoArrayList_uint32_add(&(ls->ls_spells_known[sp_level]), sp_id);
				}
			}
		}
	}
	return 1;
}

int CNssSpells::RemoveKnownSpell(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error RemoveKnownSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t sp_class = 0;
	uint32_t sp_id = 0;
	int AtLevel = 0;

	CParams::ExtractP3(Params, sp_class, sp_id, AtLevel);

	int i;
	int sp_level=0;
	int iIndex=0;

	CNWSStats_Level *ls = NULL;

	if (cre->cre_stats == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	/* find the requested class and level, then remove the new spell */
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
						if ((iIndex = CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id)) > -1) {
							_log(3, "Spell %i found in class[i] spell list[%i] of class type sp_class.\n", sp_id, sp_class, sp_level, i);
							CExoArrayList_uint32_delfeatindex(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), iIndex);
						}
					}
				}
			}
		}
	}

	if (AtLevel > 0) {
		// need to loop through all levels, through all spell levels
		int iCharacterLevel=0;
		sp_level=0;
		while ((ls = GetLevelStats(cre->cre_stats, ++iCharacterLevel)) != NULL) {
			if (ls->ls_class == sp_class) {
				for (sp_level = 0; sp_level <=9; sp_level++) {
					if (ls->ls_spells_known[sp_level].len > 0) {
						if ((iIndex = CExoArrayList_uint32_contains(&(ls->ls_spells_known[sp_level]), sp_id)) > -1) {
							_log(3, "Spell %i found in spell list[%i] at at character level %i.\n", sp_id, sp_level, iCharacterLevel);
							CExoArrayList_uint32_delfeatindex(&(ls->ls_spells_known[sp_level]), iIndex);
						}
					}
				}
			}
		}
	}
	return 1;
}

int CNssSpells::RemoveAllSpells(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error RemoveAllSpells used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	CParams::ExtractP1(Params, Class);

	int i=0, sp_level=0;
	CNWSStats_Level *ls;

	if (cre->cre_stats == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	/* find the requested class and level, then remove the new spell */
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != Class)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len = 0;
				}
			}
		}
	}

	int iCharacterLevel=0;
	sp_level=0;
	while ((ls = GetLevelStats(cre->cre_stats, ++iCharacterLevel)) != NULL) {
		for (sp_level = 0; sp_level <=9; sp_level++) {
			if (ls->ls_spells_known != NULL) {
				ls->ls_spells_known[sp_level].len = 0;
			}
		}
	}

	return 1;
}

int CNssSpells::GetKnowsSpell(CGameObject *oObject, char *Params) {
	sprintf(Params, "0");

	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetKnowsSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t sp_class = 0;
	uint32_t sp_id = 0;
	int sp_level = 0;

	CParams::ExtractP3(Params, sp_class, sp_id, sp_level);

	int i;
	int iIndex=0;

	if (cre->cre_stats == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (sp_level > -1) {
			if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
					if (CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id) > -1) {
						sprintf(Params, "1");
						return 1;
					}
				}
			}
		}
		else { //loop all spell levels
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
						if (CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id) > -1) {
							sprintf(Params, "%d", sp_level+1);
							return 1;
						}
					}
				}
			}
		}
	}
	sprintf(Params, "-1");
	return 1;
}

int CNssSpells::ReplaceKnownSpell(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error ReplaceKnownSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t sp_class = 0;
	uint32_t sp_id = 0;
	uint32_t NewSpell = 0;

	CParams::ExtractP3(Params, sp_class, sp_id, NewSpell);


	int i;
	int sp_level=0;
	int iIndex=0;
	CNWSStats_Level *ls = NULL;

	if (cre->cre_stats == NULL || sp_level < 0 || sp_level > 9) {
		sprintf(Params, "-1");
		return 0;
	}

	//Classlist
	//loop through all classes to find the right one; then loop through the knownlist to find the spell
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
		if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
			continue;

		if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
					if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len > 0) {
						if ((iIndex = CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id)) > -1) {
							_log(3, "ClassList: Spell %i found in class[%i] spell list[%i] at position %i.\n", sp_id, i, sp_level, iIndex);
							cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data[iIndex] = NewSpell;
							_log(3, "ClassList: Spell Replaced\n");
						}
					}
				}
			}
		}
	}

	// LevelStatList
	// need to loop through all levels, through all spell levels
	int iCharacterLevel=0;
	sp_level=0;
	while ((ls = GetLevelStats(cre->cre_stats, ++iCharacterLevel)) != NULL) {
		if (ls->ls_class == sp_class) {
			for (sp_level = 0; sp_level <=9; sp_level++) {
				if (ls->ls_spells_known[sp_level].len > 0) {
					if ((iIndex = CExoArrayList_uint32_contains(&(ls->ls_spells_known[sp_level]), sp_id)) > -1) {
						_log(3, "LevelStatList: Spell %i found at Character Level %i; known list[%i].\n", sp_id, iCharacterLevel, sp_level);
						ls->ls_spells_known[sp_level].data[iIndex] = NewSpell;
						_log(3, "LevelStatList: Spell Replaced\n");
					}
				}
			}
		}
	}
	return 1;
}

int CNssSpells::GetRemainingSpellSlots(CGameObject *oObject, char *Params) {
	sprintf(Params, "%d", 0);
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetRemainingSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;

	CParams::ExtractP2(Params, Class, SpellLevel);

	int i, slots = 0;

	if (SpellLevel < 0 || SpellLevel > 9) {
		sprintf(Params, "-1");
		return 0;
	}

    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != SpellLevel)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_left[SpellLevel];
		sprintf(Params, "%d", slots);
        break;
    }
	return 1;
}

int CNssSpells::SetRemainingSpellSlots(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetRemainingSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;
	uint8_t Slots = 0;

	CParams::ExtractP3(Params, Class, SpellLevel, Slots);

	int i;

	if (SpellLevel < 0 || SpellLevel > 9 || Slots < 0 || Slots > 99) {
		sprintf(Params, "-1");
		return 0;
	}

    /* iterate their class list, matching the requested class, then set the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;

		if (Slots > cre->cre_stats->cs_classes[i].cl_spells_max[SpellLevel])
            Slots = cre->cre_stats->cs_classes[i].cl_spells_max[SpellLevel];

        cre->cre_stats->cs_classes[i].cl_spells_left[SpellLevel] = Slots;
        break;
    }
	return 1;
}

int CNssSpells::GetMaxSpellSlots (CGameObject *oObject, char *Params) {
	sprintf(Params, "%d", 0);
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetMaxSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;

	CParams::ExtractP2(Params, Class, SpellLevel);

	int i, slots = 0;

	if (SpellLevel < 0 || SpellLevel > 9) {
		sprintf(Params, "-1");
		return 0;
	}


    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_max[SpellLevel];

        if (slots == 0)
            slots = cre->cre_stats->cs_classes[i].cl_spells_mem[SpellLevel].len;

        break;
    }
    sprintf(Params, "%d", slots);

	return 1;
}

int CNssSpells::GetBonusSpellSlots(CGameObject *oObject, char *Params) {
	sprintf(Params, "%d", 0);
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetBonusSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;

	CParams::ExtractP2(Params, Class, SpellLevel);

	int i, slots = 0;

	if (SpellLevel < 0 || SpellLevel > 9) {
		sprintf(Params, "-1");
		return 0;
	}


    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_bonus[SpellLevel];
        break;
    }

    sprintf(Params, "%d", slots);

	return 1;
}

int CNssSpells::GetMemorizedSpellSlot(CGameObject *oObject, char *Params) {
	sprintf(Params, "%d", -1);

	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetMemorizedSpellSlot used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;
	int Index = 0;

	CParams::ExtractP3(Params, Class, SpellLevel, Index);

	CNWSStats_Spell *sp;

	int i, ret = -1;

	if (SpellLevel < 0 || SpellLevel > 9) {
		sprintf(Params, "-1");
		return 0;
	}




    /* iterate their class list, matching the requested class, then iterate the spells
     * known list for that class */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;

        if ((sp = (CNWSStats_Spell*)(CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[i].cl_spells_mem[SpellLevel]), Index))) == NULL)
            break;

        ret = (sp->sp_id & 0xFFFF) | ((sp->sp_meta & 0xFF) << 16) | (sp->sp_ready << 24);
    }

    sprintf(Params, "%d", ret);

	return 1;
}

int CNssSpells::SetMemorizedSpell(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetMemorizedSpell used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;
	int Index = 0;
	int SpellData = 0;

	CParams::ExtractP4(Params, Class, SpellLevel, Index, SpellData);

	int i, sp_spell, sp_meta, sp_flags;

	CNWSStats_Spell *sp;

	sp_spell = SpellData & 0xFFFF;
	sp_meta  = (SpellData >> 16) & 0x7F;
	sp_flags = (SpellData >> 24) & 1;

	if( SpellLevel < 0 || SpellLevel > 9 || Index < 0) {
		sprintf(Params, "-1");
		return 0;
	}



    /* find the requested class, then alter the requested memorized spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;

        if (SpellLevel >= cre->cre_stats->cs_classes[i].cl_spells_mem[SpellLevel].len)
            break;

        if (sp_spell < 0) {
            if (cre->cre_stats->cs_classes[i].cl_spells_mem[Class].data[SpellLevel] != NULL)
                free(cre->cre_stats->cs_classes[i].cl_spells_mem[SpellLevel].data[SpellLevel]); 

            cre->cre_stats->cs_classes[i].cl_spells_mem[SpellLevel].data[SpellLevel] = NULL;
        } else {
            if ((sp = ((CNWSStats_Spell *)cre->cre_stats->cs_classes[i].cl_spells_mem[Class].data[SpellLevel])) == NULL) {
                if ((sp = ((CNWSStats_Spell *)calloc(1, sizeof(*sp)))) == NULL)
                    break;

                cre->cre_stats->cs_classes[i].cl_spells_mem[SpellLevel].data[SpellLevel] = sp;
            }

            sp->sp_id     = sp_spell;
            sp->sp_meta   = sp_meta;
            sp->sp_ready  = !!(sp_flags & 1);
            sp->sp_domain = !!(sp_flags & 2);
		}
        return 1;
    }

	return 1;
}

int CNssSpells::RestoreMemorizedSpells(CGameObject *oObject, char *Params) {
	sprintf(Params, "%d", 0);

	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error RestoreMemorizedSpells used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	// P1 = class, P2 = starting spell level, P3 = ending level

	uint8_t Class = 0;
	int FromLevel = 0, ToLevel = 0;
	CParams::ExtractP3(Params, Class, FromLevel, ToLevel);

    CNWSStats_Spell *sp;
	int i,j,k;

	if (FromLevel < 0) FromLevel = 0; if (FromLevel > 9) FromLevel = 9;
	if (ToLevel < 0) ToLevel = 0; if (ToLevel > 9) ToLevel = 9;
	if (ToLevel < FromLevel) ToLevel = FromLevel;
	
	/* find the requested class, then alter the requested memorized spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;

		for (j=FromLevel; j<=ToLevel; j++) {
			k=0;
			while (k < cre->cre_stats->cs_classes[i].cl_spells_mem[j].len) {
				sp = (CNWSStats_Spell*)(CExoArrayList_ptr_get(&(cre->cre_stats->cs_classes[i].cl_spells_mem[j]), k++));
				if (sp != NULL) sp->sp_ready = 1;
			}

		}
	}
	return 1;
}

int CNssSpells::GetKnownSpells(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetKnownSpells used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	int sp_class, sp_level;
	char sDelimiter[10];
	char sSpell[6]; //string representation of a single spell id (5 + '\n')

	//split Params up into class, spell level and delimiter
	// "1|10|,|            "
	sscanf(Params, "%d %d %s", &sp_class, &sp_level, sDelimiter);

	if (cre->cre_stats == NULL ||
	sp_level < 0 || sp_level > 9) {
		sprintf(Params, "-1");
		return 0;
	}

	//number of spells for given spell level
	int nSpells=0, i;
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;
		
		nSpells = cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len;
		break;
    } 


	// SSSSSDSSSSSDSSSSS\n
	unsigned int iSize = (nSpells*5+(nSpells-1)*strlen(sDelimiter))+1;

	if (iSize > strlen(Params)) {
		_log(2, "o Error (GetKnownSpells): Size of return string [%d] would be greater than spacer [%d].\n", iSize, strlen(Params));
		sprintf(Params, "-1");
		return 0;
	}
	sprintf(Params, "-1");

	int j;
    for (j = 0; j < cre->cre_stats->cs_classes_len; j++) {
        if (cre->cre_stats->cs_classes[j].cl_class != sp_class)
            continue;

		if ((cre->cre_stats->cs_classes[j].cl_spells_known != NULL) 
		&& (cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].len > 0)) {
			sprintf(Params, "%d", cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].data[0]);
			for (i=1; i < cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].len; i++) {
				Params = strcat(Params, sDelimiter);
				sprintf(sSpell, "%d", cre->cre_stats->cs_classes[j].cl_spells_known[sp_level].data[i]);
				Params = strcat(Params, sSpell);
			}
		}
	}

	return 1;
}

int CNssSpells::GetKnownSpellCount(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error GetKnownSpellCount used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;

	CParams::ExtractP2(Params, Class, SpellLevel);

	if (cre->cre_stats == NULL ||
	SpellLevel < 0 || SpellLevel > 9) {
		sprintf(Params, "-1");
		return 0;
	}

	//number of spells for given spell level
	int nSpells=0, i;
	for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;
		
		if (cre->cre_stats->cs_classes[i].cl_spells_known != NULL) {
			sprintf(Params, "%d", cre->cre_stats->cs_classes[i].cl_spells_known[SpellLevel].len);
		}
		break;
    }
	return 1;
}

int CNssSpells::SetMaxSpellSlots(CGameObject *oObject, char *Params) {
	CNWSCreature *cre = oObject->AsNWSCreature();
	if (!cre) {
		_log(2, "o Error SetMaxSpellSlots used on non-creature object.\n");
		sprintf(Params, "-1");
		return 0;
	}

	uint8_t Class = 0;
	int SpellLevel = 0;
	uint8_t MaxSpells = 0;

	CParams::ExtractP3(Params, Class, SpellLevel, MaxSpells);

	int i;

	if (SpellLevel < 0 || SpellLevel > 9) {
		sprintf(Params, "-1");
		return 0;
	}


    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != Class)
            continue;

        cre->cre_stats->cs_classes[i].cl_spells_max[SpellLevel] = MaxSpells;

        break;
    }

	return 1;
}