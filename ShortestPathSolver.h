//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_SHORTESTPATHSOLVER_H
#define PROJ2_SHORTESTPATHSOLVER_H


#include "SearchSolver.h"
#include "ConvertSolver.h"
#include "Matrix.h"
template <class T>
class ShortestPathSolver : public Solver<Matrix*, string> {
    SearchSolver<pair<int,int>>* searchSolver;
    ConvertSolver* convertSolver;
public:
    explicit ShortestPathSolver(Searcher<pair<int,int>>* searcher)
    :searchSolver(new SearchSolver<pair<int,int>>(searcher)), convertSolver(new ConvertSolver()){
//        this->searchSolver = new SearchSolver<pair<int,int>>(searcher);
//        this->convertSolver = new ConvertSolver();
    }
    string solve(Matrix* matrix) override {
        vector<T> path= this->searchSolver->solve(matrix);

//        vector<pair<int, int>> path= this->searchSolver->solve(matrix);
        return convertSolver->solve(path);
    }
    virtual ~ShortestPathSolver(){
        delete searchSolver;
        delete convertSolver;
    }
};


#endif //PROJ2_SHORTESTPATHSOLVER_H
