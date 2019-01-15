#include <utility>

//
// Created by sara on 03/01/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H


#include <vector>
#include <iostream>
#include "Searchable.h"

class Matrix: public Searchable<pair<int, int>> {
    using Point = pair<int, int>;

    vector<vector<double>> values;
    vector<vector<State<Point >*>> states;
    State<Point> initialState;
    Point goalNode;
public:
    Matrix(vector<vector<double>> values, Point in, Point out):
        initialState(in, 0, nullptr) {
        this->values = std::move(values);
        this->goalNode = out;
        initialState.setCost(get_price(in));
        //create all states
        vector<vector<State<Point >*>> states;
        for(int i=0;i<this->values.size();i++){
            vector<State<Point >*> row;
            for(int j=0;j<this->values.at(i).size();j++){
                if(i==0&&j==0){
                    row.push_back(&this->initialState);
                    continue;
                }
                State<Point> *p=new State<Point >(make_pair(i,j),this->values[i][j], nullptr);
                row.push_back(p);
            }
            states.push_back(row);
        }
        this->states=states;
    }
    ~Matrix() {
        for (int i = 0; i < states.size(); i++){
            for (int j =0; j <states[i].size(); j++){
                states[i][j]->setCameFrom(nullptr);
            }
        }
        //for (int i = 0; i < states.size(); i++) {
        vector<State<Point> *> vec;
        while(states.size()!=1){
            vec=states[states.size()-1];
            while(!vec.empty()){
                State<Point >*state=vec[vec.size()-1];
                delete (state);
                vec.pop_back();
            }
            states.pop_back();
        }
        while(states[0].size()!=1){
            State<Point >*state=states[0][states[0].size()-1];
            delete (state);
            states[0].pop_back();
        }
        //delete (states[0][0]);

    }
    vector<vector<State<Point >*>> getSates() override{
        return this->states;
    }

    State<Point>* getInitialState() override {
        return &this->initialState;
    }
    State<Point>* getGoalState() override{
        return this->states[this->goalNode.first][this->goalNode.second];
    }
    Point getInitialNode()  override    {
        return this->initialState.getState();
    }


    Point getGoalNode() override{
        return this->goalNode;
    }

    vector<State<Point>*> getAllPossibleStates(State<pair<int,int>>* s) override{
        vector<State<Point>*> list;
        //matrix is in size m*n
        int m=values.size();
        int n=values.at(0).size();
        int x=s->getState().first;
        int y=s->getState().second;
        if(x>=m||y>=n){
            __throw_invalid_argument("invalid position in matrix");
        }
        //go up is valid
        if(x-1!=-1){
            list.push_back(states[x-1][y]);
        }
        //go left is valid
        if(y-1!=-1){
            list.push_back(states[x][y-1]);

        }
        //go right is valid
        if(y+1!=n){
            list.push_back(states[x][y+1]);
        }
        //go down is valid
        if(x+1!=m){
            list.push_back(states[x+1][y]);
        }
        return list;
    }
    /*
    * return the values of the matrix
    */
    vector<vector<double >> getValues(){
        return this->values;
    }
    //1,2,3,!4,5,6,!%1,2,3,4,
    /*
     * convert string to matrix
     */
    static Matrix* readFromString(string s){
        //vector<double> row;
        vector<int> pairs;
        vector<vector<double >> mat;
        string line=s;
        size_t pos = 0;
        size_t endpos = 0;
        string token;
        //read the matrix
        while(0!=line.find("%")) {
            //endpos = line.find("!");
            vector<double> row;
            while(line.find("!")>line.find(",")) {
                pos = line.find(",");
                token = line.substr(0, pos);
                row.push_back(stod(token));
                line.erase(0, pos + 1);
            }
            mat.push_back(row);
            line.erase(0, 1);
        }
        //delete %
        line.erase(0, 1);
        for(int i=0;i<4;i++) {
            pos = line.find(",");
            token = line.substr(0, pos);
            pairs.push_back(stoi(token));
            line.erase(0, pos + 1);
        }
        return new Matrix(mat,make_pair(pairs.at(0),pairs.at(1)),make_pair(pairs.at(2),pairs.at(3)));
    }
    /*
     * convert matrix to string
     */
    string to_String(){
        string str="";
        for(int i=0;i<values.size();i++) {
            for (int j = 0; j < values.at(i).size(); j++) {
                str+=to_string(values.at(i).at(j));
                str+=",";
            }
            str+="!";
        }
        str+="%";
        str+=to_string(this->getInitialNode().first);
        str+=",";
        str+=to_string(this->getInitialNode().second);
        str+=",";
        str+=to_string(this->getGoalNode().first);
        str+=",";
        str+=to_string(this->getGoalNode().second);
        str+=",";
        return str;
    }

    bool operator==( Matrix &other) {
        return this->to_String()==other.to_String();
    }
    double getInitCost(pair<int, int> p)  override{
        return this->values[p.first][p.second];
    }
private:
    double get_price(pair<int, int> p)  {
        return this->values[p.first][p.second];
    }
};


#endif //PROJ2_MATRIX_H
