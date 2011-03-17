#pragma once

static int (__fastcall *CExoResMan__ExistsNEXT)(CExoResMan *pTHIS, void *pVOID, CResRef const &ResRef, unsigned short Type, unsigned long *a3);

class CHookFunctions {
public:
	CHookFunctions(int debuglevel, char *sourcePath) {
		debugLevel = debuglevel;
		m_sourcePath = sourcePath;
		CExoResMan__ExistsORG = 0x00416BE0;
		
		HookFunctions();
	};
	void HookFunctions();

private:
	static int debugLevel;
	static char *m_sourcePath;
	
	DWORD CExoResMan__ExistsORG;

	static int __fastcall CExoResMan__ExistsHOOK(CExoResMan *pTHIS, void *pVOID, CResRef const &ResRef, unsigned short Type, unsigned long *a3);
};