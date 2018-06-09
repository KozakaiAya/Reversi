#ifndef REVERSI_CHESSBOARD_H
#define REVERSI_CHESSBOARD_H
#include <utility>
#include <vector>

#include "Global.h"

using namespace std;


class Chessboard
{
private:
    static const int boardWidth = GRID_WIDTH;
public:
    Chessboard();
    Chessboard(Chesscolor board[boardWidth][boardWidth]);

    Chessboard(string board_string);
    Chessboard(const Chessboard& c) = default;
    bool isTerminal();
    Chesscolor getWinner();
    vector<coordinate_t> getPlaceable(Chesscolor color);
    bool putChess(coordinate_t pos, Chesscolor color);
private:
    bool isPlaceable(coordinate_t pos, Chesscolor color);
    bool isInside(coordinate_t pos);
    bool isEncompass(coordinate_t pos, Chesscolor color, pair<int, int> dir);

    void splitString(const std::string &s, std::vector<std::string> &v, const std::string &c);
    static const pair<int, int> dir[8];
    Chesscolor board[boardWidth][boardWidth];
    int blackCount = 0;
    int whiteCount = 0;
};

#endif