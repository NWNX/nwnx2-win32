#ifndef _NX_NWN_STRUCT_CWORLDTIMER_
#define _NX_NWN_STRUCT_CWORLDTIMER_

struct CWorldTimer_s {
    void               *unknown;
    
	void		GetWorldTime(uint32_t *a2, uint32_t *a3);
	void		SetWorldTime(uint32_t a2, uint32_t a3, int a4);
	uint32_t	SubtractWorldTimes(uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t *a6, uint32_t *a7);

};

#endif