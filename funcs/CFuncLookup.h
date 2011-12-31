#pragma once

#include <string>
#include <hash_map>
#include "types.h"
#include "nwn_const.h"
#include "CParams.h"

#ifndef L_CAST
#define L_CAST static_cast<int(CFuncLookup::*)(CGameObject *oObject, char *Params)>
#endif


class CFuncLookup;

typedef struct Functions_s {
	CFuncLookup *pTHIS;
	int (__thiscall CFuncLookup::*pF)(CGameObject *oObject, char *Params);
}Functions;

class CFuncLookup {
private:
	//static stdext::hash_map<std::string, int (__thiscall CFuncLookup::*)(CGameObject *oObject, char *Params)> FunctionMap;
	static stdext::hash_map<std::string, Functions> FunctionMap;

public:
//	virtual ~CFuncLookup(); //just in case
	void AddFunction(std::string Name, int(__thiscall CFuncLookup::*p)(CGameObject *oObject, char *Params));
	int Execute(std::string Name, CGameObject *oObject, char *Params);

private: //no copying
	CFuncLookup(CFuncLookup const&);
	CFuncLookup& operator=(CFuncLookup const&);

protected:
	CFuncLookup();
	
};

/*
Base Class for implementing functions to be called fron nwn script
script functions can be encapsulated in new classes to make them independent of the main plugin class (nwnx_funcs in this case) which cuts 
down on (re)compile time and makes it easier to add new functionality.
New classes still have to be instantiated individually in CNWNXFuncs (still trying to find a workaround)

New classes must inherit from CFuncLookup and use AddFunction() in their constructor to make functions available to nwn script. (Function lookup and
execution is done in CNWNXFuncs::OnRequest with CFuncLookup::Execute.)
*/