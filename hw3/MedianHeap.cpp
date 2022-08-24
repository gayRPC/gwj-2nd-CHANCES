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
    lower = MaxHe