#ifndef _CEXORESMAN_H_
#define _CEXORESMAN_H_

struct CExoResMan_s {
  /* 0x0/0 */ unsigned long field_0;
  /* 0x4/4 */ unsigned long TotalResourceMemory;
  /* 0x8/8 */ unsigned long FreeMemory;
  /* 0xC/12 */ unsigned long field_C;
  /* 0x10/16 */ void *KeyTable1;
  /* 0x14/20 */ void *KeyTable2;
  /* 0x18/24 */ void *KeyTable3;
  /* 0x1C/28 */ void *KeyTable4;
  /* 0x20/32 */ void *ToBeFreedList;
  /* 0x24/36 */ void *ResList2;
  /* 0x28/40 */ unsigned long field_28;
  /* 0x2C/44 */ unsigned long field_2C;
  /* 0x30/48 */ unsigned long SuspendServicing;
  /* 0x34/52 */ unsigned long field_34;
  /* 0x38/56 */ unsigned long field_38;
  /* 0x3C/60 */ unsigned long field_3C;
  /* 0x44/68 */ char rsvd1[4];
  /* 0x44/68 */ unsigned long field_44;

	int Exists(CResRef *ResRef, unsigned short a2, unsigned long *a3);
	int FreeChunk();

};

#endif