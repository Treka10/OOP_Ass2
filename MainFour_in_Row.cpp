#include <iostream>
#include "BoardGame_Classes.h"
#include "X_O_Four_in_row_GAME.h"

using namespace std;

int main() {
    int choice;
    Player<char>* players[2];
    X_O_Board<char>* board = new X_O_Board<char>();
    string playerXName, player2Name;

    cout<<"Welcome Game Four In a Row"<<endl;
    

    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:" << endl;
    cout << "1. Human" << endl;
    cout << "2. Random Computer" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new X_O_Player<char>(playerXName, 'X');
            break;
        case 2:
            players[0] = new X_O_Random_Player<char>('X');
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game." << endl;
            delete board;
            return 1;
    }

    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:" << endl;
    cout << "1. Human" << endl;
    cout << "2. Random Computer" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new X_O_Player<char>(player2Name, 'O');
            break;
        case 2:
            players[1] = new X_O_Random_Player<char>('O');
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game." << endl;
            delete board;
            return 1;
    }

    GameManager<char> x_o_game(board, players);
    x_o_game.run();

    delete board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}
