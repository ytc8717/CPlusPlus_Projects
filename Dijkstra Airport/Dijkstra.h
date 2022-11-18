//
// Created by Yun-Ting Chen on 4/27/2020.
//
// This is the header file design for Dijkstra
// will be used to determine the shortest distance between two airport codes using Dijkstra's Algorithm
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

#ifndef ASSIGNMENT_2_DIJKSTRA_H
#define ASSIGNMENT_2_DIJKSTRA_H

// define matrix size constant
#define V 100

class Dijkstra {
public:
    // constructor
    Dijkstra();

    // constructor take in file name
    explicit Dijkstra(string file);

    // return total vertices
    int getNumOfVertice() const;

    // Dijkstra algorithm
    void dijkstra(string src, string end);

private:
    // read in data from file
    void readFile(string fileName);

    // vectors to store data
    vector<string> airport1;
    vector<string> airport2;
    vector<int> mile;
    vector<string> airports;

    // count total vertice
    void countVertice();

    int numOfVertices;

    // add data to construct graph
    void add();

    // adjacency matrix to represent graph
    int adjMatrix[V][V];
    // final distance answer from dijkstra method
    int answer[V];

    // check if user input code is valid
    void inputcheck(string src, string end);

    // Helper function for dijkstra
    void dijkstraHelper(int graph[V][V], int src);

    // get min distance
    int minDistance(int dist[], bool sptSet[]);
};


#endif //ASSIGNMENT_2_DIJKSTRA_H
