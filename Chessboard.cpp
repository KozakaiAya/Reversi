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

Chessboard::Chessboard(color_t board[boardWidth][boardWidth])
{
    whiteCount = 0;
    blackCount = 0;
    for (int i = 0; i < boardWidth; i++)
        for (int j = 0; j < boardWidth; j++)
        {
            this->board[i][j] = board[i][j];
            if (board[i][j] == WHITE)
                whiteCount++;
            else if (board[i][j] == BLACK)
                blackCount++;
        }
}

bool Chessboard::isTerminal()
{
    if ((blackCount + whiteCount) >= boardWidth * boardWidth)
        return true;
    for (int i = 0; i < boardWidth; i++)
        for (int j = 0; j < boardWidth; j++)
            if (isPlaceable(make_pair(i, j), WHITE) || isPlaceable(make_pair(i, j), BLACK))
                return false;
    return true;
}

bool Chessboard::isInside(coordinate_t pos)
{
    int x = pos.first;
    int y = pos.second;
    if ((x >= 0) && (x < boardWidth) && (y >= 0) && (y < boardWidth))
        return true;
    else   
        return false;
}
bool Chessboard::isEncompass(coordinate_t pos, color_t color, pair<int, int> dir)
{
    bool getOppositeColor = false;
    bool getSameColor = false;
    int x = pos.first;
    int y = pos.second;
    do
    {
        x+=dir.first;
        y+=dir.second;
        if (!isInside(make_pair(x, y))) break;
        if ((board[x][y] == -color) && !getSameColor)
            getOppositeColor = true;
        if ((board[x][y] == color) && getOppositeColor)
        {
            getSameColor = true;
        }
    } while(!getSameColor && !getOppositeColor && isInside(make_pair(x, y)));
    return getSameColor & getOppositeColor;
}

bool Chessboard::isPlaceable(coordinate_t pos, color_t color)
{
    bool flag = false;
    if (board[pos.first][pos.second] != FREE)
        return false;
    for (int i = 0;i < 8; i++)
    {
        if (isEncompass(pos, color, dir[i]))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

vector<coordinate_t> Chessboard::getPlaceable(color_t color)
{
    vector<coordinate_t> result;
    for (int i = 0;i < boardWidth; i++)
        for (int j = 0;j < boardWidth; j++)
            if (isPlaceable(make_pair(i, j), color))
            {
                result.push_back(make_pair(i, j));
            }
    return result;
}

const pair<int, int> dir[8] = {{-1, -1}, 
                               {-1, 0},
                               {-1, 1},
                               {0, -1},
                               {0, 1},
                               {1, -1},
                               {1, 0},
                               {1, 1}};
