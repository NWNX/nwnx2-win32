#include "nwnx_funcs_effst"

const int LV_TYPE_INT = 1;
const int LV_TYPE_FLT = 2;
const int LV_TYPE_STR = 3;
const int LV_TYPE_OBJ = 4;
const int LV_TYPE_LOC = 5;

const int EVENT_CREATURE_HEARTBEAT		=0;
const int EVENT_CREATURE_PERCEPTION		=1;
const int EVENT_CREATURE_SPELLCASTAT	=2;
const int EVENT_CREATURE_ATTACKED		=3;
const int EVENT_CREATURE_DAMAGED		=4;
const int EVENT_CREATURE_DISTURBED		=5;
const int EVENT_CREATURE_ENDCOMBAT		=6;
const int EVENT_CREATURE_DIALOG			=7;
const int EVENT_CREATURE_SPAWN			=8;
const int EVENT_CREATURE_RESTED			=9;
const int EVENT_CREATURE_DEATH			=10;
const int EVENT_CREATURE_USERDEFINDED	=11;
const int EVENT_CREATURE_BLOCKED		=12;
                                         
const int EVENT_AREA_HEARTBEAT			=0;
const int EVENT_AREA_USERDEFINED		=1;
const int EVENT_AREA_ENTER				=2;
const int EVENT_AREA_EXIT				=3;
                                         
const int EVENT_PLACEABLE_CLOSED		=0;
const int EVENT_PLACEABLE_DAMAGED		=1;
const int EVENT_PLACEABLE_DEATH			=2;
const int EVENT_PLACEABLE_DISARM		=3;
const int EVENT_PLACEABLE_HEARTBEAT		=4;
const int EVENT_PLACEABLE_DISTURBED		=5;
const int EVENT_PLACEABLE_LOCK			=6;
const int EVENT_PLACEABLE_ATTACKED		=7;
const int EVENT_PLACEABLE_OPEN			=8;
const int EVENT_PLACEABLE_SPELLCASTAT	=9;
const int EVENT_PLACEABLE_TRAPTRIGGERED	=10;
const int EVENT_PLACEABLE_UNLOCK		=11;
const int EVENT_PLACEABLE_USED			=12;
const int EVENT_PLACEABLE_USERDEFINED	=13;
const int EVENT_PLACEABLE_DIALOG		=14;
const int EVENT_PLACEABLE_CLICK			=15;
                                         
const int EVENT_AOE_HEARTBEAT			=0;
const int EVENT_AOE_USERDEFINED			=1;
const int EVENT_AOE_ENTER				=2;
const int EVENT_AOE_EXIT				=3;
                                         
const int EVENT_DOOR_OPEN				=0;
const int EVENT_DOOR_CLOSED				=1;
const int EVENT_DOOR_DAMAGED			=2;
const int EVENT_DOOR_DEATH				=3;
const int EVENT_DOOR_DISARM				=4;
const int EVENT_DOOR_HEARTBEAT			=5;
const int EVENT_DOOR_LOCK				=6;
const int EVENT_DOOR_ATTACKED			=7;
const int EVENT_DOOR_SPELLCASTAT		=8;
const int EVENT_DOOR_TRAPTRIGGERED		=9;
const int EVENT_DOOR_UNLOCK				=10;
const int EVENT_DOOR_USERDEFINED		=11;
const int EVENT_DOOR_CLICK				=12;
const int EVENT_DOOR_DIALOG				=13;
const int EVENT_DOOR_FAILTOOPEN			=14;
                                         
const int EVENT_ENCOUNTER_ENTERED       =0;
const int EVENT_ENCOUNTER_EXIT          =1;
const int EVENT_ENCOUNTER_HEARTBEAT     =2;
const int EVENT_ENCOUNTER_EXHAUSTED     =3;
const int EVENT_ENCOUNTER_USERDEFINED   =4;
                                         
const int EVENT_MODULE_HEARTBEAT		=0;
const int EVENT_MODULE_USRDEFINED		=1;
const int EVENT_MODULE_MODLOAD			=2;
const int EVENT_MODULE_MODSTART			=3;
const int EVENT_MODULE_CLIENTENTR		=4;
const int EVENT_MODULE_CLIENTLEAV		=5;
const int EVENT_MODULE_ACTVTITEM		=6;
const int EVENT_MODULE_ACQUIRITEM		=7;
const int EVENT_MODULE_UNAQREITEM		=8;
const int EVENT_MODULE_PLRDEATH			=9;
const int EVENT_MODULE_PLRDYING			=10;
const int EVENT_MODULE_SPAWNBTNDN		=11;
const int EVENT_MODULE_PLRREST			=12;
const int EVENT_MODULE_PLRLVLUP			=13;
const int EVENT_MODULE_CUTSNABORT		=14;
const int EVENT_MODULE_PLREQITM			=15;
const int EVENT_MODULE_PLRUNEQITM		=16;
const int EVENT_MODULE_PLRCHAT			=17;
                                         
const int EVENT_STORE_OPENSTORE			=0;
const int EVENT_STORE_CLOSESTORE		=1;
                                         
const int EVENT_TRIGGER_HEARTBEAT		=0;
const int EVENT_TRIGGER_ENTER		    =1;
const int EVENT_TRIGGER_EXIT		    =2;
const int EVENT_TRIGGER_USERDEFINED		=3;
const int EVENT_TRIGGER_TRAPTRIGGERED	=4;
const int EVENT_TRIGGER_DISARM			=5;
const int EVENT_TRIGGER_CLICK			=6;


const int ITEM_VALUE_IDENTIFIED = 1;
const int ITEM_VALUE_UNIDENTIFIED = 2;
const int ITEM_VALUE_ADDITIONAL = 3;

const int QUICKBAR_TYPE_INVALID							=	0;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_ITEM							=	1;	// set/getquickslot: no
const int QUICKBAR_TYPE_SPELL							=	2;	// set/getquickslot: yes; Param#: 4; see struct quickslot_s;
const int QUICKBAR_TYPE_PARRY							=	3;	// set/getquickslot: yes; Param#: 1; iParam1 = 10
const int QUICKBAR_TYPE_FEAT							=	4;	// set/getquickslot: yes; Param#: 1; iParam1 = Feat id
const int QUICKBAR_TYPE_TALKTO							=	6;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_ATTACK							=	7;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_EMOTE							=	8;	// set/getquickslot: yes; Param#: 1; iParam1 = emote id
const int QUICKBAR_TYPE_MODE							=	10;	// set/getquickslot: yes; Param#: 1; iParam1 = mode id
const int QUICKBAR_TYPE_DM_CREATECREATURE				=	11;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_CREATEITEM					=	12;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_CREATEENCOUNTER				=	13;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_CREATEWAYPOINT				=	14;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_CREATETRIGGER				=	15;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_CREATEPORTAL					=	16;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_CREATEPLACEABLE				=	17;	// set/getquickslot: no
const int QUICKBAR_TYPE_MACRO							=	18;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_TOGGLEINVULNERABLE			=	19;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_FORCEREST					=	20;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_GOTO							=	21;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_HEAL							=	22;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_KILL							=	23;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_TAKECONTROL					=	24;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_TAKECONTROLFULLPOWERS		=	25;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_GIVEGOLD						=	27;	// set/getquickslot: yes; Param#: 1; iParam1 = gold amount
const int QUICKBAR_TYPE_DM_TAKEGOLD						=	28;	// set/getquickslot: yes; Param#: 1; iParam1 = NEGATIVE gold amount
const int QUICKBAR_TYPE_DM_GIVEITEM						=	29;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_TAKEITEM						=	30;	// set/getquickslot: no
const int QUICKBAR_TYPE_DM_GIVEXP						=	31;	// set/getquickslot: yes; Param#: 1; iParam1 = xp amount
const int QUICKBAR_TYPE_DM_TAKEXP						=	32;	// set/getquickslot: yes; Param#: 1; iParam1 = NEGATIVE xp amount
const int QUICKBAR_TYPE_DM_GIVELEVEL					=	33;	// set/getquickslot: yes; Param#: 1; iParam1 = number of levels
const int QUICKBAR_TYPE_DM_TAKELEVEL					=	34;	// set/getquickslot: yes; Param#: 1; iParam1 = NEGATIVE number of levels
const int QUICKBAR_TYPE_DM_LIMBO						=	35;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_DM_TOGGLEAI						=	36;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_POSSESSFAMILIAR					=	38;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_EXAMINE							=	40;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_BARTER							=	41;	// set/getquickslot: yes; Param#: 0
const int QUICKBAR_TYPE_ASSOCIATECOMMAND				=	42;	// set/getquickslot: yes; Param#: 1; iParam1 = command id
const int QUICKBAR_TYPE_CANCELPOLYMORPH					=	43;	// ??
const int QUICKBAR_TYPE_SPELLLIKEABILITY				=	44;	// set/getquickslot: yes; Param#: 1; basically the same as spell
const int QUICKBAR_TYPE_DM_SHIFTALIGNMENTGOOD			=	45;	// set/getquickslot: yes; Param#: 1; iParam1 = amount to shift towards allignment
const int QUICKBAR_TYPE_DM_SHIFTALIGNMENTEVIL			=	46;	// set/getquickslot: yes; Param#: 1; iParam1 = amount to shift towards allignment
const int QUICKBAR_TYPE_DM_SHIFTALIGNMENTLAWFUL			=	47;	// set/getquickslot: yes; Param#: 1; iParam1 = amount to shift towards allignment
const int QUICKBAR_TYPE_DM_SHIFTALIGNMENTCHAOTIC		=	48;	// set/getquickslot: yes; Param#: 1; iParam1 = amount to shift towards allignment

const int TIMINGBAR_LABEL_FLAGTRAP = 1;
const int TIMINGBAR_LABEL_RECOVERTRAP = 2;
const int TIMINGBAR_LABEL_DISARMTRAP = 3;
const int TIMINGBAR_LABEL_EXAMINETRAP = 4;
const int TIMINGBAR_LABEL_SETTRAP = 5;
const int TIMINGBAR_LABEL_REST = 6;
const int TIMINGBAR_LABEL_UNLOCK = 7;
const int TIMINGBAR_LABEL_LOCK = 8;
const int TIMINGBAR_LABEL_NONE = 9;

const int REGENERATION_ALL = 1;
const int REGENERATION_ITEM = 2;
const int REGENERATION_EFFECT = 3;

struct localvar_s {
	int iType;
	string sName;
	object obj;
	int nPos;
	string sLabel;
	string sCommand;
};

struct itemproperty_s {
	int Type;
	int SubType;
	int Chance;
	int CostTable;
	int CostTablevalue;
	int Param1;
	int Param1Value;
};

struct MemorizedSpellSlot {
    int id;
    int ready, meta, domain;
};

struct levelstats_s {
	int iClass;
	int iHP;
	int iSkillPoints;
	int iAbility;
};

struct quickslot_s {
	int iType;			// see QUICKBAR_TYPE_* section above
	int iClass;			// only used with QUICKBAR_TYPE_SPELL. Is the class position (1-3), not class type! which will cast the spell
	int iParam1;		// see QUICKBAR_TYPE_* section above
	int iMetaMagic;		// only used with QUICKBAR_TYPE_SPELL. Values are the same as defined in nwscript for METAMAGIC_
						// This is also used for Cleric Domain spells in which case iMetamagic is ored with 512.
	// The following 2 strings are used with Macros (iType = 18) and DM Creator objects (iType = 11-17)
	string sS1;	//the label of the quickslot for Macros and DM Creator objects
	string sS2; //for Macros this is the command, for DM Creator objects it's the ResRef of the object to be spawned
};

// Returns the object given by soID 
// soID is a hex string, e.g.: 7FFFFFEF. It is not necessary to use leading zeros: EF = 000000EF;
object NWNXFuncs_StringToObject(string soID);

// Returns the total number of areas in the module;
int  NWNXFuncs_GetAreaCount();

// returns the area in the modules area list given by iIndex
// iIndex is zero based
object NWNXFuncs_GetAreaByPosition(int iIndex);

// Returns the first area of the module.
// Use with NWNXFuncs_GetNextArea to loop through all areas
object NWNXFuncs_GetFirstArea();

// Returns the first area of the module.
// Use with NWNXFuncs_GetFirstArea to loop through all areas
// As long as GetFirstArea isn't called again the area index is preserved,
// so it is possible to use this with DelayCommand calls to get around TMI errors
object NWNXFuncs_GetNextArea();

// Returns the total number of Local Variables set on oObject
int  NWNXFuncs_GetLocalVariableCount(object oObject);

