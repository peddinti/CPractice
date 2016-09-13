//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/3/16.
//

#ifndef CPRACTICE_LINKEDLIST_H
#define CPRACTICE_LINKEDLIST_H

template <typename T>
struct LinkedListNode {
    T* value_ptr;
    LinkedListNode<T>* next;
    LinkedListNode() : value_ptr(nullptr), next(nullptr) {};
    LinkedListNode(T* val, LinkedListNode<T>* next_ptr) : value_ptr(val), next(next_ptr) {};
};

template <typename T>
class LinkedList {
private:
    mutable LinkedListNode<T> head;
    LinkedListNode<T>* GetTail();
public:
    LinkedList() : head() {};
    LinkedList(T[], int);
    LinkedList(LinkedListNode<T> head): head(head) {};
    void Insert(T*);
    bool Search(T*) const;
    bool Delete(const T);
    LinkedListNode<T>* GetHead() const;
    void Print();
    int Length() const;
    void set_head(LinkedListNode<T> head);
    static LinkedList<T> Add(const LinkedList<T>*, const LinkedList<T>*);
};


#endif //CPRACTICE_LINKEDLIST_H
