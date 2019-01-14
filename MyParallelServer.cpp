//
// Created by sara on 31/12/18.
//

#include <netinet/in.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "MyParallelServer.h"
#include "TCP_sockets.h"

struct MyClientParams{
    ClientHandler* cl;
    int socketID;
};

void* threadFunc(void* info){
    MyClientParams* clientParams = (MyClientParams*) info;
    clientParams->cl->handleClient(clientParams->socketID);
}
/**
 * open server and get client - one a client will log in the limited time requested (1 second)
 * it will open new thread which will handel the client.
 * @param port
 * @param clientHandler
 */
void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    stack<pthread_t> threads;


    stack<posix_sockets::TCP_client> sockets;
    posix_sockets::TCP_server server(port);
//    int mainSocketID = socket(AF_INET, SOCK_STREAM, 0);
//    sockets.push(mainSocketID);
//    struct sockaddr_in server;
//    server.sin_addr.s_addr = INADDR_ANY;
//    server.sin_port = htons(port);
//    server.sin_family = AF_INET;
//    if(bind(mainSocketID, (sockaddr*)&server, sizeof(server)) < 0){
//        std::cerr << "Failed creating main socket!" << std::endl;
//    }
//    struct sockaddr_in client;
//    listen(mainSocketID,5);
//    int clilen = sizeof(client);
    server.listen(5);
//    timeval timeout;
//    timeout.tv_usec = 0;
//    setsockopt(mainSocketID, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout));
    while(true){
//        timeout.tv_sec = 1;
//        int newClient = accept(mainSocketID, (struct sockaddr *) &client, (socklen_t*)&clilen);
//        if (newClient < 0) {
//            if(errno == EWOULDBLOCK){
//                cout << "timeout!" << endl;
//                break;
//            } else {
//                __throw_invalid_argument("ERROR on accept");
//            }
//        }
        try {
            posix_sockets::TCP_client client = server.accept();
            sockets.push(client);
            MyClientParams* MCP = new MyClientParams();
            MCP->cl = clientHandler;
            MCP->socketID = client.get_sock();
            pthread_t clientThread;
            if(pthread_create(&clientThread, nullptr, threadFunc, MCP)!=0){
                __throw_invalid_argument("ERROR in creating thread");
            }
            threads.push(clientThread);
        }   catch (posix_sockets::timeout_exception& e) {
            break;
        }

        server.settimeout(10);  // TODO change to 1
    }
    cout << "No more clients!" << endl;
}

void MyParallelServer::stop(std::stack<pthread_t> threads) {
    while(!threads.empty())  {
        pthread_join(threads.top(), nullptr);
        threads.pop();
    }
}