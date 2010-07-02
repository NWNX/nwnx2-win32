#include "stdafx.h"
#include "nwnx_funcs.h"

CNWNXFuncs NWNFuncs;

extern "C" __declspec(dllexport) CNWNXBase* GetClassObject()
{
	return &NWNFuncs;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}