// returns the type and name (as localvar_s struct) of the local variable at position iIndex
// iIndex is zero based
struct localvar_s NWNXFuncs_GetLocalVarByPosition(object oObject, int iVarPos);

// Returns the type and name (as localvar_s struct) of the first local variable on oObject
// Use with NWNXFuncs_GetNextLocalVar to loop through all local variables on an object
struct localvar_s NWNXFuncs_GetFirstLocalVariable(object oObject);

// Returns the type and name (as localvar_s struct) of the next local variable on oObject
// Use with NWNXFuncs_GetFirstLocalVar to loop through all local variables on an object
// As long as GetFirstLocalVar isn't called again the index of the variable is preserved, 
// so it is possble to use this with DelayCommand calls to get around possible TMI errors
struct localvar_s NWNXFuncs_GetNextLocalVariable(struct localvar_s lv);


// Checks if oObject has a local variable with the name sVarName
// iVarType specifies the type of local variable to look for (LV_TYPE_*)
// The default (iVarType = 0) disregards type and find the first local variable with the specified name
// The return value is the type of variable (LV_TYPE_*) or zero if no local variable was found
int  NWNXFuncs_GetHasLocalVariable(object oObject, string sVarName, int iVarType = 0);

// changes the SpellID (returned by GetEffectSpellID or GetEffectSpellIDInternal) of the last effect applied 
// on oObject to iSpellID. If the last effect applied used EffectLinkEffects(...) this will affect 
// all the effects linked together.
void NWNXFuncs_SetLastEffectSpellID(object oObject, int iSpellID);

// changes the Creator (returned by GetEffectCreator) of the last effect applied on oObject to oEffectCreator
// if sEffectCreator is specified as an 8 character hex string (e.g.: from ObjectToString) it is used instead of oEffectCreator
// If the last effect applied used EffectLinkEffects(...) this will affect all the effects linked together.
void NWNXFuncs_SetLastEffectCreator(object oObject, object oEffectCreator, string sEffectCreator = "");

// dumps some information about all the effects applied to oObject to the log file
void NWNXFuncs_DumpEffects(object oObject);

// dumps all local variables of an object to the log file
void NWNXFuncs_DumpLocals(object oObject);

// Sets the gold pieces of oObject to iGold.
// No notification is given to a player whose gold is changed.
void NWNXFuncs_SetGold(object oCreature, int iGold);

// Sets a base ability score iAbility (ABILITY_STRENGTH, ABILITY_DEXTERITY, etc) to iValue
// The range of iValue is 3 to 255
// bAdjustCurrentHitPoints is only used when Constitution is set: if false a potential increase in hitpoints
// will only affect oCreature's maximum hit points. The missing hit points can be regained the normal way: resting,
// healing, regeneration, etc.
void NWNXFuncs_SetAbilityScore(object oCreature, int iAbility, int iValue, int bAdjustCurrentHitPoints = 1);

// Changes a base ability score iAbility (ABILITY_STRENGTH, ABILITY_DEXTERITY, etc) by iValue
void NWNXFuncs_ModAbilityScore(object oCreature, int iAbility, int iValue, int bAdjustCurrentHitPoints = 1);

// Adds a feat to oObject's general featlist
// If iLevel is greater than 0 the feat is also added to the featlist for that level
void NWNXFuncs_AddFeat(object oCreature, int iFeat, int iLevel=0);

// Sets the amount of xp oObject currently has to iXP
// No notification is given to a player whose xp is changed
// This will not delevel a PC - they will keep their current levels - until they gain or lose xp in a "regular" way
void NWNXFuncs_SetXP(object oPC, int iXP);

// Set the racial type of oObject to iRace;
// Will not change the actual appearance of iObject
void NWNXFuncs_SetRace(object oCreature, int iRace);

// Sets the base AC for a given AC type
// Effectively, this is the base AC of the item (armour or shield) worn; or the Natural AC set in the toolset for a creature; ; does not make changes to any items themselves
// Valid values for iACType are:
// AC_ARMOUR_ENCHANTMENT_BONUS (base ac of the armor worn)
// AC_SHIELD_ENCHANTMENT_BONUS (base ac of the shield worn)
// AC_NATURAL_BONUS (base ac of a creature set in the toolset)
void NWNXFuncs_SetBaseAC(object oCreature, int iValue, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS);

// Returns the base AC for a given AC type
// Effectively, this is the base AC of the item (armour or shield) worn; or the Natural AC set in the toolset for a creature
// See NWNXFuncs_SetBaseAC for iACType values
int  NWNXFuncs_GetBaseAC(object oCreature, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS);

// Sets the AC bonus for a given AC type
// Effectively, this is the AC bonus of a worn item or from EffectACIncrease; does not make changes to any items themselves
// Valid values for iACType are:
// AC_ARMOUR_ENCHANTMENT_BONUS (highest bonus ac from an item with Armor AC)
// AC_SHIELD_ENCHANTMENT_BONUS (highest bonus ac from an item with Shield AC)
// AC_NATURAL_BONUS (highest bonus ac from an item with Natural AC)
// AC_DEFLECTION_BONUS (highest bonus ac from an item with Deflection AC)
// AC_DODGE_BONUS (highest bonus ac from an item with Dodge AC)
void NWNXFuncs_SetBonusAC(object oCreature, int iValue, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS);

// Returns the AC bonus for a given AC type
// See NWNXFuncs_SetBonusAC for iACType values
int  NWNXFuncs_GetBonusAC(object oCreature, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS);

// Sets the AC penalty for a given AC type
// See NWNXFuncs_SetBonusAC for iACType values
void NWNXFuncs_SetPenaltyAC(object oCreature, int iValue, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS);

// Returns the AC penalty for a given AC type
// See NWNXFuncs_SetBonusAC for iACType values
int  NWNXFuncs_GetPenaltyAC(object oCreature, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS);

// Sets the Skill Points saved during level-up
void NWNXFuncs_SetSavedSkillPoints(object oPC, int iSkillPoints, int nLevel=0);

// Returns the Skill Points saved during level-up
int  NWNXFuncs_GetSavedSkillPoints(object oPC, int nLevel=0);

// Sets the Armor Check Penalty currently incured from wearing armor or a shield
// AC_ARMOUR_ENCHANTMENT_BONUS sets the penalty from armor
// AC_SHIELD_ENCHANTMENT_BONUS sets the penalty from a shield
// Does not actually modify the items themselves
// Value is reset when the respective item is unequipped or equipped
void NWNXFuncs_SetArmorCheckPenalty(object oCreature, int iPenalty, int iShield_Armor = AC_ARMOUR_ENCHANTMENT_BONUS);

// Returns the Armor Check Penalty currently incurred from wearing armor or a shield
int  NWNXFuncs_GetArmorCheckPenalty(object oCreature, int iShield_Armor = AC_ARMOUR_ENCHANTMENT_BONUS);

// Returns the speed of oObject
// Values correspond with the ones in creaturespeed.2da
int  NWNXFuncs_GetMovementRate(object oCreature);

// Sets the type of familiar oObject can summon
// Does not allow summoning of familiars without having the necessary feat
void NWNXFuncs_SetFamiliarType(object oCreature, int iFamiliarType);

// Sets the type of animal companion oObject can summon
// Does not allow summoning of animal companians without having the necessary feat
void NWNXFuncs_SetAnimalCompanion(object oCreature, int iAnimalCompanionType);

// Sets hitpoints gained at iLevel
void NWNXFuncs_SetHitPointsByLevel(object oCreature, int iHP, int iLevel);

// Changes the hitpoints gained at iLevel by iHPMod
void NWNXFuncs_ModHitPointsByLevel(object oCreature, int iHPMod, int iLevel);

// Sets the amount of hitpoints oObject has currently to iHP
void NWNXFuncs_SetCurrentHitPoints(object oCreature, int iHP);

// Sets the amount of hitpoints oObject can maximally have to iHP
void NWNXFuncs_SetMaxHitPoints(object oCreature, int iHP);

// Set the saving throw bonus iSavingThrow of oObject to iValue;
void NWNXFuncs_SetSavingThrowBonus(object oCreature, int iSavingThrow, int iValue);

// Changes the saving throw bonus iSavingThrow of oObject by iValue;
void NWNXFuncs_ModSavingThrowBonus(object oCreature, int iSavingThrow, int iValue);

// Changes the skill ranks for iSkill on oObject to iValue
void NWNXFuncs_SetSkill(object oCreature, int iSkill, int iValue);

// Changes the skill ranks for iSkill on oObject by iValue
void NWNXFuncs_ModSkill(object oCreature, int iSkill, int iValue);

// Changes the skill ranks for iSkill gained at iLevel on oObject to iValue
void NWNXFuncs_SetSkillByLevel(object oCreature, int iSkill, int iValue, int iLevel);

// Changes the skill ranks for iSkill gained at iLevel on oObject by iValue
void NWNXFuncs_ModSkillByLevel(object oCreature, int iSkill, int iValue, int iLevel);

// Changes the internal size of a creature to iSize (CREATURE_SIZE_*)
// This does not change the physical size of the creature model as seen in game
void NWNXFuncs_SetCreatureSize(object oCreature, int iSize = CREATURE_SIZE_MEDIUM);

// Returns the total weight of all items equiped by oCreature in tenth of pounds
int  NWNXFuncs_GetEquippedWeight(object oCreature);

// Changes the number of saved skillpoints by iSkillPoints
void NWNXFuncs_ModSavedSkillPoints(object oPC, int iSkillPoints, int nLevel=0);

// Removes a feat from a creature
// If bRemoveFromLevel is FALSE, the feat will only be removed from the general feat list (the feat lists for each character level are ignored; 
// If bRemoveFromLevel is TRUE, the feat will be removed from the general feat list and from the feat list for the appropriate level
// If found, the feat will be removed from the general feat list whether it exists in a level feat list or not, and vice versa
int  NWNXFuncs_RemoveFeat(object oCreature, int iFeat, int bRemoveFromLevel=TRUE);

// Checks if oCreature inherently knows a feat (as opposed to a feat given from an equipped item)
// Returns FALSE if oCreature does not know the feat, TRUE if the feat is known
// The return value (if greater than 0) also denotes the position of the feat in the general feat list offset by +1
int  NWNXFuncs_GetFeatKnown(object oCreature, int iFeat);

// Retuns a delimited list of all the known feats of oCreature
// Not sure how useful this is in general but I'll be using it to enter it into mysql
// GetAllKnownFeats can fail if oCreature has too many feats (more precisely if the returned string would be longer than 2048 characters)
// Worst case scenario (all feats are above row 10000) is about 340 feats for the default delimiter
string NWNXFuncs_GetAllKnownFeats(object oCreature, string sDelimiter=",");

// Removes all feats from oCreature's general feat list (oCreature will not have any feats in game)
// If bClearLevelFeatLists is true it will remove all the feats from the level stat lists too
void NWNXFuncs_RemoveAllFeats(object oCreature, int bClearLevelFeatLists=1);

// Sets all skills of oCreature to zero
void NWNXFuncs_SetAllSkillsToZero(object oCreature);

// Adds iSpell (SPELL_*) to oCreature's list of spells
// iClass is the type of class to add the spell for (CLASS_TYPE_*)
// While iSpellLevel does not seem to matter for memorizing and casting the spell (the spell will show up at the right spell level in
// the spellbook, it might potentially cause problems selecting new spells
// If iCharacterLevel is greater than zero, the spell will be added to the Spells Known list for that level
// Only works for spell casting classes that need to select which spells they want to know (Sorcerer, Wizard, Bard)
void NWNXFuncs_AddKnownSpell(object oCreature, int iClass, int iSpellLevel, int iSpell, int iCharacterLevel=0);

// Removes a spell from a creature
// If bRemoveFromLevel is FALSE, the spell will only be removed from the class spell list (the spell lists for each character level are ignored; 
// If bRemoveFromLevel is TRUE, the spell will be removed from the class spell list and from the spell list for the appropriate level
// If found, the spell will be removed from the class spell list whether it exists in a level spell list or not, and vice versa
// Only works for spell casting classes that need to select which spells they want to know (Sorcerer, Wizard, Bard)
void NWNXFuncs_RemoveKnownSpell(object oCreature, int iClass, int iSpell, int bRemoveFromLevel=TRUE);

// Returns TRUE if one of oCreature's classes knows the spell iSpell at a specific spell level
// If iSpellLevel is left at the default value (-1) all of iClass's spell levels are searched for the spell and
// the return value is the spell level +1 at which the spell was found or FALSE if the spell was not found
// Only works for spell casting classes that need to select which spells they want to know (Sorcerer, Wizard, Bard)
int  NWNXFuncs_GetKnowsSpell(object oCreature, int iClass, int iSpell, int iSpellLevel=-1);

