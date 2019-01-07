//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_SEARCHSOLVER_H
#define PROJ2_SEARCHSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class P, class S>
class SearchSolver : public Solver<Searchable<State<P> > *, S>{
    Searcher<P>* searcher; // an algorithm to search
public:
    explicit SearchSolver(Searcher<P>* searcher){
        this->searcher = searcher;
    }

    S solve(Searchable<State<P> >* p) override{
        return this->searcher->search(p);
    }
};


#endif //PROJ2_SEARCHSOLVER_H
