#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

uint32_t		(__thiscall *CNWSFaction__GetFactionMember)(CNWSFaction *pThis, int nNth, int bNPCs) = (uint32_t (__thiscall*)(CNWSFaction *pThis, int nNth, int bNPCs))0x004EA9E0;

uint32_t CNWSFaction_s::GetFactionMember(int nNth, int bNPCs) {
	return CNWSFaction__GetFactionMember(this, nNth, bNPCs);
}
	