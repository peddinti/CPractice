//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/3/16.
//

#include "LinkedList.h"
#include "BinaryTree.h"
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList(T array[], int length) {
    // creating the head first
    LinkedListNode<T>* previous = new LinkedListNode<T>(&array[0], nullptr);
    head = *previous;
    for (int i = 1; i < length; i++) {
        previous->next = new LinkedListNode<T>(&array[i], nullptr);
        if (i==1) {
            head = *previous;
        }
        previous = previous->next;
    }
}

template <typename T>
LinkedListNode<T>* LinkedList<T>::GetTail() {
    LinkedListNode<T>* previous = &head;
    while (previous->next != nullptr) previous = previous->next;
    return previous;
}

template <typename T>
void LinkedList<T>::Insert(T* val) {
    LinkedListNode<T>* tail = GetTail();
    tail->next = new LinkedListNode<T>(val, nullptr);
}

template <typename T>
bool LinkedList<T>::Search(T* val) const {
    LinkedListNode<T>* previous;
    *previous = head;
    while (previous->next != nullptr && (*previous->value_ptr != *val)) previous = previous->next;
    if (*previous->value_ptr == *val) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool LinkedList<T>::Delete(const T val) {
    LinkedListNode<T>* previous = &head;
    // search for the value_ptr
    // Checking if the head matches
    if (*previous->value_ptr == val) {
        // replace head with next element
        previous = previous->next;
        head = *previous;
        return true;
    }

    while (previous->next != nullptr && (*previous->next->value_ptr != val)) previous = previous->next;

    if (previous->next == nullptr) {
        // no match
        return false;
    } else {
        // there is match and node is previous-> next
        LinkedListNode<T>* match_node = previous->next;
        previous->next = match_node->next;
        delete match_node;
        return true;
    }
}

template <typename T>
LinkedListNode<T>* LinkedList<T>::GetHead() const {
    return &head;
}

template <typename T>
void LinkedList<T>::set_head(LinkedListNode<T> head_value) {
    head = head_value;
}

template <typename T>
void LinkedList<T>::Print() {
    LinkedListNode<T>* node = &head;
    while(node->next != nullptr) {
        cout << *(node->value_ptr) << "->";
        node = node->next;
    }
    cout << *(node->value_ptr);
    cout << endl;
}

template <typename T>
int LinkedList<T>::Length() const {
    LinkedListNode<T>* node = &head;
    int length = 0;
    while (node != nullptr) {
        node = node->next;
        length++;
    }
    return length;
}

template class LinkedList<int>;
template class LinkedList<string>;
template class LinkedList<BinaryTreeNode<int>>;
template class LinkedList<BinaryTreeNode<string>>;


