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
        rebalance();
        size++;
    }
}



// helper to determine the heap with the bigger size
void MedianHeap::findBiggerHeap(int &flag, int &maxSize, int &minSize){
    if (lower.size() > upper.size()) {
        // max heap size is bigger
        flag = 1;
        maxSize = lower.size();
        minSize = upper.size();
    } else {
        // min heap size is bigger
        flag = 0;
        maxSize = upper.size();
        minSize = lower.size();
    }
}

// rebalances the max-heap and min-heap size when they differ more than 1 item
void MedianHeap::rebalance(){
    // determine the heap which has the gratest size
    int flag = -1;
    int maxSize;
    int minSize;
    findBiggerHeap(flag, maxSize, minSize);
    // rebalance if the size of heaps differ more than 1 element
    if (maxSize - minSize > 1) {
        if (lower.size() > upper.size()) {
            // max heap has the bigger size
            // get element from the max heap and add to the min heap
            upper.insert(lower.extractMax());
        } else {
            // min heap has a greater size
            // get element from the min heap and