#include "SearchTree.h"

SearchNode::SearchNode(Chesscolor color, const Chessboard& board)
{
	this->currentColor = color;
	this->board = board;
}

void SearchNode::addVisit()
{
	this->visitCount ++;
}

bool SearchNode::isVisited()
{
	return visited;
}

void SearchNode::addWin()
{
	this->winCount ++;
}


bool SearchNode::visitNode()
{
	visited = true;
	this->addVisit();
	this->createChildren();

}

Chessboard SearchNode::getBoard()
{
	return board;
}

shared_ptr<SearchNode> SearchNode::getParent()
{
	return parent;
}

vector<pair<shared_ptr<SearchNode>, coordinate_t>> SearchNode::getChildren()
{
	return children;
}

double SearchNode::getUCTValue()
{
	double score = double(this->getReward()) / this->getAccessTime() +
                    c * std::sqrt(2 * std::log(this->parent->getAccessTime()) / double(this->getAccessTime()));
}


void SearchNode::createChildren()
{
	Chesscolor childcolor = -currentColor;

	vector<coordinate_t> possibleChildren = board.getPlaceable(childcolor);
	if (possibleChildren.empty())
	{
		childcolor = currentColor;
		possibleChildren = board.getPlaceable(childcolor);
	}

	for (auto positions : possibleChildren)
	{
		steps.push_back(positions);
		const Chessboard* newboard = board;
		if (newboard->putChess(positions, childcolor))
		{
			shared_ptr<SearchNode> child = make_shared<SearchNode>(new SearchNode(childcolor, newboard));
			child->parent = this;
			children.push_back(child);
		}
	}

}

