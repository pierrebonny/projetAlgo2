#ifndef PROJET_ALMOSTWORSTFIRST_H
#define PROJET_ALMOSTWORSTFIRST_H


#include "Algorithme.h"

class AlmostWorstFirst : public Algorithme {
public:
    AlmostWorstFirst(const queue<int> &valuesQueue);
    virtual void compute();

};


#endif //PROJET_ALMOSTWORSTFIRST_H
