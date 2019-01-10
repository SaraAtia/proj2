//
// Created by sara on 31/12/18.
//

#ifndef PROJ2_MYPARALLELSERVER_H
#define PROJ2_MYPARALLELSERVER_H
#include "Server.h"

class MyParallelServer : public server_side::Server{
public:
    void open(int port, ClientHandler *clientHandler) override;

    void stop(std::stack<pthread_t> threads) override;

};


#endif //PROJ2_MYPARALLELSERVER_H