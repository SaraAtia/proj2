//
// Created by sara on 30/12/18.
//


#include "MyClientHandler.h"

// get info and insert to vector<vector<string>> (after sending to lexer)
// check if info is solved in "Cache Manager" - if not send to Solver
// if you solved - add new solution to map (FileCacheManger)
// send solution
void readLine(ClientData* clientData){
    //todo: need to be parameters from outside
    clientData->buffer = new char;
    clientData->line.clear();
    int i;
    for(i = 0; read(clientData->socketID, clientData->buffer+i, 1)!=0; i++){
        if(*(clientData->buffer+i)=='\n'){
            break;
        }
    }
    for(int j = 0; j < i; j++){
        clientData->line += *(clientData->buffer+j);
    }
    delete(clientData->buffer);
}
void getAllInfo(ClientData* clientData){
    int flag = 1;

    while(flag){
        readLine(clientData);
        if(clientData->line == "end"){
            flag--;
            continue;
        }
        vector<string> lineRead;
        clientData->lineRead.push_back(clientData->line);
        clientData->matrix.push_back(clientData->lineRead);
    }
    vector<string> entryPoint;
    readLine(clientData);
    clientData->entryPoint = clientData->line;
    readLine(clientData);
    clientData->exitPoint = clientData->line;
}

/**
 * in order to separate buffer and info of every thread the
 * function will receive struct which will have all data-structures needed to store it's info
 * @param socketID
 */
