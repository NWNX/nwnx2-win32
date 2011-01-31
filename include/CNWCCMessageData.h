#ifndef __H_CNWCCMESSAGEDATA_H__
#define __H_CNWCCMESSAGEDATA_H__

struct CNWCCMessageData_s {
	unsigned __int16 EventType;
	unsigned __int16 field_02;
	int *integer_list;
	int integer_count;
	int integer_alloc;
	float float_list;
	int float_count;
	int float_alloc;
	DWORD *dword1C;
	int exostring_count;
	int exostring_alloc;
	DWORD *dword28;
	int object_count;
	int object_alloc;

	CNWCCMessageData_s();
	~CNWCCMessageData_s();
	
	void SetObjectID(int Nth, nwn_objid_t oID);
	uint32_t SetString(uint32_t a2, CExoString ExoString);
	int SetInteger(int Nth, int Value);
	void CopyTo(CNWCCMessageData *Dest);
	
	void AddAttackerCombatMessage(CNWSCreature *Attacker);
};

#endif
