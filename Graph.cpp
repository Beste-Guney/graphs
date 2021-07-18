/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Implemetation file for graph
*/
#include "Graph.h"
#include <iostream>
using namespace std;
Graph::Graph(){
    matrix = new int*[MATRIX_SIZE];
    for(int i = 0; i < MATRIX_SIZE; i++)
        matrix[i] = new int[MATRIX_SIZE];

    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++)
            matrix[i][j] = 0;
    }

}
Graph::~Graph(){
    for(int i = 0; i < MATRIX_SIZE; i++)
        delete [] matrix[i];
    delete [] matrix;
}
int* Graph::findNeighbours(int index, int& size){
    int index1 = 0;
    for(int i = 0; i < MATRIX_SIZE; i++){
        if(matrix[index][i] == 1){
            index1 ++;

        }
    }
    int* temp = new int[index1];
    int index2 = 0;
    for(int i = 0; i < MATRIX_SIZE; i++){
        if(matrix[index][i] == 1){
            temp[index2] = i;
            index2++;
        }
    }
    size = index1;
    return temp;
}

void Graph::displayColumn(int index){
    for(int i = 0; i < MATRIX_SIZE; i++){
        cout << matrix[i][index] << endl;
    }
}

void Graph::displayGraph(){
    for(int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
void Graph::makeConnection(int index1, int index2){
    matrix[index1][index2] = 1;
    matrix[index2][index1] = 1;
}

bool Graph::isConnected(int row, int column){
    return matrix[row][column] == 1;
}

