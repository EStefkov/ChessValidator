#pragma once
#include "GamePiece.h"
#include <string>
class KingPiece :
    public GamePiece
{
private:
    virtual char PieceSymbol();
    bool isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]);
public:
    KingPiece(char pColor) : GamePiece(pColor) {}
    ~KingPiece() {}
};

