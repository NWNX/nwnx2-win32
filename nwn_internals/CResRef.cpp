#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

CResRef* (__thiscall *CResRef__CResRef)(CResRef *pTHIS, CExoString const &) = (CResRef* (__thiscall*)(CResRef *pTHIS, CExoString const &))0x00415AD0;

CResRef *CResRef::CResRef(CExoString const &Ref) {
	return CResRef__CResRef(this, Ref);
}