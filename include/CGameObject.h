#ifndef _NX_NWN_STRUCT_CGENERICOBJECT_
#define _NX_NWN_STRUCT_CGENERICOBJECT_

struct CGameObject_s {
	uint32_t							obj_type;						/* 0x000C */
	nwn_objid_t							obj_id;								/* 0x0004 */
	uint8_t								obj_type2;							/* 0x0008 */
	
	uint8_t								field_0009;							/* 0x0009 */
	uint8_t								field_000A;							/* 0x000A */
	uint8_t								field_000B;							/* 0x000B */
	
	void								*obj_vtable;						/* 0x000C */
	char								*obj_lastname;						/* 0x0010 */
	
	uint32_t							field_0014;							/* 0x0014 */
	
	CExoString							obj_tag;							/* 0x0018 */
//	uint32_t							obj_tag_len;						/* 0x001C */

	CExoString							obj_template;						/* 0x0020 */
//	uint32_t							obj_template_len;					/* 0x0024 */

	CNWSModule *AsModule();
	CNWSArea *AsNWSArea();

	CNWSObject *AsNWSObject();

	CNWSItem *AsNWSItem();
	CNWSAreaOfEffectObject *AsNWSAreaOfEffectObject();
	CNWSStore *AsNWSStore();
	CNWSDoor *AsNWSDoor();
	CNWSCreature *AsNWSCreature();
	CNWSTrigger *AsNWSTrigger();
	CNWSPlaceable *AsNWSPlaceable();
	CNWSWaypoint *AsNWSWaypoint();
	CNWSEncounter *AsNWSEncounter();
};

#endif /* _NX_NWN_STRUCT_CGENERICOBJECT_ */
	
