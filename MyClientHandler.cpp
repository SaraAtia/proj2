//
// Created by sara on 30/12/18.
//


#include "MyClientHandler.h"

#define SIZE 256


string join(vector<string> s, string sym)
{
    if (s.empty()) return string();
    string output;
    for (int i = 0; i < s.size() /*- 1*/; ++i)  {
        output += s[i] + sym;
    }
    //output += s[s.size() - 1];
    return output;
}
string SocketReader::readLine(){
    char buffer[SIZE];
    ssize_t find_pos;
    while ((find_pos = this->buffer.find('\n')) == string::npos)   {
        ssize_t num_read;
        if ((num_read = read(this->sock_id, buffer, SIZE - 1)) < 0)    {
            perror("error on read");
            exit(1);
        }   else if (num_read == 0) {
            // TODO connection closed by peer
        }
        buffer[num_read] = 0;
        this->buffer += string(buffer);
    }
    string output = this->buffer.substr(0, find_pos);
    this->buffer = this->buffer.substr(find_pos + 1);
    string line;
    //delete spaces
    for(int i=0;i<output.length();i++){
        if(output.at(i)!=' ')
            line+=output.at(i);
    }
    return line;
}


tuple<vector<string>, string, string> getAllInfo(int socketID){

    SocketReader reader(socketID);
    string in;
    vector<string> lines_read;
    do{
        in = reader.readLine();
        lines_read.push_back(in); //todo: change sign
    } while (in != "end");
    lines_read.pop_back();
    string exitPoint = lines_read[lines_read.size()-1];
    lines_read.pop_back();
    string entryPoint = lines_read[lines_read.size()-1];
    lines_read.pop_back();

    return make_tuple(lines_read, entryPoint, exitPoint);
}
/**
 * in order to separate buffer and info of every thread the
 * function will receive struct which will have all data-structures needed to store it's info
 * @param socketID
 */
