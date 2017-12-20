#ifndef PROJET_ALGORITHME_H
#define PROJET_ALGORITHME_H
#include "queue"
#include "list"
#include "../Bin.h"

using std::queue;
using std::list;

class Algorithme {
private:
    queue<int> valuesQueue;
    list<Bin> listOfBin;
    int id = 1;
public:
    Algorithme(queue<int> valuesQueue, int binSize);
    virtual void compute() = 0;
};


#endif //PROJET_ALGORITHME_H
