//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H


#include "CacheManager.h"
template<class P, class S>
class FileCacheManager : public CacheManager<P, S>{
    bool isSolved(P *p) override {

    }

    S *getSolution(P *p) override {
        return nullptr;
    }

    void saveProblem(P *p, S *s) override {

    }

};


#endif //PROJ2_FILECACHEMANAGER_H
