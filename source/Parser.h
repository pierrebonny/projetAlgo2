#ifndef PROJET_PARSER_H
#define PROJET_PARSER_H


#include <fstream>
#include <iostream>
#include "queue"

using std::string;
using std::ifstream;
using std::queue;
using std::cout;
using std::endl;

class Parser {

    public:
        void readFile(string filename);
        int getBinSize();
        queue<int> getQueue();

    private:
        queue<int> valueQueue;
        int bin_size = 0;
        void parse(ifstream& is);
};


#endif //PROJET_PARSER_H
