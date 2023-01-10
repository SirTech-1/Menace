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

#include "catch.hpp"
#include "Board.hpp"
#include "MagicMoves.hpp"
#include "MoveGen.hpp"


TEST_CASE( "Queen moves", "[queen]" )
{
	MagicMoves::initmagicmoves();
    Tables::init();
	SECTION("Test pseudo-legal moves")
	{
		Board board("k1q1b2p/p2p1pp1/2B1Q3/1N3P2/4r3/2Pn1Q1P/P1RPP1PR/B1K3R1 b K -");
		MoveGen moveGen(board);

		unsigned int whiteSize = moveGen.getQueenPseudoLegalMoves(WHITE).size();
		unsigned int blackSize = moveGen.getQueenPseudoLegalMoves(BLACK).size();
		REQUIRE(whiteSize == 6+3 + 8+5);
		REQUIRE(blackSize == 4+2);
	}
}