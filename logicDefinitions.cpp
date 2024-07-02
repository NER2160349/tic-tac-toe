//function definitions

#include <iostream>
using namespace std;
void drawBoard(char *spaces){
    cout << "_________________" << '\n';
    cout << "     |     |     " << '\n';
    cout << " " << spaces[0] << "   |  " << spaces[1] << "  |   " << spaces[2] << " " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << " " << spaces[3] << "   |  " << spaces[4] << "  |   " << spaces[5] << " " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << " " << spaces[6] << "   |  " << spaces[7] << "  |   " << spaces[8] << " " << '\n';
    cout << "_____|_____|_____" << '\n';
}
void playerMove(char *spaces, char player){
    //Player will enter an number between 1 and 9, depending on what space they would like to occupy with there marker
    int number;
    do{
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--; // we decrement the number by 1, because the array starts at zero
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        } 
    }while(!number > 0 || !number < 8); //the user can only enter a num 1-8


}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0)); //generate a random number
    while(true){
        number = rand() % 9; // number will be rand between 0-8
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
    }
bool checkWinner(char *spaces, char player, char computer){
    //Conditions start: check all the rows
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? cout << "YOU WIN\n" : cout << "YOU LOOSE\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? cout <<"YOU WIN!\n" : cout << "YOU LOOSE\n";
    }
    //Condition end: check all the rows
    //Condition start: check all the columns
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? cout <<"YOU WIN!\n" : cout << "YOU LOOSE\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? cout <<"YOU WIN!\n" : cout << "YOU LOOSE\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? cout <<"YOU WIN!\n" : cout << "YOU LOOSE\n";
    }
    //Conditon end: check all the columns
    //Condition start: check all the diagonal
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? cout <<"YOU WIN!\n" : cout << "YOU LOOSE\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? cout <<"YOU WIN!\n" : cout << "YOU LOOSE\n";
    }
    //Condition end: check all the diagonal
    else{
        return false;
    }
    return true;
}
bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}