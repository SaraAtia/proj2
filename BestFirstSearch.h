//
// Created by paz on 03/01/19.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include "Searcher.h"
template <class S>
class BestFirstSearch: public Searcher<S> {
public:
    virtual vector<State<S>*> search(Searchable<S> *searchable);
};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
