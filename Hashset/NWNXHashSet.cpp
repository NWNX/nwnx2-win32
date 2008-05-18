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
	#ifdef _DEBUG
	char log[MAX_PATH];
	sprintf (log, "%s\\nwnx_hashset.txt", LogDir);
	if (!CNWNXBase::OnCreate(log))
		return false;

	Log("NWNX HashSet V.1.0\n");
	Log("(c) 2003 by Ingmar Stieger (Papillon)\n");
	Log("visit us at http://www.nwnx.org\n\n");
	#endif

	// create hash table with space for 5000 entries
	// this hash will contain the pointers to our HashSets
	pHashSets = new CHashTable(5000);
	if (pHashSets->getSize() == 0)
	{
		#ifdef _DEBUG
		Log("* Critical error: creation of hash table failed!\n");
		#endif
		return false;
	}
	else 
	{
		#ifdef _DEBUG
		Log("* Module loaded successfully.\n");
		#endif
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
			#ifdef _DEBUG
			Log("-> lookup request on hashset %s, key %s, answering with %s\n", pUniqueHashSet, pKey, pResult);
			#endif
		}
	}
	else if (strcmp(Request, "INSERT") == 0)
	{
		if (GetKeyAndValue(pReminder, &pKey, &pValue))
		{
			#ifdef _DEBUG
			Log("-> insert request on hashset %s, key %s, value %s\n", pUniqueHashSet, pKey, pValue);
			#endif
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
			#ifdef _DEBUG
			Log("-> delete request on hashset %s, key %s\n", pUniqueHashSet, pKey);
			#endif
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
			#ifdef _DEBUG
			Log("-> valid request on hashset %s\n", pUniqueHashSet);
			#endif
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
			#ifdef _DEBUG
			Log("-> exists request on hashset %s, key %s\n", pUniqueHashSet, pKey);
			#endif
			if (Exists(pUniqueHashSet, pKey))
				pResult = "1";
			else
				pResult = "0";
		}
	}
	else if (strcmp(Request, "GETFIRSTKEY") == 0)
	{
		#ifdef _DEBUG
		Log("-> getfirstkey request on hashset %s\n", pUniqueHashSet);
		#endif
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
		#ifdef _DEBUG
		Log("-> getnextkey request on hashset %s\n", pUniqueHashSet);
		#endif
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
		#ifdef _DEBUG
		Log("-> getcurrentkey request on hashset %s\n", pUniqueHashSet);
		#endif
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
		#ifdef _DEBUG
		Log("-> getnthkey request on hashset %s, key number %d\n", pUniqueHashSet, iIndex);
		#endif
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
		#ifdef _DEBUG
		Log("-> hasnext request on hashset %s\n", pUniqueHashSet);
		#endif
		if (HasNext(pUniqueHashSet))
			pResult = "1";
		else
			pResult = "0";
	}
	else if (strcmp(Request, "GETSIZE") == 0)
	{
		#ifdef _DEBUG
		Log("-> size request on hashset %s\n", pUniqueHashSet);
		#endif
		sprintf(cLastValue, "%d", GetSize(pUniqueHashSet));
		pResult = cLastValue;
	}
	else if (strcmp(Request, "DESTROY") == 0)
	{
		#ifdef _DEBUG
		Log("* Destroy hashset %s\n", pUniqueHashSet);
		#endif
		Create(pUniqueHashSet, 0);
		iLastOperation = HashSet_SUCCESS;
	}
	else if (strcmp(Request, "CREATE") == 0)
	{
		iIndex = atoi(pReminder);
		#ifdef _DEBUG
		Log("* Create HashSet '%s' with size : %d\n", pUniqueHashSet, iIndex);
		#endif
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
