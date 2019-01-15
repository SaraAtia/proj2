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
class ConvertSolver : public Solver<vector<pair<int,int>>, string>{
public:
    string solve(vector<pair<int,int>> path) override;
    virtual ~ConvertSolver()= default;
};


#endif //PROJ2_CONVERTSOLVER_H
