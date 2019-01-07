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

template <class Node>
class ShortestPathSolver : public Solver<Matrix, vector<string>> {
    SearchSolver<Node>* searchSolver;
    ConvertSolver* convertSolver;
public:
    vector<string> solve(Matrix matrix) override {
        vector<Node> path=searchSolver->solve(matrix);
        return convertSolver->solve(path);
    }
};


#endif //PROJ2_SHORTESTPATHSOLVER_H
