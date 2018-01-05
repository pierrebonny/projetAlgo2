#include <iostream>

using namespace std;

#include "Parser.h"
#include "algorithmes/BestFit.h"
#include "algorithmes/NextFit.h"
#include "algorithmes/FirstFit.h"
#include "algorithmes/WorstFit.h"

int main() {

    Parser parser;
    parser.readFile("exemples/exemple20.txt");
    cout<<"BEST FIT"<< endl;
    BestFit bestFit(parser.getQueue(),parser.getBinSize());
    bestFit.compute();
    bestFit.dispResult();
    cout<<"NEXT FIT"<< endl;
    NextFit nextFit(parser.getQueue(),parser.getBinSize());
    nextFit.compute();
    nextFit.dispResult();
    cout<<"FIRST FIT"<< endl;
    FirstFit firstFit(parser.getQueue(),parser.getBinSize());
    firstFit.compute();
    firstFit.dispResult();

    /*WorstFit worstFit(parser.getQueue(),parser.getBinSize());
    worstFit.compute();
    worstFit.dispResult();*/
    return 0;
}