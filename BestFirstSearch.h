//
// Created by paz on 03/01/19.
//

#ifndef PROJ2_BESTFIRSTSEARCH_H
#define PROJ2_BESTFIRSTSEARCH_H


#include "Searcher.h"
#include <queue>
#include <unordered_set>
template <class Node>
class BestFirstSearch: public Searcher<Node> {
public:
    bool hasItem(priority_queue <State<Node>> open, Node node) {
        queue <State<Node>> temp;
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
            open.push(temp.front());
            temp.pop();
        }
        return flag;
    }

    vector<Node> search(Searchable<Node> *searchable) override {
        priority_queue <State<Node>> open;
        unordered_set <State<Node>> closed;
        vector<Node> path;
        double currentValue;
        open.push(searchable->getInitialState());
        while (!open.empty()) {
            //todo < operator to pop
            State<Node> n = open.top();
            closed.insert(n);
            open.pop();
            if (n.equals(searchable->getGoalNode())) {
                //find the path
                while (!n.equals(searchable->getInitialNode())) {
                    path.insert(path.begin(), n.getCameFrom().getState());
                    n = n.getCameFrom();
                }
                return path;
            } else
                for (State<Node> s:searchable->getAllPossibleStates(n)) {
                    if (closed.count(s) != 0 && !hasItem(open, s.getState())) {
                        s.setCameFrom(&n);
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
