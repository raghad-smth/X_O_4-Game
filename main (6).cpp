#include "X_O_Four.h"
#include <iostream>

using namespace std;

int main() {
    int choice;
    Player* players[2];

    players[0] = new Player(1, 'x');
    cout << "Welcome to the X_O_FourToWin Game :)\n";
    cout << "--------------------------------RULES--------------------------------------\n"
            "1.First move must be in the last row\n"
            "2.You must pick the lowest empty square in the column for a valid move\n"
            "3.You win once you booked four squares(vertically, horizontally, or diagonally)\n"
            "Play smart, Good luck ;)\n"
            "------------------------------------------------------------------------------\n";

    cout << "Press (1) if you want to play against the computer :";
    cin >> choice;
    if(choice == 1)
        players[1] = new RandomPlayer('o', 7);
    else
        players[1] = new Player(2, 'o');
    GameManager X_O_Four (new Board(), players);
    X_O_Four.run();
    system ("pause");



    return 0;
}

