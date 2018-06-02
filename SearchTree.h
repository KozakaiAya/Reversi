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
    color_t currentColor;
    shared_ptr<SearchNode> parent;
    vector<shared_ptr<SearchNode>> children;
public:
    SearchNode(color_t color, const Chessboard& board); 
    bool visitNode(); //vC++, visited, createChildren
    vector<shared_ptr<SearchNode>> getChildren();
    shared_ptr<SearchNode> getParent();
    double getUCTValue();
    void addVisit();
    void addWin();
    bool isVisited();
};

