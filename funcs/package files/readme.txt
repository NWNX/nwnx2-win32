INSTALLATION INSTRUCTIONS

	- Copy nwnx_funcs.dll into your main Neverwinter Nights folder (e.g.: "C:\Program Files\Neverwinter Nights\"
	
	- Add nwnx_funcs.nss to your module (or include directory)
	
	- Add the following lines to your nwnx.ini
		[FUNCS]
		;Number_of_Skills, the amount of skills from skills.2da (last row+1)
		Number_of_Skills=28

		;debugLevel: 1 should only show basic information, 2 should include errors and 3 should log pretty much everything
		debugLevel=0

		;Set this to 1 to use the CustomTrapGeometry functions
		HOOK_CustomTrapGeometry=1

		;Hook for a new OnPlayerLeave event which runs before OnClientLeave
		;Makes it possible to retrieve information about the player object as usual (GetName, GetArea, etc)
		;In the onplayerleaving script, OBJECT_SELF is the player object about to leave
		HOOK_OnPlayerLeaving=1
		OnPlayerLeavingScript=onplayerleaving


Dll compiled with Visual C++ 2008 Express