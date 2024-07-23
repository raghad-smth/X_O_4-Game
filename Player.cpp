#include "Player.h"
#include <iostream>

Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player(int order, char symbol) {
    std::cout << "Welcome player " << order << std::endl;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    this->symbol = symbol;
}

void Player::get_move(int& x, int& y) {
    std::cout << "Please enter your move x (0 - 5) / y (0-6) separated by space : ";
    std::cin >> x >> y;
}

std::string Player::to_string() {
    return "Player: " + name;
}

char Player::get_symbol() {
    return symbol;
}
