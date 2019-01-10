//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H
#include "Solver.h"

template <class P,class S>
class CacheManager{
    virtual bool isSolved(P p)=0;
    virtual S getSolution(P p)=0;
    virtual void saveProblem(P p, S s)=0;
};


#endif //PROJ2_CACHEMANAGER_H
