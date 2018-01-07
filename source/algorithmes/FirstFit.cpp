//
// Created by user on 30/12/2017.
//

#include <iostream>
#include "FirstFit.h"

FirstFit::FirstFit(queue<int> &valuesQueue, int size) : Algorithme(valuesQueue), binSize(size),
                                                        sizeMax(valuesQueue.size()), idOrdered() {
    binHeapMin = std::vector<int>(5 * sizeMax, 0);
}

void FirstFit::compute() {
    while (!valuesQueue.empty()) {
        int objet = valuesQueue.front();
        valuesQueue.pop();
        int binId = search(objet);
        update(binId, objet);
    }
}

void FirstFit::dispResult() {
    int id = 0;
    for (auto f : idOrdered) {
        std::cout << "La boite " << (++id) << " est de taille : " << binSize << " et il reste "
                  << (binSize - binHeapMin.at(f)) << std::endl;
    }
    std::cout << std::endl;
}

int FirstFit::search(int value) {
    return search(1, value, 1, sizeMax);
}

int FirstFit::search(int idx, int val, int left, int right) {
    if (left == right) {
        return left;
    }
    if (binHeapMin.at(2 * idx) <= binSize - val) return search(2 * idx, val, left, mid(left, right));
    else return search(2 * idx + 1, val, (left + right) / 2 + 1, right);
}

void FirstFit::update(int idBin, int sizeItem) {
    update(1, idBin, sizeItem, 1, sizeMax);
}

void FirstFit::update(int idx, int x, int val, int left, int right) {
    if (left == right) {
        binHeapMin.at(idx) += val;
        idOrdered.insert(idx);
        return;
    }

    if (x <= mid(left, right)) {
        update(2 * idx, x, val, left, mid(left, right));
    } else {
        update(2 * idx + 1, x, val, mid(left, right) + 1, right);
    }

    // store the new minimum fill level of the current (sub)tree
    binHeapMin.at(idx) = min(2 * idx, 2 * idx + 1);
}

int FirstFit::mid(int l, int r) {
    return (l + r) / 2;
}

int inline FirstFit::min(int a, int b) {
    return (binHeapMin.at(a) < binHeapMin.at(b) ? binHeapMin.at(a) : binHeapMin.at(b));
}


void FirstFit::boxNumber(){
    std::cout<<"Il y a "<<idOrdered.size()<<" boites"<<std::endl;

}
void FirstFit::averageBoxFilling() {

    int totalSize = idOrdered.size() * binSize;
    if (totalSize == 0)
        return;
    int freeSize = 0;

    for (auto f : idOrdered) {
        freeSize += binHeapMin.at(f);
    }
    std::cout << "Le taux de remplissage moyen est de " << 100.0 * (totalSize - freeSize) / totalSize << "%" << std::endl;
}

