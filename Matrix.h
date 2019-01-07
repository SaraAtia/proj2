//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H


#include <vector>
#include "Searchable.h"
class Matrix: public Searchable<pair<int,int>> {
    vector<vector<State<pair<int,int>>*>> matrix;
    vector<vector<double>> values;
    State<pair<int,int>>* initialState;
    State<pair<int,int>>* goalState;
public:
    Matrix(vector<vector<double>> values, pair<int,int> in, pair<int,int> out){
        this->values=values;
        vector<vector<State<pair<int,int>>*>> tempMatrix;
        for(int i=0;i<values.size();i++){
            vector<State<pair<int,int>>*> rowStates;
            //vector<T> row = values[i];
            for(int j=0;j<values[i].size();j++){
                rowStates.push_back(new State<pair<int,int>>(pair<int,int>(i,j)));
            }
            tempMatrix.push_back(rowStates);
        }
        this->matrix=tempMatrix;
        this->initialState = this->matrix[in.first][in.second];
        this->goalState = this->matrix[out.first][out.second];
    }


    State<pair<int,int>> *getInitialState(){
        return this->initialState;
    }


    State<pair<int,int>> *getGoalState() override{
        return this->goalState;
    }
//TODO

    list<State<pair<int,int>>*> getAllPossibleStates(State<pair<int,int>> s) override{
    }

    vector<vector<double >> getValues(){
        return this->values;
    }
};


#endif //PROJ2_MATRIX_H
