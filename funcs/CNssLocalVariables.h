#pragma once
#include "CFunclookup.h"
#include "types.h"

class CNssLocalVariables :	public CFuncLookup {
public:
	CNssLocalVariables();

private: //helper functions
	CNWSScriptVarTable* GetVarTable(CGameObject *oObject);
	CScriptVariable *GetLocalVarByPosition(CGameObject *oObject, int nIndex);
	char* GetScriptVarType(int i);

	int getFirstNextVarIndex;
	nwn_objid_t getFirstNextVarObj;

public: //Script functions
	int GetLocalVariableByPosition(CGameObject *oObject, char *Params);
	int GetFirstLocalVariable(CGameObject *oObject, char *Params);
	int GetNextLocalVariable(CGameObject *oObject, char *Params);
	int GetLocalVariableCount(CGameObject *oObject, char *Params);
	int GetHasLocalVariable(CGameObject *oObject, char *Params);
	int PrintLocalVars(CGameObject *oObject, char *Params);

};
