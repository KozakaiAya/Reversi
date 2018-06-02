#include <utility>

#include "Global.h"
#include "Context.h"
#include "SearchTree.h"


using namespace std;

class MCTS
{
private:
    typedef pair<double, double> score_t;
    typedef pair<SearchNode*, bool> expand_t;
    Context context;
    expand_t getNextNode(SearchNode* rootNode);
    static const int valueOfPos[GRID_WIDTH][GRID_WIDTH];
    static const int visitThreshold;
    bool isTerminal();
public:
    MCTS(Context context);
    coordinate_t search();
    SearchNode* expand();
    score_t simulate(SearchNode* currentNode);
    void backPropagate(SearchNode* currentNode, score_t score);

};