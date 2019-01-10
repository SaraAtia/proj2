//
// Created by sara on 31/12/18.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Solver.h"
#include "Searchable.h"
#include <vector>
template <class Node>
class Searcher{
public:
    virtual vector<Node> search(Searchable<Node> *s)=0;
    virtual int getNumberOfNodesEvaluated()=0;

};
#endif //PROJ2_SEARCHER_H

