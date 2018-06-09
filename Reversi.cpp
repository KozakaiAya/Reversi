#include <iostream>
#include <map>
#include <algorithm>

#include "Global.h"
#include "SearchTree.h"
#include "MCTS.h"
#include "Client.h"

#define _NETWORK_RUN_

using namespace std;

int main()
{
#ifdef _NETWORK_RUN_
    Client client("47.89.179.202", 5000);
    /*
    cout << client.createSession("5") << endl;
    cout << "----------------------" << endl;
    cout << client.turn() << endl;
    cout << "----------------------" << endl;
    cout << client.move(2, 4, Chesscolor::WHITE) << endl;
    cout << "----------------------" << endl;
    cout << client.getBoard() << endl;
    */
    string sessionID;
    cout << "Please input session ID: ";
    cin >> sessionID;
    Chesscolor myColor = client.createSession(sessionID);
    while (1) {
        Chesscolor currentColor = client.turn();
        if (currentColor == myColor) {
            string curBoardStr = client.getBoard();
            Chessboard curBoard(curBoardStr);
            MCTS mcts(curBoard, -myColor, chrono::milliseconds(1000));
            coordinate_t nextStep = mcts.getNextStep();
            client.move(nextStep.first, nextStep.second, myColor);
        }
    }

#else
    cout << "Please input color (-1 for White, 1 for Black): " << endl;
    //    int inputcolor;
//    cin >> inputcolor;
//inputcolor == -1 ? Chesscolor::WHITE :
    Chesscolor color =  Chesscolor::BLACK;
    cout << color << endl;
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
#endif
};
