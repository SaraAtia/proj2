//
// Created by sara on 03/01/19.
//

#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(vector<vector<T>> values, pair<int,int> in, pair<int,int> out){
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

template <class T>
State<T> *Matrix<T>::getInitialState() {
    return this->initialState;
}

template <class T>
State<T> *Matrix<T>::getGoalState(){
    return this->goalState;
}
//TODO
template <class T>
list<State<T>*> Matrix<T>::getAllPossibleStates(State<T> s){
}

template <class T>
vector<vector<T>> Matrix<T>::getValues(){
    return this->values;
}
