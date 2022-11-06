#pragma once
#include <stdlib.h>
#include <iostream>
#include "GamePiece.h"
#include "BishopPiece.h"
#include "KingPiece.h"
#include "KnightPiece.h"
#include "PawnPiece.h"
#include "QueenPiece.h"
#include "RookPiece.h"

class CBoard
{
public:
    GamePiece* Board[8][8];
    CBoard();
    ~CBoard();
    void Print();
    bool IsInCheck(char pColor);
    bool CanMove(char pColor);
    
};