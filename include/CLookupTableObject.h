#ifndef _H_CLOOKUPTABLEOBJECT_H_
#define _H_CLOOKUPTABLEOBJECT_H_

struct CLookupTableObject_s {
	char Tag[33];
	char fill[3];
	uint32_t unknown[7];
	CGenericObject *pObject;
	uint32_t obj_oid;
};

#endif