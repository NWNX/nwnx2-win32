struct CResHelper_s {
	uint32_t					*pVTable;			// 0000 
	uint32_t 					bIsRequestPending;  // 0004 not quite sure
	void 						*pRes;    			// 0008
	CResRef 					sResRef;	        // 000C 
	// size 001C
};

