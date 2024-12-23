#include "BoardGame_Classes.h"

template <typename T>
class ultimateBoard : public Board<T>
{
public:
    ultimateBoard();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class ultimatePlayer : public Player<T>
{
public:
    ultimatePlayer(string name, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class ultimateRandomPlayer : public RandomPlayer<T>
{
public:
    ultimateRandomPlayer(T symbol);
    void getmove(int &x, int &y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()

using namespace std;

// Constructor for ultimateBoard
template <typename T>
ultimateBoard<T>::ultimateBoard()
{
    this->rows = this->columns = 9;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool ultimateBoard<T>::update_board(int x, int y, T mark)
{
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0))
    {
        if (mark == 0)
        {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else
        {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void ultimateBoard<T>::display_board()
{
    for (int i = 0; i < this->rows; i++)
    {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++)
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n"
             << string(73, '-');
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool ultimateBoard<T>::is_win()
{
    // Check rows and columns
    for (int i = 0; i < this->rows; i++)
    {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]
          && this->board[i][0] != 0 && this->board[i][1] == this->board[i][3] && 
          this->board[i][1] == this->board[i][4] && this->board[i][1] == this->board[i][5] && 
          this->board[i][1] == this->board[i][6]) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && 
            this->board[0][i] != 0 && this->board[1][i] == this->board[3][i] && this->board[1][i] == this->board[4][i] 
            && this->board[1][i] == this->board[5][i] && this->board[1][i] == this->board[6][i]))
        {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0
     && this->board[1][1] == this->board[3][3] && this->board[1][1] == this->board[4][4] 
     && this->board[1][1] == this->board[5][5] && this->board[1][1] == this->board[6][6]) ||
        (this->board[0][8] == this->board[1][7] && this->board[0][8] == this->board[2][6] 
        && this->board[0][8] == this->board[3][5] && this->board[0][8] == this->board[4][4] 
        && this->board[0][8] == this->board[5][3] && this->board[0][2] != 0))
    {
        return true;
    }

    return false;
}

// Return true if 81 moves are done and no winner
template <typename T>
bool ultimateBoard<T>::is_draw()
{
    return (this->n_moves == 81 && !is_win());
}

template <typename T>
bool ultimateBoard<T>::game_is_over()
{
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for ultimatePlayer
template <typename T>
ultimatePlayer<T>::ultimatePlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void ultimatePlayer<T>::getmove(int &x, int &y)
{
    cout << "\nPlease enter your move x and y (0 to 8) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for ultimateRandomPlayer
template <typename T>
ultimateRandomPlayer<T>::ultimateRandomPlayer(T symbol) : RandomPlayer<T>(symbol)
{
    this->dimension = 9;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

template <typename T>
void ultimateRandomPlayer<T>::getmove(int &x, int &y)
{
    x = rand() % this->dimension; // Random number between 0 and 8
    y = rand() % this->dimension;
}
