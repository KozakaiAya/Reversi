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

bool Chessboard::isTerminal()
{
    if ((blackCount + whiteCount) >= boardWidth * boardWidth)
        return true;
    for (int i = 0; i < boardWidth; i++)
        for (int j = 0; j < boardWidth; j++)
            if (isPlaceable(make_pair(i, j), WHITE) || isPlaceable(make_pair(i, j),BLACK))
                return false;
    return true;
}

bool Chessboard::isPlaceable(coordinate_t pos, color_t color)
{

}