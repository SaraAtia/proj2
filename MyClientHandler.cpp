//
// Created by sara on 30/12/18.
//

#include <unistd.h>
#include <vector>
#include "MyClientHandler.h"

// get info and insert to vector<vector<string>> (after sending to lexer)
// check if info is solved in "Cache Manager" - if not send to Solver
// if you solved - add new solution to map (FileCacheManger)
// send solution
string readLine(int socketID){
    string line;
    char buffer[1];
    while(read(socketID, buffer, 1)!=0){
        if(buffer[0] =='\n')
            break;
        line += buffer[0];
    }
    return line;
}
vector<vector<string>> getAllInfo(int socketID){
    vector<vector<string>> matrixInfo;
    int flag = 1;
    string line;
    while(flag){
        line = readLine(socketID);
        if(line == "end"){
            flag--;
            continue;
        }
        vector<string> lineRead;
        lineRead.push_back(line);
        matrixInfo.push_back(lineRead);
    }
    vector<string> entryPoint;
    entryPoint.push_back(readLine(socketID));
    matrixInfo.push_back(entryPoint);
    vector<string> exitPoint;
    exitPoint.push_back(readLine(socketID));
    matrixInfo.push_back(exitPoint);
    return matrixInfo;
}
void handleClient(int socketID) {
    vector<vector<string>> matrixInfo = getAllInfo(socketID);
    string exitPoint = matrixInfo.back()[0];
    matrixInfo.pop_back();
    string entryPoint = matrixInfo.back()[0];
    matrixInfo.pop_back();
}