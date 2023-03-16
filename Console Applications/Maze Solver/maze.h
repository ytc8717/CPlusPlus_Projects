//
// Created by Yun-Ting Chen on 2/10/2020.
//
// This class is used to generate and represent the maze
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
    // output the maze
    friend ostream &operator<<(ostream &Out, const Maze &Maze);
private:
    // max size dimension for maze
    const static int MAX_SIZE = 100;
    // maze field 2d array
    char Field[MAX_SIZE][MAX_SIZE];
    int Width, Height;
    int ExitRow, ExitColumn;
public:
    // constructor taken in file name
    explicit Maze(const string &FileName);
    // check if given location is move able
    bool isClear(int Row, int Col) const;
    // check if is wall
    bool isWall(int Row, int Col) const ;
    // mark the path
    void markAsPath(int Row, int Col);
    // mark visited
    void markAsVisited(int Row, int Col);
    // return exit row
    int getExitRow() const;
    // return exit Column
    int getExitColumn() const;
};

#endif //ASS3_MAZE_H
