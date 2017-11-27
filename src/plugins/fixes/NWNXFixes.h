/***************************************************************************
    NWNXFixes.h - Interface for the CNWNXFixes class.
    (c) 2007 virusman (virusman@virusman.ru)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#if !defined(NWNXFIXES_H_)
#define NWNXFIXES_H_

#include "NWNXBase.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IniFile.h"
#include "FixesHooks.h"

class CNWNXFixes : public CNWNXBase
{

public:
	CNWNXFixes();
	virtual ~CNWNXFixes();
	BOOL OnCreate(const char* LogDir);
	char* OnRequest(char* gameObject, char* Request, char* Parameters);
	unsigned long OnRequestObject (char *gameObject, char* Request);
	BOOL OnRelease();
	bool bHooked;
	int ini_stacking, ini_stealthconvo, ini_portalcrash, ini_healkit_disease, ini_healkit_poison, ini_hide_charlist_all, ini_hide_charlist_levels, ini_hide_charlist_portraits, ini_hide_charlist_dms, ini_copy_vars, ini_keep_hidden_in_conversation, ini_compare_vars, ini_hp_limit, ini_cap_ability_inc, ini_cap_ability_dec, ini_cap_atkbonus_inc, ini_cap_atkbonus_dec, ini_cap_skill_inc, ini_cap_skill_dec, ini_spelluses_fix;
	char ini_compare_vars_ignore_prefix[16];

private:

};

#endif
