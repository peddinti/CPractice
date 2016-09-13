//
// Created by Raghava Viswa Mani Kiran Peddinti on 8/31/16.
//

#include "MaxHeap.h"
#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
MaxHeap<T>::MaxHeap(T values[], int length) {
    for (int i=0; i< length; i++) {
        Insert(&values[i]);
    }
}

template <typename T>
void MaxHeap<T>::Insert(T *value) {
    // If Heap is empty assign value_ptr to node
    if (head.value == nullptr) {
        head.value = value;
        return;
    }
    // Identify which leaf node, insert must happen.
    Node<T>* node = &head;
    while (node->Depth() > 0) {
        if (node->leftNode == nullptr) {
            node->rightDepth++;
            node = node->rightNode;
        }
        if (node->rightNode == nullptr) {
            node->leftDepth++;
            node = node->leftNode;
        }
        if (node->leftNode->Depth() < node->rightNode->Depth()) {
            node = node->leftNode;
        } else {
            node = node->rightNode;
        }
    }
    // insert a new leaf node now
    Node<T>* new_node = new Node<T>(nullptr, nullptr, node, value);
    if (node->leftNode == nullptr) {
        node->leftNode = new_node;
        node->leftDepth++;
    } else {
        node->rightNode = new_node;
        node->rightDepth++;
    }
    // perform the bubble up on the new_node
    BubbleUp(new_node);
}

template <typename T>
T MaxHeap<T>::DeleteMax() {
    // head has the max value_ptr
    T* max_value = head.value;
    // get the leaf node with greatest depth
    auto node = &head;
    while ((node->leftNode != nullptr) || (node->rightNode != nullptr)) {
        if (node->leftNode == nullptr) {
            node->rightDepth--;
            node = node->rightNode;
            continue;
        }
        if (node->rightNode == nullptr) {
            node->leftDepth--;
            node = node->leftNode;
            continue;
        }
        if (node->leftDepth > node->rightDepth) {
            node->leftDepth--;
            node = node->leftNode;
        } else {
            node->rightDepth--;
            node = node->rightNode;
        }
    }
    // deleting the node
    Node<T>* parent = node->parentNode;
    if (parent->leftNode == node) {
        parent->leftNode = nullptr;
    } else {
        parent->rightNode = nullptr;
    }

    // Replacing head value_ptr with node value_ptr
    head.value = node->value;
    delete(node);

    // Bubble Down from head.
    BubbleDown(&head);
    return *max_value;
}


template <typename T>
void MaxHeap<T>::BubbleUp(Node<T> *node) {
    if (node->parentNode == nullptr) {
        return;
    }
    if (*node->parentNode->value < *node->value) {
        // swap the value_ptr
        T* temp = node->parentNode->value;
        node->parentNode->value = node->value;
        node->value = temp;
    }
    // run bubbleup on the parent node
    BubbleUp(node->parentNode);
}

template <typename T>
void MaxHeap<T>::BubbleDown(Node<T> *node) {
    T* temp;
    if (node->leftNode == nullptr && node->rightNode == nullptr) {
        return;
    }
    else if ((node->leftNode == nullptr || *node->leftNode->value <= *node->value) && (node->rightNode == nullptr || *node->rightNode->value <= *node->value)) {
        // no violation
        return;
    } else if (*node->leftNode->value > *node->value && (node->rightNode == nullptr || *node->rightNode->value <= *node->value)) {
        // only the left node is violating.
        goto bubbleLeft;
    } else if((node->leftNode == nullptr || *node->leftNode->value <= *node->value) && *node->rightNode->value > *node->value) {
        // only the right node is violating.
        goto bubbleRight;
    } else if(*node->leftNode->value < *node->rightNode->value) {
        // Both nodes violating, but right has bigger value_ptr. so bubble right
        goto bubbleRight;
    } else {
        goto bubbleLeft;
    }

    bubbleLeft:
        temp = node->value;
        node->value = node->leftNode->value;
        node->leftNode->value = temp;
        return BubbleUp(node->leftNode);

    bubbleRight:
        temp = node->value;
        node->value = node->rightNode->value;
        node->rightNode->value = temp;
        return BubbleDown(node->rightNode);
}

template <typename T>
T MaxHeap<T>::GetMax() const {
    return *head.value;
}

template class MaxHeap<double>;
template class MaxHeap<int>;
template class MaxHeap<float>;


