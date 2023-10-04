#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "constants/D2ItemStatCosts.h"
#include "constants/D2Missiles.h"

#include "D2Common/D2Item.h"

__stdcall int MagicBullets(int *param_1,int *param_2)
{
    if (param_1 == nullptr) {
        return 0;
    }

    int rc;

    rc = D2COMMON_HasItemProperty(param_1, ISC_MAGIC_ARROW, 0);
    if (rc)
    {
        if (param_2 != nullptr)
        {
            *param_2 = rc;
        }

        return MISSILE_MAGIC_ARROW;
    }

    rc = D2COMMON_HasItemProperty(param_1, ISC_EXPLODING_ARROW, 0);
    if (rc)
    {
        if (param_2 != nullptr)
        {
            *param_2 = rc;
        }

        return MISSILE_EXPLODING_ARROW;
    }

    rc = D2COMMON_HasItemProperty(param_1, ISC_PUS_BOLT, 0);
    if (rc)
    {
        if (param_2 != nullptr)
        {
            *param_2 = rc;
        }

        return 192;
    }


    return MISSILE_BOLT;
}