// Removes all known spells for a class
// Only works for spell casting classes that need to select which spells they want to know (Sorcerer, Wizard, Bard)
void NWNXFuncs_RemoveAllSpells(object oCreature, int iClass);

// Sets the Base Attack Bonus Override of oObject to iBaB
// If BAB Override is greater than zero GetBaseAttackBonus will return this instead
// The original BAB can be restored by setting the BAB Override to zero
// The range of iBab is 0 to 254
// Unfortunately this is not a permanent setting as the game calculates the BaB every time a player logs in
void NWNXFuncs_SetBaseAttackBonusOverride(object oCreature, int iBaB);

// Modifies the Bab override of oCreature by iBab
void NWNXFuncs_ModBaseAttackBonusOverride(object oCreature, int iBaB);

// Returns the current BaB override of oCreature
// If BAB Override is greater than zero this will return the same as GetBaseAttackBonus()
int  NWNXFuncs_GetBaseAttackBonusOverride(object oCreature);

// Sets the weight of an item;
// iWeight is in tenth of pounds (iWeight = 100 will set the item weight to 10.0; fractions are not displayed in game)
void NWNXFuncs_SetItemWeight(object oItem, int iWeight);

// Sets one of 3 different item values, determined by iType
// The value of an (identified) item is Identified Value + Additional Cost/Value
// ITEM_VALUE_IDENTIFIED: The item value when the item is identified. If bZeroAdditionalCost is TRUE, the additional cost of the item will be set to zero. (just to save a function call)
// ITEM_VALUE_UNIDENTIFIED: The value of an item as long as it is unidentified
// ITEM_VALUE_ADDITIONAL: An additional value which is added to the identified value of the item (This was used in the toolset since there was no other way of
// directly adjusting the value of an item. Can be set beyond the 32,000 allowed in the toolset.
void NWNXFuncs_SetItemValue(object oItem, int iValue, int iType = ITEM_VALUE_IDENTIFIED, int bZeroAdditionalCost = TRUE);

// Returns one of 3 different item values, determined by iType
// ITEM_VALUE_IDENTIFIED: The item value when the item is identified.
// ITEM_VALUE_UNIDENTIFIED: The value of an item as long as it is unidentified
// ITEM_VALUE_ADDITIONAL: An additional value which is added to the identified value of the item.
int  NWNXFuncs_GetItemValue(object oItem, int iType = ITEM_VALUE_ADDITIONAL);

// Set the charges an item has left.
// This can be used to set item charges up to 255 (the nwscript function limits this to 50).
void NWNXFuncs_SetItemCharges(object oItem, int iCharges);

// Sets either one of the two domains of a cleric to iDomain
// iDomain_1_2 can either be 1 or 2
void NWNXFuncs_SetDomain(object oCreature, int iDomain_1_2, int iDomain);

// Returns either one of the two domains of a cleric
// iDomain_1_2 can either be 1 or 2
int NWNXFuncs_GetDomain(object oCreature, int iDomain_1_2);

// Sets the specialist spell school of a Wizard
void NWNXFuncs_SetWizardSpecialization(object oCreature, int iSpecialization);

// Returns the specialist spell school of a Wizard
int NWNXFuncs_GetWizardSpecialization(object oCreature);

// Replaces a spell with another one.
// This will replace all occurences of iOldSpell with iNewSpell (in the ClassList as well as the LevelStatList)
void NWNXFuncs_ReplaceKnownSpell(object oCreature, int iClass, int iOldSpell, int iNewSpell);

// Returns the remaining spell slots (uses) oCreature has for a given class and spell level. (only applies to Bards and Sorcerers)
int  NWNXFuncs_GetRemainingSpellSlots(object oCreature, int iClass, int iSpellLevel);

// Sets the remaining spell slots (uses) oCreature has for a given class and spell level. (only applies to Bards and Sorcerers)
// nSlots cannot exceed the maximum spell slots for that spell level
void NWNXFuncs_SetRemainingSpellSlots(object oCreature, int iClass, int iSpellLevel, int nSlots);

// Returns the maximum spell slots (uses) oCreature has for a given class and spell level. (only applies to Bards and Sorcerers)
int  NWNXFuncs_GetMaxSpellSlots(object oCreature, int iClass, int iSpellLevel);

// Returns the number of bonus spell slots oCreature receives from items and effects (but not from high ability scores).
int  NWNXFuncs_GetBonusSpellSlots(object oCreature, int iClass, int iSpellLevel);

// Returns information about a memorized spell (spell id, meta magic and whether the spell is ready to be cast)
struct MemorizedSpellSlot NWNXFuncs_GetMemorizedSpellSlot(object oCreature, int iClass, int iSpellLevel, int iIndex);

// Sets information about a spell in a memorized spell slot (spell id, meta magic and whether the spell is ready to be cast);
void NWNXFuncs_SetMemorizedSpellSlot(object oCreature, int iClass, int iSpellLevel, int iIndex, struct MemorizedSpellSlot spell);

// Sets all spells for the given spell levels to be ready to cast (as if the creature had rested)
void NWNXFuncs_RestoreMemorizedSpells(object oCreature, int iClass, int iFromSpellLevel = 0, int iToSpellLevel = 9);

// Returns the number of feats oCreature has (not including feats gained from items)
int  NWNXFuncs_GetFeatCount(object oCreature);

// returns a string delimited by sDelimiter of all known spells of a given class and spell level
string NWNXFuncs_GetKnownSpells(object oCreature, int iClass, int iSpellLevel, string sDelimiter=",");

// returns the number of spells known for a given class and spell level
int NWNXFuncs_GetKnownSpellCount(object oCreature, int iClass, int iSpellLevel);

// Set an object's conversation resref (Creatures and Placeables only);
void NWNXFuncs_SetConversation(object oObject, string sConvo);

// Returns an object's conversation resref (Creatures and Placeables only);
string NWNXFuncs_GetConversation(object oObject);

// Sets the type of body bag a placeable or creature leaves behind on death
// iBodyBag values are in bodybag.2da
void NWNXFuncs_SetBodyBag(object oObject, int iBodyBag);

// Returns the type of body bag a placeable or creature leaves behind on death
int NWNXFuncs_GetBodyBag(object oObject);

// Returns a | delimited string of all feats oCreature gained at level iLevel
string NWNXFuncs_GetFeatsGainedAtLevel(object oCreature, int iLevel);

// Returns a | delimited string of the number of ranks oCreature gained to their skills at level iLevel
// the skills are in the same order as in skills.2da
string NWNXFuncs_GetSkillRanksGainedAtLevel(object oCreature, int iLevel);


// Returns a | delimited string of spells oCreature gained for a given spell level at level iLevel
string NWNXFuncs_GetSpellsGainedAtLevel(object oCreature, int iSpellLevel, int iLevel);

// returns Class, Hitpoints, Saved SkillPoints and which Ability was raised by oCreature at level iLevel
// levelstats.iAbility corresponds to the ABILITY_* constants and is 6 if no ability was raised at the given level
struct levelstats_s NWNXFuncs_GetStatsGainedAtLevel(object oCreature, int iLevel);


// Returns data for a given quickslot; 0-11 F1-F12 / 12-23 = SHIFT+(F1-F12) / 24-35 = CTRL+(F1-F12)
// Won't work for items
struct quickslot_s NWNXFuncs_GetQuickSlot(object oPC, int iSlot);

// Sets data for a given quickslot
// bUpdateGUI set to FALSE is useful when changing several quickslots at the same time.
// Each GUI update freezes the client for a fraction of a second, which isn't a problem if it happens only once
// but becomes VERY noticable for all 36 quickslots.
// Either call NWNXFuncs_SetQuickslot with bUpdateGUI = TRUE at the end of a series of changing quickslot or call
// NWNXFuncs_UpdateQuickbarGUI after all quickslots are set.
// Won't work for items
void NWNXFuncs_SetQuickSlot(object oPC, int iSlot, struct quickslot_s slotData, int bUpdateGUI=TRUE);

// Needs to be called after NWNXFuncs_SetQuickSlot has been used
// to actually update  oPC's GUI with the changes
void NWNXFuncs_UpdateQuickbarGUI(object oPC);

// Changes oCreatures class type at iPosition(1-3)
void NWNXFuncs_SetClassByPosition(object oCreature, int iPosition, int iClass);

// Sets the gender of oCreature to iGender (GENDER_*)
// This does NOT change the creature appearance in any way, unless a player relogs or a creature is saved and respawned
void NWNXFuncs_SetGender(object oCreature, int iGender);

// Sets the modules current date and time
// The values for wtDate and wtTime are calculated in the following manner
// wtDate = YY * (28*12) + (MM-1) * 28 + DD-1  (where YY := Year, MM := Month, DD := Day)
// wtTime = hh * 1000*60*MinutesPerHour + mm * 60*1000 + ss * 1000 + ms (where hh := hour, mm := Minute, ss := Second, ms := Millisecond; MinutesPerHour is the value set in the toolset)
void NWNXFuncs_SetWorldDateTime(int wtDate, int wtTime, int P3=0);

// Returns the modules current date as an unsigned integer value
int NWNXFuncs_GetWorldDate();

// Returns the modules current time as an unsigned integer value
int NWNXFuncs_GetWorldTime();

// Returns the id of the faction oCreature belongs to
int NWNXFuncs_GetFactionID(object oCreature);

// Changes the faction id of oCreature to iFactionID
void NWNXFuncs_SetFactionID(object oCreature, int iFactionID);

// Returns the soundsset of oCreature (row number of soundset.2da)
int NWNXFuncs_GetSoundSetID(object oCreature);

// Changes the soundsset of oCreature to iSoundSetID (row number of soundset.2da)
void NWNXFuncs_SetSoundSetID(object oCreature, int iSoundSetID);

// Retuns the bonus to a saving throw for oCreature
// This is the additional bonus, usually set in the toolset for NPCs, not a bonus from items or effects
int NWNXFuncs_GetSavingThrowBonus(object oCreature, int iSavingThrow = SAVING_THROW_FORT);

// Puts oCreature into Limbo
// Can be Removed with JumpToLocation/Object
void NWNXFuncs_JumpCreatureToLimbo(object oCreature);

// Changes the level for oCreature's class at position iClassPos
// This should not be used on player characters to increase their level
// as it will crash the server once they log off
void NWNXFuncs_SetClassLevel(object oCreature, int iClassPos, int iLevel);

// Return the Damage Immunity (in percent) of oCreature against a specific Damage Type
// Will return Damage Vulnerability too, in which case the return value will be negative
int NWNXFuncs_GetDamageImmunity(object oCreature, int iDamageType=DAMAGE_TYPE_BLUDGEONING);

// Gets the highest spell id (last effect applied) of all effects applied to oObject
// meant to work in conjunction with SetEffectSpellIDByEffectID / SetCreatorByEffectID
int NWNXFuncs_GetHighestEffectID(object oObject);


//*
// The following functions are for NWNXFuncs_GetFirst_NextEffectInternal loops only and should not be
// used within a reguler GetFirst/NextEffect loop
//*

// Cycles through the effects of oObject
// if bExposedOnly is true this function only cycles through effect which are returned
// by the "real" GetFirst/NextEffect. Otherwise it includes effects not exposed to scripts
// Do NOT add or remove effects in a NWNXFuncs_GetFirst/GetNextEffectInternal loop!
// instead use NWNXFuncs_QueueRemoveEffectInternal to add an effect to the removal queue and
// NWNXFuncs_RemoveQueuedEffectsInternal after the loop is done to remove the effects.
// NWNXFuncs_GetFirstEffectInternal will empty an existing queue, but not remove any effects
// Both functions return FALSE if no (more) effects could be found, TRUE if they found an effect
// The actual effect is stored internally and all other functions to manipulate an effect or return data from it
// use this internal effect and therefore don't require an object as a paramter.
// (They actually use OBJECT_SELF but it could be any valid object.)
int NWNXFuncs_GetFirstEffectInternal(object oObject, int bExposedOnly = FALSE);
int NWNXFuncs_GetNextEffectInternal(object oObject);


// Returns the remaining duration in milliseconds of the effect on oObject currently selected by NWNXFuncs_GetFirst/NextEffectInternal
// Uses the current effect from NWNXFuncs_GetFirst/NextEffectInternal
int NWNXFuncs_GetEffectRemainingDurationInternal();

