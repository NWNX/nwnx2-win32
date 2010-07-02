#include "stdafx.h"
#include "nwnx_trinity.h"

CNWNXTrinity NWNXTrinity;

extern "C" __declspec(dllexport) CNWNXBase* GetClassObject()
{
	return &NWNXTrinity;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
