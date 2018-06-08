#ifndef REVERSI_GLOBAL_H
#define REVERSI_GLOBAL_H
#include <utility>
#include <cmath>

#define GRID_WIDTH 8

using namespace std;

/*
 typedef enum
 {
     FREE = 0,
     WHITE = -1,
     BLACK = 1
 } Chesscolor;
*/

enum class Chesscolor
{
    FREE = 0,
    WHITE = -1,
    BLACK = 1
};



Chesscolor operator-(const Chesscolor& color)
{
    if (color == Chesscolor::FREE)
    {
        return Chesscolor::FREE;
    }
    else if (color == Chesscolor::WHITE)
    {
        return Chesscolor::BLACK;
    }
    else if (color == Chesscolor::BLACK)
    {
        return Chesscolor::BLACK;
    }
    // will never reach here
    return Chesscolor::FREE;
}


typedef pair<int, int> coordinate_t;

#endif
