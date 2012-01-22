/***************************************************************************
    NWNXReset.cpp - Implementation of the CNWNXReset class.
    Copyright (C) 2005 Fay Smith (Asmodae)
    Copyright (C) 2006, 2012 virusman (virusman@virusman.ru)

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

#include "NWNXReset.h"

void d_enable_write (unsigned long location)
{
	char *page;
	unsigned long oldAlloc;
	page = (char *) location;
	VirtualProtect(page, 0xFF, PAGE_EXECUTE_READWRITE, &oldAlloc);
}

CNWNXReset::CNWNXReset()
{
}

CNWNXReset::~CNWNXReset()
{
	OnRelease();
}

char* CNWNXReset::OnRequest(char *gameObject, char* Request, char* Parameters)
{
	// This assumes you call SetLocalString like this
	// SetLocalString(oObject, "NWNX!RESETPLUGIN!SHUTDOWN", "...................................");

	if (stricmp (Request, "SHUTDOWN") == 0)
	{
		// This will output "SHUTDOWN" as the request
		Log("* NWNXResetPlugin - Got request: %s.\n", Request);

		char *pShutdown = (char*)0x00402700;
		if(pShutdown[0] == 0x75)
		{
			d_enable_write((unsigned long)pShutdown);
			pShutdown[0] = 0x74;
		}
	}

	return NULL;
}

BOOL CNWNXReset::OnCreate(const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_resetplugin.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;

	WriteLogHeader();
	return true;
}

BOOL CNWNXReset::OnRelease()
{
	Log("o Shutting down\n");

	// call base class function
	return CNWNXBase::OnRelease();
}

void CNWNXReset::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX Reset Plugin V.0.2\n");
	fprintf(m_fFile, "By virusman, 2012 \n");
	fprintf(m_fFile, "visit us at http://www.nwnx.org\n\n");
}