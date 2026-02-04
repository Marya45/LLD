#include "TicTacToeGame.h"
#include <iostream>
using namespace std;

int main(){
    TicTacToeGame game;
    cout << "Welcome to Tic Tac Toe!" << endl;
    GameStatus status = game.start_game();

    if(status == GameStatus::WIN){
        cout << "Congratulations! " << game.getWinner()->getName() << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}