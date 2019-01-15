//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H

template <class P, class S>
class Solver{
public:
    virtual S solve(P p)=0;
    virtual ~Solver()= default;
};
#endif //PROJ2_SOLVER_H
