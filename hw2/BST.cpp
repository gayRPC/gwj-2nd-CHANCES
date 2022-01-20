/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: Source file of Binary Search Tree .
 *              Note: This file contains implementations. Detailed comments are in the header file
 */

#include "BST.h"
#include <iostream>
using namespace std;
// default constructor
BST::BST(){
    root = NULL;
}

// destructor
BST::~BST(){
    deleteTree(root);
}

// Insertion
void BST::insertItem(int key){
    // first find the position to insert
    insertItem(key, root);
}

// Deletion
void BST::deleteItem(int key){
    // First search for the node to delete
    // Case 1) Node has no children
    // Case 2) Node has only 1 child
    // Case 3) Node has 2 childeren
    searchToDelete(key, root);
};

// Fetch
BSTNode* BST::retrieveItem(int key){
    return retrieveItem(key, root);
};

// Inorder traversal
int* BST::inorderTraversal(int& length){
    length = 0; // safety
    countNodes(length, root);
    if (!length) {
        return NULL; // tree empty
    } else {
        // create an dynamically allocated array
        int *treeArray = new int[length];
        int idx = 0; // increment index within the function
        writeInArray(treeArray, idx, root);
        return treeArray;
    }
};


// check whether given array is a subequence within the tree
bool BST::containsSequence(int* seq, int length){
    int idx = 0;
    bool flag = false;
    BSTcontainsSequence(seq, length, idx, root, flag);
    return flag;
}

// Returns number of nodes whose level is greater than the level threshold
int BST::countNodesDeeperThan(int level){
    int numNodes = 0;
    countNodesDeeperThan(level, numNodes, root);
    return numNodes;
}

// returns maximum height if the tree could have height balanced.
int BST::maxBalancedHeight(){
    int curBalanced = 0;
    checkBalancedHeight(root, curBalanced);
    // root has only one child or have no child
    if ((root->rightChildPtr == NULL) || (root->leftChildPtr == NULL)){
        return ++curBalanced;
    }
    return curBalanced;
}



// ======= Private Methods of the BST Class (Helpers) ===========

// insertion
void BST::insertItem(const int &keyItem, BSTNode *&rootNode){
    if (!rootNode) {
        rootNode = new BSTNode(keyItem, NULL, NULL); // dynamic allocated node
    } else {
        // determine which brach to go
        if (keyItem < rootNode->item) {
            // look left
            insertItem(keyItem, rootNode->leftChildPtr);
        } else {
            // look right
            insertItem(keyItem, rootNode->rightChildPtr);
        }
    }
}

// empty check
bool BST::isEmpty(){
    if (root) {
        return false;
    }
    return true;
}

// desrtuctor helper
void BST::deleteTree(BSTNode *&rootNode){
    if (rootNode) { // root is not empty
        deleteTree(rootNode->leftChildPtr); // deallocate left subtree
        deleteTree(rootNode->rightChildPtr); // deallocate right subtree
        delete rootNode; // deallocate current node
        rootNode = NULL; // consistency
    }
}

// retrieve the item which contains the key value
BSTNode* BST::retrieveItem(const int &keyItem, BSTNode *&rootNode){
    // node is empty we searched and not found
    if (!rootNode) {
        // return NULL to indicate not found
        return NULL;
    } else {
        if (keyItem == rootNode->item) {
            return rootNode; // node found
        }
        else if (keyItem < rootNode->item) {
            // look left
            retrieveItem(keyItem, rootNode->leftChildPtr);
        }
        else {
            // look right
            retrieveItem(keyItem, rootNode->rightChildPtr);
        }
    }
    return NULL; // never falls to this case
}

// ===