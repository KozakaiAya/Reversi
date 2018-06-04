#include <utility>
#include <memory>

#include "Global.h"
#include "SearchTree.h"

using namespace std;

class MCTS
{
private:
    typedef bool result_t;
    Chessboard board;
    color_t color;
    static const int valueOfPos[GRID_WIDTH][GRID_WIDTH];
    shared_ptr<SearchNode> root;
    shared_ptr<SearchNode> runTreePolicy();
    result_t runDefaultPolicy(shared_ptr<SearchNode> currentNode);
    void backPropagate(shared_ptr<SearchNode> currentNode, result_t result);
    time_t timeLimit;
public:
    MCTS(Chessboard board, color_t color, time_t timeLimit);
    coordinate_t getNextStep();
};
