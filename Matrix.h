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
    Matrix(vector<vector<double>> values, Point in, Point out):initialState(State<Point>(in, get_price(in), nullptr)){
        this->values = std::move(values);
        this->goalNode = out;
//        this->initialState = State<Point>(in, get_price(in), nullptr);
    }


    State<Point > getInitialState() override {
        return this->initialState;
    }


    Point getGoalNode() override{
        return this->goalNode;
    }
//TODO

    list<State<pair<int,int>>> getAllPossibleStates(State<pair<int,int>> s) override{

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
