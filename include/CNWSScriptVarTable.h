#ifndef _NX_NWN_STRUCT_CNWSSCRIPTVARTABLE_
#define _NX_NWN_STRUCT_CNWSSCRIPTVARTABLE_

struct CNWSScriptVarTable_s {
    CScriptVariable    *vt_list;
    uint32_t            vt_len;

	void 				DestroyFloat(CExoString &VarName);
	void				DestroyInt(CExoString &VarName);
	void				DestroyObject(CExoString &VarName);
	void				DestroyString(CExoString &VarName);
	float 				GetFloat(CExoString &VarName);
	int 				GetInt(CExoString &VarName);
	CScriptLocation 	GetLocation(CExoString &VarName);
	nwn_objid_t 		GetObject(CExoString &VarName);
	CExoString*			GetString(CExoString &VarName);
	void 				SetFloat(CExoString &VarName, float VarValue);
	void 				SetInt(CExoString &VarName, int VarValue, int a3);
	void 				SetObject(CExoString &VarName, nwn_objid_t Object_oID);
	void 				SetString(CExoString &VarName, CExoString &VarValue);
};

#endif