#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "CExoLocString.h"

CExoLocStringElement *CExoLocString_s::GetLangEntry(uint32_t nLocale)
{
	if(this->StrRef != -1) return NULL;
	CExoLocStringElement *pLangEntry;
	CExoLinkedListElement *pText = this->List->GetHeadPos();
	while(pText)
	{
		pLangEntry = (CExoLocStringElement *) this->List->GetAtPos(pText);
		if(pLangEntry->LangID == nLocale) return pLangEntry;
		pText = this->List->GetNext(pText);
	}
	return NULL;
}


char *CExoLocString_s::GetStringText(uint32_t nLocale)
{
	if(this->StrRef != -1) return NULL;
	CExoLocStringElement *pLangEntry;
	CExoLinkedListElement *pText = this->List->GetHeadPos();
	while(pText)
	{
		pLangEntry = (CExoLocStringElement *) this->List->GetAtPos(pText);
		if(pLangEntry->LangID == nLocale) return pLangEntry->Text.text;
		pText = this->List->GetNext(pText);
	}
	return NULL;
}

int CExoLocString_s::AddString(uint32_t nLocale, char *sString) {
	CExoLocStringElement *pCurrentData;
	CExoLocStringElement *pNewEntry;
	CExoLinkedListElement *pCurrentElement;

	pCurrentElement = this->List->GetHeadPos();
	pCurrentData = (CExoLocStringElement *) this->List->GetHead();
	while ( pCurrentData )
	{
	  if ( pCurrentData->LangID == nLocale )
	  {
	  	if(pCurrentData->Text.text)
			delete[] pCurrentData->Text.text;
		pCurrentData->Text.text = sString;
		pCurrentData->Text.len = strlen(sString)+1;
		//delete[] sString;
		return 1;
	  }
	  pCurrentData = (CExoLocStringElement *)this->List->GetNext(pCurrentElement);
	}
	pNewEntry = new CExoLocStringElement;
	if ( !pNewEntry  )
	{
	  delete[] sString;
	  return 0;
	}
	pNewEntry->LangID = nLocale;
	pNewEntry->Text.text = sString;
	pNewEntry->Text.len = strlen(sString)+1;
	this->List->AddTail(pNewEntry);
	//++this->List->Count;
	//++this->List->ListHeader->Count;
	//delete[] sString;
	return 1;
}
