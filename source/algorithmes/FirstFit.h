//
// Created by user on 30/12/2017.
//

#ifndef PROJET_FIRSTFIT_H
#define PROJET_FIRSTFIT_H


#include "Algorithme.h"

class FirstFit : Algorithme {
public:
    FirstFit(const queue<int> &valuesQueue, int binSize);
    void compute();
    void dispResult();

private:
    void add(int objet);
    int binSize;
    int id = 0;
    std::vector<Bin> bins;

};


#endif //PROJET_FIRSTFIT_H
