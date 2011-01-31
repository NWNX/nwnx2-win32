#ifndef __H_CNWSPELL_H__
#define __H_CNWSPELL_H__

struct CNWSpell_s {
  char				*sp_label;			// 0x00
  unsigned __int32	field_004;			// 0x04
  unsigned __int32	sp_name_tlk;		// 0x08
  unsigned __int32	sp_desc_tlk;		// 0x0C
  char 				sp_icon_resref[16];	// 0x10
  unsigned __int32	sp_school;			// 0x20
  CExoString		sp_range;			// 0x24
  CExoString		sp_spellcomponent;	// 0x2C
  unsigned __int32	sp_targettype;		// 0x34
  CExoString		sp_impactscript;	// 0x38
  unsigned __int8	sp_level_bard;		// 0x40
  unsigned __int8	sp_level_cleric;    // 0x41
  unsigned __int8	sp_level_druid;     // 0x42
  unsigned __int8	sp_level_paladin;   // 0x43
  unsigned __int8	sp_level_ranger;    // 0x44
  unsigned __int8	sp_level_sorc;      // 0x45
  unsigned __int8	sp_level_wiz;       // 0x46
  unsigned __int8	sp_level_innate;    // 0x47
  unsigned __int32	sp_conjtime;		// 0x48
  unsigned __int32 field_04C;
  unsigned __int32 field_050;
  unsigned __int32 field_054;
  unsigned __int32 field_058;
  unsigned __int8 field_05C;
  unsigned __int8 field_05D;
  char				sp_conjhandvisual[16];		// 0x5e
  char field_06E[16];
  char				sp_conjsoundmale[16];		// 0x7e
  char				sp_conjsoundfemale[16];		// 0x8e
  char				sp_conjsoundvfx[16];		// 0x9e
  unsigned __int8 field_0AE;
  unsigned __int8 field_0AF;
  unsigned __int8 field_0B0;
  unsigned __int8 field_0B1;
  unsigned __int8 field_0B2;
  unsigned __int8 field_0B3;
  unsigned __int8 field_0B4;
  unsigned __int8 field_0B5;
  unsigned __int8 field_0B6;
  unsigned __int8 field_0B7;
  unsigned __int8 field_0B8;
  unsigned __int8 field_0B9;
  unsigned __int8 field_0BA;
  unsigned __int8 field_0BB;
  unsigned __int8 field_0BC;
  unsigned __int8 field_0BD;
  unsigned __int8 field_0BE;
  unsigned __int8 field_0BF;
  unsigned __int8 field_0C0;
  unsigned __int8 field_0C1;
  unsigned __int8 field_0C2;
  unsigned __int8 field_0C3;
  unsigned __int8 field_0C4;
  unsigned __int8 field_0C5;
  unsigned __int8 field_0C6;
  unsigned __int8 field_0C7;
  unsigned __int8 field_0C8;
  unsigned __int8 field_0C9;
  unsigned __int8 field_0CA;
  unsigned __int8 field_0CB;
  unsigned __int8 field_0CC;
  unsigned __int8 field_0CD;
  unsigned __int8 field_0CE;
  unsigned __int8 field_0CF;
  unsigned __int8 field_0D0;
  unsigned __int8 field_0D1;
  unsigned __int8 field_0D2;
  unsigned __int8 field_0D3;
  unsigned __int8 field_0D4;
  unsigned __int8 field_0D5;
  unsigned __int8 field_0D6;
  unsigned __int8 field_0D7;
  unsigned __int8 field_0D8;
  unsigned __int8 field_0D9;
  unsigned __int8 field_0DA;
  unsigned __int8 field_0DB;
  unsigned __int8 field_0DC;
  unsigned __int8 field_0DD;
  unsigned __int8 field_0DE;
  unsigned __int8 field_0DF;
  unsigned __int8 field_0E0;
  unsigned __int8 field_0E1;
  unsigned __int8 field_0E2;
  unsigned __int8 field_0E3;
  unsigned __int8 field_0E4;
  unsigned __int8 field_0E5;
  unsigned __int8 field_0E6;
  unsigned __int8 field_0E7;
  unsigned __int8 field_0E8;
  unsigned __int8 field_0E9;
  unsigned __int8 field_0EA;
  unsigned __int8 field_0EB;
  unsigned __int8 field_0EC;
  unsigned __int8 field_0ED;
  unsigned __int8 field_0EE;
  unsigned __int8 field_0EF;
  unsigned __int8 field_0F0;
  unsigned __int8 field_0F1;
  unsigned __int8 field_0F2;
  unsigned __int8 field_0F3;
  unsigned __int8 field_0F4;
  unsigned __int8 field_0F5;
  unsigned __int8 field_0F6;
  unsigned __int8 field_0F7;
  unsigned __int8 field_0F8;
  unsigned __int8 field_0F9;
  unsigned __int8 field_0FA;
  unsigned __int8 field_0FB;
  unsigned __int8 field_0FC;
  unsigned __int8 field_0FD;
  unsigned __int8 field_0FE;
  unsigned __int8 field_0FF;
  unsigned __int8 field_100;
  unsigned __int8 field_101;
  unsigned __int8 field_102;
  unsigned __int8 field_103;
  unsigned __int8 field_104;
  unsigned __int8 field_105;
  unsigned __int8 field_106;
  unsigned __int8 field_107;
  unsigned __int8 field_108;
  unsigned __int8 field_109;
  unsigned __int8 field_10A;
  unsigned __int8 field_10B;
  unsigned __int8 field_10C;
  unsigned __int8 field_10D;
  unsigned __int8 field_10E;
  unsigned __int8 field_10F;
  unsigned __int8 field_110;
  unsigned __int8 field_111;
  unsigned __int8 field_112;
  unsigned __int8 field_113;
  unsigned __int8 field_114;
  unsigned __int8 field_115;
  unsigned __int8 field_116;
  unsigned __int8 field_117;
  unsigned __int8 field_118;
  unsigned __int8 field_119;
  unsigned __int8 field_11A;
  unsigned __int8 field_11B;
  unsigned __int8 field_11C;
  unsigned __int8 field_11D;
  unsigned __int8 field_11E;
  unsigned __int8 field_11F;
  unsigned __int8 field_120;
  unsigned __int8 field_121;
  unsigned __int8 field_122;
  unsigned __int8 field_123;
  unsigned __int8 field_124;
  unsigned __int8 field_125;
  unsigned __int8 field_126;
  unsigned __int8 field_127;
  unsigned __int8 field_128;
  unsigned __int8 field_129;
  unsigned __int8 field_12A;
  unsigned __int8 field_12B;
  unsigned __int8 sp_subradial_spells;
  unsigned __int8 field_12D;
  unsigned __int8 field_12E;
  unsigned __int8 field_12F;
  unsigned __int8 sp_subradialspells_len;
  unsigned __int8 field_131;
  unsigned __int8 field_132;
  unsigned __int8 field_133;
  unsigned __int8 field_134;
  unsigned __int8 field_135;
  unsigned __int8 field_136;
  unsigned __int8 field_137;
  unsigned __int32 sp_ID;
  unsigned __int8 field_13C;
  unsigned __int8 field_13D;
  unsigned __int8 field_13E;
  unsigned __int8 field_13F;
  unsigned __int8 field_140;
  unsigned __int8 field_141;
  unsigned __int8 field_142;
  unsigned __int8 field_143;
  unsigned __int8 UserType;
  unsigned __int8 field_145;
  unsigned __int8 field_146;
  unsigned __int8 field_147;
  unsigned __int8 field_148;
  unsigned __int8 field_149;
  unsigned __int8 field_14A;
  unsigned __int8 field_14B;
  unsigned __int8 field_14C;
  unsigned __int8 field_14D;
  unsigned __int8 field_14E;
  unsigned __int8 field_14F;
  unsigned __int8 field_150;
  unsigned __int8 field_151;
  unsigned __int8 field_152;
  unsigned __int8 field_153;
  unsigned __int8 field_154;
  unsigned __int8 field_155;
  unsigned __int8 field_156;
  unsigned __int8 field_157;
  unsigned __int8 field_158;
  unsigned __int8 field_159;
  unsigned __int8 field_15A;
  unsigned __int8 field_15B;
  unsigned __int8 field_15C;
  unsigned __int8 field_15D;
  unsigned __int8 field_15E;
  unsigned __int8 field_15F;
  unsigned __int8 field_160;
  unsigned __int8 field_161;
  unsigned __int8 field_162;
  unsigned __int8 field_163;
};
#endif


