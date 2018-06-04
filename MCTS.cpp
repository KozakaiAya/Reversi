#include <memory>
#include <limits>
#include <random>

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


MCTS::MCTS(Chessboard board, Chesscolor color, time_t timeLimit):board(board), color(color), timeLimit(timeLimit)
{
	root = make_shared<SearchNode>(new SearchNode(color, board));
}

shared_ptr<SearchNode> MCTS::runTreePolicy(shared_ptr<SearchNode> cur)
{
	if (!cur->isVisited())
	{
		cur->visitNode();
		return cur;
	}
	else
	{
		auto children = cur->getChildren();
		bool isFullyExpanded = true;
		for (auto x: children)
		{
			if (!x.first->isVisited())
			{
				isFullyExpanded = false;
				return runTreePolicy(x.first);
			}
		}
		if (isFullyExpanded)
		{
			shared_ptr<SearchNode> toVisit;
			double max = numeric_limits<double>::lowest();
			for (auto x: children)
			{
				double t = valueOfPos[x.second.first][x.second.second] + x.first->getUCTValue();
				if (t > max)
				{
					max = t;
					toVisit = x.first;
				}
			}
			return runTreePolicy(toVisit);
		}
	}
}

MCTS::result_t MCTS::runDefaultPolicy(shared_ptr<SearchNode> currentNode)
{
	Chessboard currentBoard(currentNode->getBoard());
	Chesscolor currentColor = this->color;
	while (!currentBoard.isTerminal())
	{
		auto nextSteps = currentBoard.getPlaceable(currentColor);
		if (nextSteps.size == 0)
		{
			nextSteps = 
		}
		default_random_engine generator;

	}
}