// Returns the Integers associated with an effect as a ¬ separated string
// Uses the current effect from NWNXFuncs_GetFirst/NextEffectInternal
// These integers are usually the Parameters from the create Effect functions
// e.g.: For EffectAbilityIncrease(ABILITY_DEXTERITY, 7) GetEffectIntegers would return 1¬7¬0¬0¬0¬0¬0¬
// Most (all) effects seem to have 8 integers associated with them, whether they have any meaning or not
// Returns an empty string if an error occured
string NWNXFuncs_GetEffectIntegersInternal();

// Returns a specific Integer associated with an effect
// Uses the current effect from NWNXFuncs_GetFirst/NextEffectInternal
// nNthInteger starts at 0 (for the first integer)
// Returns -1 on error
int NWNXFuncs_GetEffectIntegerInternal(int nNthInteger);

// Changes the Integer values associated with an effect
// Uses the current effect from NWNXFuncs_GetFirst/NextEffectInternal
// nNthInteger starts at 0 (for the first integer)
// Changing integers values doesn't necessarily propagate through all values affected by the original effect.
// e.g.: Changing the strength bonus (2nd int) from EffectAbilityIncrease(ABILITY_STRENGTH, ...) will change the Strength score
// but won't update the Attack Bonus or Damage
// Since most (all) effects have at least 8 integer values associated with them, the unused ones could be used to store additional custom information
void NWNXFuncs_SetEffectIntegerInternal(int nNthInteger, int iIntValue);

// Returns the id of an effect
// Uses the current effect from NWNXFuncs_GetFirst/NextEffectInternal
int NWNXFuncs_GetEffectIDInternal();

// The following 5 functions do exactly the same as their regular script counterparts
// but can be used in a NWNXFuncs_GetFirst/NextEffectInternal loop without having to run a GetFirst/GetNext alongside it
int NWNXFuncs_GetEffectTypeInternal(int bRealType = TRUE);
int NWNXFuncs_GetEffectSubTypeInternal();
string NWNXFuncs_GetEffectCreatorInternal();
int NWNXFuncs_GetEffectSpellIdInternal();
int NWNXFuncs_GetEffectDurationTypeInternal();

// Queues the current effect of an NWNXFuncs_GetFirst/NextEffectInternal loop for removal
// Calling NWNXFuncs_GetFirstEffectInternal will empty the queue, but not remove any effects
void NWNXFuncs_QueueRemoveEffectInternal();

// To be used AFTER an NWNXFuncs_GetFirst/NextEffectInternal loop.
// Removes all queued effects
// Calling NWNXFuncs_GetFirstEffectInternal will empty the queue, but not remove any effects
void NWNXFuncs_RemoveQueuedEffectsInternal(object oObject);

//*
// The following functions are for can be used inside a regular GetFirst/GetNextEffect loop
// and do the same as the "internal" versions; With the exception of NWNXFuncs_GetEffectRealType, which
// always returns the "internal" effect type
// However, they invalidate a NWNXFuncs_GetFirst/NextEffectInternal loop
//*
string NWNXFuncs_GetEffectIntegers(object oObject);
int NWNXFuncs_GetEffectInteger(object oObject, int nNthInteger);
void NWNXFuncs_SetEffectInteger(object oObject, int nNthInteger, int iIntValue);
float NWNXFuncs_GetEffectRemainingDuration(object oObject);
int NWNXFuncs_GetEffectID(object oObject);
int NWNXFuncs_GetEffectRealType(object oObject);

// Applies a visual effect at a specified location that only oPC can see
// This only works with instant visual effects (VFX_FNF_*, VFX_IMP_*)
void NWNXFuncs_ApplyVisualEffectForPC(object oPC, int nVFX, vector vPos);

// Changes the geometry of a trap created by a subsequent CreateTrapAtLocation(...) call
// Needs to be called before CreateTrapAtLocation!
// sGeometry is a list of x and y coordinates separated by ¬ (the z coordinate is 
// calculated automatically so that the trap is placed on the floor)
// The coordinates list also not include the the first coordinate pair (actual location
// of the trap), because the location parameter from CreateTrapAtLocation will 
// be used for that.
// If bAbsoluteCoordinates is FALSE, all coordinates in the list are treated as being relative to 
// the location of the trap.
// If bAbsoluteCoordinates is TRUE, the coordinates in the list are treated as absolute coordinates
// for the area.
// If an invalid (odd) number of coordinates is used, CreateTrapAtLocation behaves as usual
// and creates a square trap of the specified size
// See trap_example.nss for details on relative coordinates
// See trap_respawn.nss and trap_area_respwn.nss for details on absolute coordinates (and how
// to repawn traps that aren't square
void NWNXFuncs_SetCustomTrapGeometry(string sGeometry, int bAbsoluteCoordinates=FALSE);

// Applies a simple rotation to the coordinates created by NWNXFuncs_SetCustomTrapGeometry
// Needs to be called after NWNXFuncs_SetCustomTrapGeometry but before CreateTrapAtLocation
// This does NOT work when using Absolute Coordinates
// See trap_example.nss for details
void NWNXFuncs_RotateCustomTrapGeometry(float fAngle);

// Returns the geometry of a trigger type trap as a list of x and y coordinates, separated by ¬
// See trap_respawn.nss and trap_area_respwn.nss for details
string NWNXFuncs_GetTrapGeometry(object oTrap);

// Returns a row from surfacemat.2da indicating the material of the location given
// Return -1 on error
int NWNXFuncs_GetSurfaceMaterial(location lLoc);

// Changes the debug level (how much gets logged) for the plugin
// same as the option in nwnx.ini
void NWNXFuncs_SetDebugLevel(int iDebugLevel);

// Displays a timing bar for oPC (the same one that is displayed when resting or disarmaing a trap)
// iDuration is the time in milliseconds until the bar is filled
// iLabel is a reference (TIMINGBAR_LABEL_*) to what label is displayed above the timing bar. (Unforunately this
// doesn't directly reference a  tlk entry)
// Unlike with a "regular" game event (rest, unlock, disarm trap, etc) the timing bar
// will not disappear when the bar is filled or the player takes any actions, but only
// if NWNXFuncs_StopTimingbar is called
void NWNXFuncs_StartTimingbar(object oPC, int iDuration, int iLabel);

// Removes a timing bar for oPC
void NWNXFuncs_StopTimingbar(object oPC);

// Set a creature's age
void NWNXFuncs_SetAge(object oCreature, int iAge);

// Changes the Tag of an object
void NWNXFuncs_SetTag(object oObject, string sTag);

// returns the name of an eventscript for an object
string NWNXFuncs_GetEventScript(object oObject, int iEvent);

// sets an eventscript for an object
void NWNXFuncs_SetEventScript(object oObject, string sScript, int iEvent);

// Clear the playerdata of logged off players 
// This is rather experimental.
// This function deletes all the persistent player data the server stores 
// when a player logs off: Location, local variables, effects, etc.
// This does not affect any scripted custom persistency between resets
// After a call to NWNXFuncs_ClearPlayerTURDs the server will essentially
// behave as if it had been reset when player logon's are concerened.
void NWNXFuncs_ClearPlayerTURDs();

// Sets the class type taken at a specific level
void NWNXFuncs_SetClassByLevel(object oCreature, int iClass, int iLevel);

// Replaces one class of a creature with another
// including classes in the level statlist of the creature
void NWNXFuncs_ReplaceClass(object oCreature, int iOldClass, int iNewClass);

// Updates the character sheet of a player
// Most of the information on the char sheet is just for display purposes and the 
// actual values used (e.g. for combat) are recalculated when needed.
// This function "resyncs" the charsheet with the real values should they go out
// of sync (can happen with NWNXFuncs_ReplaceClass)
void NWNXFuncs_UpdateCharacterSheet(object oPC);

// Returns a custom effect as defined by the gameeffect_s struct (see nwnx_funcs_effst.nss and nwnx_funcs_eff.nss)
effect NWNXFuncs_EffectCustomEffect(struct gameeffect_s e);

// Returns the duration subtype of the current effect in a GetFirst/NextEffect loop
int NWNXFuncs_GetEffectSubType(object oObject);

// Boots a PC displaying a tlk entry rather than the standard "You have been booted"
void NWNXFuncs_BootPCWithMessage(object oPC, int iTlkEntry);

// Get Information about an itemproperty
float NWNXFuncs_GetItemPropertyDuration(itemproperty ip);
float NWNXFuncs_GetItemPropertyDurationRemaining(itemproperty ip);
int NWNXFuncs_GetItemPropertyInteger(itemproperty ip, int nInt);
int NWNXFuncs_GetItemPropertySpellId(itemproperty ip);

// These don't do anything (yet)
void NWNXFuncs_SetItemPropertyInteger(itemproperty ip, int nInt, int iValue);
void NWNXFuncs_SetItemPropertySpellId(itemproperty ip, int iSpellID);

// Create a Custom ItemProperty
// Can be used to apply itemproperties which are defined via 2DAs (itempropdef.2da, iprp_*.2da, etc) but do not have scripting functions
itemproperty NWNXFuncs_ItemPropertyCustom(int iType, int iSubType, int iCostTableValue, int iParam1Value);


//**** Original work by virusman ****

const int VISIBILITY_TYPE_DEFAULT = 0;
const int VISIBILITY_TYPE_VISIBLE = 1;
const int VISIBILITY_TYPE_INVISIBLE = 2;

// Sets the visibility of oObject for everybody
void NWNXFuncs_SetVisibilityOverride(object oObject, int nVisibilityType);

// Sets whether oObject2 can see oObject1
void NWNXFuncs_SetVisibility(object oObject1, object oObject2, int nVisibility);

// Gets the visibility of oObject
int NWNXFuncs_GetVisibilityOverride(object oObject);

// Gets whether oObject2 can see oObject1
int NWNXFuncs_GetVisibility(object oObject1, object oObject2);

//**************************************

// Gets the amount of regeneration a creature currently possess
int NWNXFuncs_GetRegeneration(object oCreature, int nType=REGENERATION_ALL);

// Helper function to add overrides for specific immunities
// The override is simply a bitfield (integer)
// the last one (DEATH) would be 2^32 which a script INT cannot hold (max is 2^(32-1)) but Death has to be explicitly checked for anyways
// Overrides |= 2 << (iImmunity - 1)
int NWNXFuncs_ImmunityOverride(int Overrides, int iImmunity);

// Sets immunity overrides for a creature
void NWNXFuncs_SetImmunityOverride(object oCreature, int Override);

// Removes all immunity overrides for a creature
void NWNXFuncs_RemoveAllImmunityOverrides(object oCreature);

// Directly adds a single immunity override to a creature
void NWNXFuncs_AddImmunityOverride(object oCreature, int iImmunity);

// Remove a single immunity override from a creature
void NWNXFuncs_RemoveImmunityOverride(object oCreature, int iImmunity);

//Get the AutoRemoveKey flag from a door or placeable object
int NWNXFuncs_GetAutoRemoveKeyFlag(object oObject);

//Set the AutoRemoveKey flag from a door or placeable object
void NWNXFuncs_SetAutoRemoveKeyFlag(object oObject, int iFlag);

//*******************************************************************************************************************

object NWNXFuncs_StringToObject(string soID) {
	return GetLocalObject(OBJECT_SELF, "NWNX!FUNCS!STRINGTOOBJECT¬"+soID);

}

object NWNXFuncs_GetFirstArea() {
	return GetLocalObject(OBJECT_SELF, "NWNX!FUNCS!GETFIRSTAREA");

}	

object NWNXFuncs_GetNextArea() {
	return GetLocalObject(OBJECT_SELF, "NWNX!FUNCS!GETNEXTAREA");
}	
	

object NWNXFuncs_GetAreaByPosition(int iIndex) {
	return GetLocalObject(OBJECT_SELF, "NWNX!FUNCS!GETAREABYPOSITION¬"+IntToString(iIndex));
}

struct localvar_s NWNXFuncs_GetFirstLocalVariable(object oObject) {
	return NWNXFuncs_GetLocalVarByPosition(oObject, 0); 
}

struct localvar_s NWNXFuncs_GetNextLocalVariable(struct localvar_s lv) {
	return NWNXFuncs_GetLocalVarByPosition(lv.obj, lv.nPos + 1); 
}

struct localvar_s NWNXFuncs_GetLocalVarByPosition(object oObject, int iVarPos) {
	SetLocalString(oObject, "NWNX!FUNCS!GETLOCALVARBYPOSITION", IntToString(iVarPos)+ " ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"); 
	string sVar = GetLocalString(oObject, "NWNX!FUNCS!GETLOCALVARBYPOSITION");
	DeleteLocalString(oObject, "NWNX!FUNCS!GETLOCALVARBYPOSITION");
	struct localvar_s lv;
	if (sVar != "") {
		int iP = FindSubString(sVar, "¬");
		lv.iType = StringToInt(GetStringLeft(sVar, iP));
		lv.sName = GetStringRight(sVar, GetStringLength(sVar)-(iP+1));
		lv.obj = oObject;
		lv.nPos = iVarPos;
	}
	return lv;
}

