#ifndef PROJET_ALMOSTWORSTFIRST_H
#define PROJET_ALMOSTWORSTFIRST_H


#include "Algorithme.h"
#include "../utils/BinaryTree.h"
#include <cmath>

class AlmostWorstFirst : public Algorithme {
public:
    AlmostWorstFirst(queue<int> &valuesQueue, int binSize);
    virtual void compute();
    void dispResult();

    virtual void boxNumber();
    virtual void averageBoxFilling();


private:
    BinaryTree binsTree;
    int box_number = 0;
    int bin_size;
    int id = 1;

};


#endif //PROJET_ALMOSTWORSTFIRST_H
