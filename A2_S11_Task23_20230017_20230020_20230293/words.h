#include "BoardGame_Classes.h"
#include <fstream>
#include <bits\stdc++.h>
template <typename T>
class Word_Board:public Board<T> {
public:
    Word_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    vector <string> v;
};

template <typename T>
class Word_Player : public Player<T> {
public:
    Word_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Word_RandomPlayer : public RandomPlayer<T>{
public:
    Word_RandomPlayer (string namex,T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for Word_Board
template <typename T>
Word_Board<T>::Word_Board() {

    ifstream myfile("dic.txt");
    string line;
    while (getline(myfile,line))
    v.push_back(line);
    myfile.close();
    
    this->rows = this->columns = 3;
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
bool Word_Board<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) &&
        (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        } else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Word_Board<T>::display_board() {
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

// Returns true if there is any winner
template <typename T>
bool Word_Board<T>::is_win() {
    string row, col;
    for (int i = 0 ; i < 3 ; i++)
    {
        row = col = "";
        row += this->board[i][0] ;
        row += this->board[i][1] ;
        row += this->board[i][2] ;
        col += this->board[0][i] ;
        col += this->board[1][i] ;
        col += this->board[2][i] ;

        if (count(v.begin(),v.end(),row) || count(v.begin(),v.end(),col))
        {return true;}
    }

    string diag1;
    diag1 += this->board[0][0];
    diag1 += this->board[1][1];
    diag1 += this->board[2][2];
    if (count(v.begin() , v.end(),diag1))
        return true;
    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool Word_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Word_Board<T>::game_is_over() {
    return is_win() || is_draw();
}



//--------------------------------------

// Constructor for Word_Player
template <typename T>
Word_Player<T>::Word_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Word_Player<T>::getmove(int& x, int& y) {
 
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
    while (x < 0 || x > 2 || y < 0 || y > 2)
    {
        cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
        cin >> x >> y;
    }
    T letter;
    cout << "Enter the letter: ";
    cin >> letter;
    while (!isalpha(letter))
    {
        cout << "Please Enter a letter: ";
        cin >> letter;
    }
    this->symbol = letter;
}

// Constructor for Word_RandomPlayer
template <typename T>
Word_RandomPlayer<T>::Word_RandomPlayer(string namex,T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = namex;
    srand(static_cast<unsigned int>(time(0)));  // Seed the random letter generator
}

template <typename T>
void Word_RandomPlayer<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random letter between 0 and 2
    y = rand() % this->dimension;
    T letter;
    letter = 'A' + (rand() % 26);
    this->symbol = letter;
}

