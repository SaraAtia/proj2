//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H


#include <vector>
#include "Searchable.h"
template <class T>
class Matrix: public Searchable<T> {
    vector<vector<State<T>*>> matrix;
    vector<vector<T>> values;
    State<T>* initialState;
    State<T>* goalState;
public:
    Matrix(vector<vector<T>> values, pair<int,int> in, pair<int,int> out){
        this->values=values;
        vector<vector<State<T>*>> tempMatrix;
        for(int i=0;i<values.size();i++){
            vector<State<T>*> rowStates;
            vector<T> row = values[i];
            for(int j=0;j<row.size();j++){
                rowStates.push_back(new State<pair<int,int>>(pair<int,int>(i,j)));
            }
            tempMatrix.push_back(rowStates);
        }
        this->matrix=tempMatrix;
        this->initialState = this->matrix[in.first][in.second];
        this->goalState = this->matrix[out.first][out.second];
    }


    State<T> *getInitialState() override {
        return this->initialState;
    }


    State<T> *getGoalState() override{
        return this->goalState;
    }
//TODO

    list<State<T>*> getAllPossibleStates(State<T> s) override{
    }

    vector<vector<T>> getValues() override{
        return this->values;
    }
};


#endif //PROJ2_MATRIX_H
