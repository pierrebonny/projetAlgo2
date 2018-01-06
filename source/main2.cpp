#include <iostream>
#include <time.h>

using namespace std;

#include "Parser.h"
#include "algorithmes/BestFit.h"
#include "algorithmes/NextFit.h"
#include "algorithmes/FirstFit.h"
#include "algorithmes/WorstFit.h"

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
    cout<<"NEXT FIT"<< endl;
    NextFit nextFit(valuesQueue,b_size);
    nextFit.compute();
    nextFit.dispResult();
    cout<<"FIRST FIT"<< endl;
    FirstFit firstFit(valuesQueue,b_size);
    firstFit.compute();
    firstFit.dispResult();
    cout<<"WORST FIT"<< endl;
    WorstFit worstFit(valuesQueue,b_size);
    worstFit.compute();
    worstFit.dispResult();
    return 0;
}