//
// Created by Yun-Ting Chen on 2/10/2020
//
// This is the Implementation for the Creature class.
// The direction functions implementation and algorithm is based and modify from Carrano Chapter 5 Problem 9
//

#include "creature.h"

// output the creature location
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
    Out << "C(" << Creature.getRow() << "," << Creature.getCol() << ")";
    return Out;
}

// constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col),Path(""),startRow(Row),startCol(Col) {
}

// check if the creature is at exit
// return true if at exit
// false if not
bool Creature::atExit(const Maze &Maze) const {
    if(Maze.getExitRow() == this->getRow() && Maze.getExitColumn() == this->getCol())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// this function make the creature to move at different directs
// and try to find the exit by calling direction functions
string Creature::solve(Maze &Maze) {
    // if the start point is at wall
    // return error message
    if(Maze.isWall(getRow(),getCol()))
    {
        return "Invalid Start point";
    }

    // else mark the start point
    Maze.markAsPath(getRow(), getCol());

    // check if at exit
    // return at exit if true
    if (atExit(Maze)) {
        return "At exit";
    }

    // if not at exit
    // make creature go north and get path
    if (goNorth(Maze)) {
        return Path;
    }

    // reset to start point
    Row = startRow;
    Col = startCol;

    // make creature go south and get path
    if (goSouth(Maze)) {
        return Path;
    }

    Row = startRow;
    Col = startCol;

    // make creature go west and get path
    if (goWest(Maze)) {
        return Path;
    }

    Row = startRow;
    Col = startCol;

    // make creature go east and get path
    if (goEast(Maze)) {
        return Path;
    }

    // if failed to find exit (no more place to move)
    // return path not found
    return "Path not found";
}

// function to make the creature go north
// return true if the move is success
// false if not
bool Creature::goNorth(Maze &Maze) {
    bool Success;
    // if path to north is clear then move north
    if (Maze.isClear(getRow() - 1, getCol())) {
        Row -= 1;
        Maze.markAsPath(getRow(), getCol());
        // add to path
        Path += "N";
        // check if at exit
        if (atExit(Maze)) {
            Success = true;
        }
        else {
            Success = goNorth(Maze);
            if (!Success) {
                Success = goWest(Maze);
                if (!Success) {
                    Success = goEast(Maze);
                    if (!Success) {
                        Maze.markAsPath(getRow(), getCol());
                        Row += 1;
                        // remove last char in path
                        Path.erase(Path.size() - 1, 1);
                    }
                }
            }
        }
    } else {
        Success = false;
    }
    return Success;
}

// function to make the creature go west
// return true if the move is success
// false if not
bool Creature::goWest(Maze &Maze) {
    bool Success;
    if (Maze.isClear(getRow(), getCol() - 1)) {
        Col -= 1;
        Maze.markAsPath(getRow(), getCol());
        Path += "W";
        if (atExit(Maze)) {
            Success = true;
        } else {
            Success = goWest(Maze);
            if (!Success) {
                Success = goNorth(Maze);
                if (!Success) {
                    Success = goSouth(Maze);
                    if (!Success) {
                        Maze.markAsVisited(getRow(), getCol());
                        Col += 1;
                        // remove last char in path
                        Path.erase(Path.size() - 1, 1);
                    }
                }
            }
        }
    } else {
        Success = false;
    }
    return Success;
}

// function to make the creature go east
// return true if the move is success
// false if not
bool Creature::goEast(Maze &Maze) {
    bool Success;
    if (Maze.isClear(getRow(), getCol() + 1)) {
        Col += 1;
        Maze.markAsPath(getRow(), getCol());
        Path += "E";
        if (atExit(Maze)) {
            Success = true;
        } else {
            Success = goEast(Maze);
            if (!Success) {
                Success = goNorth(Maze);
                if (!Success) {
                    Success = goSouth(Maze);
                    if (!Success) {
                        Maze.markAsVisited(getRow(), getCol());
                        Col -= 1;
                        // remove last char in path
                        Path.erase(Path.size() - 1, 1);
                    }
                }
            }
        }
    } else {
        Success = false;
    }
    return Success;
}

// function to make the creature go south
// return true if the move is success
// false if not
bool Creature::goSouth(Maze &Maze) {
    bool Success;
    if (Maze.isClear(getRow() + 1, getCol())) {
        Row += 1;
        Maze.markAsPath(getRow(), getCol());
        Path += "S";
        if (atExit(Maze)) {
            Success = true;
        } else {
            Success = goSouth(Maze);
            if (!Success) {
                Success = goWest(Maze);
                if (!Success) {
                    Success = goEast(Maze);
                    if (!Success) {
                        Maze.markAsVisited(getRow(), getCol());
                        Row -= 1;
                        // remove last char in path
                        Path.erase(Path.size() - 1, 1);
                    }
                }
            }
        }
    } else {
        Success = false;
    }
    return Success;
}

// return the Column value
int Creature::getCol() const {
    return Col;
}

// return the row value
int Creature::getRow() const {
    return Row;
}

// return path
string Creature::getPath() const {
    return Path;
}
