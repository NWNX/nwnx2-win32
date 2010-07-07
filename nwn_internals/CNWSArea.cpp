#include "stdafx.h"
#include "types.h"
#include "nwn_internals.h"

void			(__thiscall *CNWSArea__CNWSArea)(void* pTHIS, CResRef, int, unsigned long)=(void (__thiscall*)(void* pTHIS, CResRef, int, unsigned long))0x0050A2E0;
void			(__thiscall *CNWSArea__Destructor)(CNWSArea *pTHIS)=(void (__thiscall*)(CNWSArea *pTHIS))0x0050A780;
int 			(__thiscall *CNWSArea__LoadArea)(void*, int)=(int (__thiscall*)(void*, int))0x0050C380;
void			(__thiscall *CNWSArea__scalar_Destructor)(CNWSArea *pTHIS, char)=(void (__thiscall*)(CNWSArea *pTHIS, char))0x0050A760;
signed int 		(__thiscall *CNWSArea__ExploreArea)(CNWSArea *pTHIS, CNWSCreature *a2, int a3, int a4, int a5)=(signed int (__thiscall*)(CNWSArea *pTHIS, CNWSCreature *a2, int a3, int a4, int a5))0x00529C50;
long double 	(__thiscall *CNWSArea__ComputeHeight)(CNWSArea *pTHIS, float x, float y, float z)=(long double (__thiscall*)(CNWSArea *pTHIS, float x, float y, float z))0x005276D0;
CNWTile*		(__thiscall *CNWSArea__GetTile)(CNWSArea* pTHIS, float x, float y, int z)=(CNWTile* (__thiscall*)(CNWSArea* pTHIS, float x, float y, int z))0x0050C0E0;
void *			(__thiscall *CNWSArea__SetScriptName)(CNWSArea *pTHIS, int iScript, CExoString ScriptName)=(void* (__thiscall*)(CNWSArea *pTHIS, int iScript, CExoString ScriptName))0x00510C00;
int 			(__thiscall *CNWSArea__ClearLineOfSight)(CNWSArea *pTHIS, Vector v1, Vector v2, Vector *v3, uint32_t *, nwn_objid_t, nwn_objid_t, uint8_t)=(int (__thiscall*)(CNWSArea *pTHIS, Vector v1, Vector v2, Vector *v3, uint32_t *, nwn_objid_t, nwn_objid_t, uint8_t))0x005114E0;
signed int 		(__thiscall *CNWSArea__GetFirstObjectInArea)(CNWSArea *pTHIS, nwn_objid_t *oID)=(signed int (__thiscall*)(CNWSArea *pTHIS, nwn_objid_t *oID))0x0050C070;
signed int 		(__thiscall *CNWSArea__GetNextObjectInArea)(CNWSArea *pTHIS, nwn_objid_t *oID)=(signed int (__thiscall*)(CNWSArea *pTHIS, nwn_objid_t *oID))0x0050C0A0;
signed int		(__thiscall *CNWSArea__AddObjectToArea)(CNWSArea *pTHIS, unsigned int Object_ID, int bRunEnterScript)=(signed int (__thiscall*)(CNWSArea *pTHIS, unsigned int Object_ID, int bRunEnterScript))0x0050BAA0;
signed int 		(__thiscall *CNWSArea__RemoveObjectFromArea)(CNWSArea *pTHIS, unsigned int oID)=(signed int (__thiscall*)(CNWSArea *pTHIS, unsigned int oID))0x0050BEE0;


void CNWSArea_s::Destructor() {
	CNWSArea__Destructor(this);
}

void CNWSArea_s::CNWSArea(CResRef a1, int a2, unsigned long a3) {
	CNWSArea__CNWSArea(this, a1, a2, a3);
}

signed int CNWSArea_s::AddObjectToArea(unsigned int Object_ID, int bRunEnterScript) {
	return CNWSArea__AddObjectToArea(this, Object_ID, bRunEnterScript);
}

int CNWSArea_s::ClearLineOfSight(Vector v1, Vector v2, Vector *v3, uint32_t *a5, nwn_objid_t a6, nwn_objid_t a7, uint8_t a8) {
	return CNWSArea__ClearLineOfSight(this, v1, v2, v3, a5, a6, a7, a8);
}

long double CNWSArea_s::ComputeHeight(float x, float y, float z) {
	return CNWSArea__ComputeHeight(this, x, y, z);
}

signed int CNWSArea_s::ExploreArea(CNWSCreature *a2, int a3, int a4, int a5) {
	return CNWSArea__ExploreArea(this, a2, a3, a4, a5);
}

signed int CNWSArea_s::GetFirstObjectInArea(nwn_objid_t *oID) {
	return CNWSArea__GetFirstObjectInArea(this, oID);
}

signed int CNWSArea_s::GetNextObjectInArea(nwn_objid_t *oID) {
	return CNWSArea__GetNextObjectInArea(this, oID);
}

CNWTile *CNWSArea_s::GetTile(float x, float y, int z) {
	return CNWSArea__GetTile(this, x, y, z);
}

int CNWSArea_s::LoadArea(int a2) {
	return CNWSArea__LoadArea(this, a2);
}

signed int CNWSArea_s::RemoveObjectFromArea(unsigned int oID) {
	return CNWSArea__RemoveObjectFromArea(this, oID);
}

void *CNWSArea_s::SetScriptName(int iScript, CExoString ScriptName) {
	return CNWSArea__SetScriptName(this, iScript, ScriptName);
}

void CNWSArea_s::scalar_Destructor(char Flag) {
	CNWSArea__scalar_Destructor(this, Flag);
}
