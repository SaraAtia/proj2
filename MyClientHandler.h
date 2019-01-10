//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template <class P, class S>
class MyClientHandler : public ClientHandler{
    Solver<P, S>* solver;
    CacheManager<P, S>* cm;
public:
    MyClientHandler(Solver<P, S>* solver, CacheManager<P, S>* cm){
        this->solver = solver;
        this->cm = cm;
    }

    void handleClient(int socketID) override;

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H