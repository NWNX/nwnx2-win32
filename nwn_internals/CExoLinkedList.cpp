#include "stdafx.h"
#include <stdlib.h>
#include "CExoLinkedList.h"

int (__thiscall *CExoLinkedListInternal__Remove)(CExoLinkedListHeader *pTHIS, CExoLinkedListElement *Element) = (int (__thiscall *)(CExoLinkedListHeader *pTHIS, CExoLinkedListElement *Element))0x00410080;
CExoLinkedListElement* (__thiscall *CExoLinkedListInternal__AddTail)(CExoLinkedList_s *pTHIS, void *) = (CExoLinkedListElement* (__thiscall*)(CExoLinkedList_s *pTHIS, void*))0x0040FE60;
	
int CExoLinkedList_s::Remove(CExoLinkedListElement *Element) {
	return CExoLinkedListInternal__Remove(this->ListHeader, Element);
}

CExoLinkedListElement *CExoLinkedList_s::GetHeadPos()
{
	return this->ListHeader->FirstElement;
}

void *CExoLinkedList_s::GetHead()
{
	if(this->ListHeader->FirstElement)
		return this->ListHeader->FirstElement->Data;
	else return NULL;

}

void *CExoLinkedList_s::GetAtPos(CExoLinkedListElement *Position)
{
	if(!Position) return NULL;
	return Position->Data;
}

CExoLinkedListElement *CExoLinkedList_s::GetNext(CExoLinkedListElement *Position)
{
	if(!Position) return NULL;
	return Position->NextElement;
}

CExoLinkedListElement *CExoLinkedList_s::AddTail(void *pData)
{
	return CExoLinkedListInternal__AddTail(this, pData);
	/*
	CExoLinkedListElement *pNewElement = new CExoLinkedListElement;
	pNewElement->PrevoiusElement = NULL;
	pNewElement->NextElement = NULL;
	pNewElement->Data = NULL;
	
	pNewElement->PrevoiusElement = this->ListHeader->LastElement;
	if(this->ListHeader->LastElement)
	{
		this->ListHeader->LastElement = pNewElement;
	}
	this->ListHeader->LastElement = pNewElement;
	pNewElement->Data = pData;
	if(!this->ListHeader->FirstElement)
	{
		this->ListHeader->FirstElement = pNewElement;
	}

	return pNewElement;*/
}

