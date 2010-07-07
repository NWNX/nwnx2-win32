#ifndef ___NX_NWN_FUNC_INTERNALS__
#define ___NX_NWN_FUNC_INTERNALS__

extern CAppManager **NWN_AppManager;
extern CVirtualMachine **NWN_VirtualMachine;
extern CTlkTable **NWN_CTlkTable;
extern CNWTlkTable **NWN_CNWTlkTable;
extern CNWRules **NWN_Rules;
extern CExoResMan **NWN_ResMan;

//void SendFeedbackmessage(nwn_objid_t oID, char *Msg);

extern int 					(__fastcall *CExoArrayList_uint32___Add)(void *, void *, uint32_t a2);
extern void 				(__fastcall *CExoArrayList_uint32___Remove)(void *, void *, unsigned long);

extern void					(__fastcall *CNWMessage__CreateWriteMessage)(CNWSMessage*, void*, uint32_t, nwn_objid_t, uint32_t);
extern int					(__fastcall *CNWMessage__GetWriteMessage)(CNWSMessage*, void*, uint8_t**, uint64_t*);

// scalar and vector(if existing) deleting destructors
extern void (__fastcall *CNWSCreature__dtor_CNWSCreature)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSItem__dtor_CNWSItem)								(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSTrigger__dtor_CNWSTrigger)							(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSPlaceable__dtor_CNWSPlaceable)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSDoor__dtor_CNWSDoor)								(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSAreaOfEffectObject__dtor_CNWSAreaOfEffectObject)	(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSWaypoint__dtor_CNWSWaypoint)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSEncounter__dtor_CNWSEncounter)						(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSStore__dtor_CNWSStore)								(void *pTHIS, void *pVOID, char);
extern void (__fastcall *CNWSSoundObject_dtor_CNWSSoundObject)					(void *pTHIS, void *pVOID, char);


#endif