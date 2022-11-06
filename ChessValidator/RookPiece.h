#pragma once
#include "GamePiece.h"
class RookPiece :
    public GamePiece
{
private:
    virtual char PieceSymbol();
    bool isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]);
public:
    RookPiece(char pColor) : GamePiece(pColor) {}
    ~RookPiece() {}
};

