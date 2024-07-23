#include "Board.h"
#include <iostream>
#include <iomanip>

Board::Board() {
    cntRow = 6;
    cntColumn = 7;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }
}

bool Board::update_board(int x, int y, char mark) {
    if (board[x][y] == ' ' && (y >= 0 && y < 7)
        && ((moves > 0 && (x >= 0 && x < 6) || (moves == 0 && x == 5)))
        && (update_rule(x, y))) {
        board[x][y] = toupper(mark);
        moves++;
        return true;
    } else {
        return false;
    }
}

bool Board::update_rule(int x, int y) {
    bool ans;
    if (x == 5) {
        return true;
    } else {
        for (int i = 5; i > x; i--) {
            if (board[i][y] != ' ') {
                ans = true;
            } else {
                return false;
            }
        }
        return ans;
    }
}

void Board::display_board() {
    for (int i = 0; i < 6; i++) {
        std::cout << "\n| ";
        for (int j = 0; j < 7; j++) {
            std::cout << "(" << i << "," << j << ")";
            std::cout << std::setw(2) << board[i][j] << " |";
        }
        std::cout << "\n------------------------------------------------------------------";
    }
    std::cout << std::endl;
}

bool Board::is_winner() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if ((board[i][j] != ' ') &&
                (((j < 4) && (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3])) ||
                 ((i < 3) && (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j])) ||
                 ((i == j) && (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3])))) {
                return true;
            }
        }
    }
    return false;
}

bool Board::is_draw() {
    if (moves == 42 && !is_winner())
        return true;
    else
        return false;
}

bool Board::game_is_over() {
    return moves >= 42;
}
