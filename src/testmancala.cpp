#include <gtest/gtest.h>
#include "MancalaBoard.h"

TEST(MancalaBoardTest, DefaultBoardTest){
    
    CMancalaBoard Board;

    EXPECT_EQ(std::string(Board), 
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "| 0 |-------------------| 0 |\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");

    EXPECT_EQ(Board.ToString(),
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "| 0 |-------------------| 0 |\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");

    EXPECT_EQ(Board.PlayerTurn(), 1); //Player 1 goes first

    EXPECT_EQ(Board.PlayerScore(1), 0); //Player 1 begins with 0 stones in their store
    EXPECT_EQ(Board.PlayerScore(2), 0); //Player 2 begins with 0 stones in their store
    EXPECT_EQ(Board.PlayerScore(3), -1); //PlayerScore returns -1 on bad parameter 
    EXPECT_EQ(Board.PlayerScore(-3), -1); //PlayerScore returns -1 on bad parameter 


    EXPECT_EQ(Board.PitStoneCount(1, 1), 4); //Player 1, Pit 1 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(1, 2), 4); //Player 1, Pit 2 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(1, 3), 4); //Player 1, Pit 3 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(1, 4), 4); //Player 1, Pit 4 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(1, 5), 4); //Player 1, Pit 5 == 4 stones

    EXPECT_EQ(Board.PitStoneCount(2, 1), 4); //Player 2, Pit 1 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(2, 2), 4); //Player 2, Pit 2 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(2, 3), 4); //Player 2, Pit 3 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(2, 4), 4); //Player 2, Pit 4 == 4 stones
    EXPECT_EQ(Board.PitStoneCount(2, 5), 4); //Player 2, Pit 5 == 4 stones

    EXPECT_EQ(Board.PitStoneCount(3, 1), -1); //invalid parameter for player
    EXPECT_EQ(Board.PitStoneCount(-3, 1), -1); //invalid parameter for player
    EXPECT_EQ(Board.PitStoneCount(1, 6), -1); //invalid parameter for pit
    EXPECT_EQ(Board.PitStoneCount(3, 6), -1); //invalid parameter for player and pit

    EXPECT_FALSE(Board.GameOver()); //game should not be over

}

TEST(MancalaBoardTest, SetBoardTest){
    CMancalaBoard DefBoard;
    //CMancalaBoard SetBoard(1, 4, 0);

}

TEST(MancalaBoardTest, ResetBoardTest){
    CMancalaBoard ResBoard; //use move

    //EXPECT_EQ(ResBoard.ResetBoard().ToString(),
                                            // "P1          PITS\n"
                                            // "      5   4   3   2   1\n"
                                            // "/---------------------------\\\n"
                                            // "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                            // "| 0 |-------------------| 0 |\n"
                                            // "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                            // "\\---------------------------/\n"
                                            // "      1   2   3   4   5\n"
                                            // "             PITS          P2\n"); 


    

}

TEST(MancalaBoardTest, BasicMoveTest){
    // Needs to test that basic non-scoring moves are correct
}

TEST(MancalaBoardTest, ScoringMoveTest){
    // Needs to test that basic scoring, non double moves, non steals are correct    
}

TEST(MancalaBoardTest, DoubleMoveTest){
    // Needs to test that double move is correct
}

TEST(MancalaBoardTest, StealMoveTest){
    // Needs to test that stealing move works correctly
}

TEST(MancalaBoardTest, CantMoveTest){
    // Needs to test when player can't move correctly
}

TEST(MancalaBoardTest, BadParametersTest){
    // Needs to check that bad parameters are handled correctly
}

