#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void (__thiscall *CNWTile__GetLocation)(CNWTile* pTHIS, int *, int *) = (void (__thiscall*)(CNWTile* pTHIS, int *, int *))0x00523150;

void CNWTile::GetLocation(int *a2, int *a3) {
	CNWTile__GetLocation(this, a2, a3);
}