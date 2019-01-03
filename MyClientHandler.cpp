//
// Created by sara on 30/12/18.
//

#include "MyClientHandler.h"
template <class P, class S>
MyClientHandler<P,S>::MyClientHandler(Solver<P, S>* solver, CacheManager<P, S>* cm){
    this->solver = solver;
    this->cm = cm;
}
template <class P, class S>
void MyClientHandler<P,S>::handleClient(istream input, ostream output) {


}
