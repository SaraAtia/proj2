//
// Created by sara on 31/12/18.
//

#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include "State.h"
#include <list>
using namespace std;
template <class Node> // Node marks the position of the state
class Searchable{
// TODO searchable
public:
    virtual State<Node> getInitialState()=0;

    virtual Node getInitialNode()=0;

    virtual Node getGoalNode()=0;

    virtual list<State<Node>> getAllPossibleStates(State<Node> s)=0;
};
#endif //PROJ2_SEARCHABLE_H
