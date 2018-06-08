#include <iostream>
#include <map>
#include <algorithm>

#include "Global.h"
#include "SearchTree.h"
#include "MCTS.h"

using namespace std;

int main()
{
    cout << "Please input color (-1 for White, 1 for Black): " << endl;
    int inputcolor;
    cin >> inputcolor;
    Chesscolor color = inputcolor == -1 ? Chesscolor::WHITE : Chesscolor::BLACK;
    MCTS mcts(Chessboard(), color, chrono::milliseconds(1500));
    cout << mcts.getNextStep().first << mcts.getNextStep().second << endl;

};
