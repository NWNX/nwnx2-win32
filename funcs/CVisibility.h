#pragma once
/*
    NWNX Visibility - interface for the CNWNXVisibility class.
    (c) 2007-2010 virusman (virusman@virusman.ru)

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
*/

#include "types.h"
#include <map>
#include <string>
#include "CFuncLookup.h"

using namespace std;

enum OverrideType {
	Default,
	AlwaysVisible,
	AlwaysInvisible
};

typedef map< unsigned int, unsigned int, less<unsigned int> > ObjectVisMap;

struct ObjectEntry {
	OverrideType eOverrideType;
	ObjectVisMap vismap;
};

typedef map< unsigned int, ObjectEntry, less<unsigned int> > ObjectsMap;

class CVisibility : public CFuncLookup {
public:
	CVisibility();
	~CVisibility();

	int TestVisibility(nwn_objid_t oObject1, nwn_objid_t oObject2, int &nResult);

private:
	ObjectsMap objects;
	ObjectsMap::iterator it;
	ObjectVisMap::iterator it_Vis;

	void SetVisibilityOverride(nwn_objid_t oObject1, OverrideType eOverrideType);
	void SetVisibility(nwn_objid_t oObject1, nwn_objid_t oObject2, unsigned int nValue);

	int GetVisibilityOverride(nwn_objid_t oObject);
	int GetVisibility(nwn_objid_t oObject1, nwn_objid_t oObject2);

public:
	int NssSetVisibility(CGameObject *oObject, char *Params);
	int NssGetVisibility(CGameObject *oObject, char *Params);

	int NssSetVisibilityOverride(CGameObject *oObject, char *Params);
	int NssGetVisibilityOverride(CGameObject *oObject, char *Params);
};
