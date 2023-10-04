#pragma once

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

__stdcall int MagicBullets(int *param_1,int *param_2);
__stdcall int D2Common_Patch_58470(int param_1);
__thiscall int D2Common_Patch_58640(void * __this, int param_1);
__stdcall void D2Common_Patch_421c0(int *param_1, unsigned int param_2, int param_3); // Related to identify items
__stdcall int Hirelings_ITEMS_CheckItemTypeId(int* pItem, unsigned int nItemType);