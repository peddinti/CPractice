//
// Created by Raghava Viswa Mani Kiran Peddinti on 8/30/16.
//

#ifndef CPRACTICE_SORTINGALGORITHMS_H
#define CPRACTICE_SORTINGALGORITHMS_H

template <typename T>
class SortingAlgorithms {
    static void Swap(T* v1, T* v2);
    static void QuickSortInternal(T sort_array[], int start, int end);
 public:
    static void BubbleSort(T sort_array[], int length);
    static void SelectionSort(T sort_array[], int length);
    static void InsertionSort(T sort_array[], int length);
    static void QuickSort(T sort_array[], int length);
    static void HeapSort(T sort_arrayp[], int length);
};
#endif //CPRACTICE_SORTINGALGORITHMS_H
