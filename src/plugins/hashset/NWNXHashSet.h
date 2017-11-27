	/***************************************************************************
    NWNXHashSet.h - Interface for the CNWNXHashSet class.
    Copyright (C) 2003 Jeroen Broekhuizen (nwnx@jengine.nl)

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

#if !defined(AFX_NWNXHashSet_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
#define AFX_NWNXHashSet_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_

#include "NWNXBase.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <vector>
#include <windows.h>
#include <malloc.h>

#include "HashTable.h"

#define HashSet_SUCCESS true
#define HashSet_FAILURE false

class HashSetWrapper
{
public:

	HashSetWrapper(int size)
	{
		pHashTable = new CHashTable(size);
		pKeys = new std::vector<char*>();
		currentKey = 0;
	}

	void Insert(char* pKey, char* pValue)
	{
		if (Exists(pKey))
			pHashTable->del(pKey);
		else
			pKeys->push_back(_strdup(pKey));
		pHashTable->insert(pKey, pValue);
	}

	char* Lookup(char* pKey)
	{
		return (char*) pHashTable->lookup(pKey);
	}

	void Delete(char* pKey)
	{
		if (Exists(pKey))
		{
			free(pHashTable->lookup(pKey));
			pHashTable->del(pKey);
			std::vector<char*>::iterator it = pKeys->begin();
			while (it != pKeys->end())
			{
				if (strcmp(*it, pKey) == 0)
				{
					free(*it);
					pKeys->erase(it);
					break;
				}
				it++;
			}
		}
	}

	void Destroy()
	{
		// free data
		char* data;
		std::vector<char*>::iterator it = pKeys->begin();
		while (it != pKeys->end())
		{
			data = (char*)pHashTable->lookup(*it);
			pHashTable->del(*it);
			free(*it);
			free(data);
			it++;
		}
		pKeys->clear();
		delete pHashTable;
		delete pKeys;
	}

	char* GetFirstKey()
	{
		pKeysIterator = pKeys->begin();
		if (pKeysIterator != pKeys->end())
			return *pKeysIterator;
		else
			return NULL;
	}

	char* GetNextKey()
	{
		pKeysIterator++;
		if (pKeysIterator != pKeys->end())
			return *pKeysIterator;
		else
			return NULL;
	}

	char* GetCurrentKey()
	{
		if (pKeysIterator != pKeys->end())
			return *pKeysIterator;
		else
			return NULL;
	}

	char* GetNthKey(int iIndex)
	{
		if ((iIndex > 0) && (iIndex <= pKeys->size()))
			return pKeys->at(iIndex - 1);
		else
			return NULL;
	}

	bool Exists(char* pKey)
	{
		return (pHashTable->lookup(pKey) != NULL);
	}

	int GetSize()
	{
		return (pKeys->size());
	}

	bool HasNext()
	{
		return (pKeysIterator + 1!= pKeys->end());
	}

	CHashTable *pHashTable;
	std::vector<char*>* pKeys;
	std::vector<char*>::iterator pKeysIterator;
	int currentKey;
};

class CNWNXHashSet : public CNWNXBase
{
public:
	CNWNXHashSet();
	virtual ~CNWNXHashSet();

	BOOL OnCreate(const char* LogDir);
	char* OnRequest(char* gameObject, char* Request, char* Parameters);
	BOOL OnRelease();

protected:
	bool GetHashSetName(char *parameter, char **pName, char **pReminder);
	bool GetKey(char* Parameter, char **pKey);
	bool GetKeyAndValue(char* parameter, char** pKey, char **pValue);

	bool SplitParameter (char* Parameter, int& iIndex, char **pValue);

	void Create(char *pHashSetName, int iSize);
	bool Insert(char* pHashSetName, char *pKey, char* pValue);
	bool Delete(char* pHashSetName, char *pKey);
	char* Lookup(char* pHashSetName, char *pKey);
	bool Valid(char* pHashSetName);
	bool Exists(char* pHashSetName, char *pKey);
	char* GetFirstKey(char* pHashSetName);
	char* GetNextKey(char* pHashSetName);
	char* GetCurrentKey(char* pHashSetName);
	char* GetNthKey(char* pHashSetName, int iIndex);
	int GetSize(char* pHashSetName);
	bool HasNext(char* pHashSetName);

private:
	int iLastOperation;
	CHashTable* pHashSets; // pointers to hashsets of game objects
	char* temp;
	char cLastValue[64];
};

#endif // !defined(AFX_NWNXHashSet_H__925D298E_8775_4BBF_8D41_479D2179BABD__INCLUDED_)
