/*
 *  created by Yun-Ting Chen 4/27/2020
 *
 *  This is a driver class for Dijkstra class
 */
#include <iostream>
#include "Dijkstra.h"

int main() {
    // read in file
    Dijkstra d("AirportDistances.csv");
    char code = 'y';
    while (code == 'y') {
        code = 'n';
        cout << "Please Enter departure code[UPPERCASE]: ";
        string dept;
        cin >> dept;
        cout << endl;
        cout << "Please Enter destination code[UPPERCASE]: ";
        string dest;
        cin >> dest;
        cout << endl;
        d.dijkstra(dept, dest);
        cout << endl;
        cout << endl;
        cout << "enter another data? (y/n) ";
        cin >> code;
        cout << endl;
    }
}
