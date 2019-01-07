//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;
class MySerialServer : public Server{
    void open(int port, ClientHandler* clientHandler) override {

        /*
         * open a thread
         * open a socket
         * once someone is connected it the limited time we have assign to it - send to client handler
         * else - stop
         * after finished one client go to next client
         */
    }

    void stop() override {

    }

};


#endif //PROJ2_MYSERIALSERVER_H
