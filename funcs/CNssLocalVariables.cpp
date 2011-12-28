#include "stdafx.h"
#include "CNssLocalVariables.h"

CNssLocalVariables::CNssLocalVariables() {
	getFirstNextVarIndex = -1;
	getFirstNextVarObj = 0x7FFFFFFF;

	AddFunction("GETLOCALVARIABLECOUNT", L_CAST(&CNssLocalVariables::GetLocalVariableCount));
	AddFunction("GETHASLOCALVARIABLE", L_CAST(&CNssLocalVariables::GetHasLocalVariable));
	AddFunction("GETFIRSTLOCALVAR", L_CAST(&CNssLocalVariables::GetFirstLocalVariable));
	AddFunction("GETNEXTLOCALVAR", L_CAST(&CNssLocalVariables::GetNextLocalVariable));
	AddFunction("GETLOCALVARBYPOSITION", L_CAST(&CNssLocalVariables::GetLocalVariableByPosition));
	AddFunction("PRINTLOCALVARS", L_CAST(&CNssLocalVariables::PrintLocalVars));
}

CNWSScriptVarTable* CNssLocalVariables::GetVarTable(CGameObject *oObject) {
	switch(oObject->obj_type) {
		case OBJECT_TYPE_AREA: { //Area
			return &((CNWSArea*)oObject)->area_vartable;
		} break;
		case OBJECT_TYPE_MODULE: { //Module
			return &((CNWSModule*)oObject)->mod_vartable;
		} break;
		default: {	//creature, item, placeable, etc
			return &((CNWSObject*)oObject)->obj_vartable;
		} break;
	}
	//_log(2, "o Error: Could not determine ScriptVarTable for object type: %08X\n", ((CGameObject*)gameObject)->obj_type);
	return NULL;
}

char* CNssLocalVariables::GetScriptVarType(int i) {
	switch(i) {
		case 1: return "INT"; break;
		case 2: return "FLT"; break;
		case 3: return "STR"; break;
		case 4: return "OID"; break;
		case 5: return "LOC"; break;
	}
	//_log(2, "o !!!Error!!! GetScriptVarType: Could not determine local variable type!\n");
	return "unknown";
}


CScriptVariable *CNssLocalVariables::GetLocalVarByPosition(CGameObject *oObject, int nIndex) {
	if (nIndex < 0) {
		nIndex = 0;
	}
	CScriptVariable *scriptVar = NULL;
	const CNWSScriptVarTable *vartable = GetVarTable(oObject);

	if (vartable  == NULL) {
		_log(2, "o Error: GetLocalVariableByPosition: Could not find scriptvar table for object %09X!\n", oObject->obj_id);
	}
	else {
		if (vartable->vt_list) {
			int n = vartable->vt_len;
			if (nIndex > n-1) { // the last variable is the NWNX!FUNCS one itself, no need to return it.
				_log(3, "o Error: GetLocalVariableByPosition: Requested local variable index (%i) exceeds number of local variables (%i) for object %09X!\n", nIndex, n, oObject->obj_id);
			}
			else {
				scriptVar = &vartable->vt_list[nIndex];
			}
		}
	}

	return scriptVar;
}

int CNssLocalVariables::GetLocalVariableCount(CGameObject *oObject, char *Params) {
	CNWSScriptVarTable *vartable;
	if ((vartable = GetVarTable(oObject)) == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	sprintf(Params, "%d", vartable->vt_len);

	return 1;
}

int CNssLocalVariables::GetHasLocalVariable(CGameObject *oObject, char *Params) {
	const CNWSScriptVarTable *vartable;
	if ((vartable = GetVarTable(oObject)) == NULL) {
		sprintf(Params, "-1");
		return 0;
	}
	CScriptVariable *scriptVar = vartable->vt_list;

	std::string sVarName = Params;
	int iP;

	uint32_t varType;
	int n = vartable->vt_len;
	iP = sVarName.find(" ");
	varType = atoi((sVarName.substr(iP+1)).c_str());
	sVarName = sVarName.substr(0, iP);

	for (int i=0; i<n; i++) {
		if ((strcmp(sVarName.c_str(), (&scriptVar->var_name)->text) == 0) && ( varType == 0 || varType == scriptVar->var_type)) {
			sprintf(Params, "%d", scriptVar->var_type);
			return 1;
		}
		scriptVar++;
	}
	sprintf(Params, "0");

	return 1;
}

int CNssLocalVariables::GetLocalVariableByPosition(CGameObject *oObject, char *Params) {
	_log(3, "CLocalVariables::GetLocalVariableByPosition\n");
	int nIndex = 0;
	CParams::ExtractP1(Params, nIndex);

	CScriptVariable *scriptVar = GetLocalVarByPosition(oObject, nIndex);
	if (scriptVar) {
		sprintf(Params, "%d¬%s", scriptVar->var_type, scriptVar->var_name.text);
		return 1;
	}

	sprintf(Params, "");
	return 0;
}

int CNssLocalVariables::GetFirstLocalVariable(CGameObject *oObject, char *Params) {
	// set the object id in any case, that way getnextlocalvariable won't throw an error if there are no locals
	getFirstNextVarObj = oObject->obj_id;
	CScriptVariable *scriptVar = GetLocalVarByPosition(oObject, 0);
	if (scriptVar) {
		sprintf(Params, "%d¬%s", scriptVar->var_type, scriptVar->var_name.text);
		getFirstNextVarIndex = 0;
		return 1;
	}
	getFirstNextVarIndex = -1;
	sprintf(Params, "");
	return 0;
}

int CNssLocalVariables::GetNextLocalVariable(CGameObject *oObject, char *Params) {
	if (getFirstNextVarIndex >= 0) {
		if (oObject->obj_id == getFirstNextVarObj) {
			++getFirstNextVarIndex;
			CScriptVariable *scriptVar = GetLocalVarByPosition(oObject, getFirstNextVarIndex);
			if(scriptVar) {
				sprintf(Params, "%d¬%s", scriptVar->var_type, scriptVar->var_name.text);
				return 1;
			}
			else {
				getFirstNextVarIndex = -1; // don't even read anymore 
			}
		}
		else {
			_log(2, "o ERROR: GetNextLocalVar used on an object before GetFirstLocalVar!\n");
		}
	}
	sprintf(Params, "");
	return 0;
}

int CNssLocalVariables::PrintLocalVars(CGameObject *oObject, char *Params) {
	const CNWSScriptVarTable *vartable = GetVarTable(oObject);
	if (vartable == NULL) {
		sprintf(Params, "-1");
		return 0;
	}

	CScriptVariable *scriptVar = vartable->vt_list; 

	uint32_t varType;
	uint32_t varValue;
	int n = vartable->vt_len;

	_log(0, "o Printing local vars for %08X\n", oObject->obj_id);
	for (int i=0; i<n; i++) {
		varType = scriptVar->var_type;
		varValue = scriptVar->var_value;
		switch (varType) {
			case 1: _log(0, "  [%s] %s = %i\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, varValue); break;
			case 2: _log(0, "  [%s] %s = %f\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, *(float*)&scriptVar->var_value); break;
			case 3: _log(0, "  [%s] %s = %s\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, ((CExoString*)*&varValue)->text); break;
			case 4: _log(0, "  [%s] %s = %08X\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, varValue); break;
			case 5: {
				Vector *v = (Vector*)*&varValue;
				_log(0, "  [%s] %s = (%f, %f, %f)\n", GetScriptVarType(varType), (&scriptVar->var_name)->text, v->x, v->y, v->z); break;
			}
		}
		scriptVar++;
	}
	return 1;
}
