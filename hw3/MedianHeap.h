/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Interface for the median heap data structure.
 *               Calculates median of the values inserted in O(1) time
 */

#ifndef MedianHeap_h
#define MedianHeap_h

#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream> // cout
using namespace std; // cout

class MedianHeap{
public:
    // constructor
    MedianHeap();
    
    /**
     * @brief inserts an element into MedianHeap
     * @param value integer to insert
     */
    void insert(int value);
    
    /**
     * @brief Find the median of the heap
     */
    int findMedian();
    
private:
    // 2 heaps to get median in O(1) time
    MaxHeap lower;
    MinHeap upper;
    // size of the median heap
    int size;
    /**
     * @brief Function for rebalancing the median heap
     * The heap needs to 