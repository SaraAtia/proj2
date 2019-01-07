#include <utility>

//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H


#include <vector>
#include "Searchable.h"

class Matrix: public Searchable<pair<int, int> > {
    using Point = pair<int, int>;

    vector<vector<double>> values;
    State<Point> initialState;
    Point goalNode;
public:
    Matrix(vector<vector<double>> values, Point in, Point out):
        initialState(in, 0, nullptr) {
        this->values = std::move(values);
        this->goalNode = out;
        initialState.setCost(get_price(in));
    }


    State<Point> getInitialState() override {
        return this->initialState;
    }

    Point getInitialNode()  override    {
        return this->initialState.getState();
    }


    Point getGoalNode() override{
        return this->goalNode;
    }
//TODO

    list<State<Point>> getAllPossibleStates(State<pair<int,int>> s) override{
        // TODO TODO SARAH
        return list<State<Point>>();

    }

    vector<vector<double >> getValues(){
        return this->values;
    }
private:
    double get_price(pair<int, int> p)  {
        return this->values[p.first][p.second];
    }
};


#endif //PROJ2_MATRIX_H
