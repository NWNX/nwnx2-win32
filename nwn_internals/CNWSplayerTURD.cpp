#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void * (__thiscall *CNWSPlayerTURD__scalar_deleting_destructor)(CNWSPlayerTURD_s *pTHIS, uint32_t Flags) = (void* (__thiscall*)(CNWSPlayerTURD_s *pTHIS, uint32_t Flags))0x004DBFF0;
	
void *CNWSPlayerTURD_s::ScalarDestructor(uint32_t Flags) {
	return CNWSPlayerTURD__scalar_deleting_destructor(this, Flags);
}