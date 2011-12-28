#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int 			(__thiscall *CNWSPlayer__HasExpansionPack)(CNWSPlayer *pTHIS, unsigned char a2, int a3) = (int (__thiscall*)(CNWSPlayer *pTHIS, unsigned char a2, int a3))0x00436720;
int 			(__thiscall *CNWSPlayer__AddArea)(CNWSPlayer* pTHIS, uint32_t areaid) = (int (__thiscall*)(CNWSPlayer* pTHIS, uint32_t areaid))0x00436560;
CGameObject* (__thiscall *CNWSPlayer__GetGameObject)(CNWSPlayer *pTHIS) = (CGameObject* (__thiscall*)(CNWSPlayer *pTHIS))0x004364E0;
void 			(__thiscall *CNWSPlayer__vec_dtor)(CNWSPlayer *pTHIS, char Flag) = (void (__thiscall*)(CNWSPlayer *pTHIS, char Flag))0x0042EEA0;


int CNWSPlayer_s::AddArea(uint32_t areaid) {
	return CNWSPlayer__AddArea(this, areaid);
}

CGameObject *CNWSPlayer_s::GetGameObject() {
	return CNWSPlayer__GetGameObject(this);
}

int CNWSPlayer_s::HasExpansionPack(unsigned char a2, int a3) {
	return CNWSPlayer__HasExpansionPack(this, a2, a3);
}

void CNWSPlayer_s::vec_dtor(char Flag) {
	CNWSPlayer__vec_dtor(this, Flag);
}

