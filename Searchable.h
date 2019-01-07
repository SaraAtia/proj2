//
// Created by sara on 31/12/18.
//

#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include "State.h"
#include <list>
using namespace std;
template <class T> // T marks the position of the state
class Searchable{

public:
    virtual State<T> getInitialState()=0;

    virtual T getGoalNode()=0;

    virtual list<State<T>> getAllPossibleStates(State<T> s)=0;
};
#endif //PROJ2_SEARCHABLE_H
