//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H
template <class T>
class State{
    T state;
    double cost;
    State<T> cameFrom;
public:
    State(T state);
    bool equals(State<T> other) override;
    void setCost(double cost);
};
#endif //PROJ2_STATE_H
