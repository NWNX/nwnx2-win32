#ifndef _NX_NWN_STRUCT_CNWSOBJECT_
#define _NX_NWN_STRUCT_CNWSOBJECT_

struct CNWSObject_s {
	CGenericObject						obj_generic;						/* 0x0000 - 0x0007 */

	uint32_t							field_0028;							/* 0x0028 */
	uint32_t							field_002C;							/* 0x002C */
	uint32_t							field_0030;							/* 0x0030 */
	
	uint32_t							obj_conv_object_1;					/* 0x0034 */
	uint16_t							obj_portrait_id;					/* 0x0038 */
	
	uint16_t							field_003A;							/* 0x003A */
	
	uint32_t							obj_conv_object_2;					/* 0x003C */
	
	uint32_t							field_0040;							/* 0x0040 */
	uint32_t							field_0044;							/* 0x0044 */
	uint32_t							field_0048;							/* 0x0048 */
	
	uint32_t							obj_conv_object_3;					/* 0x004C */
	uint32_t							obj_conv_paused;					/* 0x0050 */
	uint32_t							obj_conv_owner;						/* 0x0054 */
	uint32_t							obj_conv_animation;					/* 0x0058 */
	uint32_t							obj_ai_level;						/* 0x005C */
	uint32_t							obj_ai_lock;						/* 0x0060 */
	void								*obj_ai_pos_list;					/* 0x0064 */
	
	uint8_t								field_0068;							/* 0x0068 */
	uint8_t								field_0069;							/* 0x0069 */
	uint8_t								field_006A;							/* 0x006A */
	uint8_t								field_006B;							/* 0x006B */
	
	nwn_objid_t							obj_action_target;					/* 0x006C */
	
	uint32_t							field_0070;							/* 0x0070 */
	
	uint32_t							obj_area_id;						/* 0x0074 */
	Vector								obj_position;						/* 0x0078 */
	Vector								obj_orientation;					/* 0x0084 */
	
	uint32_t							field_0090;							/* 0x0090 */
	uint32_t							field_0094;							/* 0x0094 */
	
	uint32_t							obj_action_timer_day;				/* 0x0098 */
	uint32_t							obj_action_timer_sec;				/* 0x009C */
	uint32_t							obj_last_anim_time_day;				/* 0x00A0 */
	uint32_t							obj_last_anim_time_sec;				/* 0x00A4 */
	
	uint32_t							field_00A8;							/* 0x00A8 */
	
	int32_t								obj_anim;							/* 0x00AC */
	int32_t								obj_anim_speed;						/* 0x00B0 */
	int16_t								obj_hp_cur;							/* 0x00B4 */
	int16_t									field_00B6;
	int16_t								obj_hp_max;							/* 0x00B8 */
	int16_t									field_00BA;
	
	uint32_t							obj_hp_temp;						/* 0x00BC */
	uint32_t							obj_is_commandable;					/* 0x00C0 */
	uint32_t							obj_is_destroyable;					/* 0x00C4 */
	uint32_t							obj_is_raisable;					/* 0x00C8 */
	uint32_t							obj_is_dead_selectable;				/* 0x00CC */
	uint32_t							obj_is_invulnerable;				/* 0x00D0 */
	void								*obj_actions;						/* 0x00D4 */
	CNWSScriptVarTable					obj_vartable;						/* 0x00D8 */
	
	uint32_t							field_00E0;							/* 0x00E0 */
	uint32_t							field_00E4;							/* 0x00E4 */
	
	CGameEffect							**obj_effects;						/* 0x00E8 */
	uint32_t							obj_effects_len;					/* 0x00EC */
	uint32_t							obj_effects_allocated;				/* 0x00F0 */
	
	void								*obj_visuals;						/* 0x00F4 */
	int32_t								obj_visuals_len;					/* 0x00F8 */
	uint32_t							obj_visuals_allocated;				/* 0x00FC */
	
	nwn_objid_t							*obj_effect_target_list;			/* 0x0100 */
	uint32_t							obj_effect_target_len;				/* 0x0104 */
	uint32_t							obj_effects_target_allocated;		/* 0x0108 */

	uint32_t							obj_pending_effect_removal;			/* 0x010C */
	uint32_t							obj_saving_throw_spellid;			/* 0x0110 */
	int32_t								obj_custom_event_id;				/* 0x0114 */
	nwn_objid_t							obj_killer;							/* 0x0118 */
	nwn_objid_t							obj_last_hostile_actor;				/* 0x011C */
	nwn_objid_t							obj_last_attacker;					/* 0x0120 */
	nwn_objid_t							obj_last_damager;					/* 0x0124 */
	nwn_objid_t							obj_last_disturbed;					/* 0x0128 */
	int32_t								*obj_last_damage;					/* 0x012C */
	uint16_t							obj_last_attack_type;				/* 0x0130 */
	uint8_t								obj_last_attack_mode;				/* 0x0132 */

