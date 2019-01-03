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
public:
    Matrix(vector<vector<T>> values, pair<int,int> in, pair<int,int> out);
    State<T> *getInitialState() override;

    State<T> *getGoalState() override;

    list<State<T> *> getAllPossibleStates(State<T> s);

};


#endif //PROJ2_MATRIX_H
