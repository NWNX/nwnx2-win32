#include "nwnx_funcs"

void DoEffectsStuff(object oPC) {
	effect e = GetFirstEffect(oPC);	
	while (GetIsEffectValid(e)) {
		//Get the remaining duration of the effect
		float fRemainingDuration = NWNXFuncs_GetEffectRemainingDuration(oPC);
		PrintString("\nDuration left: "+FloatToString(fRemainingDuration)+" ms");
		
		if (GetEffectType(e) == EFFECT_TYPE_ABILITY_INCREASE) {
			// We know the effect increases an ability, but we also want to know which one, and by how much
			int iAbility = NWNXFuncs_GetEffectInteger(oPC, 0);
			int iIncrease = NWNXFuncs_GetEffectInteger(oPC, 1);
			PrintString("EffectAbilityIncrease increased Ability #" +IntToString(iAbility)+ " by "+IntToString(iIncrease));
			
			//Add 4 more to the increase, just because
			NWNXFuncs_SetEffectInteger(oPC, 1, iIncrease+4);
		}
		else if (GetEffectType(e) == EFFECT_TYPE_VISUALEFFECT) {
			//find out which vfx was applied
			int iVFX = NWNXFuncs_GetEffectInteger(oPC, 0);
			PrintString("EffectVisualEffect uses vfx #"+IntToString(iVFX));
			
			// schedule the shadow shield visual for removal
			RemoveEffect(oPC, e);
		}		
		e = GetNextEffect(oPC);
	}
}

// effect loop, getting additional information from effects and effect removal
void Example1() {
	object oPC = OBJECT_SELF;
	ForceRest(oPC);

	//Apply some effects first
	ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectAbilityIncrease(ABILITY_CONSTITUTION, 5), oPC, 30.0);
	ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectVisualEffect(VFX_DUR_PROT_SHADOW_ARMOR), oPC, 20.0);
	ApplyEffectToObject(DURATION_TYPE_TEMPORARY, EffectVisualEffect(VFX_DUR_PROT_PREMONITION), oPC, 20.0);
	
	DelayCommand(3.0, DoEffectsStuff(oPC)); // We use DelayCommand so that GetEffectRemainingDuration doesn't return the original duration right away
}

void ChangeEffectCreator(object oPC) {
	object oItem = GetItemInSlot(INVENTORY_SLOT_RIGHTHAND, oPC);
	if (!GetIsObjectValid(oItem)) {
		FloatingTextStringOnCreature("Please quip an item in the right hand.", oPC);
		return;
	}
	
	string soID = ObjectToString(oItem);
	int sEffectID = NWNXFuncs_GetHighestEffectID(oPC); // this should be the id of the effects from fox's cunning
	
	NWNXFuncs_SetEffectCreatorByEffectID(oPC, sEffectID, soID); // change the creator of the fox's cunning effects to the item
	
	// Now, if the item is unequipped all the effects will disappear
	
}

// Changing Effect Creators (how to turn effets into item properties)
// this example requires an equipped item in the right hand
void Example2() {
	object oPC = OBJECT_SELF;
	ForceRest(oPC);
	// cast Fox's Cunning on self
	ActionCastSpellAtObject(SPELL_FOXS_CUNNING, oPC, METAMAGIC_ANY, TRUE);
	ActionDoCommand(ChangeEffectCreator(oPC));
}

// uncomment the example you want to run
// don't do both at the same time
void main() {
	//Example1();
	Example2();
	
}