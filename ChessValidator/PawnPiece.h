#pragma once
#include "GamePiece.h"
class PawnPiece :
    public GamePiece
{
private:
    virtual char PieceSymbol();
    bool isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]);
public:
    PawnPiece(char pColor) : GamePiece(pColor) {}
    ~PawnPiece() {}
};


