//
// Created by user on 04/01/2018.
//

#ifndef PROJET_WORSTFIT_H
#define PROJET_WORSTFIT_H


#include "Algorithme.h"
#include "../utils/BinaryTree.h"
#include <cmath>

class WorstFit : public Algorithme{

public:
    WorstFit(queue<int> &valuesQueue, int binSize);
    virtual void compute();
    void dispResult();
    virtual void boxNumber();
    virtual void averageBoxFilling();

private:
    int box_number = 0;
    BinaryTree binsTree;
    int bin_size;
    int id;

};


#endif //PROJET_WORSTFIT_H
