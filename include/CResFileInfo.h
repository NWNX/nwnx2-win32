#ifndef _H_CRESFILEINFO_H_
#define _H_CRESFILEINFO_H_

struct CResFileInfo_s {
	char ResName[17];
	NwnResType resType;
	unsigned int size;
	unsigned int mtime;
};

#endif