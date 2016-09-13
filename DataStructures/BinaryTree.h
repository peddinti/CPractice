//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/9/16.
//

#ifndef CPRACTICE_BINARYTREE_H
#define CPRACTICE_BINARYTREE_H

#include <iostream>
using namespace std;

template <typename T>
struct BinaryTreeNode {
    T* value;
    BinaryTreeNode<T>* leftNode;
    int leftNodeHeight = 0;
    BinaryTreeNode<T>* rightNode;
    int rightNodeHeight = 0;

    bool operator ==(const BinaryTreeNode& node) const {
        return *value == *node.value;
    }

    bool operator !=(const BinaryTreeNode& node) const {
        return *value != *node.value;
    }

    friend ostream& operator <<(ostream& os, const BinaryTreeNode<T>& node) {
        os << *node.value;
        return os;
    }
};

template <typename T>
class BinaryTree {
private:
    BinaryTreeNode<T>* head;
    void InsertInternal(BinaryTreeNode<T>*, T*);
    int InOrderTraverseInternal(BinaryTreeNode<T>*, T*, int);
    int PreOrderTraverseInternal(BinaryTreeNode<T>*, T*, int);
    int PostOrderTraverseInternal(BinaryTreeNode<T>*, T*, int);
public:
    BinaryTree() : head(nullptr) {};
    BinaryTree(BinaryTreeNode<T>* headPtr) : head(headPtr) {};
    BinaryTree(T[], int);
    void Insert(T*);
    int InOrderTraverse(T**);
    int PreOrderTraverse(T**);
    int PostOrderTraverse(T**);
    BinaryTreeNode<T>* GetHead();
};


#endif //CPRACTICE_BINARYTREE_H
