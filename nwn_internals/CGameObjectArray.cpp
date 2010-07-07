#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

uint8_t (__thiscall *CGameObjectArray__delete)(CGameObjectArray *pTHIS, nwn_objid_t oID) = (uint8_t (__thiscall*)(CGameObjectArray *pTHIS, nwn_objid_t oID))0x004668C0;


uint8_t CGameObjectArray_s::DEL(nwn_objid_t oID) {
	return CGameObjectArray__delete(this, oID);
}