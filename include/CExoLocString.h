#ifndef _CEXOLOCSTRING_H_
#define _CEXOLOCSTRING_H_
/*
http://nwn.bioware.com/developers/Bioware_Aurora_LocalizedStrings_Format.pdf
*/

#include "nwnx_funcs_const.h"
#include "CExoLinkedList.h"

struct _CExoString {
    char               *text;
    uint32_t            len;
};

struct CExoLocStringElement
{
	uint32_t      LangID;
	_CExoString Text;
};

class CExoLocString_s {
	public:
	CExoLinkedList_s *List;
	uint32_t       StrRef;

	char                 *GetStringText(uint32_t nLocale);
	CExoLocStringElement *GetLangEntry(uint32_t nLocale);
	int                  AddString(uint32_t nLocale, char *sString);
};

#endif
