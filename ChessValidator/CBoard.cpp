#include "CBoard.h"
CBoard::CBoard() {
    {
        for (int Row = 0; Row < 8; ++Row) {
            for (int Col = 0; Col < 8; ++Col) {
                Board[Row][Col] = 0;
            }
        }
        // Putting black pieces on the board
        for (int Col = 0; Col < 8; ++Col) {
            Board[6][Col] = new PawnPiece('B');
        }
        Board[7][0] = new RookPiece('B');
        Board[7][1] = new KnightPiece('B');
        Board[7][2] = new BishopPiece('B');
        Board[7][3] = new KingPiece('B');
        Board[7][4] = new QueenPiece('B');
        Board[7][5] = new BishopPiece('B');
        Board[7][6] = new KnightPiece('B');
        Board[7][7] = new RookPiece('B');

        // Putting white pieces on the board
        for (int Col = 0; Col < 8; ++Col) {
            Board[1][Col] = new PawnPiece('W');
        }
        Board[0][0] = new RookPiece('W');
        Board[0][1] = new KnightPiece('W');
        Board[0][2] = new BishopPiece('W');
        Board[0][3] = new KingPiece('W');
        Board[0][4] = new QueenPiece('W');
        Board[0][5] = new BishopPiece('W');
        Board[0][6] = new KnightPiece('W');
        Board[0][7] = new RookPiece('W');
    }
}

CBoard::~CBoard() {
    for (int Row = 0; Row < 8; ++Row) {
        for (int Col = 0; Col < 8; ++Col) {
            
           delete Board[Row][Col];
            Board[Row][Col] = 0;
        }
    }
}
void CBoard::Print() {
    {
        for (int Row = 0; Row < 8; ++Row) {
            for (int Col = 0; Col < 8; ++Col) {
                int iRow = Row;
                int iColumn = Col;
                if ( Board[7- iRow][iColumn] != 0) {
                    if ((Col % 1) == 1) {
                        std::cout << Board[7 - iRow][iColumn]->GetColor();
                    }
                    else {
                        std::cout << Board[7 - iRow][iColumn]->PieceSymbol();
                    }
                }
                else {
                    if ((iRow + iColumn) % 1 == 0) {
                        std::cout << '*';
                    }
                    else {
                        std::cout << ' ';
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    
}
bool CBoard::IsInCheck(char pColor) {
    // Find the king
    int iKingRow;
    int iKingCol;
    for (int Row = 0; Row < 8; ++Row) {
        for (int Col = 0; Col < 8; ++Col) {
            if (Board[Row][Col] != 0) {
                if (Board[Row][Col]->GetColor() == pColor) {
                    if (Board[Row][Col]->PieceSymbol() == 'K') {
                        iKingRow = Row;
                        iKingCol = Col;
                    }
                }
            }
        }
    }
    // Run through the opponent's pieces and see if any can take the king
    for (int Row = 0; Row < 8; ++Row) {
        for (int Col = 0; Col < 8; ++Col) {
            if (Board[Row][Col] != 0) {
                if (Board[Row][Col]->GetColor() != pColor) {
                    if (Board[Row][Col]->isMovePossible (Row, Col, iKingRow, iKingCol, Board)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool CBoard::CanMove(char pColor) {
    // Run through all pieces
    for (int Row = 0; Row < 8; ++Row) {
        for (int Col = 0; Col < 8; ++Col) {
            if (Board[Row][Col] != 0) {
                // If it is a piece of the current player, see if it has a legal move
                if (Board[Row][Col]->GetColor() == pColor) {
                    for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow) {
                        for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol) {
                            if (Board[Row][Col]->isMovePossible (Row, Col, iMoveRow, iMoveCol, Board)) {
                                // Make move and check whether king is in check
                                GamePiece* qpTemp = Board[iMoveRow][iMoveCol];
                                Board[iMoveRow][iMoveCol] = Board[Row][Col];
                                Board[Row][Col] = 0;
                                bool bCanMove = !IsInCheck(pColor);
                                // Undo the move
                                Board[Row][Col] = Board[iMoveRow][iMoveCol];
                                Board[iMoveRow][iMoveCol] = qpTemp;
                                if (bCanMove) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
