#include "stdafx.h"
#include "nwnx_areas.h"
#include "madchook.h"
#include <string>

extern CNWNXAreas NWNXAreas;

#define _log(a,b,...) if(a<=NWNXAreas.debugLevel)NWNXAreas.LOG(b,__VA_ARGS__)

void (*nwn_CExoResMan__ExistsNextHook)();
void (*nwn_OverridePlayerTURDAreaNextHook)();
void (*nwn_OverrideSetPlayerAreaFromTURDNextHook)();

char *git;
int iType;
std::string resPath;
FILE *GIT = NULL;
void __declspec(naked)CExoResMan__ExistsHookProc() {
	__asm {
		pushad	
		mov eax, [esp+0x24]
		mov git, eax
		mov eax, [esp+0x28]
		mov iType, eax;
	}

	if (iType != 2023) {
		__asm {
			popad
			jmp nwn_CExoResMan__ExistsNextHook
		}
	}
	else {
		_log(3, "o GIT request\n");
		resPath = NWNXAreas.m_sourcePath;
		resPath += "are\\";
		resPath += git;
		resPath += ".git";
		GIT = fopen(resPath.c_str(), "rb");
		if (GIT == NULL) {
			_log(3, "o File not found\n");
			__asm {
				popad
				jmp nwn_CExoResMan__ExistsNextHook
			}
		}
		else {
			_log(2, "o external git found: %s\n", resPath.c_str());
			fclose(GIT); // just needed to know it was there
			__asm {
				popad
				mov eax, 1
				retn 0x0C;
			}
		}
	}
}

uint32_t *pTHIS = NULL;
CNWSArea *OverrideArea = NULL;
void __declspec(naked)OverridePlayerTURDAreaHookProc() {
	__asm {
		mov ecx, esi //this
		pushad
		mov pTHIS, ecx
	}
	
	OverrideArea = NWNXAreas.GetOverrideArea((CNWSCreature*)pTHIS);

	if (!OverrideArea) {
		_asm {
			popad
			jmp nwn_OverridePlayerTURDAreaNextHook // no override area, let the function do it's thing
		}
	}
	else {
		__asm {
			popad
			mov eax, OverrideArea
			mov ebx, 0x0042F5EB
			jmp ebx 
		}
	}
}

CNWSPlayerTURD *TURD;
CNWSCreature *Cre;
uint32_t AreaID=OBJECT_INVALID;
float P_X, P_Y, P_Z, O_X, O_Y, O_Z;
void __declspec(naked)OverrideSetPlayerAreaFromTURDHookProc() {
	__asm {
		mov eax, edi //get turd

		pushad
		mov TURD, eax
	}

	_log(3, "TURD OVERRIDE");

	if (NWNXAreas.CheckArea(TURD)) {
		AreaID = TURD->TURD_AreaId;
		P_X = TURD->TURD_PositionX;
		P_Y = TURD->TURD_PositionY;
		P_Z = TURD->TURD_PositionZ;
		O_X = TURD->TURD_OrientatX;
		O_Y = TURD->TURD_OrientatY;
		O_Z = TURD->TURD_OrientatZ;

		__asm {
			popad
			mov eax, AreaID
			mov [edi+0x74], eax
			mov eax, P_X
			mov [edi+0x78], eax
			mov eax, P_Y
			mov [edi+0x7C], eax
			mov eax, P_Z 
			mov [edi+0x80], eax
			mov eax, O_X
			mov [edi+0x84], eax
			mov eax, O_Y
			mov [edi+0x88], eax
			mov eax, O_Z
			mov [edi+0x90], eax

			jmp nwn_OverrideSetPlayerAreaFromTURDNextHook

		}
	}
	else {
		__asm {
			popad
			jmp nwn_OverrideSetPlayerAreaFromTURDNextHook
		}
	}
}


void HookFunctions() {
	DWORD org_CExoResMan__Exists=0x00416BE0;
	//DWORD org_OverridePlayerTURDArea=0x0042F5D9;

	//DWORD org_OverrideSetPlayerAreaFromTURD=0x0042F830;

	if (strlen(NWNXAreas.m_sourcePath) > 0) {
		if (HookCode((PVOID) org_CExoResMan__Exists, CExoResMan__ExistsHookProc, (PVOID*)&nwn_CExoResMan__ExistsNextHook)) _log(0, "* CExoResMan__Exists hooked; SourcePath: '%s'\n", NWNXAreas.m_sourcePath);
	}

	// catch and change the area on logout
	//if (HookCode((PVOID) org_OverridePlayerTURDArea, OverridePlayerTURDAreaHookProc, (PVOID*)&nwn_OverridePlayerTURDAreaNextHook)) _log(0, "* nwn_OverridePlayerTURDArea hooked\n");
	
	// catch and change the area on login
	// this crashes the server when the player logs back in: CNWSModule::LoadTURDLIST: virtual GetFirstName
//	if (HookCode((PVOID) org_OverrideSetPlayerAreaFromTURD, OverrideSetPlayerAreaFromTURDHookProc, (PVOID*)&nwn_OverrideSetPlayerAreaFromTURDNextHook)) _log(0, "* OverrideSetPlayerAreaFromTURD hooked\n");
}