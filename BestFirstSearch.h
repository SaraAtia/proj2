//
// Created by paz on 03/01/19.
//

#ifndef PROJ2_BESTFIRSTSEARCH_H
#define PROJ2_BESTFIRSTSEARCH_H


#include "Searcher.h"
#include <queue>
#include "map"
#include <unordered_set>
#include "iostream"
template <class Node>
class comp{
public:
    int operator() (const State<Node>* p1, const State<Node>* p2)
    {
        return p1->getCost() > p2->getCost();
    }
};
template <class Node>
class BestFirstSearch: public Searcher<Node> {
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
        init(searchable);
        std::priority_queue <State<Node>*, vector<State<Node>*>,comp<Node>> open;
        //std::unordered_set <State<Node>*> closed;
        open.push(searchable->getInitialState());
        while(!open.empty()){
            State<Node>* n=open.top();
            this->NumberOfNodesEvaluated++;
            open.pop();
            n->setVisited(true);
            if(n==searchable->getGoalState()){ break;}
            for(State<Node>* s : searchable->getAllPossibleStates(*n)){
                if(s->getCost()==-1){ continue;}
                if(!s->isVisited()&&!hasItem(open,s)){
                    s->setCameFrom(n);
                    s->setCost(s->getCost() + n->getCost());
                    open.push(s);
                }
                else if(!s->isVisited() ){
                        if ((s->getCost() + n->getCost()) < (s->getCost() + s->getCameFrom()->getCost())) {
                            if (!hasItem(open, s))
                                open.push(s);
                            else
                                //arrange the queue
                                hasItem(open, s);
                            s->setCost(s->getCost() + n->getCost());
                        }
                }
            }
        }
        //return path
        return returnPath(searchable);

    }
    vector<Node> returnPath(Searchable<Node> *searchable) {
        State<Node> state =*(searchable->getGoalState());
        vector<Node> path;
        while(state.getCameFrom() != nullptr){
            path.push_back(state.getState());
            state=*(state.getCameFrom());
        }
        path.push_back(searchable->getInitialNode());
        std::reverse(path.begin(),path.end());
        //todo delete
        cout<<searchable->getGoalState()->getCost()<<","<<this->NumberOfNodesEvaluated<<endl;
        return path;
    }
    /**
     * find item in priority queue, by take all out and insert all
     * @param open queue
     * @param s specific state
     * @return if it has the state
     */
        bool hasItem(std::priority_queue <State<Node>*, vector<State<Node>*>,comp<Node>> open,State<Node>* s){
        std::queue<State<Node>*> temp;
        bool flag=false;
        while(!open.empty()){
            State<Node>* state=open.top();
            if(state==s){
                flag=true;
                open.pop();
                temp.push(state);
                break;
            }
            else{
                open.pop();
                temp.push(state);
            }
        }
        while(!temp.empty()){
            State<Node>* state=temp.front();
            temp.pop();
            open.push(state);
        }
        return flag;
    }

};



#endif //PROJ2_BESTFIRSTSEARCH_H
