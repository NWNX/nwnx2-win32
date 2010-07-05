#ifndef _NX_NWN_STRUCT_CVIRTUALMACHINE_
#define _NX_NWN_STRUCT_CVIRTUALMACHINE_

typedef struct
{
	DWORD Stack;
	DWORD StackSize;
	DWORD InstructionPtr;
	DWORD SecondaryPtr;
	DWORD Code;
	DWORD CodeSize;
	CExoString Name;
	DWORD field_20;
} CVirtualMachineScript;

typedef struct
{
	DWORD  StackPointer;
	DWORD  field_4;
	DWORD  AllocatedSize;
	BYTE  *VarTypes;
	DWORD *Values;
	DWORD  field_14;
	DWORD  CurrentInstruction;
} CVirtualMachineStack;

struct CVirtualMachine_s {
	DWORD field_0;
	DWORD field_4;
	DWORD field_8;
	DWORD RecursionLevel;
	CVirtualMachineScript Scripts[8];
	DWORD LevelActive[8];
	DWORD ObjectID[8];
	CVirtualMachineStack Stack;
	DWORD field_18C[8];
	DWORD field_1AC[123];
	void *Commands; 

    void                       *unknown;
};

#endif 
