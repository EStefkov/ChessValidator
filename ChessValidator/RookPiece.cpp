#include "RookPiece.h"
char RookPiece::PieceSymbol() {
    return 'R';
}
bool RookPiece::isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]) {
    if (fromX == toX) {
        // Make sure that all invervening squares are empty
        int iColOffset = (toY - fromY > 0) ? 1 : -1;
        for (int iCheckCol = fromY + iColOffset; iCheckCol != toY; iCheckCol = iCheckCol + iColOffset) {
            if (GameBoard[fromX][iCheckCol] != 0) {
                return false;
            }
        }
        return true;
    }
    else if (toY == fromY) {
        // Make sure that all invervening squares are empty
        int iRowOffset = (toX - fromX > 0) ? 1 : -1;
        for (int iCheckRow = fromX + iRowOffset; iCheckRow != toX; iCheckRow = iCheckRow + iRowOffset) {
            if (GameBoard[iCheckRow][fromY] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}