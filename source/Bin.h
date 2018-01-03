#ifndef PROJET_BIN_H
#define PROJET_BIN_H


class Bin {

private:
    int size;
    int remainingSize;
    int id;//To identify the bin

public:
    Bin(int size,int id);
    bool operator<(const Bin bin);
    int getAvailableSize() const ;
    bool addAnObject(int sizeOfObject);
    int getID()const;
    void print()const;
    int compareTo(Bin& bin)const;

};


#endif //PROJET_BIN_H
