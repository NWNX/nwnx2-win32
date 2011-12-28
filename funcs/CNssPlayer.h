#pragma once
#include "CFuncLookup.h"

class CNssPlayer : public CFuncLookup {
public:
	CNssPlayer(void);

private: //helper functions
	void CNssPlayer::UpdateQuickBar(CGameObject* obj);

public: //script functions
	int SetQuickSlot(CGameObject *oObject, char *Params);
	int GetQuickSlot(CGameObject *oObject, char *Params);
	int UpdateQuickbar(CGameObject *oObject, char *Params);
	int TimebarStart(CGameObject *oObject, char *Params);
	int TimebarStop(CGameObject *oObject, char *Params);
	int UpdateCharSheet(CGameObject *oObject, char *Params);
	int PossessCreature(CGameObject *oObject, char *Params);
	int BootPCWithMessage(CGameObject *oObject, char *Params);

};
