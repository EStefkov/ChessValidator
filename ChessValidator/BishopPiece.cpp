#include "BishopPiece.h"
char BishopPiece::PieceSymbol() {
    return 'B';
}
bool BishopPiece::isRoadFree(int fromX,
    int fromY,
    int toX, 
    int toY, 
    GamePiece* GameBoard[8][8]) {
    {
        if ((toY - fromY == toX - fromX) || (toY - fromY == fromX - toX)) {
            // Make sure that all squares in row are empty
            int iRowOffset = (toX - fromX > 0) ? 1 : -1;
            int iColOffset = (toY - fromY > 0) ? 1 : -1;
            int iCheckRow;
            int iCheckCol;
            for (iCheckRow = fromX + iRowOffset, iCheckCol = fromY + iColOffset;
                iCheckRow != toX;
                iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
            {
                if (GameBoard[iCheckRow][iCheckCol] != 0) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}