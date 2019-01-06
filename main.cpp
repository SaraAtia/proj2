#include <iostream>
#include "ConvertSolver.h"

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
using namespace std;
int main(){
    Solver<vector<State<pair<int,int>>*>,vector<string>>* cs = new ConvertSolver();
    State<pair<int,int>>* a = new State<pair<int,int>>(pair<int,int>(0,0));
    State<pair<int,int>>* b = new State<pair<int,int>>(pair<int,int>(1,0));
    State<pair<int,int>>* c = new State<pair<int,int>>(pair<int,int>(1,1));
    State<pair<int,int>>* d = new State<pair<int,int>>(pair<int,int>(0,1));
    State<pair<int,int>>* e = new State<pair<int,int>>(pair<int,int>(0,0));
    vector<State<pair<int,int>>*> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);
    vec.push_back(e);
    vector<string> sol = cs->solve(vec);
    for(string s:sol){
        cout<< s<<", ";
    }

}