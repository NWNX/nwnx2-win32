/***************************************************************************
	Copyright (C) 2008 David Strait (addicted2rpg)  (duckbreath@yahoo.com)


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
#include "NWNXTMI.h"
#include <stdlib.h>
#include <string.h>
#include "..\NWNXDll\IniFile.h"
#include "..\NWNXDll\madCHook.h"

//005BD1A0
unsigned long FindTMILimit() {	
	unsigned char* ptr = (unsigned char*) 0x400000;
	while (ptr < (unsigned char*) 0x600000)	{
		if (ptr[0] == (unsigned char) 0x08 && 
			ptr[1] == (unsigned char) 0x41 &&    
			ptr[2] == (unsigned char) 0x8B &&    
			ptr[3] == (unsigned char) 0xC1 &&    
			ptr[4] == (unsigned char) 0x3D && 
			ptr[5] == (unsigned char) 0x00 &&
			ptr[6] == (unsigned char) 0x00 && 
			ptr[7] == (unsigned char) 0x02 &&
			ptr[8] == (unsigned char) 0x00 &&
			ptr[9] == (unsigned char) 0x89 &&
			ptr[10] == (unsigned char) 0x4E &&
			ptr[11] == (unsigned char) 0x08 &&
			ptr[12] == (unsigned char) 0x0F &&
			ptr[13] == (unsigned char) 0x8D &&
			ptr[14] == (unsigned char) 0x83 &&
			ptr[15] == (unsigned char) 0x23 &&
			ptr[16] == (unsigned char) 0x00 &&
			ptr[17] == (unsigned char) 0x00)
			return (unsigned long)(ptr + 5);
		else
			ptr++;
	}

	return 0;
}

static void enable_write (unsigned long location)
{
	char *page;
	unsigned long oldAlloc;
	page = (char *) location;
	VirtualProtect(page, 0xFF, PAGE_EXECUTE_READWRITE, &oldAlloc);
}

CNWNXTMI::CNWNXTMI()
{
	orig_TMI = 0;
}

CNWNXTMI::~CNWNXTMI()
{
}

char* CNWNXTMI::OnRequest(char *gameObject, char* Request, char* Parameters)
{
	Log(1, "Request: \"%s\"\n", Request);
	Log(1, "Params:  \"%s\"\n", Parameters);

	if (strncmp(Request, "GETLIMIT", 8) == 0) {
		GetTMILimit(Parameters);
		return NULL;
	}

	if (strncmp(Request, "SETLIMIT", 8) == 0) {
		SetTMILimit(Parameters);
		return NULL;
	}

	return NULL;
}

BOOL CNWNXTMI::OnCreate(const char* LogDir)
{
	char log[MAX_PATH];

	sprintf (log, "%s\\nwnx_tmi.txt", LogDir);

	// call the base class function
	if (!CNWNXBase::OnCreate(log))
		return false;

	WriteLogHeader();

	orig_TMI = FindTMILimit();

	if(!orig_TMI)
		return false;

	enable_write(orig_TMI);

	Log(1, "o found TMI limit at 0x%08lx\n", (const char *)orig_TMI);

	return true;
}

void CNWNXTMI::WriteLogHeader()
{
	fprintf(m_fFile, "NWNX TMI Plugin (c) 2010 by virusman, based on Linux code (c) 2007 by Doug Swarin (acaos)\n");
	fprintf(m_fFile, "Previous versions: (c) by 2008 David Strait (addicted2rpg), (c) by 2010 Jonny R (Baaleos)");
}

void CNWNXTMI::GetTMILimit(char *value) {
	int lim = 0;

	lim |= *((unsigned char *)(orig_TMI + 2)) << 16;
	lim |= *((unsigned char *)(orig_TMI + 1)) << 8;
	lim |= *((unsigned char *)orig_TMI);

	snprintf(value, strlen(value), "%d", lim);
}

void CNWNXTMI::SetTMILimit(char *value) {
	int lim = atoi(value);

	if (lim < 16383)
		lim = 16383;
	else if (lim > 8388607)
		lim = 8388607;

	*((unsigned char *)(orig_TMI + 2)) = (lim >> 16) & 0xFF;
	*((unsigned char *)(orig_TMI + 1)) = (lim >> 8) & 0xFF;
	*((unsigned char *)orig_TMI) = lim & 0xFF;
}
