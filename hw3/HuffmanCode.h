/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Header (.h) file for Huffman Coding Algorithm
 *                 - Solution of Question 3)
 */

#ifndef HuffmanCode_h
#define HuffmanCode_h

#include "HuffmanQueue.h"
#include <fstream> // file read and write
#include <string> // for keeping dictionaries for pattern
using namespace std;
class HuffmanCode{
public:
    // Insert a node into queue of the huffman tree
    void hcInsert(const int freq, const char character);
    // size of the huffman queue
    int hcSize();
    // construct Huffman Tree
    HuffmanHeap::MinHeapNode*& createHuffmanTree();
    // traverse the huffman tree to obtain coding pattern
    // writes the pattern in a output file
    void getCodingPattern();
    // helper function to get coding patt