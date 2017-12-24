#ifndef PROJET_ALGORITHME_H
#define PROJET_ALGORITHME_H
#include "queue"
#include "list"
#include "../Bin.h"

using std::queue;
using std::list;


class Algorithme {
private:
    int id = 1;
protected:
    queue<int> valuesQueue;
public:
    Algorithme(queue<int> valuesQueue);
    virtual void compute() = 0;
};


#endif
