#ifndef _H_CLOOKUPTABLEOBJECT_H_
#define _H_CLOOKUPTABLEOBJECT_H_

struct CLookupTableObject_s {
	char Tag[32];
	char fill[4];
	uint32_t unknown_1;
	uint32_t unknown_2;
	uint32_t tag_len1; //includes the terminator
	uint32_t unknown_4;
	uint32_t tag_len2; //not sure why there is a second length
	uint32_t unknown_6;
	uint32_t unknown_7;
	CGameObject *pObject;
	uint32_t obj_oid;
};

#endif