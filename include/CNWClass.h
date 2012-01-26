#ifndef _H_CNWCLASS_H_
#define _H_CNWCLASS_H_

struct CNWClass_s {
  uint32_t name_tlk;
  uint32_t name_lower_tlk;
  uint32_t name_plural;
  uint32_t description_tlk;
  CExoString Icon;
  uint32_t f18;
  uint32_t f1C;
  uint8_t AttackBonusTable[60];
  uint8_t HitDie;
  uint8_t SkillPointBase;
  uint8_t FortSaveTable[60];
  uint8_t ReflSaveTable[60];
  uint8_t WillSaveTable[60];
  uint8_t byte112;
  uint8_t byte113;
  void *SpellsKnown;
  unsigned __int8 NumSpellLevels[40];
  uint32_t SpellGain[40];
  uint32_t *SkillsTable;
  uint32_t SkillsTable_Len;
  uint32_t *feats;
  uint32_t feats_len;
  uint8_t f1f0[38];
  uint8_t PrimaryAbility;
  uint32_t dword217;
  uint16_t word21B;
  uint8_t AlignRestrict;
  uint8_t AlignRestrictType;
  uint8_t f21F[1];
  uint32_t InvertRestrict;
  uint8_t EffCRLvl[40];
  uint32_t DWord24C;
  uint32_t PlayerClass;
  uint32_t SpellCaster;
  uint32_t DWord258;
  uint32_t XPPenalty;
  uint32_t Package;
  uint8_t ArcSpellLvlMod;
  uint8_t DivSpellLvlMod;
  uint8_t EpicLevel;
  uint8_t byte267;
  

  unsigned char GetFortSaveBonus(uint8_t Level);
  unsigned char GetWillSaveBonus(uint8_t Level);
  unsigned char GetRefSaveBonus(uint8_t Level);
  char GetAttackBonus(uint8_t Level);
};

#endif