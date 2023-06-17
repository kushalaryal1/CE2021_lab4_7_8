#ifndef arrayBST_h
#define arrayBST_h

#define MAX_NUM_NODES 128

#include "binaryTree.h"

struct ArrayNode {
    int key;
    int value;
    
    ArrayNode(int key, int value) : key(key), value(value) {}
};

class arrayBST : public binaryTree {
public:
    arrayBST();
    ~arrayBST();
    
    // Checks if the BST is empty
    bool isEmpty();
    void add(int key, int value);
    
    void max(int &output);
    void min(int &output);
    
    bool exists(int targetKey);
    
    void inorder();
    
private:
    ArrayNode* nodes[MAX_NUM_NODES];
    
    void inorder(int index, char sep = ' ');
};

#endif