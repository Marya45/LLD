#pragma once
#include <vector>
#include <iostream>
#include "PlayingPiece.h"
using namespace std;

class Board {

private:
    int size;
    vector<vector<PlayingPiece*>> grid;

public:

    Board() {}
    Board(int s) : size(s) {
        grid.resize(size, vector<PlayingPiece*>(size, nullptr));
    }

    bool addPiece(int row, int col, PlayingPiece* piece) {
        if (row < 0 || row >= size || col < 0 || col >= size || grid[row][col] != nullptr) {
            return false;
        }
        grid[row][col] = piece;
        return true;
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(grid[i][j] == nullptr){
                    cout << "   ";
                } else if(grid[i][j]->getType() == PieceType::X){
                    cout << " X ";
                } else if(grid[i][j]->getType() == PieceType::O){
                    cout << " O ";
                } 
                if(j < size - 1) cout << " | ";
            }
            cout << endl;
        }
    }

    bool hasfreeCells() {
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(grid[i][j] == nullptr){
                    return true;
                }
            }
        }
        return false;
    }

    bool checkWin(PieceType type) {
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(grid[i][j] == nullptr || grid[i][j]->getType() != type){
                    break;
                }
                if(j == size-1){
                    return true;
                }
            }
        }
        for(int j=0;j<size;j++){
            for(int i=0;i<size;i++){
                if(grid[i][j] == nullptr || grid[i][j]->getType() != type){
                    break;
                }
                if(i == size-1){
                    return true;
                }
            }
        }
        for(int i=0;i<size;i++){
            if(grid[i][i] == nullptr || grid[i][i]->getType() != type){
                break;
            }
            if(i == size-1){
                return true;
            }
        }
        for(int i=0;i<size;i++){
            if(grid[i][size-1-i] == nullptr || grid[i][size-1-i]->getType() != type){
                break;
            }
            if(i == size-1){
                return true;
            }
        }
        return false;
    }

};