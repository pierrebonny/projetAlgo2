#include <iostream>
#include <time.h>

using namespace std;

#include "Parser.h"
#include "algorithmes/BestFit.h"
#include "algorithmes/NextFit.h"
#include "algorithmes/FirstFit.h"
#include "algorithmes/WorstFit.h"

int main (int argc, char *argv[]){
    string filename;
    std::queue<int> valuesQueue;
    if(argc > 1){
        filename = argv[1];
    }else{
        filename  = "exemples/exemple100.txt";
    }
    Parser parser;
    if(!parser.readFile(filename)){
        cerr << "Impossible de lire le fichier " << filename<< endl;
        return EXIT_FAILURE;
    }
    cout<<"BEST FIT"<< endl;
    BestFit bestFit(parser.getQueue(),parser.getBinSize());
    //bestFit.compute();
    //bestFit.dispResult();
    cout<<"NEXT FIT"<< endl;
    NextFit nextFit(parser.getQueue(),parser.getBinSize());
    nextFit.compute();
    nextFit.dispResult();
    cout<<"FIRST FIT"<< endl;
    FirstFit firstFit(parser.getQueue(),parser.getBinSize());
    firstFit.compute();
    firstFit.dispResult();
    cout<<"WORST FIT"<< endl;
    WorstFit worstFit(parser.getQueue(),parser.getBinSize());
    //worstFit.compute();
    //worstFit.dispResult();
    return 0;
}