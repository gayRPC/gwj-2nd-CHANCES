/**
* Title: Algorithm Efficiency and Sorting
* Author: Zeynep Cankara
* ID: 21703381
* Section: 2
* Assignment: 1
* Description: Cpp file for the sorting algorithms + performance analysis
*/

#include "sorting.h"
using namespace std;

// BUBBLE SORT
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, int size, int &compCount, int &moveCount){
    int boundary = size - 2;
    while (boundary >= 0) {
        for (int i = 0; i <= boundary; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                // swap makes 3 data moves
                moveCount += 3;
            }
            // comparison arr[i] > arr[i+1]
            compCount++;
        }
        boundary -= 1;
    }
}


// MERGE SORT
void mergeSort(int *arr, int size, int &compCount, int &moveCount){
    mergeSort(arr, 0, size-1, compCount, moveCount);
}


void mergeSort(int *arr, int start, int end, int &compCount, int &moveCount){
    if (start != end) {
        // step1: divide from middle
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, end, compCount, moveCount);

        // step2: conquer the divided steps
        merge(arr, start, mid, end, compCount, moveCount);
    }
}


void merge(int *arr, int 