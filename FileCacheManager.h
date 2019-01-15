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
    FileCacheManager(){
        readFromFile("cache.txt");
    }
    virtual ~FileCacheManager(){
        writeToFile("cache.txt");
    }
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
    /*
     * save the map to file in the end of the program
     */
    void writeToFile(const string& file_name){
        fstream file;
        file.open (file_name, std::fstream::in | std::fstream::out | std::fstream::app);
        for(auto p:cache){
            file<<(p.first);
            file<< "$";
            file<<(p.second);
            file<<"\n";
        }
        file.close();
    }
    /*
     * upload the file to the map of problem-solution
     */
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
            //problem and solution separate by $
            pos = line.find("$");
            token = line.substr(0, pos);
            Problem problem=token;
            line.erase(0, pos + 1);
            Solution solution=line;
            this->cache.insert(make_pair(problem,solution));
        }
    }
};
#endif //PROJ2_FILECACHEMANAGER_H
