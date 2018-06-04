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
    vector<shared_ptr<SearchNode>> children;
    vector<coordinate_t> steps;
public:
    SearchNode(Chesscolor color, const Chessboard& board); 
    bool visitNode(); //vC++, visited, createChildren
    vector<pair<shared_ptr<SearchNode>, coordinate_t>> getChildren();
    shared_ptr<SearchNode> getParent();
    double getUCTValue();
    void addVisit();
    void addWin();
    bool isVisited();
    Chessboard getBoard();
};

