#include <cstring>
#include "BinaryTree.h"

void BinaryTree::insert(Bin& bin) {
    root = insert(bin,root);
}

BinaryNode* BinaryTree::insert(Bin& bin, BinaryNode* node) {
    if (node == nullptr){
        node = new BinaryNode(bin);
        return node;
    }
    if (bin.getAvailableSize() >= node->getBin().getAvailableSize()){
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
    int compareResult = x - node->getBin().getAvailableSize();
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
        if(root->getBin().getAvailableSize() == neededSpace){
            return root;
        }
        if (root->getBin().getAvailableSize() > neededSpace) {
            best = root;
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
    return root;
}

void BinaryTree::display() {
    //cout << this->root<<endl;
    display(root);

}

BinaryNode * BinaryTree::findMax(BinaryNode* node) {
    if(node != nullptr){
        while( node->getRight() != nullptr )
            node = node->getRight();
    }
    return node;
}

BinaryNode* BinaryTree::findMax() {
    return findMax(root);
}

BinaryNode *BinaryTree::findMin(BinaryNode* node) {
    if(node != nullptr){
        while (node->getLeft() != nullptr){
            node = node->getLeft();
        }
        return node;
    }
}

BinaryNode* BinaryTree::deleteNode(BinaryNode* root, int key)
{
        // base case
    if (root == nullptr){
        return root;
    }

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->getBin().getAvailableSize()){
        root->setLeft(deleteNode(root->getLeft(), key));
    }

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (key > root->getBin().getAvailableSize()){
        root->setRight(deleteNode(root->getRight(), key));
    }

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (root->getLeft() == nullptr)
        {
            BinaryNode* temp = root->getRight();
            delete(root);
            return temp;
        }
        else if (root->getRight() == nullptr)
        {
            BinaryNode* temp = root->getLeft();
            delete(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        BinaryNode* temp = findMin(root->getRight());

        // Copy the inorder successor's content to this node
        root->setBin(temp->getBin());

        // Delete the inorder successor
        root->setRight(deleteNode(root->getRight(), temp->getBin().getAvailableSize()));
    }
    return root;
}

void BinaryTree::deleteNode(int key) {
    root = deleteNode(root,key);
}

void BinaryTree::display(BinaryNode *node) {
    if(node != nullptr){
        node->getBin().print();
        if(node->getRight() != nullptr){
            display(node->getRight());
        }
        if(node->getLeft() != nullptr){
            display(node->getLeft());
        }
    }
}
