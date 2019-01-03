//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_CONVERTSOLVER_H
#define PROJ2_CONVERTSOLVER_H


#include "Solver.h"
#include <vector>
#include <string>
#include "State.h"
using namespace std;
template <class T>
class ConvertSolver : public Solver<vector<State<T>*>, vector<string>>{
public:
    vector<string> *solve( vector<State<T>*> path) override;
};


#endif //PROJ2_CONVERTSOLVER_H
