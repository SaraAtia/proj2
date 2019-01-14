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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
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
        string in = get<1>(result);
        string out = get<2>(result);
        str+=+"%"+in+","+out+",";
        string solution;
        pthread_mutex_lock(&mutex);
        if(cm->isSolved(str)){
            solution = cm->getSolution(str);
            cout<<"already solved";

        } else {
            Matrix* mat = Matrix::readFromString(str);
            solution = solver->solve(mat);
            cm->saveProblem(mat->to_String(), solution);
            cout<<"solving...";
        }
        pthread_mutex_unlock(&mutex);
        solution+="\r\n";
        send(socketID, solution.c_str(), sizeof(solution), 0);
        close(socketID);

    }

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H