void NWNXFuncs_DumpEffects(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!PRINTEFFECTS", "-");
	DeleteLocalString(oObject, "NWNX!FUNCS!PRINTEFFECTS");
}

void NWNXFuncs_DumpLocals(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!PRINTLOCALVARS", "-");
	DeleteLocalString(oObject, "NWNX!FUNCS!PRINTLOCALVARS");
}

void NWNXFuncs_SetGold(object oCreature, int iGold) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETGOLD", IntToString(iGold));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETGOLD");
}

void NWNXFuncs_SetAbilityScore(object oCreature, int iAbility, int iValue, int bAdjustCurrentHitPoints = 1) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETABILITYSCORE", IntToString(iAbility)+" "+IntToString(iValue)+ " 0"+ " "+IntToString(bAdjustCurrentHitPoints));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETABILITYSCORE");
}

void NWNXFuncs_ModAbilityScore(object oCreature, int iAbility, int iValue, int bAdjustCurrentHitPoints = 1) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETABILITYSCORE", IntToString(iAbility)+" "+IntToString(iValue)+" 1"+ " "+IntToString(bAdjustCurrentHitPoints));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETABILITYSCORE");
}

int NWNXFuncs_GetBaseAttackBonusOverride(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETBABOVERRIDE", "---");
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETBABOVERRIDE"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETBABOVERRIDE");
	return iRet;
}

void NWNXFuncs_SetBaseAttackBonusOverride(object oCreature, int iBaB) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETBABOVERRIDE", IntToString(iBaB)+ " 0");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETBABOVERRIDE");
}

void NWNXFuncs_ModBaseAttackBonusOverride(object oCreature, int iBaB) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETBABOVERRIDE", IntToString(iBaB)+ " 1");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETBABOVERRIDE");
}

void NWNXFuncs_AddFeat(object oCreature, int iFeat, int iLevel=0) {
	if (!iLevel) {
		SetLocalString(oCreature, "NWNX!FUNCS!ADDFEAT", IntToString(iFeat));
		DeleteLocalString(oCreature, "NWNX!FUNCS!ADDFEAT");
	}
	else if(iLevel > 0) {
		SetLocalString(oCreature, "NWNX!FUNCS!ADDFEATATLEVEL", IntToString(iLevel)+" "+IntToString(iFeat));
		DeleteLocalString(oCreature, "NWNX!FUNCS!ADDFEATATLEVEL");
	}
}

void NWNXFuncs_SetXP(object oPC, int iXP) {
	SetLocalString(oPC, "NWNX!FUNCS!SETXP", IntToString(iXP));
	DeleteLocalString(oPC, "NWNX!FUNCS!SETXP");
}

void NWNXFuncs_SetRace(object oCreature, int iRace) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETRACE", IntToString(iRace));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETRACE");
}

void NWNXFuncs_SetBaseAC(object oCreature, int iValue, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETBASEAC", IntToString(iValue)+" "+IntToString(iACType));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETBASEAC");
}

int NWNXFuncs_GetBaseAC(object oCreature, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETBASEAC", IntToString(iACType));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETBASEAC"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETBASEAC");
	return iRet;
}

void NWNXFuncs_SetBonusAC(object oCreature, int iValue, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETBONUSAC", IntToString(iValue)+" "+IntToString(iACType));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETBONUSAC");
}

int NWNXFuncs_GetBonusAC(object oCreature, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETBONUSAC", IntToString(iACType));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETBONUSAC"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETBONUSAC");
	return iRet;
}

void NWNXFuncs_SetPenaltyAC(object oCreature, int iValue, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETPENALTYAC", IntToString(iValue)+" "+IntToString(iACType));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETPENALTYAC");
}

int NWNXFuncs_GetPenaltyAC(object oCreature, int iACType = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETPENALTYAC", IntToString(iACType));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETPENALTYAC"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETPENALTYAC");
	return iRet;
}

void NWNXFuncs_SetSavedSkillPoints(object oPC, int iSkillPoints, int nLevel=0) {
	SetLocalString(oPC, "NWNX!FUNCS!SETSAVEDSKILLPOINTS", IntToString(iSkillPoints)+" 0 " +IntToString(nLevel));
	DeleteLocalString(oPC, "NWNX!FUNCS!SETSAVEDSKILLPOINTS");
}

int NWNXFuncs_GetSavedSkillPoints(object oPC, int nLevel=0) {
	SetLocalString(oPC, "NWNX!FUNCS!GETSAVEDSKILLPOINTS", IntToString(nLevel));
	int iRet = StringToInt(GetLocalString(oPC, "NWNX!FUNCS!GETSAVEDSKILLPOINTS"));
	DeleteLocalString(oPC, "NWNX!FUNCS!GETSAVEDSKILLPOINTS");
	return iRet;
}

void NWNXFuncs_SetArmorCheckPenalty(object oCreature, int iPenalty, int iShield_Armor = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETARMORCHECKPENALTY", IntToString(iPenalty)+" "+IntToString(iShield_Armor));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETARMORCHECKPENALTY");
}

int NWNXFuncs_GetArmorCheckPenalty(object oCreature, int iShield_Armor = AC_ARMOUR_ENCHANTMENT_BONUS) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETARMORCHECKPENALTY", IntToString(iShield_Armor));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETARMORCHECKPENALTY"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETARMORCHECKPENALTY");
	return iRet;
}

int NWNXFuncs_GetMovementRate(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETMOVEMENTRATE", "-");
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETMOVEMENTRATE"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETMOVEMENTRATE");
	return iRet;
}

void NWNXFuncs_SetFamiliarType(object oCreature, int iFamiliarType) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETFAMILIARTYPE", IntToString(iFamiliarType));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETFAMILIARTYPE");
}

void NWNXFuncs_SetAnimalCompanion(object oCreature, int iAnimalCompanionType) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETCOMPANIONTYPE", IntToString(iAnimalCompanionType));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETCOMPANIONTYPE");
}

void NWNXFuncs_SetHitPointsByLevel(object oCreature, int iHP, int iLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETHITPOINTSBYLEVEL", IntToString(iHP)+" "+IntToString(iLevel)+" 0");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETHITPOINTSBYLEVEL");
}

void NWNXFuncs_ModHitPointsByLevel(object oCreature, int iHPMod, int iLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETHITPOINTSBYLEVEL", IntToString(iHPMod)+" "+IntToString(iLevel)+" 1");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETHITPOINTSBYLEVEL");
}

void NWNXFuncs_SetCurrentHitPoints(object oCreature, int iHP) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETCURRENTHITPOINTS", IntToString(iHP));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETCURRENTHITPOINTS");
}	

void NWNXFuncs_SetMaxHitPoints(object oCreature, int iHP) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETMAXHITPOINTS", IntToString(iHP));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETMAXHITPOINTS");
}

void NWNXFuncs_SetSavingThrowBonus(object oCreature, int iSavingThrow, int iValue) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETSAVINGTHROWBONUS", IntToString(iSavingThrow)+" "+IntToString(iValue)+" 0");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETSAVINGTHROWBONUS");
}

void NWNXFuncs_ModSavingThrowBonus(object oCreature, int iSavingThrow, int iValue) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETSAVINGTHROWBONUS", IntToString(iSavingThrow)+" "+IntToString(iValue)+" 1");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETSAVINGTHROWBONUS");
}

void NWNXFuncs_SetSkill(object oCreature, int iSkill, int iValue) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETSKILL", IntToString(iSkill)+" "+IntToString(iValue)+" 0");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETSKILL");
}
void NWNXFuncs_ModSkill(object oCreature, int iSkill, int iValue) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETSKILL", IntToString(iSkill)+" "+IntToString(iValue)+" 1");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETSKILL");
}

void NWNXFuncs_SetSkillByLevel(object oCreature, int iSkill, int iValue, int iLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETSKILLBYLEVEL", IntToString(iSkill)+" "+IntToString(iValue)+" "+IntToString(iLevel)+" 0");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETSKILLBYLEVEL");
}

void NWNXFuncs_ModSkillByLevel(object oCreature, int iSkill, int iValue, int iLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETSKILLBYLEVEL", IntToString(iSkill)+" "+IntToString(iValue)+" "+IntToString(iLevel)+" 1");
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETSKILLBYLEVEL");
}

int NWNXFuncs_GetAreaCount() {
	object oObject = GetModule();
	SetLocalString(oObject, "NWNX!FUNCS!GETAREACOUNT", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETAREACOUNT"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETAREACOUNT");
	return iRet;
}	

int NWNXFuncs_GetLocalVariableCount(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLECOUNT", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLECOUNT"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETLOCALVARIABLECOUNT");
	return iRet;
}

int NWNXFuncs_GetHasLocalVariable(object oObject, string sVarName, int iVarType = 0) {
	SetLocalString(oObject, "NWNX!FUNCS!GETHASLOCALVARIABLE", sVarName+ " " +IntToString(iVarType));
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETHASLOCALVARIABLE"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETHASLOCALVARIABLE");
	return iRet;
}

void NWNXFuncs_SetCreatureSize(object oCreature, int iSize = CREATURE_SIZE_MEDIUM) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETCREATURESIZE", IntToString(iSize));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETCREATURESIZE");
}

int NWNXFuncs_GetEquippedWeight(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETEQUIPPEDWEIGHT", "-");
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETEQUIPPEDWEIGHT"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETEQUIPPEDWEIGHT");
	return iRet;
}

void NWNXFuncs_ModSavedSkillPoints(object oPC, int iSkillPoints, int nLevel=0) {
	SetLocalString(oPC, "NWNX!FUNCS!SETSAVEDSKILLPOINTS", IntToString(iSkillPoints)+" 1 "+IntToString(nLevel));
	DeleteLocalString(oPC, "NWNX!FUNCS!SETSAVEDSKILLPOINTS");
}

int NWNXFuncs_RemoveFeat(object oCreature, int iFeat, int bRemoveFromLevel=TRUE) {
	SetLocalString(oCreature, "NWNX!FUNCS!REMOVEFEAT", IntToString(iFeat)+" "+IntToString(bRemoveFromLevel));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!REMOVEFEAT"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!REMOVEFEAT");
	return iRet;
}

int NWNXFuncs_GetFeatKnown(object oCreature, int iFeat) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETFEATKNOWN", IntToString(iFeat));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETFEATKNOWN"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETFEATKNOWN");
	return iRet;
}

string NWNXFuncs_GetAllKnownFeats(object oCreature, string sDelimiter=",") {
	
	// reserve enough space for the return string
	// spacer = 256 bytes
	string sSpacer;
	int iCount = NWNXFuncs_GetFeatCount(oCreature);
	iCount = (iCount*5+(iCount-1)*GetStringLength(sDelimiter))+1;
	iCount = iCount / 256 +1;
	for (iCount; iCount>0; iCount--) {
		sSpacer += "                                                                                                                                                                                                                                                                ";
	}
	
	SetLocalString(oCreature, "NWNX!FUNCS!GETALLKNOWNFEATS", sDelimiter+GetStringLeft(sSpacer, GetStringLength(sSpacer)-GetStringLength(sDelimiter)));
	string sRet = GetLocalString(oCreature, "NWNX!FUNCS!GETALLKNOWNFEATS");
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETALLKNOWNFEATS");
	return sRet;
}

void NWNXFuncs_RemoveAllFeats(object oCreature, int bClearLevelFeatLists=1) {
	SetLocalString(oCreature, "NWNX!FUNCS!CLEARFEATLIST", IntToString(bClearLevelFeatLists));
	DeleteLocalString(oCreature, "NWNX!FUNCS!CLEARFEATLIST");
}

void NWNXFuncs_SetAllSkillsToZero(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!ZEROALLSKILLS", "-");
	DeleteLocalString(oCreature, "NWNX!FUNCS!ZEROALLSKILLS");
}

