#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int (__thiscall *CExoResMan__Exists)(CExoResMan *pThis, CResRef *, unsigned short, unsigned long *) = (int (__thiscall*)(CExoResMan *pThis, CResRef *, unsigned short, unsigned long *))0x00416BE0;
int (__thiscall *CExoResMan__FreeChunk)(CExoResMan *pTHIS) = (int (__thiscall*)(CExoResMan *pTHIS))0x00416D10;

int CExoResMan::Exists(CResRef *ResRef, unsigned short a2, unsigned long *a3) {
	return CExoResMan__Exists(this, ResRef, a2, a3);
}

int CExoResMan::FreeChunk() {
	return CExoResMan__FreeChunk(this);
}
