#ifndef REVERSI_MCTS_H
#define REVERSI_MCTS_H
#include <utility>
#include <memory>
#include <chrono>

#include "Global.h"
#include "SearchTree.h"

using namespace std;


class MCTS
{
private:

    typedef bool result_t;
    Chessboard board;
    Chesscolor color;
    static const int valueOfPos[GRID_WIDTH][GRID_WIDTH];
    shared_ptr<SearchNode> root;
    shared_ptr<SearchNode> runTreePolicy(shared_ptr<SearchNode> cur);
    result_t runDefaultPolicy(shared_ptr<SearchNode> currentNode);
    void backPropagate(shared_ptr<SearchNode> currentNode, result_t result);
    chrono::milliseconds timeLimit;
    chrono::milliseconds getTimeElapsed(chrono::high_resolution_clock::time_point st);
public:
    MCTS(Chessboard board, Chesscolor color, chrono::milliseconds timeLimit);
    coordinate_t getNextStep();
    
};

#endif