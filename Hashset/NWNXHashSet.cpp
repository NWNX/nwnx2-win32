/***************************************************************************
    NWNXHashSet.cpp - Implementation of the CNWNXHashSet class.
    Copyright (C) 2003 Jeroen Broekhuizen (nwnx@jengine.nl) and
	Ingmar Stieger (Papillon, papillon@blackdagger.com)
    
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
#include "NWNXHashSet.h"
#include <stdio.h>
#include <memory.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXHashSet::CNWNXHashSet()
{
	iLastOperation = HashSet_FAILURE;
}

CNWNXHashSet::~CNWNXHashSet()
{
}

BOOL CNWNXHashSet::OnCreate (const char* LogDir)
{
	// call the base class function
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_hashset.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;

	Log(0, "NWNX HashSet V.1.0\n");
	Log(0, "(c) 2003 by Ingmar Stieger (Papillon)\n");
	Log(0, "visit us at http://www.nwnx.org\n\n");

	// create hash table with space for 5000 entries
	// this hash will contain the pointers to our HashSets
	pHashSets = new CHashTable(5000);
	if (pHashSets->getSize() == 0)
	{
		Log(1, "* Critical error: creation of hash table failed!\n");
		return false;
	}
	else 
	{
		Log(1, "* Module loaded successfully.\n");
		return true;
	}
}

char* CNWNXHashSet::OnRequest (char* gameObject, char* Request, char* Parameters)
{
	char* pKey = NULL;
	char* pValue = NULL;
	char* pResult = NULL;
	char* pReminder = NULL;
	char* pHashSetName = NULL;
	char pUniqueHashSet[256] = {0};
	int iIndex;

	int iGameObjectId = *(int*)(gameObject+4);

	if (!GetHashSetName(Parameters, &pHashSetName, &pReminder))
		return NULL;

	// build unique HashSet name using game object id + HashSet name
    sprintf(pUniqueHashSet, "%d", iGameObjectId);
	strcat(pUniqueHashSet, pHashSetName);

	// see what action must be taken
	if (strcmp(Request, "LOOKUP") == 0)
	{
		if (GetKey(pReminder, &pKey))
		{
			pResult = Lookup(pUniqueHashSet, pKey);
			if (pResult)
				iLastOperation = HashSet_SUCCESS;
			else
			{
				iLastOperation = HashSet_FAILURE;
				// return empty string
				pResult = ""; 
			}
			Log(2, "-> lookup request on hashset %s, key %s, answering with %s\n", pUniqueHashSet, pKey, pResult);
		}
	}
	else if (strcmp(Request, "INSERT") == 0)
	{
		if (GetKeyAndValue(pReminder, &pKey, &pValue))
		{
			Log("-> insert request on hashset %s, key %s, value %s\n", pUniqueHashSet, pKey, pValue);
			// Create a copy of the supplied value and insert that into the hashset
			Insert(pUniqueHashSet, pKey, _strdup(pValue));
			iLastOperation = HashSet_SUCCESS;
		}
		else
			iLastOperation = HashSet_FAILURE;
	}
	else if (strcmp(Request, "DELETE") == 0)
	{
		if (GetKey(pReminder, &pKey))
		{
			Log(2, "-> delete request on hashset %s, key %s\n", pUniqueHashSet, pKey);
			Delete(pUniqueHashSet, pKey);
			iLastOperation = HashSet_SUCCESS;
		}
		else
			iLastOperation = HashSet_FAILURE;
	}

	else if (strcmp(Request, "STATUS") == 0)
	{
		if (iLastOperation)
			pResult = "1";
		else
			pResult = "0";
	}
	else if (strcmp(Request, "VALID") == 0)
	{
		if (GetKey(pReminder, &pKey))
		{
			Log(2, "-> valid request on hashset %s\n", pUniqueHashSet);
			if (Valid(pUniqueHashSet))
				pResult = "1";
			else
				pResult = "0";
		}
	}
	else if (strcmp(Request, "EXISTS") == 0)
	{
		if (GetKey(pReminder, &pKey))
		{
			Log(2, "-> exists request on hashset %s, key %s\n", pUniqueHashSet, pKey);
			if (Exists(pUniqueHashSet, pKey))
				pResult = "1";
			else
				pResult = "0";
		}
	}
	else if (strcmp(Request, "GETFIRSTKEY") == 0)
	{
		Log(2, "-> getfirstkey request on hashset %s\n", pUniqueHashSet);
		pResult = GetFirstKey(pUniqueHashSet);
		if (pResult)
			iLastOperation = HashSet_SUCCESS;
		else
		{
			iLastOperation = HashSet_FAILURE;
			// return empty string
			pResult = ""; 
		}
	}
	else if (strcmp(Request, "GETNEXTKEY") == 0)
	{
		Log(2, "-> getnextkey request on hashset %s\n", pUniqueHashSet);
		pResult = GetNextKey(pUniqueHashSet);
		if (pResult)
			iLastOperation = HashSet_SUCCESS;
		else
		{
			iLastOperation = HashSet_FAILURE;
			// return empty string
			pResult = ""; 
		}
	}
	else if (strcmp(Request, "GETCURRENTKEY") == 0)
	{
		Log(2, "-> getcurrentkey request on hashset %s\n", pUniqueHashSet);
		pResult = GetCurrentKey(pUniqueHashSet);
		if (pResult)
			iLastOperation = HashSet_SUCCESS;
		else
		{
			iLastOperation = HashSet_FAILURE;
			// return empty string
			pResult = ""; 
		}
	}
	else if (strcmp(Request, "GETNTHKEY") == 0)
	{
		iIndex = atoi(pReminder);
		Log(2, "-> getnthkey request on hashset %s, key number %d\n", pUniqueHashSet, iIndex);
		pResult = GetNthKey(pUniqueHashSet, iIndex);
		if (pResult)
			iLastOperation = HashSet_SUCCESS;
		else
		{
			iLastOperation = HashSet_FAILURE;
			// return empty string
			pResult = ""; 
		}
	}
	else if (strcmp(Request, "HASNEXT") == 0)
	{
		Log(2, "-> hasnext request on hashset %s\n", pUniqueHashSet);
		if (HasNext(pUniqueHashSet))
			pResult = "1";
		else
			pResult = "0";
	}
	else if (strcmp(Request, "GETSIZE") == 0)
	{
		Log(2, "-> size request on hashset %s\n", pUniqueHashSet);
		sprintf(cLastValue, "%d", GetSize(pUniqueHashSet));
		pResult = cLastValue;
	}
	else if (strcmp(Request, "DESTROY") == 0)
	{
		Log(2, "* Destroy hashset %s\n", pUniqueHashSet);
		Create(pUniqueHashSet, 0);
		iLastOperation = HashSet_SUCCESS;
	}
	else if (strcmp(Request, "CREATE") == 0)
	{
		iIndex = atoi(pReminder);
		Log(2, "* Create HashSet '%s' with size : %d\n", pUniqueHashSet, iIndex);
		Create(pUniqueHashSet, iIndex);
		iLastOperation = HashSet_SUCCESS;
	}

	// a return value of NULL tells NWNX that it shouldn't copy
	// any values, a non zero pointer tells NWNX that it should copy
	// the null terminated string pointed to by that pointer back into NWN.
	return pResult; 
}

BOOL CNWNXHashSet::OnRelease()
{
	// call base class
	return CNWNXBase::OnRelease();
}

bool CNWNXHashSet::GetHashSetName(char *parameter, char **pName, char **pReminder)
{
	char* pos;
	if ((pos = strchr(parameter, '!')) != NULL)
	{
		// change ! to terminating zero
		*pos = 0;
		pos++;
		// return left part in pName
		(*pName) = parameter;
		// return rest in pReminder
		(*pReminder) = pos;
		return true;
	}
	else 
		return false;
}

bool CNWNXHashSet::GetKey(char* parameter, char** pKey)
{
	char* pos;
	if ((pos = strchr(parameter, '!')) != NULL)
	{
		// change ! to terminating zero
		*pos = 0;
		// use left part as key
		(*pKey) = parameter;
		return true;
	}
	else 
		return false;
}

bool CNWNXHashSet::GetKeyAndValue(char* parameter, char** pKey, char **pValue)
{
	char* pos;
	if ((pos = strchr(parameter, '!')) != NULL)
	{
		// change ! to terminating zero
		*pos = 0;
		pos++;
		// use left part as key
		(*pKey) = parameter;
		// return value in pointer pValue
		(*pValue) = pos;
		return true;
	}
	else 
		return false;
}

void CNWNXHashSet::Create(char* pHashSetName, int iSize)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);

	if (pHashSetWrapper)
	{
		pHashSetWrapper->Destroy();
		pHashSets->del(pHashSetName);
	}

	// create new HashSet
	if (iSize > 0)
	{
		pHashSetWrapper = new HashSetWrapper(iSize);
		pHashSets->insert(pHashSetName, pHashSetWrapper);
	}
}

bool CNWNXHashSet::Insert(char* pHashSetName, char *pKey, char *pValue)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
	{
		// add value to HashSet
		pHashSetWrapper->Insert(pKey,pValue);
		return true;
	}
	return false;
}

bool CNWNXHashSet::Delete(char* pHashSetName, char *pKey)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
	{
		pHashSetWrapper->Delete(pKey);
		return true;
	}
	return false;
}

char* CNWNXHashSet::Lookup(char* pHashSetName, char *pKey)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
	{
		// lookup value in HashSet
		return pHashSetWrapper->Lookup(pKey);
	}
	return NULL;
}

bool CNWNXHashSet::Valid(char* pHashSetName)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return true;
	else
		return false;
}

bool CNWNXHashSet::Exists(char* pHashSetName, char *pKey)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return pHashSetWrapper->Exists(pKey);
	else
		return false;
}

char* CNWNXHashSet::GetFirstKey(char* pHashSetName)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return pHashSetWrapper->GetFirstKey();
	else
		return NULL;
}

char* CNWNXHashSet::GetNextKey(char* pHashSetName)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return pHashSetWrapper->GetNextKey();
	else
		return NULL;
}

char* CNWNXHashSet::GetCurrentKey(char* pHashSetName)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return pHashSetWrapper->GetCurrentKey();
	else
		return NULL;
}

char* CNWNXHashSet::GetNthKey(char* pHashSetName, int iIndex)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return pHashSetWrapper->GetNthKey(iIndex);
	else
		return NULL;
}

int CNWNXHashSet::GetSize(char* pHashSetName)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return pHashSetWrapper->GetSize();
	else
		return 0;
}

bool CNWNXHashSet::HasNext(char* pHashSetName)
{
	HashSetWrapper* pHashSetWrapper = (HashSetWrapper*)pHashSets->lookup(pHashSetName);
	if (pHashSetWrapper)
		return pHashSetWrapper->HasNext();
	else
		return false;
}
