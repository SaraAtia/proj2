//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H


//a -> MATRIX , vector[MATRIX] == map<Matrix, Solu>
#include "CacheManager.h"
#include <vector>
#include <map>
#include <string>
enum Problems{MATRIX, PATH, REVERS};
using namespace std;
template<class P, class S>
class FileCacheManager : public CacheManager<P, S>{
    vector<map<string,S>>  problemsType;
public:
    bool isSolved(P *p) override{
        //
    }


    S* getSolution(P *p) override{
        return nullptr;
    }


    void saveProblem(P *p, S *s) override{

        //this->problemsType.at(p->to_string(),s)
    }
/*
 * todo: every solution will have "convert to string" method
 *
 */
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
