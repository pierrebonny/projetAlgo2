#include <iostream>
#include "BestFit.h"

BestFit::BestFit(queue<int> &valuesQueue, int binSize) : Algorithme(valuesQueue),box_number(0) {
    this->bin_size = binSize;
    Bin bin1 = {binSize,1};
    binsTree.insert(bin1);
    boxFilling.push_back(0);
    box_number++;
}

void BestFit::dispResult() {
    for(Bin bin : fullBins){
        bin.print();
    }
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
            box_number++;
            boxFilling.push_back(0);
        }
        bestBin.addAnObject(value);
        if(bestBin.getAvailableSize() == 0){
            fullBins.push_back(bestBin);
        } else{
            binsTree.insert(bestBin);
        }
    }
}

void BestFit::averageBoxFilling() {
    double average = 0.;
    average += binsTree.somme(bin_size);
    average += bin_size*fullBins.size();
    average = floor((average/box_number)*100 + 0.5)/100;
    cout<<"Le taux de remplissage moyen est de "<<average<<"%"<<endl;
}

void BestFit::boxNumber() {
    cout<<"Il y a "<<box_number<<" boites"<<endl;
}

