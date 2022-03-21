#pragma once

#ifndef _D2PATCH_H
#define _D2PATCH_H

#include "D2PatchConst.h"

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
	// 6fc2ebe8 85  c0            TEST       EAX ,EAX // Check quest state
	// arg3 quest state
	// arg2 quest ID
	// arg1 ptHistory
	{D2DLL_D2GAME, 0xEBE8, 0x33, FALSE, 0x1},
    {D2DLL_INVALID} // this must be the last entry in the array!
};

// end of file --------------------------------------------------------------
#endif