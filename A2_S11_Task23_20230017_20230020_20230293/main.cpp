#include <bits\stdc++.h>
#include "5x5_TicTacToe.h"
#include "words.h"
#include "BoardGame_Classes.h"
#include "pyramid.h"
#include "Misere.h"
#include "X_O_Four_in_row_GAME.h"
#include "X_ONumericalTic_Tac_Toe.h"
#include "SUS.H"
#include "9x9.h"
using namespace std;
void word_game(string, string);
void X_O_5x5(string, string);
void pyramid(string , string);
void Misere_game(string , string);
void Four_In_Row (string , string);
void Numerical_Game (string , string);
void SUS_Game (string , string);
void Ultimate (string , string);
void showMenu();


int main()
{
    showMenu();
    return 0;
}



void word_game(string name1, string name2)
{
    cout << "Welcome in Word game\n";
    int choice;
    Player<char> *players[2];
    Word_Board<char> *B = new Word_Board<char>();
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    cin.ignore();
    char s;
    switch (choice)
    {
    case 1:
        players[0] = new Word_Player<char>(name1, 'X');
        break;
    case 2:
        players[0] = new Word_RandomPlayer<char>(name1,'X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting the game.\n";
        break;
    }

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        players[1] = new Word_Player<char>(name2, 'O');
        break;
    case 2:
        players[1] = new Word_RandomPlayer<char>(name2,'O');
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting the game.\n";
        break;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

void X_O_5x5(string name1, string name2)
{
    TicTacToe5x5Board<char> *board = new TicTacToe5x5Board<char>();
    Player<char> *players[2];
    int choice;

    cout << "Welcome to 5x5 Tic Tac Toe!\n";
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        players[0] = new TicTacToe5x5Player<char>(name1, 'X');
    }
    else if (choice == 2)
    {
        players[0] = new TicTacToe5x5RandomPlayer<char>('X');
    }
    else
    {
        cout << "Invalid choice for Player 1. Exiting.\n";
        return;
    }

    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        players[1] = new TicTacToe5x5Player<char>(name2, 'O');
    }
    else if (choice == 2)
    {
        players[1] = new TicTacToe5x5RandomPlayer<char>('O');
    }
    else
    {
        cout << "Invalid choice for Player 2. Exiting.\n";
        return;
    }

    // Create Game Manager and play the game
    GameManager<char> gameManager(board, players);
    gameManager.run();

    // Count and declare winner
    int xWins = board->count_three_in_a_rows('X');
    int oWins = board->count_three_in_a_rows('O');
    cout << name1 << " Wins: " << xWins << ", " << name2 << " Wins: " << oWins << endl;

    if (xWins > oWins)
        cout << name1 << " Wins!\n";
    else if (oWins > xWins)
        cout << name2 << " Wins!\n";
    else
        cout << "It's a Draw!\n";

    // Cleanup
    delete board;
    delete players[0];
    delete players[1];
}

void pyramid(string name1 , string name2)
{
    int choice;
    Player<char>* players[2];
    Pyramid_Board<char>* board = new Pyramid_Board<char>();
    cout << "Welcome to Pyramid Tic-Tac-Toe Game! \n";
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[0] = new Pyramid_Player<char>(name1, 'X');
            break;
        case 2:
            players[0] = new Pyramid_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return ;
    }
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice) {
        case 1:
            players[1] = new Pyramid_Player<char>(name2, 'O');
            break;
        case 2:
            players[1] = new Pyramid_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return ;
    }

    // Create the game manager and run the game
    GameManager<char> pyramid_game(board, players);
    pyramid_game.run();

    // Clean up
    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}

