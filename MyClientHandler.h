//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include <unistd.h>
#include <vector>
struct ClientData{
    int socketID;
    vector<vector<string>> matrix;
    vector<string> lineRead;
    char* buffer;
    string line;
    string entryPoint;
    string exitPoint;
};
void readLine(ClientData* clientData);
void getAllInfo(ClientData* clientData);
template <class P, class S>
class MyClientHandler : public ClientHandler{
    Solver<P, S>* solver;
    CacheManager<P, S>* cm;


public:
    MyClientHandler(Solver<P, S>* solver, CacheManager<P, S>* cm){
        this->solver = solver;
        this->cm = cm;
    }

    void handleClient(/*void* clientInfo*/int socketID) override{
        void* clientInfo;

        ClientData* clientData = (ClientData*)clientInfo;

        getAllInfo(socketID, clientData);
    }

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H