/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Implementation of an array-baseds max heap.
 *             - Check header file (.h) for more detailed explenation of the code.
 */

#include "MaxHeap.h"
#include <iostream> // for cout <<
using namespace std;
// Constructor
MaxHeap::MaxHeap(){
    sizeHeap = 0;
    items = new int[MAX_SIZE];
}

// Destructor
MaxHeap::~MaxHeap(){
    if (!isEmpty()) {
        // deallocate the heap space
        delete [] items;
        sizeHeap = 0;