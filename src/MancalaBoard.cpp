#include "MancalaBoard.h"
#include <iostream>
#include <string>

CMancalaBoard EmptyBoard;

CMancalaBoard::CMancalaBoard(){
    DTurn = 0;
    for(int Index = 0; Index < MANCALA_TOTAL_PITS; Index++)
    {
        DPits[Index] = 4;   
    }
    for(int Index = 0; Index < MANCALA_PLAYERS; Index++)
    {
        DStores[Index] = 0;
    }
}

CMancalaBoard::CMancalaBoard(int turn, const int pits[MANCALA_TOTAL_PITS], const int stores[MANCALA_PLAYERS])
{
    if (turn > 1 || turn < 0)
    {
        std::cout << "Invalid player: Turn goes to player 1" << std::endl;
        DTurn = 0;
    } else
    {
        DTurn = turn;
    }

    for (int Index = 0; Index < MANCALA_TOTAL_PITS; Index++)
    {
        if (pits[Index] < 0)
        { 
            std::cout << "Invalid input: Default number of stones" << std::endl;
            DPits[Index] = 4;
        } else
        {
            DPits[Index] = pits[Index];
        }
    }

    for (int Index = 0; Index < MANCALA_PLAYERS; Index++)
    {
        if (stores[Index] < 0)
        {
            std::cout << "Invalid input: Default number of stones" << std::endl;
            DStores[Index] = 0;
        } else
        {
            DStores[Index] = stores[Index];
        }
          
    }
}  

void CMancalaBoard::ResetBoard(){
    DTurn = 0;
    for (int Index = 0; Index < MANCALA_TOTAL_PITS; Index++)
    {
        DPits[Index] = 4;
    }
    for (int Index = 0; Index < MANCALA_PLAYERS; Index++)
    {
        DStores[Index] = 0;
    }
}

int CMancalaBoard::PlayerTurn() const{
    return DTurn;
}

int CMancalaBoard::PlayerScore(int player) const{
    if (player > 1 || player < 0)
    {
        std::cout << "Incorrect input: player should be either 0 or 1." << std::endl;
        return -1;
    }
    
    return DStores[player];
}

int CMancalaBoard::PitStoneCount(int player, int pit){

    if (player > 1 || player < 0 || pit > 4|| pit < 0)
    {
        std::cout << "Incorrect input: (0 <= player <=1)  AND  (0 <= pit <= 4)" << std::endl;
            return -1;
    }
    
    return DPits[player * MANCALA_PIT_SLOTS + pit]; 
}

bool CMancalaBoard::GameOver() const
{
    for(int Index = 0; Index < MANCALA_TOTAL_PITS; Index++){
        if(DPits[Index]){
            return false;   
        }
    }
    return true;
}

std::string CMancalaBoard::ToString() const{
    std::string ReturnString  = "P1          PITS\n";
    ReturnString += "      5   4   3   2   1\n";
    ReturnString += "/---------------------------\\\n";
    ReturnString += "|   |";
    for(int Index = MANCALA_PIT_SLOTS-1; Index >= 0; Index--){
        if(DPits[Index] >= 10){
            ReturnString += std::to_string(DPits[Index]) + " |";
        }
        else{
            ReturnString += std::string(" ") + std::to_string(DPits[Index]) + " |";    
        }
    }
    ReturnString += "   |\n|";
    
    if(DStores[0] >= 10){
        ReturnString += std::to_string(DStores[0]);
    }
    else{
        ReturnString += std::string(" ") + std::to_string(DStores[0]);
    }
    ReturnString += " |-------------------|";
    if(DStores[1] > 10){
        ReturnString += std::to_string(DStores[1]);
    }
    else{
        ReturnString += std::string(" ") + std::to_string(DStores[1]);
    }
    ReturnString += " |\n|   |";
    for(int Index = 0; Index < MANCALA_PIT_SLOTS; Index++){
        if(DPits[MANCALA_PIT_SLOTS + Index] >= 10){
            ReturnString += std::to_string(DPits[MANCALA_PIT_SLOTS + Index]) + " |";
        }
        else{
            ReturnString += std::string(" ") + std::to_string(DPits[MANCALA_PIT_SLOTS + Index]) + " |";    
        }
    }
    ReturnString += "   |\n";
    ReturnString += "\\---------------------------/\n";
    ReturnString += "      1   2   3   4   5\n";
    ReturnString += "             PITS          P2\n";
                
    return ReturnString;
}

CMancalaBoard::operator std::string() const{

    return ToString();
    
}


