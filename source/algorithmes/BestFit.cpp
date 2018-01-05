#include <iostream>
#include "BestFit.h"

BestFit::BestFit(queue<int> &valuesQueue, int binSize) : Algorithme(valuesQueue) {
    this->bin_size = binSize;
    Bin bin1 = {binSize,1};
    binsTree.insert(bin1);
}

void BestFit::dispResult() {
    binsTree.display();
}

void BestFit::compute() {
    Bin bestBin(0,0);
    while (!valuesQueue.empty()){
        int value = valuesQueue.front();
        valuesQueue.pop();
        bestBin = binsTree.getBest(value);
        if(bestBin.getAvailableSize() != 0){
            binsTree.deleteNode(bestBin.getAvailableSize());

        }else{
            bestBin = {bin_size,++id};
        }
        bestBin.addAnObject(value);
        binsTree.insert(bestBin);
    }
}

