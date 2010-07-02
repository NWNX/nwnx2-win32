struct NWN_EFFECT_TYPE_ATTACK_INCREASE_s {
	unsigned int AttackBonus;
	unsigned int AttackHand;
	unsigned int Race;					// 28 for any race
	unsigned int AlignmentLawChaos;
	unsigned int AlignmentGoodEvil;
};

// Same as Attack Increase really, except that scriptwise you cannot select any of the race or alignment features
struct NWN_EFFECT_TYPE_ATTACK_DECREASE_s {
	unsigned int AttackBonus;
	unsigned int AttackHand;
	unsigned int Race;					// 28 for any race
	unsigned int AlignmentLawChaos;
	unsigned int AlignmentGoodEvil;
};