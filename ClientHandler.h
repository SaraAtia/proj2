//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

//#include <istream>

using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int socketID)=0;
    virtual ~ClientHandler()= default;
};


#endif //PROJ2_CLIENTHANDLER_H
