#include "PawnPiece.h"
char PawnPiece::PieceSymbol() {
    return 'P';
}
bool PawnPiece::isRoadFree(int fromX, int fromY, int toX, int toY, GamePiece* GameBoard[8][8]) {
    GamePiece* qpDest = GameBoard[toX][toY];
/*
    if (firstMove == 0) {
        if (GetColor() == 'W') {
            if (toX == fromX + 1 || toX == fromX + 2) {
                firstMove++;
                return true;
            }
        }
        else {
            if (toX == fromX - 1 || toX == fromX -2) {
                firstMove++;
                return true;
            }
        }

    }
    */
    if (qpDest == 0) {
        // Destination square is unoccupied
        if (fromY == toY) {
            if (GetColor() == 'W') {
                if (toX == fromX + 1) {
                    return true;
                }
            }
            else {
                if (toX == fromX - 1) {
                    return true;
                }
            }
        }
    }
    else {
        // Dest holds piece of opposite color
        if ((fromY == toY + 1) || (fromY == toY - 1)) {
            if (GetColor() == 'W') {
                if (toX == fromX + 1) {
                    return true;
                }
            }
            else {
                if (toX == fromX - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}
