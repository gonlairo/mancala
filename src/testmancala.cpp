#include <gtest/gtest.h>
#include "MancalaBoard.h"

TEST(MancalaBoardTest, DefaultBoardTest)
{
    /////// NEW BOARD ///////
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

    EXPECT_EQ(Board.PlayerTurn(), 0);   
    EXPECT_FALSE(Board.GameOver());     

}

TEST(MancalaBoardTest, SetBoardTest)
{
    /////// NEW BOARD ///////

    int pits[] = {2, 1, 0, 4, 5, 5, 3, 1, 0, 9};
    int stores[] = {8, 4};
    CMancalaBoard SetBoard(1, pits, stores);
    EXPECT_EQ(SetBoard.ToString(),
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 5 | 4 | 0 | 1 | 2 |   |\n"
                                "| 8 |-------------------| 4 |\n"
                                "|   | 5 | 3 | 1 | 0 | 9 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");

    EXPECT_EQ(SetBoard.PitStoneCount(0, 0), 2);
    EXPECT_EQ(SetBoard.PitStoneCount(0, 1), 1);
    EXPECT_EQ(SetBoard.PitStoneCount(0, 2), 0);
    EXPECT_EQ(SetBoard.PitStoneCount(0, 3), 4);
    EXPECT_EQ(SetBoard.PitStoneCount(0, 4), 5);

    EXPECT_EQ(SetBoard.PitStoneCount(1, 0), 5);
    EXPECT_EQ(SetBoard.PitStoneCount(1, 1), 3);
    EXPECT_EQ(SetBoard.PitStoneCount(1, 2), 1);
    EXPECT_EQ(SetBoard.PitStoneCount(1, 3), 0);
    EXPECT_EQ(SetBoard.PitStoneCount(1, 4), 9);

    /////// NEW BOARD ///////

    CMancalaBoard DefBoard; 
    int pits2[MANCALA_TOTAL_PITS] = {4,4,4,4,4,4,4,4,4,4};
    int stores2[MANCALA_PLAYERS] = {0,0};     
    
    CMancalaBoard SetBoard2(0, pits2, stores2);    // equivalent to default board

    EXPECT_EQ(SetBoard2.ToString(), DefBoard.ToString());
    EXPECT_TRUE(SetBoard2.PlayerTurn() == DefBoard.PlayerTurn());
    EXPECT_FALSE(SetBoard2.GameOver());

    /////// NEW BOARD ///////

    int pits3[MANCALA_TOTAL_PITS] = {0,0,0,0,0,0,0,0,0,0};
    int stores3[MANCALA_PLAYERS] = {20, 20};
    CMancalaBoard SetBoard3(1, pits3, stores3);
    EXPECT_TRUE(SetBoard3.GameOver());

    for (int player = 0; player < MANCALA_PLAYERS; player++)
    {
        for (int pit = 0; pit < MANCALA_PIT_SLOTS; pit++)
        {
            EXPECT_EQ(SetBoard3.PitStoneCount(player, pit), 0);
        }
    }

    SetBoard3.ResetBoard(); // reset board
    EXPECT_EQ(SetBoard3.ToString(), DefBoard.ToString());

    /////// NEW BOARD ///////

    int pits4[MANCALA_TOTAL_PITS] = {2, 5, -1, 7, 2, 3, -2, 1, -3, 0};
    int stores4[MANCALA_PLAYERS] = {2, -5};
    CMancalaBoard SetBoard4(1, pits4, stores4);

    EXPECT_EQ(SetBoard4.PlayerTurn(), 1);   
    EXPECT_FALSE(SetBoard4.PlayerTurn() == DefBoard.PlayerTurn());   // DefBoard = 0, SetBoard3 = 1 
    EXPECT_FALSE(SetBoard4.GameOver());

    EXPECT_EQ(SetBoard4.ToString(),
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
    /////// NEW BOARD ///////
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

    int pits[] = {1,2,3,4,5,6,4,1,0,0};
    int stores[] = {7, 7};
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
    int pits[] = {0, 5, 5, 5, 5, 0, 5, 5, 5, 5};
    int stores[] = {0, 0};
    CMancalaBoard TargetBoard(1, pits, stores);
   
    TargetBoard.Move(0,0);
    TargetBoard.Move(1,0);
  
    EXPECT_EQ(std::string(TargetBoard),
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   | 5 | 5 | 5 | 5 | 0 |   |\n"
                                "| 0 |-------------------| 0 |\n"
                                "|   | 0 | 5 | 5 | 5 | 5 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");

    EXPECT_TRUE(std::string(TargetBoard) == std::string(TargetBoard));
    EXPECT_EQ(TargetBoard.PitStoneCount(0, 0), 0);
    EXPECT_EQ(TargetBoard.PitStoneCount(0, 1), 5);
    EXPECT_EQ(TargetBoard.PitStoneCount(0, 2), 5);
    EXPECT_EQ(TargetBoard.PitStoneCount(0, 3), 5);
    EXPECT_EQ(TargetBoard.PitStoneCount(0, 4), 5);

    /////// NEW BOARD ///////
    int pits2[] = {4, 3, 2, 0, 9, 3, 2, 1, 1, 2};
    int stores2[] = {9, 6};
    CMancalaBoard TargetBoard2(1, pits2, stores2);

    TargetBoard2.Move(1, 3);
    TargetBoard2.Move(0,2);

    EXPECT_EQ(std::string(TargetBoard2),
                                "P1          PITS\n"
                                "      5   4   3   2   1\n"
                                "/---------------------------\\\n"
                                "|   |10 | 1 | 0 | 3 | 4 |   |\n"
                                "| 9 |-------------------| 6 |\n"
                                "|   | 3 | 2 | 1 | 0 | 3 |   |\n"
                                "\\---------------------------/\n"
                                "      1   2   3   4   5\n"
                                "             PITS          P2\n");
}

TEST(MancalaBoardTest, ScoringMoveTest){
    
    /////// NEW BOARD ///////
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

    /////// NEW BOARD ///////
    int pits2[] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int stores2[] = {19, 20};
    CMancalaBoard ScoreBoard2(0, pits2, stores2);
    ScoreBoard2.Move(0, 4); //last move of the game

    for (int player = 0; player < MANCALA_PLAYERS; player++)
    {
        for (int pit = 0; pit < MANCALA_PIT_SLOTS; pit++)
        {
            EXPECT_EQ(ScoreBoard2.PitStoneCount(player, pit), 0);
        }
    }

    EXPECT_EQ(ScoreBoard2.PlayerScore(0), 20);
    EXPECT_EQ(ScoreBoard2.PlayerScore(1), 20);
    EXPECT_TRUE(ScoreBoard2.GameOver());
    EXPECT_EQ(std::string(ScoreBoard2),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 0 | 0 | 0 | 0 | 0 |   |\n"
                                    "|20 |-------------------|20 |\n"
                                    "|   | 0 | 0 | 0 | 0 | 0 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");

}

TEST(MancalaBoardTest, DoubleMoveTest){
    
    /////// NEW BOARD ///////
    CMancalaBoard Board;
    Board.Move(0,1);
    Board.Move(0,0);

    int pits[] = {0, 1, 6, 6, 6, 4, 4, 4, 4, 4};
    int stores[] = {1, 0};
    CMancalaBoard DMBoard(1, pits, stores);

    EXPECT_EQ(Board.ToString(), DMBoard.ToString());
    EXPECT_EQ(Board.PitStoneCount(0, 0), 0);
    EXPECT_EQ(Board.PitStoneCount(0, 1), 1);
    EXPECT_EQ(Board.PitStoneCount(0, 2), 6);
    EXPECT_EQ(Board.PitStoneCount(0, 3), 6);
    EXPECT_EQ(Board.PitStoneCount(0, 4), 6);
    
    EXPECT_EQ(Board.PlayerTurn(), 1);   
    EXPECT_FALSE(Board.GameOver());  

    /////// NEW BOARD ///////
    int pits2[] = {0, 0, 0, 2, 1, 0, 0, 0, 2, 1};
    int stores2[] = {15, 19};
    CMancalaBoard DMBoard2(0, pits2, stores2);

    DMBoard2.Move(0,3);
    EXPECT_EQ(DMBoard2.PlayerTurn(), 0); 
    EXPECT_EQ(DMBoard2.PlayerScore(0), 16);
    EXPECT_EQ(DMBoard2.PitStoneCount(0, 3), 0);
    EXPECT_EQ(DMBoard2.PitStoneCount(0, 4), 2);

    DMBoard2.Move(0,4);
    EXPECT_EQ(DMBoard2.PlayerTurn(), 1); 
    EXPECT_EQ(DMBoard2.PlayerScore(0), 17);
    EXPECT_EQ(DMBoard2.PitStoneCount(0, 4), 0);
    EXPECT_EQ(DMBoard2.PitStoneCount(1, 0), 1);

    EXPECT_FALSE(DMBoard2.GameOver()); 
    EXPECT_EQ(std::string(DMBoard2),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 0 | 0 | 0 | 0 | 0 |   |\n"
                                    "|17 |-------------------|19 |\n"
                                    "|   | 1 | 0 | 0 | 2 | 1 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n"); 
    
    DMBoard2.Move(1,3);
    EXPECT_EQ(DMBoard2.PlayerTurn(), 1); 
    EXPECT_EQ(DMBoard2.PlayerScore(1), 20);
    EXPECT_EQ(DMBoard2.PitStoneCount(1, 3), 0);
    EXPECT_EQ(DMBoard2.PitStoneCount(1, 4), 2);

    DMBoard2.Move(1,4);
    EXPECT_EQ(DMBoard2.PlayerTurn(), 0); 
    EXPECT_EQ(DMBoard2.PlayerScore(1), 21);
    EXPECT_EQ(DMBoard2.PitStoneCount(1, 4), 0);
    EXPECT_EQ(DMBoard2.PitStoneCount(0, 0), 1);

    EXPECT_FALSE(DMBoard2.GameOver()); 
    EXPECT_EQ(std::string(DMBoard2),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 0 | 0 | 0 | 0 | 1 |   |\n"
                                    "|17 |-------------------|21 |\n"
                                    "|   | 1 | 0 | 0 | 0 | 0 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n"); 


}

TEST(MancalaBoardTest, StealMoveTest){

    /////// NEW BOARD ///////
    int pits[] = {1, 2, 3, 0, 4, 4, 2, 3, 6, 5};
    int stores[] = {5, 5};
    CMancalaBoard SBoard(0, pits, stores);

    SBoard.Move(0,1);
    EXPECT_EQ(SBoard.PlayerTurn(), 1);
    EXPECT_EQ(SBoard.PlayerScore(0), 8);
    EXPECT_EQ(SBoard.PitStoneCount(0, 3), 0);
    EXPECT_EQ(SBoard.PitStoneCount(1, 1), 0);

    EXPECT_FALSE(SBoard.GameOver()); 
    EXPECT_EQ(std::string(SBoard),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 4 | 0 | 4 | 0 | 1 |   |\n"
                                    "| 8 |-------------------| 5 |\n"
                                    "|   | 4 | 0 | 3 | 6 | 5 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");

    
    /////// NEW BOARD ///////
    int pits2[] = {9, 2, 2, 0, 4, 4, 2, 2, 4, 0};
    int stores2[] = {5, 6};
    CMancalaBoard SBoard2(1, pits2, stores2);

    SBoard2.Move(1,2);

    EXPECT_EQ(SBoard2.PlayerTurn(), 0);
    EXPECT_EQ(SBoard2.PlayerScore(1), 16);
    EXPECT_EQ(SBoard2.PitStoneCount(1, 4), 0);
    EXPECT_EQ(SBoard2.PitStoneCount(0, 0), 0);

    EXPECT_FALSE(SBoard2.GameOver()); 
    EXPECT_EQ(std::string(SBoard2),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 4 | 0 | 2 | 2 | 0 |   |\n"
                                    "| 5 |-------------------|16 |\n"
                                    "|   | 4 | 2 | 0 | 5 | 0 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");


    /////// NEW BOARD ///////
    int pits3[] = {4, 0, 3, 3, 4, 4, 2, 4, 5, 3};
    int stores3[] = {5, 3};

    CMancalaBoard SBoard3(1, pits3, stores3);

    SBoard3.Move(1,4);

    EXPECT_EQ(SBoard3.PlayerTurn(), 0);
    EXPECT_EQ(SBoard3.PlayerScore(1), 4);
    EXPECT_EQ(SBoard3.PitStoneCount(1, 4), 0);
    EXPECT_EQ(SBoard3.PitStoneCount(0, 0), 5);
    EXPECT_EQ(SBoard3.PitStoneCount(0, 1), 1);

    EXPECT_FALSE(SBoard3.GameOver());

    EXPECT_EQ(std::string(SBoard3),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 4 | 3 | 3 | 1 | 5 |   |\n"
                                    "| 5 |-------------------| 4 |\n"
                                    "|   | 4 | 2 | 4 | 5 | 0 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");

}

TEST(MancalaBoardTest, CantMoveTest){
    
    /////// NEW BOARD ///////
    int pits[] = {0, 0, 0, 0, 1, 0, 2, 1, 2, 1};
    int stores[] = {18, 15};

    CMancalaBoard CantMoveBoard(0, pits, stores);

    EXPECT_EQ(std::string(CantMoveBoard),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 1 | 0 | 0 | 0 | 0 |   |\n"
                                    "|18 |-------------------|15 |\n"
                                    "|   | 0 | 2 | 1 | 2 | 1 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");
    CantMoveBoard.Move(0,4);
    EXPECT_EQ(CantMoveBoard.PlayerScore(0), 19);
    EXPECT_EQ(CantMoveBoard.PitStoneCount(0, 4), 0);
    EXPECT_EQ(CantMoveBoard.PlayerTurn(), 1);   
    EXPECT_FALSE(CantMoveBoard.GameOver()); 
    EXPECT_EQ(std::string(CantMoveBoard),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 0 | 0 | 0 | 0 | 0 |   |\n"
                                    "|19 |-------------------|15 |\n"
                                    "|   | 0 | 2 | 1 | 2 | 1 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");
    CantMoveBoard.Move(1, 2);
    EXPECT_EQ(CantMoveBoard.PlayerScore(1), 15);
    EXPECT_EQ(CantMoveBoard.PitStoneCount(1, 2), 0);
    EXPECT_EQ(CantMoveBoard.PlayerTurn(), 1);
    EXPECT_EQ(std::string(CantMoveBoard),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 0 | 0 | 0 | 0 | 0 |   |\n"
                                    "|19 |-------------------|15 |\n"
                                    "|   | 0 | 2 | 0 | 3 | 1 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");
    CantMoveBoard.Move(1, 4);
    EXPECT_EQ(CantMoveBoard.PlayerScore(1), 16);
    EXPECT_EQ(CantMoveBoard.PitStoneCount(1, 4), 0);
    EXPECT_EQ(CantMoveBoard.PlayerTurn(), 1);
    EXPECT_EQ(std::string(CantMoveBoard),
                                    "P1          PITS\n"
                                    "      5   4   3   2   1\n"
                                    "/---------------------------\\\n"
                                    "|   | 0 | 0 | 0 | 0 | 0 |   |\n"
                                    "|19 |-------------------|16 |\n"
                                    "|   | 0 | 2 | 0 | 3 | 0 |   |\n"
                                    "\\---------------------------/\n"
                                    "      1   2   3   4   5\n"
                                    "             PITS          P2\n");

}

TEST(MancalaBoardTest, BadParametersTest)
{
    CMancalaBoard Board;

    //invalid parameter for player score
    EXPECT_EQ(Board.PlayerScore(2), -1); 
    EXPECT_EQ(Board.PlayerScore(-3), -1); 

    EXPECT_EQ(Board.PitStoneCount(2, 1), -1);  //invalid parameter for player
    EXPECT_EQ(Board.PitStoneCount(-2, 1), -1); //invalid parameter for player 

    EXPECT_EQ(Board.PitStoneCount(1, 5), -1);  //invalid parameter for pit
    EXPECT_EQ(Board.PitStoneCount(1, -5), -1);  //invalid parameter for pit

    EXPECT_EQ(Board.PitStoneCount(3, 6), -1);  //invalid parameter for player and pit
    EXPECT_EQ(Board.PitStoneCount(67, -4), -1);  //invalid parameter for player and pit

    int pits[] = {4, 0, 2, 1, 3, 4, 2, 1, 3, 1};
    int stores[] = {10, 8};

    CMancalaBoard BadParameterBoard(0, pits, stores);
    EXPECT_FALSE(BadParameterBoard.Move(0, 1)); //picking a pit with no stones
    EXPECT_TRUE(BadParameterBoard.Move(0, 2));
    EXPECT_FALSE(BadParameterBoard.Move(0, 0)); //trying to move player 0's stones when it is not their turn
    
}
