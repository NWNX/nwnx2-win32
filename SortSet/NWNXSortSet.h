/***************************************************************************
    NWNX FOR LINUX Minimal Network eXtender plugin Class interface
    Copyright (C) 2003 John Klar (paladin at projectplasma dot com)

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

#ifndef NWNXSortSet_h_
#define NWNXSortSet_h_
#include "..\NWNXdll\NWNXBase.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdio.h>

#include <string.h> /* memset() */

#include <errno.h>
#include <signal.h>

// using namespace::std;

#include "SortSetImpl.h"

typedef std::map<std::string, SortSet> sortsetdict;

class CNWNXSortSet : public CNWNXBase
{
public:
	CNWNXSortSet();
	~CNWNXSortSet();

	BOOL OnCreate(const char *LogDir=NULL);
	char *OnRequest(char* gameObject, char* Request, char* Parameters);
	// bool OnRelease();

protected:
	bool Configure();

	char *CNWNXSortSet::GetNextArg(char *start, char *dest, int width);
	
	bool SetInit(const char *setkey);
	bool Length(const char *setkey);
	bool Add(const char *setkey, const char *key, const char *sort, const char *value);
	bool SetByIdx(const char *setkey, const char *index, const char *sort, const char *value);
	bool SetByTag(const char *setkey, const char *resref, const char *sort, const char *value);
	bool Remove(const char *setkey, const char *index);
	bool GetByIdx(const char *setkey, const char *index);
	bool GetByTag(const char *setkey, const char *resref);
	bool Exists(const char *setkey, const char *resref);
	bool Sort(const char *setkey);

private:
	sortsetdict sets;
	char *results;
};

#endif
