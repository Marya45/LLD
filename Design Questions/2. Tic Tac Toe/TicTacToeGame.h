#include "models/Board.h"
#include "models/Player.h"
#include "models/PlayingPieceX.h"
#include "models/PlayingPieceO.h"
#include "enums/GameStatus.h"
#include <deque>
#include <iostream>
using namespace std;

class TicTacToeGame {

private:
    deque<Player*> players;
    Board board;
    Player* winner;

public:

    TicTacToeGame(){
        board = Board(3);
        players.push_back(new Player("Player X", new PlayingPieceX()));
        players.push_back(new Player("Player O", new PlayingPieceO()));
    } 

    GameStatus start_game(){
        cout<< "Starting Tic Tac Toe Game!" << endl;
        bool no_winner = true;

        while(no_winner){
            Player* current_player = players.front();
            players.pop_front();
            cout << current_player->getName() << "'s turn." << endl;
            board.display();
            if(board.hasfreeCells() == false){
                no_winner = false;
                continue;
            }

            int row, col;
            cout << current_player->getName() << ", enter your move (row and column): ";
            cin >> row >> col;

            bool valid_move = board.addPiece(row,col,current_player->getPlayingPiece());
            if (!valid_move) {
                cout << "Invalid move. Try again." << endl;
                players.push_front(current_player);
                continue;
            }
            players.push_back(current_player);

            bool is_winner = board.checkWin(current_player->getPlayingPiece()->getType());
            if(is_winner){
                board.display();
                winner = current_player;
                return GameStatus::WIN;
            }
            
        }

        return GameStatus::DRAW;
    }

    Player* getWinner() const {
        return winner;
    }


    ~TicTacToeGame() {
        for (auto &p : players)
            delete p;
    }

};