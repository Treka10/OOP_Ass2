#ifndef _5X5_TICTACTOE_H
#define _5X5_TICTACTOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

template <typename T>
class TicTacToe5x5Board : public Board<T> {
private:
    bool check_three_in_a_row(int x, int y, T symbol, int dx, int dy);

public:
    TicTacToe5x5Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    int count_three_in_a_rows(T symbol);


};

template <typename T>
class TicTacToe5x5Player : public Player<T> {
public:
    TicTacToe5x5Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class TicTacToe5x5RandomPlayer : public RandomPlayer<T> {
public:
    TicTacToe5x5RandomPlayer(T symbol);
    void getmove(int& x, int& y);
};

// Implementation

template <typename T>
TicTacToe5x5Board<T>::TicTacToe5x5Board() {
    this->rows = this->columns = 5;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]();
    }
    this->n_moves = 0;
}

template <typename T>
bool TicTacToe5x5Board<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    return false;
}

template <typename T>
void TicTacToe5x5Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")" << setw(2) << this->board[i][j] << " | ";
        }
        cout << "\n" << string(40, '-');
    }
    cout << endl;
}

template <typename T>
bool TicTacToe5x5Board<T>::is_win() {
    // No single winner in this game variation
    return false;
}

template <typename T>
bool TicTacToe5x5Board<T>::is_draw() {
    return this->n_moves == 24;
}

template <typename T>
bool TicTacToe5x5Board<T>::game_is_over() {
    return is_draw();
}

template <typename T>
int TicTacToe5x5Board<T>::count_three_in_a_rows(T symbol) {
    int count = 0;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            // Check all directions
            if (this->board[i][j] == symbol) {
                count += check_three_in_a_row(i, j, symbol, 0, 1);  // Horizontal
                count += check_three_in_a_row(i, j, symbol, 1, 0);  // Vertical
                count += check_three_in_a_row(i, j, symbol, 1, 1);  // Diagonal
                count += check_three_in_a_row(i, j, symbol, 1, -1); // Anti-diagonal
            }
        }
    }
    return count;
}

template <typename T>
bool TicTacToe5x5Board<T>::check_three_in_a_row(int x, int y, T symbol, int dx, int dy) {
    for (int k = 1; k < 3; k++) {
        int nx = x + k * dx, ny = y + k * dy;
        if (nx < 0 || ny < 0 || nx >= this->rows || ny >= this->columns || this->board[nx][ny] != symbol) {
            return false;
        }
    }
    return true;
}

template <typename T>
TicTacToe5x5Player<T>::TicTacToe5x5Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void TicTacToe5x5Player<T>::getmove(int& x, int& y) {
    cout << this->getname() << ", enter your move (x y): ";
    cin >> x >> y;
}

template <typename T>
TicTacToe5x5RandomPlayer<T>::TicTacToe5x5RandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 5;
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

template <typename T>
void TicTacToe5x5RandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

#endif // _5X5_TICTACTOE_H
