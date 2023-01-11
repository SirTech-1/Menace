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

#include <vector>
#include <memory>
#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>

#include "headers/Types.hpp"
#include "headers/Eval.hpp"
#include "headers/Search.hpp"
#include "headers/Board.hpp"
#include "headers/MoveGen.hpp"
#include "headers/Move.hpp"
#include "headers/MagicMoves.hpp"
#include "headers/Utils.hpp"
#include "headers/Uci.hpp"
#include "headers/TT.hpp"

#define PERFORMANCE_TEST


int main() {

    // Init engine parameters
	MagicMoves::initmagicmoves();
	Tables::init();
	ZK::initZobristKeys();
    
    Uci uci;
    uci.init();

	#ifdef PERFORMANCE_TEST

		Utils::getPerformanceIndicator();

	#else

		uci.loop();

	#endif

	return 0;
}