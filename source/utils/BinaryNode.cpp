#include "BinaryNode.h"

BinaryNode::BinaryNode(Bin &bin):nodeBin(bin) {
}

Bin& BinaryNode::getBin() {
    return nodeBin;
}

BinaryNode *BinaryNode::getLeft() {
    return left;
}

BinaryNode *BinaryNode::getRight() {
    return right;
}

void BinaryNode::setLeft(BinaryNode * newLeft) {
    delete(left);
    left = newLeft;
}

void BinaryNode::setRight(BinaryNode * newRight) {
    delete(right);
    right = newRight;
}

void BinaryNode::setBin(Bin &bin) {
    this->nodeBin = bin;
}

BinaryNode *BinaryNode::remove(int value, BinaryNode *parent) {
    if (value < this->getBin().getAvailableSize()) {
        if (left != nullptr)
            return left->remove(value, this);
        else
            return nullptr;
    } else if (value > this->getBin().getAvailableSize()) {
        if (right != nullptr)
            return right->remove(value, this);
        else
            return nullptr;
    } else {
        if (left != nullptr && right != nullptr) {
            this->setBin(right->getBin());
            return right->remove(this->getBin().getAvailableSize(), this);
        } else if (parent->left == this) {
            parent->left = (left != nullptr) ? left : right;
            return this;

        } else if (parent->right == this) {
            parent->right = (left != nullptr) ? left : right;
            return this;
        }

    }
}

int BinaryNode::minValue() {
    if (left == nullptr) {
        return nodeBin.getAvailableSize();
    } else {
        return left->minValue();
    }
}
