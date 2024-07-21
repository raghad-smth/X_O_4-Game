#include <string>
using namespace std;

class Board{
private :
    int cntRow, cntColumn;
    char board[6][7];
    int moves = 0;
public :
    Board();
    bool update_board (int x, int y, char mark);
    bool update_rule(int x, int y);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class Player {
protected:
    std :: string name;
    char symbol;
public:
    Player (char symbol);
    Player (int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};

class GameManager {
private:
    // pointer to a board object
    Board* boardPtr;
    // pointer to an array of two players
    Player* players[2];
public:
    GameManager(Board* ptrB, Player* playerPtr[2]);
    void run();  // * it bascicly call all the functions built in the classes to run the game
};
