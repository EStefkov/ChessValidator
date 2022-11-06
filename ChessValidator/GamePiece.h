#pragma once
class GamePiece
{
private:
    virtual bool isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]) = 0;
    char currentPieceColor;
public:
    int firstMove = 0;
    GamePiece(char pColor) : currentPieceColor(pColor) {}
    ~GamePiece() {}
    virtual char PieceSymbol() = 0;
    char GetColor();
    bool isMovePossible (int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]);
};

