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
            // comparison arr[i] > arr[i+1