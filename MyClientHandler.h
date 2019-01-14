//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H

#include <tuple>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Matrix.h"

using Point = pair<int,int>;

string join(vector<string> s, string sym);

tuple<vector<string>, string, string> getAllInfo(int socketID);


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
    CacheManager<string, string>* cm;


public:
    MyClientHandler(Solver<P, S>* solver, CacheManager<string, string>* cm){
        this->solver = solver;
        this->cm = cm;
    }
    Point convertToPoint(string pointStr){
        return pair<int,int>(0,0);//todo
    }
    void handleClient(int socketID) override{

        auto result = getAllInfo(socketID);
        //convert data to matrix with its info;
        string str = join(get<0>(result), "!");

        Point in = convertToPoint(get<1>(result));
        Point out = convertToPoint(get<2>(result));

        Matrix* mat = Matrix::readFromString(str);
        if(cm->isSolved(mat->to_String())){
            string solution = cm->getSolution(mat->to_String());
            send(socketID, solution.c_str(), sizeof(solution), 0);
            close(socketID);
        } else {
            string solution = solver->solve(mat);
            cm->saveProblem(mat->to_String(), solution);
            send(socketID, solution.c_str(), sizeof(solution), 0);
            close(socketID);
        }

    }

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H