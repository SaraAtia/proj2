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
/*    Point convertToPoint(string pointStr){
        int pos = pointStr.find(",");
        string token = pointStr.substr(0, pos);
        int num1=stoi(token);
        pointStr.erase(0, pos + 1);
        int num2=stoi(pointStr);
        return Point(num1,num2);
    }*/
    void handleClient(int socketID) override{

        auto result = getAllInfo(socketID);
        //convert data to matrix with its info;
        string str = join(get<0>(result), ",!");

        string in = /*convertToPoint(*/get<1>(result);
        string out = /*convertToPoint(*/get<2>(result);
        str+=+"%"+in+","+out+",";
        if(cm->isSolved(str)){
            string solution = cm->getSolution(str);
            send(socketID, solution.c_str(), sizeof(solution), 0);
            close(socketID);
        } else {
            Matrix* mat = Matrix::readFromString(str);
            string solution = solver->solve(mat);
            cm->saveProblem(mat->to_String(), solution);
            send(socketID, solution.c_str(), sizeof(solution), 0);
            close(socketID);
        }

    }

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H