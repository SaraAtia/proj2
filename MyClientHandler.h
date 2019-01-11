//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "Matrix.h"
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
        getAllInfo(clientData);
        //convert data to matrix with its info;
        vector<vector<double>> vec = convertToDouble(clientData->matrix);
        Point in = convertToPoint(clientData->entryPoint);
        Point out = convertToPoint(clientData->exitPoint);
        Matrix mat = new Matrix(vec, in, out);
        if(cm->isSolved(mat)){
            S solution = cm->getSolution(mat);
            send(clientData->socketID, solution, sizeof(solution), 0);
        } else {
            S solution = solver->solve(mat);
            cm->saveProblem(mat.to_String(), solution);
            send(clientData->socketID, solution, sizeof(solution), 0);
        }

    }

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H