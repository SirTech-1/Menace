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

//#define PERFORMANCE_TEST


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