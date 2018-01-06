#include "AlmostWorstFirst.h"

AlmostWorstFirst::AlmostWorstFirst(queue<int> &valuesQueue, int binSize): Algorithme(valuesQueue),bin_size(binSize),binsTree() {
    Bin bin = {binSize, 1};
    binsTree.insert(bin);
}

void AlmostWorstFirst::compute() {
    while (!valuesQueue.empty()) {
        int value = valuesQueue.front();
        valuesQueue.pop();
        Bin mostEmptyBin = binsTree.findMax()->getBin();
        if (mostEmptyBin.getAvailableSize() < value) {
            mostEmptyBin = Bin(bin_size, ++id);
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
        binsTree.insert(mostEmptyBin);
    }

}


void AlmostWorstFirst::dispResult() {
    binsTree.display();
}