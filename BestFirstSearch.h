//
// Created by paz on 03/01/19.
//

#ifndef PROJ2_BESTFIRSTSEARCH_H
#define PROJ2_BESTFIRSTSEARCH_H


#include "Searcher.h"
#include <queue>
#include <unordered_set>
template <class S>
class BestFirstSearch: public Searcher<S> {
public:
    bool hasItem(priority_queue <S> open, S node) {
        queue <S> temp;
        bool flag = false;
//check all the nodes till found or empty queue
        while (!open.empty()) {
            if (open.top().equals(node)) {
                flag = true;
                temp.push(open.top());
                open.pop();
                break;
            }
            temp.push(open.top());
            open.pop();
        }
//return the nodes that in the temp
        while (!temp.empty()) {
            open.push(temp.top());
            temp.pop();
        }
        return flag;
    }

    vector<S> search(Searchable<S> *searchable) override {
        priority_queue <State<S>> open;
        unordered_set <State<S>> closed;
        vector<S> path;
        double currentValue;
        open.push(searchable->getInitialState());
        while (!open.empty()) {
            //todo < operator to pop
            State<S> n = open.top();
            closed.push(n);
            open.pop();
            if (n.equals(searchable->getGoalNode())) {
                //find the path
                while (!n.equals(searchable->getInitialNode())) {
                    path.insert(path.begin(), n.getCameFrom());
                    n = n.getCameFrom();
                }
                return path;
            } else
                for (State<S> *s:searchable->getAllPossibleStates(n)) {
                    if (closed.count(s) != 0 && !hasItem(open, s)) {
                        s->setCameFrom(n);
                        open.push(s);
                    }
                    /*                       //todo this is better
                                       else if (1) {
                                           if (!hasItem(s, open)) {
                                               open.push(s);
                                           } else {
                                               //todo adjust priority

                                           }
                                       }
                                   }*/
                }
            return path;
        }
    }
};


#endif //PROJ2_BESTFIRSTSEARCH_H
