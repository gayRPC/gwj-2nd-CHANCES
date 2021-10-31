/**
 * Title: Algorithm Efficiency and Sorting
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 1
 * Description: Header file for the sorting algorithms + performance analysis
 */

#ifndef sorting_h
#define sorting_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>  // for timer
#include <stdlib.h>  //rand
#include <iomanip>
using namespace std;
/**
 *  @brief Sorts an array in ascending order
 *  Idea: array divided into (unsorted | sorted) subregions. Largest element bubble up with every iteration
 *  Worst case: O(n^2)
 *  Best case: O(n) where array "sorted" order
 *  Average case: O(n^2)
 */
void bubbleSort(int *arr, int size, int &compCount, int &moveCount);

/**
 *  @brief Sorts an array in ascending order
 *  Idea: array divided into (<pivot | >pivot) subregions around chosen pivot.
 *  Worst case: O(n^2)
 *  Best case: O