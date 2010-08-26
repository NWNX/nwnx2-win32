#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CGameEffect*	(__thiscall *CGameEffect__CGameEffect)(CGameEffect *PTHIS, int a2) = (CGameEffect *(__thiscall*)(CGameEffect *PTHIS, int a2))0x004E7D30;
void			(__thiscall *CGameEffect__dtor)(CGameEffect *pTHIS) = (void (__thiscall*)(CGameEffect *pTHIS))0x004E7FD0;
int				(__thiscall *CGameEffect__GetScriptEffectType)(CGameEffect *pTHIS) = (int (__thiscall *)(CGameEffect *pTHIS))0x004E8CD0;
//int			(__thiscall *CGameEffect__GetInteger)(CGameEffect, pTHIS, int nInt) = (int (__thiscall*)(CGameEffect, pTHIS, int nInt))0x004E8130;
int				(__thiscall *CGameEffect__SetCreator)(CGameEffect *pTHIS, nwn_objid_t oidCreator) = (int (__thiscall*)(CGameEffect *pTHIS, nwn_objid_t oidCreator))0x004E8C00;
CGameEffect*	(__thiscall *CGameEffect__CGameEffect_c)(CGameEffect *pTHIS, CGameEffect *Effect, int bCopy) = (CGameEffect* (__thiscall*)(CGameEffect *pTHIS, CGameEffect *Effect, int bCopy))0x004E7E70;

CGameEffect *CGameEffect_s::ctor(int a2) {
	return CGameEffect__CGameEffect(this, a2);
}

CGameEffect *CGameEffect_s::ctor(CGameEffect *Effect, int bCopy) {
	return CGameEffect__CGameEffect_c(this, Effect, bCopy);
}

int	CGameEffect_s::GetScriptEffectType() {
	return CGameEffect__GetScriptEffectType(this);
}

int CGameEffect_s::GetInteger(int nInt) {
	return this->eff_integers[nInt];
}

void CGameEffect_s::dtor() {
	CGameEffect__dtor(this);
}

int CGameEffect_s::SetNumIntegers(int nInts) {
	eff_num_integers = nInts;
	if (eff_integers) {
		delete[] eff_integers;
		eff_integers = NULL;
	}
	eff_integers = new int[nInts];
	for (int i=0; i<nInts; i++) {
		eff_integers[i] = 0;
	}
	return 0;
}

int CGameEffect_s::SetCreator(nwn_objid_t oidCreator) {
	return CGameEffect__SetCreator(this, oidCreator);
}