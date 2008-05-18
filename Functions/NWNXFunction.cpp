/***************************************************************************
    NWNXFunction.cpp - Implementation of the CNWNXFunction class.
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com

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
#include "NWNXFunction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXFunction::CNWNXFunction()
{
}

CNWNXFunction::~CNWNXFunction()
{
}

BOOL CNWNXFunction::OnCreate (const char* LogDir)
{
	// we do not need a log file, so just exit
	return true;
}

void CNWNXFunction::SetLockDC(char* value)
{
	if (*(pGameObject+0x8) == 0x9) // object type placeable
	{
		int iLockDC = atoi(value);
		*(pGameObject+0x210) = iLockDC;
	}
}


void CNWNXFunction::SetGoldPieceValue(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int iGoldValue = atoi(value);
		*(int*)(pGameObject+0x1F4) = iGoldValue;
	}
}

void CNWNXFunction::SetTag(char* value)
{
    char* tag = (char*)(*(int*)(pGameObject+0x18));

	int iLength;
	int iOrgLength = strlen(tag);
	int iNewLength = strlen(value);

	if (iOrgLength > iNewLength)
		iLength = iNewLength;
	else
		iLength = iOrgLength;

	strncpy(tag, value, iLength);

	*(tag+iLength) = 0x0;
}

void CNWNXFunction::SetArmorAC(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int iAC = atoi(value);
		*(int*)(pGameObject+0x1CC) = iAC;
	}
	// 0x1d4: auch armor class ??
}

void CNWNXFunction::GetArmorAC(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int iAC = *(int*)(pGameObject+0x1CC);
		if (strlen(value) > 1)
			sprintf(value, "%d", iAC);
	}
}

void CNWNXFunction::GetDescription(char* value)
{
	int length = strlen(value);
	char* desc;
	
	if (*(pGameObject+0x8) != 0x6) // object type item	
		return;
	
	desc = (char*)(*(int*)(pGameObject+0x228));
	if (*(desc+4) == 0)
		return;
	desc = (char*)(*(int*)(desc));
	desc = (char*)(*(int*)(desc));
	desc = (char*)(*(int*)(desc+0x8));
	desc = (char*)(*(int*)(desc+0x4));

	int iDescLength = strlen(desc);
	if (iDescLength < length)
	{
		strncpy(value, desc, iDescLength);
		*(value+iDescLength) = 0x0;
	}
	else
	{
		strncpy(value, desc, length);
		*(value+length) = 0x0;
	}
}

void CNWNXFunction::GetIsPickPocketable(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int i = *(int*)(pGameObject+0x248);
		if (strlen(value) > 1)
			sprintf(value, "%d", i);
	}
}

void CNWNXFunction::SetIsPickPocketable(char* value)
{
	if (*(pGameObject+0x8) == 0x6) // object type item
	{
		int i = atoi(value);
		*(int*)(pGameObject+0x248) = i;
	}
}


char* CNWNXFunction::OnRequest (char *gameObject, char* Request, char* Parameters)
{
	this->pGameObject = gameObject;

	if (strncmp(Request, "SETLOCKDC", 9) == 0) 	
	{
		SetLockDC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETGOLDPIECEVALUE", 17) == 0) 	
	{
		SetGoldPieceValue(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETTAG", 6) == 0) 	
	{
		SetTag(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETARMORAC", 10) == 0) 	
	{
		SetArmorAC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETARMORAC", 10) == 0) 	
	{
		GetArmorAC(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETDESCRIPTION", 14) == 0) 	
	{
		GetDescription(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "GETISPICKPOCKETABLE", 19) == 0) 	
	{
		GetIsPickPocketable(Parameters);
		return NULL;
	}
	else if (strncmp(Request, "SETISPICKPOCKETABLE", 19) == 0) 	
	{
		SetIsPickPocketable(Parameters);
		return NULL;
	}
	return NULL;
}

BOOL CNWNXFunction::OnRelease ()
{
	// call base class
	return CNWNXBase::OnRelease ();
}
