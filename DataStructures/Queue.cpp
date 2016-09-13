//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/7/16.
//

#include "Queue.h"
#include "BinaryTree.h"
#include <string>
using namespace std;

template <typename T>
void Queue<T>::Push(T* val) {
    data.Insert(val);
    length++;
}

template <typename T>
T* Queue<T>::Pop() {
    T* value = data.GetHead()->value_ptr;
    data.Delete(*value);
    length--;
    return value;
}

template <typename T>
T* Queue<T>::Peek() {
    return data.GetHead()->value_ptr;
}

template <typename T>
int Queue<T>::Length() {
    return length;
}

template class Queue<int>;
template class Queue<string>;
template class Queue<BinaryTreeNode<int>>;
template class Queue<BinaryTreeNode<string>>;