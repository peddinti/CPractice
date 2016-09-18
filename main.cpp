#include <iostream>
#include "SortingAlgorithms.h"
#include "DataStructures/MaxHeap.h"
#include "DataStructures/LinkedList.h"
#include "DataStructures/BinaryTree.h"
#include "DataStructures/Queue.h"
#include "PracticeProblemsTests/PracticeProblemsTests.h"
#include "PracticeProblems/PracticeProblems.h"
#include "PracticeProblems/QuoraChallenges.h"
#include <array>
#include <vector>
using namespace std;

int main() {
//    int array1[] = {-5, 2, 7, 1, -3, 3, 6, 3, 8, 4, -3, 5, 6, 1, -9};
//    BinaryTree<int> tree = PracticeProblems<int>::ConstructBinaryTree(array1, 15);
//    vector<vector<int>> paths = PracticeProblems<int>::SumPaths(&tree, 3);
    int count = PracticeProblems<int>::QueenPositions(8);

    int array[] = {1,2,3,4,5};
    int* trends = new int(3);
    //cout << QuoraChallenges::NonDecreasingRange(array, 1, 3);
    //cout << QuoraChallenges::NonIncreasingRange(array, 1, 3);
//    QuoraChallenges::UpVotesTrend(array, 5, 3, trends);
//    int reading_times[] = {2, 2, 1, 2, 2};
//    vector<pair<int, int>> relations = {{1,2}, {2,3}, {3,4}, {4,5}};
//    //auto questions = QuoraChallenges::CreateRelatedQuestions(5, reading_times, relations);
//    //float cost = QuoraChallenges::ComputeCost(questions[1], nullptr);
//    int position = QuoraChallenges::BestRelatedQuestion(5, reading_times, relations);
    auto results = PracticeProblems<int>::MakeSums(array, 5, 3);
    return 0;
}