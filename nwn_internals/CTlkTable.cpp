#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CExoString const & (__thiscall *CTlkTable__GetCustomTokenValue)(CTlkTable *pTHIS, uint32_t a2) = (CExoString const & (__thiscall*)(CTlkTable *pTHIS, uint32_t a2))0x0043C370;


CExoString const &CTlkTable_s::GetCustomTokenValue(uint32_t a2) {
	return CTlkTable__GetCustomTokenValue(this, a2);
}