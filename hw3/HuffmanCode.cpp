
/**
 * Title : Heaps and AVL Trees
 * Author : Zeynep Cankara
 * ID: 21703381
 * Section : 2
 * Assignment : 3
 * Description : Source (.cpp) file for constructing Huffman Tree includes Huffman Coding algorithm
 *                 - Implementation details given
 *                 - Solution of Question 3)
 */

#include "HuffmanCode.h"
using namespace std;

/**
 * @brief Insert a node into huffman Tree's priority queue
 */
void HuffmanCode::hcInsert(const int freq, const char character){
    queue.pqInsert(freq, character);
    pqSize++;
}
/**
 * @brief Returns initial size of the priority queue
 */
int HuffmanCode::hcSize(){
    return queue.size();
}

/**
 * @brief Constructs a Huffman Tree from the priority queue
 *         - The function executes the Huffman Coding algorithm
 */
HuffmanHeap::MinHeapNode*& HuffmanCode::createHuffmanTree(){
    // continue untill only one element left in the queue
    while (queue.size() > 1) {
        // extract 2 min elements from the queue
        HuffmanHeap::MinHeapNode *newNode = new HuffmanHeap::MinHeapNode;
        // dangling pointers prevented
        newNode->freq = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->character =  '\0'; // not to leave it null
        // assign min elements to the newly created node
        newNode->left = queue.pqDelete();
        newNode->right = queue.pqDelete();
        // new node's frequency is total of the children's frequency
        if((newNode->left != NULL) && (newNode->right != NULL)) {
            newNode->freq = ((newNode->left->freq) + (newNode->right->freq));
        } else if(newNode->left != NULL){
            newNode->freq = newNode->left->freq;
        }
        else {
            newNode->freq = 0;
        }
        newNode->character = '\0'; // not to leave it null
        // insert the new node pointer to queue
        queue.pqInsert(newNode);
    }
    root = queue.pqDelete();
    return root;
}

/**
 * @brief Writes the coding pattern of the Huffman Tree on an output file
 *        - Output file name output.txt
 */
void HuffmanCode::getCodingPattern(){
    // open file
    ofstream outFile;
    outFile.open("output.txt");
    if (!outFile) {
        cout << "ERROR: Can't open output file" << endl;
    } else {
        if (!root) {
            // empty root
            cout << "ERROR: Empty Huffman Tree" << endl;
            outFile.close();
            return;
        }
	    cout << "DONE: File opened" << endl; // test file opened
        // create dictionary to store pattern
        string *patternDict = new string[pqSize];
        char *characterDict = new char[pqSize];
        // will used to obtain pattern
        string curString = "";
        int curIndex = 0;
        getCodingPattern(root, patternDict, characterDict, curString, curIndex);
        // iterate over the dict to obtain pattern
        for (int i = 0; i < pqSize; i++) {
            outFile << characterDict[i] << " " << patternDict[i] << endl;
        }
        outFile.close();
    }
};

/**
 * @brief Helper function of getCodingPattern()
 *        - Performs inorder traversal on Huffman Tree to obtain coding pattern
 * @param node pointer to the min heap node