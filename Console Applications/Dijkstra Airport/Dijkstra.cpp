//
// Created by Yun-Ting Chen on 4/27/2020.
//
// This is the implementation of Dijkstra class
//

#include "Dijkstra.h"

// read in data from file
void Dijkstra::readFile(string fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);

            string dept;
            string dest;
            string distance;
            getline(ss, dept, ',');
            getline(ss, dest, ',');
            getline(ss, distance, ',');
            int dist = stoi(distance);

            // store data to vectors
            airport1.push_back(dept);
            airport2.push_back(dest);
            mile.push_back(dist);
        }
        file.close();
    }
}

// constructor take in file name
Dijkstra::Dijkstra(string file) {
    readFile(file);
    // count total vertice(airports)
    countVertice();
    // construct graph
    add();
}

// defacult constructor
Dijkstra::Dijkstra() {

}

// count total vertices
void Dijkstra::countVertice() {
    vector<string> all;
    for (string s:airport1) {
        all.push_back(s);
    }
    for (string i:airport2) {
        all.push_back(i);
    }
    int res = 1;
    for (int i = 1; i < all.size(); i++) {
        int j = 0;
        for (j = 0; j < i; j++)
            if (all[i] == all[j])
                break;

        if (i == j)
            res++;
    }
    numOfVertices = res;

    sort(all.begin(), all.end());

    auto end = all.end();
    for (auto it = all.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }
    all.erase(end, all.end());

    for (string s: all) {
        airports.push_back(s);
    }
}

// return total vertices
int Dijkstra::getNumOfVertice() const {
    return numOfVertices;
}

// construct graph as adj-matrix
void Dijkstra::add() {
    int graph[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    string dest;
    int distance;
    for (int i = 0; i < airports.size(); i++) {
        for (int j = 0; j < airport1.size(); j++) {
            if (airports[i] == airport1[j]) {
                dest = airport2[j];
                distance = mile[j];
                for (int z = 0; z < airports.size(); z++) {
                    if (airports[z] == dest) {
                        graph[i][z] = distance;
                    }
                }
            }

        }
    }
    for (int i = 0; i < airports.size(); i++) {
        for (int j = 0; j < airport2.size(); j++) {
            if (airports[i] == airport2[j]) {
                dest = airport1[j];
                distance = mile[j];
                for (int z = 0; z < airports.size(); z++) {
                    if (airports[z] == dest) {
                        graph[i][z] = distance;
                    }
                }
            }

        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = graph[i][j];
        }
    }
}

// Helper function for dijkstra method
// take in adj-matrix and source input
void Dijkstra::dijkstraHelper(int (*graph)[100], int src) {
    // output array
    // dist[i] will hold the shortest distance from src to i
    int dist[V];

    // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[V];

    // initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    // distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // mark the picked vertex as processed
        sptSet[u] = true;

        // update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    // copy output array to answer array
    for (int i = 0; i < V; i++) {
        answer[i] = dist[i];
    }
}

/*
 * A utility function to find the vertex with minimum distance value, from
 * the set of vertices not yet included in shortest path tree
 */
int Dijkstra::minDistance(int *dist, bool *sptSet) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// dijkstra algorithm
void Dijkstra::dijkstra(string src, string end) {
    inputcheck(src, end);
    int index = -1;
    for (int i = 0; i < airports.size(); i++) {
        if (airports[i] == src) {
            index = i;
            break;
        }
    }
    // call for helper function
    dijkstraHelper(adjMatrix, index);
    for (int i = 0; i < airports.size(); i++) {
        if (airports[i] == end) {
            index = i;
            break;
        }
    }
    // print out result
    cout << src << " to " << end << " = " << answer[index] << " miles";
}

// check if user input match the airport code
// if not exit the program
void Dijkstra::inputcheck(string src, string end) {
    string start = src;
    bool found = false;
    bool found2 = false;
    for (int i = 0; i < airports.size(); i++) {
        if (start == airports[i])
            found = true;
    }
    if (found == false) {
        cout << "departure code not found" << endl;
        exit(0);
    }
    for (int i = 0; i < airports.size(); i++) {
        if (end == airports[i])
            found2 = true;
    }
    if (found2 == false) {
        cout << "destination code not found" << endl;
        exit(0);
    }
}




