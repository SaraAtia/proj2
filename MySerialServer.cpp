//
// Created by sara on 30/12/18.
//

#include "MySerialServer.h"

void MySerialServer::open(int port, ClientHandler* clientHandler) {

    /*
     * open a thread
     * open a socket
     * once someone is connected it the limited time we have assign to it - send to client handler
     * else - stop
     * after finished one client go to next client
     */
}

void MySerialServer::stop() {

}
