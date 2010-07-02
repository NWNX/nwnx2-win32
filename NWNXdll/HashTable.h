/***************************************************************************
    HashTable.h - Interface for the CHashTable class.
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


// HashTable.h: interface for the CHashTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HASHTABLE_H__C0E249B5_6F15_4DE1_B413_D32FDBB64E7B__INCLUDED_)
#define AFX_HASHTABLE_H__C0E249B5_6F15_4DE1_B413_D32FDBB64E7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdio.h>
#include <stdlib.h>

class CHashTable  
{
	class CItem
	{
	public:
		CItem () {}
		CItem (char* key, void* data): Key(_strdup(key)), Data(data) {}
		~CItem () { free (Key); }
		char* Key;
		void* Data;
	};
public:
	CHashTable();
	virtual ~CHashTable();

	bool Create (int Size = 211);
	void* Delete (char* Key);
	void DeleteAll ();

	bool Insert (char* Key, void* Data);
	void* Lookup (char* Key);
	int GetCount ();

	int GetFirstItem ();
	void* GetNextItem (int& pos);

protected:
	UINT Hash (char* Key);

private:
	CItem** m_Items;
	int m_iTableSize;
	int m_iCount;
};

#endif // !defined(AFX_HASHTABLE_H__C0E249B5_6F15_4DE1_B413_D32FDBB64E7B__INCLUDED_)
