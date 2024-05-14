/********************
 *   Gorkem Guller  *
 ********************/

#include "Board.h"
#include <iostream>
using namespace std;

//the constructor that creates new matrix and fill with '-' character
Board::Board(int size, int winP) : size(size), N(winP){
    head = new char*[size];
    for(int i = 0; i < size; ++i){
        head[i] = new char[size];
    }
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            head[i][j] = '-';
        }
    }
}
//destructor that deallocates the memory and deletes the matrix
Board::~Board(){
    for(int i = 0; i < size; ++i){
        delete[] head[i];
    }
    delete[] head;
    head = nullptr;
}
//function that prints the board
void Board::print_board(){
    cout << endl;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            cout << head[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
//function that put player piece to the matrix with gravity effect
bool Board::put_piece(char c, int column){
    //checks the column size
    if(column < 0 || column >= size){
        return false;
    }
    //starting from bottom to control for optimization and gravity effect
    for(int i = size - 1; i >= 0; i--){
        if(head[i][column] == '-'){
            head[i][column] = c;
            return true;
        }
    }
    return false;
}
//function that turns the board clockwise with gravity effect
void Board::turn_board_clockwise(){
    //creating new empty matrix
    char **temp = new char*[size];
    for(int i = 0; i < size; ++i){
        temp[i] = new char[size];
    }
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            temp[i][j] = '-';
        }
    }
    //starting from bottom, it checks every character and puts the element to the new matrix from gravity effect
    int column = -1;
    for(int j = size - 1; j >= 0 ; j--){
        int row = size - 1;
        column++;
        //it puts the element starting bottom from old matrix and starting left of the new matrix
        for(int i = size - 1; i >= 0 ; i--){
            if(head[j][i] != '-'){
                temp[row][column] = head[j][i];
                row--;
            }
        }
    }
    //deleting the old matrix
    for(int i = 0; i < size; ++i){
        delete[] head[i];
    }
    delete[] head;
    //assign new matrix to the head
    head = temp;
}
//function that checks the game status
char Board::get_game_status(){
    //creating variable for multiple winners
    char firstWinner = '0';
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(head[i][j] != '-' && head[i][j] != firstWinner){
                //using isWinner function in all directions one by one
                //check for horizontal control
                if(isWinner(i,j,1,0)){
                    //if there is a winner
                    if(firstWinner == '0'){
                        //checking for distinct winners
                        if(firstWinner != head[i][j]){
                            firstWinner = head[i][j];
                        }
                    }
                    //there is multiple winners
                    else{
                        return 'D';
                    }
                }
                //check for vertical control
                else if(isWinner(i,j,0,1)){
                    //if there is a winner
                    if(firstWinner == '0'){
                        //checking for distinct winners
                        if(firstWinner != head[i][j]){
                            firstWinner = head[i][j];
                        }
                    }
                    //there is multiple winners
                    else{
                        return 'D';
                    }
                }
                //check for positive diagonal control
                else if(isWinner(i,j,1,1)){
                    //if there is a winner
                    if(firstWinner == '0'){
                        //checking for distinct winners
                        if(firstWinner != head[i][j]){
                            firstWinner = head[i][j];
                        }
                    }
                    //there is multiple winners
                    else{
                        return 'D';
                    }
                }
                //check for negative diagonal control
                else if(isWinner(i,j,-1,1)){
                    //if there is a winner
                    if(firstWinner == '0'){
                        //checking for distinct winners
                        if(firstWinner != head[i][j]){
                            firstWinner = head[i][j];
                        }
                    }
                    //there is multiple winners
                    else{
                        return 'D';
                    }
                }
            }
        }
    }
    //checking if the matrix full of not for not winner status
    bool isFull = true;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(head[i][j] == '-'){
                isFull = false;
            }
        }
    }
    //if there is one winner it returns the game piece of that winner
    if(firstWinner != '0'){
        return firstWinner;
    }
    //if matrix is full and no winner it's a draw
    if(isFull){
        return 'D';
    }
    //game moves on
    return '-';
}
//function that checks if there is a winner on vertical, horizontal and diagonal directions
bool Board::isWinner(int row, int column, int x_direction, int y_direction){
    //the char we check
    char current = head[row][column];
    //we have a starting char so count is 1
    int count = 1;
    //checking for positive direction
    int current_row = row + x_direction;
    int current_column = column + y_direction;
    while(current_row >= 0 && current_row < size && current_column >= 0 && current_column < size && head[current_row][current_column] == current){
        count++;
        //if we reach N it means there is a winner
        if(count == N){
            return true;
        }
        current_row += x_direction;
        current_column += y_direction;
    }

    //checking for negative direction
    current_row = row - x_direction;
    current_column = column - y_direction;
    while(current_row >= 0 && current_row < size && current_column >= 0 && current_column < size && head[current_row][current_column] == current){
        count++;
        //if we reach N it means there is a winner
        if(count == N){
            return true;
        }
        current_row -= x_direction;
        current_column -= y_direction;
    }

    return false;
}







