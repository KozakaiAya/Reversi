#include "Chessboard.h"

#include "Global.h"

Chessboard::Chessboard()
{
    for (int i = 0; i < boardWidth; i++)
        for (int j = 0; j < boardWidth; j++)
            board[i][j] = FREE;
    board[3][3] = WHITE;
    board[3][4] = BLACK;
    board[4][3] = BLACK;
    board[4][4] = WHITE;
    blackCount = 2;
    whiteCount = 2;
}

