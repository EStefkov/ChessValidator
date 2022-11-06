#include "KingPiece.h"
char KingPiece::PieceSymbol() {
    return 'K';
}
bool KingPiece::isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]) {
    int iRowDelta = toX - fromX;
    int iColDelta = toY - fromY;
    if (((iRowDelta >= -1) && (iRowDelta <= 1)) &&
        ((iColDelta >= -1) && (iColDelta <= 1)))
    {
        return true;
    }
    return false;
}