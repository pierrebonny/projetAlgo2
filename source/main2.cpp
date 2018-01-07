#include <iostream>
#include <time.h>

using namespace std;

#include "Parser.h"
#include "algorithmes/BestFit.h"
#include "algorithmes/NextFit.h"
#include "algorithmes/FirstFit.h"
#include "algorithmes/WorstFit.h"
#include "algorithmes/AlmostWorstFirst.h"

int main (int argc, char *argv[]){
    std::queue<int> valuesQueue;
    srand(time(0));
    cout<<"entrez la contenance maximum des boites"<<endl;
    int b_size;
    cin>>b_size;
    cout<<"entrez le nombre de valeurs que vous souhaitez generer"<<endl;
    int boxNumbers;
    cin>>boxNumbers;
    for(int i = 0; i < boxNumbers;i++){
        valuesQueue.push(rand()%b_size);
    }

    cout<<"BEST FIT"<< endl;
    BestFit bestFit(valuesQueue,b_size);
    bestFit.compute();
    bestFit.dispResult();
    bestFit.averageBoxFilling();
    bestFit.boxNumber();
    cout<<"NEXT FIT"<< endl;
    NextFit nextFit(valuesQueue,b_size);
    nextFit.compute();
    nextFit.dispResult();
    nextFit.averageBoxFilling();
    nextFit.boxNumber();
    cout<<"FIRST FIT"<< endl;
    FirstFit firstFit(valuesQueue,b_size);
    firstFit.compute();
    firstFit.dispResult();
    firstFit.averageBoxFilling();
    firstFit.boxNumber();
    cout<<"WORST FIT"<< endl;
    WorstFit worstFit(valuesQueue,b_size);
    worstFit.compute();
    worstFit.dispResult();
    worstFit.averageBoxFilling();
    worstFit.boxNumber();
    cout<<"ALMOST WORST FIT"<<endl;
    AlmostWorstFirst almostWorstFirst(valuesQueue, b_size);
    almostWorstFirst.compute();
    almostWorstFirst.dispResult();
    almostWorstFirst.averageBoxFilling();
    almostWorstFirst.boxNumber();
    return 0;
}