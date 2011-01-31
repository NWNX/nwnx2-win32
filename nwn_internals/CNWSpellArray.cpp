#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CNWSpell *(__thiscall *CNWSpellArray__GetSpell)(CNWSpellArray *pTHIS, int SpellID) = (CNWSpell*(__thiscall*)(CNWSpellArray *pTHIS, int SpellID))0x00502C90;
	
CNWSpell *CNWSpellArray_s::GetSpell(int SpellID) {
	return CNWSpellArray__GetSpell(this, SpellID);
}

