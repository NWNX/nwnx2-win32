#ifndef _NWNX_CGAMEOBJECTARRAY_H__
#define _NWNX_CGAMEOBJECTARRAY_H__

struct CGameObjectArray_s
{
	CGameObjectArrayElement **Objects;
	uint32_t ObjectPointer;
	uint32_t field_8;
	uint32_t PlayerPointer;
	uint32_t field_10;
	uint32_t field_14;
	
	uint8_t DEL(nwn_objid_t oID);
	char GetGameObject(unsigned int a2, CGenericObject *a3);
};

#endif

