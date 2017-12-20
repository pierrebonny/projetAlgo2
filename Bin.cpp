#include "Bin.h"
#include "iostream"


Bin::Bin(int size,int id) {
    this->size = size;
    this->remainingSize = size;
    this->id = id;
}

int Bin::getAvailableSize() {
    return remainingSize;
}

bool Bin::addAnObject(int sizeOfObject) {
    if(remainingSize - sizeOfObject < 0)
        return false;
    else{
        remainingSize -= sizeOfObject;
        return true;
    }
}

void Bin::print() {
    std::cout<<"La boite "<< id <<" est de taille : " << size << " et il reste " << remainingSize << std::endl;
}
