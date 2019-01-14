//
// Created by sara on 03/01/19.
//

#include "ConvertSolver.h"
string ConvertSolver::solve(vector<pair<int,int>> path){
    string instructions="";
    for(int i = 1 ; i < path.size(); i++){
        int xSrc = path[i-1].first;
        int ySrc = path[i-1].second;
        int xDes = path[i].first;
        int yDes = path[i].second;
        // no change in x
        if(xDes==xSrc){
            if(yDes == ySrc+1){
                instructions+="Right,";
            } else if(yDes == ySrc-1){
                instructions+="Left,";
            }
            // no change in y
        } else if(yDes == ySrc){
            if(xDes == xSrc+1){
                instructions+="Down,";
            } else if(xDes == xSrc-1){
                instructions+="Up,";
            }
        }
    }
    instructions = instructions.substr(0, instructions.size()-1);
    return instructions;
}
