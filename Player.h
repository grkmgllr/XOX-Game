/********************
*   Gorkem Guller  *
********************/

#ifndef HW5_PLAYER_H
#define HW5_PLAYER_H
using namespace std;
#include "Board.h"

class Player {
private:
    //sharing board object with reference variable to use it by both players
    Board &board;
    char game_piece;

public:
    //constructor that assigns the board to players
    Player(Board& board, char piece);
    //putting piece function of a player
    bool put(int s);
    //function that player turns the board clockwise
    void turn_board();
    //function that checks if a player is a winner
    bool is_winner();
    //function that gets the player's symbol
    char get_symbol() const;
};

#endif
