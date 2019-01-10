//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <istream>
#include <sys/socket.h>
using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int socketID)=0;
};


#endif //PROJ2_CLIENTHANDLER_H