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
//    int inputcolor;
//    cin >> inputcolor;
//inputcolor == -1 ? Chesscolor::WHITE :
    Chesscolor color =  Chesscolor::BLACK;
    cout << color;
    Chessboard global = Chessboard();
/*    Chesscolor t[8][8] = {{Chesscolor::BLACK, Chesscolor::WHITE, Chesscolor ::FREE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE},
    {Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE},
    {Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE},
    {Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE},
    {Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE},
    {Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE},
    {Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE},
    {Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE, Chesscolor::WHITE}};*/

    while (1) {
        MCTS mcts(global, -color, chrono::milliseconds(1500));
        int x, y;
        coordinate_t next_step = mcts.getNextStep();
        cout << next_step.first << " " << next_step.second << endl;
        cout << "Please input next step" << endl;
        cin >> x >> y ;
        global.putChess((next_step),color);
        global.putChess(make_pair(x, y), -color);
    }

};
