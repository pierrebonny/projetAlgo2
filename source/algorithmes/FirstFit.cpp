//
// Created by user on 30/12/2017.
//

#include <iostream>
#include "FirstFit.h"

FirstFit::FirstFit(const queue<int> &valuesQueue, int binSize) : Algorithme(valuesQueue) {
    this->binSize = binSize;
    Bin bin{binSize,id};
    bins.push_back(bin);
}

void FirstFit::compute() {
    for(int i=0; i < valuesQueue.size();i++ ){
        int objet = valuesQueue.front();
        valuesQueue.pop();
        add(objet);
    }
}

void FirstFit::add(int objet){
    for (int j = 0; j < bins.size() ; ++j) {
        if(bins.at(j).getAvailableSize() >= objet) {
            bins.at(j).addAnObject(objet);
            return;
        }
    }
    Bin newBin{binSize,++id};
    newBin.addAnObject(objet);
    bins.push_back(newBin);
}

void FirstFit::dispResult() {
    std::cout<<"Resultat de l'algo First Fit" << std::endl;
    for (Bin bin : bins){
        bin.print();
    }
    std::cout<<std::endl;
}
