/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Header file for adjacency matrix implemented graph
*/
#include <iostream>
using namespace std;
const int MATRIX_SIZE = 5757;

class Graph{
public:

    Graph();
    ~Graph();

    void displayColumn(int index);
    void makeConnection(int, int);
    void displayGraph();
    int* findNeighbours(int index, int& size);
    bool isConnected(int row, int column);

private:
    int** matrix;
};



