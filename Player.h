#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    char symbol;

public:
    Player(char symbol);
    Player(int order, char symbol);
    void get_move(int& x, int& y);
    std::string to_string();
    char get_symbol();
};

#endif // PLAYER_H
