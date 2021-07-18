/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Beste Guney
* ID: 21901631
* Section : 1
* Assignment : 4
* Description : Header file for word network
*/
#include <iostream>
#include <string>
#include "Graph.h"
#include "HashTable.h"
using namespace std;

class WordNetwork {
public :
    WordNetwork ( const string vertexFile , const string edgeFile );
    ~ WordNetwork () ;
    void listNeighbors ( const string word ) ;
    void listNeighbors ( const string word , const int distance );

    void printDFT(int);
    void printDFT(int startPoint, bool* isVisited);
    void listConnectedComponents () ;
    void findShortestPath ( const string word1 , const string word2 ) ;
    void displayHash();
    void displayGraph();
    void listRecursive(const string word, const int distance, const int index);
private :
    Graph* graph;
    HashTable* hashTable;
    string* wordArray;

};


