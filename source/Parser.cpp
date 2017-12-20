#include "Parser.h"

void Parser::readFile(string filename) {
    string s;
    ifstream is{filename};
    getline(is,s);
    is >> bin_size;
    getline(is,s);
    getline(is,s);
    parse(is);
}

int Parser::getBinSize() {
    return bin_size;
}

void Parser::parse(ifstream& is) {
    string line;
    getline(is,line);
    string delimiter = ", ";
    size_t pos = 0;
    string token;
    while((pos = line.find(delimiter)) != string::npos){
        token = line.substr(0,pos);
        valueQueue.push(std::stoi(token));
        line.erase(0,pos + delimiter.length());
    }
    line = line.substr(0,line.size() -1);
    valueQueue.push(std::stoi(line));
}

queue<int> Parser::getQueue() {
    return valueQueue;
}
