#include <utility>
#include <vector>

#include "Global.h"

using namespace std;

class Chessboard
{
private:
    static const int boardWidth = 8;
public:
    Chessboard();
    Chessboard(color_t board[boardWidth][boardWidth]);
    bool isTerminal();
    vector<coordinate_t> getPlaceable(color_t color);
    bool putChess(coordinate_t pos, color_t color);
private:
    bool isPlaceable(coordinate_t pos, color_t color);
    static const pair<int, int> dir[8];
    color_t board[boardWidth][boardWidth];
    int blackCount = 0;
    int whiteCount = 0;
};