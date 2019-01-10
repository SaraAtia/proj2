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
#include <fstream>

using namespace std;
template<class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution>{
    map<Problem,Solution>  cache;
public:
    bool isSolved(Problem p) override{
        if(!cache.count(p))
            return false;
        return true;
    }


    Solution getSolution(Problem p) override{
        return cache.at(p);
    }


    void saveProblem(Problem p, Solution s) override{
        cache.insert(make_pair(p,s));
    }
    //todo read in the destructor
    void writeToFile(const string& file_name){
        fstream file;
        file.open (file_name, std::fstream::in | std::fstream::out | std::fstream::app);
        for(auto p:cache){
            file<<(p.first)/*->to_String()*/;
            file<< "$";
            file<<(p.second)/*todo check->to_String()*/;
            file<<"\n";
        }
        file.close();
    }
    void readFromFile(const string& file_name){
        fstream file;
        file.open (file_name, std::fstream::in | std::fstream::out | std::fstream::app);
        ifstream infile(file_name);
        if(file.peek() == std::ifstream::traits_type::eof()){
            return;
        }
        string line;
        size_t pos = 0;
        string token;
        while(getline(infile, line)){
            pos = line.find("$");
            token = line.substr(0, pos);
            Problem problem=token;
            line.erase(0, pos + 1);
            Solution solution=line;
            this->cache.insert(make_pair(problem,solution));
        }
    }
};
/*
 * in the distructor we'll update the file
 */
#endif //PROJ2_FILECACHEMANAGER_H
