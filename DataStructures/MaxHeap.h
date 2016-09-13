//
// Created by Raghava Viswa Mani Kiran Peddinti on 8/31/16.
//

#ifndef CPRACTICE_MAXHEAP_H
#define CPRACTICE_MAXHEAP_H
#include "Node.h"

template <typename T>
class MaxHeap {
  private:
    Node<T> head;
    void BubbleUp(Node<T>* node);
    void BubbleDown(Node<T>* node);
  public:
    MaxHeap(T values[], int length);
    MaxHeap() : head() {};

    void Insert(T *value);
    T GetMax() const;
    T DeleteMax();
};


#endif //CPRACTICE_MAXHEAP_H
