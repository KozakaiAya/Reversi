#ifndef REVERSI_SEARCHTREE_H
#define REVERSI_SEARCHTREE_H
#include <vector>
#include <memory>

#include "Global.h"
#include "Chessboard.h"

using namespace std;

class SearchNode
{
private:
    Chessboard board;
    int visitCount, winCount;
    bool visited;
    Chesscolor currentColor;
    shared_ptr<SearchNode> parent;
    vector<pair<shared_ptr<SearchNode>, coordinate_t>> children;
    vector<coordinate_t> steps;
    void createChildren();
public:
    SearchNode(Chesscolor color, const Chessboard& board);
    bool visitNode(); //vC++, visited, createChildren
    vector<pair<shared_ptr<SearchNode>, coordinate_t>> getChildren();
    shared_ptr<SearchNode> getParent(); //
    double getUCTValue( double );
    int getWin();
    int getVisit();
    void addVisit(); //
    void addWin();  //
    bool isVisited(); //
    Chessboard getBoard(); //
};

#endif