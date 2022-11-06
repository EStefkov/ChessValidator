#pragma once
#include "GamePiece.h"
class BishopPiece :
    public GamePiece
{
private:
    virtual char PieceSymbol();
    bool isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]);
public:
    BishopPiece(char pColor) : GamePiece(pColor) {}
    ~BishopPiece() {}
};

