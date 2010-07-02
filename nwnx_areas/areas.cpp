#include "stdafx.h"
#include "nwnx_areas.h"

CNWNXAreas NWNXAreas;

extern "C" __declspec(dllexport) CNWNXBase* GetClassObject()
{
	return &NWNXAreas;
}

BOOL APIENTRY DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
