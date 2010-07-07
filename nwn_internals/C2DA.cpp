#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

C2DA*			(__thiscall *C2DA__C2DA)(C2DA *pTHIS, CResRef, int) = (C2DA* (__thiscall*)(C2DA *pTHIS, CResRef, int))0x0041DF10;
int 			(__thiscall *C2DA__Load2DArray)(C2DA *pTHIS) = (int (__thiscall*)(C2DA *pTHIS))0x0041E720;
int 			(__thiscall *C2DA__GetINTEntry_strcol)(C2DA *pTHIS, int nRow, CExoString const &ColName, int *Ret) = (int (__thiscall*)(C2DA *pTHIS, int nRow, CExoString const &ColName, int *Ret))0x0041E540;
int 			(__thiscall *C2DA__GetINTEntry_intcol)(C2DA *pTHIS, int nRow, int nCol, int *Ret) = (int (__thiscall*)(C2DA *pTHIS, int nRow, int nCol, int *Ret))0x0041E430;
int 			(__thiscall *C2DA__GetCExoStringEntry)(C2DA *pTHIS, int nRow, CExoString const &ColName, CExoString *Ret) = (int (__thiscall*)(C2DA *pTHIS, int nRow, CExoString const &ColName, CExoString *Ret))0x0041E250;
void * 			(__thiscall *C2DA__vect_destructor)(C2DA *pTHIS, unsigned int) = (void* (__thiscall*)(C2DA *pTHIS, unsigned int))0x0041E0B0;

C2DA *C2DA_s::C2DA(CResRef a1, int a2) {
	return C2DA__C2DA(this, a1, a2);
}

int C2DA_s::Load2DArray() {
	return C2DA__Load2DArray(this);
}

int C2DA_s::GetCExoStringEntry(int nRow, CExoString const &ColName, CExoString *Ret) {
	return C2DA__GetCExoStringEntry(this, nRow, ColName, Ret);
}

int C2DA_s::GetINTEntry_strcol(int nRow, CExoString const &ColName, int *Ret) {
	return C2DA__GetINTEntry_strcol(this, nRow, ColName, Ret);
}

int C2DA_s::GetINTEntry_intcol(int nRow, int nCol, int *Ret) {
	return C2DA__GetINTEntry_intcol(this, nRow, nCol, Ret);
}

void *C2DA_s::vect_destructor(unsigned int a1) {
	return C2DA__vect_destructor(this, a1);
}

