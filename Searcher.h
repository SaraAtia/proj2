//
// Created by sara on 31/12/18.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Solver.h"
#include "Searchable.h"
#include <vector>
template <class S>
class Searcher{
public:
    virtual vector<State<S>*> search(Searchable<S> *s)=0;
    //int getNumberOfNodesEvaluated();

};
#endif //PROJ2_SEARCHER_H

