#ifndef _NX_NWN_STRUCT_CNWSITEM_
#define _NX_NWN_STRUCT_CNWSITEM_

struct CNWSItem_s {
	uint32_t					field_00;				/* 0x0000 */
	
    uint8_t                     it_color[6];			/* 0x0004 */       
    uint8_t                     field_06;				/* 0x000A */
    uint8_t                     field_07;				/* 0x000B */

    uint32_t                    it_baseitemtype;		/* 0x000C */
 
    CNWSObject                  obj;					/* 0x0010 */
    
    uint32_t					spacer1[3];				/* 0x01CC */ 

    uint32_t					it_base_ac;				/* 0x01DC */

    uint8_t                     it_identified;          /* 0x01E0 */ //CHECK!

    uint8_t                     field_1E1;
    uint8_t                     field_1E2;
    uint8_t                     field_1E3;
    
    uint32_t					field_1E4;
 
	CNWSItemPropertyHandler		ActiveProperties;				/* 0x01E8 */ 
	CNWSItemPropertyHandler		PassiveProperties;				/* 0x01F4 */
	
	uint8_t						it_charges;				/* 0x0200 */ //CHECK!
	
	uint8_t						field_1F1;				/* 0x0201 */
	uint8_t						field_1F2;				/* 0x0202 */
	uint8_t						field_1F3;				/* 0x0203 */
	
	uint32_t					it_cost_ided;			/* 0x0204 */ //CHECK
	uint32_t					it_cost_unided;			/* 0x0208 */
	uint32_t					it_cost_add;			/* 0x020C */ 
	
    uint32_t                    field_200;              /* 0x0210 */

  unsigned __int8 ModelPart1;
  unsigned __int8 ModelPart2;
  unsigned __int8 ModelPart3;
  unsigned __int8 ArmorParts[19];
//  unsigned __int8 ArmorPart_RFoot;
//  unsigned __int8 ArmorPart_LFoot;
//  unsigned __int8 ArmorPart_RShin;
//  unsigned __int8 ArmorPart_LShin;
//  unsigned __int8 ArmorPart_LThigh;
//  unsigned __int8 ArmorPart_RThigh;
//  unsigned __int8 ArmorPart_Pelvis;
//  unsigned __int8 ArmorPart_Torso;
//  unsigned __int8 ArmorPart_Belt;
//  unsigned __int8 ArmorPart_Neck;
//  unsigned __int8 ArmorPart_RFArm;
//  unsigned __int8 ArmorPart_LFArm;
//  unsigned __int8 ArmorPart_RBicep;
//  unsigned __int8 ArmorPart_LBicep;
//  unsigned __int8 ArmorPart_RShoul;
//  unsigned __int8 ArmorPart_LShoul;
//  unsigned __int8 ArmorPart_RHand;
//  unsigned __int8 ArmorPart_LHand;
//  unsigned __int8 ArmorPart_Robe;
  unsigned __int8 UArmorParts[19];
  
    uint8_t                     field_23D;
    uint8_t                     field_23E;
    uint8_t						field_23F;
    
    nwn_objid_t					it_container_obj;		/* 0x0240 */
    
    uint32_t					field_0244;				/* 0x0244 */
    
    uint8_t						it_posx;				/* 0x0248 */
    uint8_t						it_posy;				/* 0x0249 */
    
    uint8_t						field_024A;				/* 0x024A */
    uint8_t						field_024B;				/* 0x024B */

    uint32_t					spacer_24C[14];			/* 0x024C */
    
    uint8_t						it_droppable;			/* 0x0284 */
    
	uint8_t						field_285;
	uint8_t						field_286;
	uint8_t						field_287;
	uint32_t					field_288;

	uint8_t						it_pickpocketable;		/* 0x028C */

	uint8_t						field_28D;
	uint8_t						field_28E;
	uint8_t						field_28F;

	uint32_t					it_stacksize;
	uint8_t						it_stolen;				/* 0x0294 */

	uint8_t						field_295;
	uint8_t						field_296;
	uint8_t						field_297;
	
	uint32_t					it_weight;				/* 0x0298 */
	
	uint32_t					field_29C;
	uint32_t					field_2A0;

	CNWSItem *CNWSItem_s::ctor(unsigned int a1);

	int ComputeArmorClass();
	unsigned short GetDamageFlags();
	int SetPossessor(unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i);
	int GetPropertyByType(CNWSItemProperty **iprp, uint16_t ipType, uint16_t ipSubType);
	int GetPropertyByTypeExists(unsigned short a1, unsigned short a2);
	int SaveItem(CResGFF *ResGFF, void *ResStruct, int a3);
	int LoadItem(CResGFF *ResGFF, void *CResStruct, int a3);
	void AddToArea(CNWSArea *Area, float x, float y, float z, int a5);
};

#endif