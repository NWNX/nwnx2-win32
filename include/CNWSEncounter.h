#ifndef _H_CNWSENCOUNTER_H
#define _H_CNWSENCOUNTER_H

struct CNWSEncounter_s
{
  CNWSObject obj;
  unsigned __int8 field_1C0;
  unsigned __int8 field_1C1;
  unsigned __int8 field_1C2;
  unsigned __int8 field_1C3;
  unsigned __int32 Faction;
  unsigned __int8 LocalizedName;
  unsigned __int8 field_1C9;
  unsigned __int8 field_1CA;
  unsigned __int8 field_1CB;
  unsigned __int8 field_1CC;
  unsigned __int8 field_1CD;
  unsigned __int8 field_1CE;
  unsigned __int8 field_1CF;
  unsigned __int8 Active;
  unsigned __int8 field_1D1;
  unsigned __int8 field_1D2;
  unsigned __int8 field_1D3;
  unsigned __int8 Reset;
  unsigned __int8 field_1D5;
  unsigned __int8 field_1D6;
  unsigned __int8 field_1D7;
  int ResetTime;
  int SpawnOption;
  unsigned __int32 Difficulty;
  unsigned __int32 DifficultyIndex;
  unsigned __int32 RecCreatures;
  int MaxCreatures;
  int NumberSpawned;
  unsigned __int32 HeartbeatDay;
  unsigned __int32 HeartbeatTime;
  unsigned __int32 LastSpawnDay;
  unsigned __int32 LastSpawnTime;
  unsigned __int8 Started;
  unsigned __int8 field_205;
  unsigned __int8 field_206;
  unsigned __int8 field_207;
  unsigned __int8 Exhausted;
  unsigned __int8 field_209;
  unsigned __int8 field_20A;
  unsigned __int8 field_20B;
  int AreaListMaxSize;
  unsigned __int8 field_210;
  unsigned __int8 field_211;
  unsigned __int8 field_212;
  unsigned __int8 field_213;
  unsigned __int8 field_214;
  unsigned __int8 field_215;
  unsigned __int8 field_216;
  unsigned __int8 field_217;
  unsigned __int8 field_218;
  unsigned __int8 field_219;
  unsigned __int8 field_21A;
  unsigned __int8 field_21B;
  unsigned __int8 field_21C;
  unsigned __int8 field_21D;
  unsigned __int8 field_21E;
  unsigned __int8 field_21F;
  unsigned __int8 field_220;
  unsigned __int8 field_221;
  unsigned __int8 field_222;
  unsigned __int8 field_223;
  unsigned __int8 field_224;
  unsigned __int8 field_225;
  unsigned __int8 field_226;
  unsigned __int8 field_227;
  unsigned __int8 field_228;
  unsigned __int8 field_229;
  unsigned __int8 field_22A;
  unsigned __int8 field_22B;
  unsigned __int8 field_22C;
  unsigned __int8 field_22D;
  unsigned __int8 field_22E;
  unsigned __int8 field_22F;
  unsigned __int8 field_230;
  unsigned __int8 field_231;
  unsigned __int8 field_232;
  unsigned __int8 field_233;
  unsigned __int8 field_234;
  unsigned __int8 field_235;
  unsigned __int8 field_236;
  unsigned __int8 field_237;
  unsigned __int8 field_238;
  unsigned __int8 field_239;
  unsigned __int8 field_23A;
  unsigned __int8 field_23B;
  unsigned __int8 field_23C;
  unsigned __int8 field_23D;
  unsigned __int8 field_23E;
  unsigned __int8 field_23F;
  unsigned __int8 field_240;
  unsigned __int8 field_241;
  unsigned __int8 field_242;
  unsigned __int8 field_243;
  unsigned __int8 field_244;
  unsigned __int8 field_245;
  unsigned __int8 field_246;
  unsigned __int8 field_247;
  unsigned __int8 field_248;
  unsigned __int8 field_249;
  unsigned __int8 field_24A;
  unsigned __int8 field_24B;
  unsigned __int8 field_24C;
  unsigned __int8 field_24D;
  unsigned __int8 field_24E;
  unsigned __int8 field_24F;
  int Respawns;
  int CurrentSpawns;
  unsigned __int8 field_258;
  unsigned __int8 field_259;
  unsigned __int8 field_25A;
  unsigned __int8 field_25B;
  unsigned __int8 field_25C;
  unsigned __int8 field_25D;
  unsigned __int8 field_25E;
  unsigned __int8 field_25F;
  float *AreaPoints;
  unsigned __int8 field_264;
  unsigned __int8 field_265;
  unsigned __int8 field_266;
  unsigned __int8 field_267;
  float SpawnPoolActive;
  unsigned __int32 LastEntered;
  unsigned __int32 LastLeft;
  CExoString OnEntered;
  CExoString OnExit;
  CExoString OnHeartbeat;
  CExoString OnExhausted;
  CExoString OnUserDefined;
  unsigned __int8 field_29C;
  unsigned __int8 field_29D;
  unsigned __int8 field_29E;
  unsigned __int8 field_29F;
  int CustomScriptId;
  unsigned __int8 PlayerOnly;
  unsigned __int8 field_2A5;
  unsigned __int8 field_2A6;
  unsigned __int8 field_2A7;

	void SetScriptName(int iScript, CExoString ScriptName);
};

#endif