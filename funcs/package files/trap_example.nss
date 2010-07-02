#include "nwnx_funcs"

void main() {
	//SpeakString("HELLO");
/*
	This works best being a DM
	For funs and giggles we're going to create a trap in the shape of a 5 pointed star.
	The trap is pretty large and in order to fully see it I recommend standing in the middle
	of an - at least - 8x8 area which is entirely flat (microset works pretty well)
	
	The coordinates for this are as follows:

		  X			  Y
		-2.5 		-7.79
		-8.18		0.03 
		6.63 		-4.79
		-2.55		-7.77
		6.6  		4.83 
		6.6  		-4.83
		-2.55	 	7.77 
		6.63 		4.79 
		-8.18		-0.03
		
	Why are there only 9 pairs of coordinates, when a 5 pointed star requires 10? (5 for the points pointing outward and 5 for the ones pointing inward)
	The first pair of coordinates - the origin - will be provided by the location parameter specifid in the call to CreateTrapAtLocation(...)
	The coordinates are also not absolute, but relative to each other:
	From the origin, move 2.5 to the left and 7.79 down (-2.5 / -7.79), from there move -8.18 left and 0.03 up and so on.
*/

//  Getting the coordinates into the game (NWNXFuncs_SetCustomTrapGeometry(string sGeometry))
/*	As you can see NWNXFuncs_SetCustomTrapGeometry takes a string as Parameter.
	This string is simply all the coordinates concatenated alternating x and y, and putting a ¬ (ALT+170) between each of them:
		X1¬Y1¬X2¬Y2¬...¬Xn¬Yn¬
	We also need to make sure that there's one last ¬ at the very end.
*/	

	float X1 =	-2.5  	, Y1 =	-7.79 ,
	      X2 =	-10.68	, Y2 =	-7.76 ,
	      X3 =	-4.05 	, Y3 =	-12.55,
	      X4 =	-6.6  	, Y4 =	-20.32,
	      X5 =	0.0    	, Y5 =	-15.49,
	      X6 =	6.6   	, Y6 =	-20.32,
	      X7 =	4.05  	, Y7 =	-12.55,
	      X8 =	10.68 	, Y8 =	-7.76 ,
	      X9 =	2.5   	, Y9 =	-7.79;
	      
	string sGeometry = 
		FloatToString(X1)+"¬"+FloatToString(Y1) +"¬"+
		FloatToString(X2)+"¬"+FloatToString(Y2) +"¬"+
		FloatToString(X3)+"¬"+FloatToString(Y3) +"¬"+
		FloatToString(X4)+"¬"+FloatToString(Y4) +"¬"+
		FloatToString(X5)+"¬"+FloatToString(Y5) +"¬"+
		FloatToString(X6)+"¬"+FloatToString(Y6) +"¬"+
		FloatToString(X7)+"¬"+FloatToString(Y7) +"¬"+
		FloatToString(X8)+"¬"+FloatToString(Y8) +"¬"+
		FloatToString(X9)+"¬"+FloatToString(Y9) +"¬";
		
	
	// Yes, we could have just written the string right away but it's easier to change something this way.
	
/*	Now we can call NWNXFuncs_SetCustomTrapGeometry
*/

	string s;
	object oModule = GetModule();


	NWNXFuncs_SetCustomTrapGeometry(sGeometry);
	
/*	And to actually create the trap: CreateTrapAtLocation(...)
	Remember that the location used is the origin for our star
*/


	location lLoc = GetLocation(OBJECT_SELF);
	object oTrap;
	oTrap = CreateTrapAtLocation(TRAP_BASE_TYPE_AVERAGE_FIRE, lLoc);


/*	Roation
	Using NWNXFuncs_RotateCustomTrapGeometry it is possible to apply a simple rotation to the coordinates.
	The coordinates are always rotated around the origin
*/

	//NWNXFuncs_SetCustomTrapGeometry(sGeometry); // set the same coordinates again
	//NWNXFuncs_RotateCustomTrapGeometry(180.0); // clockwise rotation of 90 degrees

	//oTrap = CreateTrapAtLocation(TRAP_BASE_TYPE_AVERAGE_FIRE, lLoc);
	
/*	You should now have 2 star shaped traps connected by one their points
*/

}