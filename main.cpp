#include "Board.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "GameManager.h"

int main() {
    Board board;
    Player* players[2];

    players[0] = new Player(1, 'X'); // Example player 1
    players[1] = new RandomPlayer('O', 2); // Example random player

    GameManager game(&board, players);
    game.run();

    delete players[0];
    delete players[1];

    return 0;
}
