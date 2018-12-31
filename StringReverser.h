//
// Created by sara on 30/12/18.
//

#ifndef PROJ2_STRINGREVERSER_H
#define PROJ2_STRINGREVERSER_H


#include "Solver.h"
#include <string>
using namespace std;
class StringReverser : public Solver<string,string>{
    string *solve(string *p) override;

};


#endif //PROJ2_STRINGREVERSER_H
