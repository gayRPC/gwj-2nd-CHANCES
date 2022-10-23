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
    return true;
}

// returns the max element of the heap
int MinHeap::peek(){
    // maximum element always be the first element of the heap
    if (!isEmpty()) {
        return items[0];
    }
    // boolean flag indicating not found
    cout << "ERROR: The heap is empty" << endl;
    return -1;
}

// insert a new value into the heap
void MinHeap::insert(int value){
    // 0) Check whether there is a space left for inserting the value
    // 1) Appand the new value at the end of the array
    // 2) Go up to by checking parents and max heap condition
    if (size() >= MAX_SIZE2) {
        // 0) reached to the maximum size
        cout << "ERROR: max size reached can't insert!" << endl;
        return;
    } else {
        // place the item at the end
        items[sizeHeap] = value;
        
        // rem