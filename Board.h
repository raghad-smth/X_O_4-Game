#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    char board[6][7];
    int cntRow;
    int cntColumn;
    int moves = 0;

    bool update_rule(int x, int y);

public:
    Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

#endif // BOARD_H
