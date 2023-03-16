//
// Created by Yun-Ting Chen on 3/11/2020.
//
// A class represent the functions of Threaded Binary Search Tree
//

#ifndef ASSIGNMENT_5_TBST_H
#define ASSIGNMENT_5_TBST_H

#include <iostream>

using namespace std;

class TBST {
    // create Node struct to store node values
    struct Node
    {
        Node*left, *right;
        int data;
        bool lthread; // check if left thread
        bool rthread; // check if right thread
    };
public:
    // constructor
    TBST();
    // insert element to tree
    bool insert(int key);
    // remove element from tree
    bool remove(int key);
    // inorder traversal to print out the tree
    void inorder();
    // search for element in tree
    bool search(int key);
    // check of tree is empty
    bool isEmpty()const ;
private:
    Node *root;
    // only Right Child (used for remove function)
    Node* caseA(Node* root,Node*par,Node*ptr);
    // only Left Child (used for remove function)
    Node* caseB(Node* root,Node*par,Node*ptr);
    // two Children (used for remove function)
    Node* caseC(Node* root,Node*par,Node*ptr);
    // returns inorder successor using left and right children
    Node* inSucc(Node* ptr);
    // returns inorder successor using rthread
    Node* inorderSuccessor(Node* ptr);
    // returns inorder predecessor using lthread
    Node* inPred(Node* ptr);
};

#endif //ASSIGNMENT_5_TBST_H
