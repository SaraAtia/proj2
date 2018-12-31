//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H

template <class P, class S>
class Solver{
    virtual P* solve(S* p)=0;
};
#endif //PROJ2_SOLVER_H
