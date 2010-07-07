#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void			(__thiscall *CNWCCMessageData__ctor)(CNWCCMessageData *pTHIS) = (void (__thiscall*)(CNWCCMessageData *pTHIS))0x00506630;
uint32_t 		(__thiscall *CNWCCMessageData__SetString)(CNWCCMessageData *pTHIS, uint32_t a2, CExoString ExoString) = (uint32_t (__thiscall*)(CNWCCMessageData *pTHIS, uint32_t a2, CExoString ExoString))0x00506880;


void CNWCCMessageData_s::ctor() {
	CNWCCMessageData__ctor(this);
}

uint32_t CNWCCMessageData_s::SetString(uint32_t a2, CExoString ExoString) {
	return CNWCCMessageData__SetString(this, a2, ExoString);
}
