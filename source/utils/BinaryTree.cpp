#include <cstring>
#include "BinaryTree.h"

void BinaryTree::insert(Bin bin) {
    root = insert(bin,root);
}

BinaryNode* BinaryTree::insert(Bin bin, BinaryNode* root) {
    bin.print();
    if (root == nullptr){
        root = new BinaryNode(bin);
    }
    if (bin.getAvailableSize() > root->getBin().getAvailableSize()){
        root->setRight(insert(bin,root->getRight()));
    }
    else if (bin.getAvailableSize() < root->getBin().getAvailableSize()){
        root->setLeft(insert(bin,root->getLeft()));
    }
    return root;
}

BinaryNode* BinaryTree::remove(int x, BinaryNode *root) {
    if (root == nullptr){
        delete(root);
        return nullptr;
    }

    if (x > root->getBin().getAvailableSize()){
        return remove(x,root->getRight());
    }
    else if (x < root->getBin().getAvailableSize()){
        return remove(x,root->getLeft());
    }
    else if (root->getLeft() == nullptr){
        return (root->getRight());
    }

    else if (root->getRight() == nullptr){
        return root->getLeft();
    }
    else {
        root->setLeft(removeMax(root->getLeft(),root));
        return root;
    }
}

BinaryNode* BinaryTree::removeMax(BinaryNode* t, BinaryNode* r){
    if(t->getRight() == nullptr){
        r->setBin(t->getBin());
        return t->getLeft();
    }
    t->setRight(removeMax(t->getRight(),r));
    return t;
}

void BinaryTree::remove(int neededSpace) {
    remove2(neededSpace);
}

BinaryNode* BinaryTree::getBest(BinaryNode* root, int neededSpace) {
    BinaryNode* best = nullptr;
    unsigned int found = 0;
    while (root != nullptr && !found) {
        if (root->getBin().getAvailableSize() > neededSpace) {
            if (best == nullptr || best->getBin().getAvailableSize() < neededSpace) {
                best = root;
            }
            root = root->getLeft();
        }
        else if (root->getBin().getAvailableSize() < neededSpace) {
            root = root->getRight();
        }
        else {
            best = root;
            found = 1;
        }
    }
    return best;
}

Bin BinaryTree::getBest(int neededSpace) {
    BinaryNode* best = getBest(root,neededSpace);
    if(best != nullptr){
        return best->getBin();
    } else{
        return Bin(0,0);
    }
}

BinaryNode* BinaryTree::getRoot() {
    cout<<root->getBin().getAvailableSize()<<"get"<<endl;
    return root;
}

bool BinaryTree::remove2(int value) {
    if (root == nullptr)
        return false;
    else {
        if (root->getBin().getAvailableSize() == value) {
            BinaryNode* r = root;
            BinaryNode* removedNode = root->remove(value, r);
            root = r;
            if (removedNode != nullptr) {
                delete removedNode;
                return true;
            } else
                return false;
        } else {
            BinaryNode* removedNode = root->remove(value, nullptr);
            if (removedNode != nullptr) {
                delete removedNode;
                return true;
            } else
                return false;
        }

    }

}
