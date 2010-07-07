#ifndef _H_CNWCCMessageData_H_
#define _H_CNWCCMessageData_H_

struct CNWCCMessageData_s {
	void *data;

	void		ctor();
	uint32_t	SetString(uint32_t a2, CExoString ExoString);

};

#endif