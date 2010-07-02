#ifndef _NX_NWN_STRUCT_CNWSCREATUREEVENTHANDLER_
#define _NX_NWN_STRUCT_CNWSCREATUREEVENTHANDLER_

// size: 104 [0x0068]

struct CNWSCreatureEventHandler_s { 
	CExoString	onHeartbeat;  		/* 0x01F4 */
	CExoString	onPerception; 		/* 0x01FC */
	CExoString	onSpellCastAt;		/* 0x0204 */
	CExoString	onAttacked;   		/* 0x020C */
	CExoString	onDamaged;    		/* 0x0214 */
	CExoString	onDisturbed;  		/* 0x021C */
	CExoString	onEndCombat;  		/* 0x0224 */
	CExoString	onDialog;     		/* 0x022C */
	CExoString	onRested;     		/* 0x0234 */
	CExoString	onSpawn;      		/* 0x023C */
	CExoString	onDeath;      		/* 0x0244 */
	CExoString	onUserDefined;		/* 0x024C */
	CExoString	onBlocked;    		/* 0x0254 */
};

#endif /* _NX_NWN_STRUCT_CNWSCREATUREEVENTHANDLER_ */