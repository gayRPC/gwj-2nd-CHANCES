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
 *  Best case: O(n*log(n)) efficient pivot selection
 *  Average case: O(n*log(n))
 *  @param arr array to be sorted
 *  @param size size of the array
 *  @param compCount number of comparisons between array element
 *  @param moveCount number of data moves
 */
void quickSort(int *arr, int size, int &compCount, int &moveCount);


/**
 *  @brief Sorts an array in ascending order
 *  Idea: Divide array in half. Sort subarrays. Merge subarrays
 *  Worst case: O(n*log(n))
 *  Best case: O(n*log(n)) Independent of the array sorted or not
 *  Average case: O(n*log(n)) Independent of the array sorted or not
 *  @param arr array to be sorted
 *  @param size size of the array
 *  @param compCount number of comparisons between array element
 *  @param moveCount number of data moves
 */
void mergeSort(int *arr, int size, int &compCount, int &moveCount);

/**
 * Find the number in the array with the highest number of digits
 * Create 10 container (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
 * Starting from the least sig digit group the numbers within the containers
 */
void radixSort(int *arr, int size);


/**
 * @brief Prints contents of 