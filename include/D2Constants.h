#pragma once

#ifndef _D2CONSTANTS_H
#define _D2CONSTANTS_H

/****************************************************************************
*                                                                           *
*   D2Constants.h                                                           *
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
*   This file is meant to declare various constant data. As you add more    *
*   custom code to your library, you will be using many constant values     *
*   used by the game's internal code. Unit types are a good example.        *
*   Declaring constants allows you to assign a name to these constants      *
*   which are more convenient to use in your source code.                   *
*                                                                           *
*   Another advantage is smaller impact in cases where these values would   *
*   need to change. Rather than revising every single piece of code using   *
*   this value, you only need to change your constant's value               *
*                                                                           *
*****************************************************************************/

enum D2C_UnitTypes
{
    UNIT_PLAYER,        // 0 - Players
    UNIT_MONSTER,       // 1 - Monsters
    UNIT_OBJECT,        // 2 - Objects
    UNIT_MISSILE,       // 3 - Missiles
    UNIT_ITEM,          // 4 - Items
    UNIT_TILE           // 5 - Tiles
};

// Affinity based on Elden Ring
enum D2Affinity
{
	AFFINITY_NONE,
	AFFINITY_FIRE, // Str
	AFFINITY_LTNG, // Dex
	AFFINITY_MAGIC, // Int
	AFFINITY_COLD, // Int
	AFFINITY_POIS, // Dex
	AFFINITY_NUM
};

// const double unique_ratio = 296/259;
// const double ratio_max = 289/118;
// Max fire damage in relation to unimproved base damage
// const double fire_ratio_max = 192/118;
// Fire damage in relation to base (physical) damage
// const double fire_ratio = 192/289;
// const double magic_ratio = 220/289; // Probably would follow something closer to the magic ratio
// const double magic_ratio_max =  220/118;
// Weapon Scaling (ER)
// E: 0-24
// D: 25-59
// C: 60-89
// B: 90-139
// A: 140-174
// S: 175+
// Improvement Level Scaling (ER/Unique)
// +0:  1.00 (121/121)
// +1:  1.14 (138/121)
// +2:  1.29 (156/121)
// +3:  1.43 (173/121)
// +4:  1.58 (191/121)
// +5:  1.72 (208/121)
// +6:  1.87 (226/121)
// +7:  2.01 (243/121)
// +8:  2.16 (261/121)
// +9:  2.30 (278/121)
// +10: 2.47 (296/121)
// Calc (rough)
// (baseDamage * baseDamageRatio) + (((statBonus * stat)/100)/100 * (baseDamage * baseDamageRatio))
// end of file ---------------------------------------------------------------
#endif