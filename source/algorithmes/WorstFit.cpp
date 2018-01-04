
#include "WorstFit.h"
using std::vector;

WorstFit::WorstFit(queue<int> &valuesQueue, int binSize): Algorithme(valuesQueue),bin_size(binSize),binsTree() {
    Bin bin = {binSize, 1};
    binsTree.insert(bin);
}

void WorstFit::compute() {
    while (!valuesQueue.empty()){
        int value = valuesQueue.front();
        valuesQueue.pop();
        Bin mostEmptyBin = binsTree.findMax()->getBin();
        if(mostEmptyBin.getAvailableSize() < value){
            mostEmptyBin = Bin(bin_size,++id);
        }else{
            binsTree.remove(mostEmptyBin.getAvailableSize());
            mostEmptyBin.addAnObject(value);
        }
        binsTree.insert(mostEmptyBin);
    }

}


void WorstFit::dispResult() {
    binsTree.display();
}
