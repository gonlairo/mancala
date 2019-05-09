#include "MancalaBoard.h"
#include <iostream>
#include <string>

CMancalaBoard EmptyBoard;

// helper functions -> delete later

void print_game(int *pits[MANCALA_PIT_SLOTS], int *stores[MANCALA_PLAYERS])
{
    for (int i = 0; i < MANCALA_PIT_SLOTS; i++)
    {
        pits += " " + std::to_string(pits[i]) + " ";
    }
    for (int j = 0; j < MANCALA_PLAYERS; j++)
    {
        stores += " " + std::to_string(stores[j]) + " ";
    }

    std::cout << "PITS:  " << "[" << pits << "]" << std::endl;
    std::cout << "STORES:  " << "[" << stores << "]" << std::endl;
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
    if (turn > 2 || turn < 1)
    {
        std::cout << "Invalid player: Turn goes to player 1" << std::endl;
        DTurn = 0;
    } else
    {
        DTurn = turn - 1;
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
    if (player > 2 || player < 1)
    {
        std::cout << "Incorrect input: player should be either 1 or 2" << std::endl;
        return -1;
    }
    
    return DStores[player - 1];
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
    for(int Index = 0; Index < MANCALA_PIT_SLOTS; Index++){
        if(DPits[Index] >= 10){
            ReturnString += std::to_string(DPits[Index]) + " |";
        }
        else{
            ReturnString += std::string(" ") + std::to_string(DPits[Index]) + " |";    
        }
    }
    ReturnString += "   |\n|";
    
    if(DStores[0] > 10){
        ReturnString += std::to_string(DStores[0]);
    }
    else{
        ReturnString += std::string(" ") + std::to_string(DStores[0]);
    }
    ReturnString += " |-------------------|";
    if(DStores[1] >= 10){
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

bool CMancalaBoard::Move(int player, int pit)
{
 
    int PitIndex = player * MANCALA_PIT_SLOTS + pit;    // pit we are in: number 0, ... ,9
    
    if((PitIndex < 0) or (PitIndex > MANCALA_TOTAL_PITS))   // pit out of bounds: return false
    {
        return false;    
    }
    
    int Stones = DPits[PitIndex];
    int LastPitDrop = PitIndex;
    DPits[PitIndex] = 0;

    while(Stones > 1)   // why dont we do > 0?
    {
    
        
        PitIndex++; // what if Pitindex is 9? we can't do this. Prob why weird numbers.
        // if pitindex = 9; pitindex = 0

        if ((PitIndex + 1 % MANCALA_PIT_SLOTS) == 0)    // Pit num 5 or 10 -> we need to put stone in Store
        {    
            if (player == (PitIndex + 1 / MANCALA_PIT_SLOTS) - 1) // player 0 or 1
            {
                DStores[player]++;  // we increment the number of stones in store of player 0 or 1.
                Stones--;           // we reduce the num of stones by 1.
            }
            // possible else to switch to opposite side
        }
        
        PitIndex %= MANCALA_TOTAL_PITS; // PitIndex = Pitindex % MANCALA_TOTAL_PITS; what does this do?

        if(Stones)  // if stones num ≠ 0
        {
            DPits[PitIndex]++;
            Stones--;
            LastPitDrop = PitIndex;
        }
    }
    std::cout << "LINE: " << __LINE__ << std::endl; 
    print_game(DPits, DStores);

    PitIndex++; // why do we move again if we don't have any stones?
    PitIndex = PitIndex + 1 % MANCALA_TOTAL_PITS; //why do we update PitIndex?

    if(DPits[PitIndex] == 0)    // stealing
    {
        int OppositeSide = MANCALA_TOTAL_PITS - 1  - PitIndex;
        DStores[player] += DPits[OppositeSide] + 1;
        DPits[OppositeSide] = 0;
        // DPits[PitIndex] = 0;
        // return true: we need to change turns
    }
    std::cout << "LINE: " << __LINE__ << std::endl;
    print_game(DPits, DStores);

    else if(Stones == 1) 
    {
        if((PitIndex + 1% MANCALA_PIT_SLOTS) == 0)
        {
            if(player == (PitIndex + 1 / MANCALA_PIT_SLOTS) - 1)
            {
                DStores[player]++;
                Stones--;
                // return something
            }
        }

        PitIndex %= MANCALA_TOTAL_PITS;
        if(Stones){
            DPits[PitIndex]++;
            Stones--;
            LastPitDrop = PitIndex;
        }
    }
    
    if((LastPitDrop == MANCALA_PIT_SLOTS) or (PitIndex != MANCALA_PIT_SLOTS))
    {
        DTurn = 1 - DTurn;
    }

    std::cout << "LINE: " << __LINE__ << std::endl;
    print_game(DPits, DStores);


    return true;
}

// int main()
// {
//     int pits[] = {0, 5, 5, 5, 5, 4, 4, 4, 4, 4};
//     int stores[] = {0, 0};
//     CMancalaBoard TargetBoard(1, pits, stores);
//     CMancalaBoard Board;

//     Board.Move(0, 0);
//     return 0;
// }
