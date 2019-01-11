//
// Created by paz on 09/01/19.
//

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include <map>
#include <iostream>
#include "Searcher.h"
template <class Node>
class Astar :public Searcher<Node>{
    int NumberOfNodesEvaluated=0;
public:
    int getNumberOfNodesEvaluated(){
        return this->NumberOfNodesEvaluated;
    }
    double f(vector<vector<int>>h,State<Node>* son,Searchable<Node> *searchable){
        return h[son->getState().first][son->getState().second]+ g(son,searchable);
    }

    double g(State<Node>* state,Searchable<Node> *searchable){
        if(state==searchable->getInitialState()){
            return state->getCost();
        }
        return state->getCameFrom()->getCost()+state->getCost();
    }
    int calch(pair<int,int> st,Searchable<Node> *searchable){
        int n=searchable->getSates().size();
        int m=searchable->getSates().at(0).size();
        int x=st.first;
        int y=st.second;
        return (n-1-x)+(m-1-y);
    }

    bool findNode(map<double ,State<Node>*> open, State<Node>* node) {
        typename std::map<double ,State<Node>*>::iterator it;
        for ( it=open.begin(); it!=open.end(); ++it){
            if(it->second==node){
                return true;
            }
        }
        return false;

    }
    void deleteNode(map<double ,State<Node>*>* open, State<Node>* node) {
        typename std::map<double ,State<Node>*>::iterator it;
        for ( it=open->begin(); it!=open->end(); ++it){
            if(it->second==node){
                open->erase(it);
                return;
            }
        }

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
        init(searchable);
        //huristic matrix- manhattan distance
        vector<vector<int>>h;
        for(int i=0;i<searchable->getSates().size();i++){
            vector<int> row;
            for(int j=0;j<searchable->getSates().at(0).size();j++){
                row.push_back(calch(make_pair(i,j),searchable));
            }
            h.push_back(row);
        }
        std::map<double,State<Node>*> open;
        list<State<Node>*> closed;
        State<Node>* node_current;
        State<Node>* initial=searchable->getInitialState();
        open.insert(make_pair((initial->getCost()+calch(initial->getState(),searchable)),initial));
        while(open.size()!=0){
            this->NumberOfNodesEvaluated++;
            //the least f node
            node_current =open.begin()->second;
            deleteNode(&open,node_current);
            //if it the goal node
            if(node_current==searchable->getGoalState()){break;}
            vector<State<Node>*> neighbours=searchable->getAllPossibleStates(*node_current);
            for(State<Node>* neighbour:neighbours){
                if(neighbour->getCost()==-1){ continue;}
                double currentval = node_current->getCost() +neighbour->getCost();
                //in open
                if(findNode(open,neighbour)) {
                    if (g(neighbour,searchable) <= currentval) {continue; }
                // in closed
                }else if (std::find(closed.begin(), closed.end(), neighbour) != closed.end()){
                            if(g(neighbour,searchable) <= currentval){ continue;}
                            closed.remove(neighbour);
                            neighbour->setCameFrom(node_current);
                            open.insert(make_pair(f(h,neighbour,searchable),neighbour));
                        //not in close and not in open
                        }else{
                            neighbour->setCameFrom(node_current);
                            open.insert(make_pair(f(h,neighbour,searchable),neighbour));
                        }
                            neighbour->setCameFrom(node_current);
                            //todo check if it right
                            neighbour->setCost(node_current->getCost() + neighbour->getCost());
                    }
                 closed.push_back(node_current);

        }
        if(node_current != searchable->getGoalState()){
            __throw_invalid_argument("not find a way");
        }
        //return path
        State<Node> state =*(searchable->getGoalState());
        vector<Node> path;
        while(state.getCameFrom() != nullptr){
            path.push_back(state.getState());
            state=*(state.getCameFrom());
        }
        path.push_back(searchable->getInitialNode());
        //cout<<this->NumberOfNodesEvaluated<<endl;
        cout<<searchable->getGoalState()->getCost()<<","<<this->NumberOfNodesEvaluated<<endl;
        return path;

    }

};


#endif //PROJ2_ASTAR_H