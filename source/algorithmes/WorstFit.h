//
// Created by user on 04/01/2018.
//

#ifndef PROJET_WORSTFIT_H
#define PROJET_WORSTFIT_H


#include "Algorithme.h"
#include "../utils/BinaryTree.h"

class WorstFit : public Algorithme{

public:
    WorstFit(queue<int> &valuesQueue, int binSize);
    virtual void compute();
    void compute2();
    void dispResult();
    void dispResult2();

private:
    BinaryTree binsTree;
    int bin_size;
    int id;
    std::vector<Bin> fullBins;
    std::vector<Bin> binsQueue;
    Bin& nextFillableBin(int value);

};


#endif //PROJET_WORSTFIT_H
