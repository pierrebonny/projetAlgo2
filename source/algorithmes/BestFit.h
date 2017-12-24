#ifndef PROJET_BESTFIT_H
#define PROJET_BESTFIT_H


#include "Algorithme.h"

using std::priority_queue;
using std::vector;

class BestFit: public Algorithme {

public:
    BestFit(queue<int> &valuesQueue, int binSize);
    virtual void compute();
    void dispResult();

private:
    int bin_size;
    int id = 1;
    std::vector<Bin> fullBins;
    std::vector<Bin> binsQueue;
    Bin& nextFillableBin(int value);

};


#endif