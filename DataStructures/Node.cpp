//
// Created by Raghava Viswa Mani Kiran Peddinti on 8/31/16.
//

#include "Node.h"

template <typename T>
Node<T>::Node() {}

template <typename T>
Node<T>::Node(Node *left, Node *right, Node *parent, T *val) {
    leftNode = left; rightNode = right; parentNode = parent; value = val;
}

template <typename T>
int Node<T>::Depth() {
    return (leftDepth < rightDepth) ? leftDepth : rightDepth;
}

template class Node<double>;
template class Node<int>;
template class Node<float>;