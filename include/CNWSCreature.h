#ifndef _NX_NWN_STRUCT_CNWSCREATURE_
#define _NX_NWN_STRUCT_CNWSCREATURE_

struct CNWSCreature_s {
    CNWSObject                  		obj;
  unsigned __int32							spacer_01;
  unsigned __int32							spacer_02;
  unsigned __int32							spacer_03;
  unsigned __int32							spacer_04;
  unsigned __int32							spacer_05;
  unsigned __int32							spacer_06;
  unsigned __int32							spacer_07;
  unsigned __int32							spacer_08;
  unsigned __int32							spacer_09;
  unsigned __int32							spacer_10;
  unsigned __int32							spacer_11;
  unsigned __int32							spacer_12;
  unsigned __int32							spacer_13;
    CNWSCreatureEventHandler			cre_events;							/* 0x01F4 */  /* size: 104 (13*8 bytes) */
	uint32_t								spacer1[26];						/* 0x025C */
	CNWSQuickbarButton					*cre_quickbar;						/* 0x02C4 */
    uint32_t                    		cre_lootable;           			/* 02C8 */
    uint32_t                    		cre_decaytime;          			/* 02CC */
    uint32_t                    		cre_bodybag_id;         			/* 02D0 */
	uint32_t 							cre_area_id;
	float 								cre_XPosition;
	float 								cre_YPosition;
	float 								cre_ZPosition;
	uint8_t 								spacer2_017;
	uint8_t 								spacer2_018;
	uint8_t 								spacer2_019;
	uint8_t 								spacer2_020;
	uint8_t 								spacer2_021;
	uint8_t 								spacer2_022;
	uint8_t 								spacer2_023;
	uint8_t 								spacer2_024;
	uint8_t 								spacer2_025;
	uint8_t 								spacer2_026;
	uint8_t 								spacer2_027;
	uint8_t 								spacer2_028;
	uint8_t 								spacer2_029;
	uint8_t 								spacer2_030;
	uint8_t 								spacer2_031;
	uint8_t 								spacer2_032;
	uint8_t 								spacer2_033;
	uint8_t 								spacer2_034;
	uint8_t 								spacer2_035;
	uint8_t 								spacer2_036;
	uint8_t 								spacer2_037;
	uint8_t 								spacer2_038;
	uint8_t 								spacer2_039;
	uint8_t 								spacer2_040;
	uint8_t 								spacer2_041;
	uint8_t 								spacer2_042;
	uint8_t 								spacer2_043;
	uint8_t 								spacer2_044;
	uint8_t 								spacer2_045;
	uint8_t 								spacer2_046;
	uint8_t 								spacer2_047;
	uint8_t 								spacer2_048;
	uint8_t 								spacer2_049;
	uint8_t 								spacer2_050;
	uint8_t 								spacer2_051;
	uint8_t 								spacer2_052;
	uint8_t 								spacer2_053;
	uint8_t 								spacer2_054;
	uint8_t 								spacer2_055;
	uint8_t 								spacer2_056;
	uint32_t 								spacer2_057;
	uint8_t 								spacer2_061;
	uint8_t 								spacer2_062;
	uint8_t 								spacer2_063;
	uint8_t 								spacer2_064;
	uint32_t 							cre_CreatnScrptFird;
	uint8_t 								spacer2_069;
	uint8_t 								spacer2_070;
	uint8_t 								spacer2_071;
	uint8_t 								spacer2_072;
	uint8_t 								spacer2_073;
	uint8_t 								spacer2_074;
	uint8_t 								spacer2_075;
	uint8_t 								spacer2_076;
	uint8_t 								spacer2_077;
	uint8_t 								spacer2_078;
	uint8_t 								spacer2_079;
	uint8_t 								spacer2_080;
	uint8_t 								spacer2_081;
	uint8_t 								spacer2_082;
	uint8_t 								spacer2_083;
	uint8_t 								spacer2_084;
	uint8_t 								spacer2_085;
	uint8_t 								spacer2_086;
	uint8_t 								spacer2_087;
	uint8_t 								spacer2_088;
	uint8_t 								spacer2_089;
	uint8_t 								spacer2_090;
	uint8_t 								spacer2_091;
	uint8_t 								spacer2_092;
	uint8_t 								spacer2_093;
	uint8_t 								spacer2_094;
	uint8_t 								spacer2_095;
	uint8_t 								spacer2_096;
	uint8_t 								spacer2_097;
	uint8_t 								spacer2_098;
	uint8_t 								spacer2_099;
	uint8_t 								spacer2_100;
	uint8_t 								spacer2_101;
	uint8_t 								spacer2_102;
	uint8_t 								spacer2_103;
	uint8_t 								spacer2_104;
	uint8_t 								spacer2_105;
	uint8_t 								spacer2_106;
	uint8_t 								spacer2_107;
	uint8_t 								spacer2_108;
	uint8_t 								spacer2_109;
	uint8_t 								spacer2_110;
	uint8_t 								spacer2_111;
	uint8_t 								spacer2_112;
	uint8_t 								spacer2_113;
	uint8_t 								spacer2_114;
	uint8_t 								spacer2_115;
	uint8_t 								spacer2_116;
	uint8_t 								spacer2_117;
	uint8_t 								spacer2_118;
	uint8_t 								spacer2_119;
	uint8_t 								spacer2_120;
	uint8_t 								spacer2_121;
	uint8_t 								spacer2_122;
	uint8_t 								spacer2_123;
	uint8_t 								spacer2_124;
	uint8_t 								spacer2_125;
	uint8_t 								spacer2_126;
	uint8_t 								spacer2_127;
	uint8_t 								spacer2_128;
	uint8_t 								spacer2_129;
	uint8_t 								spacer2_130;
	uint8_t 								spacer2_131;
	uint8_t 								spacer2_132;
	uint8_t 								spacer2_133;
	uint8_t 								spacer2_134;
	uint8_t 								spacer2_135;
	uint8_t 								spacer2_136;
	uint8_t 								spacer2_137;
	uint8_t 								spacer2_138;
	uint8_t 								spacer2_139;
	uint8_t 								spacer2_140;
	uint8_t 								spacer2_141;
	uint8_t 								spacer2_142;
	uint8_t 								spacer2_143;
	uint8_t 								spacer2_144;
	uint8_t 								spacer2_145;
	uint8_t 								spacer2_146;
	uint8_t 								spacer2_147;
	uint8_t 								spacer2_148;
	uint8_t 								spacer2_149;
	uint8_t 								spacer2_150;
	uint8_t 								spacer2_151;
	uint8_t 								spacer2_152;
	uint8_t 								spacer2_153;
	uint8_t 								spacer2_154;
	uint8_t 								spacer2_155;
	uint8_t 								spacer2_156;
	uint8_t 								spacer2_157;
	uint8_t 								spacer2_158;
	uint8_t 								spacer2_159;
	uint8_t 								spacer2_160;
	uint8_t 								spacer2_161;
	uint8_t 								spacer2_162;
	uint8_t 								spacer2_163;
	uint8_t 								spacer2_164;
	uint8_t 								spacer2_165;
	uint8_t 								spacer2_166;
	uint8_t 								spacer2_167;
	uint8_t 								spacer2_168;
	uint8_t 								spacer2_169;
	uint8_t 								spacer2_170;
	uint8_t 								spacer2_171;
	uint8_t 								spacer2_172;
	uint8_t 								spacer2_173;
	uint8_t 								spacer2_174;
	uint8_t 								spacer2_175;
	uint8_t 								spacer2_176;
	uint8_t 								spacer2_177;
	uint8_t 								spacer2_178;
	uint8_t 								spacer2_179;
	uint8_t 								spacer2_180;
	uint8_t 								spacer2_181;
	uint8_t 								spacer2_182;
	uint8_t 								spacer2_183;
	uint8_t 								spacer2_184;
	uint8_t 								spacer2_185;
	uint8_t 								spacer2_186;
	uint8_t 								spacer2_187;
	uint8_t 								spacer2_188;
	uint8_t 								spacer2_189;
	uint8_t 								spacer2_190;
	uint8_t 								spacer2_191;
	uint8_t 								spacer2_192;
	uint8_t 								spacer2_193;
	uint8_t 								spacer2_194;
	uint8_t 								spacer2_195;
	uint8_t 								spacer2_196;
	uint8_t 								spacer2_197;
	uint8_t 								spacer2_198;
	uint8_t 								spacer2_199;
	uint8_t 								spacer2_200;
	uint8_t 								spacer2_201;
	uint8_t 								spacer2_202;
	uint8_t 								spacer2_203;
	uint8_t 								spacer2_204;
	uint8_t 								spacer2_205;
	uint8_t 								spacer2_206;
	uint8_t 								spacer2_207;
	uint8_t 								spacer2_208;
	uint8_t 								spacer2_209;
	uint8_t 								spacer2_210;
	uint8_t 								spacer2_211;
	uint8_t 								spacer2_212;
	uint8_t 								spacer2_213;
	uint8_t 								spacer2_214;
	uint8_t 								spacer2_215;
	uint8_t 								spacer2_216;
	uint8_t 								spacer2_217;
	uint8_t 								spacer2_218;
	uint8_t 								spacer2_219;
	uint8_t 								spacer2_220;
	uint8_t 								spacer2_221;
	uint8_t 								spacer2_222;
	uint8_t 								spacer2_223;
	uint8_t 								spacer2_224;
	uint8_t 								spacer2_225;
	uint8_t 								spacer2_226;
	uint8_t 								spacer2_227;
	uint8_t 								spacer2_228;
	uint8_t 								spacer2_229;
	uint8_t 								spacer2_230;
	uint8_t 								spacer2_231;
	uint8_t 								spacer2_232;
	uint8_t 								spacer2_233;
	uint8_t 								spacer2_234;
	uint8_t 								spacer2_235;
	uint8_t 								spacer2_236;
	uint8_t 								spacer2_237;
	uint8_t 								spacer2_238;
	uint8_t 								spacer2_239;
	uint8_t 								spacer2_240;
	uint8_t 								spacer2_241;
	uint8_t 								spacer2_242;
	uint8_t 								spacer2_243;
	uint8_t 								spacer2_244;
	uint8_t 								spacer2_245;
	uint8_t 								spacer2_246;
	uint8_t 								spacer2_247;
	uint8_t 								spacer2_248;
	uint8_t 								spacer2_249;
	uint8_t 								spacer2_250;
	uint8_t 								spacer2_251;
	uint8_t 								spacer2_252;
	uint8_t 								spacer2_253;
	uint8_t 								spacer2_254;
	uint8_t 								spacer2_255;
	uint8_t 								spacer2_256;
	uint8_t 								spacer2_257;
	uint8_t 								spacer2_258;
	uint8_t 								spacer2_259;
	uint8_t 								spacer2_260;
	uint8_t 								spacer2_261;
	uint8_t 								spacer2_262;
	uint8_t 								spacer2_263;
	uint8_t 								spacer2_264;
	uint8_t 								spacer2_265;
	uint8_t 								spacer2_266;
	uint8_t 								spacer2_267;
	uint8_t 								spacer2_268;
	uint8_t 								spacer2_269;
	uint8_t 								spacer2_270;
	uint8_t 								spacer2_271;
	uint8_t 								spacer2_272;
	uint8_t 								spacer2_273;
	uint8_t 								spacer2_274;
	uint8_t 								spacer2_275;
	uint8_t 								spacer2_276;
	uint8_t 								spacer2_277;
	uint8_t 								spacer2_278;
	uint8_t 								spacer2_279;
	uint8_t 								spacer2_280;
	uint8_t 								spacer2_281;
	uint8_t 								spacer2_282;
	uint8_t 								spacer2_283;
	uint8_t 								spacer2_284;
	uint8_t 								spacer2_285;
	uint8_t 								spacer2_286;
	uint8_t 								spacer2_287;
	uint8_t 								spacer2_288;
	uint8_t 								spacer2_289;
	uint8_t 								spacer2_290;
	uint8_t 								spacer2_291;
	uint8_t 								spacer2_292;
	uint8_t 								spacer2_293;
	uint8_t 								spacer2_294;
	uint8_t 								spacer2_295;
	uint8_t 								spacer2_296;
	uint8_t 								spacer2_297;
	uint8_t 								spacer2_298;
	uint8_t 								spacer2_299;
	uint8_t 								spacer2_300;
	uint8_t 								spacer2_301;
	uint8_t 								spacer2_302;
	uint8_t 								spacer2_303;
	uint8_t 								spacer2_304;
	uint8_t 								spacer2_305;
	uint8_t 								spacer2_306;
	uint8_t 								spacer2_307;
	uint8_t 								spacer2_308;
	uint8_t 								spacer2_309;
	uint8_t 								spacer2_310;
	uint8_t 								spacer2_311;
	uint8_t 								spacer2_312;
	uint8_t 								spacer2_313;
	uint8_t 								spacer2_314;
	uint8_t 								spacer2_315;
	uint8_t 								spacer2_316;
	uint8_t 								spacer2_317;
	uint8_t 								spacer2_318;
	uint8_t 								spacer2_319;
	uint8_t 								spacer2_320;
	uint8_t 								spacer2_321;
	uint8_t 								spacer2_322;
	uint8_t 								spacer2_323;
	uint8_t 								spacer2_324;
	uint8_t 								spacer2_325;
	uint8_t 								spacer2_326;
	uint8_t 								spacer2_327;
	uint8_t 								spacer2_328;
	uint8_t 								spacer2_329;
	uint8_t 								spacer2_330;
	uint8_t 								spacer2_331;
	uint8_t 								spacer2_332;
	uint8_t 								spacer2_333;
	uint8_t 								spacer2_334;
	uint8_t 								spacer2_335;
	uint8_t 								spacer2_336;
	uint8_t 								spacer2_337;
	uint8_t 								spacer2_338;
	uint8_t 								spacer2_339;
	uint8_t 								spacer2_340;
	uint8_t 								spacer2_341;
	uint8_t 								spacer2_342;
	uint8_t 								spacer2_343;
	uint8_t 								spacer2_344;
	uint8_t 								spacer2_345;
	uint8_t 								spacer2_346;
	uint8_t 								spacer2_347;
	uint8_t 								spacer2_348;
	uint8_t 								spacer2_349;
	uint8_t 								spacer2_350;
	uint8_t 								spacer2_351;
	uint8_t 								spacer2_352;
	uint8_t 								spacer2_353;
	uint8_t 								spacer2_354;
	uint8_t 								spacer2_355;
	uint8_t 								spacer2_356;
	uint8_t 								spacer2_357;
	uint8_t 								spacer2_358;
	uint8_t 								spacer2_359;
	uint8_t 								spacer2_360;
	uint8_t 								spacer2_361;
	uint8_t 								spacer2_362;
	uint8_t 								spacer2_363;
	uint8_t 								spacer2_364;
	uint8_t 								spacer2_365;
	uint8_t 								spacer2_366;
	uint8_t 								spacer2_367;
	uint8_t 								spacer2_368;
	uint8_t 								spacer2_369;
	uint8_t 								spacer2_370;
	uint8_t 								spacer2_371;
	uint8_t 								spacer2_372;
	uint8_t 								spacer2_373;
	uint8_t 								spacer2_374;
	uint8_t 								spacer2_375;
	uint8_t 								spacer2_376;
	uint8_t 								spacer2_377;
	uint8_t 								spacer2_378;
	uint8_t 								spacer2_379;
	uint8_t 								spacer2_380;
	uint8_t 								spacer2_381;
	uint8_t 								spacer2_382;
	uint8_t 								spacer2_383;
	uint8_t 								spacer2_384;
	uint8_t 								spacer2_385;
	uint8_t 								spacer2_386;    /* 0x0 */
	uint8_t 								spacer2_387;    /* 0x0 */
	uint8_t 								spacer2_388;    /* 0x0 */
	uint8_t 								spacer2_389;    /* 0x0 */
	uint8_t 								spacer2_390;    /* 0x0 */
	uint8_t 								spacer2_391;    /* 0x0 */
	uint8_t 								spacer2_392;    /* 0x0 */
	uint8_t 								spacer2_393;    /* 0x0 */
	uint8_t 								spacer2_394;    /* 0x0 */
	uint8_t 								spacer2_395;    /* 0x0 */
	uint8_t 								spacer2_396;    /* 0x0 */
	uint8_t 								spacer2_397;    /* 0x0 */
	uint8_t 								spacer2_398;    /* 0x0 */
	uint8_t 								spacer2_399;    /* 0x0 */
	uint8_t 								spacer2_400;    /* 0x0 */
	uint8_t 								spacer2_401;    /* 0x0 */
	uint8_t 								spacer2_402;    /* 0x0 */
	uint8_t 								spacer2_403;    /* 0x0 */
	uint8_t 								spacer2_404;    /* 0x0 */
	uint8_t 								spacer2_405;    /* 0x0 */
	uint8_t 								spacer2_406;    /* 0x0 */
	uint8_t 								spacer2_407;    /* 0x0 */
	uint8_t 								spacer2_408;    /* 0x0 */
	uint8_t 								spacer2_409;    /* 0x0 */
	uint8_t 								spacer2_410;    /* 0x0 */
	uint8_t 								spacer2_411;    /* 0x0 */
	uint8_t 								spacer2_412;    /* 0x0 */
	uint8_t 								spacer2_413;    /* 0x0 */
	uint8_t 								spacer2_414;    /* 0x0 */
	uint8_t 								spacer2_415;    /* 0x0 */
	uint8_t 								spacer2_416;    /* 0x0 */
	uint8_t 								spacer2_417;    /* 0x0 */
	uint8_t 								spacer2_418;    /* 0x0 */
	uint8_t 								spacer2_419;    /* 0x0 */
	uint8_t 								spacer2_420;    /* 0x0 */
	uint8_t 								spacer2_421;    /* 0x0 */
	uint8_t 								spacer2_422;    /* 0x0 */
	uint8_t 								spacer2_423;    /* 0x0 */
	uint8_t 								spacer2_424;    /* 0x0 */
	uint8_t 								spacer2_425;    /* 0x0 */
	uint8_t 								spacer2_426;    /* 0x0 */
	uint8_t 								spacer2_427;    /* 0x0 */
	uint8_t 								spacer2_428;    /* 0x0 */
	uint8_t 							cre_AmbientAnimState;   /* 0x0 */
	uint8_t 								spacer2_430;    /* 0x0 */
	uint8_t 								spacer2_431;    /* 0x0 */
	uint8_t 								spacer2_432;    /* 0x0 */
	uint8_t 								spacer2_433;    /* 0x0 */
	uint8_t 								spacer2_434;    /* 0x0 */
	uint8_t 								spacer2_435;    /* 0x0 */
	uint8_t 								spacer2_436;    /* 0x0 */
	uint8_t 								spacer2_437;    /* 0x0 */
	uint8_t 								spacer2_438;    /* 0x0 */
	uint8_t 								spacer2_439;    /* 0x0 */
	uint8_t 								spacer2_440;    /* 0x0 */
	void 								**cre_areaminimaps;    /* 0x048C */
	uint32_t 								*cre_arealist;    /* 0x0490 */
	uint32_t 							cre_areacount;    /* 0x0494 */
	uint32_t 							cre_areaalloc;    /* 0x0498 */
	uint8_t 								spacer2_457;	/* 0x049C */
	uint8_t 								spacer2_458;    /* 0x0 */
	uint8_t 								spacer2_459;    /* 0x0 */
	uint8_t 								spacer2_460;    /* 0x0 */
	uint8_t 								spacer2_461;    /* 0x04A0 */
	uint8_t 								spacer2_462;    /* 0x0 */
	uint8_t 								spacer2_463;    /* 0x0 */
	uint8_t 								spacer2_464;    /* 0x0 */
	uint8_t 								spacer2_465;    /* 0x04A4 */
	uint8_t 								spacer2_466;    /* 0x0 */
	uint8_t 								spacer2_467;    /* 0x0 */
	uint8_t 								spacer2_468;	/* 0x0 */
	uint8_t								cre_mode_detect;					/* 0x04A8 */
	uint8_t								cre_mode_stealth;					/* 0x04A9 */
	uint8_t								cre_mode_defcast;					/* 0x04AA */
	uint8_t								cre_mode_combat;					/* 0x04AB */
	uint8_t								cre_mode_desired;					/* 0x04AC */
	uint8_t									field_4AD;
	uint8_t									field_4AE;
	uint8_t									field_4AF;
	nwn_objid_t							cre_counterspell_target;			/* 0x04B0 */
	uint8_t								cre_initiative_roll;				/* 0x04B4 */
	uint8_t									field_4B5;
	uint8_t									field_4B6;
	uint8_t									field_4B7;
	uint32_t							cre_initiative_expired;				/* 0x04B8 */
    uint32_t                    		cre_combat_state;       			/* 0x04BC */
    uint32_t                    		cre_combat_state_timer; 			/* 0x04C0 */
    uint32_t                    		cre_passive_attack_beh; 			/* 0x04C4 */
    uint32_t                    		cre_has_arms;           			/* 0x04C8 */
    uint32_t                    		cre_has_legs;           			/* 0x04CC */
    uint32_t                    		cre_is_disarmable;      			/* 0x04D0 */
    uint32_t                    		cre_size;               			/* 0x04D4 */
    float                       		cre_pref_attack_dist;   			/* 0x04D8 */
    uint32_t                    		cre_weapon_scale;       			/* 0x04DC */
    nwn_objid_t                 		cre_attack_target;      			/* 0x04E0 */
    nwn_objid_t                 		cre_attempted_target;   			/* 0x04E4 */
    uint32_t								spacer3[317];						/* 0x04E8 */
    uint8_t								cre_vision_type;					/* 0x09DC */
    uint8_t								cre_state;							/* 0x09DD */
	uint8_t									field_9DE;
	uint8_t									field_9DF;
	uint8_t									field_9E0;
	uint8_t									field_9E1;
	uint8_t									field_9E2;
	uint8_t									field_9E3;
	uint8_t									field_9E4;
	uint8_t									field_9E5;
	uint8_t									field_9E6;
	uint8_t									field_9E7;
	uint8_t									field_9E8;
	uint8_t									field_9E9;
	uint8_t									field_9EA;
	uint8_t									field_9EB;
	uint8_t									field_9EC;
	uint8_t									field_9ED;
	uint8_t									field_9EE;
	uint8_t									field_9EF;
	uint32_t								field_9F0;
	uint8_t									field_9F4;
	uint8_t									field_9F5;
	uint8_t									field_9F6;
	uint8_t									field_9F7;
	uint8_t									field_9F8;
	uint8_t									field_9F9;
	uint8_t									field_9FA;
	uint8_t									field_9FB;
	uint8_t									field_9FC;
	uint8_t									field_9FD;
	uint8_t									field_9FE;
	uint8_t									field_9FF;
	uint8_t									field_A00;
	uint8_t									field_A01;
	uint8_t									field_A02;
	uint8_t									field_A03;
	uint8_t									field_A04;
	uint8_t									field_A05;
	uint8_t									field_A06;
	uint8_t									field_A07;
	uint8_t									field_A08;
	uint8_t									field_A09;
	uint8_t									field_A0A;
	uint8_t									field_A0B;
	uint8_t									field_A0C;
	uint8_t									field_A0D;
	uint8_t									field_A0E;
	uint8_t									field_A0F;
	uint8_t									field_A10;
	uint8_t									field_A11;
	uint8_t									field_A12;
	uint8_t									field_A13;
	uint8_t									field_A14;
	uint8_t									field_A15;
	uint8_t									field_A16;
	uint8_t									field_A17;
	float								cre_primary_range;
	uint8_t									field_A1C;
	uint8_t									field_A1D;
	uint8_t									field_A1E;
	uint8_t									field_A1F;
	float								cre_secondary_range;
	uint8_t									field_A24;
	uint8_t									field_A25;
	uint8_t									field_A26;
	uint8_t									field_A27;
	uint8_t									field_A28;
	uint8_t									field_A29;
	uint8_t									field_A2A;
	uint8_t									field_A2B;
	uint8_t									field_A2C;
	uint8_t									field_A2D;
	uint8_t									field_A2E;
	uint8_t									field_A2F;
	void								*cre_perception_list;
	uint8_t									field_A34;
	uint8_t									field_A35;
	uint8_t									field_A36;
	uint8_t									field_A37;
	uint8_t									field_A38;
	uint8_t									field_A39;
	uint8_t									field_A3A;
	uint8_t									field_A3B;
	uint8_t									field_A3C;
	uint8_t									field_A3D;
	uint8_t									field_A3E;
	uint8_t									field_A3F;
	uint8_t									field_A40;
	uint8_t									field_A41;
	uint8_t									field_A42;
	uint8_t									field_A43;
	uint8_t									field_A44;
	uint8_t									field_A45;
	uint8_t									field_A46;
	uint8_t									field_A47;
	uint8_t									field_A48;
	uint8_t									field_A49;
	uint8_t									field_A4A;
	uint8_t									field_A4B;
	uint8_t									field_A4C;
	uint8_t									field_A4D;
	uint8_t									field_A4E;
	uint8_t									field_A4F;
	uint8_t									field_A50;
	uint8_t									field_A51;
	uint8_t									field_A52;
	uint8_t									field_A53;
	uint8_t									field_A54;
	uint8_t									field_A55;
	uint8_t									field_A56;
	uint8_t									field_A57;
	uint8_t									field_A58;
	uint8_t									field_A59;
	uint8_t									field_A5A;
	uint8_t									field_A5B;
	uint8_t									field_A5C;
	uint8_t									field_A5D;
	uint8_t									field_A5E;
	uint8_t									field_A5F;
	uint8_t									field_A60;
	uint8_t									field_A61;
	uint8_t									field_A62;
	uint8_t									field_A63;
	uint8_t									field_A64;
	uint8_t									field_A65;
	uint8_t									field_A66;
	uint8_t									field_A67;
	uint8_t									field_A68;
	uint8_t									field_A69;
	uint8_t									field_A6A;
	uint8_t									field_A6B;
	uint8_t									field_A6C;
	uint8_t									field_A6D;
	uint8_t									field_A6E;
	uint8_t									field_A6F;
	uint8_t									field_A70;
	uint8_t									field_A71;
	uint8_t									field_A72;
	uint8_t									field_A73;
	uint8_t									field_A74;
	uint8_t									field_A75;
	uint8_t									field_A76;
	uint8_t									field_A77;
	uint8_t									field_A78;
	uint8_t									field_A79;
	uint8_t									field_A7A;
	uint8_t									field_A7B;
	uint32_t 							SitObject;
	uint8_t									field_A80;
	uint8_t									field_A81;
	uint8_t									field_A82;
	uint8_t									field_A83;
	uint8_t									field_A84;
	uint8_t									field_A85;
	uint8_t									field_A86;
	uint8_t									field_A87;
	uint8_t									field_A88;
	uint8_t									field_A89;
	uint8_t									field_A8A;
	uint8_t									field_A8B;
	uint8_t									field_A8C;
	uint8_t									field_A8D;
	uint8_t									field_A8E;
	uint8_t									field_A8F;
	uint8_t									field_A90;
	uint8_t									field_A91;
	uint8_t									field_A92;
	uint8_t									field_A93;
	uint8_t									field_A94;
	uint8_t									field_A95;
	uint8_t									field_A96;
	uint8_t									field_A97;
	uint8_t									field_A98;
	uint8_t									field_A99;
	uint8_t									field_A9A;
	uint8_t									field_A9B;
	uint8_t									field_A9C;
	uint8_t									field_A9D;
	uint8_t									field_A9E;
	uint8_t									field_A9F;
	uint8_t									field_AA0;
	uint8_t									field_AA1;
	uint8_t									field_AA2;
	uint8_t									field_AA3;
	uint8_t									field_AA4;
	uint8_t									field_AA5;
	uint8_t									field_AA6;
	uint8_t									field_AA7;
	uint8_t									field_AA8;
	uint8_t									field_AA9;
	uint8_t									field_AAA;
	uint8_t									field_AAB;
	uint8_t									field_AAC;
	uint8_t									field_AAD;
	uint8_t									field_AAE;
	uint8_t									field_AAF;
	uint8_t									field_AB0;
	uint8_t									field_AB1;
	uint8_t									field_AB2;
	uint8_t									field_AB3;
	uint8_t									field_AB4;
	uint8_t									field_AB5;
	uint8_t									field_AB6;
	uint8_t									field_AB7;
	uint8_t									field_AB8;
	uint8_t									field_AB9;
	uint8_t									field_ABA;
	uint8_t									field_ABB;
	uint8_t									field_ABC;
	uint8_t									field_ABD;
	uint8_t									field_ABE;
	uint8_t									field_ABF;
	uint8_t									field_AC0;
	uint8_t									field_AC1;
	uint8_t									field_AC2;
	uint8_t									field_AC3;
	uint8_t									field_AC4;
	uint8_t									field_AC5;
	uint8_t									field_AC6;
	uint8_t									field_AC7;
	CNWSCombatRound						*cre_combat_round;					/* 0x0AC8 */
	uint32_t								field_ACC;
	uint32_t								field_AD0;
    uint32_t                    		cre_gold;               			/* 0x0AD4 */
    uint32_t                    		cre_is_pc;              			/* 0x0AD8 */
    uint16_t                    		cre_soundset;           			/* 0x0ADC */
    uint16_t                    			field_AE2;              			/* 0x0ADE */
    uint32_t                    		cre_footstep;           			/* 0x0AE0 */
    uint8_t                     		cre_bodybag;            			/* 0x0AE4 */
	uint8_t 								field_AE5;
	uint8_t 								field_AE6;
	uint8_t 								field_AE7;
	uint8_t 								field_AE8;
	uint8_t 								field_AE9;
	uint8_t 								field_AEA;
	uint8_t 								field_AEB;
	uint8_t 								field_AEC;
	uint8_t 								field_AED;
	uint8_t 								field_AEE;
	uint8_t 								field_AEF;
	uint8_t 								field_AF0;
	uint8_t 								field_AF1;
	uint8_t 								field_AF2;
	uint8_t 								field_AF3;
	uint8_t 							cre_IsImmortal;
	uint8_t 								field_AF5;
	uint8_t 								field_AF6;
	uint8_t 								field_AF7;
	uint8_t 							cre_no_permadeath;
	uint8_t 								field_AF9;
	uint8_t 								field_AFA;
	uint8_t 								field_AFB;
	CExoString 							cre_DisplayName;
	uint8_t 								field_B04;
	uint8_t 								field_B05;
	uint8_t 								field_B06;
	uint8_t 								field_B07;
	uint8_t 								field_B08;
	uint8_t 								field_B09;
	uint8_t 								field_B0A;
	uint8_t 								field_B0B;
	uint8_t 								field_B0C;
	uint8_t 								field_B0D;
	uint8_t 								field_B0E;
	uint8_t 								field_B0F;
	uint8_t 								field_B10;
	uint8_t 								field_B11;
	uint8_t 								field_B12;
	uint8_t 								field_B13;
	uint8_t 								field_B14;
	uint8_t 								field_B15;
	uint8_t 								field_B16;
	uint8_t 								field_B17;
	uint8_t 								field_B18;
	uint8_t 								field_B19;
	uint8_t 								field_B1A;
	uint8_t 								field_B1B;
	float 								cre_movement_rate;
	uint8_t 								field_B20;
	uint8_t 								field_B21;
	uint8_t 								field_B22;
	uint8_t 								field_B23;
	uint8_t 								field_B24;
	uint8_t 								field_B25;
	uint8_t 								field_B26;
	uint8_t 								field_B27;
	uint8_t 								field_B28;
	uint8_t 								field_B29;
	uint8_t 								field_B2A;
	uint8_t 								field_B2B;
	uint8_t 								field_B2C;
	uint8_t 								field_B2D;
	uint8_t 								field_B2E;
	uint8_t 								field_B2F;
	uint32_t 							cre_MasterID;
	uint8_t 								field_B34;
	uint8_t 								field_B35;
	uint8_t 								field_B36;
	uint8_t 								field_B37;
	uint16_t 							cre_associate_type;
	uint8_t 								field_B3A;
	uint8_t 								field_B3B;
	uint8_t 								field_B3C;
	uint8_t 								field_B3D;
	uint8_t 								field_B3E;
	uint8_t 								field_B3F;
	uint8_t 								field_B40;
	uint8_t 								field_B41;
	uint8_t 								field_B42;
	uint8_t 								field_B43;
	uint8_t 								field_B44;
	uint8_t 								field_B45;
	uint8_t 								field_B46;
	uint8_t 								field_B47;
	uint8_t 								field_B48;
	uint8_t 								field_B49;
	uint8_t 								field_B4A;
	uint8_t 								field_B4B;
	uint8_t 								field_B4C;
	uint8_t 								field_B4D;
	uint8_t 								field_B4E;
	uint8_t 								field_B4F;
	uint8_t 								field_B50;
	uint8_t 								field_B51;
	uint8_t 								field_B52;
	uint8_t 								field_B53;
	uint8_t 								field_B54;
	uint8_t 								field_B55;
	uint8_t 								field_B56;
	uint8_t 								field_B57;
	uint8_t 								field_B58;
	uint8_t 								field_B59;
	uint8_t 								field_B5A;
	uint8_t 								field_B5B;
	uint32_t							cre_default_reputation;
	uint8_t 								field_B60;
	uint8_t 								field_B61;
	uint8_t 								field_B62;
	uint8_t 								field_B63;
	uint32_t 							EncounterObject;
	uint8_t 								field_B68;
	uint8_t 								field_B69;
	uint8_t 								field_B6A;
	uint8_t 								field_B6B;
    CNWSInventory						*cre_equipment;						/* 0x0B6C */
    CItemRepository						*cre_inventory;						/* 0x0B70 */
    uint16_t							cre_inventory_index;				/* 0x0B74 */
    uint16_t							cre_container_index;				/* 0x0B76 */
    nwn_objid_t							cre_current_container;				/* 0x0B78 */
    uint32_t                    		cre_equipped_weight;    			/* 0x0B7C */
    uint32_t                    		cre_calc_npc_weight;    			/* 0x0B80 */
    uint32_t                    		cre_encumbrance_state;  			/* 0x0B84 */
    uint32_t                    		cre_last_pickup_failed; 			/* 0x0B88 */
	uint32_t							cre_total_weight;					/* 0x0B8C */
  	uint32_t 							cre_pm_itemlist;
  	uint8_t 							spacer5_005;
  	uint8_t 							spacer5_006;
  	uint8_t 							spacer5_007;
  	uint8_t 							spacer5_008;
  	uint8_t 							spacer5_009;
  	uint8_t 							spacer5_010;
  	uint8_t 							spacer5_011;
  	uint8_t 							spacer5_012;
  	uint8_t 							spacer5_013;
  	uint8_t 							spacer5_014;
  	uint8_t 							spacer5_015;
  	uint8_t 							spacer5_016;
  	uint8_t 							spacer5_017;
  	uint8_t 							spacer5_018;
  	uint8_t 							spacer5_019;
  	uint8_t 							spacer5_020;
  	uint8_t 							spacer5_021;
  	uint8_t 							spacer5_022;
  	uint8_t 							spacer5_023;
  	uint8_t 							spacer5_024;
  	uint8_t 							spacer5_025;
  	uint8_t 							spacer5_026;
  	uint8_t 							spacer5_027;
  	uint8_t 							spacer5_028;
  	uint8_t 							spacer5_029;
  	uint8_t 							spacer5_030;
  	uint8_t 							spacer5_031;
  	uint8_t 							spacer5_032;
  	uint8_t 							spacer5_033;
  	uint8_t 							spacer5_034;
  	uint8_t 							spacer5_035;
  	uint8_t 							spacer5_036;
  	uint8_t 							spacer5_037;
  	uint8_t 							spacer5_038;
  	uint8_t 							spacer5_039;
  	uint8_t 							spacer5_040;
  	uint8_t 							spacer5_041;
  	uint8_t 							spacer5_042;
  	uint8_t 							spacer5_043;
  	uint8_t 							spacer5_044;
  	uint8_t 							spacer5_045;
  	uint8_t 							spacer5_046;
  	uint8_t 							spacer5_047;
  	uint8_t 							spacer5_048;
  	uint8_t 							spacer5_049;
  	uint8_t 							spacer5_050;
  	uint8_t 							spacer5_051;
  	uint8_t 							spacer5_052;
  	uint8_t 							spacer5_053;
  	uint8_t 							spacer5_054;
  	uint8_t 							spacer5_055;
  	uint8_t 							spacer5_056;
  	uint8_t 							spacer5_057;
  	uint8_t 							spacer5_058;
  	uint8_t 							spacer5_059;
  	uint8_t 							spacer5_060;
  	uint8_t 							spacer5_061;
  	uint8_t 							spacer5_062;
  	uint8_t 							spacer5_063;
  	uint8_t 							spacer5_064;
  	uint8_t 							spacer5_065;
  	uint8_t 							spacer5_066;
  	uint8_t 							spacer5_067;
  	uint8_t 							spacer5_068;
  	uint8_t 							spacer5_069;
  	uint8_t 							spacer5_070;
  	uint8_t 							spacer5_071;
  	uint8_t 							spacer5_072;
  	uint8_t 						cre_pm_portrait;
  	uint8_t 							spacer5_074;
  	uint8_t 							spacer5_075;
  	uint8_t 							spacer5_076;
  	uint8_t 							spacer5_077;
  	uint8_t 							spacer5_078;
  	uint8_t 							spacer5_079;
  	uint8_t 							spacer5_080;
  	uint8_t 							spacer5_081;
  	uint8_t 							spacer5_082;
  	uint8_t 							spacer5_083;
  	uint8_t 							spacer5_084;
  	uint8_t 							spacer5_085;
  	uint8_t 							spacer5_086;
  	uint8_t 							spacer5_087;
  	uint8_t 							spacer5_088;
  	uint16_t 						cre_pm_PortraitId;
  	uint8_t 							spacer5_091;
  	uint8_t 							spacer5_092;
  	uint32_t 						cre_pm_IsPolymorphed;
  	uint16_t 						cre_pm_Appearance;
  	uint8_t 						cre_pm_PrePolySTR;
  	uint8_t 						cre_pm_PrePolyCON;
  	uint8_t 						cre_pm_PrePolyDEX;
  	uint8_t 							spacer5_102;
  	uint16_t 						cre_pm_RacialType;
  	uint16_t 						cre_pm_PrePolyHP;
  	uint8_t 							spacer5_107;
  	uint8_t 							spacer5_108;
  	uint8_t 							spacer5_109;
  	uint8_t 							spacer5_110;
  	uint8_t 							spacer5_111;
  	uint8_t 							spacer5_112;
  	uint8_t 							spacer5_113;
  	uint8_t 							spacer5_114;
  	uint8_t 							spacer5_115;
  	uint8_t 							spacer5_116;
  	uint8_t 							spacer5_117;
  	uint8_t 							spacer5_118;
  	uint8_t 							spacer5_119;
  	uint8_t 							spacer5_120;
  	uint32_t 						cre_pm_ACBonus_lo;
  	uint32_t 						cre_pm_ACBonus_hi;
  	uint32_t 						cre_pm_HPBonus_lo;
  	uint32_t 						cre_pm_HPBonus_hi;
  	uint8_t 						cre_pm_HasPrePolyCP;
  	uint8_t 							spacer5_138;
  	uint8_t 							spacer5_139;
  	uint8_t 							spacer5_140;
  	uint8_t 							spacer5_141;
  	uint8_t 							spacer5_142;
  	uint8_t 							spacer5_143;
  	uint8_t 							spacer5_144;
  	uint8_t 							spacer5_145;
  	uint8_t 							spacer5_146;
  	uint8_t 							spacer5_147;
  	uint8_t 							spacer5_148;
  	uint8_t 							spacer5_149;
  	uint8_t 							spacer5_150;
  	uint8_t 							spacer5_151;
  	uint8_t 							spacer5_152;
  	uint8_t 							spacer5_153;
  	uint8_t 							spacer5_154;
  	uint8_t 							spacer5_155;
  	uint8_t 							spacer5_156;
  	uint8_t 							spacer5_157;
  	uint8_t 							spacer5_158;
  	uint8_t 							spacer5_159;
  	uint8_t 							spacer5_160;
  	uint8_t 							spacer5_161;
  	uint8_t 							spacer5_162;
  	uint8_t 							spacer5_163;
  	uint8_t 							spacer5_164;
  	uint8_t 							spacer5_165;
  	uint8_t 							spacer5_166;
  	uint8_t 							spacer5_167;
  	uint8_t 							spacer5_168;
  	uint32_t 						cre_appearance;
  	uint8_t 							spacer01;
  	uint8_t 							spacer02;
  	uint8_t 							spacer03;
  	uint8_t 							spacer04;
  	uint8_t 							spacer05;
  	uint8_t 							spacer06;
  	uint8_t 							spacer07;
  	uint8_t 							spacer08;
  	uint8_t 							spacer09;
  	uint8_t 							spacer10;
  	uint8_t 							spacer11;
  	uint8_t 							spacer12;
  	uint8_t 							spacer13;
  	uint8_t 							spacer14;
  	uint8_t 							spacer15;
  	uint8_t 							spacer16;
  	uint8_t 							spacer17;
  	uint8_t 							spacer18;
  	uint8_t 							spacer19;
  	uint8_t 							spacer20;
  	uint8_t 							spacer21;
  	uint8_t 							spacer22;
  	uint8_t 							spacer23;
  	uint8_t 							spacer24;
  	uint8_t 							spacer25;
  	uint8_t 							spacer26;
  	uint8_t 							spacer27;
  	uint8_t 							spacer28;
  	uint8_t 							spacer29;
  	uint8_t 							spacer30;
  	uint8_t 							spacer31;
  	uint8_t 							spacer32;
  	uint8_t 							spacer33;
  	uint8_t 							spacer34;
  	uint8_t 							spacer35;
  	uint8_t 							spacer36;
  	uint8_t 							spacer37;
  	uint8_t 							spacer38;
  	uint8_t 							spacer39;
  	uint8_t 							spacer40;
	CNWSCreatureStats 				*cre_stats;			/* 0x0C64 */
};
#endif /* _NX_NWN_STRUCT_CNWSCREATURE_ */
/* vim: set sw=4: */