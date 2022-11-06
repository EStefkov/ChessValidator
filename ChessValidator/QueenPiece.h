#pragma once
#include "GamePiece.h"
class QueenPiece :
    public GamePiece
{
private:
    virtual char PieceSymbol();
    bool isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]);
public:
    QueenPiece(char pColor) : GamePiece(pColor) {}
    ~QueenPiece() {}
};

