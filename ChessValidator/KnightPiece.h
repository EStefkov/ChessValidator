#pragma once
#include "GamePiece.h"
class KnightPiece :
    public GamePiece
{
private:
    virtual char PieceSymbol();
    bool isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]);
public:
    KnightPiece(char pColor) : GamePiece(pColor) {}
    ~KnightPiece() {}
};


