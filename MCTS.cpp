#include "Global.h"
#include "MCTS.h"
#include "SearchTree.h"

using namespace std;

const int MCTS::valueOfPos[GRID_WIDTH][GRID_WIDTH] = {
	30, 2, 20, 15, 15, 20,  2, 30,
	2,  1,  2,  8,  8,  2,  1,  2,
	20, 2,  9,  9,  9,  9,  2, 20,
	15, 8,  9,  2,  2,  9,  8, 15,
	15, 8,  9,  2,  2,  9,  8, 15,
	20, 2,  9,  9,  9,  9,  2, 20,
	2,  1,  2,  8,  8,  2,  1,  2,
	30, 2, 20, 15, 15, 20,  2, 20};

const int MCTS::visitThreshold = 64;

MCTS::MCTS(Context context): context(context) {};

expand_t MCTS::getNextNode(SearchNode* x)
{
		
}

coordinate_t MCTS::search()
{
    SearchNode* rootNode, currentNode;
    rootNode = new SearchNode();
    
}