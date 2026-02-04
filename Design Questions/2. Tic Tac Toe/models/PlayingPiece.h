#pragma once
#include "../enums/PieceType.h"

class PlayingPiece {

private:
    PieceType type;    

public:
    PlayingPiece(PieceType type) : type(type) {}
    
    PieceType getType() {
        return type;
    }

    virtual ~PlayingPiece() = default;
};
