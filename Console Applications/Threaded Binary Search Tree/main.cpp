//
// Created by Yun-Ting Chen on 3/11/2020.
//
// this class is used to test out the functions for ThreadedBST
//

#include <iostream>
#include <cassert>
#include <sstream>
#include "TBST.h"

using namespace std;

int main() {
    TBST t;
    t.insert(20);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(16);
    t.insert(14);
    t.insert(17);
    t.insert(13);
    t.remove(20);
    t.inorder();
}
