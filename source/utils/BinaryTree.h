#ifndef PROJET_BINARYTREE_H
#define PROJET_BINARYTREE_H

#include <cstdio>
#include "BinaryNode.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class BinaryTree {
    public:
        void insert(Bin bin);
        void remove(int neededSpace);
        Bin getBest(int neededSpace);
        void display();
        BinaryNode* getRoot();
        bool remove2(int value);
    private:
        void display(BinaryNode* node);
        BinaryNode* getBest(BinaryNode* root, int neededSpace);
        BinaryNode* insert(Bin bin,BinaryNode* root);
        BinaryNode* root = nullptr;
        BinaryNode* remove(int x, BinaryNode *root);
        BinaryNode* removeMax(BinaryNode* t,BinaryNode* r);
};


#endif //PROJET_BINARYTREE_H
