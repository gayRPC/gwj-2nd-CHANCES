/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Implementation of an array-baseds min heap.
 *             - Check header file (.h) for more detailed explenation of the code.
 */
#include "MinHeap.h"
#include <iostream> // #for cout <<
using namespace std;

const int MAX_SIZE2 = 100;

// Constructor
MinHeap::MinHeap(){
    sizeHeap = 0;
    items = new int[MAX_SIZE2];
}

// Destructor
MinHeap::~MinHeap(){
    if (!isEmpty()) {
        // deallocate the heap space
        delete [] items;
        sizeHeap = 0;
    }
}

// size
int MinHeap::size(){
    return sizeHeap;
}

// isEmpty
bool MinHeap::isEmpty(){
    if (sizeHeap > 0) {
        return false;
    }
  