//
// Created by sara on 03/01/19.
//

#include <string>
#include "ShortestPathSolver.h"
#include "Matrix.h"
template <class T>
vector<string> *ShortestPathSolver<T>::solve(Matrix<T> *matrix) {
    vector<State<T>*> path=searchSolver->solve(matrix);
    return convertSolver->solve(path);
}
