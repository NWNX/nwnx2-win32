#ifndef _NX_NWN_STRUCT_CNWSCOMBATROUND_
#define _NX_NWN_STRUCT_CNWSCOMBATROUND_
 
 struct CNWSCombatRound_s
{
  CNWSCombatAttackData AttackData[50];
  unsigned __int16 *SpecialAttack;
  __int32 SpecAttackList;
  unsigned __int8 field_9;
  unsigned __int8 field_10;
  unsigned __int8 field_11;
  unsigned __int8 field_12;
  unsigned __int16 *SpecialAttackId;
  __int32 SpecAttackIdList;
  unsigned __int8 field_21;
  unsigned __int8 field_22;
  unsigned __int8 field_23;
  unsigned __int8 field_24;
  __int16 AttackID[2];
  unsigned __int8 RoundStarted;
  unsigned __int8 field_30;
  unsigned __int8 field_31;
  unsigned __int8 field_32;
  unsigned __int8 SpellCastRound;
  unsigned __int8 field_34;
  unsigned __int8 field_35;
  unsigned __int8 field_36;
  unsigned __int32 Timer;
  unsigned __int32 RoundLength;
  unsigned __int32 OverlapAmount;
  unsigned __int32 BleedTimer;
  unsigned __int8 RoundPaused;
  unsigned __int8 field_54;
  unsigned __int8 field_55;
  unsigned __int8 field_56;
  unsigned __int32 RoundPausedBy;
  unsigned __int32 PauseTimer;
  unsigned __int8 InfinitePause;
  unsigned __int8 field_66;
  unsigned __int8 field_67;
  unsigned __int8 field_68;
  unsigned __int8 CurrentAttack;
  unsigned __int8 AttackGroup;
  unsigned __int8 field_71;
  unsigned __int8 field_72;
  unsigned __int8 DeflectArrow;
  unsigned __int8 field_74;
  unsigned __int8 field_75;
  unsigned __int8 field_76;
  unsigned __int8 WeaponSucks;
  unsigned __int8 field_78;
  unsigned __int8 field_79;
  unsigned __int8 field_80;
  unsigned __int8 EpicDodgeUsed;
  unsigned __int8 field_82;
  unsigned __int8 field_83;
  unsigned __int8 field_84;
  unsigned __int32 ParryIndex;
  unsigned __int32 NumAOOs;
  unsigned __int32 NumCleaves;
  unsigned __int32 NumCircleKicks;
  unsigned __int32 NewAttackTarget;
  unsigned __int32 OnHandAttacks;
  unsigned __int32 OffHandAttacks;
  unsigned __int32 OffHandTaken;
  unsigned __int32 ExtraTaken;
  unsigned __int32 AdditAttacks;
  unsigned __int32 EffectAttacks;
  unsigned __int8 ParryActions;
  unsigned __int8 field_130;
  unsigned __int8 field_131;
  unsigned __int8 field_132;
  unsigned __int32 DodgeTarget;
  unsigned __int32 **SchedActionList;
  CNWSCreature *org_nwcreature;

	void		ClearAllAttacks();
	CNWSItem *	GetCurrentAttackWeapon(uint32_t a2);
	void		StartCombatRound(nwn_objid_t oidDefender);

};

#endif