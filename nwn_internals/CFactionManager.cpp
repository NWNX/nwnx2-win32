#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CNWSFaction*	(__thiscall *CFactionManager__GetFaction)(CFactionManager *pTHIS, uint32_t FactionID) = (CNWSFaction * (__thiscall*)(CFactionManager *pTHIS, uint32_t FactionID))0x00533EE0;


CNWSFaction *CFactionManager::GetFaction(uint32_t FactionID) {
	return CFactionManager__GetFaction(this, FactionID);
}