void NWNXFuncs_AddKnownSpell(object oCreature, int iClass, int iSpellLevel, int iSpell, int iCharacterLevel=0) {
	SetLocalString(oCreature, "NWNX!FUNCS!ADDKNOWNSPELL", IntToString(iClass)+" "+IntToString(iSpellLevel)+" "+IntToString(iSpell)+" "+IntToString(iCharacterLevel));
	DeleteLocalString(oCreature, "NWNX!FUNCS!ADDKNOWNSPELL");
}

void NWNXFuncs_RemoveKnownSpell(object oCreature, int iClass, int iSpell, int bRemoveFromLevel=TRUE) {
	SetLocalString(oCreature, "NWNX!FUNCS!REMOVEKNOWNSPELL", IntToString(iClass)+" "+IntToString(iSpell)+" "+IntToString(bRemoveFromLevel));
	DeleteLocalString(oCreature, "NWNX!FUNCS!REMOVEKNOWNSPELL");
}

void NWNXFuncs_RemoveAllSpells(object oCreature, int iClass) {
	SetLocalString(oCreature, "NWNX!FUNCS!REMOVEALLSPELLS", IntToString(iClass));
	DeleteLocalString(oCreature, "NWNX!FUNCS!REMOVEALLSPELLS");
}

int NWNXFuncs_GetKnowsSpell(object oCreature, int iClass, int iSpell, int iSpellLevel=-1) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETKNOWSSPELL", IntToString(iClass)+" "+IntToString(iSpell)+" "+IntToString(iSpellLevel));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETKNOWSSPELL"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETKNOWSSPELL");
	return iRet;
}

void NWNXFuncs_SetItemWeight(object oItem, int iWeight) {
	SetLocalString(oItem, "NWNX!FUNCS!SETITEMWEIGHT", IntToString(iWeight));
	DeleteLocalString(oItem, "NWNX!FUNCS!SETITEMWEIGHT");
}

void NWNXFuncs_SetItemValue(object oItem, int iValue, int iType = ITEM_VALUE_IDENTIFIED, int bZeroAdditionalCost = TRUE) {
	SetLocalString(oItem, "NWNX!FUNCS!SETITEMVALUE", IntToString(iValue)+" "+IntToString(iType)+" "+IntToString(bZeroAdditionalCost));
	DeleteLocalString(oItem, "NWNX!FUNCS!SETITEMVALUE");
}

int NWNXFuncs_GetItemValue(object oItem, int iType = ITEM_VALUE_ADDITIONAL) {
	SetLocalString(oItem, "NWNX!FUNCS!GETITEMVALUE", IntToString(iType));
	int iRet = StringToInt(GetLocalString(oItem, "NWNX!FUNCS!GETITEMVALUE"));
	DeleteLocalString(oItem, "NWNX!FUNCS!GETITEMVALUE");
	return iRet;
}

void NWNXFuncs_SetItemCharges(object oItem, int iCharges) {
	SetLocalString(oItem, "NWNX!FUNCS!SETITEMCHARGES", IntToString(iCharges));
	DeleteLocalString(oItem, "NWNX!FUNCS!SETITEMCHARGES");
}

void NWNXFuncs_SetDomain(object oCreature, int iDomain_1_2, int iDomain) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETDOMAIN", IntToString(iDomain_1_2)+" "+IntToString(iDomain));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETDOMAIN");
}
	
int NWNXFuncs_GetDomain(object oCreature, int iDomain_1_2) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETDOMAIN", IntToString(iDomain_1_2));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETDOMAIN"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETDOMAIN");
	return iRet;

}

void NWNXFuncs_SetWizardSpecialization(object oCreature, int iSpecialization) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETWIZARDSPECIALIZATION", IntToString(iSpecialization));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETWIZARDSPECIALIZATION");
}

int NWNXFuncs_GetWizardSpecialization(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETWIZARDSPECIALIZATION", "-");
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETWIZARDSPECIALIZATION"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETWIZARDSPECIALIZATION");
	return iRet;
	
}

void NWNXFuncs_ReplaceKnownSpell(object oCreature, int iClass, int iOldSpell, int iNewSpell) {
	SetLocalString(oCreature, "NWNX!FUNCS!REPLACEKNOWNSPELL", IntToString(iClass)+" "+IntToString(iOldSpell)+" "+IntToString(iNewSpell));
	DeleteLocalString(oCreature, "NWNX!FUNCS!REPLACEKNOWNSPELL");
}

int NWNXFuncs_GetRemainingSpellSlots(object oCreature, int iClass, int iSpellLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETREMAININGSPELLSLOTS", IntToString(iClass)+" "+IntToString(iSpellLevel));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETREMAININGSPELLSLOTS"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETREMAININGSPELLSLOTS");
	return iRet;
}

void NWNXFuncs_SetRemainingSpellSlots(object oCreature, int iClass, int iSpellLevel, int nSlots) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETREMAININGSPELLSLOTS", IntToString(iClass)+" "+IntToString(iSpellLevel)+" "+IntToString(nSlots));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETREMAININGSPELLSLOTS");
	
}

int NWNXFuncs_GetMaxSpellSlots(object oCreature, int iClass, int iSpellLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETMAXSPELLSLOTS", IntToString(iClass)+" "+IntToString(iSpellLevel));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETMAXSPELLSLOTS"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETMAXSPELLSLOTS");
	return iRet;
}

int NWNXFuncs_GetBonusSpellSlots(object oCreature, int iClass, int iSpellLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETBONUSSPELLSLOTS", IntToString(iClass)+" "+IntToString(iSpellLevel));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETBONUSSPELLSLOTS"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETBONUSSPELLSLOTS");
	return iRet;
}

struct MemorizedSpellSlot NWNXFuncs_GetMemorizedSpellSlot(object oCreature, int iClass, int iSpellLevel, int iIndex) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETMEMORIZEDSPELLSLOT", IntToString(iClass)+" "+IntToString(iSpellLevel)+" "+IntToString(iIndex));
	int nSpell = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETMEMORIZEDSPELLSLOT"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETMEMORIZEDSPELLSLOT");

	struct MemorizedSpellSlot iRet;
	
   if (nSpell >= 0) {
        iRet.id    = nSpell & 0xFFFF;
        iRet.meta  = (nSpell >> 16) & 0x7F;
        iRet.ready = (nSpell >> 24) & 1;
    } else
        iRet.id = -1;
 	
	return iRet;
}

void NWNXFuncs_SetMemorizedSpellSlot(object oCreature, int iClass, int iSpellLevel, int iIndex, struct MemorizedSpellSlot spell) {
	int P4 = (spell.id & 0xFFFF) | ((spell.meta& 0xFF) << 16) | (spell.ready << 24);
	SetLocalString(oCreature, "NWNX!FUNCS!SETMEMORIZEDSPELLSLOT", IntToString(iClass)+" "+IntToString(iSpellLevel)+" "+IntToString(iIndex)+" "+IntToString(P4));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETMEMORIZEDSPELLSLOT");
}

void NWNXFuncs_RestoreMemorizedSpells(object oCreature, int iClass, int iFromSpellLevel = 0, int iToSpellLevel = 9) {
	SetLocalString(oCreature, "NWNX!FUNCS!RESTOREMEMORIZEDSPELLS", IntToString(iClass)+" "+IntToString(iFromSpellLevel)+" "+IntToString(iToSpellLevel));
	DeleteLocalString(oCreature, "NWNX!FUNCS!RESTOREMEMORIZEDSPELLS");
}

int NWNXFuncs_GetFeatCount(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETFEATCOUNT", "     ");
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETFEATCOUNT"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETFEATCOUNT");
	return iRet;
}

string NWNXFuncs_GetKnownSpells(object oCreature, int iClass, int iSpellLevel, string sDelimiter=",") {
	
	if (GetStringLength(sDelimiter) > 9) return "-1";
	
	// reserve enough space for the return string
	// spacer = 256 bytes
	string sSpacer;
	int iCount = NWNXFuncs_GetKnownSpellCount(oCreature, iClass, iSpellLevel);
	iCount = (iCount*5+(iCount-1)*GetStringLength(sDelimiter))+1;
	iCount = iCount / 256 +1;
	for (iCount; iCount>0; iCount--) {
		sSpacer += "                                                                                                                                                                                                                                                                ";
	}

	SetLocalString(oCreature, "NWNX!FUNCS!GETKNOWNSPELLS", IntToString(iClass)+" "+IntToString(iSpellLevel)+" "+sDelimiter+" "+sSpacer);
	string sRet = GetLocalString(oCreature, "NWNX!FUNCS!GETKNOWNSPELLS");
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETKNOWNSPELLS");
	return sRet;
}

int NWNXFuncs_GetKnownSpellCount(object oCreature, int iClass, int iSpellLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETKNOWNSPELLCOUNT", IntToString(iClass)+ " " +IntToString(iSpellLevel));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETKNOWNSPELLCOUNT"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETKNOWNSPELLCOUNT");
	return iRet;
}

void NWNXFuncs_SetConversation(object oObject, string sConvo) {
	SetLocalString(oObject, "NWNX!FUNCS!SETCONVERSATION", sConvo);
	DeleteLocalString(oObject, "NWNX!FUNCS!SETCONVERSATION");
}

string NWNXFuncs_GetConversation(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETCONVERSATION", "                ");
	string sRet = GetLocalString(oObject, "NWNX!FUNCS!GETCONVERSATION");
	DeleteLocalString(oObject, "NWNX!FUNCS!GETCONVERSATION");
	return sRet;
}

void NWNXFuncs_SetBodyBag(object oObject, int iBodyBag) {
	SetLocalString(oObject, "NWNX!FUNCS!SETBODYBAG", IntToString(iBodyBag));
	DeleteLocalString(oObject, "NWNX!FUNCS!SETBODYBAG");
}

int NWNXFuncs_GetBodyBag(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!SETBODYBAG", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!SETBODYBAG"));
	DeleteLocalString(oObject, "NWNX!FUNCS!SETBODYBAG");
	return iRet;
}

