#ifndef PROJET_ALMOSTWORSTFIRST_H
#define PROJET_ALMOSTWORSTFIRST_H


#include "Algorithme.h"
#include "../utils/BinaryTree.h"

class AlmostWorstFirst : public Algorithme {
public:
    AlmostWorstFirst(queue<int> &valuesQueue, int binSize);
    virtual void compute();
    void dispResult();


private:
    BinaryTree binsTree;
    int bin_size;
    int id = 1;

};


#endif //PROJET_ALMOSTWORSTFIRST_H
