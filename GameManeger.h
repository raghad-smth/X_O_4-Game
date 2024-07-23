#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Board.h"
#include "Player.h"

class GameManager {
private:
    Board* boardPtr;
    Player* players[2];

public:
    GameManager(Board* bPtr, Player* playerPtr[2]);
    void run();
};

#endif // GAMEMANAGER_H
