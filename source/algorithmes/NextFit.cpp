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
    for (int i = 0; i < valuesQueue.size(); i++) {
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


void NextFit::dispResult() {
    std::cout<<"Resultat de l'algo Next Fit" << std::endl;
    for (Bin bin : bins){
        bin.print();
    }
    std::cout<<std::endl;
}
