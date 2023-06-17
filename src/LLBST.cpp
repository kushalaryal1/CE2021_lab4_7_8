#include <stdio.h>
#include <iostream>

#include "LLBST.h"

LinkedBST::LinkedBST() : root(NULL) {}
LinkedBST::~LinkedBST(){
    delete root;
}

bool LinkedBST::isEmpty()
{
    return this->root == NULL;
}

void LinkedBST::add(int key, int value)
{
    Node* newNode(new Node);
    newNode->data.key = key;
    newNode->data.data = value;
    newNode->leftChild = newNode->rightChild = NULL;
    
    if (this->isEmpty())
    {
        this->root = newNode;
    }
    else
    {
        this->add(this->root, newNode);
    }
}

void LinkedBST::add(Node *subtreeRoot, Node *newNode)
{
    
    if (subtreeRoot->data.key > newNode->data.key) {
        if (subtreeRoot->leftChild != NULL) {
            add(subtreeRoot->leftChild, newNode);
        }
        else {
            subtreeRoot->leftChild = newNode;
        }
    }
    else if (subtreeRoot->data.key < newNode->data.key) {
        if (subtreeRoot->rightChild != NULL) {
            add(subtreeRoot->rightChild, newNode);
        }
        else {
            subtreeRoot->rightChild = newNode;
        }
    }
    else
    {
        // Duplicate key
        std::cout << "Duplicate key!!" << std::endl;
    }
}

void LinkedBST::inorder() {
    std::cout << "Inorder traversal yields " << std::endl;
    this->inorder(this->root);
    std::cout << std::endl;
}

void LinkedBST::inorder(Node *node, char sep) {
    if (node != NULL) {
        inorder(node->leftChild);
        std::cout << node->data.key << sep;
        inorder(node->rightChild);
    }
}

void LinkedBST::max(int &output) {
    
    if (!this->isEmpty()) {
        Node* temp = this->root;
        
        while (temp->rightChild != NULL) {
            temp = temp->rightChild;
        }
        output = temp->data.key;
    }else {
        std::cout << "The tree is empty!" << std::endl;
    }
}

void LinkedBST::min(int &output) {
    
    if (!this->isEmpty()) {
        Node* temp = this->root;
        
        while (temp->leftChild != NULL) {
            temp = temp->leftChild;
        }
        output = temp->data.key;
    } else {
        std::cout << "The tree is empty!" << std::endl;
    }
}

bool LinkedBST::exists(int targetKey) {
    bool found = false;
    
    if (this->isEmpty()) {
        std::cout << "The tree is empty!" << std::endl;
    } else  {
        Node* temp = this->root;
        
        while (temp != NULL) {
            if (temp->data.key == targetKey) {
                found = true;
                break;
            } else if (temp->data.key < targetKey) {
                temp = temp->rightChild;
            } else {
                temp = temp->leftChild;
            }
        }
        
    }
    return found;
}