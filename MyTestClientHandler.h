//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
template <class P, class S>
class MyTestClientHandler : public ClientHandler{
    Solver<P, S>* solver;
    CacheManager<P, S>* cm;
public:
    MyTestClientHandler(Solver<P, S>* solver, CacheManager<P, S>* cm);
    void handleClient(istream input, ostream output) override;

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