	uint8_t								field_0133;							/* 0x0133 */

	nwn_objid_t							obj_last_attack_weapon;				/* 0x0134 */
	nwn_objid_t							obj_inv_disturb_item;				/* 0x0138 */
	int32_t								obj_inv_disturb_type;				/* 0x013C */
	nwn_objid_t							obj_conv_last_speaker;				/* 0x0140 */
	uint32_t							obj_conv_private;					/* 0x0144 */
	uint32_t							obj_conv_play_hello;				/* 0x0148 */
	CExoString							obj_conv_last_resref;				/* 0x014C */

	uint32_t							field_0154;							/* 0x0154 */

	void								*obj_listen_expressions;			/* 0x0158 */

	uint32_t							field_015C;							/* 0x015C */
	uint32_t							field_0160;							/* 0x0160 */

	int32_t								obj_matched_position;				/* 0x0164 */
	uint32_t							obj_is_listening;					/* 0x0168 */
	void								*obj_matched_strings;				/* 0x016C */

	uint32_t							field_0170;							/* 0x0170 */

	int16_t								*obj_damage_immunities;				/* 0x0174 */
	Vector								obj_last_spell_location;			/* 0x0178 */
	nwn_objid_t							obj_last_spell_target;				/* 0x0184 */
	uint32_t							obj_last_spell_id;					/* 0x0188 */
	uint8_t								obj_last_spell_domain_level;		/* 0x018C */

	uint8_t								field_018D;							/* 0x018D */
	uint8_t								field_018E;							/* 0x018E */
	uint8_t								field_018F;							/* 0x018F */

	uint32_t							obj_last_spell_proj_time;			/* 0x0190 */
	uint32_t							obj_last_spell_cast;				/* 0x0194 */
	uint32_t							obj_last_spell_spontaneous;			/* 0x0198 */
	uint8_t								obj_last_spell_multiclass;			/* 0x019C */
	uint8_t								obj_last_spell_metamagic;			/* 0x019D */

	uint8_t								field_019E;							/* 0x019E */
	uint8_t								field_019F;							/* 0x019F */

	uint32_t							obj_last_spell_castat_caster;		/* 0x01A0 */
	uint32_t							obj_last_spell_castat_id;			/* 0x01A4 */
	uint32_t							obj_last_spell_castat_harmful;		/* 0x01A8 */
	uint16_t							obj_last_spell_feat;				/* 0x01AC */

	uint16_t							field_01AE;							/* 0x01AE */

	void								*obj_ai_action;						/* 0x01B0 */
	uint16_t							obj_effect_index;					/* 0x01B4 */

	uint16_t							field__01B6;						/* 0x01B4 */

	uint32_t							obj_effect_postprocess;				/* 0x01B8 */
	uint32_t							obj_door_anim_played;				/* 0x01BC */

CNWSItem *AsNWSItem();
CNWSModule *AsModule();
CNWSAreaOfEffectObject *AsNWSAreaOfEffectObject();
CNWSArea *AsNWSArea();
CNWSStore *AsNWSStore();


int16_t				ApplyEffect(CGameEffect *Effect, int a3, int a4);
void *				BroadcastDialog(CExoString Msg, float Max_Distance);
void 				ClearSpellEffectsOnOthers();
int 				DoDamageImmunity(CNWSCreature *Attacker, int DamageDelivered, int DamageFlags, int _bMaxDamage, int bFeedback);
int					DoDamageResistance(CNWSCreature *a2, int a3, signed int a4, int a5, int a6, int a7);
CNWSArea * 			GetArea();
int16_t 			GetCurrentHitPoints(int bExcludeTemp);
char				GetDamageImmunityByFlags(uint16_t Flags);
int 				GetDead();
int					GetIsPCDying();
int  				GetMaximumDamageResistanceVsDamageFlag(uint16_t DamageType, int *EffectIndex);
void 				LoadVarTable(CResGFF *pResGFF, CResStruct *pResStruct);
int					RemoveEffectById(uint64_t EffID);
unsigned int 		SetArea(CNWSArea *Area);
void 				SetOrientation(Vector v);
void 				SetPosition(Vector v, int a3);
void 				SetTag(CExoString sTag);
void 				SaveVarTable(CResGFF *pResGFF, CResStruct *pResStruct);




};

#endif