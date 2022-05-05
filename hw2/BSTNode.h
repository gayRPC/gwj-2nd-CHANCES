/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: header file of Binary Search Tree Node Class. Node data type: int
 *              Note: This file is the private interface for BSTNode.
 */

#ifndef BSTNode_h
#define BSTNode_h

#include <stdio.h>

class BSTNode{
private:
    // instance variables
    int item;
    BSTNode *leftChildPtr;
    BSTNode *rightChildPtr;
    
    // default constructor
    BSTNode();
 
    /**
     * @brief Constructor which initializes the node with given parameters
     * @param nodeItem integer key
     * @param left BSTNode pointer left child
   