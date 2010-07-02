#ifndef _H_CCOMBATINFORMATION_H_
#define _H_CCOMBATINFORMATION_H_

struct CCombatinformation_s {
  unsigned __int8 NumAttacks;
  unsigned __int8 OnHandAttackMod;
  unsigned __int8 OnHandDamageMod;
  unsigned __int8 OffHandAttackMod;
  unsigned __int8 OffHandDamageMod;
  unsigned __int8 SpellResistance;
  unsigned __int8 ArcaneSpellFail;
  unsigned __int8 ArmorCheckPen;
  unsigned __int8 UnarmedDamDice;
  unsigned __int8 UnarmedDamDie;
  unsigned __int8 field_0A;
  unsigned __int8 field_0B;
  unsigned __int8 field_0C;
  unsigned __int8 field_0D;
  unsigned __int8 field_0E;
  unsigned __int8 field_0F;
  unsigned __int8 field_10;
  unsigned __int8 field_11;
  unsigned __int8 field_12;
  unsigned __int8 OnHandCritRng;
  unsigned __int8 OnHandCritMult;
  unsigned __int8 field_15;
  unsigned __int8 field_16;
  unsigned __int8 field_17;
  unsigned __int32 OffHandWeaponEq;
  unsigned __int8 OffHandCritRng;
  unsigned __int8 OffHandCritMult;
  unsigned __int8 field_1E;
  unsigned __int8 field_1F;
  void *field_20;
  unsigned __int8 AttackList_Len_;
  unsigned __int8 field_25;
  unsigned __int8 field_26;
  unsigned __int8 field_27;
  unsigned __int8 AttackList;
  unsigned __int8 field_29;
  unsigned __int8 field_2A;
  unsigned __int8 field_2B;
  void *field_2C;
  unsigned __int8 DamageList_Len_;
  unsigned __int8 field_31;
  unsigned __int8 field_32;
  unsigned __int8 field_33;
  unsigned __int8 DamageList;
  unsigned __int8 field_35;
  unsigned __int8 field_36;
  unsigned __int8 field_37;
  unsigned __int32 RightEquip;
  unsigned __int32 LeftEquip;
  CExoString RightString;
  CExoString LeftString;
  unsigned __int8 DamageDice;
  unsigned __int8 DamageDie;
  unsigned __int8 field_52;
  unsigned __int8 field_53;
  unsigned __int8 field_54;
};

#endif