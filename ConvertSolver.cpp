//
// Created by sara on 03/01/19.
//

#include "ConvertSolver.h"
//todo: to convert from index path to instruction - if went down on row index put"Down"..
vector<string> ConvertSolver::solve(vector<pair<int,int>> path){
    vector<string> instructions;
    for(int i = 1 ; i < path.size(); i++){
        int xSrc = path[i-1].first;
        int ySrc = path[i-1].second;
        int xDes = path[i].first;
        int yDes = path[i].second;
        // no change in x
        if(xDes==xSrc){
            if(yDes == ySrc+1){
                instructions.push_back("Right");
            } else if(yDes == ySrc-1){
                instructions.push_back("Left");
            }
            // no change in y
        } else if(yDes == ySrc){
            if(xDes == xSrc+1){
                instructions.push_back("Down");
            } else if(xDes == xSrc-1){
                instructions.push_back("Up");
            }
        }
    }
    return instructions;
}
