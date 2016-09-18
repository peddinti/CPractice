cmake_minimum_required(VERSION 3.6)
project(CPractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SortingAlgorithms.cpp SortingAlgorithms.h DataStructures/MaxHeap.cpp DataStructures/MaxHeap.h DataStructures/Node.cpp DataStructures/Node.h PracticeProblems/PracticeProblems.cpp PracticeProblems/PracticeProblems.h PracticeProblemsTests/PracticeProblemsTests.cpp PracticeProblemsTests/PracticeProblemsTests.h DataStructures/LinkedList.cpp DataStructures/LinkedList.h DataStructures/Queue.cpp DataStructures/Queue.h DataStructures/BinaryTree.cpp DataStructures/BinaryTree.h PracticeProblems/QuoraChallenges.cpp PracticeProblems/QuoraChallenges.h)
add_executable(CPractice ${SOURCE_FILES})