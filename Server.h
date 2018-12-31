//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H
#include "ClientHandler.h"
namespace server_side{
    class Server{
    public:
        // should open server and wait for clients
        virtual void open(int port, ClientHandler* clientHandler)=0;
        // close the server
        virtual void stop()=0;
        // add more relevant methods - send.

    };
}
#endif //PROJ2_SERVER_H