string NWNXFuncs_GetFeatsGainedAtLevel(object oCreature, int iLevel) {
	int i=0;
	string sSpacer;
	for (i; i<4; i++) {
		sSpacer += "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	}

	SetLocalString(oCreature, "NWNX!FUNCS!GETFEATSGAINEDATLEVEL", IntToString(iLevel)+" "+sSpacer);
	string sRet = (GetLocalString(oCreature, "NWNX!FUNCS!GETFEATSGAINEDATLEVEL"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETFEATSGAINEDATLEVEL");
	return sRet;
}

string NWNXFuncs_GetSkillRanksGainedAtLevel(object oCreature, int iLevel) {
	string sSpacer = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

	SetLocalString(oCreature, "NWNX!FUNCS!GETSKILLRANKSGAINEDATLEVEL", IntToString(iLevel)+" "+sSpacer);
	string sRet = GetLocalString(oCreature, "NWNX!FUNCS!GETSKILLRANKSGAINEDATLEVEL");
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETSKILLRANKSGAINEDATLEVEL");
	return sRet;
}

string NWNXFuncs_GetSpellsGainedAtLevel(object oCreature, int iSpellLevel, int iLevel) {
	string sSpacer = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

	SetLocalString(oCreature, "NWNX!FUNCS!GETSPELLSGAINEDATLEVEL", IntToString(iLevel)+" "+IntToString(iSpellLevel)+" "+sSpacer);
	string sRet = GetLocalString(oCreature, "NWNX!FUNCS!GETSPELLSGAINEDATLEVEL");
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETSPELLSGAINEDATLEVEL");
	return sRet;
}

struct levelstats_s NWNXFuncs_GetStatsGainedAtLevel(object oCreature, int iLevel) {
	string sSpacer = "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

	SetLocalString(oCreature, "NWNX!FUNCS!GETSTATSGAINEDATLEVEL", IntToString(iLevel)+" "+sSpacer);
	string sRet = GetLocalString(oCreature, "NWNX!FUNCS!GETSTATSGAINEDATLEVEL");
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETSTATSGAINEDATLEVEL");
	
	struct levelstats_s ls;
	int iP, iStart=0;
	
	iP = FindSubString(sRet, "|", iStart);	ls.iAbility = StringToInt(GetSubString(sRet, iStart, iP-iStart)); iStart = iP+1;
	iP = FindSubString(sRet, "|", iStart);	ls.iClass = StringToInt(GetSubString(sRet, iStart, iP-iStart)); iStart = iP+1;
	iP = FindSubString(sRet, "|", iStart);	ls.iHP = StringToInt(GetSubString(sRet, iStart, iP-iStart)); iStart = iP+1;
	iP = FindSubString(sRet, "|", iStart);	ls.iSkillPoints = StringToInt(GetSubString(sRet, iStart, iP-iStart));
	
	return ls;
}

struct quickslot_s NWNXFuncs_GetQuickSlot(object oPC, int iSlot) {
	SetLocalString(oPC, "NWNX!FUNCS!GETQUICKSLOT", IntToString(iSlot)+" --------------------------------------------------------------------------------------------------------------------------------");
	string sRet = GetLocalString(oPC, "NWNX!FUNCS!GETQUICKSLOT");
	PrintString(sRet);
	DeleteLocalString(oPC, "NWNX!FUNCS!GETQUICKSLOT");

	struct quickslot_s qs;
	int iP, iStart=0;
	
	iP = FindSubString(sRet, "¬", iStart);	iStart = iP+1;
	iP = FindSubString(sRet, "¬", iStart);	qs.iType 		= StringToInt(GetSubString(sRet, iStart, iP-iStart)); iStart = iP+1;
	iP = FindSubString(sRet, "¬", iStart);	qs.iClass 		= StringToInt(GetSubString(sRet, iStart, iP-iStart)); iStart = iP+1;
	iP = FindSubString(sRet, "¬", iStart);	qs.iParam1 		= StringToInt(GetSubString(sRet, iStart, iP-iStart)); iStart = iP+1;
	iP = FindSubString(sRet, "¬", iStart);	qs.iMetaMagic 	= StringToInt(GetSubString(sRet, iStart, iP-iStart)); iStart = iP+1;
	iP = FindSubString(sRet, "¬", iStart);	
	if (iP < 0) return qs;
											qs.sS1 		= 			  GetSubString(sRet, iStart, iP-iStart) ; iStart = iP+1;
	iP = FindSubString(sRet, "¬", iStart);	qs.sS2 	= 			  GetSubString(sRet, iStart, iP-iStart) ; iStart = iP+1;
	
	return qs;	
}

void NWNXFuncs_SetQuickSlot(object oPC, int iSlot, struct quickslot_s slotData, int bUpdateGUI=TRUE) {
	string sQuickSlot = IntToString(iSlot)+" "+IntToString(slotData.iType)+" "+IntToString(slotData.iClass)	+" "+IntToString(slotData.iParam1)+" "+IntToString(slotData.iMetaMagic)+" "+IntToString(bUpdateGUI);

	switch(slotData.iType) {
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: sQuickSlot += "¬"+ slotData.sS1 +"¬"+ slotData.sS2; break;
	}
	
	PrintString(sQuickSlot);
	SetLocalString(oPC, "NWNX!FUNCS!SETQUICKSLOT", sQuickSlot);
	DeleteLocalString(oPC, "NWNX!FUNCS!SETQUICKSLOT");
}

void NWNXFuncs_UpdateQuickbarGUI(object oPC) {
	SetLocalString(oPC, "NWNX!FUNCS!UPDATEQUICKBAR", "-");
	DeleteLocalString(oPC, "NWNX!FUNCS!UPDATEQUICKBAR");
}	

void NWNXFuncs_SetClassByPosition(object oCreature, int iPosition, int iClass) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETCLASSBYPOSITION", IntToString(iPosition)+" "+IntToString(iClass));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETCLASSBYPOSITION");
}

void NWNXFuncs_SetGender(object oCreature, int iGender) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETGENDER", IntToString(iGender));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETGENDER");
}

void NWNXFuncs_SetWorldDateTime(int wtDate, int wtTime, int P3=0) {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!SETWORLDTIME", IntToString(wtDate)+" "+IntToString(wtTime)+" "+IntToString(P3));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!SETWORLDTIME");
}	

int NWNXFuncs_GetWorldDate() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETWORLDTIME", "1");
	int ret = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETWORLDTIME"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETWORLDTIME");
	return ret;
}

int NWNXFuncs_GetWorldTime() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETWORLDTIME", "0");
	int ret = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETWORLDTIME"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETWORLDTIME");
	return ret;
}

int NWNXFuncs_GetFactionID(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETFACTIONID", "-");
	int ret = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETFACTIONID"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETFACTIONID");
	return ret;
}	

void NWNXFuncs_SetFactionID(object oCreature, int iFactionID) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETFACTIONID", IntToString(iFactionID));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETFACTIONID");
}

int NWNXFuncs_GetSoundSetID(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETSOUNDSETID", "-");
	int ret = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETSOUNDSETID"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETSOUNDSETID");
	return ret;
}

void NWNXFuncs_SetSoundSetID(object oCreature, int iSoundSetID) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETSOUNDSETID", IntToString(iSoundSetID));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETSOUNDSETID");
}

int NWNXFuncs_GetSavingThrowBonus(object oCreature, int iSavingThrow = SAVING_THROW_FORT) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETSAVINGTHROWBONUS", IntToString(iSavingThrow));
	int ret = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETSAVINGTHROWBONUS"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETSAVINGTHROWBONUS");
	return ret;
}

void NWNXFuncs_JumpCreatureToLimbo(object oCreature) {
	SetLocalString(oCreature, "NWNX!FUNCS!JUMPTOLIMBO", "-");
	DeleteLocalString(oCreature, "NWNX!FUNCS!JUMPTOLIMBO");
}

void NWNXFuncs_SetClassLevel(object oCreature, int iClassPos, int iLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETCLASSLEVEL", IntToString(iClassPos)+" "+IntToString(iLevel));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETCLASSLEVEL");
}

int NWNXFuncs_GetDamageImmunity(object oCreature, int iDamageType=DAMAGE_TYPE_BLUDGEONING) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETDAMAGEIMMUNITY", IntToString(iDamageType));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETDAMAGEIMMUNITY"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETDAMAGEIMMUNITY");
	return iRet;
}

int NWNXFuncs_GetHighestEffectID(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETHIGHESTEFFECTID", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETHIGHESTEFFECTID"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETHIGHESTEFFECTID");
	return iRet;
}

void NWNXFuncs_SetEffectCreatorByEffectID(object oObject, int iEffectID, string sNewCreatorID) {
	SetLocalString(oObject, "NWNX!FUNCS!SETEFFECTCREATORBYEFFECTID", IntToString(iEffectID)+" "+sNewCreatorID);
	DeleteLocalString(oObject, "NWNX!FUNCS!SETEFFECTCREATORBYEFFECTID");
}

void NWNXFuncs_SetEffectSpellIDByEffectID(object oObject, int iEffectID, int iNewSpellID) {
	SetLocalString(oObject, "NWNX!FUNCS!SETEFFECTSPELLIDBYEFFECTID", IntToString(iEffectID)+" "+IntToString(iNewSpellID));
	DeleteLocalString(oObject, "NWNX!FUNCS!SETEFFECTSPELLIDBYEFFECTID");
}

int NWNXFuncs_GetFirstEffectInternal(object oObject, int bExposedOnly = FALSE) {
	SetLocalString(oObject, "NWNX!FUNCS!GETFIRSTALLEFFECT", IntToString(bExposedOnly));
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETFIRSTALLEFFECT"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETFIRSTALLEFFECT");
	return iRet;
}

int NWNXFuncs_GetNextEffectInternal(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETNEXTALLEFFECT", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETNEXTALLEFFECT"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETNEXTALLEFFECT");
	return iRet;
}

int NWNXFuncs_GetEffectRemainingDurationInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTREMAININGDURATION", "-");
	int sRet = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTREMAININGDURATION"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTREMAININGDURATION");
	return sRet;
}

string NWNXFuncs_GetEffectIntegersInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTINTEGERS", "-1 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	string sRet = GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTINTEGERS");
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTINTEGERS");
	return sRet;
}

int NWNXFuncs_GetEffectIntegerInternal(int nNthInteger) {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTINTEGERS", IntToString(nNthInteger));
	string sRet = GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTINTEGERS");
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTINTEGERS");
	if (GetStringLength(sRet) == 0) return -1;
	return StringToInt(sRet);
}

void NWNXFuncs_SetEffectIntegerInternal(int nNthInteger, int iIntValue) {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!SETALLEFFECTINTEGERS", IntToString(nNthInteger)+" "+IntToString(iIntValue));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!SETALLEFFECTINTEGERS");
}

int NWNXFuncs_GetEffectIDInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTID", "-");
	int iRet = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTID"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTID");
	return iRet;
}

int NWNXFuncs_GetEffectTypeInternal(int bRealType = TRUE) {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTTYPE", IntToString(bRealType));
	int iRet = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTTYPE"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTTYPE");
	return iRet;
}

int NWNXFuncs_GetEffectSubTypeInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTSUBTYPE", "-");
	int iRet = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTSUBTYPE"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTSUBTYPE");
	return iRet;
}

string NWNXFuncs_GetEffectCreatorInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTCREATOR", "-");
	string sRet = GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTCREATOR");
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTCREATOR");
	return sRet;
}

int NWNXFuncs_GetEffectSpellIdInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTSPELLID", "-");
	int iRet = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTSPELLID"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTSPELLID");
	return iRet;
}

int NWNXFuncs_GetEffectDurationTypeInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTDURATIONTYPE", "-");
	int iRet = StringToInt(GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTDURATIONTYPE"));
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETALLEFFECTDURATIONTYPE");
	return iRet;
}

void NWNXFuncs_QueueRemoveEffectInternal() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!QUEUEREMOVEEFFECT", "-");
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!QUEUEREMOVEEFFECT");
}	

void NWNXFuncs_RemoveQueuedEffectsInternal(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!REMOVEQUEUEDEFFECTS", "-");
	DeleteLocalString(oObject, "NWNX!FUNCS!REMOVEQUEUEDEFFECTS");
}

void NWNXFuncs_ApplyVisualEffectForPC(object oPC, int nVFX, vector vPos) {
	SetLocalString(oPC, "NWNX!FUNCS!APPLYVFXFORPC", IntToString(nVFX)+" "+FloatToString(vPos.x)+" "+FloatToString(vPos.y)+" "+FloatToString(vPos.z));
	DeleteLocalString(oPC, "NWNX!FUNCS!APPLYVFXFORPC");
}

string NWNXFuncs_GetEffectIntegers(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETEFFECTINTEGERS", "-1 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	string sRet = GetLocalString(oObject, "NWNX!FUNCS!GETEFFECTINTEGERS");
	DeleteLocalString(oObject, "NWNX!FUNCS!GETEFFECTINTEGERS");
	return sRet;
}

int NWNXFuncs_GetEffectInteger(object oObject, int nNthInteger) {
	SetLocalString(oObject, "NWNX!FUNCS!GETEFFECTINTEGERS", IntToString(nNthInteger));
	string sRet = GetLocalString(oObject, "NWNX!FUNCS!GETEFFECTINTEGERS");
	DeleteLocalString(oObject, "NWNX!FUNCS!GETEFFECTINTEGERS");
	if (GetStringLength(sRet) == 0) return -1;
	return StringToInt(sRet);
}

void NWNXFuncs_SetEffectInteger(object oObject, int nNthInteger, int iIntValue) {
	SetLocalString(oObject, "NWNX!FUNCS!SETEFFECTINTEGERS", IntToString(nNthInteger)+" "+IntToString(iIntValue));
	DeleteLocalString(oObject, "NWNX!FUNCS!SETEFFECTINTEGERS");
}

