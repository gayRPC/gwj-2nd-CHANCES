/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Interface for the max heap data structure.
 *             - Note: Methods with TODO are required functions for the assignment
 */

#ifndef MaxHeap_h
#define MaxHeap_h

const int MAX_SIZE = 100;
class MaxHeap {
public:
    // Constructor
    MaxHeap();
    
    // Destructor
    ~MaxHeap();
    
    /**
     * @brief inserts integer into heap
     * @param value type(int)
     * TODO: Done
     */
    void insert(int value);
    
    /**
     * @brief returns the value of the max element
     * @return maxEleme