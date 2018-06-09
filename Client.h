//
// Created by qian on 18-6-9.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#include <iostream>
#include <string>

#include "Global.h"

using namespace std;

class Client {
private:
    string sessionID;
    string serverIP;
    long serverPort;

    string httpGET(string url);

public:
    Client(string serverIP, long port) : serverIP(serverIP), serverPort(port) {};

    Chesscolor createSession(string sessionID);

    bool move(int x, int y, Chesscolor color);

    string getBoard();

    Chesscolor turn();
};


#endif //REVERSI_CLIENT_H
