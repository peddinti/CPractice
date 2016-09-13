//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/7/16.
//

#ifndef CPRACTICE_STACK_H
#define CPRACTICE_STACK_H

#include "LinkedList.h"

template <typename T>
class Queue {
private:
    LinkedList<T> data;
    int length = 0;
public:
    Queue(T values[], int length) : data(values, length) {};
    Queue() {};
    void Push(T* value);
    T* Pop();
    T* Peek();
    int Length();
};


#endif //CPRACTICE_STACK_H
