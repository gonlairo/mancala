#include <gtest/gtest.h>
#include "MancalaBoard.h"

TEST(MancalaBoardTest, DefaultBoardTest)
{
    
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

    EXPECT_EQ(Board.ToString(), std::string(Board));

    for (int player = 0; player < MANCALA_PLAYERS; player++)
    {
        for (int pit = 0; pit < MANCALA_PIT_SLOTS; pit++)
        {
            EXPECT_EQ(Board.PitStoneCount(player, pit), 4);
        }
        
    }  

    EXPECT_EQ(Board.PlayerTurn(), 0);   //Player 1 goes first -> 0 == first player
    EXPECT_FALSE(Board.GameOver());     //game should not be over

}

TEST(MancalaBoardTest, SetBoardTest)
{
    CMancalaBoard DefBoard; // empty board
    int pits[MANCALA_TOTAL_PITS] = {4,4,4,4,4,4,4,4,4,4};
    int stores[MANCALA_PLAYERS] = {0,0};     
    CMancalaBoard SetBoard(1, pits, stores);    // equivalent to default board

    EXPECT_EQ(SetBoard.ToString(), DefBoard.ToString());
    EXPECT_TRUE(SetBoard.PlayerTurn() == DefBoard.PlayerTurn());
    EXPECT_FALSE(SetBoard.GameOver());

    /////// NEW BOARD ///////

    int pits2[MANCALA_TOTAL_PITS] = {0,0,0,0,0,0,0,0,0,0};
    int stores2[MANCALA_PLAYERS] = {20, 20};
    CMancalaBoard SetBoard2(2, pits2, stores2);
    EXPECT_TRUE(SetBoard2.GameOver());

    for (int player = 0; player < MANCALA_PLAYERS; player++)
    {
        for (int pit = 0; pit < MANCALA_PIT_SLOTS; pit++)
        {
            EXPECT_EQ(SetBoard2.PitStoneCount(player, pit), 0);
        }
    }

    SetBoard2.ResetBoard(); // reset board
    EXPECT_EQ(SetBoard2.ToString(), DefBoard.ToString());

    /////// NEW BOARD ///////

    int pits3[MANCALA_TOTAL_PITS] = {2, 5, -1, 7, 2, 3, -2, 1, -3, 0};
    int stores3[MANCALA_PLAYERS] = {2, -5};
    CMancalaBoard SetBoard3(2, pits3, stores3);

    EXPECT_EQ(SetBoard3.PlayerTurn(), 1);   // it should be player 2's turn = 1
    EXPECT_FALSE(SetBoard3.PlayerTurn() == DefBoard.PlayerTurn());   // DefBoard = 0, SetBoard3 = 1 
    EXPECT_FALSE(SetBoard3.GameOver());

    // it doesnt pass. it seems correct.
    std::cout << SetBoard3.ToString() << std::endl;
    EXPECT_EQ(SetBoard3.ToString(),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 2 | 7 | 4 | 5 | 2 |   |\n"
                                    "| 2 |-------------------| 0 |\n"
                                    "|   | 3 | 4 | 1 | 4 | 0 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");
}



TEST(MancalaBoardTest, ResetBoardTest)
{
    CMancalaBoard ResBoard;
    ResBoard.ResetBoard();

    EXPECT_EQ(ResBoard.ToString(),
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "| 0 |-------------------| 0 |\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");

    /////// NEW BOARD ///////

    int pits[] = {1,2,3,4,5,6,7,8,9,8};
    int stores[] = {20, 20};
    CMancalaBoard ResBoard2(1, pits, stores);
    ResBoard2.ResetBoard();

    EXPECT_EQ(ResBoard2.ToString(),

                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "| 0 |-------------------| 0 |\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");

    EXPECT_EQ(std::string(ResBoard2),
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "| 0 |-------------------| 0 |\n"
                                "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");
}

TEST(MancalaBoardTest, BasicMoveTest)
{
    CMancalaBoard Board;

    int pits[] = {0, 5, 5, 5, 5, 0, 5, 5, 5, 5};
    int stores[] = {0, 0};
    CMancalaBoard TargetBoard(1, pits, stores);

    std::cout << std::string(Board) << std::endl;
    Board.Move(0,0);
    Board.Move(1,0);
    Board.print_ps();
    std::cout << std::string(Board) << std::endl;
    EXPECT_EQ(std::string(Board),
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 5 | 5 | 5 | 5 | 0 |   |\n"
                                "| 0 |-------------------| 0 |\n"
                                "|   | 0 | 5 | 5 | 5 | 5 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");

    EXPECT_TRUE(std::string(Board) == std::string(TargetBoard));

    EXPECT_EQ(Board.PitStoneCount(0, 0), 0);
    EXPECT_EQ(Board.PitStoneCount(0, 1), 5);
    EXPECT_EQ(Board.PitStoneCount(0, 2), 5);
    EXPECT_EQ(Board.PitStoneCount(0, 3), 5);
    EXPECT_EQ(Board.PitStoneCount(0, 4), 5);

}

TEST(MancalaBoardTest, ScoringMoveTest){
    CMancalaBoard Board;
    Board.Move(0,2);
    
    int pits[] = {4, 4, 0, 5, 5, 5, 4, 4, 4, 4};
    int stores[] = {1, 0};
    CMancalaBoard ScoreBoard(1, pits, stores);

    EXPECT_EQ(Board.ToString(), ScoreBoard.ToString());
    EXPECT_EQ(Board.PitStoneCount(0, 0), 4);
    EXPECT_EQ(Board.PitStoneCount(0, 1), 4);
    EXPECT_EQ(Board.PitStoneCount(0, 2), 0);
    EXPECT_EQ(Board.PitStoneCount(1, 0), 5);
    EXPECT_EQ(Board.PitStoneCount(1, 1), 4);


    

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

TEST(MancalaBoardTest, BadParametersTest)
{
    CMancalaBoard Board;

    EXPECT_EQ(Board.PlayerScore(1), 0);   //Player 1 begins with 0 stones in their store
    EXPECT_EQ(Board.PlayerScore(2), 0);   //Player 2 begins with 0 stones in their store
    EXPECT_EQ(Board.PlayerScore(3), -1);  //PlayerScore returns -1 on bad parameter
    EXPECT_EQ(Board.PlayerScore(-3), -1); //PlayerScore returns -1 on bad parameter

    EXPECT_EQ(Board.PitStoneCount(3, 1), -1);  //invalid parameter for player
    EXPECT_EQ(Board.PitStoneCount(-3, 1), -1); //invalid parameter for player
    EXPECT_EQ(Board.PitStoneCount(1, 6), -1);  //invalid parameter for pit
    EXPECT_EQ(Board.PitStoneCount(3, 6), -1);  //invalid parameter for player and pit
}
