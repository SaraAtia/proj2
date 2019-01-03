//
// Created by sara on 31/12/18.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H

#include "Solver.h"
#include "Searchable.h"

template <class S>
class Searcher{
    S *search(Searchable<S> *s);
    //int getNumberOfNodesEvaluated();

};
#endif //PROJ2_SEARCHER_H
