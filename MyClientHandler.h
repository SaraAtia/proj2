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
#include <tuple>


using Point = pair<int,int>;

string join(vector<string> s, string sym);

tuple<vector<string>, string, string> getAllInfo(int socketID);
Point convertToPoint(string pointStr){

}

class SocketReader
{
    int sock_id;
    string buffer;
public:
    SocketReader(int sock_id) : sock_id(sock_id)    {

    }

    string readLine();
};

template <class P, class S>
class MyClientHandler : public ClientHandler{
    Solver<P, S>* solver;
    CacheManager<P, S>* cm;


public:
    MyClientHandler(Solver<P, S>* solver, CacheManager<P, S>* cm){
        this->solver = solver;
        this->cm = cm;
    }

    void handleClient(int socketID) override{

        auto result = getAllInfo(socketID);
        //convert data to matrix with its info;
        string str = join(get<0>(result), "!");
        Point in = convertToPoint(get<1>(result));
        Point out = convertToPoint(get<2>(result));

        Matrix* mat = Matrix::readFromString(str);
        if(cm->isSolved(mat)){
            S solution = cm->getSolution(mat);
            send(socketID, solution, sizeof(solution), 0);
        } else {
            S solution = solver->solve(mat);
            cm->saveProblem(mat->to_String(), solution);
            send(socketID, solution, sizeof(solution), 0);
        }

    }

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H