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
 
	CNWSItemPropertyHandler		it_iph1;				/* 0x01E8 */ 
	CNWSItemPropertyHandler		it_iph2;				/* 0x01F4 */
	
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
  unsigned __int8 ArmorPart_RFoot;
  unsigned __int8 ArmorPart_LFoot;
  unsigned __int8 ArmorPart_RShin;
  unsigned __int8 ArmorPart_LShin;
  unsigned __int8 ArmorPart_LThigh;
  unsigned __int8 ArmorPart_RThigh;
  unsigned __int8 ArmorPart_Pelvis;
  unsigned __int8 ArmorPart_Torso;
  unsigned __int8 ArmorPart_Belt;
  unsigned __int8 ArmorPart_Neck;
  unsigned __int8 ArmorPart_RFArm;
  unsigned __int8 ArmorPart_LFArm;
  unsigned __int8 ArmorPart_RBicep;
  unsigned __int8 ArmorPart_LBicep;
  unsigned __int8 ArmorPart_RShoul;
  unsigned __int8 ArmorPart_LShoul;
  unsigned __int8 ArmorPart_RHand;
  unsigned __int8 ArmorPart_LHand;
  unsigned __int8 ArmorPart_Robe;
  
    uint8_t                     field_22A;
    uint8_t                     field_22B;
    uint32_t					spacer_021C;			/* 0x022C */ 
    
    nwn_objid_t					it_container_obj;		/* 0x0240 */
    
    uint32_t					field_0244;				/* 0x0244 */
    
    uint8_t						it_posx;				/* 0x0248 */
    uint8_t						it_posy;				/* 0x0249 */
    
    uint8_t						field_024A;				/* 0x024A */
    uint8_t						field_024B;				/* 0x024B */

    uint32_t					spacer_24C[14];			/* 0x024C */
    
    uint8_t						it_droppable;			/* 0x0274 */
    
	uint8_t						field_275;
	uint8_t						field_276;
	uint8_t						field_277;
	uint32_t					field_278;

	uint8_t						it_pickpocketable;		/* 0x027C */

	uint8_t						field_27D;
	uint8_t						field_27E;
	uint8_t						field_27F;

	uint32_t					it_stacksize;
	uint8_t						it_stolen;				/* 0x0284 */

	uint8_t						field_285;
	uint8_t						field_286;
	uint8_t						field_287;
	
	uint32_t					it_weight;				/* 0x0288 */

	int ComputeArmorClass();
	int SetPossessor(unsigned int a2_Possessor_id, int a3_Signalevent, int a4_bFeedback, int i);

};

#endif