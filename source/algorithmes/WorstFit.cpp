
#include "WorstFit.h"

using std::vector;

WorstFit::WorstFit(queue<int> &valuesQueue, int binSize): Algorithme(valuesQueue),bin_size(binSize),binsTree(), id(0) {
    Bin bin = {binSize, id};
    binsTree.insert(bin);
    box_number++;
}

void WorstFit::compute() {
    while (!valuesQueue.empty()){
        int value = valuesQueue.front();
        valuesQueue.pop();
        Bin mostEmptyBin = binsTree.findMax()->getBin();
        if(mostEmptyBin.getAvailableSize() < value){
            mostEmptyBin = Bin(bin_size,++id);
            box_number++;
        }else{
            binsTree.deleteNode(mostEmptyBin.getAvailableSize());
        }
        mostEmptyBin.addAnObject(value);
        if(mostEmptyBin.getAvailableSize() == 0){
            fullBins.push_back(mostEmptyBin);
        }
        else{
            binsTree.insert(mostEmptyBin);
        }
    }
}


void WorstFit::dispResult() {
    for(Bin bin : fullBins){
        bin.print();
    }
    binsTree.display();
}

void WorstFit::boxNumber() {
    cout<<"Il y a "<<box_number<<" boites"<<endl;
}

void WorstFit::averageBoxFilling() {
    double average = 0.;
    average += binsTree.somme(bin_size);
    for(Bin bin : fullBins){
        average += bin_size;
    }
    average = floor((average/box_number)*100 + 0.5)/100;
    cout<<"Le taux de remplissage moyen est de "<<average<<"%"<<endl;
}
