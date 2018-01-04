#include <cstring>
#include "BinaryTree.h"

void BinaryTree::insert(Bin& bin) {
    root = insert(bin,root);
}

BinaryNode* BinaryTree::insert(Bin bin, BinaryNode* node) {
    bin.print();
    if (node == nullptr){
        return new BinaryNode(bin);
    }
    if (bin.getAvailableSize() > node->getBin().getAvailableSize()){
        node->setRight(insert(bin,node->getRight()));
    }
    else if (bin.getAvailableSize() < node->getBin().getAvailableSize()){
        node->setLeft(insert(bin,node->getLeft()));
    }
    return node;
}

BinaryNode* BinaryTree::remove(int x, BinaryNode *node) {
    if(node == nullptr){
        // TODO : delete the removed node
        return node;
    }
    int compareResult = x-  node->getBin().getAvailableSize();
    if(compareResult < 0){
        BinaryNode * removed = remove(x,node->getLeft());
        node->setLeft(removed);
    }else if(compareResult > 0){
        BinaryNode* removed = remove(x,node->getRight());
        node->setRight(removed);
    }else if (node->getLeft()!= nullptr && node->getRight() != nullptr) {
        Bin bin =findMax(node)->getBin();
        node->setLeft(remove(bin.getAvailableSize(),node->getLeft()));
    } else{
        return (node->getLeft() != nullptr ) ? node->getLeft() : node->getRight();
    }
    return node;
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
    root = remove(neededSpace,root);
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

void BinaryTree::display() {
    cout << this->root<<endl;

}

BinaryNode * BinaryTree::findMax(BinaryNode *node) {
    if(node != nullptr){
        while( node->getRight() != nullptr )
            node = node->getRight();
    }
    return node;
}

BinaryNode* BinaryTree::findMax() {
    return findMax(root);
}


