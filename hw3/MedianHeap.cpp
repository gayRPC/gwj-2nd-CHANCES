/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Implementation of an hybrid median heap data structure
 *             - Check header file (.h) for more detailed explenation of the code.
 */

#include "MedianHeap.h"

MedianHeap::MedianHeap(){
    size = 0;
    upper = MinHeap();
    lower = MaxHeap();
}

// find the insertion point of the array
void MedianHeap::insert(int value){
    // 1) Check the max heap's size
    // 2) If there it's empty or value smaller than lower's max add to the max-heap
    if(lower.isEmpty() || (value < lower.peek())){
        lower.insert(value);
        rebalance();
        size++;
        // check the balance condition
    } else {
        upper.insert(value);
        reba