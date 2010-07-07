#include "stdafx.h"
#include "nwnx_funcs2.h"
#include "CQUickbarExtension.h"

extern CNWNXFuncs2 NWNFuncs2;

#define log(a,b,...) if(a<=NWNFuncs2.debugLevel)NWNFuncs2.LOG(b,__VA_ARGS__)

CQuickbarExtension::CQuickbarExtension() {
	iExtension=0;
}