/********************
 *   Gorkem Guller  *
 ********************/

#include "Player.h"
using namespace std;

//constructor that assigns the current board to board and game piece to piece
Player::Player(Board& current_board, char piece) : board(current_board) , game_piece(piece){}
//the function allows player to put piece
bool Player::put(int column) {
    return board.put_piece(game_piece, column);
}
//function that turns the board clockwise
void Player::turn_board() {
    board.turn_board_clockwise();
}
//function that returns if player is winner
bool Player::is_winner() {
    //checking for draw
    if (board.get_game_status() == 'D') {
        return false;
    }
    //if one player wins the game it returns the symbol of winning player, if there is not it returns '-' character
    return board.get_game_status() == this -> get_symbol();
}
//function that returns player's game piece
char Player::get_symbol() const {
    return game_piece;
}