#include "headers/catch_amalgamated.hpp"
#include "headers/Board.hpp"
#include "headers/MagicMoves.hpp"
#include "headers/MoveGen.hpp"


TEST_CASE( "Bishop moves", "[bishop]" )
{
	MagicMoves::initmagicmoves();
	Tables::init();

	SECTION("Test pseudo-legal moves")
	{
		Board board("1bq1b2p/p2p1pp1/2Bk4/1N6/4r1Q1/2P4P/P2PPPPR/B2K2R1 b K -");
		MoveGen moveGen(board);

		unsigned int whiteSize = moveGen.getBishopPseudoLegalMoves(WHITE).size();
		unsigned int blackSize = moveGen.getBishopPseudoLegalMoves(BLACK).size();
		REQUIRE(whiteSize == 6);
		REQUIRE(blackSize == 1);
	}
}