#include "stdafx.h"
#include "CNssItemProperty.h"

CNssItemProperty::CNssItemProperty(void) {
}

int CNssItemProperty::GetItemPropertyInformation() {
	CExoString varname = CExoString("NWNX_FUNCS_IPRP");
	CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
	//CNWSModule *Mod = ((CNWSModule*)(mod+=0x1C));
	CExoString *Params = NULL;
	int iprp=0, P2=0, P3=0;

	Params = Mod->mod_vartable.GetString(varname);
	if (Params) {
		if (sscanf(Params->text, "%d %d %d", &iprp, &P2, &P3) == 3) {
			int Ret = 0;
			CGameEffect *eff = NULL;
			CNWSItemProperty *ip = NULL;
			void *temp;
			if ((*NWN_VirtualMachine)->StackPopEngineStructure(4, &temp)) {
				int iPush = -1;
				if (temp != NULL) {
					eff = (CGameEffect*)temp;
					_log(3, "temp %08X|teff: %08X\n", temp, eff);
					uint32_t tD, tT, eD, eT;
					int64_t current, expire;
					float fRemaining = 0.0;
					switch (iprp) {
						case 1: Mod->mod_vartable.SetFloat(varname, eff->eff_duration); iPush = 1; break;
						case 2: iPush = eff->eff_spellid; break;
						case 3:	if (eff->eff_integers[P2] != NULL) {iPush = eff->GetInteger(P2); } break;
						case 4:
							if (eff->eff_integers[P2] != NULL) {
								eff->eff_integers[P2] = P3; iPush = 1; 
							}
						break;
						case 5: eff->eff_spellid = P2; iPush = 1; break;
						case 6: 
							if (eff->eff_duration != 0.0) {
								(*NWN_AppManager)->app_server->srv_internal->srv_time_world->GetWorldTime(&tD, &tT);
								current = (tD * 2880000LL) + tT;

								eD = eff->eff_expire_day;
								eT = eff->eff_expire_time;
								expire = (eD * 2880000LL) + eT;
			 
								Mod->mod_vartable.SetFloat(varname, (float)(expire - current)/1000.0);
								iPush = 1;
							}
						break;
						case 7:
							_log(3, "Set Creator\n");
							eff->eff_creator = P2; iPush = 1;
						break;
					}
				}
				if ((*NWN_VirtualMachine)->StackPushInteger(iPush)) {
					if (eff) {
						eff->dtor();
						free (eff);
					}
				}
				else {
					Ret = -638;
				}
			}
			else {
				Ret = -639;
			}
			return Ret;
		}
	}
	return -1;
}

int CNssItemProperty::ItemPropertyCustom(void *CVirtComm, int a1) {
	int result = -1;
	if (a1 == 657) {
		CExoString varname = CExoString("NWNX_FUNCS_IPRP");
		CNWSModule *Mod = ((*NWN_AppManager)->app_server->srv_internal)->GetModule();
		CExoString *Params = NULL;
		Params = Mod->mod_vartable.GetString(varname);

		if (Params && Params->len > 0) {
			int Type=0, SubType=0, CostValue=0, ParamValue=0;
			if (sscanf(Params->text, "%d %d %d %d", &Type, &SubType, &CostValue, &ParamValue) == 4) {
				CGameEffect *e = (CGameEffect*)malloc(0x90);
				e->ctor(1);
				e->SetNumIntegersInitializeToNegativeOne(9);
				e->SetCreator(((CVirtualMachineCommands*)CVirtComm)->OBJ_SELF);
				e->eff_type = 91;
				e->eff_dursubtype &= 0xFFA | 2;

				e->eff_integers[0] = Type;
				e->eff_integers[1] = SubType;
				e->eff_integers[2] = a1;
				e->eff_integers[3] = CostValue;
				e->eff_integers[5] = ParamValue;

				e->eff_integers[7] = 100;
				e->eff_integers[8] = 1;
				if ((*NWN_VirtualMachine)->StackPushEngineStructure(4, e)) {
					if (e) {
						e->dtor();
						free(e);
					}
					result = 0;
				}
				else result = -638;
			}
		}
	}
	return result;
}
