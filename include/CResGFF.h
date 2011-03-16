#ifndef _NX_NWN_STRUCT_CRESGFF_
#define _NX_NWN_STRUCT_CRESGFF_

struct CResGFF_s {
  unsigned __int16 nDemands;
  unsigned __int16 nRequests;
  unsigned __int32 oID;
  unsigned __int32 field_08;
  void *res_data;
  void *res_name;
  unsigned __int32 res_size;
  unsigned __int32 res_loaded;
  unsigned __int32 field_1C;
  unsigned __int32 field_20;
  void *res_list;
  void *res_class;
  /* 0x2C/44 */ unsigned long field_2C;
  /* 0x30/48 */ unsigned long field_30;
  /* 0x34/52 */ unsigned long field_34;
  /* 0x38/56 */ unsigned long field_38;
  /* 0x3C/60 */ unsigned long field_3C;
  /* 0x40/64 */ unsigned long field_40;
  /* 0x44/68 */ unsigned long m_pFileHeader;
  /* 0x48/72 */ unsigned long field_48;
  /* 0x4C/76 */ unsigned long field_4C;
  /* 0x50/80 */ unsigned long field_50;
  /* 0x54/84 */ unsigned long field_54;
  /* 0x58/88 */ unsigned long field_58;
  /* 0x5C/92 */ unsigned long field_5C;
  /* 0x60/96 */ unsigned long field_60;
  /* 0x64/100 */ unsigned long field_64;
  /* 0x68/104 */ unsigned long field_68;
  /* 0x6C/108 */ unsigned long field_6C;
  /* 0x70/112 */ unsigned long field_70;
  /* 0x74/116 */ unsigned long field_74;
  /* 0x78/120 */ unsigned long field_78;
  /* 0x7C/124 */ unsigned long field_7C;
  /* 0x80/128 */ unsigned long field_80;
  /* 0x84/132 */ char m_pLabelBuffer[17];
  /* 0x95/149 */ char m_pFileType[4];
  /* 0x9A/154 */ char rsvd1;
  /* 0x9A/154 */ unsigned long m_bLoaded;
  /* 0x9E/158 */ unsigned short field_9E;
  /* 0xA0/160 */ unsigned short field_A0;
  /* 0xA4/    */ unsigned long field_A4;
  /* 0xA8/    */ unsigned long field_A8;
  
  	CResGFF_s();
  	~CResGFF_s();
	CResGFF_s *ctor();
    int CreateGFFFile(void *ResStruct, CExoString const &Version, CExoString const &Type);
    int WriteGFFFile(CExoString const &FileName, unsigned short GFFType);
    int WriteGFFToPointer(void **Data, unsigned int &a2);
	int GetDataFromPointer(char *Pointer, int a3);
	int GetTopLevelStruct(CResStruct *ResStruct);
	void GetGFFFileInfo(CExoString &Type, CExoString &Version);
	void dtor();

	int ReadFieldINT(CResStruct *ResStruct, char *Source, int &a3, int a4);
	int GetList(void *a2, CResStruct *a3, char *a4);
	unsigned long GetListCount(void *a2);
	int GetListElement(CResStruct *a2, void *a3, unsigned long a4);
	int ReadFieldVOID(CResStruct* a2, void *a3, unsigned long a4, char *Source, int &a6, void *a7);

};

#endif /* _NX_NWN_STRUCT_CRESGFF_ */

/* vim: set sw=4: */
