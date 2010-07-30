#ifndef _H_CNWSPLAYERCHARSHEETGUI_H_
#define _H_CNWSPLAYERCHARSHEETGUI_H_

struct CNWSPlayerCharSheetGUI_s {
	void *data;
	
	uint32_t ComputeCharacterSheetUpdateRequired(CNWSPlayer *Player);
};

#endif