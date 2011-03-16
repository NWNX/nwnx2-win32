#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

int				(__thiscall *CResGFF__CreateGFFFile)(CResGFF *pTHIS, void *ResStruct, CExoString const &, CExoString const &) = (int(__thiscall*)(CResGFF *pTHIS, void *ResStruct, CExoString const &, CExoString const &))0x00614190;
CResGFF_s *		(__thiscall *CResGFF__CResGFF)(CResGFF *pTHIS) = (CResGFF_s*(__thiscall*)(CResGFF *pTHIS))0x00611920;
int				(__thiscall *CResGFF__WriteGFFFile)(CResGFF *pTHIS, CExoString const &FileName, unsigned short GFFType) = (int(__thiscall*)(CResGFF *pTHIS, CExoString const &FileName, unsigned short GFFType))0x00614300;
int 			(__thiscall *CResGFF__WriteGFFToPointer)(CResGFF *pTHIS, void * *, unsigned int &) = (int(__thiscall*)(CResGFF *pTHIS, void * *, unsigned int &))0x00614570;
int 			(__thiscall *CResGFF__GetDataFromPointer)(CResGFF *pTHIS, char *Pointer, int) = (int(__thiscall*)(CResGFF *pTHIS, char *Pointer, int))0x00612A20;
int 			(__thiscall *CResGFF__GetTopLevelStruct)(CResGFF *pTHIS, char *ResStruct) = (int(__thiscall*)(CResGFF *pTHIS, char *ResStruct))0x00612EF0;
void 			(__thiscall *CResGFF__GetGFFFileInfo)(CResGFF *pTHIS, CExoString &, CExoString &) = (void(__thiscall*)(CResGFF *pTHIS, CExoString &, CExoString &))0x00612C60;
void			(__thiscall *CResGFF_dtor)(CResGFF *pTHIS) = (void(__thiscall*)(CResGFF *pTHIS))0x00611AF0;

int 			(__thiscall *CResGFF__ReadFieldINT)(CResGFF *pTHIS, CResStruct *, char *Source, int &, int) = (int(__thiscall*)(CResGFF *pTHIS, CResStruct *, char *Source, int &, int))0x00613140;
int 			(__thiscall *CResGFF__GetList)(CResGFF *pTHIS, void *, CResStruct *, char*) = (int(__thiscall*)(CResGFF *pTHIS, void *, CResStruct *, char*))0x00612D30;
unsigned long 	(__thiscall *CResGFF__GetListCount)(CResGFF *pTHIS, void *) = (unsigned long(__thiscall*)(CResGFF *pTHIS, void *))0x00612DC0;
int 			(__thiscall *CResGFF__GetListElement)(CResGFF *pTHIS, CResStruct *, void*, unsigned long) = (int(__thiscall*)(CResGFF *pTHIS, CResStruct *, void*, unsigned long))0x00612E20;
int 			(__thiscall *CResGFF__ReadFieldVOID)(CResGFF *pTHIS, CResStruct*, void *, unsigned long, char *Source, int &, void *) = (int(__thiscall*)(CResGFF *pTHIS, CResStruct*, void *, unsigned long, char *Source, int &, void *))0x00613690;



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

int CResGFF::ReadFieldINT(CResStruct *ResStruct, char *Source, int &a3, int a4) {
	return CResGFF__ReadFieldINT(this, ResStruct, Source, a3, a4);
}
	
int CResGFF::GetList(void *a2, CResStruct *a3, char *a4) {
	return CResGFF__GetList(this, a2, a3, a4);
}
	
unsigned long 	CResGFF::GetListCount(void *a2) {
	return CResGFF__GetListCount(this, a2);
}
	
int CResGFF::GetListElement(CResStruct *a2, void *a3, unsigned long a4) {
	return CResGFF__GetListElement(this, a2, a3, a4);
}
	
int CResGFF::ReadFieldVOID(CResStruct* a2, void *a3, unsigned long a4, char *Source, int &a6, void *a7) {
	return CResGFF__ReadFieldVOID(this, a2, a3, a4, Source, a6, a7);
}