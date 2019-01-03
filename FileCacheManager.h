//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H


#include "CacheManager.h"
template<class P, class S>
class FileCacheManager : public CacheManager<P, S>{

public:
    bool isSolved(P *p) override;

    S *getSolution(P *p) override;

    void saveProblem(P *p, S *s) override;

};
//todo: choose data base, and format for saving data in the file
/*
 * format - 3 col' separated by '?':
 * first index for problem type flag as letter
 * second index for problem info - will be read until '?'
 * third - solution
 */
/*
 * in the distructor we'll update the file
 */
#endif //PROJ2_FILECACHEMANAGER_H
