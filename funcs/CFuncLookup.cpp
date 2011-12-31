#include "stdafx.h"
#include "CFuncLookup.h"

//stdext::hash_map<std::string, int (__thiscall CFuncLookup::*)(CGameObject *oObject, char *Params)> CFuncLookup::FunctionMap;
stdext::hash_map<std::string, Functions> CFuncLookup::FunctionMap;

CFuncLookup::CFuncLookup() {
}

void CFuncLookup::AddFunction(std::string F_Name, int(__thiscall CFuncLookup::*p)(CGameObject *oObject, char *Params)) {
	if (FunctionMap.find(F_Name) == FunctionMap.end()) {
		Functions f = {this, p};
		FunctionMap[F_Name] = f;
	}
	else {
		printf("Duplicate Lookup Function: %s\n", F_Name.c_str());
	}
}

int CFuncLookup::Execute(std::string Name, CGameObject *oObject, char *Params) {
	stdext::hash_map<std::string, Functions>::iterator it = FunctionMap.begin();

	it = FunctionMap.find(Name);
	if (it != FunctionMap.end()) {
		Functions *f = &it->second;
		CFuncLookup *pTHIS = f->pTHIS;
		(*pTHIS.*(f->pF))(oObject, Params);
		return 1;
	}
	return 0;
}

//*************

