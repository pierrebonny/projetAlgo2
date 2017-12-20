#ifndef PROJET_BESTFIT_H
#define PROJET_BESTFIT_H


#include "Algorithme.h"

class BestFit: public Algorithme {
public:
    BestFit(const queue<int> &valuesQueue, int binSize);
    virtual void compute();
};


#endif //PROJET_BESTFIT_H
