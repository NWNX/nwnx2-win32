#ifndef _H_CFACTIONMANAGER_H_
#define _H_CFACTIONMANAGER_H_

struct CFactionManager_s {
	unsigned __int8 field_00;
	unsigned __int8 field_01;
	unsigned __int8 field_02;
	unsigned __int8 field_03;
	unsigned __int8 field_04;
	unsigned __int8 field_05;
	unsigned __int8 field_06;
	unsigned __int8 field_07;
	unsigned __int8 field_08;
	unsigned __int8 field_09;
	unsigned __int8 field_0A;
	unsigned __int8 field_0B;
	unsigned __int8 field_0C;
	unsigned __int8 field_0D;
	unsigned __int8 field_0E;
	unsigned __int8 field_0F;
	unsigned __int8 field_10;
	unsigned __int8 field_11;
	unsigned __int8 field_12;
	unsigned __int8 field_13;
	unsigned __int32 field_14;

	CNWSFaction *GetFaction(uint32_t FactionID);
};


#endif
