#include "Global.h"

using namespace std;

class Context
{
public:
    color_t chessBoard[GRID_WIDTH][GRID_WIDTH];
    color_t myColor;
public:
    Context(int myColor);
    void putChess(coordinate_t pos, color_t color);
};

