#include "KnightPiece.h"
char KnightPiece::PieceSymbol() {
    return 'N';
}
bool KnightPiece::isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]) {
    // Destination square is unoccupied or occupied by opposite color
    if ((fromY == toY + 1) || (fromY == toY - 1)) {
        if ((fromX == toX + 2) || (fromX == toX - 2)) {
            return true;
        }
    }
    if ((fromY == toY + 2) || (fromY == toY - 2)) {
        if ((fromX == toX + 1) || (fromX == toX - 1)) {
            return true;
        }
    }
    return false;
}