//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_SHORTESTPATHSOLVER_H
#define PROJ2_SHORTESTPATHSOLVER_H


#include <vector>
#include "Solver.h"
#include "SearchSolver.h"
#include "ConvertSolver.h"
#include "Matrix.h"

template <class T>
class ShortestPathSolver: public Solver<Matrix<T>, vector<string>> {
    SearchSolver<Matrix<T>,vector<State<T>*>> searchSolver;
    ConvertSolver* convertSolver;
public:
    vector<string> *solve(Matrix<T> *matrix) override;
};


#endif //PROJ2_SHORTESTPATHSOLVER_H
