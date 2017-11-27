/***************************************************************************
    NWNXFixes.cpp - Implementation of the CNWNXFixes class.
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

#include "stdafx.h"
#include "NWNXFixes.h"
#include "FixesHooks.h"
#include "IniFile.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXFixes::CNWNXFixes()
{
	bHooked = 0;
}

CNWNXFixes::~CNWNXFixes()
{
}

BOOL CNWNXFixes::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_fixes.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;
	fprintf(m_fFile, "NWNX Fixes V.1.0.5 for Windows\n");
	fprintf(m_fFile, "Copyright 2007-2009 virusman, 2008-2009 Zebranky\n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
	
	CIniFile iniFile ("nwnx.ini");

	debuglevel = iniFile.ReadInteger("FIXES", "debuglevel", 0);

	// Crash fixes -- default to ON
	// Zebranky hooks:
	ini_portalcrash = iniFile.ReadInteger("FIXES", "portalcrash", 1);

	// Functionality changes -- default to OFF
	// virusman hooks:
	ini_copy_vars = iniFile.ReadInteger("FIXES", "copy_vars", 0);
	ini_keep_hidden_in_conversation = iniFile.ReadInteger("FIXES", "keep_hidden_in_conversation", 0);
	ini_compare_vars = iniFile.ReadInteger("FIXES", "compare_vars", 0);
	ini_hp_limit = iniFile.ReadInteger("FIXES", "hp_limit", -10);
	// Zebranky hooks:
	ini_healkit_disease = iniFile.ReadInteger("FIXES", "healkit_disease", 0);
	ini_healkit_poison = iniFile.ReadInteger("FIXES", "healkit_poison", 0);
	ini_hide_charlist_all = iniFile.ReadInteger("FIXES", "hide_charlist_all", 0);
	ini_hide_charlist_levels = iniFile.ReadInteger("FIXES", "hide_charlist_levels", 0);
	ini_hide_charlist_portraits = iniFile.ReadInteger("FIXES", "hide_charlist_portraits", 0);
	ini_hide_charlist_dms = iniFile.ReadInteger("FIXES", "hide_charlist_dms", 0);
	ini_cap_ability_inc = iniFile.ReadInteger("FIXES", "cap_ability_inc", -1);
	ini_cap_ability_dec = iniFile.ReadInteger("FIXES", "cap_ability_dec", -1);
	ini_cap_atkbonus_inc = iniFile.ReadInteger("FIXES", "cap_atkbonus_inc", -1);
	ini_cap_atkbonus_dec = iniFile.ReadInteger("FIXES", "cap_atkbonus_dec", -1);
	ini_cap_skill_inc = iniFile.ReadInteger("FIXES", "cap_skill_inc", -1);
	ini_cap_skill_dec = iniFile.ReadInteger("FIXES", "cap_skill_dec", -1);
	ini_compare_vars_ignore_prefix[0] = '\0';
	iniFile.ReadString("FIXES", "compare_vars_ignore_prefix", ini_compare_vars_ignore_prefix, 16, "");
	ini_spelluses_fix = iniFile.ReadInteger("FIXES", "spelluses_fix", 0);

	if (FindHookFunctions())
	{
		bHooked=1;
		fprintf(m_fFile, "* Module loaded successfully.\n");
	}
	else
	{
		bHooked=0;
		fprintf(m_fFile, "* Module loaded successfully.\n");
		fprintf(m_fFile, "* Signature recognition failed. Some functions will be disabled.\n");
		//return false;
	}
	fflush(m_fFile);

	return true;
}

char* CNWNXFixes::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	return NULL;
}

unsigned long CNWNXFixes::OnRequestObject (char *gameObject, char* Request)
{
	return OBJECT_INVALID;
}

BOOL CNWNXFixes::OnRelease ()
{
	Log ("o Shutdown.\n");
	// call base class function
	return CNWNXBase::OnRelease();
}
