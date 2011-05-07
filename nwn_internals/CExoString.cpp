#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CExoString.h"

int (__thiscall *CExoString__StripNonAlphaNumeric)(CExoString *pTHIS, int a1, int a2, int a3) = (int (__thiscall*)(CExoString *pTHIS, int a1, int a2, int a3))0x0040CE30;
int	(__thiscall *CExoString__AsTAG)(CExoString *pTHIS, CExoString *ExoString) = (int (__thiscall*)(CExoString *pTHIS, CExoString *ExoString))0x0040CFB0;

CExoString::CExoString() {
	text = NULL;
	len = 0;
}

CExoString::CExoString(CExoString const &Source) {
	if (Source.text && strlen(Source.text) > 0) {
		len = strlen(Source.text)+1;
		text = new char[len];
		strcpy_s(text, len, Source.text);
	}
	else {
		text = NULL;
		len = 0;
	}
}

CExoString::CExoString(char const *Source) {
	if (Source && strlen(Source) > 0) {
		len = strlen(Source)+1;
		text = new char[len];
		strcpy_s(text, len, Source);
	}
	else {
		text = NULL;
		len = 0;
	}
}

CExoString::CExoString(char const *Source, int Length) {
	if (Length > 0) {
		len = Length+1;
		text = new char[len];
		strncpy_s(text, len, Source, Length);
	}
	else {
		text = NULL;
		len = 0;
	}
}

CExoString::CExoString(int Number) {
	char c[32];
	sprintf_s(c, 31, "%i", Number);
	len = strlen(c)+1;
	text = new char[len];
	strcpy_s(text, len, c);
}

CExoString::~CExoString() {
	if (text) {
		len = 0;
		delete[] text;
		text = NULL;
	}
}

char *CExoString::CStr() {
	return text;
}

bool CExoString::operator!=(const CExoString &Comp) {
	bool result=false;
	char *c = this->text;
	char *c2 = Comp.text;
	if (text && Comp.text) {
		if (strcmp(c, c2))
			result = true;
	}
	else {
		result = c && *c || c2 && *c2;
	}
	return result;
}

bool CExoString::operator!=(char const *Comp) {
	bool result=false;
	char *c = this->text;
	if (text && Comp) {
		if (strcmp(text, Comp) != 0)
			result = true;
	}
	else {
		result = c && *c || Comp && *Comp;
	}
	return result;
}

bool CExoString::operator==(CExoString const &Comp) {
	if (!text && !Comp.text) return true;
	else if (!text && Comp.text || text && !Comp.text)
		return false;
	
	//both have to be valid pointers at this point
	if (strcmp(text, Comp.text))
		return false;
		
	return true;
}

bool CExoString::operator==(char const *c) {
	if (!text && !c) return true;
	else if (!text && c || text && !c)
		return false;
	
	//both have to be valid pointers at this point
	if (strcmp(text, c))
		return false;
		
	return true;
}

CExoString &CExoString::operator=(CExoString const &Op) {
	if (this != &Op) {
		if (text) {
			if (!Op.text || strlen(Op.text)+1 > len) {
				len = 0;
				delete[] text;
				text = NULL;
			}
		}
		if (Op.text && (strlen(Op.text)+1) > 1) {
			if (!text) {
				len = strlen(Op.text)+1;
				text = new char[len];
			}
			strcpy_s(text, len, Op.text);
		}
		else {
			if (text) {
				delete[] text;
				text = NULL;
				len = 0;
			}
		}
	}

	return *this;
}

CExoString &CExoString::operator=(char const *Op) {
	if (Op && text && (strcmp(Op, text) == 0)) return *this;

	if (text) {
		if (!Op || strlen(Op)+1 > len) {
			len = 0;
			delete[] text;
			text = NULL;
		}
	}
	if (Op && strlen(Op)+1 > 1) {
		if (!text) {
			len = strlen(Op)+1;
			text = new char[len];
		}
		strcpy_s(text, len, Op);
	}
	else {
		if (text) {
			delete[] text;
			text = NULL;
			len = 0;
		}
	}

	return *this;
}

CExoString CExoString::operator+(CExoString const &Op) {
	char *c=NULL;
	int iLength=0;

	int strlenThis = this->text ? this->len-1 : 0,
		strlenOp = Op.text ? Op.len-1 : 0;

	CExoString result;

	if (strlenThis > 0) iLength = strlenThis;
	if (strlenOp > 0) iLength += strlenOp;
	
	if (iLength > 0) {
		++iLength;
		c = new char[iLength];
		memset(c, 0, iLength);
		
		if (strlenThis > 0 && strlenOp > 0) {
			strcpy_s(c, iLength, this->text);
			strcat_s(c, iLength, Op.text);
		}
		else {
			if (strlenThis > 0) strcpy_s(c, iLength, this->text);
			else if (strlenOp > 0) strcpy_s(c, iLength, Op.text);
		}

		result = c;
	}

	return result;
}

CExoString CExoString::operator+(char const *Op) {
	char *c=NULL;
	int iLength=0;

	int strlenThis = this->text ? this->len-1 : 0,
		strlenOp = strlen(Op);

	CExoString result;

	if (strlenThis > 0) iLength = strlenThis;
	if (strlenOp > 0) iLength += strlenOp;
	
	if (iLength > 0) {
		++iLength;
		c = new char[iLength];
		memset(c, 0, iLength);
		
		if (strlenThis > 0 && strlenOp > 0) {
			strcpy_s(c, iLength, this->text);
			strcat_s(c, iLength, Op);
		}
		else {
			if (strlenThis > 0) strcpy_s(c, iLength, this->text);
			else if (strlenOp > 0) strcpy_s(c, iLength, Op);
		}

		result = c;
	}

	return result;
}

int	CExoString::AsTAG(CExoString *ExoString) {
	return CExoString__AsTAG(this, ExoString);
}

int CExoString::StripNonAlphaNumeric(int a1, int a2, int a3) {
	return CExoString__StripNonAlphaNumeric(this, a1, a2, a3);
}
