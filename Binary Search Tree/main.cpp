//
// Created by Yun-Ting Chen on 4/20/2020.
//
// This is a driver class for BST
//
#include <iostream>
#include "BST.h"

int main() {
    cout << "==================================================" << endl;
    BST t("CSS343_A1_F1.txt");
    cout << "Tree data: ";
    t.displayInorder();
    cout << endl;
    cout << "Smallest branch height: " << t.getMinHeight() << endl;
    cout << "highest branch height: " << t.getMaxHeight() << endl;
    cout << "Number of nodes: " << t.getTotalNodes() << endl;
    cout << "is Tree balanced? ";
    t.isBalanced();
    cout << endl;
    cout << "is Tree complete? ";
    t.isComplete();
    cout << endl;

    cout << "==================================================" << endl;
    BST t2("CSS343_A1_F2.txt");
    cout << "Tree data: ";
    t2.displayInorder();
    cout << endl;
    cout << "Smallest branch height: " << t2.getMinHeight() << endl;
    cout << "highest branch height: " << t2.getMaxHeight() << endl;
    cout << "Number of nodes: " << t2.getTotalNodes() << endl;
    cout << "is Tree balanced? ";
    t2.isBalanced();
    cout << endl;
    cout << "is Tree complete? ";
    t2.isComplete();
    cout << endl;

    cout << "==================================================" << endl;
    BST t3("CSS343_A1_F3.txt");
    cout << "Tree data: ";
    t3.displayInorder();
    cout << endl;
    cout << "Smallest branch height: " << t3.getMinHeight() << endl;
    cout << "highest branch height: " << t3.getMaxHeight() << endl;
    cout << "Number of nodes: " << t3.getTotalNodes() << endl;
    cout << "is Tree balanced? ";
    t3.isBalanced();
    cout << endl;
    cout << "is Tree complete? ";
    t3.isComplete();
    cout << endl;
}