bool CMancalaBoard::Move(int player, int pit)
{
    int PitIndex = player * MANCALA_PIT_SLOTS + pit;  
    int last_pit_p0 = (MANCALA_TOTAL_PITS/2) - 1; // PitIndex = 4
    int last_pit_p1 =  MANCALA_TOTAL_PITS - 1; // PitIndex = 9
    
    if((PitIndex < 0) or (PitIndex > MANCALA_TOTAL_PITS))   // pit out of bounds: return false
    {
        return false;    
    }

    if (DTurn != player)
    {
        return false;
    }

    int Stones = DPits[PitIndex];

    if (Stones < 1)
    {
        return false;
    }

    int LastPitDrop = PitIndex;
    DPits[PitIndex] = 0;

    while(Stones > 1) 
    {
        if (PitIndex == last_pit_p0 || PitIndex == last_pit_p1)
        {
            if ((PitIndex == last_pit_p0 && player == 0) or (PitIndex == last_pit_p1 && player == 1))
            {
                DStores[player]++;
                Stones--;
            }

            if (PitIndex == last_pit_p0)
            {
                PitIndex++;
            }
            else
            {
                PitIndex = (PitIndex + 1) % MANCALA_TOTAL_PITS;
            }        
        }

        else
        {
            PitIndex++;
        }

        if(Stones)  // if stones num ≠ 0.
        {
            DPits[PitIndex]++;
            Stones--;
            LastPitDrop = PitIndex;

            if (Stones == 0)
            {
                DTurn = 1 - DTurn;
                return true;
            }
        }
    }

    // WHAT DO WE DO WITH THE STONE LEFT?

    if (PitIndex == last_pit_p0 || PitIndex == last_pit_p1)
    {
        if ((PitIndex == last_pit_p0 && player == 0) or (PitIndex == last_pit_p1 && player == 1))
        {
            DStores[player]++;
            Stones--;

            if (player == 0)
            {
                for (int i = 0; i < MANCALA_PIT_SLOTS; i++)
                {
                    if (DPits[i])
                    {
                        return true;
                    } 
                }
                DTurn = 1 - DTurn;
                return true;
            }
            else
            {
                for (int i = MANCALA_PIT_SLOTS; i < MANCALA_TOTAL_PITS; i++)
                {
                    if (DPits[i])
                    {
                        return true;
                    }
                }
                DTurn = 1 - DTurn;
                return true;
            }
        }
        else
        {
            if (PitIndex == 4)
            {
                PitIndex++;
            }
            else
            {
                PitIndex = (PitIndex + 1) % MANCALA_TOTAL_PITS;
            }
        }
    }
    else
    {
        PitIndex++;
    }

    // OTHER RULES WITH THE STONE LEFT //
    
    // STEALING: If we steal the stones of the oponent, we change turns -> return statement.
    if(DPits[PitIndex] == 0)    
    {
        if ((player == 0 && PitIndex <= last_pit_p0) or (player == 1 && (PitIndex > last_pit_p0 && PitIndex <= last_pit_p1)))
        {
            int OppositeSide = MANCALA_TOTAL_PITS - 1 - PitIndex;
            DStores[player] += DPits[OppositeSide] + 1; //stones of opponent + player stone.
            Stones--;
            DPits[OppositeSide] = 0;
            DPits[PitIndex] = 0;

            if (player == 0)
            {
                for (int i = MANCALA_PIT_SLOTS; i < MANCALA_TOTAL_PITS; i++)
                {
                    if (DPits[i])
                    {
                        DTurn = 1 - DTurn;
                        return true;
                    }
                }

                return true;
            }
            else
            {
                for (int i = 0; i < MANCALA_PIT_SLOTS; i++)
                {
                    if (DPits[i])
                    {
                        DTurn = 1 - DTurn;
                        return true;
                    }
                }
                return true;
            }
        }
    
    }

    // NORMAL CASE: We just add one stone.
    DPits[PitIndex]++;
    Stones--;
    LastPitDrop = PitIndex;
    
    if (player == 0)
    {
        for (int i = MANCALA_PIT_SLOTS; i < MANCALA_TOTAL_PITS; i++)
        {
            if (DPits[i])
            {
                DTurn = 1 - DTurn;
                return true;
            }
        }
        return true;
    }
    else
    {
        for (int i = 0; i < MANCALA_PIT_SLOTS; i++)
        {
            if (DPits[i])
            {
                DTurn = 1 - DTurn;
                return true;
            }
        }
        return true;
    }
    return true;

}

