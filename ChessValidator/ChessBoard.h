#pragma once
#include "CBoard.h"
class ChessBoard
{
private:
    CBoard mqGameBoard;
    char mcPlayerTurn;
    
public:
    
    ChessBoard() : mcPlayerTurn('W') {}
    ~ChessBoard() {}
    void Start();
    void GetNextMove(GamePiece* GameBoard[8][8]);
    void AlternateTurn();
    bool IsGameOver();
};

