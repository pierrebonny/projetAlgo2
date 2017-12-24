#include <iostream>

using namespace std;

#include "Parser.h"
#include "algorithmes/BestFit.h"

int main() {

    Parser parser;
    parser.readFile("exemples/exemple20.txt");
    BestFit bestFit(parser.getQueue(),parser.getBinSize());
    bestFit.compute();
    bestFit.dispResult();
    std::list<int> liste;
    return 0;
}