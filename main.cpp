#include <iostream>
#include <ctime>
#include "logicDefinitions.cpp"
using namespace std;

//This will keep track of what spots are taken and which are occupied, in a one dimentional array
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char charPlayer, char computer);
bool checkTie(char *spaces);

int main(){
    char spaces[9] = {' ',' ',' ',' ', ' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    
    //When we run the game, this will immediately invoke this function
    //When we pass an array into a function it decays into a pointer, so there is not need to create a pointer for this array
    drawBoard(spaces);
    //while our condition is running, when we exit we will set running to be false
    while(running){
        playerMove(spaces, player);
        drawBoard(spaces); //Invoke the board to reflect any changes
        //after the player moves we will check for a winner
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;

        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;

        }
    }
    cout << "Thank you for playing!\n";
    return 0;
}