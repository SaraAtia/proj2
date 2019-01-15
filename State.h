//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H
#include <algorithm>
#include <iostream>

template <class T>
class State {
    T position;
    double cost;
    State<T> *cameFrom;
    bool visited;
public:
    ~State(){};
    State(T state): cost(0) {
        this->position = state;
//        this->cost = 0;
        this->cameFrom = nullptr;
        visited=false;
    }
    State(T position, double cost, State<T> *cameFrom): cost(cost) {
        this->position = position;
//        this->cost = cost;
        this->cameFrom = cameFrom;
        visited=false;
    }
    bool isVisited(){
        return visited;
    }
    void setVisited(bool flag){
        this->visited=flag;
    }

    bool equals(State<T> other) const {
        return (this->position == other.position);
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> *state) {
        this->cameFrom = state;
    }


    T getState() const {
        return position;
    }


    double getCost() const {
        return cost;
    }


    State<T>* getCameFrom() {
        return cameFrom;
    }

    bool operator<(const State<T> &other){
        return cost < other.cost;
    }

    bool operator==(const State<T> &other) const {
        return cost == other.cost;
    }
};

namespace std
{
    template<>
    struct hash<State<pair<int, int>>>
    {
        size_t operator()(const State<pair<int, int>> & ob) const
        {
            auto x = ob.getState();
            return hash<int>()(hash<int>()(x.first) ^ (x.second));
        }
    };
}
#endif //PROJ2_STATE_H
