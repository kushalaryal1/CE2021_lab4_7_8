#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "binaryTree.h"

struct Data {
    int key;
    int data;
};

struct Node {
    Data data;
    
    Node* leftChild;
    Node* rightChild;
};

class LinkedBST : public binaryTree {
public:
    LinkedBST();
    ~LinkedBST();
    
    // Checks if the BST is empty
    bool isEmpty();
    void add(int key, int value);
    
    void max(int &output);
    void min(int &output);
    
    bool exists(int targetKey);
    
    void inorder();
    
private:
    Node* root;
    
    void add(Node* root, Node* newNode);
    void inorder(Node* node, char sep = ' ');
};
#endif