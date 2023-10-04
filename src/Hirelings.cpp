#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "D2Common/D2Item.h"

__stdcall int Hirelings_ITEMS_CheckItemTypeId(int* pItem, unsigned int nItemType)
{
    // return 1;

    // TODO: Would be ideal to load this from an external file.
    if (nItemType != 0x1B) // Check for bows only applies to Act 1 Hireling
    {
        return D2COMMON_ITEMS_CheckItemTypeId(pItem, nItemType);
    }

    int rc = D2COMMON_ITEMS_CheckItemTypeId(pItem, 44); // Javelin

    if (rc == 0)
    {
        return D2COMMON_ITEMS_CheckItemTypeId(pItem, 2); // Shield
    } else {
        return rc;
    }
}