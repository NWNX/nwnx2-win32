#pragma once

#include "types.h"
#include "nwn_const.h"

class CFuncUtility {
protected:
	CNWSStats_Level *GetLevelStats (const CNWSCreatureStats *stats, int level);
};
