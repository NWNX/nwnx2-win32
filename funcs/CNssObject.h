#pragma once
#include "CFuncLookup.h"

class CNssObject : public CFuncLookup {
public:
	CNssObject(void);

private: //helper functions
	int GetEventScriptInfo(int &ScriptNumber, std::string &ScriptName, int Max, char *Params);

public: //script functions
	int GetDamageImmunity(CGameObject *oObject, char *Params);
	int GetRegeneration(CGameObject *oObject, char *Params);
	int SetTag(CGameObject *oObject, char *Params);
	int SetEvent(CGameObject *oObject, char *Params);
	int GetEvent(CGameObject *oObject, char *Params);
	int SetConversation(CGameObject *oObject, char *Params);
	int GetConversation(CGameObject *oObject, char *Params);
	int SetBodyBag(CGameObject *oObject, char *Params);
	int GetBodyBag(CGameObject *oObject, char *Params);
	int SetFactionID(CGameObject *oObject, char *Params);
	int GetFactionID(CGameObject *oObject, char *Params);

};
