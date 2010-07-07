#if !defined(HookEvents_h_)
#define HookEvents_h_

void HookFunctions();
       void VM_ExecuteCommand(DWORD nCommandID, int nArgsCount);
	
	        int StackPopInteger(int *buf);
	        int StackPopFloat(float *buf);
	        int StackPopString(char **buf);
	        int StackPopVector(Vector *buf);
	        int StackPopObject(DWORD *buf);
	        int StackPopEngineStructure(DWORD nStructType, void **buf);
	
	        int StackPushInteger(int value);
	        int StackPushFloat(float value);
	        int StackPushString(char *value);
	        int StackPushVector(Vector value);
	        int StackPushObject(DWORD value);
	        int StackPushEngineStructure(DWORD nStructType, void *value);
	
	        DWORD GetObjectSelf();

#endif