//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/2/16.
//

#include "PracticeProblems.h"
#include "./../DataStructures/Queue.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template <typename T>
T PracticeProblems<T>::MinRotatedArray(T *array, int length) {
    int start = 0, end = length;

    while (start < end) {
        int middle = (start + end)/2;
        if (middle == start) {
            if (array[start] < array[end]) {
                end = start;
            } else {
                start = end;
            }
        } else if (array[start] > array[middle]) {
            // Look Left
            end = middle;
        } else {
            // Look right
            start = middle;
        }
    }
    return array[start];
}

template <>
string PracticeProblems<string>::CompressString(string original_string) {
    ostringstream stream;
    int length = original_string.length();
    char previous = original_string[0];
    int count = 1;
    for (int i = 1; i < length; i++) {
        if (previous != original_string[i]) {
            stream << previous << count;
            previous = original_string[i];
            count = 1;
        } else {
            count++;
        }
    }
    stream << previous << count;
    string new_string = stream.str();
    if (new_string.length() > length) {
        return original_string;
    } else {
        return new_string;
    }
}

template <typename T>
void PracticeProblems<T>::PrintMatrix(vector<vector<T>> matrix){
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

template <typename T>
void PracticeProblems<T>::Rotate90(vector<vector<T>> *matrix) {
    int size = matrix->size();
    return Rotate90_internal(matrix, 0, size);
}

template <typename T>
void PracticeProblems<T>::Rotate90_internal(vector<vector<T>>* matrix, int start, int size) {
    int row_count = matrix->size();
    if (row_count == 0) {
        return;
    }
    int col_count = (*matrix).size();
    for (int i = start; i < start+size-1; i++) {
        T previous_value = (*matrix)[start][i];
        // original values
        int r = start;
        int c = i;
        // new values
        int t = r;
        r = c;
        c = row_count - 1 - t;
        while (!(r == start && c == i)) {
            // swapping values
            T temp = (*matrix)[r][c];
            (*matrix)[r][c] = previous_value;
            previous_value = temp;
            // updating r and c
            int t = r;
            r = c;
            c = row_count - 1 - t;
        }
        (*matrix)[start][i] = previous_value;
    }
    // if row_count > 2, rotate inner matrix
    if (size > 2) {
        Rotate90_internal(matrix, start+1, size-2);
    }
    return;
}

template <typename T>
static void DedupeLinkedList(LinkedList<T>* ll) {
    LinkedListNode<T>* first_pointer = ll->GetHead();
    while (first_pointer->next != nullptr) {
        LinkedListNode<T>* second_pointer = first_pointer->next;
        while (second_pointer->next != nullptr) {
            if (*first_pointer->value_ptr == *second_pointer->value_ptr) {
                // Delete the first occurance of the value_ptr
                ll->Delete(*second_pointer->value_ptr);
                break;
            }
        }
    }
}

template <>
LinkedList<int> PracticeProblems<int>::AddNumberLinkedList(const LinkedList<int>* list1,
                                                           const LinkedList<int>* list2) {
    const LinkedListNode<int>* list1_previous = list1->GetHead();
    const LinkedListNode<int>* list2_previous = list2->GetHead();
    vector<int>* resultValues = new vector<int>();
    int size = 0;
    int carryover=0;
    while(list1_previous != nullptr && list2_previous != nullptr) {
        int value = *(list1_previous->value_ptr) + *(list2_previous->value_ptr) + carryover;
        carryover = value / 10;
        value = value % 10;
        resultValues->push_back(value);
        size++;
        list1_previous = list1_previous->next;
        list2_previous = list2_previous->next;
    }
    // If one of the lists is longer than other.
    while(list1_previous != nullptr) {
        int value = (*list1_previous->value_ptr) + carryover;
        carryover = value / 10;
        value = value % 10;
        resultValues->push_back(value);
        size++;
        list1_previous = list1_previous->next;
    }
    // If one of the lists is longer than other.
    while(list2_previous != nullptr) {
        int value = (*list2_previous->value_ptr) + carryover;
        carryover = value / 10;
        value = value % 10;
        resultValues->push_back(value);
        size++;
        list2_previous = list2_previous->next;
    }
    LinkedList<int> result(&resultValues->at(0), size);
    return result;
}

template <>
int PracticeProblems<int>::AddNumberReverseLinkedListInternal(const LinkedListNode<int>* list1, int list1_length, const LinkedListNode<int>* list2, int list2_length, LinkedListNode<int>** returnNode) {
    if (list1_length == 0 && list2_length == 0)
        return 0;
    LinkedListNode<int>* node = new LinkedListNode<int>();
    int carryover = 0;
    int value = 0;
    if (list1_length == list2_length) {
        carryover = AddNumberReverseLinkedListInternal(list1->next, list1_length -1, list2->next, list2_length-1, &node->next);
        value = *list1->value_ptr + *list2->value_ptr + carryover;
    } else if (list1_length > list2_length) {
        carryover = AddNumberReverseLinkedListInternal(list1->next, list1_length -1, list2, list2_length, &node->next);
        value = *list1->value_ptr  + carryover;
    } else {
        carryover = AddNumberReverseLinkedListInternal(list1, list1_length, list2->next, list2_length-1, &node->next);
        value = *list2->value_ptr  + carryover;
    }
    int* returnValue = new int(value % 10);
    node->value_ptr = returnValue;
    *returnNode = node;
    return value/10;
}

template <>
LinkedList<int> PracticeProblems<int>::AddNumberReverseLinkedList(const LinkedList<int>* list1,
                                                                  const LinkedList<int>* list2) {
    int list1_length = list1->Length();
    int list2_length = list2->Length();
    LinkedListNode<int>* head;
    int carryover = PracticeProblems<int>::AddNumberReverseLinkedListInternal(list1->GetHead(), list1_length, list2->GetHead(), list2_length, &head);
    if (carryover > 0) {
        LinkedListNode<int>* new_head = new LinkedListNode<int>();
        int* value = new int(carryover);
        new_head->value_ptr = value;
        new_head->next = head;
        head = new_head;
    }
    LinkedList<int> result(*head);
    return result;
}

template <typename T>
bool PracticeProblems<T>::IsPalindromLinkedListInternal(LinkedListNode<T>* head, int length, LinkedListNode<T>** tail) {
    if (length == 1) {
        // list is of odd length and hence satisfies the palindrome requirements
        *tail = head;
        return true;
    } else if (length == 2) {
        // list is of even length and hence compare the elements
        *tail = head->next;
        return (*head->value_ptr == *head->next->value_ptr);
    } else {
        // recursion
        bool result = IsPalindromLinkedListInternal(head->next, length - 2, tail);
        result &= (*head->value_ptr == *(*tail)->value_ptr);
        *tail = (*tail)->next;
        return result;
    }
}

template <typename T>
bool PracticeProblems<T>::IsPalindromeLinkedList(const LinkedList<T> list, int length) {
    LinkedListNode<T>* tail;
    bool result = IsPalindromLinkedListInternal(list.GetHead(), length, &tail);
    return result;
}

template <typename T>
bool PracticeProblems<T>::DFS(BinaryTree<T>* tree, T* value) {
    if (tree == nullptr)
        return false;
    return DFSInternal(tree->GetHead(), value);
}

template <typename T>
bool PracticeProblems<T>::BFS(BinaryTree<T>* tree, T* value) {
    Queue<BinaryTreeNode<T>>* queue = new Queue<BinaryTreeNode<T>>();
    queue->Push(tree->GetHead());
    do {
        BinaryTreeNode<T>* node = queue->Pop();
        if (*node->value == *value) {
            return true;
        }
        if (node->leftNode != nullptr)
            queue->Push(node->leftNode);
        if (node->rightNode != nullptr)
            queue->Push(node->rightNode);

    } while(queue->Length() > 0);
    return true;
}

template <typename T>
BinaryTree<T> PracticeProblems<T>::ConstructBinaryTree(T values[], int length) {
    BinaryTreeNode<T>* head = ConstructBinaryTreeInternal(values, 0, length-1);
    BinaryTree<T> tree(head);
    return tree;
}

template <typename T>
bool PracticeProblems<T>::CheckBST(BinaryTree<T> * tree) {
    T *min, *max;
    return CheckBSTInternal(tree->GetHead(), &min, &max);
}

template <typename T>
vector<vector<T>> PracticeProblems<T>::SumPaths(BinaryTree<T> *tree, T sum) {
    return SumPathsInternal(tree->GetHead(), sum);
}

template <typename T>
int PracticeProblems<T>::MatrixSteps(int X, int Y) {
    int** stepCount;
    stepCount = new int* [X];
    for (int i=0;i < X; i++) {
        stepCount[i] = new int[Y];
        fill_n(stepCount[i], Y, 0);
    }
    int count = MatrixStepsInternal(stepCount, X-1, Y-1);
    return count;
}

template <typename T>
int PracticeProblems<T>::GetChange(int sum) {
    int denoms[] = {25, 10, 1};
    return GetChangeInternal(sum, denoms, 3, 0);
}

template <typename T>
int PracticeProblems<T>::QueenPositions(int dim) {
    int* positions = new int[dim];
    return QueenPositionsInternal(dim, positions, 0);
}

template <typename T>
bool PracticeProblems<T>::CheckBSTInternal(BinaryTreeNode<T> * node, T ** min, T ** max) {
    if (node == nullptr)
        return false;
    *min = node->value;
    *max = node->value;
    T *left_min = node->value, *left_max = node->value, *right_min = node->value, *right_max = node->value;
    bool result = true;
    if (node->leftNode != nullptr) {
        result &= CheckBSTInternal(node->leftNode, &left_min, &left_max);
        result &= (*left_min <= *node->value) && (*node->leftNode->value <= *node->value);
    }
    if (!result)
        return false;
    if (node->rightNode != nullptr) {
        result &= CheckBSTInternal(node->rightNode, &right_min, &right_max);
        result &= (*right_max > *node->value) && (*node->rightNode->value > *node->value);
    }
    *min = left_min;
    *max = right_max;
    return result;
}

template <typename T>
BinaryTreeNode<T>* PracticeProblems<T>::ConstructBinaryTreeInternal(T values[], int start, int end) {
    // error check
    if (start > end) {
        return nullptr;
    }
    int middle = ((end - start) / 2) + start;
    BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
    node->value = &values[middle];
    if (start < middle) {
        node->leftNode = ConstructBinaryTreeInternal(values, start, middle-1);
        if (node->leftNode != nullptr) {
            node->leftNodeHeight = max(node->leftNode->leftNodeHeight, node->leftNode->rightNodeHeight) + 1;
        }
    }
    if (end > middle) {
        node->rightNode = ConstructBinaryTreeInternal(values, middle+1, end);
        if (node->rightNode != nullptr) {
            node->rightNodeHeight = max(node->rightNode->leftNodeHeight, node->rightNode->rightNodeHeight) + 1;
        }
    }
    return node;
}

template <typename T>
bool PracticeProblems<T>::DFSInternal(BinaryTreeNode<T> * node, T * value) {
    if (node == nullptr)
        return false;
    bool result = false;
    if (node->leftNode != nullptr) {
        result |= DFSInternal(node->leftNode, value);
    }
    if (result)
        return result;
    if (node->rightNode != nullptr) {
        result |= DFSInternal(node->rightNode, value);
    }
    if (result)
        return result;
    return (*node->value == *value);
}

template <typename T>
vector<vector<T>> PracticeProblems<T>::SumPathsInternal(BinaryTreeNode<T>* node, T sum) {
    vector<vector<T>> new_paths;
    if (node == nullptr)
        return new_paths;
    if (node->leftNode != nullptr) {
        vector<vector<T>> leftPaths = SumPathsInternal(node->leftNode, (sum - *node->value));
        // push current node at first for each path
        for (auto& path : leftPaths) {
            path.push_back(*node->value);
        }
        new_paths.insert(new_paths.end(), leftPaths.begin(), leftPaths.end());
        // concat all paths which start from child node and have same value
        leftPaths = SumPathsInternal(node->leftNode, *node->value);
        new_paths.insert(new_paths.end(), leftPaths.begin(), leftPaths.end());
    }
    if (node->rightNode != nullptr) {
        vector<vector<T>> rightPaths = SumPathsInternal(node->rightNode, (sum - *node->value));
        // push current node at first for each path
        for (auto& path : rightPaths) {
            path.push_back(*node->value);
        }
        new_paths.insert(new_paths.end(), rightPaths.begin(), rightPaths.end());
        // concat all paths which start from child node and have same value
        rightPaths = SumPathsInternal(node->leftNode, *node->value);
        new_paths.insert(new_paths.end(), rightPaths.begin(), rightPaths.end());
    }
    if (*node->value == sum) {
        vector<T> path;
        path.push_back(*node->value);
        new_paths.push_back(path);
    }
    return new_paths;
}

template <typename T>
int PracticeProblems<T>::MatrixStepsInternal(int ** stepCounts, int x, int y) {
    if (x == 0 && y == 0) {
        stepCounts[x][y] = 1;
    } else if (stepCounts[x][y] != 0) {
        return stepCounts[x][y];
    } else if (x == 0) {
        stepCounts[x][y] = MatrixStepsInternal(stepCounts, x, y - 1);
    } else if (y == 0) {
        stepCounts[x][y] = MatrixStepsInternal(stepCounts, x-1, y);
    } else {
        stepCounts[x][y] = MatrixStepsInternal(stepCounts, x-1, y) + MatrixStepsInternal(stepCounts, x, y-1);
    }
    return stepCounts[x][y];
}

template <typename T>
int PracticeProblems<T>::GetChangeInternal(int sum, int denoms[], int denom_length, int level) {
    // Base condition
    if ((denom_length - 1) == level)
        return 1;
    int maxValue = sum/denoms[level];
    int noWays = 0;
    for (int i=0; i<=maxValue; i++) {
        noWays += GetChangeInternal((sum - (i*denoms[level])), denoms, denom_length, level+1);
    }
    return noWays;
}

template <typename T>
int PracticeProblems<T>::QueenPositionsInternal(int dim, int* positions, int col) {
    if (col >= dim)
        return 1;
    int sum = 0;
    for (int i=0; i<dim; i++) {
        positions[col] = i;
        if (QueenPositionIsValid(positions, dim, i, col)) {
            sum += QueenPositionsInternal(dim, positions, col+1);
        }
    }
    return sum;
}

template <typename T>
bool PracticeProblems<T>::QueenPositionIsValid(const int* positions, int dim, int row, int col) {
    // check if there is any other queen in the same row for other columns
    for (int i=0; i<col; i++) {
        if (positions[i] == row)
            return false;
    }

    // check if there is any other queen on top and bottom diagonal
    for (int i=1; i<=col; i++) {
        if ((row - i) >= 0) {
            if (positions[col-i] == (row-i))
                return false;
        }

        if ((row + i) < dim) {
            if (positions[col-i] == (row + i))
                return false;
        }
    }
    return true;
}

template class PracticeProblems<int>;