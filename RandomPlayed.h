#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "Player.h"

class RandomPlayer : public Player {
private:
    int dimension;

public:
    RandomPlayer(char symbol, int dimension);
    void get_move(int& x, int& y) override;
};

#endif // RANDOMPLAYER_H
