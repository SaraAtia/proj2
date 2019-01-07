//
// Created by sara on 07/01/19.
//


//#include "Searcher.h"
#include <iostream>
#include "Matrix.h"
#include "SearchSolver.h"
#include "BestFirstSearch.h"
/*namespace boot{
    class Main{
        int main(int argv, string argc[]) {
            Server* s = new MySerialServer();
            Solver<string, string>* solver = new StringReverser();
            CacheManager<string, string> *manager = new FileCacheManager<string, string>();
            ClientHandler* clientHandler = new MyClientHandler<string,string>(solver,manager);
            s->open(stoi(argc[0]), clientHandler);
            return 0;
        }
    };
}*/
//using namespace std;
int main(){
    /*Solver<vector<State<pair<int,int>>*>,vector<string>>* cs = new ConvertSolver();
    State<pair<int,int>>* a = new State<pair<int,int>>(pair<int,int>(0,0));
    State<pair<int,int>>* b = new State<pair<int,int>>(pair<int,int>(1,0));
    State<pair<int,int>>* c = new State<pair<int,int>>(pair<int,int>(1,1));
    State<pair<int,int>>* d = new State<pair<int,int>>(pair<int,int>(0,1));
    State<pair<int,int>>* e = new State<pair<int,int>>(pair<int,int>(0,0));
    vector<State<pair<int,int>>*> vec;
    vec.push_back(a) ;
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);
    vec.push_back(e);
    vector<string> sol = cs->solve(vec);
    for(string s:sol){
        cout<< s<<", ";
    }*/
    typedef pair<int, int> Point;
    vector<vector<double>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    Searchable<Point>* searchable = new Matrix(mat,make_pair(0,0), make_pair(2,2));
   // Searcher<pair<int,int>>* searcher=new BestFirstSearch<pair<int,int>>();
    Solver<Searchable<Point>*,vector<State<Point>>>* solver=
            new SearchSolver<Point,vector<State<Point>>> (new BestFirstSearch<Point>());
    solver->solve(searchable);
    return 0;
}