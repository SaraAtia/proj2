//
// Created by paz on 08/01/19.
//

#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include <queue>
#include <iostream>
#include "Searcher.h"

template <class Node>
class Bfs: public Searcher<Node> {
    int NumberOfNodesEvaluated=0;
public:
    int getNumberOfNodesEvaluated(){
        return this->NumberOfNodesEvaluated;
    }
    void init(Searchable<Node> *searchable){
        for(vector<State<Node>*> s:searchable->getSates()){
            for(State<Node>* state:s){
                state->setVisited(false);
                state->setCameFrom(nullptr);
                state->setCost(searchable->getInitCost(state->getState()));
            }
        }
    }
    vector<Node> search(Searchable<Node> *searchable) override {
        //vector<State<Node>> visited;
        init(searchable);
        queue<State<Node>*> queue;
        State<Node> *start=searchable->getInitialState();
        queue.push(start);
        start->setVisited(true);
        while(!queue.empty()){
            this->NumberOfNodesEvaluated++;
            State<Node> *currnode=queue.front();
            queue.pop();
            if(currnode==searchable->getGoalState()){ break;}
            vector<State<Node>*> neighbours=searchable->getAllPossibleStates(*currnode);
            //for(State<Node> neighbor:neighbours){
            for(int i=0;i<neighbours.size();i++){
                State<Node>* neighbor=neighbours.at(i);
                if(!neighbor->isVisited()&&neighbor->getCost()!=-1){
                    neighbor->setCameFrom(currnode);
                    queue.push(neighbor);
                    neighbor->setVisited(true);
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
        std::reverse(path.begin(),path.end());
        //todo delete
        cout<<sum<<","<<this->NumberOfNodesEvaluated<<endl;
        return path;
    }

};


#endif //PROJ2_BFS_H