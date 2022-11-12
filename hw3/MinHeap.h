/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Interface for the min heap data structure.
 *             - Note: Methods with TODO are required functions for the assignment
 */

#ifndef MinHeap_h
#define MinHeap_h

// ========= MIN HEAP =========== //
class MinHeap{
public:
    // Constructor
    MinHeap();
    
    // Destructor
    ~MinHeap();
    
    /**
     * @brief inserts integer into heap
     * @param value type(int)
     * TODO: Done
     */
    void insert(int value);
    
    /**
     * @brief returns the value of the min element
     * @return minElement -1 if the heap is empty
     * TODO: Done
     */
    int peek();
    
    /**
     * @brief retrieves and removes the min element
     * TODO:
     */
    int extractMin();
    
    /**
     * @brief returns the number of elements in the heap
     * TODO: Done
     */
    int size();
    
    /**
     * @b