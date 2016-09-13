//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/9/16.
//

#include "BinaryTree.h"
#include <string>
using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree(T values[], int length) {
    for (int i=0; i<length; i++) {
        Insert(&values[i]);
    }
    return;
}

template <typename T>
void BinaryTree<T>::Insert(T *val) {
    BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
    if (head == nullptr) {
        node->value = val;
        head = node;
        return;
    }

    // add using insertinternal
    return InsertInternal(head, val);
}

template <typename T>
void BinaryTree<T>::InsertInternal(BinaryTreeNode<T>* headNode, T* val) {
    if (headNode->leftNodeHeight == 0 && headNode->rightNodeHeight == 0) {
        // add to the left node
        BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
        node->value = val;
        headNode->leftNode = node;
        headNode->leftNodeHeight += 1;
        return;
    }

    if (headNode->leftNodeHeight == 0) {
        // add to the left node
        BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
        node->value = val;
        headNode->leftNode = node;
        headNode->leftNodeHeight += 1;
        return;
    }

    if (headNode->rightNodeHeight == 0) {
        // add to the right node
        BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
        node->value = val;
        headNode->rightNode = node;
        headNode->rightNodeHeight += 1;
        return;
    }

    if (headNode->leftNodeHeight >= headNode->rightNodeHeight) {
        // add to the right side
        headNode->rightNodeHeight += 1;
        return InsertInternal(headNode->rightNode, val);
    }

    if (headNode->leftNodeHeight < headNode->rightNodeHeight) {
        // add to the left side
        headNode->leftNodeHeight += 1;
        return InsertInternal(headNode->leftNode, val);
    }
}

template <typename T>
int BinaryTree<T>::InOrderTraverse(T** values) {
    if (head == nullptr)
        return 0;
    int length = head->leftNodeHeight + head->rightNodeHeight + 1;
    *values = new T[length];
    return InOrderTraverseInternal(head, *values, 0);
}

template <typename T>
int BinaryTree<T>::PreOrderTraverse(T** values) {
    if (head == nullptr)
        return 0;
    int length = head->leftNodeHeight + head->rightNodeHeight + 1;
    *values = new T[length];
    return PreOrderTraverseInternal(head, *values, 0);
}

template <typename T>
int BinaryTree<T>::PostOrderTraverse(T** values) {
    if (head == nullptr)
        return 0;
    int length = head->leftNodeHeight + head->rightNodeHeight + 1;
    *values = new T[length];
    return PostOrderTraverseInternal(head, *values, 0);
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::GetHead() {
    return head;
}

template <typename T>
int BinaryTree<T>::InOrderTraverseInternal(BinaryTreeNode<T>* node, T* values, int position) {
    int new_position = position;
    if (node->leftNode != nullptr) {
        new_position = InOrderTraverseInternal(node->leftNode, values, new_position);
    }
    values[new_position] = *(node->value);
    new_position += 1;
    if (node->rightNode != nullptr) {
        new_position = InOrderTraverseInternal(node->rightNode, values, new_position);
    }
    return new_position;
}

template <typename T>
int BinaryTree<T>::PreOrderTraverseInternal(BinaryTreeNode<T>* node, T* values, int position) {
    int new_position = position;
    values[new_position] = *(node->value);
    new_position += 1;
    if (node->leftNode != nullptr) {
        new_position = PreOrderTraverseInternal(node->leftNode, values, new_position);
    }
    if (node->rightNode != nullptr) {
        new_position = PreOrderTraverseInternal(node->rightNode, values, new_position);
    }
    return new_position;
}

template <typename T>
int BinaryTree<T>::PostOrderTraverseInternal(BinaryTreeNode<T>* node, T* values, int position) {
    int new_position = position;
    if (node->leftNode != nullptr) {
        new_position = PostOrderTraverseInternal(node->leftNode, values, new_position);
    }
    if (node->rightNode != nullptr) {
        new_position = PostOrderTraverseInternal(node->rightNode, values, new_position);
    }
    values[new_position] = *(node->value);
    new_position += 1;
    return new_position;
}


template class BinaryTree<int>;
template class BinaryTree<string>;