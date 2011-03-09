#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int			(__thiscall *CResGFF__CreateGFFFile)(CResGFF *pTHIS, void *ResStruct, CExoString const &, CExoString const &) = (int(__thiscall*)(CResGFF *pTHIS, void *ResStruct, CExoString const &, CExoString const &))0x00614190;
CResGFF_s *	(__thiscall *CResGFF__CResGFF)(CResGFF *pTHIS) = (CResGFF_s*(__thiscall*)(CResGFF *pTHIS))0x00611920;
int			(__thiscall *CResGFF__WriteGFFFile)(CResGFF *pTHIS, CExoString const &FileName, unsigned short GFFType) = (int(__thiscall*)(CResGFF *pTHIS, CExoString const &FileName, unsigned short GFFType))0x00614300;
int 		(__thiscall *CResGFF__WriteGFFToPointer)(CResGFF *pTHIS, void * *, unsigned int &) = (int(__thiscall*)(CResGFF *pTHIS, void * *, unsigned int &))0x00614570;
int 		(__thiscall *CResGFF__GetDataFromPointer)(CResGFF *pTHIS, char *Pointer, int) = (int(__thiscall*)(CResGFF *pTHIS, char *Pointer, int))0x00612A20;
int 		(__thiscall *CResGFF__GetTopLevelStruct)(CResGFF *pTHIS, char *ResStruct) = (int(__thiscall*)(CResGFF *pTHIS, char *ResStruct))0x00612EF0;
void 		(__thiscall *CResGFF__GetGFFFileInfo)(CResGFF *pTHIS, CExoString &, CExoString &) = (void(__thiscall*)(CResGFF *pTHIS, CExoString &, CExoString &))0x00612C60;
void		(__thiscall *CResGFF_dtor)(CResGFF *pTHIS) = (void(__thiscall*)(CResGFF *pTHIS))0x00611AF0;

CResGFF_s::CResGFF_s() {
	CResGFF__CResGFF(this);
}

CResGFF_s::~CResGFF_s() {
	CResGFF_dtor(this);
}

CResGFF_s *CResGFF_s::ctor() {
	return CResGFF__CResGFF(this);
}

int CResGFF_s::CreateGFFFile(void *ResStruct, CExoString const &Version, CExoString const &Type) {
	return CResGFF__CreateGFFFile(this, ResStruct, Version, Type);
}

int CResGFF::WriteGFFFile(CExoString const &FileName, unsigned short GFFType) {
	return CResGFF__WriteGFFFile(this, FileName, GFFType);
}

int CResGFF::WriteGFFToPointer(void **Data, unsigned int &a2) {
	return CResGFF__WriteGFFToPointer(this, Data, a2);
}

int CResGFF::GetDataFromPointer(char *Pointer, int a3) {
	return 	CResGFF__GetDataFromPointer(this, Pointer, a3);
}

int CResGFF::GetTopLevelStruct(CResStruct *ResStruct) {
	return CResGFF__GetTopLevelStruct(this, (char*)ResStruct);
}

void CResGFF::GetGFFFileInfo(CExoString &Type, CExoString &Version) {
	CResGFF__GetGFFFileInfo(this, Type, Version);
}

void CResGFF::dtor() {
	CResGFF_dtor(this);
}