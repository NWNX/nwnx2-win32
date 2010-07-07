#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "CExoString.h"
//#include "nwnx_funcs2.h"

//extern CNWNXFuncs2 NWNFuncs2;
//#define _log (a,b,...) if(a<=NWNFuncs2.debugLevel)NWNFuncs2.LOG(b,__VA_ARGS__)

CExoString_s::CExoString_s() {
//	_log(3, "CExoString_s_constr: %08X\n", this);
	text = NULL;
	len = 0;
}

CExoString_s::CExoString_s(const char* c_string) {
	if (c_string != NULL && strlen(c_string) > 1 ) {
//		_log(3, "CExoString_s_new_text (const *c_string): %08X\n", this);
	    len = strlen(c_string);
    	text = new char[len+1];
    	strncpy(text, c_string, len+1);
	}
	else {
		if (text != NULL) {
//			_log(3, "CExoString_s_delete_text(const *c_string): %08X\n", this);
			delete[] text;
		}
	    text = NULL;
	    len = 0;
	}
}

CExoString_s::CExoString_s(const CExoString &ExoString) {
	//CExoString_s.len includes the zero terminator
	if (ExoString.text != NULL && ExoString.len > 1) {
//		_log(3, "CExoString_s_new_text(const &ExoString: %08X\n", this);
		len = ExoString.len;
		text = new char[len+1];
		strncpy(text, ExoString.text, len+1);
	}
	else {
		if (text != NULL) {
//			//_log(3, "CExoString_s_delete_text(const &ExoString: %08X\n", this);
			delete[] text;
		}
		text = NULL;
		len = 0;
	}
}

CExoString_s::CExoString_s(const char* c_string, int count) {
	if (count <=0) {
		if (text != NULL) {
			//_log(3, "CExoString_s_delete_text(const *c_string, count): %08X\n", this);
			delete[] text;
		}
		text = NULL;
		len = 0;
	}
	else {
	//_log(3, "CExoString_s_new_text(const *c_string, count): %08X\n", this);
		len = count;
		text = new char[count+1];
		strncpy(text, c_string, count);
		text[count] = 0;
	}
}

CExoString_s::CExoString_s(int i) {
	//_log(3, "CExoString_s_new_text(i): %08X\n", this);
	char c[20];
	sprintf_s(&c[0], 20, "%i", i);
	len = strlen(&c[0]);
	text = new char[len+1];
	strncpy(text, &c[0], len+1);
}

CExoString_s::~CExoString_s() {
	if (text != NULL) {
		//_log(3, "CExoString_s_delete_text(destructor): %08X\n", this);
		delete[] text;
		text = NULL;
	}
	len = 0;
}

CExoString_s &CExoString_s::operator=(const CExoString_s &ExoString) {
	if (this != &ExoString) {
		if (text == NULL && ExoString.text == NULL) {
		}
		else if (text != NULL && ExoString.text == NULL) {
			//_log(3, "CExoString_s_delete_text(= &ExoString): %08X\n", this);
			delete[] text; text = NULL; len = 0;
		}
		else if (text == NULL && ExoString.text != NULL) {
			len = ExoString.len;
			//_log(3, "CExoString_s_new_text(= &ExoString): %08X\n", this);
			text = new char[len+1];
			strncpy(text, ExoString.text, len+1);
		}
		else if (text != NULL && ExoString.text != NULL) {
			if (ExoString.len > len) {

				//_log(3, "CExoString_s_delete_text(= &ExoString): %08X\n", this);
				delete[] text; text = NULL; len = 0;

				len = ExoString.len;
				//_log(3, "CExoString_s_new_text(= &ExoString): %08X\n", this);
				text = new char[len+1];
				strncpy(text, ExoString.text, len+1);
			}
			else {
				len = ExoString.len;
				strncpy(text, ExoString.text, len+1);
			}
		}
	}
	return *this;
}


CExoString_s &CExoString_s::operator=(const char *c_string) {
	if (text != NULL) {
		if (c_string == NULL || strlen(c_string) > len) {
			//_log(3, "CExoString_s_delete_text(= *cstring): %08X\n", this);
			delete[] text;
			text = NULL;
			len = 0;
		}
	}
	if (c_string != NULL && strlen(c_string) > 1 ) {
		len = strlen(c_string);
		if (text == NULL) {			
			//_log(3, "CExoString_s_new_text(= *cstring): %08X\n", this);
			text = new char[len+1];
		}
		strncpy(text, c_string, len+1);
	}
	else {
		if (text != NULL) {
			//_log(3, "CExoString_s_delete_text(= *cstring): %08X\n", this);
			delete[] text;
			text = NULL;
			len = 0;
		}
	}
	return *this;
}