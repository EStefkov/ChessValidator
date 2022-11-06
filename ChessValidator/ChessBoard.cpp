#include "ChessBoard.h"
void ChessBoard::Start() {
    {
        do {
            GetNextMove(mqGameBoard.Board);
            AlternateTurn();
        } while (!IsGameOver());
        mqGameBoard.Print();
    }
}
void ChessBoard::GetNextMove(GamePiece* GameBoard[8][8]) {
    using namespace std;
    bool bValidMove = false;
    do {
        mqGameBoard.Print();
        // Get input and convert to integers
        cout << mcPlayerTurn << "'s Move: ";
        string iStartMove;
        cin >> iStartMove;
        int iStartRow = iStartMove[1];
        int iStartCol = iStartMove[0];

        int iEndRow = iStartMove[4];
        int iEndCol = iStartMove[3];
       
        if (iStartRow >= 97 && iStartRow <= 105) {
            iStartRow -= 97;
        }
        else { iStartRow -= 49; }

        if (iStartCol >= 97 && iStartCol <= 105) {
            iStartCol -= 97;
        }
        else { iStartCol -= 49; }

        if (iEndRow >= 97 && iEndRow <= 105) {
            iEndRow -= 97;
        }
        else { iEndRow -= 49; }

        if (iEndCol >= 97 && iEndCol <= 105) {
            iEndCol -= 97;
        }
        else { iEndCol -= 49; }

        

        // Here we check, is it in range of our array.
        // and that the source and destination are different
        if ((iStartRow >= 0 && iStartRow <= 7) &&
            (iStartCol >= 0 && iStartCol <= 7) &&
            (iEndRow >= 0 && iEndRow <= 7) &&
            (iEndCol >= 0 && iEndCol <= 7)) {
            // Additional checks in here
            GamePiece* CurrentPiece = GameBoard[iStartRow][iStartCol];
            // Check that the piece is the correct color
            if ((CurrentPiece != 0) && (CurrentPiece->GetColor() == mcPlayerTurn)) {
                // Check that the destination is a valid destination
                if (CurrentPiece->isMovePossible (iStartRow, iStartCol, iEndRow, iEndCol, GameBoard)) {
                    // Make the move
                    GamePiece* moves = GameBoard[iEndRow][iEndCol];
                    GameBoard[iEndRow][iEndCol] = GameBoard[iStartRow][iStartCol];
                    GameBoard[iStartRow][iStartCol] = 0;
                    // Make sure that the current player is not in check
                    if (!mqGameBoard.IsInCheck(mcPlayerTurn)) {
                        delete moves;
                        bValidMove = true;
                    }
                    else { // Undo the last move
                        GameBoard[iStartRow][iStartCol] = GameBoard[iEndRow][iEndCol];
                        GameBoard[iEndRow][iEndCol] = moves;
                    }
                }
            }
        }
        if (!bValidMove) {
            cout << "Invalid Move!" << endl;
            
           for (int i = 0; i < iStartMove.length(); i++) {
                cout << iStartMove[i];
            }
           exit(!bValidMove);
            
        }
    } while (!bValidMove);
}
void ChessBoard::AlternateTurn() {
    mcPlayerTurn = (mcPlayerTurn == 'W') ? 'B' : 'W';
}
bool ChessBoard::IsGameOver() {
    // Check that the current player can move
    // If not, we have a stalemate or checkmate
    bool bCanMove(false);
    bCanMove = mqGameBoard.CanMove(mcPlayerTurn);
    if (!bCanMove) {
        if (mqGameBoard.IsInCheck(mcPlayerTurn)) {
            AlternateTurn();
            std::cout << "Checkmate, " << mcPlayerTurn << " Wins!" << std::endl;
        }
        else {
            std::cout << "Stalemate!" << std::endl;
        }
    }
    return !bCanMove;
}
