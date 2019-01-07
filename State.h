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
    State(T state){
        this->position = state;
        this->cost = 0;
        this->cameFrom = nullptr;
    }

    bool equals(State<T>* other) {
        return (this->position == other->position);
    }

    void setCost(double cost){
        this->cost = cost;
    }

    void setCameFrom(State<T>* state){
        this->cameFrom = state;
    }


    T getState() {
        return position;
    }


    double getCost() const {
        return cost;
    }


    const State<T> getCameFrom() {
        return cameFrom;
    }
};
#endif //PROJ2_STATE_H
