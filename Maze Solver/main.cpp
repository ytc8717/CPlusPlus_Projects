//
// Created by Yun-Ting Chen 2/10/2020
//
// This is the driver class to test the creature and the maze functions
//

#include <iostream>

#include "creature.h"
#include "maze.h"
#include <cassert>

// test method
void test() {
    Maze M("maze.txt");
    Creature C(4, 4);
    cout << "start point: " << C << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    cout << C << endl;
    assert(C.getPath() == "EEENNNEEEEEESEESSSEEENNNNN");
}

// test no exit
void noExitTest()
{
    Maze M("maze.txt");
    Creature C(1, 1);
    cout << "start point: " << C << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    cout << C << endl;
    assert(C.solve(M) == "Path not found");
}

// at exit test
void atExitTest()
{
    Maze M("maze.txt");
    Creature C(0, 18);
    cout << "start point: " << C << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
    cout << C << endl;
    assert(C.solve(M) == "At exit");
}

// main driver
int main() {
    test();
    cout << endl;
    noExitTest();
    cout << endl;
    atExitTest();
    cout << "Done!" << std::endl;
    return 0;
}