//
// Created by Yun-Ting Chen on 4/20/2020.
//
// This is the header file for binary search tree(BST)
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>


#ifndef ASSIGNMENT_1_BST_H
#define ASSIGNMENT_1_BST_H

using namespace std;

class BST {
public:
    // create Node struct to store node data
    struct Node {
        int data;
        Node *right;
        Node *left;
    };

    // constructors
    BST();

    BST(string fileName);

    // add data to the tree
    void insert(int data);

    // display tree values
    void displayInorder();

    // get the highest branch height
    int getMaxHeight();

    // get the smallest branch height
    int getMinHeight();

    // get the number of nodes in the tree
    int getTotalNodes();

    // check if the tree is balanced
    bool isBalanced();

    // check if the tree is complete
    bool isComplete();

private:
    // private read file method
    void readFile(string fileName);

    // tree root
    Node *root = nullptr;
    // a vector to store nodes
    vector<int> nodes;

    // create new node
    Node *create(int data);

    // helper function for insert
    void insertHelper(Node *&root, int data);

    // help function for display to print tree values (inorder)
    void inorder(Node *root);

    // helper function to get max height
    int maxHeight(Node *root);

    // helper function to get min height
    int minHeight(Node *root);

    // helper function to count nodes in tree
    int CountNodes(Node *root);

    // counter
    int count = 1;

    // helper function for isBalanced
    bool checkBalanced(Node *root);

    // helper function for isComplete
    bool checkComplete(Node *root);
};


#endif //ASSIGNMENT_1_BST_H
