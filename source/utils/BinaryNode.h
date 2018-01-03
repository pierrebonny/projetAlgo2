#ifndef PROJET_BINARYNODE_H
#define PROJET_BINARYNODE_H

#include "../Bin.h"

class BinaryNode {
    public:
        BinaryNode(Bin& bin);
        Bin& getBin();
        BinaryNode* getLeft();
        BinaryNode* getRight();
        void setRight(BinaryNode* newRight);
        void setLeft(BinaryNode* newLeft);
        void setBin(Bin& bin);
        BinaryNode* remove(int value,BinaryNode* parent);
        int minValue();
    private:
        Bin nodeBin;
        BinaryNode* left;
        BinaryNode* right;
};


#endif //PROJET_BINARYNODE_H
