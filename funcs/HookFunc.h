#pragma once

static void (__fastcall *nwn_CreateNewGeometryNextHook)(CNWSTrigger *pTHIS, void *pVOID, float size, CScriptLocation *Loc, CNWSArea *Area);
static int (__fastcall *CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyTypeNEXT)(void *pTHIS, void *pVOID, int a1, int a2);
static int (__fastcall *CNWVirtualMachineCommands__ExecuteCommandItemPropertyEffectNEXT)(void *pTHIS, void *pVOID, int a1, int a2);
static int (__fastcall *CNWSMessage__TestObjectVisibleNEXT)(void *pMessage, void *pVOID, CNWSObject *pObject1, CNWSObject *pObject2);
static int (__fastcall *ExecuteCommandEffectAppear_Next)(void *pTHIS, void *pVOID, int a2, int a3);
static signed int (__fastcall *CNWSCreatureStats__GetEffectImmunityNEXT)(CNWSCreatureStats *Stats_this, void *pVOID, unsigned __int8 a2, CNWSCreature *Versus);
static int (__fastcall *CServerExoAppInternal__RemovePCFromWorldNEXT)(CServerExoAppInternal *pTHIS, void *pVOID, CNWSPlayer_s *a2);

//static char (__fastcall *nwn_CNWSCreatureStats__GetDEXModNextHook)(CNWSCreatureStats *Stats, void *pVOID, int a3);
//static int (__fastcall *CNWSEffectListHandler__OnApplyModifyNumAttacksNEXT)(void *pTHIS, void *pVOID, CNWSObject* obj, CGameEffect *Eff, int a3);

class CHookFunctions {
public:
	CHookFunctions(int debugLevel);

private:
	static int debugLevel;
	void HookFunctions();

	DWORD org_CreateNewGeometry;
	DWORD org_ExecuteCommandEffectAppear;
	DWORD CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyTypeORG;
	DWORD CNWVirtualMachineCommands__ExecuteCommandItemPropertyEffectORG;
	DWORD CNWSMessage__TestObjectVisibleORG;
	DWORD CNWSCreatureStats__GetEffectImmunityORG;
	DWORD CServerExoAppInternal__RemovePCFromWorldORG;
	
	static void __fastcall CreateNewGeometryHookProc(CNWSTrigger *pTHIS, void *pVOID, float size, CScriptLocation *Loc, CNWSArea *Area);
	static int __fastcall ExecuteCommandEffectAppear_Hook(void *pTHIS, void *pVOID, int a2, int a3);
	static int __fastcall CNWVirtualMachineCommands__ExecuteCommandGetItemPropertyTypeHOOK(void *pTHIS, void *pVOID, int a1, int a2);
	static int __fastcall CNWVirtualMachineCommands__ExecuteCommandItemPropertyEffectHOOK(void *pTHIS, void *pVOID, int a1, int a2);
	static int __fastcall CNWSMessage__TestObjectVisibleHOOK(void *pMessage, void *pVOID, CNWSObject *pObject1, CNWSObject *pObject2);
	static signed int __fastcall CNWSCreatureStats__GetEffectImmunityHOOK(CNWSCreatureStats *Stats_this, void *pVOID, unsigned __int8 a2, CNWSCreature *Versus);
	static int __fastcall CServerExoAppInternal__RemovePCFromWorldHOOK(CServerExoAppInternal *pTHIS, void *pVOID, CNWSPlayer_s *a2);

private:
	CHookFunctions();
	CHookFunctions(const CHookFunctions &HF);
	CHookFunctions& operator=(const CHookFunctions& HF);

//	static char __fastcall CNWSCreatureStats__GetDEXModHook(CNWSCreatureStats *Stats, void *pVOID, int a3);
//	static int __fastcall CNWSEffectListHandler__OnApplyModifyNumAttacksHook(void *pTHIS, void *pVOID, CNWSObject* obj, CGameEffect *Eff, int a3);
};