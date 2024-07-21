#include "X_O_Four.h"

#include <iomanip>
#include <iostream>
#include <algorithm>
// Initiolize the bord to empty spaces
Board :: Board() {
    cntRow = 6;
    cntColumn = 7;
    for (int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            board[i][j] = ' ';
        }
    }
}

bool Board ::update_board(int x, int y, char mark) {
    if(board[x][y] == ' '  && (y>=0 && y<7)
       && ((moves>0 && (x>=0 && x<6) || (moves == 0 && x == 5)) ) // first move must be placed in the last row only
       && (update_rule(x,y) )     // Making suer a rule is applied
            ){
        board[x][y] = toupper(mark);
        moves++;
        return true;
    }
    else {
        return false;
    }

}


// function to check if the next placement in the game is in the lowest square of the chosen column
bool Board :: update_rule(int x, int y){
    bool ans;
    // if it is already at the bottom of the column
    if(x == 5){
        return true;
    }
        // For any other row either than the last one then we need to make sure that at that column this is the last square
    else {
        for (int i = 5; i > x; i--) {   // start looping from the bottom of the column ( i = 5 )
            // decrementing by one till we reach the square before the wanted one
            // checking if it is full or not if so then we check the one before it, if not return false
            if (board[i][y] != ' ') {
                ans = true;
            } else {
                return false;

            }
        }
        return ans;
    }

}


void Board:: display_board() {
    for (int i=0; i<6; i++) {
        cout << "\n| ";
        for (int j=0;  j<7; j++){
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j]<< " |";
        }
        cout << "\n------------------------------------------------------------------";
    }
    cout << endl;
}

bool Board :: is_winner(){
    for(int i=0; i<6; i++) {
        for (int j = 0; j < 7; j++) {
            // making suer fisrt that its not an empty square
            if ((board[i][j] != ' ') &&

                // Four in a rwo (horizontally)
                (
                        ((j < 4) && (board[i][j] == board[i][j + 1] && board[i][j]== board[i][j + 2] && board[i][j]== board[i][j + 3]) ) ||

                        // Four in a row (vertically)
                        ((i < 3) && (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j])) ||


                        // Four in a row (diagonally)
                        ((i==j) && (board[i][j] == board[i + 1][j + 1] &&board[i][j] == board[i + 2][j + 2] &&board[i][j]== board[i + 3][j + 3]) )
                ) )
            {

                return true;
            }
        }
    }


    return false;
};

bool Board :: is_draw(){
    if (moves == 42 && !is_winner())
        return true;
    else
        return false;
};

bool Board :: game_is_over(){
    return moves>=42;
};


// constructor to set the symbol of the player
Player::Player(char symbol) {
    this->symbol = symbol;
}

// another constructor to set  a name and an order for the player
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move(int& x, int& y){
    cout << "Please enter your move x (0 - 5) / y (o-6) separated by space : ";
    cin >> x >> y;
}

string Player :: to_string(){
    return "Player: " + name ;
}
char Player::get_symbol() {
    return symbol;
}
using namespace std;

RandomPlayer::RandomPlayer(char symbol, int dimension):Player(symbol){    // setting the player part of randomPlayer to symbol
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
};

void RandomPlayer::get_move (int& x, int& y) {
    // Setting the seed of rand with time(NULL) to genrate the same sequance of numbers every time the program runs
    srand(time(NULL));
    // setting a rang for the rand values to be in the rang of x && y
    x = rand()%(5+1-0)+0;
    y = rand()%(6+1-0)+0;
}
GameManager ::GameManager(Board * bPtr, Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager :: run(){
    int x = 0;
    int y = 0;

    boardPtr->display_board();
    while( ! (boardPtr->game_is_over() || boardPtr->is_winner())){
        for (int i : {0, 1}) {
            // while loop for getting the move incase the input move wasn't valid
            while(!boardPtr->update_board(x,y,players[i]->get_symbol())){
                players[i]->get_move(x,y);
            }
            boardPtr->display_board();
            if(boardPtr->is_winner()){
                cout << "Congrats " << players[i]->to_string() << " you WON !\n";
            }
            if(boardPtr->is_draw() ){
                cout << "Draw :(\n";
            }
        }
    }
}
