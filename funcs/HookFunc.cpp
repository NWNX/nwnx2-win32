#include "stdafx.h"
#include "nwnx_funcs.h"
#include "madchook.h"
#include <math.h>

extern CNWNXFuncs NWNFuncs;

#define __log(a,b,...) if(a<=NWNFuncs.debugLevel)NWNFuncs.LOG(b,__VA_ARGS__)

void (__fastcall *nwn_CreateNewGeometryNextHook)(CNWSTrigger *pTHIS, void *pVOID, float size, CScriptLocation *Loc, CNWSArea *Area);
char (__fastcall *nwn_CNWSCreatureStats__GetDEXModNextHook)(CNWSCreatureStats *Stats, void *pVOID, int a3);

void __fastcall CreateNewGeometryHookProc(CNWSTrigger *pTHIS, void *pVOID, float size, CScriptLocation *Loc, CNWSArea *Area) {
	if (NWNFuncs.CustomTriggerGeometry) {

		NWNFuncs.NWN_CreateGeometry(pTHIS, Loc, Area);
		NWNFuncs.CustomTriggerGeometry = 0;
		CExoString ScriptName("__test");
		(*NWN_VirtualMachine)->Runscript(&ScriptName, pTHIS->obj.obj_generic.obj_id);
		NWNFuncs.Floats.clear();

		return;
	}
	else {
		nwn_CreateNewGeometryNextHook(pTHIS, NULL, size, Loc, Area);
	}
}

char __fastcall CNWSCreatureStats__GetDEXModHook(CNWSCreatureStats *Stats, void *pVOID, int a3) {
	CNWSCreature *cre = Stats->cs_original;
	int ArmorDexMod=0;

	if (a3 != 1) {
		CNWSItem *Armor = NULL;
		Armor = cre->cre_equipment->GetItemInSlot(2);
		if (Armor) {
			CExoString ExoString("FUNCS_OVERRIDEMAXDEX");
			ArmorDexMod = Armor->obj.obj_vartable.GetInt(ExoString);
			__log(3, "ArmorDexBonusOverride: %d\n", ArmorDexMod);
			if (ArmorDexMod == 0) {
				int ArmorBaseAC = Armor->ComputeArmorClass();
				__log(3, "ArmorBaseAC: %d\n", ArmorBaseAC);
				if (ArmorBaseAC > 0) {
					ExoString = "DEXBONUS";
					C2DA *TDA = (*NWN_Rules)->ru_2das->tda_armor;
					TDA->GetINTEntry_strcol(ArmorBaseAC, ExoString, &ArmorDexMod);
					__log(3, "TDA_DEXMOD: %d\n", ArmorDexMod);

				}
			}
		}
	}

	int DexMod = Stats->cs_dex_mod;
	int iRet = DexMod;
	__log(3, "ArmorDexMod: %d\tDexMod: %d\n", ArmorDexMod, DexMod);
	if (ArmorDexMod > 0 && DexMod > ArmorDexMod)
		iRet = ArmorDexMod;
	
	__log(3, "iRet: %d\n\n", iRet);
	return iRet;
}

signed int (__fastcall *CNWSCreatureStats__GetEffectImmunityNext)(CNWSCreatureStats *Stats_this, void *pVOID, unsigned __int8 a2, CNWSCreature *Versus);

signed int __fastcall CNWSCreatureStats__GetEffectImmunityHook(CNWSCreatureStats *Stats_this, void *pVOID, unsigned __int8 a2, CNWSCreature *Versus) {
	__log(3, "CNWSCreatureStats__GetEffectImmunityHook, a2: %d\n", a2);
	CNWSCreature * cre = Stats_this->cs_original;
	if (cre->obj.obj_is_invulnerable) {
		return 1;
	}

	uint16_t Race = 0x1C; //race_invalid
	int8_t GoodEvilAbsolute = 0;
	int8_t LawChaosAbsolute = 0;

	if (Versus) {
		CNWSCreatureStats *Stats = Versus->cre_stats;
		Race = Stats->cs_race;
		uint8_t Alignment = Stats->cs_al_goodevil;
		if (Alignment > 30) {
			if (Alignment > 70) GoodEvilAbsolute = 4;
			else GoodEvilAbsolute = 1;
		}
		else GoodEvilAbsolute = 5;

		Alignment = Stats->cs_al_lawchaos;
		if (Alignment > 30) {
			if (Alignment > 70) LawChaosAbsolute = 2;
			else LawChaosAbsolute = 1;
		}
		else LawChaosAbsolute = 3;
	}
	else {
		GoodEvilAbsolute = -1;
		LawChaosAbsolute = -1;
	}

	int i=0;
	CGameEffect *Effect = NULL;
	int int0=0, int1=0, int2=0,int3=0;

	CExoString OverrideVar("NWNXFUNCS_IMMOVERRIDE1");
	unsigned long int ImmunityOverride = cre->obj.obj_vartable.GetInt(OverrideVar);
	OverrideVar = "NWNXFUNCS_IMMOVERRIDE2";
	ImmunityOverride |= cre->obj.obj_vartable.GetInt(OverrideVar);
	__log(3, "ImmunityOverride: %d\ta2: %d\n", ImmunityOverride, a2);

	while (i < cre->obj.obj_effects_len) {
		Effect = cre->obj.obj_effects[i];
		if (Effect->eff_type > 0x16) break; // CNWSEffectListHandler__EFFECT_IMMUNITY
		int0 = Effect->GetInteger(0);
		int1 = Effect->GetInteger(1);
		int2 = Effect->GetInteger(2);
		int3 = Effect->GetInteger(3);
		if (
			   Effect->eff_type = 0x16				//EFFECT_IMMUNITY
			&& (int0 == 0x00 || int0 == a2)			//IMMUNITY_TYPE_ALL
			&& (int1 == 0x1C || int1 == Race)		//CRACE_INVALID_RACE
			&& (!int3 || int3 == GoodEvilAbsolute)
			&& (!int2 || int2 == LawChaosAbsolute)
			) {
				__log(3, "a2: %d\n", (1 << (a2-1)));
				__log(3, "%d\n", ((((unsigned long int)(1 << (a2-1))) & ImmunityOverride)));
				if (ImmunityOverride == 0 || ((((unsigned long int)(1 << (a2-1))) & ImmunityOverride) == 0))
				return 1;
		}
		i++;
	}
	return 0;
}

