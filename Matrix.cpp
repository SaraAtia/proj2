//
// Created by sara on 03/01/19.
//

#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(vector<vector<T>> values, pair<int,int> in, pair<int,int> out){

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