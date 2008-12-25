#pragma once

#ifdef VAULTSTER_EXPORTS
#define VAULTSTER_API extern "C" __declspec(dllexport)
#else
#define VAULTSTER_API extern "C" __declspec(dllimport)
#endif

VAULTSTER_API CNWNXBase* GetClassObject ();
