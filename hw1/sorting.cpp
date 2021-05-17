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


void merge(int *arr, int start, int mid, int end, int &compCount, int &moveCount){
    // pointer to the first half
    int p1 = start;
    // pointer to the second half
    int p2 = mid+1;
    int *temp = new int[end - start + 1];
    int cnt = 0;
    while (p1 <= (mid) && p2 <= end) {
        if (arr[p2] < arr[p1]) {
            temp[cnt++] = arr[p2];
            p2 += 1;
        } else {
            temp[cnt++] = arr[p1];
            p1 += 1;
        }
        // 1 comparison
        compCount++;
        // 1 data movement
        moveCount++;
    }
    // check remeaning element in the first half
    // NOTE: p1 <= (mid) is not an array element comparison it is an index comparison
    while (p1 <= (mid)) {
        temp[cnt++] = arr[p1];
        p1 += 1;
        // 1 data movement
        moveCount++;
    }
    // check remeaning element in the second half
    // NOTE: p2 <= (end) is not an array element comparison it is an index comparison
    while (p2 <= end) {
        temp[cnt++] = arr[p2];
        p2 += 1;
        // 1 data movement
        moveCount++;
    }

    // 