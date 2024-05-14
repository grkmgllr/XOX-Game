/********************
 *   Gorkem Guller  *
 ********************/

#ifndef HW5_BOARD_H
#define HW5_BOARD_H
using namespace std;

class Board {
private:
    char ** head;
    int size;
    int N;
    //function that checks is there a winner
    bool isWinner(int row, int column, int x_direction, int y_direction);

public:
    //constructor
    Board(int size, int win_Num);
    //destructor
    ~Board();
    //printing board
    void print_board();
    //putting the piece of a player
    bool put_piece(char c, int column);
    //turning board clockwise
    void turn_board_clockwise();
    //returning the game status
    char get_game_status();
};

#endif
