//
// Created by Raghava Viswa Mani Kiran Peddinti on 8/30/16.
//

#include "SortingAlgorithms.h"
#include "DataStructures/MaxHeap.h"
#include <iostream>
using namespace std;

template <typename T>
void SortingAlgorithms<T>::BubbleSort(T sort_array[], int length) {
    for (int i=length-1; i >= 0; i--) {
        for (int j=0; j < i; j++) {
            if (sort_array[j] > sort_array[j+1]) {
                // Shuffle the values
                Swap(&sort_array[j+1], &sort_array[j]);
            }
        }
    }
}

template <typename T>
void SortingAlgorithms<T>::SelectionSort(T *sort_array, int length) {
    for (int i = 0; i<length; i++) {
        T lowest_value = sort_array[i];
        int lowest_value_position = i;
        for (int j = i+1; j < length; j++) {
            if (sort_array[j] < lowest_value) {
                // swap the lowest value_ptr
                lowest_value = sort_array[j];
                lowest_value_position = j;
            }
        }
        // swap the lowest value_ptr to the ith position
        sort_array[lowest_value_position] = sort_array[i];
        sort_array[i] = lowest_value;
    }
}

template <typename T>
void SortingAlgorithms<T>::InsertionSort(T *sort_array, int length) {
    for (int i = 1; i < length-1; i++) {
        for (int j = i; j >= 0; j--) {
            // if the position at j value_ptr > position at j+1 swap else break
            if (sort_array[j+1] > sort_array[j]) {
                break;
            } else {
                // swap
                Swap(&sort_array[j+1], &sort_array[j]);
            }
        }
    }
}

template <typename T>
void SortingAlgorithms<T>::QuickSort(T *sort_array, int length) {
    if (length == 1) {
        return;
    }

    return QuickSortInternal(sort_array, 0, length-1);
}

template <typename T>
void SortingAlgorithms<T>::QuickSortInternal(T *sort_array, int start, int end) {
    if (start >= end) {
        return;
    }
    // getting the pivot first
    T pivot_value = sort_array[end];
    int pivot_position = start;
    for (int i = start; i < end; i++) {
        if (sort_array[i] < pivot_value) {
            // replace this value_ptr smaller than pivot with pivot position
            Swap(&sort_array[i], &sort_array[pivot_position]);
            // increment the new pivot position
            pivot_position++;
        }
    }
    // swap the pivot into the right position
    Swap(&sort_array[end], &sort_array[pivot_position]);

    // sort the left subset
    QuickSortInternal(sort_array, start, pivot_position - 1);
    // sort the right subset
    QuickSortInternal(sort_array, pivot_position + 1, end);
}

template <typename T>
void SortingAlgorithms<T>::HeapSort(T *sort_array, int length) {
    MaxHeap<T> heap;
    for (int i=0; i < length; i++) {
        cout << sort_array[i];
        heap.Insert(&sort_array[i]);
    }
    //for (int i=length-1; i>=0 ; i--) {
    //    auto value_ptr = heap.DeleteMax();
    //    sort_array[i] = value_ptr;
    //}
}

template <typename T>
void SortingAlgorithms<T>::Swap(T *v1, T *v2) {
    T temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

template class SortingAlgorithms<int>;
template class SortingAlgorithms<float>;
template class SortingAlgorithms<double>;