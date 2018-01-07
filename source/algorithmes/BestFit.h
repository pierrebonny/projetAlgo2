#ifndef PROJET_BESTFIT_H
#define PROJET_BESTFIT_H


#include "Algorithme.h"
#include "../utils/BinaryTree.h"
#include <cmath>

using std::priority_queue;
using std::vector;

class BestFit: public Algorithme {

public:
    BestFit(queue<int> &valuesQueue, int binSize);
    virtual void compute();
    void dispResult();
    virtual void boxNumber();
    virtual void averageBoxFilling();

private:
    vector<int> boxFilling;
    int box_number;
    BinaryTree binsTree;
    int bin_size;
    int id = 1;

};


#endif