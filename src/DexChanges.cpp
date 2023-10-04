#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


// Changes number of available stat points, skill points, defense & max durability of equipment for both player & merc????
__stdcall int D2Common_Patch_58470(int param_1)
{
    return 100;
}

// Covers just about a hundred different stats. Probably also covers getting dex though.
__thiscall int D2Common_Patch_58640(void * __this, int param_1)
{
    return 100;
}

// Related to identifiying items
// Probably something I'm issing
__stdcall void D2Common_Patch_421c0(int *param_1,unsigned int param_2,int param_3)
{
  int iVar1;
  param_2 = 0x1;
  
  /* 0x421c0  10876   */
  if (((param_1 != (int *)0x0) && (*param_1 == 4)) && (iVar1 = param_1[5], iVar1 != 0)) {
    if (param_3 != 0) {
      *(unsigned int *)(iVar1 + 0x18) = *(unsigned int *)(iVar1 + 0x18) | param_2;
      return;
    }
    *(unsigned int *)(iVar1 + 0x18) = *(unsigned int *)(iVar1 + 0x18) & ~param_2;
  }
  return;
}

// BOOL __stdcall INVENTORY_HasBodyArmorEquipped(D2InventoryStrc* pInventory)
// {
// 	if (INVENTORY_GetPtrIfValid(pInventory))
// 	{
// 		D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
// 		if (pInventoryGrid && pInventoryGrid->ppItems[BODYLOC_TORSO])
// 		{
// 			return ITEMS_CheckItemTypeId(pInventoryGrid->ppItems[BODYLOC_TORSO], ITEMTYPE_ARMOR) != 0;
// 		}
// 	}

// 	return FALSE;
// }

// BOOL __stdcall INVENTORY_GetEquippedArmor(D2InventoryStrc * pInventory, D2UnitStrc ** ppItem)
// {
//     // It's going to be annoying to get the pInventory from the pUnit anyways... *sigh*
//     D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
// 	D2UnitStrc* pItem = nullptr;
// 	if (pInventoryGrid)
// 	{
// 		pItem = pInventoryGrid->ppItems[BODYLOC_TORSO];
// 	}
// 	else
// 	{
// 		pItem = nullptr;
// 	}

// 	if (ITEMS_CanBeEquipped(pItem) && ITEMS_CheckItemTypeId(pItem, ITEMTYPE_ARMOR))
// 	{
// 		if (ppItem)
// 		{
// 			*ppItem = pItem;
// 		}
// 		return TRUE;
// 	}
// }