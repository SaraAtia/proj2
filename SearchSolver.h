//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_SEARCHSOLVER_H
#define PROJ2_SEARCHSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class P, class S>
class SearchSolver : Solver<P, S>{
    Searcher<S>* searcher; // an algorithm to search
public:
    SearchSolver(Searcher<S>* searcher);
    S *solve(Searchable<S> *p) override;
};


#endif //PROJ2_SEARCHSOLVER_H
