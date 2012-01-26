#ifndef _NX_NWN_STRUCT_CNWMESSAGE_
#define _NX_NWN_STRUCT_CNWMESSAGE_

struct CNWMessage_s {
	void *vftable;
	void *field_04;
	unsigned __int32 field_08;
	unsigned __int32 field_0C;
	void *field_10;
	unsigned __int32 field_14;
	unsigned __int32 field_18;
	unsigned __int32 field_1C;
	unsigned __int8 field_20;
	unsigned __int8 field_21;
	unsigned __int8 field_22;
	unsigned __int8 field_23;
	unsigned __int32 field_24;
	unsigned __int32 field_28;
	unsigned __int32 field_2C;
	unsigned __int32 field_30;
	unsigned __int32 field_34;
	unsigned __int32 field_38;
	unsigned __int32 field_3C;
	unsigned __int32 field_40;
	unsigned __int8 field_44;
	char field_45;

	int 		ReadBOOL();
	int			ReadCResRef(CResRef *ResRef, int a3);
	int 		MessageReadOverflow(int a2);
	int			CreateWriteMessage(int a2, nwn_objid_t Player_oID, int a4);
	void 		WriteBOOL(int a2);
	void 		WriteCExoString(CExoString a2, int a3);
	int			WriteFLOAT(float f1, float f2, int a3);
	int			GetWriteMessage(char **ppData, uint32_t *pLength);
	int			WriteWORD(unsigned __int16 a2, int a3);
	
};

#endif