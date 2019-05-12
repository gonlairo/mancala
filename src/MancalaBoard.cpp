#include "MancalaBoard.h"
#include <iostream>
#include <string>

CMancalaBoard EmptyBoard;

// helper functions -> delete later
void check_stones_pits(int player);

void print_game(int pits[MANCALA_TOTAL_PITS], int stores[MANCALA_PLAYERS], int stones)
{
    std::string pits_str_player0;
    std::string pits_str_player1;
    std::string stores_str;
    for (int i = 0; i < MANCALA_TOTAL_PITS/2; i++)
    {
        pits_str_player0 += " " + std::to_string(pits[4 - i]) + " ";
    }
    for (int i = MANCALA_TOTAL_PITS/2; i < MANCALA_TOTAL_PITS ; i++)
    {
        pits_str_player1 += " " + std::to_string(pits[i]) + " ";
    }
    for (int j = 0; j < MANCALA_PLAYERS; j++)
    {
        stores_str += " " + std::to_string(stores[j]) + " ";
    }
    std::cout << "                -----------------                 " <<std::endl;
    std::cout << "number of stones:       " << stones << std::endl;
    std::cout << "pits player 0:  " << "[" << pits_str_player0 << "]" << std::endl;
    std::cout << "pits player 1:  " << "[" << pits_str_player1 << "]" << std::endl;
    std::cout << "stores:         " << "    [" << stores_str << "]" << std::endl;
    std::cout << "                -----------------                 " << std::endl;
}

void CMancalaBoard::print_ps()
{
    std::string pits;
    std::string stores;
    for (int Index = 0; Index < MANCALA_TOTAL_PITS; Index++)
    {
        pits += " " + std::to_string(DPits[Index]) + " ";
    }
    for (int Index = 0; Index < MANCALA_PLAYERS; Index++)
    {
        stores += " " + std::to_string(DStores[Index]) + " ";
    }

    std::cout << "PITS:  " << "[" << pits << "]" << std::endl;
    std::cout << "STORES:  " << "[" << stores << "]" << std::endl;
}

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
        std::cout << "Incorrect input: player should be either 0 or 1" << std::endl;
        return -1;
    }
    
    return DStores[player];
}

int CMancalaBoard::PitStoneCount(int player, int pit){

    if (player > 1 || player < 0 || pit > 4|| pit < 0)
    {
        std::cout << "Incorrect input" << std::endl;
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
    int PitIndex = player * MANCALA_PIT_SLOTS + pit;    // pit we are in: number 0, ... ,9
    int last_pit_p0 = 4;
    int last_pit_p1 = 9;
    

    if((PitIndex < 0) or (PitIndex > MANCALA_TOTAL_PITS))   // pit out of bounds: return false
    {
        return false;    
    }
    
    int Stones = DPits[PitIndex];

    if (Stones < 1)
    {
        //DTurn = 1 - DTurn;
        std::cout << "No stones: pick another pit" << std::endl;
        return true;
    }

    int LastPitDrop = PitIndex;
    DPits[PitIndex] = 0;

    while(Stones > 1) 
    {
        std::cout << "PitIndex: " << PitIndex << std::endl;

        if (((PitIndex + 1) % MANCALA_PIT_SLOTS) == 0) // PitIndex == 4 || PitIndex == 9
        {
            std::cout << "LINE: " << __LINE__ << std::endl;

            if ((PitIndex == last_pit_p0 && player == 0) or (PitIndex == last_pit_p1 && player == 1))
            {
                std::cout << "LINE: " << __LINE__ << std::endl;
                DStores[player]++;
                Stones--;
                LastPitDrop = PitIndex;
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

        std::cout << "LINE: " << __LINE__ << std::endl;
        std::cout << "PitIndex: " << PitIndex << std::endl;

        if(Stones)  // if stones num ≠ 0. imagine pit with only 1 stone and is at 4th position.
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


    std::cout << "LINE: " << __LINE__ << std::endl;
    std::cout << "PitIndex: " << PitIndex << std::endl;
    print_game(DPits, DStores, Stones);


    // WHAT DO WE DO WITH THE STONE LEFT?

    if (((PitIndex + 1) % MANCALA_PIT_SLOTS) == 0) // PitIndex == 4 || PitIndex == 9
    {
        std::cout << "LINE: " << __LINE__ << std::endl;

        if ((PitIndex == last_pit_p0 && player == 0) or (PitIndex == last_pit_p1 && player == 1))
        {
            std::cout << "LINE: " << __LINE__ << std::endl;
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

    std::cout << "LINE: " << __LINE__ << std::endl;
    std::cout << "PitIndex: " << PitIndex << "\n" << std::endl;

    // OTHER RULES WITH THE STONE LEFT //
    
    // STEALING: If we steal the stones of the oponent, we change turns -> return statement.
    if(DPits[PitIndex] == 0)    
    {
        std::cout << "LINE: " << __LINE__ << std::endl;

        if ((player == 0 && PitIndex <= last_pit_p0) or (player == 1 && (PitIndex > last_pit_p0 && PitIndex <= last_pit_p1)))
        {
            std::cout << "LINE: " << __LINE__ << std::endl;
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

    std::cout << "STBICH: " << Stones << " " << this->PitStoneCount(1, 1) << std::endl;

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

    

    // if(Stones == 1) 
    // {
    //     DPits[PitIndex]++;
    //     Stones--;
    //     LastPitDrop = PitIndex;
    //     std::cout << "LINE: " << __LINE__ << std::endl;
    //     print_game(DPits, DStores, Stones);
    // }


    // if we get to this point, we change turns
    

    // We change turns we get to this point.
    // if((LastPitDrop == MANCALA_PIT_SLOTS) or (PitIndex != MANCALA_PIT_SLOTS))
    // {
    //     std::cout << "LINE: " << __LINE__ << std::endl;
    //     DTurn = 1 - DTurn;
    // }

    
}

// if (player == 0)
// {
//     for (int i = 0; i < MANCALA_PIT_SLOTS; i++)
//     {
//         if (this->PitStoneCount(player, i) != 0)
//         {
//             break;
//         }
//         else
//         {
//             return true;
//         }
//     }
//     DTurn = 1 - DTurn;
// }
// else
// {
//     for (int i = 0; i < MANCALA_PIT_SLOTS; i++)
//     {
//         if (this->PitStoneCount(player, i) != 0)
//         {
//             DTurn = 1 - DTurn;
//             return true;
//         }
//         else
//         {
//             return true;
//         }
//     }
// }