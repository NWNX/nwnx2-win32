#ifndef _NX_NWN_TYPES_H_
#define _NX_NWN_TYPES_H_

#include ".\nwnx_funcs_const.h"
#include ".\CExoString.h"

struct CVirtualMachineCommands_s;			typedef struct CVirtualMachineCommands_s		CVirtualMachineCommands;
struct CNWSObjectActionNode_s;				typedef struct CNWSObjectActionNode_s			CNWSObjectActionNode;
struct CCodeBase_s;							typedef struct CCodeBase_s						CCodeBase;
struct CResource_s;							typedef struct CResource_s						CResource; 
struct CTwoDimArrays_s;						typedef struct CTwoDimArrays_s					CTwoDimArrays;
struct C2DA_s;								typedef struct C2DA_s							C2DA; 
struct CExoArrayList_float_s;             	typedef struct CExoArrayList_float_s            CExoArrayList_float;
struct CExoArrayList_int32_s;             	typedef struct CExoArrayList_int32_s            CExoArrayList_int32;
struct CExoArrayList_int8_s;              	typedef struct CExoArrayList_int8_s             CExoArrayList_int8;
struct CExoArrayList_ptr_s;               	typedef struct CExoArrayList_ptr_s              CExoArrayList_ptr;
struct CExoArrayList_uint16_s;            	typedef struct CExoArrayList_uint16_s           CExoArrayList_uint16;
struct CExoArrayList_uint32_s;            	typedef struct CExoArrayList_uint32_s           CExoArrayList_uint32;
struct CExoArrayList_uint64_s;            	typedef struct CExoArrayList_uint64_s           CExoArrayList_uint64;
struct CExoArrayList_uint8_s;             	typedef struct CExoArrayList_uint8_s            CExoArrayList_uint8; 
struct CResRef_s;							typedef struct CResRef_s						CResRef;
struct CResGFF_s;							typedef struct CResGFF_s						CResGFF;
struct Vector_s;							typedef struct Vector_s                         Vector;
struct CNWClass_s;							typedef struct CNWClass_s						CNWClass;
struct CScriptEvent_s;						typedef struct CScriptEvent_s					CScriptEvent;
struct CNWCCMessageData_s;					typedef struct CNWCCMessageData_s				CNWCCMessageData;
struct CNWSFaction_s;						typedef struct CNWSFaction_s                    CNWSFaction;
struct CFactionManager_s;					typedef struct CFactionManager_s                CFactionManager;
//class CExoString_s; typedef CExoString_s CExoString;
//struct CExoLinkedListHeader_s;				typedef struct CExoLinkedListHeader_s           CExoLinkedListHeader;
//struct CExoLinkedListNode_s;				typedef struct CExoLinkedListNode_s             CExoLinkedListNode;
class CExoLinkedList_s;					typedef CExoLinkedList_s                 CExoLinkedList;
//struct CExoLocStringElement_s;				typedef struct CExoLocStringElement_s           CExoLocStringElement;
class  CExoLocString_s;						typedef CExoLocString_s                  		CExoLocString; 
struct CNWSpell_s;							typedef CNWSpell_s								CNWSpell;
struct CNWSpellArray_s;						typedef CNWSpellArray_s							CNWSpellArray;
struct CNWSAreaOfEffectObject_s;          typedef struct CNWSAreaOfEffectObject_s          CNWSAreaOfEffectObject; 
struct CNWSSoundObject_s;                 typedef struct CNWSSoundObject_s                 CNWSSoundObject; 
struct CNWSWaypoint_s;                    typedef struct CNWSWaypoint_s                    CNWSWaypoint; 
struct CNWSEncounter_s;                   typedef struct CNWSEncounter_s                   CNWSEncounter; 
struct CNWSSoundObject_s;                 typedef struct CNWSSoundObject_s                 CNWSSoundObject; 
struct CNWSStore_s;                       typedef struct CNWSStore_s                       CNWSStore; 
struct CNWSPlayerCharSheetGUI_s;			typedef struct CNWSPlayerCharSheetGUI_s			CNWSPlayerCharSheetGUI;
struct CNWSClient_s;						typedef struct CNWSClient_s						CNWSClient;
struct CNWSPlayer_s;                      typedef struct CNWSPlayer_s                      CNWSPlayer;
struct CNWSPlayerTURD_s;					typedef struct CNWSPlayerTURD_s					CNWSPlayerTURD;
struct CServerAIMaster_s;                 typedef struct CServerAIMaster_s                 CServerAIMaster; 
struct CWorldTimer_s;                     typedef struct CWorldTimer_s                     CWorldTimer; 
struct CServerExoApp_s;                   typedef struct CServerExoApp_s                   CServerExoApp;
struct CServerExoAppInternal_s;           typedef struct CServerExoAppInternal_s           CServerExoAppInternal;
struct CNWBaseItem_s;						typedef CNWBaseItem_s							CNWBaseItem;
struct CNWBaseItemArray_s;					typedef CNWBaseItemArray_s						CNWBaseItemArray;
struct CExoResMan_s;						typedef CExoResMan_s							CExoResMan;
struct CTlkTable_s;							typedef CTlkTable_s								CTlkTable;
struct CNWTlkTable_s;						typedef CNWTlkTable_s							CNWTlkTable;
struct CNWRules_s;							typedef struct CNWRules_s						CNWRules;
struct CNetLayer_s;                       typedef struct CNetLayer_s                       CNetLayer;
struct CAppManager_s;                     typedef struct CAppManager_s                     CAppManager;
struct CScriptLocation_s;                 typedef struct CScriptLocation_s                 CScriptLocation; 
struct CScriptVariable_s;					typedef struct CScriptVariable_s				CScriptVariable;
struct CNWSCombatAttackData_s;            typedef struct CNWSCombatAttackData_s            CNWSCombatAttackData;
struct CNWSCombatRound_s;                 typedef struct CNWSCombatRound_s                 CNWSCombatRound; 
struct CNWSScriptVarTable_s;				typedef struct CNWSScriptVarTable_s				CNWSScriptVarTable;
class CNWSQuickbarButton_s;				typedef CNWSQuickbarButton_s				CNWSQuickbarButton;
struct CNWSStats_Spell_s;					typedef struct CNWSStats_Spell_s				CNWSStats_Spell;
struct CNWSStats_Level_s;					typedef struct CNWSStats_Level_s				CNWSStats_Level;
struct CCombatinformation_s;				typedef struct CCombatinformation_s				CCombatinformation;
struct CNWSCreatureEventHandler_s;			typedef struct CNWSCreatureEventHandler_s		CNWSCreatureEventHandler;
struct CGameEffect_s;						typedef struct CGameEffect_s                    CGameEffect; 
struct CGameObject_VTable_s;              	typedef struct CGameObject_VTable_s             CGameObject_VTable;
struct CItemRepository_s;                 typedef struct CItemRepository_s                 CItemRepository;
struct CLastUpdateObject_s;               typedef struct CLastUpdateObject_s               CLastUpdateObject;
struct CNWSObject_s;						typedef struct CNWSObject_s                     CNWSObject; 
struct CNWSItemProperty_s;                 	typedef struct CNWSItemProperty_s               CNWSItemProperty; 
struct CNWSInventory_s;                     typedef struct CNWSInventory_s                   CNWSInventory; 
struct CNWSItemPropertyHandler_s;			typedef struct CNWSItemPropertyHandler_s		CNWSItemPropertyHandler;
struct CNWSItem_s;                          typedef struct CNWSItem_s                       CNWSItem; 
struct CNWTile_s;							typedef struct CNWTile_s						CNWTile;
struct CNWSTile_s;							typedef struct CNWSTile_s						CNWSTile;
struct CNWSArea_s;							typedef struct CNWSArea_s						CNWSArea;
struct CNWMessage_s;                     	typedef struct CNWMessage_s                     CNWMessage;
struct CNWSMessage_s;                     	typedef struct CNWSMessage_s                     CNWSMessage;
struct CGameObjectArrayElement_s;			typedef struct CGameObjectArrayElement_s		CGameObjectArrayElement;
struct CGameObjectArray_s;					typedef struct CGameObjectArray_s				CGameObjectArray;
struct CLookupTableObject_s;				typedef struct CLookupTableObject_s				CLookupTableObject;
struct CNWSModule_s;						typedef struct CNWSModule_s						CNWSModule;
struct CNWSDoor_s;                        	typedef struct CNWSDoor_s                       CNWSDoor; 
struct CNWSTrigger_s;                     	typedef struct CNWSTrigger_s                    CNWSTrigger; 
struct CNWSPlaceable_s;                   	typedef struct CNWSPlaceable_s                  CNWSPlaceable; 
struct CGenericObject_s;					typedef struct CGenericObject_s					CGenericObject;
struct CNWSCreatureAppearanceInfo_s;      	typedef struct CNWSCreatureAppearanceInfo_s     CNWSCreatureAppearanceInfo;
struct CNWSCreatureClass_s;               	typedef struct CNWSCreatureClass_s              CNWSCreatureClass;
struct CNWSCreatureStats_s;               	typedef struct CNWSCreatureStats_s              CNWSCreatureStats;
struct CNWSCreature_s;                    	typedef struct CNWSCreature_s                   CNWSCreature; 
class CQuickbarExtension;
struct CVirtualMachine_s;                 typedef struct CVirtualMachine_s                 CVirtualMachine;
struct CNWVisibilityNode_s;					typedef struct CNWVisibilityNode_s				CNWVisibilityNode;

