//
// Created by paz on 09/01/19.
//

#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H

#include "Searcher.h"
#include <stack>
#include <iostream>
//#include <iostream>

template <class Node>
class Dfs :public Searcher<Node>{
    int NumberOfNodesEvaluated=0;
public:
    int getNumberOfNodesEvaluated(){
        return this->NumberOfNodesEvaluated;
    }
    void init(Searchable<Node> *searchable) {
        for (vector<State<Node> *> s:searchable->getSates()) {
            for (State<Node> *state:s) {
                state->setVisited(false);
                state->setCameFrom(nullptr);
                state->setCost(searchable->getInitCost(state->getState()));
            }
        }
    }
        vector<Node> search(Searchable<Node> *searchable) override {
 /*           if point in closed_set:
            return null

            closed_set.add(point)
            open_count += 1

            if point = exit_node:
            return point

            if matrix[point] == -1:  // wall
            return null

            for node in matrix.neighbors(point):
            out = DFS(sum_point(point, walk))
            if out is not null:
            return (point, out)*/
        init(searchable);
        std::stack<State<Node>*> s;
        s.push(searchable->getInitialState());
        while(!s.empty()){
            State<Node>* u=s.top();
            s.pop();
            if(!u->isVisited()){
                this->NumberOfNodesEvaluated++;
                if(u==searchable->getGoalState()){ break;}
                u->setVisited(true);
                for(State<Node>* w : searchable->getAllPossibleStates(*u)){
                    if(!w->isVisited()&&w->getCost()!=-1) {
                        s.push(w);
                        w->setCameFrom(u);
                    }
                }
            }
        }
        //return path
        return returnPath(searchable);

        }
        vector<Node> returnPath(Searchable<Node> *searchable){
        int sum=0;
        State<Node> state =*(searchable->getGoalState());
        vector<Node> path;
        while(state.getCameFrom() != nullptr){
            sum+=state.getCost();
            path.push_back(state.getState());
            state=*(state.getCameFrom());
        }
        sum+=state.getCost();
        path.push_back(searchable->getInitialNode());
        cout<<sum<<","<<this->NumberOfNodesEvaluated<<endl;
        return path;
    }
};


#endif //PROJ2_DFS_H
