#ifndef _PYRAMID_TIC_TAC_TOE_H
#define _PYRAMID_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()

using namespace std;

// Pyramid_Board Class
template <typename T>
class Pyramid_Board : public Board<T> {
public:
    Pyramid_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

// Pyramid_Player Class
template <typename T>
class Pyramid_Player : public Player<T> {
public:
    Pyramid_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

// Pyramid_Random_Player Class
template <typename T>
class Pyramid_Random_Player : public RandomPlayer<T> {
public:
    Pyramid_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

// Constructor for Pyramid_Board
template <typename T>
Pyramid_Board<T>::Pyramid_Board() {
    this->rows = 3; // Number of rows in the pyramid
    this->columns = 5; // Width of the largest row
    this->board = new T*[this->rows];

    // Allocate memory for each row (increasing width)
    for (int i = 0; i < this->rows; i++) {
        int Fixed_Columns = 1 + 2 * i; // Width increases as 1, 3, 5
        this->board[i] = new T[Fixed_Columns];
        for (int j = 0; j < Fixed_Columns; j++) {
            this->board[i][j] = 0; // Initialize cells as empty
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool Pyramid_Board<T>::update_board(int x, int y, T mark) {
    if (x < 0 || x >= this->rows || y < 0 || y >= (1 + 2 * x) || this->board[x][y] != 0) {
        return false;
    }
    this->board[x][y] = toupper(mark);
    this->n_moves++;
    return true;
}

template <typename T>
void Pyramid_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        if (i == 0)
        cout << "  ";
        cout << string((this->columns - (1 + 2 * i)) / 2 * 2 , ' '); 
        for (int j = 0; j < (1 + 2 * i); j++) {
            cout << "[" << (this->board[i][j] == 0 ? ' ' : this->board[i][j]) << "]";
        }
        cout << endl;
        if (i != 1)
        cout << " ";
    }
}

template <typename T>
bool Pyramid_Board<T>::is_win() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        int Fixed_Columns = 1 + 2 * i;
        for (int j = 0; j <= Fixed_Columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                return true;
            }
        }
    }
    // check column
    if (this->board[0][0] != 0 && this->board[0][0] == this->board[1][1] && this->board[0][0] == this->board[2][2])
       return true;
    
    if (this->board[0][0] != 0 && this->board[0][0] == this->board[1][0] && this->board[0][0] == this->board[2][0])
        return true;
    if (this->board[0][0] != 0 && this->board[0][0] == this->board[1][2] && this->board[0][0] == this->board[2][4])
        return true;
    return false;
}

template <typename T>
bool Pyramid_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Pyramid_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for Pyramid_Player
template <typename T>
Pyramid_Player<T>::Pyramid_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Pyramid_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move (row and column) separated by a space: ";
    cin >> x >> y;
}

// Constructor for Pyramid_Random_Player
template <typename T>
Pyramid_Random_Player<T>::Pyramid_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

template <typename T>
void Pyramid_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3; // Random row
    y = rand() % (1 + 2 * x); // Random column within pyramid bounds
}

#endif //_PYRAMID_TIC_TAC_TOE_H
