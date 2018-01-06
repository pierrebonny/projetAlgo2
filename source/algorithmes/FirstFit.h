//
// Created by user on 30/12/2017.
//

#ifndef PROJET_FIRSTFIT_H
#define PROJET_FIRSTFIT_H


#include <set>
#include "Algorithme.h"

class FirstFit : Algorithme {
public:
    FirstFit(queue<int> &valuesQueue, int size);
    void compute();
    void dispResult();
private:
    int sizeMax;
    std::vector<int> binHeapMin;
    std::set<int> idOrdered;
    void update(int idBin,int sizeItem);
    void update(int idx, int x,int val, int left, int right);
    int search(int value);
    int search(int idx, int val,int left, int right);
    int binSize;
    int inline mid(int l,int r);
    int inline min(int a,int b);

};


#endif //PROJET_FIRSTFIT_H
