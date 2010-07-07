#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int (__thiscall *CGameEffect__GetScriptEffectType)(CGameEffect *pTHIS) = (int (__thiscall *)(CGameEffect *pTHIS))0x004E8CD0;

int	CGameEffect_s::GetScriptEffectType() {
	return CGameEffect__GetScriptEffectType(this);
}