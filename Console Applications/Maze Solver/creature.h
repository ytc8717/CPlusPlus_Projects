//
// Created by Yun-Ting Chen on 4/18/18.
//
// This class represent the creature in the maze
//
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
    // output creature location
    friend ostream &operator<<(ostream &Out, const Creature &Creature);
private:
    int Row;
    int Col;
    string Path; // string to store path info
    int startRow;
    int startCol;
public:
    // constructor
    Creature(int Row, int Col);
    // function to find exit
    string solve(Maze &Maze);
    // check if at exit
    bool atExit(const Maze &Maze) const;
    // move north
    bool goNorth(Maze &Maze);
    // move south
    bool goSouth(Maze &Maze);
    // move east
    bool goEast(Maze &Maze);
    // move west
    bool goWest(Maze &Maze);
    // return row
    int getRow()const ;
    // return column
    int getCol()const ;
    // return Path
    string getPath()const;
};

#endif //ASS3_CREATURE_H
