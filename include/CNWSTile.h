#ifndef _H_CNWSTILE_H_
#define _H_CNWSTILE_H_

struct CNWSTile_s {
	void *data;
	
	int GetSurfaceMaterial(float x, float y, float z);
};

#endif