#include "Chessboard.h"

#include "Global.h"

Chessboard::Chessboard()
{
    for (int i = 0; i < boardWidth; i++)
        for (int j = 0; j < boardWidth; j++)
            board[i][j] = Chesscolor::FREE;
    board[3][3] = Chesscolor::WHITE;
    board[3][4] = Chesscolor::BLACK;
    board[4][3] = Chesscolor::BLACK;
    board[4][4] = Chesscolor::WHITE;
    blackCount = 2;
    whiteCount = 2;
}

Chessboard::Chessboard(string board_string) {
    whiteCount = 0;
    blackCount = 0;
    vector<string> lines;
    splitString(board_string, lines, ";");
    for (int i = 0; i < boardWidth; i++) {
        vector<string> cols;
        splitString(lines.at(i), cols, ".");
        for (int j = 0; j < boardWidth; j++) {
            if (cols.at(j) == "0")
                board[i][j] = Chesscolor::FREE;
            else if (cols.at(j) == "W") {
                whiteCount++;
                board[i][j] = Chesscolor::WHITE;
            } else if (cols.at(j) == "B") {
                blackCount++;
                board[i][j] = Chesscolor::BLACK;
            }
        }
    }
}

bool Chessboard::isTerminal()
{
    if ((blackCount + whiteCount) >= boardWidth * boardWidth)
        return true;
    for (int i = 0; i < boardWidth; i++)
        for (int j = 0; j < boardWidth; j++)
            if (isPlaceable(make_pair(i, j), Chesscolor::WHITE) || isPlaceable(make_pair(i, j), Chesscolor::BLACK))
                return false;
    return true;
}

void Chessboard::splitString(const std::string &s, std::vector<std::string> &v, const std::string &c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
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
bool Chessboard::isEncompass(coordinate_t pos, Chesscolor color, pair<int, int> dir)
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
        if (!getSameColor && !getOppositeColor)
        {
            if (board[x][y] == -color)
                getOppositeColor = true;
            else
                break;
        }
        else if (getOppositeColor && !getSameColor)
        {
            if (board[x][y] == color)
                getSameColor = true;
            else if (board[x][y] == Chesscolor::FREE)
                break;
        }
    } while((!getSameColor || !getOppositeColor) && isInside(make_pair(x, y)));
    return getSameColor & getOppositeColor;
}

bool Chessboard::isPlaceable(coordinate_t pos, Chesscolor color)
{
    bool flag = false;
    if (board[pos.first][pos.second] != Chesscolor::FREE)
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

vector<coordinate_t> Chessboard::getPlaceable(Chesscolor color)
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

const pair<int, int> Chessboard::dir[8] = {{-1, -1}, 
                               {-1, 0},
                               {-1, 1},
                               {0, -1},
                               {0, 1},
                               {1, -1},
                               {1, 0},
                               {1, 1}};

bool Chessboard::putChess(coordinate_t pos, Chesscolor color)
{
    if (board[pos.first][pos.second] != Chesscolor::FREE)
    {
        return false;
    }
    else
    {
        if (color == Chesscolor::BLACK) this->blackCount++;
        if (color == Chesscolor::WHITE) this->whiteCount++;
        board[pos.first][pos.second] = color;
        for(int i = 0;i < 8;i++)
        {
            if (isEncompass(pos, color, dir[i]))
            {
                int x = pos.first + dir[i].first;
                int y = pos.second + dir[i].second;
                while (isInside(make_pair(x, y)) && (board[x][y] == -color))
                {
                    board[x][y] = color;
                    x+=dir[i].first;
                    y+=dir[i].second;
                }
            }
        }
    }
    return true;
}

Chesscolor Chessboard::getWinner()
{
    if (!isTerminal())
        return Chesscolor::FREE;
    else
    {
        if (whiteCount > blackCount)
            return Chesscolor::WHITE;
        else if (blackCount > whiteCount)
            return Chesscolor::BLACK;
        else
            return Chesscolor::FREE;
    }
}