int (__fastcall *ExecuteCommandEffectAppear_Next)(void *pTHIS, void *pVOID, int a2, int a3);

int __fastcall ExecuteCommandEffectAppear_Hook(void *pTHIS, void *pVOID, int a2, int a3) {
	CNWSScriptVarTable *vartable = NULL;
	if (NWNFuncs.CustomEffectObject == NULL) {
		char *mod = (char*)((*NWN_AppManager)->app_server->srv_internal)->GetModule();
		CNWSModule *Mod = (CNWSModule*)(mod+=0x1C);
		vartable = &Mod->mod_vartable;
	}
	else {
		vartable = &NWNFuncs.CustomEffectObject->obj_vartable;
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
			__log(3, "%s\n", effectstruct->text);
			if (strlen(effectstruct->text) > 0) {
				int i=0;
				if (a3 <= 0 || (*NWN_VirtualMachine)->StackPopInteger(&i)) {
					int type=0, creator=0, spellid=0;
					if (sscanf(effectstruct->text, "%d %x %d", &type, &creator, &spellid) == 3) {
						__log(3, "scanned: %d %x %d\n", type, creator, spellid);

						CGameEffect *e = (CGameEffect*)malloc(0x90);
						e->ctor(1);
					
						e->eff_type = type;
						e->eff_creator = creator;
						e->eff_spellid = spellid;
						e->eff_dursubtype = e->eff_dursubtype & 0xFFEF | 8;

						__log(3, "NumInts: %d\n", NumInts);
						if (e->eff_num_integers < NumInts) {
							e->SetNumIntegers(NumInts);
						}

						int iP=0, iStart=0;
						int value;
						for (int j=0; j<NumInts; j++) {
							iP = Ints.find(" ", iStart);
							value = atoi(Ints.substr(iStart, iP-iStart).c_str());
							__log(3, "Int[%d]: %d\n", j, value);
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

	return ExecuteCommandEffectAppear_Next(pTHIS, NULL, a2, a3);
}

int (__fastcall *CNWSEffectListHandler__OnApplyModifyNumAttacksNext)(void *pTHIS, void *pVOID, CNWSObject* obj, CGameEffect *Eff, int a3);
int __fastcall CNWSEffectListHandler__OnApplyModifyNumAttacksHook(void *pTHIS, void *pVOID, CNWSObject* obj, CGameEffect *Eff, int a3) {
	if (obj->GetDead() && !a3)
		return 1;
	if (obj->obj_generic.obj_type2 == 5) {
		CNWSCreature *cre = (CNWSCreature*)obj;
		cre->cre_combat_round->EffectAttacks += Eff->GetInteger(0);
	}
	return 0;
}

void HookFunctions() {
	DWORD org_CreateNewGeometry = 0x005A9250;
	if(NWNFuncs.bHookCreateGeometry) {
		if (HookCode((PVOID) org_CreateNewGeometry, CreateNewGeometryHookProc, (PVOID*)&nwn_CreateNewGeometryNextHook))
			__log(1, "* CreateNewGeometry hooked\n");
	}

	DWORD org_ExecuteCommandEffectAppear = 0x00585110;
	if (1) {
		if (HookCode((PVOID) org_ExecuteCommandEffectAppear, ExecuteCommandEffectAppear_Hook, (PVOID*)&ExecuteCommandEffectAppear_Next))
			__log(1, "* CustomEffect function hooked\n");
	}
	
/*
	DWORD org_CNWSCreatureStats__GetDEXMod = 0x0047CAF0;
	if(0 && NWNFuncs.bOverrideMaximumDexMod) {
		if (HookCode((PVOID) org_CNWSCreatureStats__GetDEXMod, CNWSCreatureStats__GetDEXModHook, (PVOID*)&nwn_CNWSCreatureStats__GetDEXModNextHook))
			__log(1, "* OverideMaxDexBonus hooked\n");
	}

	DWORD org_CNWSCreatureStats__GetEffectImmunity = 0x0048B770;
	__log(0, "* CNWSCreatureStats__GetEffectImmunity hooked: %s\n", 
		HookCode((PVOID) org_CNWSCreatureStats__GetEffectImmunity, CNWSCreatureStats__GetEffectImmunityHook, (PVOID*)&CNWSCreatureStats__GetEffectImmunityNext) ? "success" : "failure");
*/
/*
	DWORD org_CNWSEffectListHandler__OnApplyModifyNumAttacks = 0x004F56C0;
	if (1) {
		if (HookCode((PVOID) org_CNWSEffectListHandler__OnApplyModifyNumAttacks, CNWSEffectListHandler__OnApplyModifyNumAttacksHook, (PVOID*)&CNWSEffectListHandler__OnApplyModifyNumAttacksNext))
			__log(1, "* OnApplyModifyNumAttacks cap removed\n");
	}
*/
}
