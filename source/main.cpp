#include <iostream>

using namespace std;

#include "Parser.h"
#include "algorithmes/BestFit.h"
#include "algorithmes/NextFit.h"
#include "algorithmes/FirstFit.h"
#include "algorithmes/WorstFit.h"

int main() {

    Parser parser;
    parser.readFile("exemples/exemple100.txt");
    BestFit bestFit(parser.getQueue(),parser.getBinSize());
    /* bestFit.compute2();
     bestFit.compute();
     bestFit.dispResult();

     NextFit nextFit(parser.getQueue(),parser.getBinSize());
     nextFit.compute();
     nextFit.dispResult();

     FirstFit firstFit(parser.getQueue(),parser.getBinSize());
     firstFit.compute();
     firstFit.dispResult();

     std::list<int> liste;*/
    WorstFit worstFit(parser.getQueue(),parser.getBinSize());
    worstFit.compute();
    worstFit.dispResult();
    return 0;
}