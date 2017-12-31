//
// Created by user on 30/12/2017.
//

#ifndef PROJET_NEXTFIT_H
#define PROJET_NEXTFIT_H


#include "Algorithme.h"

class NextFit : Algorithme {
public:
    NextFit(const queue<int> &valuesQueue,int binSize);
    void compute();
    void dispResult();

private:
    int binSize;
    int id=0;
    std::vector<Bin> bins;

};


#endif //PROJET_NEXTFIT_H
