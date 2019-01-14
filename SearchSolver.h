//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_SEARCHSOLVER_H
#define PROJ2_SEARCHSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class Node>
class SearchSolver : public Solver<Searchable<Node>* , vector<Node>>{
    Searcher<Node>* searcher; // an algorithm to search
public:
    explicit SearchSolver(Searcher<Node>* searcher){
        this->searcher = searcher;
    }

    vector<Node> solve(Searchable<Node>* p) override{
        return this->searcher->search(p);
    }
};


#endif //PROJ2_SEARCHSOLVER_H
