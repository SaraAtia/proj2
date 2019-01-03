//
// Created by sara on 03/01/19.
//

#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(vector<vector<T>> values, pair<int,int> in, pair<int,int> out){
    vector<vector<State<T>*>> tempMatrix;
    for(vector<T> row: values){
        vector<
        for(T node: row){
            tempMatrix.push_back(new State<int>(node));
        }
    }
}

template <class T>
State<T> *Matrix<T>::getInitialState() {
    return this->matrix.at(0).at(0);
}

template <class T>
State<T> *Matrix<T>::getGoalState(){
}

template <class T>
list<State<T>*> Matrix<T>::getAllPossibleStates(State<T> s){
}