float NWNXFuncs_GetEffectRemainingDuration(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETEFFECTREMAININGDURATION", "------------------------------");
	float sRet = StringToFloat(GetLocalString(oObject, "NWNX!FUNCS!GETEFFECTREMAININGDURATION"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETEFFECTREMAININGDURATION");
	return sRet;
}

int NWNXFuncs_GetEffectID(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETEFFECTID", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETEFFECTID"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETEFFECTID");
	return iRet;
}

int NWNXFuncs_GetEffectRealType(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETEFFECTREALTYPE", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETEFFECTREALTYPE"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETEFFECTREALTYPE");
	return iRet;
}


void NWNXFuncs_SetCustomTrapGeometry(string sGeometry, int bAbsolute=FALSE) {
	sGeometry = IntToString(bAbsolute)+"¬"+sGeometry;
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!SETCUSTOMGEOMETRY", sGeometry);
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!SETCUSTOMGEOMETRY");
}

void NWNXFuncs_RotateCustomTrapGeometry(float fAngle) {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!ROTATECUSTOMGEOMETRY", FloatToString(fAngle)); 
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!SETCUSTOMGEOMETRY");
}

string NWNXFuncs_GetTrapGeometry(object oTrap) {
	string sSpacer = "--------------------------------------------------------------------------------------------------------------------------------";
	sSpacer += sSpacer + sSpacer + sSpacer;
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETTRIGGERGEOMETRY", sSpacer); 
	string sRet = GetLocalString(OBJECT_SELF, "NWNX!FUNCS!GETTRIGGERGEOMETRY");
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!GETTRIGGERGEOMETRY");
	return sRet;
}

int NWNXFuncs_GetSurfaceMaterial(location lLoc) {
	vector v = GetPositionFromLocation(lLoc);
	object oArea = GetAreaFromLocation(lLoc);
	SetLocalString(oArea, "NWNX!FUNCS!GETSURFACEMATERIAL", FloatToString(v.x)+" "+FloatToString(v.y)+" "+FloatToString(v.z));
	int iRet = StringToInt(GetLocalString(oArea, "NWNX!FUNCS!GETSURFACEMATERIAL"));
	DeleteLocalString(oArea, "NWNX!FUNCS!GETSURFACEMATERIAL");
	return iRet;
}

void NWNXFuncs_StartTimingbar(object oPC, int iDuration, int iLabel) {
	SetLocalString(oPC, "NWNX!FUNCS!TIMEBARSTART", IntToString(iDuration)+" "+IntToString(iLabel));
	DeleteLocalString(oPC, "NWNX!FUNCS!TIMEBARSTART");
}
	

void NWNXFuncs_StopTimingbar(object oPC) {
	SetLocalString(oPC, "NWNX!FUNCS!TIMEBARSTOP", "-");
	DeleteLocalString(oPC, "NWNX!FUNCS!TIMEBARSTOP");
}

void NWNXFuncs_SetAge(object oCreature, int iAge) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETAGE", IntToString(iAge));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETAGE");
}

void NWNXFuncs_SetTag(object oObject, string sTag) {
	SetLocalString(oObject, "NWNX!FUNCS!SETTAG", sTag);
	DeleteLocalString(oObject, "NWNX!FUNCS!SETTAG");
}

void NWNXFuncs_SetEventScript(object oObject, string sScript, int iEvent) {
	SetLocalString(oObject, "NWNX!FUNCS!SETEVENT", IntToString(iEvent)+" "+sScript);
	DeleteLocalString(oObject, "NWNX!FUNCS!SETEVENT");
}

string NWNXFuncs_GetEventScript(object oObject, int iEvent) {
	SetLocalString(oObject, "NWNX!FUNCS!GETEVENT", IntToString(iEvent)+" -----------------");
	string sRet = GetLocalString(oObject, "NWNX!FUNCS!GETEVENT");
	DeleteLocalString(oObject, "NWNX!FUNCS!GETEVENT");
	return sRet;
}

void NWNXFuncs_ClearPlayerTURDs() {
	SetLocalString(OBJECT_SELF, "NWNX!FUNCS!CLEARTURDLIST", "-");
	DeleteLocalString(OBJECT_SELF, "NWNX!FUNCS!CLEARTURDLIST");
}

void NWNXFuncs_SetClassByLevel(object oCreature, int iClass, int iLevel) {
	SetLocalString(oCreature, "NWNX!FUNCS!SETCLASSBYLEVEL", IntToString(iClass)+" "+IntToString(iLevel));
	DeleteLocalString(oCreature, "NWNX!FUNCS!SETCLASSBYLEVEL");
}

void NWNXFuncs_ReplaceClass(object oCreature, int iOldClass, int iNewClass) {
	SetLocalString(oCreature, "NWNX!FUNCS!REPLACECLASS", IntToString(iOldClass)+" "+IntToString(iNewClass));
	DeleteLocalString(oCreature, "NWNX!FUNCS!REPLACECLASS");
}

void NWNXFuncs_UpdateCharacterSheet(object oPC) {
	SetLocalString(oPC, "NWNX!FUNCS!UPDATECHARSHEET", ObjectToString(oPC));
	DeleteLocalString(oPC, "NWNX!FUNCS!UPDATECHARSHEET");
}

/*
struct gameeffect_s {
	int Type;
	string Creator;
	int SpellID;
	int NumInts;
	string Ints;
};	
*/	
effect NWNXFuncs_EffectCustomEffect(struct gameeffect_s e) {
	object o = GetModule();
	SetLocalInt(o, "NWNXFUNCS_CE", 1);
	SetLocalInt(o, "NWNXFUNCS_CE_NUMINTS", e.NumInts);
	SetLocalString(o, "NWNXFUNCS_CE_INTS", e.Ints);
	SetLocalString(o, "NWNXFUNCS_CE_EFFECT", IntToString(e.Type)+" "+e.Creator+" "+IntToString(e.SpellID));
	effect Eff = EffectAppear();
	DeleteLocalInt(o, "NWNXFUNCS_CE");
	DeleteLocalInt(o, "NWNXFUNCS_CE_NUMINTS");
	DeleteLocalString(o, "NWNXFUNCS_CE_INTS");
	DeleteLocalString(o, "NWNXFUNCS_CUSTOMEFFECT");
	
	return Eff;
}

int NWNXFuncs_GetEffectSubType(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETEFFECTDURATIONSUBTYPE", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETEFFECTDURATIONSUBTYPE"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETEFFECTDURATIONSUBTYPE");
	return iRet;
}

void NWNXFuncs_BootPCWithMessage(object oPC, int iTlkEntry) {
	SetLocalString(oPC, "NWNX!FUNCS!BOOTPCWITHMESSAGE", IntToString(iTlkEntry));
	DeleteLocalString(oPC, "NWNX!FUNCS!BOOTPCWITHMESSAGE");
}

float NWNXFuncs_GetItemPropertyDuration(itemproperty ip) {
	object oModule = GetModule();
	
	SetLocalString(oModule, "NWNX_FUNCS_IPRP", "1 0 0");
	GetItemPropertyType(ip);
	float fRet = GetLocalFloat(oModule, "NWNX_FUNCS_IPRP");
	DeleteLocalString(oModule, "NWNX_FUNCS_IPRP");
	DeleteLocalFloat(oModule, "NWNX_FUNCS_IPRP");
	
	return fRet;
}

float NWNXFuncs_GetItemPropertyDurationRemaining(itemproperty ip) {
	object oModule = GetModule();
	
	SetLocalString(oModule, "NWNX_FUNCS_IPRP", "6 0 0");
	GetItemPropertyType(ip);
	float fRet = GetLocalFloat(oModule, "NWNX_FUNCS_IPRP");
	DeleteLocalString(oModule, "NWNX_FUNCS_IPRP");
	DeleteLocalFloat(oModule, "NWNX_FUNCS_IPRP");
	
	return fRet;
}

int NWNXFuncs_GetItemPropertyInteger(itemproperty ip, int nInt) {
	object oModule = GetModule();
	
	SetLocalString(oModule, "NWNX_FUNCS_IPRP", "3 "+IntToString(nInt)+" 0");
	int iRet = GetItemPropertyType(ip);	
	DeleteLocalString(oModule, "NWNX_FUNCS_IPRP");
	
	return iRet;
}	
void NWNXFuncs_SetItemPropertyInteger(itemproperty ip, int nInt, int iValue) {
	object oModule = GetModule();
	
	SetLocalString(oModule, "NWNX_FUNCS_IPRP", "4 "+IntToString(nInt)+" "+IntToString(iValue));
	GetItemPropertyType(ip);
	DeleteLocalString(oModule, "NWNX_FUNCS_IPRP");
}

int NWNXFuncs_GetItemPropertySpellId(itemproperty ip) {
	object oModule = GetModule();
	
	SetLocalString(oModule, "NWNX_FUNCS_IPRP", "2 0 0");
	int iRet = GetItemPropertyType(ip);	
	DeleteLocalString(oModule, "NWNX_FUNCS_IPRP");
	
	return iRet;
}

void NWNXFuncs_SetItemPropertySpellId(itemproperty ip, int iSpellID) {
	object oModule = GetModule();
	
	SetLocalString(oModule, "NWNX_FUNCS_IPRP", "5 "+IntToString(iSpellID)+" 0");
	GetItemPropertyType(ip);
	DeleteLocalString(oModule, "NWNX_FUNCS_IPRP");
}

itemproperty NWNXFuncs_ItemPropertyCustom(int iType, int iSubType, int iCostTableValue, int iParam1Value) {
	object oModule = GetModule();
	SetLocalString(oModule, "NWNX_FUNCS_IPRP", IntToString(iType)+ " " +IntToString(iSubType)+ " " +IntToString(iCostTableValue)+ " " +IntToString(iParam1Value)); 
	itemproperty ip = ItemPropertyNoDamage();
	DeleteLocalString(oModule, "NWNX_FUNCS_IPRP");
	return ip;
}

void NWNXFuncs_SetVisibilityOverride(object oObject, int nVisibilityType) {
    SetLocalString(oObject, "NWNX!FUNCS!SET_VISIBILITY_OVERRIDE", IntToString(nVisibilityType));
}

void NWNXFuncs_SetVisibility(object oObject1, object oObject2, int nVisibility) {
    SetLocalString(oObject1, "NWNX!FUNCS!SET_VISIBILITY", ObjectToString(oObject2)+" "+IntToString(nVisibility));
}

int NWNXFuncs_GetVisibilityOverride(object oObject) {
    SetLocalString(oObject, "NWNX!FUNCS!GET_VISIBILITY_OVERRIDE", "'-");
    int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GET_VISIBILITY_OVERRIDE"));
    DeleteLocalString(oObject, "NWNX!FUNCS!GET_VISIBILITY_OVERRIDE");
    return iRet;
}

int NWNXFuncs_GetVisibility(object oObject1, object oObject2) {
    SetLocalString(oObject1, "NWNX!FUNCS!GET_VISIBILITY", ObjectToString(oObject2));
    int iRet = StringToInt(GetLocalString(oObject1, "NWNX!FUNCS!GET_VISIBILITY"));
    DeleteLocalString(oObject1, "NWNX!FUNCS!GET_VISIBILITY");
    return iRet;
}

int NWNXFuncs_GetRegeneration(object oCreature, int nType=REGENERATION_ALL) {
	SetLocalString(oCreature, "NWNX!FUNCS!GETREGENERATION", IntToString(nType));
	int iRet = StringToInt(GetLocalString(oCreature, "NWNX!FUNCS!GETREGENERATION"));
	DeleteLocalString(oCreature, "NWNX!FUNCS!GETREGENERATION");
	return iRet;
}

int NWNXFuncs_ImmunityOverride(int Overrides, int iImmunity) {
	if (iImmunity == 0 ) return Overrides | 1;
	return Overrides | (2 << (iImmunity -1));
}

void NWNXFuncs_SetImmunityOverride(object oCreature, int Override) {
	SetLocalInt(oCreature, "NWNXFUNCS_IMMOVERRIDE", Override);
}

void NWNXFuncs_RemoveAllImmunityOverrides(object oCreature) {
	DeleteLocalInt(oCreature, "NWNXFUNCS_IMMOVERRIDE");
}

void NWNXFuncs_AddImmunityOverride(object oCreature, int iImmunity) {
	int Override = GetLocalInt(oCreature, "NWNXFUNCS_IMMOVERRIDE");
	if (iImmunity == 0) Override |= 1;
	else Override |= 2 << (iImmunity-1);
	SetLocalInt(oCreature, "NWNXFUNCS_IMMOVERRIDE", Override);
}

/* For some reason my prc compiler doesn't like the NOT operator
void NWNXFuncs_RemoveImmunityOverride(object oCreature, int iImmunity) {
	int Override = GetLocalInt(oCreature, "NWNXFUNCS_IMMOVERRIDE");
	if (iImmunity == 0) Override = Override ~ 1;
	else Override = Override ~ (2 << (iImmunity-1));
	SetLocalInt(oCreature, "NWNXFUNCS_IMMOVERRIDE", Override);
}
*/

int NWNXFuncs_GetAutoRemoveKeyFlag(object oObject) {
	SetLocalString(oObject, "NWNX!FUNCS!GETAUTOREMOVEKEY", "-");
	int iRet = StringToInt(GetLocalString(oObject, "NWNX!FUNCS!GETAUTOREMOVEKEY"));
	DeleteLocalString(oObject, "NWNX!FUNCS!GETAUTOREMOVEKEY");
	return iRet;
}

void NWNXFuncs_SetAutoRemoveKeyFlag(object oObject, int iFlag) {
	SetLocalString(oObject, "NWNX!FUNCS!SETAUTOREMOVEKEY", IntToString(iFlag));
	DeleteLocalString(oObject, "NWNX!FUNCS!SETAUTOREMOVEKEY");
}
