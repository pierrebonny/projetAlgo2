#ifndef PROJET_BINARYTREE_H
#define PROJET_BINARYTREE_H

#include <cstdio>
#include "BinaryNode.h"
#include <string>
#include <vector>
#include "iostream"

using std::cout;
using std::endl;

class BinaryTree {
public:
    void insert(Bin& bin);
    Bin getBest(int neededSpace);
    ~BinaryTree();
    BinaryNode* findMax();
    void display();
    BinaryNode* getRoot();
    void deleteNode(int key);
    int somme(int bin_size);
private:
    BinaryNode* findMax(BinaryNode* node);
    BinaryNode* findMin(BinaryNode* node);
    int somme(BinaryNode* node,int bin_size);
    void display(BinaryNode* node);
    BinaryNode* getBest(BinaryNode* root, int neededSpace);
    BinaryNode* insert(Bin& bin, BinaryNode* root);
    BinaryNode* root = nullptr;
    BinaryNode* removeMax(BinaryNode* t,BinaryNode* r);
    BinaryNode* deleteNode(BinaryNode* root, int key);

    void deleteObject(BinaryNode *node);
};


#endif //PROJET_BINARYTREE_H