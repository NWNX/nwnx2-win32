#include "stdafx.h"
#include "CFuncLookup.h"

stdext::hash_map<std::string, int (__thiscall CFuncLookup::*)(CGameObject *oObject, char *Params)> CFuncLookup::FunctionMap;

CFuncLookup::CFuncLookup() {
}

int CFuncLookup::Execute(std::string Name, CGameObject *oObject, char *Params) {
	stdext::hash_map<std::string, int (__thiscall CFuncLookup::*)(CGameObject *oObject, char *Params)>::iterator it = FunctionMap.find(Name);
	if (it != FunctionMap.end()) {
//		pFunc = it->second;
		(*this.*(it->second))(oObject, Params);
		return 1;
	}
	return 0;
}

void CFuncLookup::AddFunction(std::string F_Name, int(__thiscall CFuncLookup::*p)(CGameObject *oObject, char *Params)) {
	if (FunctionMap.find(F_Name) == FunctionMap.end()) {
		FunctionMap[F_Name] = p;
	}
	else {
		printf("Duplicate Lookup Function: %s\n", F_Name.c_str());
	}
}

//*************
