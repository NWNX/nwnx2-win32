#include "stdafx.h"
#include "CFuncUtility.h"

CNWSStats_Level *CFuncUtility::GetLevelStats (const CNWSCreatureStats *stats, int level) {
    if (level < 1 || level > stats->cs_levelstat.len)
        return NULL;

    return (CNWSStats_Level*)stats->cs_levelstat.data[level - 1];
}
