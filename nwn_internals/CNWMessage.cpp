#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int (__thiscall *CNWMessage__ReadBOOL)(void *pTHIS) = (int(__thiscall*)(void *pTHIS))0x005078C0;
int (__thiscall *CNWMessage__ReadCResRef)(void *pTHIS, CResRef *a2, signed int a3) = (int (__thiscall*)(void *pTHIS, CResRef *a2, signed int a3))0x00507BC0;
int (__thiscall *CNWMessage__MessageReadOverflow)(void *pTHIS, int a2) = (int (__thiscall*)(void *pTHIS, int a2))0x00507DD0;

int (__thiscall *CNWMessage__CreateWriteMessage)(void *pTHIS, int a2, nwn_objid_t Player_oID, int a4) = (int (__thiscall*)(void *pTHIS, int a2, nwn_objid_t Player_oID, int a4))0x00507E30;
void (__thiscall *CNWMessage__WriteBOOL)(void *pTHIS, int a2) = (void(__thiscall*)(void *pTHIS, int a2))0x00507FC0;
void (__thiscall *CNWMessage__WriteCExoString)(void *pTHIS, CExoString a2, int a3) = (void(__thiscall*)(void *pTHIS, CExoString a2, int a3))0x00508900;
int (__thiscall *CNWMessage__WriteFLOAT)(void *pTHIS, float, float, int) = (int(__thiscall*)(void *pTHIS, float, float, int))0x00508690;
int (__thiscall *CNWMessage__WriteWORD)(void *pTHIS, unsigned __int16 a2, int a3) = (int(__thiscall*)(void *pTHIS, unsigned __int16 a2, int a3))0x00508210;
int	(__thiscall *CNWMessage__GetWriteMessage)(CNWMessage *pTHIS, char **ppData, uint32_t *pLength) = (int (__thiscall *)(CNWMessage *pTHIS, char **ppData, uint32_t *pLength))0x00508B80;

int CNWMessage_s::ReadCResRef(CResRef *ResRef, int a3) {
	return CNWMessage__ReadCResRef(this, ResRef, a3);
}

int CNWMessage_s::MessageReadOverflow(int a2) {
	if (this->field_30 <= this->field_2C)
		return this->field_38 < this->field_3C;
	return 1;
	//return CNWMessage__MessageReadOverflow(this, a2);
}
	
int CNWMessage_s::ReadBOOL() {
	return CNWMessage__ReadBOOL(this);
}

int CNWMessage_s::CreateWriteMessage(int a2, nwn_objid_t Player_oID, int a4) {
	return CNWMessage__CreateWriteMessage(this, a2, Player_oID, a4);
}

void CNWMessage_s::WriteBOOL(int a2) {
	CNWMessage__WriteBOOL(this, a2);
}

void CNWMessage_s::WriteCExoString(CExoString a2, int a3) {
	CNWMessage__WriteCExoString(this, a2, a3);
}

int CNWMessage_s::WriteFLOAT(float f1, float f2, int a3) {
	return CNWMessage__WriteFLOAT(this, f1, f2, a3);
}

int CNWMessage_s::GetWriteMessage(char **ppData, uint32_t *pLength) {
	return CNWMessage__GetWriteMessage(this, ppData, pLength);
}

int CNWMessage_s::WriteWORD(unsigned __int16 a2, int a3) {
	return CNWMessage__WriteWORD(this, a2, a3);
}