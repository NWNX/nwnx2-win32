#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int (__thiscall *CNWMessage__ReadCResRef)(void *pTHIS, CResRef *a2, signed int a3) = (int (__thiscall*)(void *pTHIS, CResRef *a2, signed int a3))0x00507BC0;
int (__thiscall *CNWMessage__MessageReadOverflow)(void *pTHIS, int a2) = (int (__thiscall*)(void *pTHIS, int a2))0x00507DD0;

int CNWMessage_s::ReadCResRef(CResRef *ResRef, int a3) {
	return CNWMessage__ReadCResRef(this, ResRef, a3);
}

int CNWMessage_s::MessageReadOverflow(int a2) {
	if (this->field_30 <= this->field_2C)
		return this->field_38 < this->field_3C;
	return 1;
	//return CNWMessage__MessageReadOverflow(this, a2);
}
	
