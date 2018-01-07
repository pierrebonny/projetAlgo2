#include "AlmostWorstFirst.h"

AlmostWorstFirst::AlmostWorstFirst(queue<int> &valuesQueue, int binSize): Algorithme(valuesQueue),bin_size(binSize),binsTree() {
    Bin bin = {binSize, 1};
    binsTree.insert(bin);
    box_number++;
}

void AlmostWorstFirst::compute() {
    while (!valuesQueue.empty()) {
        int value = valuesQueue.front();
        valuesQueue.pop();
        BinaryNode *pNode = binsTree.findMax();
        if(pNode == nullptr){
            Bin temp = Bin(bin_size,++id);
            binsTree.insert(temp);
            pNode = binsTree.findMax();

        }
        Bin mostEmptyBin = pNode->getBin();
        if (mostEmptyBin.getAvailableSize() < value) {
            mostEmptyBin = Bin(bin_size, ++id);
            box_number++;
            mostEmptyBin.addAnObject(value);

        }
        else {
            binsTree.deleteNode(mostEmptyBin.getAvailableSize());
            if (binsTree.findMax() != nullptr) {
                Bin almostEmptyBin = binsTree.findMax()->getBin();

                if (almostEmptyBin.getAvailableSize() < value) {
                    mostEmptyBin.addAnObject(value);
                }
                else {
                    binsTree.deleteNode(almostEmptyBin.getAvailableSize());
                    mostEmptyBin.addAnObject(value);
                    binsTree.insert(almostEmptyBin);

                }
            }
            else{
                mostEmptyBin.addAnObject(value);
            }
        }
        if(mostEmptyBin.getAvailableSize() == 0){
            fullBins.push_back(mostEmptyBin);
        } else{
            binsTree.insert(mostEmptyBin);
        }
    }

}


void AlmostWorstFirst::dispResult() {
    for(Bin bin : fullBins){
        bin.print();
    }
    binsTree.display();
}

void AlmostWorstFirst::boxNumber() {
    cout<<"Il y a "<<box_number<<" boites"<<endl;
}

void AlmostWorstFirst::averageBoxFilling() {
    double average = 0.;
    average += binsTree.somme(bin_size);
    for(Bin bin : fullBins){
        average += bin_size;
    }
    average = floor((average/box_number)*100 + 0.5)/100;
    cout<<"Le taux de remplissage moyen est de "<<average<<"%"<<endl;
}

