#ifndef PROJET_BESTFIT_H
#define PROJET_BESTFIT_H


#include "Algorithme.h"
#include "../utils/BinaryTree.h"

using std::priority_queue;
using std::vector;

class BestFit: public Algorithme {

public:
    BestFit(queue<int> &valuesQueue, int binSize);
    virtual void compute();
    void dispResult();

private:
    BinaryTree binsTree;
    int bin_size;
    int id = 1;

};


#endif