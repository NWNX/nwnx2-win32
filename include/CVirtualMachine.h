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
	//DWORD field_20;
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
    
    int Runscript(CExoString *ScriptName, nwn_objid_t OBJECT_SELF, int a4 = 1);
    int StackPopEngineStructure(int a2, void **a3);
    int StackPopInteger(int *iINT);
    int StackPopObject(nwn_objid_t *oID);
    int StackPopString(CExoString *str);
    int StackPushEngineStructure(int a2, void *a3);
    int StackPushFloat(float f);
    int StackPushInteger(int i);
    int StackPushObject(nwn_objid_t Object);
    
};

#endif 
