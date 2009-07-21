#include "typedefs.h"

#ifndef NWNXStructures_h_
#define NWNXStructures_h_

// TODO: Migrate Windows codebase over to full set of support code from Linux
// For now, we'll just steal a few structs that we need...

struct CExoString_s;                      typedef struct CExoString_s                      CExoString;
struct CNWObjectVarListElement_s;         typedef struct CNWObjectVarListElement_s         CNWObjectVarListElement;
struct CNWObjectVarList_s;                typedef struct CNWObjectVarList_s                CNWObjectVarList;
struct CNWSCreature_s;                    typedef struct CNWSCreature_s                    CNWSCreature;
struct CNWSCreatureStats_s;               typedef struct CNWSCreatureStats_s               CNWSCreatureStats;

struct CExoString_s
{
	char* Text;
	dword Length;
};

struct CNWObjectVarListElement_s
{
    CExoString  sVarName;
    dword       nVarType;
    dword       nVarValue;
};

struct CNWObjectVarList_s
{
	CNWObjectVarListElement* VarList;
	dword                    VarCount;
};

struct CNWSCreature_s {
    uint8_t fields1[0xB38];
    nwn_objid_t                 cre_master_id;          /* 0B38 */
    uint8_t fields2[0x128];
    CNWSCreatureStats* cre_stats;              /* 0C64 */
};

struct CNWSCreatureStats_s {

	uint32_t fields1[0x1d];
    uint32_t                    cs_is_pc;               /* 0074 */
    uint32_t                    cs_is_dm;               /* 0078 */
};


#endif
