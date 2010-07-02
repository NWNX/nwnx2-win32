int GetCriticalHitRoll(CNWSCreatureStats *Stats, int bOffHand) {
	CNWSCreature *cre = Stats->cs_original;
	CNWSItem *oWeapon = NULL;
	CNWSBaseItem *WeaponBase = NULL;
	
	int CritThreat = 0;
	
	//find valid weapon (either mainhand, offhand or bracers)
	if (bOffHand) {
		oWeapon = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x20); //offhand
	}
	else {
		oWeapon = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x10); //onhand
	}
	
	if (oWeapon == NULL) { // no weapon equipped, use unarmed attack; try to get the bracers as weapon
		oWeapon = CNWSInventory__GetItemInSlot(cre->cre_equipment, NULL, 0x08);
	}
		
	// determine critrange
	if (oWeapon == NULL) { // still no weapon := unarmed
		CritThreat_1 = 1;
		CritThreat_3 = 0;
	}
	else { //get the critthreat from the weapon
		WeaponBase = CNWBaseItemArray__GetBaseItem((*NWN_Rules)->ru_baseitems, NULL, oWeapon->it_baseitemtype);
		CritThreat_1 = WeaponBase->CritThreat;
		if ( CNWSItem__GetPropertyByType(oWeapon, (CNWSItemProperty *)&v11, 43, 0) )// Keen?
			CritThreat3 = CritThreat_1;
	}
	
	//improved critical range from feats
	if (CNWSCreatureStats__HasFeat((CNWSCreatureStats *)v2, 0x375) == 1) {//FEAT_KI_CRITICAL
		if (oWeapon != NULL) {
			if(CNWSCreatureStats__GetIsWeaponOfChoice(WeaponBase->BaseItem)) {
				CritThreat_3 += 2;
			}
		}
	}

	if (CNWSCreatureStats__GetWeaponImprovedCritical(Stats, oWeapon)) {
		CritThreat_3 += CritThreat_1;
	}
	
	return 21 - (CritThreat_3 + CritThreat_1);
}
