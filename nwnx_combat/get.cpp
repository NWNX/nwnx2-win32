int __thiscall CNWSCreatureStats__GetMeleeAttackBonus(CNWSCreatureStats *CreatureStats_this, int a2, int AttackBonus_3, int a4)
{
  CNWSCreatureStats *CreatureStats; // esi@1
  CNWSItem *Item_1; // ebp@2
  CNWBaseItem *v6; // eax@3
  CNWSItem *Item_2; // eax@3
  int v8; // ebx@6
  int v9; // edi@6
  int AttackBonus_1; // ebx@11
  int v11; // ebx@15
  signed int v13; // edi@19
  int AttackBonus_4; // ebx@25
  signed int v15; // edi@25
  int AttackBonus_2; // ebx@31
  signed int v17; // edi@31
  signed int v18; // edx@47
  char v19; // bl@47
  char *v20; // ebp@48
  unsigned __int8 v21; // al@50
  long double v22; // fst7@55
  signed int v23; // ebx@56
  CNWSItem *SlotItem; // edi@56
  CNWBaseItem *BaseItem; // eax@58
  CNWBaseItem *v26; // eax@63
  CNWBaseItem *v27; // ebp@63
  CNWBaseItem *v28; // ebp@71
  char v29; // [sp-1Ch] [bp-38h]@13
  CNWSObject *v30; // [sp-18h] [bp-34h]@13
  int v31; // [sp-14h] [bp-30h]@13
  int v32; // [sp-10h] [bp-2Ch]@13
  unsigned __int8 v33; // [sp-Ch] [bp-28h]@13
  unsigned __int8 v34; // [sp-8h] [bp-24h]@13
  unsigned __int8 v35; // [sp-4h] [bp-20h]@13
  unsigned __int8 v36; // [sp+0h] [bp-1Ch]@13
  int v37; // [sp+4h] [bp-18h]@13
  int v38; // [sp+24h] [bp+8h]@31
  int v39; // [sp+28h] [bp+Ch]@47

  CreatureStats = CreatureStats_this;

///// Ability Bonus //////
  if ( !a2 || (Item_1 = CNWSInventory__GetItemInSlot(32), !Item_1) 
  	&& (Item_2 = CNWSInventory__GetItemInSlot(16), (v6 = CNWBaseItemArray__GetBaseItem(*(CNWBaseItemArray **)(g_pRules + 24), Item_2->BaseItem)) != 0)
    && v6->WeaponWield == 8 )
    Item_1 = CNWSInventory__GetItemInSlot(16);
  v9 = 0;
  v8 = 0;
  if ( !CNWSCreatureStats__GetWeaponFinesse(CreatureStats, Item_1)
    || CNWSCreatureStats__GetDEXMod(CreatureStats, 0) <= CreatureStats->cs_str_mod
    || a4 )
    v8 = CreatureStats->cs_str_mod;
  else
    v9 = CNWSCreatureStats__GetDEXMod(CreatureStats, 0);
  AttackBonus_1 = v9 + v8;


  if ( AttackBonus_3 == 1 )
  {
    if ( a4 )
    {
      v37 = a2;
      v36 = -1;
      v35 = -1;
      v34 = 0;
      v33 = 0;
      v32 = 0;
      v31 = 0;
      v30 = 0;
      v29 = 6;
    }
    else
    {
      v37 = a2;
      v36 = -1;
      v35 = -1;
      v34 = 0;
      v33 = 0;
      v32 = 0;
      v31 = 0;
      v30 = 0;
      v29 = 1;
    }
    v11 = CNWSCreature__GetTotalEffectBonus(CreatureStats->cs_original, v29, v30, v31, v32, v33, v34, v35, v36, v37)
        + AttackBonus_1;
    AttackBonus_1 = CNWSCreatureStats__GetBaseAttackBonus(CreatureStats, 0) + v11;
  }
  if ( Item_1 && CNWBaseItemArray__GetBaseItem(*(CNWBaseItemArray **)(g_pRules + 24), Item_1->BaseItem)->RangedWeapon )
    return a4 != 0 ? AttackBonus_1 : 0;
  v13 = 0;
  if ( a4 != 1 )
  {
    if ( !CNWSCreatureStats__GetWeaponFocus(CreatureStats, Item_1) )
      goto LABEL_25;
    goto LABEL_24;
  }
  if ( !Item_1 && CNWSCreatureStats__GetWeaponFocus(CreatureStats, 0) )
LABEL_24:
    v13 = 1;
LABEL_25:
  AttackBonus_4 = v13 + AttackBonus_1;
  v15 = 0;
  if ( a4 != 1 )
  {
    if ( !CNWSCreatureStats__GetEpicWeaponFocus(CreatureStats, Item_1) )
      goto LABEL_31;
    goto LABEL_30;
  }
  if ( !Item_1 && CNWSCreatureStats__GetEpicWeaponFocus(CreatureStats, 0) )
LABEL_30:
    v15 = 2;
LABEL_31:
  AttackBonus_2 = v15 + AttackBonus_4;
  v38 = AttackBonus_2;
  v17 = 0;
  if ( CNWSObject__GetArea(CreatureStats->cs_original) )
  {
    if ( *(_BYTE *)(CNWSObject__GetArea(CreatureStats->cs_original) + 4) & 4 )
    {
      if ( !(*(_BYTE *)(CNWSObject__GetArea(CreatureStats->cs_original) + 4) & 1) )
      {
        if ( !(*(_BYTE *)(CNWSObject__GetArea(CreatureStats->cs_original) + 4) & 2) )
        {
          if ( CNWSCreatureStats__HasFeat(CreatureStats, 198) )
            v17 = 2;
          AttackBonus_2 += v17;
          v38 = AttackBonus_2;
        }
      }
    }
  }
  if ( CNWSCreatureStats__HasFeat(CreatureStats, 584) )
  {
    ++AttackBonus_2;
    v38 = AttackBonus_2;
  }
  if ( a4 )
    return AttackBonus_2;
  if ( Item_1 )
  {
    if ( CNWSCreatureStats__HasFeat(CreatureStats, 884) )
    {
      if ( CNWSCreatureStats__GetIsWeaponOfChoice(Item_1->BaseItem) )
        v38 = AttackBonus_2 + 1;
    }
    if ( CNWSCreatureStats__HasFeat(CreatureStats, 1071) )
    {
      if ( CNWSCreatureStats__GetIsWeaponOfChoice(Item_1->BaseItem) )
      {
        v19 = CreatureStats->cs_classes_len;
        v18 = 0;
        v39 = 0;
        if ( (signed int)(unsigned __int8)v19 > 0 )
        {
          v20 = (char *)&CreatureStats->cs_classes[0].cl_level;
          do
          {
            if ( (_BYTE)v18 < (unsigned __int8)v19 )
              v21 = CreatureStats->cs_classes[(unsigned __int8)v18].cl_class;
            else
              v21 = -1;
            if ( v21 == CNWClass__CCLASS_KENSEI )
              v39 = (unsigned __int8)*v20;
            ++v18;
            v20 += 280;
          }
          while ( v18 < (unsigned __int8)v19 );
        }
        v22 = (long double)((v39 - 10) / 3);
        floor(v22);
        v38 += (signed __int64)v22;
      }
    }
  }
  v23 = 0;
  SlotItem = CNWSInventory__GetItemInSlot(32);
  if ( !SlotItem )
  {
    SlotItem = CNWSInventory__GetItemInSlot(16);
    if ( SlotItem )
    {
      BaseItem = CNWBaseItemArray__GetBaseItem(*(CNWBaseItemArray **)(g_pRules + 24), SlotItem->BaseItem);
      if ( BaseItem )
      {
        if ( BaseItem->WeaponWield != 8 )
          SlotItem = 0;
      }
    }
  }
  if ( a2 )
  {
    if ( !SlotItem )
      return v23 + v38;
    v28 = CNWBaseItemArray__GetBaseItem(*(CNWBaseItemArray **)(g_pRules + 24), SlotItem->BaseItem);
    if ( !v28 )
      return v23 + v38;
    v23 = -10;
    if ( CNWSCreature__GetRelativeWeaponSize(CreatureStats->cs_original, SlotItem) <= -1 || v28->WeaponWield == 8 )
      v23 = -8;
    if ( CNWSCreatureStats__HasFeat(CreatureStats, 1) )
      v23 += 4;
    if ( !CNWSCreatureStats__HasFeat(CreatureStats, 41) )
      return v23 + v38;
  }
  else
  {
    if ( !SlotItem )
      return v23 + v38;
    v26 = CNWBaseItemArray__GetBaseItem(*(CNWBaseItemArray **)(g_pRules + 24), SlotItem->BaseItem);
    v27 = v26;
    if ( !v26 )
      return v23 + v38;
    if ( !v26->WeaponType )
      return v23 + v38;
    v23 = -6;
    if ( CNWSCreature__GetRelativeWeaponSize(CreatureStats->cs_original, SlotItem) <= -1 || v27->WeaponWield == 8 )
      v23 = -4;
    if ( !CNWSCreatureStats__HasFeat(CreatureStats, 41) )
      return v23 + v38;
  }
  v23 += 2;
  return v23 + v38;
}
