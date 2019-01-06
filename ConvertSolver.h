//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_CONVERTSOLVER_H
#define PROJ2_CONVERTSOLVER_H

#include <vector>
#include <string>
#include "Solver.h"
#include "State.h"

using namespace std;
class ConvertSolver : public Solver<vector<State<pair<int,int>>*>, vector<string>>{
public:
    virtual vector<string> solve(vector<State<pair<int,int>>*> path);
};


#endif //PROJ2_CONVERTSOLVER_H
