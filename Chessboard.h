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
    Chessboard(color_t board[boardWidth][boardWidth]);
    Chessboard(const Chessboard& c) = default;
    bool isTerminal();
    color_t getWinner();
    vector<coordinate_t> getPlaceable(color_t color);
    bool putChess(coordinate_t pos, color_t color);
private:
    bool isPlaceable(coordinate_t pos, color_t color);
    bool isInside(coordinate_t pos);
    bool isEncompass(coordinate_t pos, color_t color, pair<int, int> dir);
    static const pair<int, int> dir[8];
    color_t board[boardWidth][boardWidth];
    int blackCount = 0;
    int whiteCount = 0;
};