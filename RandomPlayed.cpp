#include "RandomPlayer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol) {
    this->dimension = dimension;
    this->name = "Random Computer Player";
    std::cout << "My name is " << name << std::endl;
}

void RandomPlayer::get_move(int& x, int& y) {
    srand(time(NULL));
    x = rand() % 6;
    y = rand() % 7;
}
