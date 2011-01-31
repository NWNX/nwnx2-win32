#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void	(__thiscall *CScriptEvent__dtor)(CScriptEvent *pTHIS) = (void(__thiscall*)(CScriptEvent *pTHIS))0x00469950;
int		(__thiscall *CScriptEvent__SetInteger)(CScriptEvent *PTHIS, int nNthInt, int Value) = (int(__thiscall*)(CScriptEvent *pTHIS, int nNthInt, int Value))0x00506720;

CScriptEvent_s::CScriptEvent_s() {
	integer_list = NULL;
	integer_count = 0;
	integer_alloc = 0;
	float_list = NULL;
	float_count = 0;
	float_alloc = 0;
	dword1C = NULL;
	exostring_count = 0;
	exostring_alloc = 0;
	dword28 = NULL;
	object_count = 0;
	object_alloc = 0;
	EventType = 0;
}

CScriptEvent_s::~CScriptEvent_s() {
	CScriptEvent__dtor(this);
}

int CScriptEvent_s::SetInteger(int Nth, int Value) {
	return CScriptEvent__SetInteger(this, Nth, Value);
}
