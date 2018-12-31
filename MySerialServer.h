//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;
class MySerialServer : public Server{
    void open(int port, ClientHandler* clientHandler) override;

    void stop() override;

};


#endif //PROJ2_MYSERIALSERVER_H
