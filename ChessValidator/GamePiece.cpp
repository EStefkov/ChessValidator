#include "GamePiece.h"
char GamePiece::GetColor() {   
        return currentPieceColor;
}

bool GamePiece::isMovePossible (int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]) {
    GamePiece* currentDest = GameBoard[toX][toY];
    if ((currentDest == 0) || (currentPieceColor != currentDest->GetColor())) {
        return isRoadFree(fromX, fromY, toX, toY, GameBoard);
    }
    return false;
}