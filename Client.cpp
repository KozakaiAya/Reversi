//
// Created by qian on 18-6-9.
//

#include <iostream>
#include <boost/asio.hpp>
#include "Client.h"

using namespace boost::asio;
using namespace std;

string Client::httpGET(string url) {
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string(this->serverIP), serverPort);
    ip::tcp::socket sock(service);
    sock.open(ip::tcp::v4());
    sock.connect(ep);

    boost::asio::streambuf req;
    ostream os(&req);
    os << "GET " << url << " HTTP/1.0\r\n";
    os << "Host: " << serverIP << "\r\n";
    os << "Accept: */*\r\n";
    os << "Connection: close\r\n\r\n";
    write(sock, req);

    boost::asio::streambuf response;
    read_until(sock, response, "\r\n");

    string http_verion, status_code, msg, ret;
    istream is(&response);
    is >> http_verion >> status_code;
    getline(is, msg);

    boost::asio::read_until(sock, response, "\r\n\r\n");

    // Process the response headers.
    string header;
    while (std::getline(is, header) && header != "\r");
    //std::cout << header << "\n";
    //std::cout << "\n";

    // Write whatever content we already have to output.
    // This is the real thing that we want
    if (response.size() > 0)
        //std::cout << &response;
        is >> ret;

    // Read until EOF, writing data to output as we go.
    boost::system::error_code error;
    while (boost::asio::read(sock, response, boost::asio::transfer_at_least(1), error));
    //std::cout << &response;

    return ret;
}


Chesscolor Client::createSession(string sessionID) {
    this->sessionID = sessionID;
    while (1) {
        string req = "create_session/" + sessionID;
        string ret = httpGET(req);
        if (ret == "W") {
#ifdef _NETWORK_DEBUG_
            cout << "Session created. My color is: " << Chesscolor::WHITE << endl;
#endif
            return Chesscolor::WHITE;
        }
        else if (ret == "B") {
#ifdef _NETWORK_DEBUG_
            cout << "Session created. My color is: " << Chesscolor::BLACK << endl;
#endif
            return Chesscolor::BLACK;
        }
    }
}

bool Client::move(int x, int y, Chesscolor color) {
    while (1) {
        string req = "move/" + sessionID + "/" + to_string(x) + "/" + to_string(y) + "/" + to_string(color);
        string ret = httpGET(req);
        if (ret == "SUCCESS") {
#ifdef _NETWORK_DEBUG_
            cout << "Move (" << x << ", " << y << ") succeeded." << endl;
#endif
            return true;
        } else if (ret == "ERROR") {
#ifdef _NETWORK_DEBUG_
            cout << "Move (" << x << ", " << y << ") error." << endl;
#endif
            return false;
        }
    }
}

string Client::getBoard() {
    while (1) {
        string req = "board_string/" + sessionID;
        string ret = httpGET(req);
        if (ret.length() == 127) {
#ifdef _NETWORK_DEBUG_
            cout << "Current board_string: " << ret << endl;
#endif
            return ret;
        }
    }

}

Chesscolor Client::turn() {
    while (1) {
        string req = "turn/" + sessionID;
        string ret = httpGET(req);
        if (ret == "W") {
#ifdef _NETWORK_DEBUG_
            cout << "Current Turn: " << ret << endl;
#endif
            return Chesscolor::WHITE;
        }
        else {
#ifdef _NETWORK_DEBUG_
            cout << "Current Turn: " << ret << endl;
#endif
            return Chesscolor::BLACK;
        }
    }
}
