#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void		(__thiscall *CWorldTimer__GetWorldTime)(CWorldTimer *pTHIS, uint32_t *a2, uint32_t *a3) = (void (__thiscall *)(CWorldTimer *pTHIS, uint32_t *a2, uint32_t *a3))0x005BA630;
void		(__thiscall *CWorldTimer__SetWorldTime)(CWorldTimer *pTHIS, uint32_t a2, uint32_t a3, int a4) = (void (__thiscall *)(CWorldTimer *pTHIS, uint32_t a2, uint32_t a3, int a4))0x005BA590;
uint32_t 	(__thiscall *CWorldTimer__SubtractWorldTimes)(CWorldTimer *pTHIS, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t *a6, uint32_t *a7) = (uint32_t (__thiscall *)(CWorldTimer *pTHIS, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t *a6, uint32_t *a7))0x005BA7B0;


void CWorldTimer_s::GetWorldTime(uint32_t *a2, uint32_t *a3) {
	 CWorldTimer__GetWorldTime(this, a2, a3);
}

void CWorldTimer_s::SetWorldTime(uint32_t a2, uint32_t a3, int a4) {
	CWorldTimer__SetWorldTime(this, a2, a3, a4);
}

uint32_t CWorldTimer_s::SubtractWorldTimes(uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t *a6, uint32_t *a7) {
	return CWorldTimer__SubtractWorldTimes(this, a2, a3, a4, a5, a6, a7);
}

