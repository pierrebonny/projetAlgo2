#include "Algorithme.h"

Algorithme::Algorithme(queue<int> valuesQueue, int binSize) {
    this->valuesQueue = valuesQueue;
    Bin bin1 = {binSize, id};
    listOfBin.push_front(bin1);
    id++;
}
