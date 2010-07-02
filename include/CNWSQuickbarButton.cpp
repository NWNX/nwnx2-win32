#include "stdafx.h"
#include "nwnx_funcs2.h"
#include "CNWSQuickbarButton.h"

extern CNWNXFuncs2 NWNFuncs2;

#define log(a,b,...) if(a<=NWNFuncs2.debugLevel)NWNFuncs2.LOG(b,__VA_ARGS__)

CNWSQuickbarButton_s::CNWSQuickbarButton_s() {
	qb_objid1 = 0x7F000000;
	qb_objid2 = 0x7F000000;
	qb_type = 0;
	qb_class = 0;
	for (int i=0; i<18; i++) qb_resref[i] = '\n';
	qb_label = NULL;
	qb_command = NULL;
	qb_label2 = NULL;
	qb_id = 0;
	qb_metamagic = 0;
	field_3C = 0;
}

CNWSQuickbarButton_s::~CNWSQuickbarButton_s() {
	log(3, "~CNWSQuickbarButton_s: %08X\n", this);
	//qb_label.~CExoString_s();
	//qb_command.~CExoString_s();
	//qb_label2.~CExoString_s();
}

CNWSQuickbarButton_s &CNWSQuickbarButton_s::operator=(CNWSQuickbarButton_s &qb) {
	qb_type			= qb.qb_type;

	// selectively copy new stuff, depending on type (ugh), because nwn only changes the necessary fields
	// and we wanna save some space when saving this mess
	switch(qb.qb_type) {
		case 0: case 6: case 7: case 19: case 20: case 21: case 22: case 23: 
		case 24: case 25: case 35: case 36: case 38: case 40: case 41: // 0 Params
			log(3, "CNWSQuickbarButton_s::operator= (0 Params): %08X\n", this);
			qb_objid1		= 0x7F000000;
			qb_objid2		= 0x7F000000;
			qb_class		= 0;
			qb_id			= 0;
			qb_metamagic	= 0;
			field_3C		= 0;
			qb_label = NULL;
			qb_command = NULL;
			qb_label2 = NULL;
		break;
		case 3: case 4: case 8: case 10: case 27: case 28: case 31: case 32: 
		case 33: case 34: case 42: case 45: case 46: case 47: case 48: // 1 Param
			log(3, "CNWSQuickbarButton_s::operator= (1 Params): %08X\n", this);
			qb_id = qb.qb_id;

			qb_objid1		= 0x7F000000;
			qb_objid2		= 0x7F000000;
			qb_class		= 0;
			qb_metamagic	= 0;
			field_3C		= 0;
			qb_label = NULL;
			qb_command = NULL;
			qb_label2 = NULL;
		break;
		case 2: case 44: //spell, spell like ability
			log(3, "CNWSQuickbarButton_s::operator= (spell/spell like): %08X\n", this);
			qb_class	 = qb.qb_class;
			qb_id		 = qb.qb_id;
			qb_metamagic = qb.qb_metamagic;

			qb_objid1		= 0x7F000000;
			qb_objid2		= 0x7F000000;
			field_3C		= 0;
			qb_label = NULL;
			qb_command = NULL;
			qb_label2 = NULL;
		break;
		case 18: //macro
			log(3, "CNWSQuickbarButton_s::operator= (macro): %08X\n", this);
			qb_label	= qb.qb_label;
			qb_command	= qb.qb_command;

			qb_objid1		= 0x7F000000;
			qb_objid2		= 0x7F000000;
			qb_class		= 0;
			qb_id			= 0;
			qb_metamagic	= 0;
			field_3C		= 0;
			qb_label2 = NULL;
		break;
		case 11: case 12: case 13: case 14: case 15: case 16: case 17: //dm creator stuff
			log(3, "CNWSQuickbarButton_s::operator= (resref): %08X\n", this);
			qb_label2		= qb.qb_label2;
			for (int i=0; i<17; i++) qb_resref[i] = qb.qb_resref[i];

			qb_objid1		= 0x7F000000;
			qb_objid2		= 0x7F000000;
			qb_class		= 0;
			qb_id			= 0;
			qb_metamagic	= 0;
			field_3C		= 0;
			qb_label = NULL;
			qb_command = NULL;
		break;
		case 1: // items; just for the sake of it, can't save this permanently(yet)
			log(3, "CNWSQuickbarButton_s::operator= (items): %08X\n", this);
			qb_objid1 = qb.qb_objid1;
			qb_objid2 = qb.qb_objid2;
			qb_id = qb.qb_id;			//this saves the cast spell properties of an item

			qb_label = NULL;
			qb_command = NULL;
			qb_label2 = NULL;
		break;
		default:
			log(3, "CNWSQuickbarButton_s::operator= (default): %08X\n", this);
		break;

	}

	return *this;
}