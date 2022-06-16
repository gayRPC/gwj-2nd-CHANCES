
/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Implementation of Huffman heap which is a min heap used for Huffman Coding
 */

#include "HuffmanHeap.h"
using namespace std;

// Constructor
HuffmanHeap::HuffmanHeap(){
    sizeHeap = 0;
}


// size
int HuffmanHeap::size(){
    return sizeHeap;
}

// isEmpty
bool HuffmanHeap::isEmpty() const{
    if (sizeHeap > 0) {
        return false;
    }
    return true;
}

// returns a pointer to the node at the top of the min heap
int HuffmanHeap::peek() {
    // maximum element always be the first element of the heap
    if (!isEmpty()) {
        return (*items[0]).freq;
    }
    return 0;
}

// insert a new value into the heap