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
     * @return maxElement -1 if the heap is empty
     * TODO: Done
     */
    int peek();
    
    /**
     * @brief retrieves and removes the max element
     * TODO:
     */
    int extractMax();
    
    /**
     * @brief returns the number of elements in the heap
     * TODO: Done
     */
    int size();
    
    /**
     * @brief Check heap is empty or not
     * @return flag indicating heap is empty or not
     */
    bool isEmpty();
    
private:
    int sizeHeap; // for tracking size of the array
    int *items; // array to keep the max-heap structure
    
    /**
     * @brief Deletes the root item which is also the max item from the heap
     */
    void heapDelete(int &rootItem);
    
    
    /**
     * @brief Rearrange the heap in orde