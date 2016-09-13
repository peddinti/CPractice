#include <iostream>
#include "SortingAlgorithms.h"
#include "DataStructures/MaxHeap.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/BinaryTree.h"
#include "DataStructures/Queue.h"
#include "PracticeProblemsTests/PracticeProblemsTests.h"
#include "PracticeProblems/PracticeProblems.h"
#include <array>
#include <vector>
using namespace std;

int main() {
//    int array1[] = {-5, 2, 7, 1, -3, 3, 6, 3, 8, 4, -3, 5, 6, 1, -9};
//    BinaryTree<int> tree = PracticeProblems<int>::ConstructBinaryTree(array1, 15);
//    vector<vector<int>> paths = PracticeProblems<int>::SumPaths(&tree, 3);
    int count = PracticeProblems<int>::QueenPositions(8);
    return 0;
}