//
// Created by Raghava Viswa Mani Kiran Peddinti on 9/2/16.
//

#include <iostream>
#include <vector>
#include <memory>
#include "PracticeProblemsTests.h"
#include "../PracticeProblems/PracticeProblems.h"
using namespace std;

bool PracticeProblemsTests::TestMinRotatedArray() {
    int array[] = {3,4,5,6,7,1,2};
    return PracticeProblems<int>::MinRotatedArray(array, 7) == 1;
}

bool PracticeProblemsTests::TestCompressString() {
    return (
            (PracticeProblems<string>::CompressString("aaaacccc") == "a4c4") &&
            (PracticeProblems<string>::CompressString("aaaacbbba") == "a4c1b3a1") &&
            (PracticeProblems<string>::CompressString("aacbbba") == "aacbbba")
    );
}

bool PracticeProblemsTests::TestRotate90() {
    vector<vector<int>> matrix = {{1,2,3, 4}, {5,6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    //vector<vector<int>> matrix = {{1,2}, {3,4}};
    PracticeProblems<int>::Rotate90(&matrix);
    vector<vector<int>> result = {{13,9,5,1}, {14,10,6,2}, {15,11,7,3}, {16,12,8,4}};
    return matrix == result;
}