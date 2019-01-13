//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <istream>

using namespace std;
class ClientHandler {
    virtual void handleClient(int socketID)=0;
};


#endif //PROJ2_CLIENTHANDLER_H
