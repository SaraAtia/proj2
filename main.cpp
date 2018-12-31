#include <iostream>
#include "MySerialServer.h"
#include "Server.h"
#include "StringReverser.h"
#include "MyTestClientHandler.h"
#include "CacheManager.h"
#include "FileCacheManager.h"

namespace boot{
    class Main{
        int main(int argv, string argc[]) {
            Server* s = new MySerialServer();
            Solver<string, string>* solver = new StringReverser();
            CacheManager<string, string> *manager = new FileCacheManager<string, string>();
            ClientHandler* clientHandler = new MyTestClientHandler<string,string>(solver,manager);
            s->open(stoi(argc[0]), clientHandler);
            return 0;
        }
    };
}
