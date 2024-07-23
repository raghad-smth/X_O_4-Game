#include "GameManager.h"
#include <iostream>

GameManager::GameManager(Board* bPtr, Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x = 0;
    int y = 0;

    boardPtr->display_board();
    while (!(boardPtr->game_is_over() || boardPtr->is_winner())) {
        for (int i : {0, 1}) {
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                std::cout << "Congrats " << players[i]->to_string() << " you WON !\n";
            }
            if (boardPtr->is_draw()) {
                std::cout << "Draw :(\n";
            }
        }
    }
}