struct CEffectsStore_s {
	nwn_objid_t objid;
	uint16_t len;
	uint32_t *pEffect; //this really is just a list of pointers.
};

struct CEffectsStore_s; typedef struct CEffectsStore_s CEffectsStore;


#include ".\CExoArrayList.h"
#include ".\Vector.h"
#include ".\CExoLinkedList.h"
//#include ".\CExoString.h"
//#include ".\CExoLinkedListHeader.h"
//#include ".\CExoLinkedListNode.h" 
//#include ".\CExoLocStringElement.h" 
#include ".\CExoLocString.h"
#include ".\CScriptLocation.h"
#include ".\CScriptVariable.h"
#include ".\CNWSMessage.h"
#include ".\CNWMessage.h"
#include ".\CNWBaseItem.h"
#include ".\CNWSQuickbarButton.h"
#include ".\CNWSCreatureEventHandler.h"
#include ".\CNWSScriptVarTable.h"
#include ".\CGameObject_VTable.h"
#include ".\CGenericObject.h"
#include ".\CNWSObject.h"
#include ".\CNWSDoor.h"
#include ".\CNWSTrigger.h"
#include ".\CNWSPlaceable.h"
#include ".\CNWSPlayer.h"
#include ".\CServerAIMaster.h" 
#include ".\CServerExoApp.h"
#include ".\CServerExoAppInternal.h"
#include ".\CNetLayer.h"
#include ".\CNWBaseItemArray.h"
#include ".\CNWRules.h"
#include ".\CAppManager.h"
#include ".\CNWSAreaOfEffectObject.h"
#include ".\CNWSWaypoint.h"
#include ".\CNWSEncounter.h"
#include ".\CNWSStore.h"
#include ".\CNWSSoundObject.h"
#include ".\CNWSItemProperty.h"
#include ".\CNWSItemPropertyHandler.h"
#include ".\CNWSInventory.h"
#include ".\CNWSItem.h"
#include ".\CNWSCreature.h"
#include ".\CNWSStats_Spell.h"
#include ".\CNWSStats_Level.h"
#include ".\CNWSCreatureClass.h" 
#include ".\CNWSCreatureStats.h"
#include ".\CGameEffect.h"
#include ".\CItemRepository.h" 
#include ".\CLastUpdateObject.h"
#include ".\CNWSArea.h"
#include ".\CNWSModule.h"
#include ".\CWorldTimer.h"
#include ".\CQuickbarExtension.h"
#include ".\CVirtualMachine.h"
#include ".\CNWVisibilityNode.h"
#include ".\CNWSCombatAttackData.h"
#include ".\CNWSCombatRound.h" 
#include ".\CGameObjectArrayElement.h"
#include ".\CGameObjectArray.h"
#include ".\CNWTlkTable.h"
#include ".\CTlkTable.h"
#include ".\CResRef.h"
#include ".\CExoResMan.h"
#include ".\CLookupTableObject.h"
#include ".\CNWSClient.h"
#include ".\CNWCCMessageData.h"
#include ".\CNWSTile.h"
#include ".\CNWTile.h"
#include ".\CFactionManager.h"
#include ".\CNWSFaction.h"
#include ".\CCombatinformation.h"
#include ".\CNWSPlayerTURD.h"
#include ".\CResource.h"
#include ".\C2DA.h"
#include ".\CNWSPlayerCharSheetGUI.h"
#include ".\CTwoDimArrays.h"
#include ".\CScriptEvent.h"
#include ".\CNWSpell.h"
#include ".\CNWClass.h"
#include ".\CNWSpellArray.h"
#include ".\CResGFF.h"
#include ".\CCodeBase.h"
#include ".\CNWSObjectActionNode.h"
#include ".\CVirtualMachineCommands.h"

#include ".\nwn_internals.h"

#endif /* _NX_NWN_TYPES_H_ */