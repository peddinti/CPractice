//
// Created by Raghava Viswa Mani Kiran Peddinti on 8/31/16.
//

#ifndef CPRACTICE_NODE_H
#define CPRACTICE_NODE_H

template <typename T>
struct Node {
    Node* leftNode = nullptr;
    Node* rightNode = nullptr;
    Node* parentNode = nullptr;
    T* value;

    int leftDepth = 0;
    int rightDepth = 0;

    Node(Node* left, Node* right, Node* parent, T* val);
    Node();
    int Depth();
};

#endif //CPRACTICE_NODE_H
