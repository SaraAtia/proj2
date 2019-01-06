//
// Created by sara on 03/01/19.
//

#include "State.h"
template <class T>
State<T>::State(T state){
    this->position = state;
    this->cost = 0;
    this->cameFrom = nullptr;
}
template <class T>
bool State<T>::equals(State<T>* other) {
    return (this->position == other->position);
}
template <class T>
void State<T>::setCost(double cost){
    this->cost = cost;
}

template <class T>
void State<T>::setCameFrom(State<T>* state){
    this->cameFrom = state;
}

template<class T>
T State<T>::getState() {
    return position;
}

template<class T>
double State<T>::getCost() const {
    return cost;
}

template<class T>
const State<T> State<T>::getCameFrom() {
    return cameFrom;
}
