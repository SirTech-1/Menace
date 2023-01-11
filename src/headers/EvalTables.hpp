/*
    Menace, a UCI chess playing engine.

    Copyright (c) 2023 Paul Flowers

    Menace is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Menace is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Menace.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EVALTABLES_H_INCLUDED
#define EVALTABLES_H_INCLUDED

namespace EvalTables
{
    /* Piece square tables */

    // All constants are for white, need to flip to get the little-endian ...

    /*
    [0][][] is for white, [1][][] is for black
    [][1][6] is for midgame
    [][1][6] is for endgame
    Last dimension : same as for moves
    0 Pawn, 1 Knight, 2 Bishop, 3 Rook, 4 Queen, 5 King
    */

    extern const int AllPSQT[2][2][6][64];

    /* Mobility tables */
    extern const int MobilityScaling[2][6];

    /* Pawn tables */
    extern const int PawnTable[2][3]; // 0 = passed, 1 = doubled, 2 = isolated

    /* Material Tables */
    extern const int BishopPair[2]; // OPENGING and ENDGAME bonus values

    extern const int KnightValue;
    extern const int BishopValue; /* Minor pieces bonus depending on pawns number
    0 = knight, 1 = bishop */

}

#endif // EVALTABLES_H_INCLUDED