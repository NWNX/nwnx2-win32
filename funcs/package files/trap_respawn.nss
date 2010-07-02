#include "nwnx_funcs"

void main() {
	// Respawn the trap after it has been triggered or disarmed
	
	// This is the OnTrapTriggered and OnTrapDisarmed script
	// For sake of simplicity  it is used for both events
	// For the same reason there is no code for actual trap
	// damage (and saving throws and whatnot)
	
	//Get the coordinates of the trap geometry
	string sCoords = NWNXFuncs_GetTrapGeometry(OBJECT_SELF);
	
	if (sCoords != "") {

		//Since the trap object is destroyed when triggered or disarmed
		//a simple DelayCommand doesn't work.
		//That's why we use the area itself to save the coordinates and
		//to spawn the trap back in.
	
		//Save the coordinates on the area
		object oArea = GetArea(OBJECT_SELF);
		SetLocalString(oArea, "COORDS", sCoords);
		SetLocalInt(oArea, "TrapBaseType", GetTrapBaseType(OBJECT_SELF));
		// Unless the trap is a standard one from the palette we should
		// save all the other trap information here as well (DCs, OneShot, etc)
	
		
		//The following script will take care of spawning the trap back in
		ExecuteScript("trap_area_respwn", GetArea(OBJECT_SELF));
	}	
}