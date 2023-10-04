#pragma once

#ifndef _D2PATCH_H
#define _D2PATCH_H

#include "D2PatchConst.h"
#include "D2Common/PatchFuncs.h"

/****************************************************************************
*                                                                           *
*   D2Patch.h                                                               *
*   Copyright (C) Olivier Verville                                          *
*                                                                           *
*   Licensed under the Apache License, Version 2.0 (the "License");         *
*   you may not use this file except in compliance with the License.        *
*   You may obtain a copy of the License at                                 *
*                                                                           *
*   http://www.apache.org/licenses/LICENSE-2.0                              *
*                                                                           *
*   Unless required by applicable law or agreed to in writing, software     *
*   distributed under the License is distributed on an "AS IS" BASIS,       *
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
*   See the License for the specific language governing permissions and     *
*   limitations under the License.                                          *
*                                                                           *
*---------------------------------------------------------------------------*
*                                                                           *
*   https://github.com/olivier-verville/D2Template                          *
*                                                                           *
*   This file is where you declare all your patches, in order to inject     *
*   your own code into the game. Each patch should be declared in the       *
*   array, in order to be handled by D2Template's patcher                   *
*                                                                           *
*****************************************************************************/

static const DLLPatchStrc gptTemplatePatches[] =
{
    /*
        All your patches should be added here
        Keep it organized to save yourself some headache
    */

	// Quest reference:
	// https://d2mods.info/forum/viewtopic.php?t=10620
	// D2Game.dll
	// 6fc2ebd6 0f  b6  4d  6d    MOVZX      ECX ,byte ptr [EBP  + 0x6d ] // get ptGame+6D (diff)
	// 6fc2ebda 8b  44  88  10    MOV        EAX ,dword ptr [EAX  + ECX *0x4  + 0x10 ] // pHistory (diff)
	// 6fc2ebde 6a  0a            PUSH       0xa // intermediate event / Killed Cow King
	// 6fc2ebe0 6a  04            PUSH       0x4 // Cain quest
	// 6fc2ebe2 50                PUSH       EAX
	// 6fc2ebe3 e8  32  b9        CALL       D2COMMON.DLL::Ordinal_10156 // Call getQuestState
	// 6fc2 ebe8 85  c0            TEST       EAX ,EAX // Check quest state
	// arg3 quest state
	// arg2 quest ID
	// arg1 ptHistory
	// {D2DLL_D2GAME,   0x0EBE8, 0x33, FALSE, 0x1},
	// Make exploding arrow shoot something else
	
	// {D2DLL_D2COMMON, 0x74F5F, 0xb8, FALSE, 0x1},

	// All explosive bolts are now goospit!
	// TODO: Reimplement the function so that explosive arrows & magic arrows still work
	// {D2DLL_D2COMMON, 0x74F60, 0xAC, FALSE, 0x1}, // 0x46
	// {D2DLL_D2COMMON, 0x74F61, 0x02, FALSE, 0x1}, // 0x46

    {D2DLL_D2COMMON, 0x74E20, 0xE9, FALSE, 0x00}, //0xEB vs 0xE9?
    {D2DLL_D2COMMON, 0x74E21, (DWORD)MagicBullets, TRUE, 0x00},
	// {D2DLL_D2GAME, 0x19E4B, (DWORD)MagicBullets, TRUE, 0x00},
	// {D2DLL_D2CLIENT, 0x423b7, (DWORD)MagicBullets, TRUE, 0x00},

	{D2DLL_D2COMMON, 0x19056, 0x1, FALSE, 0x01},

	// Give the Act 1 Mercenary Javelin & Shield
	{D2DLL_D2CLIENT, 0x90977, 0xE8, FALSE, 0x00},
    {D2DLL_D2CLIENT, 0x90978, (DWORD)Hirelings_ITEMS_CheckItemTypeId, TRUE, 0x00},
	{D2DLL_D2GAME,   0x6b9b7, 0xE8, FALSE, 0x00},
    {D2DLL_D2GAME,   0x6b9b8, (DWORD)Hirelings_ITEMS_CheckItemTypeId, TRUE, 0x00},
	// Ensure that shield always gets put in the right slot
	{D2DLL_D2GAME,   0x6b6a2, 0x74, FALSE, 0x01}, // Change to always jump so things other than Act 3 hire can have shields work right
	// TODO: Need to change 0x167 to 0x0 so this works for Act 3 mercs again as well.

	// Fuck Identify Scrolls
	
    // {D2DLL_D2COMMON, 0x421c0, 0xE9, FALSE, 0x00}, //0xEB vs 0xE9?
    // {D2DLL_D2COMMON, 0x421c1, (DWORD)D2Common_Patch_421c0, TRUE, 0x00},
    // { D2DLL_D2GAME, 0x2a974, 0x01, FALSE, 0x00},
    // { D2DLL_D2GAME, 0x2ab2a, 0x01, FALSE, 0x00},
    // { D2DLL_D2GAME, 0x2bbf3, 0x01, FALSE, 0x00},
    // { D2DLL_D2GAME, 0x2bf19, 0x01, FALSE, 0x00},
    // { D2DLL_D2GAME, 0x2c1c3, 0x01, FALSE, 0x00},
    // { D2DLL_D2GAME, 0x3dce1, 0x01, FALSE, 0x00},
	// Why is it diffent for the other function calls?
	{ D2DLL_D2GAME, 0xE1B41, 0x01, FALSE, 0x01},

	
	// Changes number of available stat points, skill points, & max durability of equipment????
    // {D2DLL_D2COMMON, 0x58470, 0xE9, FALSE, 0x00}, //0xEB vs 0xE9?
    // {D2DLL_D2COMMON, 0x58471, (DWORD)D2Common_Patch_58470, TRUE, 0x00},

	// {D2DLL_D2COMMON, 0x58640, 0xE9, FALSE, 0x00}, //0xEB vs 0xE9?
    // {D2DLL_D2COMMON, 0x58641, (DWORD)D2Common_Patch_58640, TRUE, 0x00},

	// {D2DLL_D2COMMON, 0x74F5F, 0xb846000000, FALSE, 0x1},
	// {D2DLL_D2COMMON, 0x74F5F, 0xb846000000, FALSE, 0x1},
    
	{D2DLL_INVALID} // this must be the last entry in the array!
};

// end of file --------------------------------------------------------------
#endif