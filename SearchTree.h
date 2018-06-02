#include <map>

#include "Global.h"

using namespace std;

class SearchNode
{
public:
    color_t board[GRID_WIDTH][GRID_WIDTH];
    int visitCount;
    double eval;
    SearchNode* parent;
    map<coordinate_t, SearchNode*> children;
public:
    SearchNode();
};

