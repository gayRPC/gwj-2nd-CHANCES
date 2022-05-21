
/**
 * Title: Binary Search Trees
 * Author: Zeynep Cankara
 * ID: 21703381
 * Section: 2
 * Assignment: 2
 * Description: Main file to test the code
 */

#include "BSTNode.h"
#include "BST.h"
#include <iostream>
using namespace std;

int main() {
    // insert code here...
    cout << "Hello, CS201 Homework 01" << endl;
    
    // Create the tree...
    cout << "=== Creating the tree ===" << endl;
    BST tree;
    //test for inserting items into the tree
    tree.insertItem(8);
    tree.insertItem(4);
    tree.insertItem(13);
    tree.insertItem(3);
    tree.insertItem(1);
    tree.insertItem(2);
    tree.insertItem(6);
    tree.insertItem(5);
    tree.insertItem(15);
    tree.insertItem(14);
    tree.insertItem(12);
    tree.insertItem(10);
    BST tree2;
    tree2.insertItem(1);
    tree2.insertItem(2);
    tree2.insertItem(3);
    tree2.insertItem(4);
    tree2.insertItem(5);
    tree2.insertItem(6);
    tree2.insertItem(7);
    BST tree3;
    tree3.insertItem(4);
    tree3.insertItem(3);
    tree3.insertItem(5);
    tree3.insertItem(6);
    tree3.insertItem(2);
    tree3.insertItem(1);
    BST tree4;
    tree4.insertItem(1);
    tree4.insertItem(2);
    BST tree5;
    tree5.insertItem(1);
    // inOrderTraversal than test...
    cout << "=== inorderTraversal method Test ===" << endl;
    cout << "Expected: [1, 2, 3, 4, 5, 6, 8, 10, 12, 13, 14, 15]" << endl;
    int length = 1000; // inOrder handles inappropiate length parameter values
    int *getArray = tree.inorderTraversal(length);
    for (int i = 0; i < length-1; i++) {
        cout << getArray[i] << ", ";
    }
    cout << getArray[length-1] << endl;
    // delete node test
    cout << "=== DeleteItems test delete key = 12 ===" << endl;
    cout << "Expected: [1, 2, 3, 4, 5, 6, 8, 10, 13, 14, 15]" << endl;
    tree.deleteItem(12); // key = 12 will deleted
    getArray = tree.inorderTraversal(length);
    for (int i = 0; i < length-1; i++) {
        cout << getArray[i] << ", ";
    }
    cout << getArray[length-1] << endl;
    cout << "=== DeleteItems test delete key = 1 (root) ===" << endl;
    cout << "Expected: [2, 3, 4, 5, 6, 8, 10, 13, 14, 15]" << endl;
    tree.deleteItem(1); // key = 12 will deleted
    getArray = tree.inorderTraversal(length);
    for (int i = 0; i < length-1; i++) {
        cout << getArray[i] << ", ";
    }
    // create another tree with the same values because the homework assignment has the same tree figure as well
    BST treeCpy;
    //test for inserting items into the tree
    treeCpy.insertItem(8);