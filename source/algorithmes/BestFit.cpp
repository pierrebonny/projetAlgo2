#include <iostream>
#include <algorithm>
#include "BestFit.h"

BestFit::BestFit(queue<int> &valuesQueue, int binSize) : Algorithme(valuesQueue) {
    this->bin_size = binSize;
    Bin bin1 = {binSize,1};
    binsQueue.push_back(bin1);
    binsTree = {};
}

Bin& BestFit::nextFillableBin(int value) {
    int i = 0;
    while(i < binsQueue.size() && binsQueue.at(i).getAvailableSize() < value){
        i++;
    }
    if(i < binsQueue.size()) {
        binsQueue.at(i).addAnObject(value);
    }
    else {
        Bin bin = {bin_size,++id};
        bin.addAnObject(value);
        binsQueue.push_back(bin);
    }
    std::sort(binsQueue.begin(),binsQueue.end());
}

void BestFit::compute() {
    int value;
    Bin bestBin(0,0);
    int size = valuesQueue.size();
    for(int i = 0; i < size; i++){
        value = valuesQueue.front();
        valuesQueue.pop();
        bestBin =  binsQueue.back();
        if(bestBin.getAvailableSize() == 0){
            fullBins.push_back(bestBin);
            binsQueue.pop_back();
        }
        nextFillableBin(value);
        dispResult();
        std::cout<<" "<<std::endl;
    }
    std::cout<<" hoy"<<std::endl;
}

void BestFit::dispResult() {
    vector<Bin> queue1 = binsQueue;
    vector<Bin> queue2 = fullBins;
    for(int i = 0; i < fullBins.size();i++){
        queue2.back().print();
        queue2.pop_back();
    }
    for(int i = 0; i < binsQueue.size();i++){
        queue1.back().print();
        queue1.pop_back();
    }
}

void BestFit::compute2() {
    binsTree.insert(binsQueue.at(0));
    int value;
    Bin bestBin(0,0);
    int size = valuesQueue.size();
    for(int i = 0; i < size; i++){
        value = valuesQueue.front();
        valuesQueue.pop();
        bestBin = binsTree.getBest(value);
        if(bestBin.getAvailableSize() != 0){
            binsTree.remove(bestBin.getAvailableSize());
        } else{
            bestBin = {bin_size,++id};
        }
        bestBin.addAnObject(value);
        binsTree.insert(bestBin);
    }
}

