//
// Created by sara on 07/01/19.
//


//#include "Searcher.h"
#include <iostream>
#include "Matrix.h"
#include "SearchSolver.h"
#include "BestFirstSearch.h"
#include "ConvertSolver.h"
//#include "Bfs.h"
#include "MyParallelServer.h"
#include "FileCacheManager.h"
#include "Dfs.h"
#include "Astar.h"
#include "Bfs.h"
#include "ShortestPathSolver.h"
#include "MyClientHandler.h"
#include <stdlib.h>
#include <time.h>
namespace boot{
    class Main{
        int main(int argv, string argc[]) {
            server_side::Server* s = new MyParallelServer();
            Solver<Matrix, string>* solver = new ShortestPathSolver<pair<int,int>>();
            CacheManager<Matrix, string> *manager = new FileCacheManager<Matrix, string>();
            ClientHandler* clientHandler = new MyClientHandler<Matrix, string>(solver,manager);
            s->open(stoi(argc[0]), clientHandler);
            return 0;
        }
    };
}
////using namespace std;
//int main() {
//
///*    Solver<vector<pair<int,int>>,string>* cs = new ConvertSolver();
//    vector<pair<int,int>> vec;
//    vec.push_back(make_pair(0,0)) ;
//    vec.push_back(make_pair(1,0));
//    vec.push_back(make_pair(1,1));
//    vec.push_back(make_pair(0,1));
//    vec.push_back(make_pair(0,0));
//    string sol = cs->solve(vec);
//    cout<<sol;*/
//    typedef pair<int, int> Point;
///*    vector<vector<double>> mat = {{ 8, 1, 6, 2, 8, 2, 9, 1, 8, 7, 5, 9, 8, 1, 1, 3, 6},
//                                  { 4, 1, 1, 9,10, 1, 7, 9, 1, 1, 2, 8, 9, 3,10, 6, 7},
//                                  { 1, 7, 8, 9, 1, 1, 1,10,10, 1,10, 1, 1,10, 3, 7, 5},
//                                  { 1, 7, 6, 9,10, 5,10, 6, 3, 8, 1, 7, 9, 7, 1, 7, 1},
//                                  { 9, 1, 3, 5, 6, 1,10, 4, 1, 7, 4, 6, 6, 2, 8,10, 5},
//                                  { 2, 2, 1, 1, 6, 1, 6, 4, 9, 5, 6,10, 7, 3, 3,10, 5},
//                                  { 3, 1, 3,10, 1, 8,10, 4, 9, 4, 9, 1, 3, 1, 1, 3, 8},
//                                  { 4, 1, 4, 8, 9, 1, 9, 3, 7, 8, 5, 1, 5, 1, 4, 4, 1},
//                                  { 1, 3, 9, 5, 5,10, 2, 3, 2, 8,10, 3, 5, 8, 6, 3, 2},
//                                  { 1, 4, 8,10, 9, 6, 1, 4, 1, 1, 5, 2,10, 3, 6, 8, 4},
//                                  { 1, 6, 2, 7, 1, 6, 4, 3, 4, 7, 6, 2, 7, 1, 5,10, 1},
//                                  { 9, 3, 1, 8, 8, 6, 7, 8, 1, 1, 1, 6, 3, 6, 4, 6, 9},
//                                  { 9, 6, 3, 6, 7, 3, 9, 5,10, 6, 7, 1, 3, 6, 9,10, 2},
//                                  { 7, 4, 3, 5, 4, 3, 6, 6, 6, 7, 2, 8, 4, 1, 6, 8, 1},
//                                  { 1, 2, 1, 2, 5, 2, 7, 1, 9, 3, 3, 4,10, 2, 1, 7, 9},
//                                  { 6, 5, 1, 3, 4,10, 3, 3, 1, 1, 5, 8, 1, 1, 9, 1, 9},
//                                  { 3, 2, 2, 3, 1, 4, 9, 3, 5, 3, 6, 5, 8, 4, 7, 6, 7}
//    };*/
///*    Searchable<Point> *searchable = new Matrix(mat, make_pair(0, 0), make_pair(2, 2));
//
//    vector<State<Point>> list1 = searchable->getAllPossibleStates(Point(1,0));
//    for(State<Point> s:list1){
//        cout<< s.getState().first<<", "<<s.getState().second<<endl;
//    }*/
///*    vector<vector<double>> mat = {{1, 2},
//                                  {3, 4}};*/
///*    vector<vector<double>> mat = {{ 4, 2, 9, 5, 7, 1, 7, 6, 3, 7, 8},
//            {4, 1,10, 8, 1, 1, 5, 5, 7, 8, 4},
//            {4, 5, 2, 8, 1, 1, 9, 3, 3, 1, 7},
//            {3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7},
//            {1, 3, 7, 3, 7,10, 4, 8, 9, 1, 1},
//            {7, 3, 2, 3, 5, 1, 2, 1, 6, 0, 9},
//            {6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8},
//            {10, 8, 1, 2, 3, 8, 1,10,10, 2, 7},
//            {5, 7, 1, 8, 8, 8, 1, 3, 4, 5, 1},
//            {7, 7, 5,10, 8,10, 1, 6, 9, 9, 1},
//            {5,10, 1,10, 7, 7, 3,10, 8, 1, 6}};*/
////todo test
//    vector<vector<vector<double>>> allmat;
//
//    int i=0;
//    srand(time(NULL));
//    while(i<10) {
//        vector<vector<double>> mat;
//        int n = rand() % 50 + 10;
//        for (int i = 0; i < n; i++) {
//            vector<double> row;
//            for(int j=0; j<n; j++){
//                row.push_back(rand() % 10 + 1);
//            }
//            mat.push_back(row);
//        }
//        allmat.push_back(mat);
//        Searchable<Point> *searchable = new Matrix(mat, make_pair(0, 0), make_pair(n-1, n-1));
//        Solver<Searchable<Point> *, vector<Point>> *bestFirstSearch =
//                new SearchSolver<Point>(new BestFirstSearch<Point>());
//        bestFirstSearch->solve(searchable);
//        Solver<Searchable<Point> *, vector<Point>> *dfs =
//                new SearchSolver<Point>(new Dfs<Point>());
//        dfs->solve(searchable);
//        Solver<Searchable<Point> *, vector<Point>> *bfs =
//                new SearchSolver<Point>(new Bfs<Point>());
//        bfs->solve(searchable);
//        Solver<Searchable<Point> *, vector<Point>> *astar =
//                new SearchSolver<Point>(new Astar<Point>());
//        astar->solve(searchable);
//        i++;
//    }
//    cout<<"***********************************************"<<endl;
//    cout<<"10"<<endl;
//    for(int k=0;k<10;k++){
//        cout<<allmat.at(k).size()<<endl;
//        cout<<"0,0"<<endl;
//        cout<<allmat.at(k).size()-1<<","<<allmat.at(k).size()-1<<endl;
//        for (int i = 0; i < allmat.at(k).size(); i++) {
//            for(int j=0; j<allmat.at(k).size()-1; j++){
//                cout<<allmat.at(k).at(i).at(j)<<", ";
//            }
//            cout<<allmat.at(k).at(i).at(allmat.at(k).size()-1)<<endl;
//        }
//    }
///*    vector<vector<double>> mat = { {4, 2, 9, 5, 7, 1, 7, 6, 3, 7, 8},
//                                   {4, 1,10, 8, 1, 1, 5, 5, 7, 8, 4},
//                                   {4, 5, 2, 8, 1, 1, 9, 3, 3, 1, 7},
//                                   {3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7},
//                                   {0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1},
//                                   {7, 3, 2, 3, 5, 1, 2, 1, 6, 1, 9},
//                                   { 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8},
//                                   {10, 8, 1, 2, 3, 8, 1,10,10, 2, 7},
//                                   {5, 7, 1, 8, 8, 8, 1, 3, 4, 5, 1},
//                                   {7, 7, 5,10, 8,10, 1, 6, 9, 9, 1},
//                                   {5,10, 1,10, 7, 7, 3,10, 8, 1, 6}};*/
///*
//    vector<vector<double>> mat = {{6, 7, 1, 3, 7, 6, 6, 6, 10, 10, 4, 5, 7, 8, 2, 6, 7, 4, 10, 5, 3, 7, 9, 8, 7, 3, 8, 10, 4, 4, 7, 9, 3, 8, 3},
//            {1, 5, 8, 9, 5, 7, 2, 1, 5, 10, 2, 3, 8, 7, 2, 4, 9, 8, 5, 8, 7, 7, 5, 6, 1, 1, 5, 1, 5, 4, 4, 5, 8, 1, 3},
//            {           4, 10, 7, 4, 4, 6, 5, 8, 5, 4, 10, 8, 4, 9, 2, 2, 7, 1, 8, 5, 1, 8, 9, 3, 2, 2, 6, 9, 1, 9, 3, 5, 10, 9, 8},
//{           3, 6, 5, 3, 10, 8, 4, 10, 1, 4, 1, 4, 1, 1, 2, 5, 3, 9, 3, 6, 3, 6, 3, 3, 6, 1, 5, 2, 10, 4, 10, 5, 9, 6, 7},
//{           1, 3, 2, 10, 5, 5, 10, 9, 5, 3, 10, 9, 7, 10, 3, 4, 2, 8, 9, 6, 6, 9, 1, 7, 1, 6, 8, 7, 4, 3, 5, 4, 5, 6, 3},
//{           2, 10, 5, 10, 7, 9, 1, 5, 5, 10, 8, 1, 4, 7, 9, 9, 4, 9, 1, 1, 9, 6, 8, 7, 10, 1, 3, 5, 7, 10, 10, 10, 10, 4, 1},
//{           8, 4, 1, 2, 10, 3, 1, 10, 6, 10, 8, 6, 3, 7, 7, 3, 7, 2, 3, 6, 3, 5, 8, 8, 3, 8, 9, 3, 9, 4, 3, 6, 7, 4, 9},
//{           6, 8, 10, 6, 3, 1, 5, 10, 3, 1, 6, 8, 10, 10, 10, 5, 2, 4, 4, 1, 8, 3, 9, 10, 1, 2, 3, 8, 8, 8, 9, 6, 5, 10, 3},
//{           9, 10, 7, 8, 2, 10, 6, 9, 9, 5, 10, 5, 8, 5, 10, 1, 3, 3, 9, 2, 5, 3, 6, 5, 2, 5, 3, 7, 9, 2, 9, 9, 1, 6, 7},
//{           4, 7, 2, 5, 5, 8, 4, 1, 7, 1, 10, 7, 3, 2, 8, 6, 9, 10, 4, 3, 1, 8, 5, 10, 9, 6, 10, 7, 8, 7, 3, 1, 3, 6, 5},
//{           7, 5, 1, 9, 4, 1, 9, 10, 5, 2, 7, 2, 2, 6, 5, 4, 9, 5, 8, 10, 3, 5, 9, 9, 4, 6, 4, 5, 8, 1, 1, 7, 8, 3, 5},
//{           1, 3, 5, 2, 9, 9, 9, 1, 10, 6, 7, 4, 6, 3, 3, 5, 5, 10, 4, 6, 3, 9, 1, 7, 8, 3, 10, 4, 2, 2, 1, 2, 7, 5, 4},
//{           5, 3, 4, 7, 3, 9, 6, 6, 5, 8, 10, 1, 5, 9, 4, 2, 2, 4, 2, 10, 4, 6, 9, 7, 8, 1, 7, 1, 9, 4, 4, 3, 6, 9, 2},
//{           8, 8, 9, 5, 4, 6, 5, 6, 2, 5, 2, 3, 6, 5, 4, 6, 8, 10, 6, 7, 9, 8, 5, 9, 6, 8, 5, 1, 4, 3, 4, 3, 2, 2, 10},
//{           7, 9, 6, 3, 1, 10, 4, 3, 8, 10, 7, 5, 8, 8, 2, 6, 8, 10, 10, 6, 7, 10, 10, 9, 5, 3, 2, 9, 6, 3, 8, 3, 2, 5, 5},
//{           2, 7, 10, 6, 4, 9, 4, 10, 8, 3, 1, 3, 10, 2, 5, 6, 9, 4, 7, 7, 8, 1, 9, 6, 7, 3, 6, 1, 6, 10, 5, 9, 8, 6, 5},
//{           1, 4, 8, 2, 2, 1, 3, 4, 10, 4, 10, 7, 4, 3, 6, 1, 2, 6, 1, 8, 4, 3, 5, 4, 1, 6, 10, 9, 4, 5, 3, 6, 9, 3, 8},
//{           10, 3, 10, 5, 4, 5, 7, 3, 9, 9, 8, 1, 1, 5, 1, 10, 9, 5, 4, 4, 5, 9, 4, 4, 2, 10, 8, 10, 8, 2, 7, 9, 6, 8, 6},
//{           2, 2, 2, 4, 2, 2, 3, 2, 2, 9, 2, 3, 7, 9, 8, 3, 3, 9, 6, 8, 2, 7, 8, 1, 5, 9, 7, 5, 5, 4, 2, 8, 8, 3, 1},
//{           9, 5, 5, 3, 8, 3, 4, 3, 2, 2, 10, 4, 7, 10, 1, 6, 2, 7, 3, 2, 3, 4, 1, 10, 10, 4, 1, 7, 3, 4, 9, 2, 10, 3, 4},
//{           9, 5, 9, 3, 8, 3, 5, 1, 1, 4, 1, 6, 5, 10, 1, 9, 2, 4, 9, 1, 3, 2, 4, 1, 7, 7, 9, 8, 8, 3, 3, 8, 7, 3, 1},
//{           7, 7, 5, 7, 7, 8, 10, 3, 5, 1, 3, 3, 2, 8, 1, 5, 2, 4, 8, 2, 10, 6, 2, 9, 5, 4, 3, 4, 2, 6, 4, 8, 2, 10, 5},
//{           1, 10, 6, 3, 4, 6, 7, 8, 9, 6, 10, 3, 7, 5, 2, 10, 5, 9, 1, 5, 3, 4, 8, 7, 5, 5, 2, 3, 8, 2, 9, 8, 3, 6, 2},
//{           8, 1, 10, 5, 1, 5, 6, 6, 1, 10, 7, 2, 4, 8, 2, 1, 10, 7, 10, 8, 2, 4, 2, 6, 1, 5, 6, 1, 7, 1, 2, 4, 3, 2, 10},
//{           3, 6, 5, 8, 9, 4, 7, 2, 10, 4, 4, 2, 5, 2, 1, 3, 5, 4, 6, 2, 6, 10, 7, 6, 8, 9, 10, 1, 1, 3, 2, 6, 8, 6, 5},
//{           8, 1, 1, 10, 2, 4, 5, 3, 1, 8, 3, 5, 3, 8, 10, 4, 4, 9, 1, 1, 6, 1, 2, 8, 4, 4, 9, 9, 4, 6, 3, 3, 8, 6, 4},
//{           10, 1, 8, 2, 1, 8, 7, 5, 10, 4, 4, 3, 9, 4, 5, 2, 1, 6, 3, 8, 1, 9, 8, 9, 2, 5, 3, 4, 3, 10, 8, 4, 1, 7, 7},
//{           1, 4, 3, 6, 5, 7, 1, 8, 7, 5, 4, 8, 5, 1, 3, 3, 1, 1, 2, 9, 4, 7, 4, 9, 1, 3, 8, 4, 3, 5, 2, 6, 10, 5, 1},
//{           5, 3, 3, 4, 9, 7, 9, 9, 2, 10, 3, 6, 10, 5, 9, 1, 10, 7, 4, 8, 7, 8, 6, 2, 3, 2, 4, 8, 1, 10, 10, 7, 4, 4, 2},
//{           2, 1, 1, 2, 4, 10, 6, 9, 1, 2, 9, 1, 1, 6, 6, 9, 2, 6, 6, 6, 8, 7, 1, 7, 9, 2, 8, 8, 5, 1, 9, 8, 3, 1, 2},
//{           6, 10, 7, 6, 1, 9, 5, 3, 1, 10, 9, 9, 3, 4, 6, 8, 3, 2, 10, 1, 3, 1, 8, 10, 7, 10, 10, 5, 3, 1, 6, 10, 10, 2, 6},
//{           2, 2, 10, 7, 3, 9, 5, 3, 1, 10, 9, 1, 4, 2, 2, 4, 4, 5, 3, 5, 1, 4, 5, 5, 6, 5, 10, 6, 6, 4, 3, 10, 7, 2, 6},
//{           1, 10, 2, 4, 2, 3, 4, 2, 6, 7, 6, 1, 1, 10, 3, 7, 10, 6, 1, 5, 4, 5, 6, 1, 3, 1, 3, 2, 8, 4, 9, 8, 5, 10, 3},
//{           6, 2, 8, 10, 9, 5, 5, 9, 5, 4, 3, 1, 5, 10, 4, 1, 5, 8, 7, 5, 2, 9, 9, 3, 8, 4, 1, 6, 8, 2, 10, 6, 3, 8, 5},
//{3, 2, 9, 3, 8, 4, 5, 10, 10, 7, 3, 1, 1, 3, 9, 8, 4, 7, 6, 9, 5, 10, 9, 2, 9, 1, 3, 4, 5, 10, 8, 10, 3, 8, 2}};
//    Searchable<Point> *searchable = new Matrix(mat, make_pair(0, 0), make_pair(34, 34));
//    Solver<Searchable<Point> *, vector<Point>> *solver =
//            new SearchSolver<Point>(new Astar<Point>());
//    vector<Point> list1=solver->solve(searchable);
//    for(Point s:list1) {
//        cout << s.first << ", " << s.second <<endl;
//    }
//*/
//
//    //Matrix::readFromString("1,2,3,!4,5,6,!%1,2,3,4,");
///*    vector<vector<double>> mat = {{1, 2, 3},
//                                  {4, 5, 6},
//                                  {7, 8, 9}};
//    Matrix*m = new Matrix(mat, make_pair(0, 0), make_pair(2, 2));
//    string str=m->to_String();
//    cout<<(str);
//    m=Matrix::readFromString(str);*/
///*    vector<vector<double>> mat = {{1, 2, 3},
//                                  {4, 5, 6},
//                                  {7, 8, 9}};
//    Matrix*m = new Matrix(mat, make_pair(0, 0), make_pair(2, 2));*/
///*FileCacheManager<string,string>* cacheManager=new FileCacheManager<string,string>();
//string s("Right,Down,Down,Right");
//cacheManager->saveProblem(m->to_String(),s);
//cacheManager->writeToFile("cache.txt");*/
///*    FileCacheManager<string,string>* cacheManager=new FileCacheManager<string,string>();
//    //cacheManager->writeToFile("cache.txt");
//    cacheManager->readFromFile("cache.txt");
//    cout<<cacheManager->isSolved(m->to_String());*/
///*    vector<vector<double>> mat = {{1, 2, 3},
//                                  {4, 5, 6},
//                                  {7, 8, 9}};
//    Searchable<Point> *searchable = new Matrix(mat, make_pair(0, 0), make_pair(2, 2));
//    Solver<Searchable<Point> *, vector<Point>> *solver =
//            new SearchSolver<Point>(new Bfs<Point>());
//    vector<Point> list1=solver->solve(searchable);
//    for(Point s:list1)
//        cout << s.first << ", " << s.second <<endl;*/
//    return 0;
//}