void Misere_game (string name1 , string name2)
{
    cout << "Welcome in Misere game\n";
    int choice;
    Player<char>* players[2];
    Misere_Board<char>* B = new Misere_Board<char>();
    swap(name1,name2);
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            players[0] = new Misere_player<char>(name1, 'X');
            break;
        case 2:
            players[0] = new Misere_random_player<char>(name1,'X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return ;
    }

    
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            players[1] = new Misere_player<char>(name2, 'O');
            break;
        case 2:
            players[1] = new Misere_random_player<char>(name2,'O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return ;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}

void Four_In_Row (string name1 , string name2)
{
    int choice;
    Player<char>* players[2];
    X_O_Board<char>* board = new X_O_Board<char>();
    cout<<"Welcome in Game Four In a Row"<<endl;
    cout << "Choose Player X type:" << endl;
    cout << "1. Human" << endl;
    cout << "2. Random Computer" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new X_O_Player<char>(name1, 'X');
            break;
        case 2:
            players[0] = new X_O_Random_Player<char>(name1,'X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game." << endl;
            delete board;
            return ;
    }

    cout << "Choose Player 2 type:" << endl;
    cout << "1. Human" << endl;
    cout << "2. Random Computer" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new X_O_Player<char>(name2, 'O');
            break;
        case 2:
            players[1] = new X_O_Random_Player<char>(name2,'O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game." << endl;
            delete board;
            return ;
    }

    GameManager<char> x_o_game(board, players);
    x_o_game.run();

    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}

void Numerical_Game (string name1 , string name2)
{
    int choice;
    Player<int>* players[2];
    Numerical_Board<int>* B = new Numerical_Board<int>();
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new Numerical_Player<int>(name1, 1);
            break;
        case 2:
            players[0] = new Numerical_RandPlayer<int>(1);
            
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return ;
    }
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new Numerical_Player<int>(name2, 2);
            break;
        case 2:
            players[1] = new Numerical_RandPlayer<int>(2);
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return ;
    }

    GameManager<int> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

void SUS_Game (string name1, string name2)
{
    SUS_Board<char>* board = new SUS_Board<char>();
    Player<char>* players[2];
    int choice1,choice2;

    cout << "Welcome to SUS Game\n";
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice1;

    if (choice1 == 1) {
        players[0] = new SUS_Player<char>(name1, 'S');
    } else if (choice1 == 2) {
        players[0] = new SUS_RandomPlayer<char>('S');
    } else {
        cout << "Invalid choice for Player 1. Exiting.\n";
        return ;
    }
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice2;

    if (choice2 == 1) {
        players[1] = new SUS_Player<char>(name2, 'U');
    } else if (choice2 == 2) {
        players[1] = new SUS_RandomPlayer<char>('U');
    } else {
        cout << "Invalid choice for Player 2. Exiting.\n";
        return;
    }

    GameManager<char> gameManager(board, players);
    gameManager.run();

    pair <int,int> x;
    x.first = board->who_wins().first;
    x.second = board->who_wins().second;
    //cout << x.first << " " << x.second << endl;

    if (choice1 == 2 && choice2 == 2)
    {
    if (x.first > x.second)
    cout << "Player 1 wins\n";
    else if (x.first < x.second)
    cout << "Player 2 wins\n";
    }
    delete board;
    delete players[0];
    delete players[1];

}

void Ultimate (string name1, string name2)
{
    int choice;
    Player<char>* players[2];
    ultimateBoard<char>* B = new ultimateBoard<char>();
    cout << "Welcome to Ultimate Game.\n";
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            players[0] = new ultimatePlayer<char>(name1, 'X');
            break;
        case 2:
            players[0] = new ultimateRandomPlayer<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return ;
    }
    
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;
    switch(choice) {
        case 1:
            players[1] = new ultimatePlayer<char>(name2, 'O');
            break;
        case 2:
            players[1] = new ultimateRandomPlayer<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return ;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

void showMenu()
{
    cout << "\n======================\n\n";
    cout << "Welcome in our APP ^_^\n";
    cout << "\n======================\n";
    string name1, name2;
    cout << "Enter player1 name(last name is valid like Ahmed Khalil): ";
    getline(cin, name1);
    cout << "Enter player2 name(last name is valid like Ahmed Khalil): ";
    getline(cin, name2);
    cout << "\n============================================\n";
    while (true)
    {

        cout << "1- Pyramic Tic-Tac-Toe\t";
        cout << "\t2- Four-in-a-row\n";
        cout << "3- 5 x 5 Tic Tac Toe\t"
             << "\t4- Word Tic Tac Toe\n"
             << "5- Numerical Tic Tac Toe\t"
             << "6- Misere Tic Tac Toe\n"
             << "8- Ultimate Tic Tac Toe\t"
             << "\t9- SUS\n"
             << "0- Exit the program\n";

        cout << "Enter your choice: ";
        string num_game;
        cin >> num_game;
        cin.ignore();
        if (num_game == "1")
        {
            pyramid(name1 , name2);
        }
        else if (num_game == "2")
        {
            Four_In_Row(name1,name2);
        }
        else if (num_game == "3")
        {
            X_O_5x5(name1, name2);
        }
        else if (num_game == "4")
        {
            word_game(name1,name2);
        }
        else if (num_game == "5")
        {
            Numerical_Game(name1 , name2);
        }
        else if (num_game == "6")
        {
            Misere_game(name1 , name2);
        }
        else if (num_game == "8")
        {
            Ultimate(name1,name2);
        }
        else if (num_game == "9")
        {
            SUS_Game(name1,name2);
        }
        else if (num_game == "0")
        {
            cout << "Exiting...\n";
            break;
        }

        else
        {
            cout << "Invalid inpute,try again\n";
        }

        cout << "\n=============================\n";
    }
}