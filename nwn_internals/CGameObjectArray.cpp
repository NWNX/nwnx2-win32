#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

uint8_t (__thiscall *CGameObjectArray__delete)(CGameObjectArray *pTHIS, nwn_objid_t oID) = (uint8_t (__thiscall*)(CGameObjectArray *pTHIS, nwn_objid_t oID))0x004668C0;
char 	(__thiscall *CGameObjectArray__GetGameObject)(CGameObjectArray *pTHIS, unsigned int a2, CGameObject *a3) = (char (__thiscall*)(CGameObjectArray *pTHIS, unsigned int a2, CGameObject *a3))0x00466980;

uint8_t CGameObjectArray_s::DEL(nwn_objid_t oID) {
	return CGameObjectArray__delete(this, oID);
}

char CGameObjectArray_s::GetGameObject(unsigned int a2, CGameObject *a3) {
	return CGameObjectArray__GetGameObject(this, a2, a3);
}