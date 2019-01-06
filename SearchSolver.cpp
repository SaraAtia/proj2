//
// Created by sara on 03/01/19.
//

#include "SearchSolver.h"
template<class P, class S>
SearchSolver<P,S>::SearchSolver(Searcher<S> searcher){
    this->searcher = searcher;
}

template<class P, class S>
S SearchSolver<P,S>::solve(Searchable<S> p){
    return this->searcher->search(p);
}