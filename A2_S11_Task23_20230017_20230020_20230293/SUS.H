#ifndef _3X3_TICTACTOE_H
#define _3X3_TICTACTOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <algorithm>  // For using find

using namespace std;

template <typename T>
class SUS_Board : public Board<T> {
private:
    bool arr_row[3] = {true,true,true};
    bool arr_col[3] = {true,true,true};
    bool x1 = true;
    bool x2 = true;

public:
    SUS_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    void Checking_SUS(int x, int y);  // Pass x, y as arguments
    pair<int, int> who_wins();
    int count1 = 0;
    int count2 = 0;
};

template <typename T>
class SUS_Player : public Player<T> {
public:
    SUS_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class SUS_RandomPlayer : public RandomPlayer<T> {
public:
    SUS_RandomPlayer(T symbol);
    void getmove(int& x, int& y);
};

// Implementation

template <typename T>
SUS_Board<T>::SUS_Board() {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]();
    }
    this->n_moves = 0;
}

template <typename T>
bool SUS_Board<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        Checking_SUS(x, y);  // Pass x, y as arguments
        return true;
    }
    return false;
}

template <typename T>
void SUS_Board<T>::display_board() {
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
bool SUS_Board<T>::is_win() {
    // No single winner in this game variation
    return this->n_moves == 9 && this->count1 > this->count2;
}

template <typename T>
bool SUS_Board<T>::is_draw() {
    return this->n_moves == 9 || is_win();
}

template <typename T>
bool SUS_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
pair<int, int> SUS_Board<T>::who_wins() {
    return make_pair(this->count1, this->count2);
}

template <typename T>
void SUS_Board<T>::Checking_SUS(int x, int y) {
    // Vector to store the checked positions
    // vector<pair<int, int>> v;
    
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        string row = "", col = "";
        
        for (int j = 0; j < this->columns; j++) {
            row += this->board[i][j];
            col += this->board[j][i];
        }
        
        // Check the row and column for "SUS"
        if (this->board[x][y] == 'S') {
            if ((row == "SUS" && arr_row[i])) {
                this->count1++; // Count points for "S"
                arr_row[i] = false;
            }
            else if (col == "SUS" && arr_col[i])
            {
                this->count1++;
                arr_col[i] = false;
            }
        }
        else if (this->board[x][y] == 'U') {
            if ((row == "SUS" && arr_row[i])) {
                this->count2++; // Count points for "U"
                arr_row[i] = false;
            }

            else if (col == "SUS" && arr_col[i])
            {
                this->count2++;
                arr_col[i] = false;
            }
        }
    }

    // Check the main diagonal: top-left to bottom-right
    string diag1 = "";
    diag1 += this->board[0][0];
    diag1 += this->board[1][1];
    diag1 += this->board[2][2];
    
    // Check the main diagonal for "SUS"
    if (this->board[x][y] == 'S') {
        if (diag1 == "SUS" && x1) {
            this->count1++; // Count points for "S"
            x1 = false;
        }
    }
    else if (this->board[x][y] == 'U') {
        if (diag1 == "SUS" && x2) {
            this->count2++; // Count points for "U"
            x1 = false;
        }
    }

    // Check the anti-diagonal: top-right to bottom-left
    string diag2 = "";
    diag2 += this->board[0][2];
    diag2 += this->board[1][1];
    diag2 += this->board[2][0];
    
    // Check the anti-diagonal for "SUS"
    if (this->board[x][y] == 'S') {
        if (diag2 == "SUS" && x2) {
            this->count1++; // Count points for "S"
            x2 = false;
        }
    }
    else if (this->board[x][y] == 'U') {
        if (diag2 == "SUS" && x2) {
            this->count2++; // Count points for "U"
            x2 = false;
        }
    }
}

template <typename T>
SUS_Player<T>::SUS_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void SUS_Player<T>::getmove(int& x, int& y) {
    cout << this->getname() << ", enter your move (x y): ";
    cin >> x >> y;
}

template <typename T>
SUS_RandomPlayer<T>::SUS_RandomPlayer(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

template <typename T>
void SUS_RandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

#endif // _3X3_TICTACTOE_H
