/***************************************************************************
    HashTable.cpp - Implementation of the CHashTable class.
    Copyright (C) 2003 Jeroen Broekhuizen
    email: 

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
#include "HashTable.h"
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHashTable::CHashTable()
{
	m_Items = NULL;
	m_iTableSize = 0;
	m_iCount = 0;
}

CHashTable::~CHashTable()
{
	// destroy the items
	if (m_Items != NULL)
		DeleteAll ();
}

bool CHashTable::Create(int Size)
{
	// create the table
	m_iTableSize = Size;
	m_Items = new CItem* [Size];
	if (m_Items == NULL)
		return false;

	// initialize the items
	for (int i = 0; i < Size; i++)
		m_Items[i] = NULL;

	return true;
}

void* CHashTable::Delete(char *Key)
{
	// find the position in the table
	int iIndex = Hash (Key) % m_iTableSize;
	if (m_Items[iIndex] == NULL)
		return NULL;

	// free item & return current data
	void* pData = m_Items[iIndex]->Data;
	delete m_Items[iIndex]->Key;
	/* (changed by pap)
	delete m_Items[iIndex];
	m_Items[iIndex] = NULL;
	m_iCount--;
	return pData;
	*/
	delete m_Items[iIndex]->Data;
	m_Items[iIndex] = NULL;
	m_iCount--;
	return NULL;
}

void CHashTable::DeleteAll()
{
	// bail out if table is not yet created
	if (m_Items == NULL)
		return;

	// destroy all elements
	for (int i = 0; i < m_iTableSize; i++)
	{
		if (m_Items[i] != NULL)
		{
			// free (m_Items[i]->Key);
			delete m_Items[i];
			m_Items[i] = NULL;
		}
	}
	// destroy the table
	delete[] m_Items;
	m_Items = NULL;
	// reset table size and counter
	m_iTableSize = 0;
	m_iCount = 0;
}

UINT CHashTable::Hash(char *Key)
{
	UINT code = 0;
	int ch;

	// create hash code
	while (Key[0])
	{
		ch = *Key++;
		code ^= ch;
		code <<= 1;
	}
	return code;
}

bool CHashTable::Insert(char *Key, void *Data)
{
	// search spot in table (with hash code)
	UINT iIndex = Hash(Key) % m_iTableSize;
	if (m_Items[iIndex] != NULL)
		return false;

	// create the new item
	m_Items[iIndex] = new CItem (Key, Data);
	if (m_Items[iIndex] == NULL)
		return false;
	m_iCount++;

	return true;
}

void* CHashTable::Lookup(char *Key)
{
	// see if there is something in the tabel
	UINT iIndex = Hash(Key) % m_iTableSize;
	if (m_Items[iIndex] != NULL)
		return m_Items[iIndex]->Data;

	// return data
	return NULL;
}

int CHashTable::GetCount()
{
	// return number of items in the table
	return m_iCount;
}

int CHashTable::GetFirstItem()
{
	// find the first valid item in the table
	for (int i = 0; i < m_iTableSize; i++)
		if (m_Items[i] != NULL)
			return i;
	return -1;
}

void* CHashTable::GetNextItem(int &pos)
{
	int i = pos; // remember current item

	// search for next item in the table
	for (pos++; pos < m_iTableSize; pos++)
		if (m_Items[pos] != NULL)
			break;

	// look for endpoint
	if (pos == m_iTableSize)
		pos = -1;

	// return data of remembered item
	return m_Items[i]->Data;
}
