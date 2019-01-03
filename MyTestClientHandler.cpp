//
// Created by sara on 30/12/18.
//

#include "MyTestClientHandler.h"
template <class P, class S>
MyTestClientHandler<P,S>::MyTestClientHandler(Solver<P, S>* solver, CacheManager<P, S>* cm){
    this->solver = solver;
    this->cm = cm;
}
template <class P, class S>
void MyTestClientHandler<P,S>::handleClient(istream input, ostream output) {


}
