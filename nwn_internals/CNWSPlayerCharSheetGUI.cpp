#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

#include "CNWSPlayerCharSheetGUI.h"

uint32_t (__thiscall *CNWSPlayerCharSheetGUI__ComputeCharacterSheetUpdateRequired)(CNWSPlayerCharSheetGUI_s *pTHIS, CNWSPlayer *Player) = (uint32_t (__thiscall*)(CNWSPlayerCharSheetGUI_s *pTHIS, CNWSPlayer *Player))0x0042E120;

uint32_t CNWSPlayerCharSheetGUI_s::ComputeCharacterSheetUpdateRequired(CNWSPlayer *Player) {
	char *pl = (char*)Player;
	return CNWSPlayerCharSheetGUI__ComputeCharacterSheetUpdateRequired((CNWSPlayerCharSheetGUI_s*)(pl + 0x60), Player);
}