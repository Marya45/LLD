#pragma once
#include <string>
#include "PlayingPiece.h"  

class Player {

private:
    std::string name;
    PlayingPiece* piece;

public:    
    Player(const std::string& playerName, PlayingPiece* playerPiece) 
        : name(playerName), piece(playerPiece) {}

    std::string getName() const {
        return name;
    }

    PlayingPiece* getPlayingPiece() const {
        return piece;
    }
};