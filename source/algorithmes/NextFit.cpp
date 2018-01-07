//
// Created by user on 30/12/2017.
//

#include <iostream>
#include "NextFit.h"

NextFit::NextFit(const queue<int> &valuesQueue, int binSize) : Algorithme(valuesQueue) {
    this->binSize = binSize;
    Bin bin{binSize,id};
    bins.push_back(bin);
}


void NextFit::compute() {
    int position = 0;
    while (!valuesQueue.empty()){
        int objet = valuesQueue.front();
        valuesQueue.pop();
        if (bins.at(position).getAvailableSize() >= objet)
            bins.at(position).addAnObject(objet);
        else{
            Bin newBin {binSize,++id};
            newBin.addAnObject(objet);
            position++;
            bins.push_back(newBin);
        }
    }
}

double NextFit::percentageEmpty(){
        int totalSize = bins.size() * binSize;
        if(totalSize == 0)
            return 0;
        int freeSize = 0;
        for (Bin bin : bins){
            freeSize += bin.getAvailableSize();
        }
        return (100.0*freeSize)/totalSize;
}
void NextFit::dispResult() {
    std::cout<<"Resultat de l'algo Next Fit" << std::endl;
    for (Bin bin : bins){
        bin.print();
    }
    std::cout<<std::endl;
}
