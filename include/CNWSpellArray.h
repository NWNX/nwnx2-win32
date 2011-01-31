#ifndef _H_CNWSPELLARRAY_H_
#define _H_CNWSPELLARRAY_H_

struct CNWSpellArray_s {
	void *unknown;
	
	CNWSpell *GetSpell(int SpellID);
};


#endif