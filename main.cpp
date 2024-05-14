#include <iostream>
#include "Board.h"
#include "Player.h"

using namespace std;

int main() {
    int board_size, N;
    cout << "Please enter board size" << endl;
    cin >> board_size;
    while (board_size < 4  || board_size > 10) {
        cout << "Board size must be between 4 and 10 (inclusive)" << endl;
        cout << "Please enter board size" << endl;
        cin >> board_size;
    }

    cout << "Please enter connected piece count necessary to win" << endl;
    cin >> N;
    while (N < 3 || N > board_size) {
        if (N < 3) {
            cout << "Connected piece count necessary to win can not be lower than 3!" << endl;
        }
        else {
            cout << "Connected piece count necessary to win can not be bigger than board size!" << endl;
        }

        cout << "Please enter connected piece count necessary to win" << endl;
        cin >> N;
    }

    Board board = Board(board_size, N);
    Player players[] = {
            Player(board, 'O'),
            Player(board, 'X')
    };


    char turn = 0;
    while (board.get_game_status() == '-'){
        board.print_board();

        cout << "It is " << players[turn].get_symbol() << "'s turn." << endl;
        cout << "1 - Place a piece to the board" << endl;
        cout << "2 - Turn the board clockwise" << endl;

        int option;
        cin >> option;

        while (option != 1 && option != 2) {
            cout << "Invalid option!" << endl << endl;
            cout << "It is " << players[turn].get_symbol() << "'s turn." << endl;
            cout << "1 - Place a piece to the board" << endl;
            cout << "2 - Turn the board clockwise" << endl;

            cin >> option;
        }

        if (option == 1) {
            int col;
            cout << "Write column number you want to put your piece in" << endl;
            cin >> col;

            while(!players[turn].put(col)) {
                cout << "You can not place a piece to column " << col << ". Invalid column index or full" << endl;

                cout << "Write column number you want to put your piece in" << endl;
                cin >> col;
            }
        }
        else if (option == 2) {
            players[turn].turn_board();
        }


        turn  = (turn + 1) % 2;
    }

    board.print_board();

    for (int idx = 0; idx < 2; idx++) {
        if (players[idx].is_winner()) {
            cout << "Congratulations! Player " << players[idx].get_symbol() << ", you have won! ";
            cout << "Player " << players[1 - idx].get_symbol() << " had no chance of defeating you! ";
        }
    }
    if (board.get_game_status() == 'D') {
        cout << "It is a draw!";
    }

    return 0;
}