#pragma once

#include "CExoString.h"

class CExoLocString2ListListNodeData {
public:
	unsigned __int32 Language;
	CExoString Text;
};

class CExoLocString2ListListNode {
public:
	CExoLocString2ListListNode *Prev;
	CExoLocString2ListListNode *Next;
	CExoLocString2ListListNodeData *pData;
};

class CExoLocString2ListList {
public:
	CExoLocString2ListListNode *First;
	CExoLocString2ListListNode *Last;
	unsigned __int32 count;		
};

class CExoLocString2List {
public:
	CExoLocString2ListList *ExoLocString2ListList;
	unsigned __int32 count;
};

class CExoLocString2 {
public:
	CExoLocString2List *ExoLocString2List;
	unsigned __int32 field_04;
	
	CExoString *GetFirstEntry() {
		if (ExoLocString2List && ExoLocString2List->count) {
			if (ExoLocString2List->ExoLocString2ListList->First) {
				return &ExoLocString2List->ExoLocString2ListList->First->pData->Text;
			}
		}
		return NULL;		
	}
};