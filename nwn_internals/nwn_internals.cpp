#include "stdafx.h"
#include ".\types.h"

// Internal function calls definitions

CAppManager **NWN_AppManager = (CAppManager**)0x0066c050;
CVirtualMachine **NWN_VirtualMachine = (CVirtualMachine**)0x0066C048;
CTlkTable **NWN_CTlkTable = (CTlkTable**)0x0066C054;
CNWTlkTable **NWN_CNWTlkTable = (CNWTlkTable**)0x0066C058;
CNWRules **NWN_Rules = (CNWRules**)0x0066c060;
CExoResMan **NWN_ResMan = (CExoResMan**)0x0066C044;


/*
void			(__fastcall *CNWSCreature__SetQuickbarButton_AssociateCommand)(CNWSCreature*, void*, uint8_t, int, uint16_t, uint32_t) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, int, uint16_t, uint32_t))0x004A8E10;
void			(__fastcall *CNWSCreature__SetQuickbarButton_CommandLine)(CNWSCreature*, void*, uint8_t, class CExoString const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CExoString const &, class CExoString const &))0x004A9100;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DM_General_ResRefParam)(CNWSCreature*, void*, uint8_t, uint8_t, CResRef const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint8_t, class CResRef const &))0x004A9160;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateCreature)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8E60;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateEncounter)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8F20;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateItem)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8EC0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePlaceable)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A90A0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreatePortal)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A9040;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateTrigger)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8FE0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_DungeonMaster_CreateWaypoint)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, class CResRef const &, class CExoString const &))0x004A8F80;
void			(__fastcall *CNWSCreature__SetQuickbarButton_GeneralINTParam)(CNWSCreature*, void*, uint8_t, uint8_t, int) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint8_t, int))0x004A91E0;
void			(__fastcall *CNWSCreature__SetQuickbarButton_GeneralNoParam)(CNWSCreature*, void*, uint8_t, uint8_t) = (void (__fastcall *)(CNWSCreature*, void*, uint8_t, uint8_t))0x004A91B0;
*/

int 			(__fastcall *CExoArrayList_uint32___Add)(void *, void *, uint32_t a2) = (int (__fastcall *)(void *, void *, uint32_t a2))0x0048F480;
void 			(__fastcall *CExoArrayList_uint32___Remove)(void *, void *, unsigned long) = (void (__fastcall *)(void *, void *, unsigned long))0x004D0D50;

void			(__fastcall *CNWMessage__CreateWriteMessage)(CNWSMessage*, void*, uint32_t, nwn_objid_t, uint32_t) = (void (__fastcall *)(CNWSMessage*, void*, uint32_t, nwn_objid_t, uint32_t))0x00507E30;
int				(__fastcall *CNWMessage__GetWriteMessage)(CNWSMessage*, void*, uint8_t**, uint64_t*) = (int (__fastcall *)(CNWSMessage*, void*, uint8_t**, uint64_t*))0x00508B80;


void (__fastcall *CNWSAreaOfEffectObject__dtor_CNWSAreaOfEffectObject)	(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005A3880;
void (__fastcall *CNWSDoor__dtor_CNWSDoor)								(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005237F0;
void (__fastcall *CNWSEncounter__dtor_CNWSEncounter)					(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005A9D80;
void (__fastcall *CNWSItem__dtor_CNWSItem)								(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x00502150;
void (__fastcall *CNWSPlaceable__dtor_CNWSPlaceable)					(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x0051E1C0;
void (__fastcall *CNWSSoundObject_dtor_CNWSSoundObject)					(void *pTHIS, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005B5BA0;
void (__fastcall *CNWSStore__dtor_CNWSStore)							(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x004645E0;
void (__fastcall *CNWSTrigger__dtor_CNWSTrigger)						(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005A63D0;
void (__fastcall *CNWSWaypoint__dtor_CNWSWaypoint)						(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x005B51B0;
void (__fastcall *CNWSCreature__dtor_CNWSCreature)						(void *pThis, void *pVOID, char) = (void (__fastcall*)(void *pThis, void *pVOID, char))0x0048FFE0;



/*
void SendFeedbackmessage(nwn_objid_t oID, char *Msg) {
	CNWSCreature *cre = CServerExoAppInternal__GetCreatureByGameObjectID((*NWN_AppManager)->app_server->srv_internal, NULL, oID);
	CNWCCMessageData *Data = (CNWCCMessageData*)malloc(52);
	CNWCCMessageData__ctor(Data, NULL);
	CExoString cstr(Msg);
	CNWCCMessageData__SetString(Data, NULL, 0, cstr);
	CNWSCreature__SendFeedbackMessage(cre, NULL, 0xCC, Data, 0);
}*/