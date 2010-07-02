#include "stdafx.h"
#include "nwnx_combat.h"

CNWNXCombat NWNXCombat;

extern "C" __declspec(dllexport) CNWNXBase* GetClassObject()
{
	return &NWNXCombat;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}