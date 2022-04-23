
/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: Header file of Binary Search Tree. Contains protototypes of tree fucntions.
 *              Note: This file is the private interface.
 */

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include "BSTNode.h"

class BST{
public:
    // default constructor
    BST();
    // destructor free nodes
    ~BST();
    
    /**
     *  @brief Inserts the key (int) to corresponding place in the tree
     *  @param key integer item value
     */
    void insertItem(int key);
    
    /**
     *  @brief Deletes the key (int) if it exists
     *  @param key integer target item value
     */
    void deleteItem(int key);
    
    /**
     *  @brief Returns the node which contains the key
     *  @param key integer target item value
     */
    BSTNode* retrieveItem(int key);
    
    /**
     *  @brief Performs inorder traversal writes data into an array returns the size of array within length
     *  @param length size of array
     *  @return array contains node items in sorted order
     */