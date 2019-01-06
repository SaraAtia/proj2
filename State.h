//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H
template <class T>
class State{
    T position;
    double cost;
    State<T>* cameFrom;
public:
    State(T state);
    bool equals(State<T>* other); // todo: override equals in Object
    void setCost(double cost);
    void setCameFrom(State<T>* state);

    T getState();

    double getCost() const;

    const State<T> getCameFrom();
};
#endif //PROJ2_STATE_H
