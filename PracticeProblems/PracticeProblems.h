//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/2/16.
//

#ifndef CPRACTICE_PRACTICEPROBLEMS_H
#define CPRACTICE_PRACTICEPROBLEMS_H

#include <string.h>
#include <string>
#include <vector>
#include <memory>
#include "./../DataStructures/LinkedList.h"
#include "./../DataStructures/BinaryTree.h"
#include "./../DataStructures/Queue.h"

using namespace std;

template <typename T>
class PracticeProblems {
public:
    static T MinRotatedArray(T[], int);
    static string CompressString(string original_string);
    static void PrintMatrix(vector<vector<T>>);
    static void Rotate90(vector<vector<T>>*);
    static void DedupeLinkedList(LinkedList<T>* ll);
    static bool Test();
    static LinkedList<T> AddNumberLinkedList(const LinkedList<T>*, const LinkedList<T>*);
    static LinkedList<T> AddNumberReverseLinkedList(const LinkedList<T>*, const LinkedList<T>*);
    static bool IsPalindromeLinkedList(const LinkedList<T>, int);
    static bool DFS(BinaryTree<T>*, T*);
    static bool BFS(BinaryTree<T>*, T*);
    static BinaryTree<T> ConstructBinaryTree(T[], int);
    static bool CheckBST(BinaryTree<T>*);
    static vector<vector<T>> SumPaths(BinaryTree<T>* tree, T sum);
    static int MatrixSteps(int, int);
    static int GetChange(int);
    static int QueenPositions(int);
private:
    static void Rotate90_internal(vector<vector<T>>*, int, int);
    static int AddNumberReverseLinkedListInternal(const LinkedListNode<T>*, int, const LinkedListNode<T>*, int, LinkedListNode<T>**);
    static bool IsPalindromLinkedListInternal(LinkedListNode<T> *, int, LinkedListNode<T> **);
    static bool DFSInternal(BinaryTreeNode<T>*, T*);
    static BinaryTreeNode<T>* ConstructBinaryTreeInternal(T[], int, int);
    static bool CheckBSTInternal(BinaryTreeNode<T>*, T**, T**);
    static vector<vector<T>> SumPathsInternal(BinaryTreeNode<T>* node, T sum);
    static int MatrixStepsInternal(int**, int, int);
    static int GetChangeInternal(int, int[], int, int);
    static int QueenPositionsInternal(int, int*, int);
    static bool QueenPositionIsValid(const int*, int, int, int);
};


#endif //CPRACTICE_PRACTICEPROBLEMS_H
