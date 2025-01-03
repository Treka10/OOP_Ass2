#ifndef _7X6_X_O_H
#define _7X6_X_O_H

#include "BoardGame_Classes.h"

template <typename T>
class X_O_Board: public Board<T> {
public:
    X_O_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T> {
public:
    X_O_Random_Player(string namex,T symbol);
    void getmove(int& x, int& y);
};

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

template <typename T>
X_O_Board<T>::X_O_Board() {
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool X_O_Board<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns)) {
        if (mark != 0) {
            for (int i = this->rows - 1; i >= 0; --i) {
                if (this->board[x][y] == 0) { 
                    this->board[x][y] = toupper(mark);
                    this->n_moves++;
                    return true;
                }
            }
        }
        else if (this->board[x][y] != 0) {
            this->n_moves--;
            this->board[x][y] = 0;
            return true;
        }
    }
    return false;
}


template <typename T>
void X_O_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template <typename T>
bool X_O_Board<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][0] != 0) ||
            (this->board[i][1] == this->board[i][2] && this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4] && this->board[i][1] != 0) ||
            (this->board[i][2] == this->board[i][3] && this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && this->board[i][2] != 0) ||
            (this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && this->board[i][5] == this->board[i][6] && this->board[i][3] != 0)) {
            return true;
        }
    }
    for (int i = 0; i < this->columns; i++) {
        if ((this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[0][i] != 0) ||
            (this->board[1][i] == this->board[2][i] && this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i] && this->board[1][i] != 0) ||
            (this->board[2][i] == this->board[3][i] && this->board[3][i] == this->board[4][i] && this->board[4][i] == this->board[5][i] && this->board[2][i] != 0)) {
            return true;
        }
    }
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->board[i][j] != 0 && this->board[i][j] == this->board[i - 1][j + 1] && this->board[i - 1][j + 1] == this->board[i - 2][j + 2] && this->board[i - 2][j + 2] == this->board[i - 3][j + 3]) {
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->board[i][j] != 0 && this->board[i][j] == this->board[i + 1][j + 1] && this->board[i + 1][j + 1] == this->board[i + 2][j + 2] && this->board[i + 2][j + 2] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
bool X_O_Board<T>::is_draw() {
    return (this->n_moves == 42 && !is_win());
}

template <typename T>
bool X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x (0 to 5) and y (0 to 6) separated by spaces: ";
    cin >> x >> y;
}

template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(string namex,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 7;
    this->name = namex ;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % (this->dimension - 1);
    y = rand() % this->dimension;
}

#endif
