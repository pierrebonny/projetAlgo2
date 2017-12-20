#ifndef PROJET_BIN_H
#define PROJET_BIN_H


class Bin {

private:
    int size;
    int remainingSize;
    int id;//To identify the bin

public:
    Bin(int size,int id);
    int getAvailableSize();
    bool addAnObject(int sizeOfObject);
    int getID();
    void print();

};


#endif //PROJET_BIN_H
