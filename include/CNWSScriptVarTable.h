#ifndef _NX_NWN_STRUCT_CNWSSCRIPTVARTABLE_
#define _NX_NWN_STRUCT_CNWSSCRIPTVARTABLE_

struct CNWSScriptVarTable_s {
    CScriptVariable    *vt_list;
    uint32_t            vt_len;

	float 				GetFloat(CExoString &VarName);
	int 				GetInt(CExoString &VarName);
	CScriptLocation 	GetLocation(CExoString &VarName);
	CExoString*			GetString(CExoString &VarName);
	void 				SetInt(CExoString &VarName, int VarValue, int a3);
};

#endif